int counter = 0; //declaring the counter variable and setting it to 0

//declarations for the millis() function
long currentTime = 0; //declaring a variable for the current time
long prevTime = 0; //declaring a variable for the previous time
long countDelay = 500; //declaring how long we want to wait per counter increment

//For the blink state machine
int blinkSwitchState = 0; //for determining which case we are in for our state machine
long blinkStartTime = 0; //for holding the time when the timer starts for blinking the LED
long blinkDelay = 500; //how long in milliseconds the delay will be between LED transitions

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //set the Baud rate to 9600hz. You can change this in the bottom right corner of the serial monitor
  pinMode(13, OUTPUT); //set pin 13 (the built in LED) to be an output  

  //set up the 3 LEDs to be outputs
  pinMode(5, OUTPUT); //LED 1
  pinMode(8, OUTPUT); //LED 2
  pinMode(11, OUTPUT); //LED 3

  //set up the 3 ground pins for the LEDs
  pinMode(4, OUTPUT); //Ground for LED 1
  pinMode(7, OUTPUT); //Ground for LED 2
  pinMode(10, OUTPUT); //Ground for LED 3

  //set up the ground pins for the 3 LEDs
  digitalWrite(4, LOW); //Ground for LED 1 gets set low
  digitalWrite(7, LOW); //Ground for LED 2 gets set low
  digitalWrite(10, LOW); //Ground for LED 3 gets set low

  //set up the input button
  pinMode(3, INPUT_PULLUP); //set pin 3 to be an input and turn on the pullup resistor so you're not connecting ground to 5v directly
}

void loop() 
{
  blinkStateMachine();
  currentTime = millis(); //store the current time from the start of the program (in milliseconds) in the variable currentTime
  
  if (currentTime - prevTime > countDelay) //if 500 ms has passed
  {
    prevTime = currentTime; //update the previous time to the current time
    counter = counter + 1; //take the previous value of 'counter', add 1, and store that new number in 'counter' again
    Serial.print("counter: "); //so we know what we're looking at in the serial monitor
    Serial.println(counter); //print the value of the variable 'counter'
  }
  
  if (counter > 5) //if the variable 'counter' is greater than 10 (5 seconds), then do what's in the brackets
  {
    //digitalWrite(13, HIGH); //turn on the built in LED by turning pin 13 high

    //Turn on the 3 LEDs
    digitalWrite(5, HIGH); //LED 1
    digitalWrite(8, HIGH); //LED 2
    digitalWrite(11, HIGH);  //LED 3
  }
  else //make sure the LEDs are off if the timer has not reached over 5
  {
    //Turn off the 3 LEDs 
    digitalWrite(5, LOW); //LED 1
    digitalWrite(8, LOW); //LED 2
    digitalWrite(11, LOW);  //LED 3
  }

  if (digitalRead(3) == LOW) //if the arduino reads pin 3 as LOW/0v/ground, then do what's in the brackets
  {
    counter = 0; //reset the timer variable back to 0.
  }
}


void blinkStateMachine() //Our state machine function
{
  switch(blinkSwitchState) //The part that does the work, the switch statement
  {
    case 0: //Off and waiting
      //Do nothing
      if((millis()-blinkStartTime)>blinkDelay){blinkSwitchState=1;}
      break;
    case 1: //Off and transitioning to On
      //Start timer
      //Turn LED on
      blinkStartTime = millis(); //Start the timer
      digitalWrite(13, HIGH); //Turn the built in LED on
      blinkSwitchState = 2; //go to case 2
      break;
    case 2: //On and waiting
      //Do nothing
      if((millis()-blinkStartTime)>blinkDelay){blinkSwitchState=3;}
      break;
    case 3: //On and transitioning to Off
      //Start timer
      //Turn LED off
      blinkStartTime = millis(); //Start the timer
      digitalWrite(13, LOW); //Turn the LED off
      blinkSwitchState = 0; //go to case 0
      break;
  }
}
