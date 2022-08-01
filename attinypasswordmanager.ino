#include "DigiKeyboard.h"

//pins 3 & 4 used for usb connection
bool buttonState0 = 0;
bool buttonState1 = 0;
bool buttonState2 = 0;
bool buttonState3 = 0;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH); 
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  if ((digitalRead(0) != buttonState0)||(digitalRead(1) != buttonState1)||(digitalRead(2) != buttonState2)){
    DigiKeyboard.delay(5);
    
    if (digitalRead(0)!= buttonState0){
      buttonState0 = digitalRead(0);
      if (buttonState0 == LOW)   DigiKeyboard.println("pass1"); ; 
    }
    
    if (digitalRead(2)!= buttonState1){
      buttonState1 = digitalRead(2);
      if (buttonState1 == LOW) DigiKeyboard.println("pass2"); 
    }
    
    if (digitalRead(1)!= buttonState2){
      buttonState2 = digitalRead(1);
      if (buttonState2 == LOW) DigiKeyboard.println("pass3");
    }
    
    if (digitalRead(5)!= buttonState3){
      buttonState3 = digitalRead(5);
      if (buttonState3 == LOW) DigiKeyboard.println("pass4"); 
    }
  }
}
