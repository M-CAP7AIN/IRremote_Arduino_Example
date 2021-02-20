#include <IRremote.h>

void setup() {
  Serial.begin(9600);    //initialize serial,baudrate is 9600
  IrSender.begin(false);
}

void loop() {
  if (Serial.available() > 0) {
    long incomingStr = Serial.parseInt();
    Serial.println("OK");
    IrSender.sendNECRaw(incomingStr, 1);
    delay(150);
  }

 }
