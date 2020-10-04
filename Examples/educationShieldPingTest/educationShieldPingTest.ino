/*
 * This library was developed on an Arduino Uno with Education Shield
 * The software serial ports should be able to be changed as needed.
 * The wifi used was DSD TECH ESP-WROOM-02D WiFi UART 
 * 
 * I have found the first ping normally fails, then is good after that
 */


#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 12); // RX, TX

// This can be any IP or web address
String ipAddress = "www.google.com";

void setup() {
 
  Serial.begin(9600);
  while (!Serial) {
  }

  Serial.println("Arduino Serial working");

  // set the data rate for the SoftwareSerial port
  // I use 9600, but default is 115200 from factory
  mySerial.begin(9600);
  mySerial.println("Software Serial working if you see this");

  // show my ip
  mySerial.println("=======  My IP INFO  ==============");
  mySerial.println("AT+CIFSR");

  delay(1500);
  
}

void loop() { // run over and over

    mySerial.println("AT+PING=\"" + ipAddress + "\"");
    
    delay(30);
    
    showResponse();
    
    delay(2000);
    }
    
    
    void showResponse(){
    
        while(mySerial.available()) {
          String inData = mySerial.readStringUntil('\n');
          
                Serial.println("Command Rx: " + inData);
                
                if(inData.startsWith("O")) {
                  Serial.println("===============");
                  Serial.println("Successful Ping");
                  Serial.println("===============");
                  }
          
          }
}
