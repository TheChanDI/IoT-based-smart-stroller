// Code for the smart stroller.
// When one or both touch sensor are activated, it unlocks the wheel i.e solenoid else 
// it locks the wheel.

byte pushPullSolenoid = 4; // This is the pin for LED light
byte touchLeftSensor = 3;  // Pin for the left touch sensor
byte touchRightSensor = 6; // Pin for the right touch sensor
bool isLeftTouchPressed = false; // variable to know the state whether the left touch sensor is pressed or not
bool isRightTouchPressed = false; // variable to know the state whether the right touch sensor is pressed or not

void setup()
{
  pinMode(pushPullSolenoid, OUTPUT); // SOLENOID --> OUTPUT
  pinMode(touchLeftSensor, INPUT); // LEFT TOUCH SENSOR --> INPUT
  pinMode(touchRightSensor, INPUT); // RIGHT TOUCH SENSOR --> INPUT
  Serial.begin(9600);
}

void loop()
  {
    isLeftTouchPressed = digitalRead(touchLeftSensor);
    isRightTouchPressed = digitalRead(touchRightSensor);

    Serial.print(isLeftTouchPressed, isRightTouchPressed);
  
    // Start the solenoid -> Unhold the brake.
    if(isLeftTouchPressed == true || isRightTouchPressed == true) { 
  	  digitalWrite(pushPullSolenoid, HIGH);
  
    }
    else {
      //stop the solenoid -> hold the brake.
	    digitalWrite(pushPullSolenoid, LOW);
    }
}