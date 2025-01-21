#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//LDC stuff

#include <AccelStepper.h>

// Defining pins
#define directionPin 2
#define stepPin 3

#define redLED 5
#define greenLED 6
#define blueLED 9

#define reverseButton 12
#define forwardButton 11
#define onoffButton 10

#define endstopButton 13

#define potentiometerButton A0

#define microstepPin A2
#define microstepPinExtraSlow A1
#define microstepPinSuperSLOW A3

// ms2 ms1 ms3
// A1 A2 A3


AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin); // initializing stepper

LiquidCrystal_I2C lcd(0x27, 16, 2); // initializing LCD

bool forwardbuttonPressed = LOW;
bool reversebuttonPressed = LOW;
bool onoffswitchPressed = LOW;
bool endstopPressed = LOW;

int stepperSpeed = 500;
//int potvalue = 0;
//double flowrate = 0;

// Pump specific code:

//int currentflowrate = 0;
//int syringepumpDiameter = 20;


//int pastflowrate = 0;
//int flowratelcdrange = 0;


// double syringe_10d = 14.75;
// double syringe_20d = 19; 

// double radius_10d = syringe_10d/2;
// double radius_20d = syringe_20d/2;



// unsigned long volumepermicrostep_10d = (3.14159265359 * sq(radius_10d) * 8)/(200 * 16 * 1000);

// unsigned long volumepermicrostep_20d = (3.14159265359 * sq(radius_20d) * 8)/(200 * 16 * 1000);






//int syringe_10d_area = (pow((syringe_10d/2)*0.1, 2)*3.14);
//int syringe_20d_area = (pow((syringe_20d/2)*0.1, 2)*3.14);

//unsigned long currentmillisLCD = 0;
//unsigned long previousmillisLCD = 0;


// NEW CODE

unsigned long previousMillisLCD = 0;


float syringe_10mL_diameter = 14.75;
float syringe_20mL_diameter = 19; 

float syringe_10mL_radius = syringe_10mL_diameter/2.00;
float syringe_20mL_radius = syringe_10mL_diameter/2.00;



// how to edit the code - just uncomment the right syring
// float radius = syringe_10mL_radius;
// float radius = syringe_20mL_radius;


float radius = 9.5; 

const float lead = 8.0; 
const float stepsPerRevolution = 200.0;
const float microstepsPerStep = 16.0;


float microstepsPerSecond = 0;



// ----
float recentpotValue = 0.00;
float potReading = 0.00;
// -----


void setup() {

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(onoffButton, INPUT);
  pinMode(forwardButton, INPUT);
  pinMode(reverseButton, INPUT);
  
  
  pinMode(endstopButton, INPUT);

  pinMode(potentiometerButton, INPUT);

  //Serial.begin(9600);



  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);



  pinMode(microstepPin, OUTPUT);
  digitalWrite(microstepPin, LOW);

  pinMode(microstepPinExtraSlow, OUTPUT);
  digitalWrite(microstepPinExtraSlow, LOW);


  pinMode(microstepPinSuperSLOW, OUTPUT);
  digitalWrite(microstepPinSuperSLOW, LOW);


  //----------


  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 

  Serial.begin(9600);

}



void loop() {

  //int stepperSpeed = map(analogRead(potentiometerButton), 0, 1023, 0, 1000);

  forwardbuttonPressed = digitalRead(forwardButton);
  reversebuttonPressed = digitalRead(reverseButton);
  onoffswitchPressed = digitalRead(onoffButton);
  endstopPressed = digitalRead(endstopButton);




  if(onoffswitchPressed == HIGH){
    //ON now

    if (endstopPressed == HIGH) {

      //Syringe Pump finished
      updateLed('R');
      updateLCD(false, 0,0);

      stepper.setSpeed(0);
      stepper.runSpeed();



    } else if (endstopPressed == LOW) {

      //GO MODE!
      updateLed('G');
      //updateLCD(stepperSpeed,0);

      digitalWrite(microstepPin, HIGH);
      digitalWrite(microstepPinExtraSlow, HIGH);
      digitalWrite(microstepPinSuperSLOW, HIGH);

      //stepperSpeed = 10 * 16;
      //stepperSpeed = 1.49 * 16;

      stepper.setSpeed(microstepsPerSecond);
      stepper.runSpeed();
      //stepper.moveTo(16*200);
      //stepper.run();


    }






  } else if (onoffswitchPressed == LOW){

      if (forwardbuttonPressed == HIGH && endstopPressed == LOW){ // if you are pressing forward button while its off

      //FORWARD mode - GO MODE
        updateLed('Y');
        //currentflowrate = stepperSpeed;

        digitalWrite(microstepPin, LOW);
        digitalWrite(microstepPinExtraSlow, HIGH);
        digitalWrite(microstepPinSuperSLOW, LOW);
      
        stepper.setSpeed(999);
        stepper.runSpeed();

        //currentflowrate = stepperSpeed/10;
        //updateLCD(3000,0);
      //Serial.println(flowrate);

      } else if (reversebuttonPressed == HIGH){ // if you are pressing reverse button while its off
      
        //REVERSE mode
        updateLed('Y');

      //set microsteps low, then move

        digitalWrite(microstepPin, LOW);
        digitalWrite(microstepPinExtraSlow, HIGH);
        digitalWrite(microstepPinSuperSLOW, LOW);

        stepper.setSpeed(-999);
        stepper.runSpeed();

        //currentflowrate = stepperSpeed/10;
        //updateLCD(-3000,0);
        //Serial.println(-stepperSpeed);
      
      } else if (forwardbuttonPressed == HIGH && endstopPressed == HIGH){ // stopped mode

        updateLCD(false, 0, 0);
        updateLed('R');
        stepper.setSpeed(0);
        stepper.runSpeed();

      } else {

        unsigned long currentMillisLCD = millis();

        if (currentMillisLCD - previousMillisLCD >= 300) {

          updateLed('Y');

          // ----
            potReading = analogRead(potentiometerButton);

            if (abs(potReading - recentpotValue) >= 50){
              recentpotValue = potReading;

              //recentpotValue = double(int(map(recentpotValue, 0, 1023, 0, 50)));
              //Serial.println(recentpotValue/10.0);
            }
            
          // ----

          //float potValue = analogRead(potentiometerButton);
          recentpotValue = map(recentpotValue, 0, 1023, 0, 51);

          float desiredFlowRate = recentpotValue/10;

          //updateLCD(true, desiredFlowRate, 0);

    
          // Calculate the number of microsteps per second
          float volumePerMicrostep = (PI * pow(radius, 2) * lead) / (stepsPerRevolution * microstepsPerStep * 1000.00); // Volume per microstep in mL

          microstepsPerSecond = (desiredFlowRate / (volumePerMicrostep * 60.00)); // Microsteps per second


          //Serial.println(microstepsPerSecond);

          //stepper.setSpeed(microstepsPerSecond);

          previousMillisLCD = currentMillisLCD;

          updateLCD(true, desiredFlowRate, 0);


        }






        // --------------------------------------------------------

        // unsigned long currentMillisLCD = millis();

        //  if (currentMillisLCD - previousMillisLCD >= 200) {

         

        //   int potvalue = int(map(analogRead(potentiometerButton), 0, 1023, 0, 999/16));

        //   float stepspersecond = potvalue;

        //   unsigned long flowrateLCD = volumepermicrostep_20d * (stepspersecond * 60);


        // // Update the LCD here

        //   stepperSpeed = potvalue;

        //   int flowrate = stepperSpeed;

        //   stepper.setSpeed(stepperSpeed);

        //   updateLCD(true, flowrate, 0);

        //   previousMillisLCD = currentMillisLCD; // Update the time after the LCD is updated

        // }




        // --------------------------------------------------------

        //STAND by mode
        
        //stepper.setSpeed(0);
        //updateLCD(0,0);
        

        //double flowrate = potvalue * 0.6792 * 16;
        //flowrate = 10;

        //delay(100);
        //Serial.println(flowrate);

//(stepspersecond)

        //stepperSpeed = potvalue; // for now

        //flowrate = potvalue; //for now just the potvalue - but later, itll be a number based on potvalue + formula etc. to get flowrate
        //then show that flowrate
        //make it to where the lcd only updates if there is something to update tho and doesnt cycle a bunch here
        /**
        currentmillisLCD = millis();

        if currentmillisLCD >= previousmillisLCD + 100{

          updateLCD(true, flowrate, 0);
        
        } else {

          previousmillisLCD = currentmillisLCD;

        }
        **/

        
        
      }


    }





  forwardbuttonPressed = LOW;
  reversebuttonPressed = LOW;
  onoffswitchPressed = LOW;
  endstopPressed = LOW;

  //stepper.runSpeed();

}



//------------------------------------------



void updateLCD(bool isRunning, float flowRate, int timeleft) {

  timeleft = 10; 

  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Flow Rate: ");
  //lcd.setCursor(6, 0);
  lcd.setCursor(12, 0);
  lcd.print(flowRate);
  //lcd.setCursor(14, 0);
  lcd.print("    ");


  lcd.setCursor(0, 1);
  // lcd.print("Units: steps/sec");
  lcd.print("Units: mL/min");
  // in the future uncomment below
  // lcd.print("Units:   ml/min");

  
  /**
  if (isRunning == false) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("STOPPED");

  } else {

    if (0 <= flowRate && flowRate < 1000){

    
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rate: ");
    lcd.setCursor(6, 0);
    lcd.print(flowRate);
    lcd.setCursor(11, 0);
    lcd.print("mL/min");

    lcd.setCursor(0, 1);
    lcd.print("Left: ");
    lcd.setCursor(6, 1);
    lcd.print(timeleft);
    lcd.setCursor(13, 1);
    lcd.print("min");


  } else if (flowRate < 0){

    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rate:");
    lcd.setCursor(5, 0);
    lcd.print(flowRate);
    lcd.setCursor(10, 0);
    lcd.print("mL/min");

    lcd.setCursor(0, 1);
    lcd.print("Left: ");
    lcd.setCursor(6, 1);
    lcd.print(timeleft);
    lcd.setCursor(13, 1);
    lcd.print("min");

  }

  }
  **/
}


void updateLed(char color) {
  // Update LED status based on the specified char for color
  switch(color) {
    case 'R': // Red
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
      break;
    case 'G': // Green
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      break;
    case 'Y': // Yellow (Red + Green)
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      break;
    case 'O': // OFF
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      break;
    case 'B': // Blue
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, HIGH);
      break;
    case 'W': // White
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
      break;
  }
}
