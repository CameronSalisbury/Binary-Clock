/*
Todo:

-Convert up time to seconds then minutes then hours
-output binary representation of time
-change toggle button to single output for two seperate buttons
WARNING: DO NOT OUTPUT HIGH VOLTAGE YOUL WILL END UP BRAKING AN LED (i already wired all the wrong resitors in)

*/

// constants won't change. They're used here to set pin numbers:
//More buttons pins here
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState, ledState, lastButtonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

unsigned long previousMillis = 0;  //counter
const long interval = 10;          //button read time
int toggle = false;               //light reading

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    previousMillis = millis();
  }

  if (millis() - previousMillis >= interval) {
    if (buttonState != toggle) {
      toggle = buttonState;
      if (toggle == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = buttonState;
}
