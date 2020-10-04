
/*
 * Used to send AT commands to WiFi device on EducationShield
 * 
 * Use the serial monitor to send commands
 * 
 * if you and send AT and recieve OK then you have it setup correctly
 */


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 12); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Arduino Serial is working");

  // set the data rate for the SoftwareSerial port
  // I use 9600, factory default is 115200
  mySerial.begin(9600);
  mySerial.println("Software Serial is working");
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
