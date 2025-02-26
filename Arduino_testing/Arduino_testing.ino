#include <Wire.h>

#define ADDRESS 0x10

byte echo_byte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World");

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("huh");
  pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveData(int bytecount)
{
  Serial.println("DATA!!!");
  for (int i = 0; i < bytecount; i++) {
    echo_byte = Wire.read();
    }
  digitalWrite(2,echo_byte);
}

void sendData()
{
  Serial.println("RESPONDING!!!");
  Wire.write(echo_byte);
}
