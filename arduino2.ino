#include <Wire.h>

String command = "";
bool commandReceived = false;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  Wire.begin(8); // Join I2C as Slave with address 8
  Wire.onReceive(receiveEvent); 
}

void loop() {
  
    if (commandReceived) {
    Serial.print("Received: ");
  Serial.println(command);
  
    if (command == "GREEN") {
      digitalWrite(13, HIGH);
      Serial.print("green led on..\n");
      delay(5000);
      digitalWrite(13, LOW);
      Serial.print("green led off..\n");
      
    }
    else if( command == "RED"){
      digitalWrite(12, HIGH);
      Serial.print("red led on..\n");
      delay(5000);
      digitalWrite(12, LOW);
      Serial.print("red led off..\n");
    }
    else if ( command == "ORANGE"){
      
      digitalWrite(2, HIGH);
      Serial.print("orange led on..\n");
      delay(5000);
      digitalWrite(12, LOW);
      Serial.print("orange led off..\n");
      
      
    }
      command = "";
    commandReceived = false;
}
  
}

void receiveEvent(int howMany)
{
  

  while (Wire.available()) {
    char c = Wire.read();
    command += c;
  }
  commandReceived = true;
}

