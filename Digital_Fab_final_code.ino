#include <LiquidCrystal.h>

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


AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin); // initializing stepper

LiquidCrystal_I2C lcd(0x27, 16, 2); // initializing LCD

bool forwardbuttonPressed = LOW;
bool reversebuttonPressed = LOW;
bool onoffswitchPressed = LOW;
bool endstopPressed = LOW;


int potvalue = 0;
int flowrate = 5; // in mL/min
double syringe_10d = 14;
double syringe_20d = 17; 
int syringe_10d_area = (pow((syringe_10d/2)*0.1, 2)*3.14);
int syringe_20d_area = (pow((syringe_20d/2)*0.1, 2)*3.14);

// Pump specific code:
int stepperSpeed = flowrate * (1/60) * (1/syringe_20d_area)*(1/0.8)*200;

//int pastflowrate = 0;
//int flowratelcdrange = 0;

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

  pinMode(microstepPin, OUTPUT);
  digitalWrite(microstepPin, LOW);

  pinMode(microstepPinExtraSlow, OUTPUT);
  digitalWrite(microstepPinExtraSlow, LOW);


  pinMode(microstepPinSuperSLOW, OUTPUT);
  digitalWrite(microstepPinSuperSLOW, LOW);


  //----------


  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 


}



void loop() {

 // int stepperSpeed = map(analogRead(potentiometerButton), 0, 1023, 0, 1000);

  forwardbuttonPressed = digitalRead(forwardButton);
  reversebuttonPressed = digitalRead(reverseButton);
  onoffswitchPressed = digitalRead(onoffButton);
  endstopPressed = digitalRead(endstopButton);




  if(onoffswitchPressed == HIGH){
    //ON now

    if (endstopPressed == HIGH) {

      //Syringe Pump finished
      updateLed('R');
      updateLCD(false, 0,0, 0);

      stepper.setSpeed(0);
      stepper.runSpeed();



    } else if (endstopPressed == LOW) {

      //Go mode
      updateLed('G');
      //updateLCD(stepperSpeed,0);

      digitalWrite(microstepPin, HIGH);
      digitalWrite(microstepPinExtraSlow, HIGH);
      digitalWrite(microstepPinSuperSLOW, HIGH);

      stepper.setSpeed(stepperSpeed);
      stepper.runSpeed();


    }






  } else if (onoffswitchPressed == LOW){

      if (forwardbuttonPressed == HIGH && endstopPressed == LOW){ // if you are pressing forward button while its off

      //FORWARD mode - GO MODE
        //updateLed('Y');
        //currentflowrate = stepperSpeed;

        digitalWrite(microstepPin, LOW);
        digitalWrite(microstepPinExtraSlow, LOW);
        digitalWrite(microstepPinSuperSLOW, LOW);
      
        stepper.setSpeed(700);
        stepper.runSpeed();

        //currentflowrate = stepperSpeed/10;
        //updateLCD(3000,0);
      //Serial.println(flowrate);

      } else if (reversebuttonPressed == HIGH){ // if you are pressing reverse button while its off
      
        //REVERSE mode
        //updateLed('Y');

      //set microsteps low, then move

        digitalWrite(microstepPin, LOW);
        digitalWrite(microstepPinExtraSlow, LOW);
        digitalWrite(microstepPinSuperSLOW, LOW);

        stepper.setSpeed(-700);
        stepper.runSpeed();

        //currentflowrate = stepperSpeed/10;
        //updateLCD(-3000,0);
        //Serial.println(-stepperSpeed);
      
      } else if (forwardbuttonPressed == HIGH && endstopPressed == HIGH){ // stopped mode

        updateLCD(false, 0, 0, 0);
        updateLed('R');
        stepper.setSpeed(0);
        stepper.runSpeed();

      } else {
        //STAND by mode
        updateLed('Y');
        //stepper.setSpeed(0);
        //updateLCD(0,0);
        potvalue = map(analogRead(potentiometerButton), 0, 1023, 0, 1000);

        stepperSpeed = potvalue; // for now

        int flowrate = stepperSpeed * (1/200) * (0.8) * (syringe_20d_area) * 60; //for now just the potvalue - but later, itll be a number based on potvalue + formula etc. to get flowrate
        //then show that flowrate
        //make it to where the lcd only updates if there is something to update tho and doesnt cycle a bunch here
        updateLCD(true, flowrate, 0, stepperSpeed);
      }


    }





  forwardbuttonPressed = LOW;
  reversebuttonPressed = LOW;
  onoffswitchPressed = LOW;
  endstopPressed = LOW;

  //stepper.runSpeed();

}



//------------------------------------------



void updateLCD(bool isRunning, int flowRate, int timeleft, int stepperSpeed) {
 
  stepperSpeed = map(analogRead(potentiometerButton), 0, 1023, 0, 1000);
  timeleft = 10;
  flowRate = stepperSpeed * (1/200) * (0.8) * (syringe_20d_area) * 60;

  if (isRunning == false) {

    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("STOPPED");

  } else {

    if (0 <= flowRate && flowRate < 1000){

    
    lcd.clear();
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

    delay(1000);


  } else if (flowRate < 1){

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
