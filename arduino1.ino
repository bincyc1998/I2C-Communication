#include <Wire.h>


void setup() {
  Wire.begin(); 
  Serial.begin(9600);
}

void loop() {
   Serial.println("Sending GREEN");
  Wire.beginTransmission(8);
  Wire.write("GREEN");
  Wire.endTransmission();
  delay(5000);

  // Send RED
  Serial.println("Sending RED");
  Wire.beginTransmission(8);
  Wire.write("RED");
  Wire.endTransmission();
  delay(5000);

  // Send ORANGE
  Serial.println("Sending ORANGE");
  Wire.beginTransmission(8);
  Wire.write("ORANGE");
  Wire.endTransmission();
  delay(5000);
}
