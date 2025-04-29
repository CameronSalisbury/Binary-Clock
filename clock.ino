/*
Cameron Salisbury
Binary clock for an Arduino
Comments:
I will be construcing an arduino to mimic a clock and tell time in binary
TODO:
-Test on arduino
-add button to adjust time
*/

//Declaring binary leds that will tell the time m for minutes, h for hours
const int minutePins[6] = {m0, m1, m2, m3, m4, m5};
const int hourPins[4] = {h0, h1, h2, h3};
int hour = 1;
int minute = 0;
int tick = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++) {
    pinMode(minutePins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(hourPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //count the time
  //hour never starts at 0
  int tock = millis() / 60000;

  //divide milisionds by 60000 (miliseconds(1000) * seconds(60))
  if (tick != tock){
    minute++;
    if (minute == 60){
      minute = 0;
      hour++;
      if (hour == 13){
        hour = 1;
      }
    }
    //global variables grumble grumble
    displayMinute();
    displayHour();
    tick = tock;
  }
}

void displayMinute(){
  //I think the for loop might be holding this back
  for (int i = 4; i >= 0; i--){
    digitalWrite(minutePins[i], (minute % 2 == 1) ? HIGH : LOW);
    min = min / 2;
  }
}

void displayHour(){
  //same as minutes for loop is suspected to hold this back
  for (int i = 3; i >= 0; i--){
    digitalWrite(hourPins[i], (hour % 2 == 1) ? HIGH : LOW);
    hour = hour / 2;
  }
}
