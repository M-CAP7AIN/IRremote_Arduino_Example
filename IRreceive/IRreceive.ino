#include <IRremote.h>

const int IR_RECEIVE_PIN = 11;  //the SIG of receiver module attach to pin2

void setup() {
  Serial.begin(9600);    //initialize serial,baudrate is 9600
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode())
  {
    //Serial.println(IrReceiver.decodedIRData.address);
    Serial.println(IrReceiver.decodedIRData.command);
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    Serial.println(IrReceiver.decodedIRData.numberOfBits);
    Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));
  }

  IrReceiver.resume();
}
