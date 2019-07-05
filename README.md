## Class 5: Use a state machine to blink an LED in the background while doing other things in your program

### 0. Write a [state machine diagram for blinking an LED](https://i.imgur.com/wFD1Hqq.png)

### 1. Load in Class 3 and delete the commented out lines of code

### 2. Attach a template for a switch state machine
- Switch state machine template:
  - `int blinkSwitchState = 0;`
  - `long blinkStartTime = 0;`
  - `long blinkDelay = 500;`
  - `void blinkStateMachine(){switch(blinkSwitchState){`
  - `case 0:`
  - `break;`
  - `case 1:`
  - `break;`
  - `case 2:`
  - `break;`
  - `case 3:`
  - `break;}}`
### 3. Use the flowchart to fill out the cases and transitions from one case to another
- New code lines:
  - `blinkStateMachine();`
  - `if((millis()-blinkStartTime)>blinkDelay){blinkSwitchState=1;}`
  - `blinkStartTime = millis();`
  - `digitalWrite(13, HIGH);`
  - `blinkSwitchState = 2;`
  - `if((millis()-blinkStartTime)>blinkDelay){blinkSwitchState=3;}`
  - `blinkStartTime = millis();`
  - `digitalWrite(13, LOW);`
  - `blinkSwitchState = 0;`
- Comment out digitalWrite(13, HIGH); line after the if statement:
  - `if (counter > 5){`
  - `digitalWrite(13, HIGH);`
- (Upload and watch LEDs)
### 4. Change the value of blinkDelay to show that the LED can be blinking at any rate
- Line to modify:
  - `long blinkDelay = 500;`
- To:
  - `long blinkDelay = 250;`
- (Upload and watch LEDs)

### Lessons learned
- With state machines you can do 2 tasks completely independently, as long as you don't have those pesky delay() statements
















