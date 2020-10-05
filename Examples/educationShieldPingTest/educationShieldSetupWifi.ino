/*
 * Setup your wifi on educationSheild
 * enter your SSID and Password
 * 
 * Once your wifi is setup if will loop pinging google
*/

#include<SoftwareSerial.h>

SoftwareSerial a(2,12);

// home
String ssid = "HIHA2.4G WIFI-6182";
String pass = "66668888";

int delayTime = 1500;
int setupDelayTime = 1000;

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Started");

  // I use 9600, but factory default is 115200
  a.begin(9600);
  a.println("a Serial Started");

  delay(setupDelayTime);

  Serial.println("Reset Wifi");
 //   a.println("AT+RST\r\n");   // set esp8266 as client
 //   delay(1000);

    showResponse(setupDelayTime);

    Serial.println("Start AP and This");
    a.println("AT+CWMODE=3\r\n");   // set esp8266 as client
    showResponse(setupDelayTime);

    Serial.println("Join Access Point");
    a.println("AT+CWJAP=\""+ssid+"\",\""+pass+"\"\r\n");  // set your home router SSID and password
    showResponse(setupDelayTime);

    Serial.println("show My IP");
    a.println("AT+CIFSR\r\n");   
    showResponse(5000);

    Serial.println("transition mode normal");
    a.println("AT+CIPMODE=0\r\n");
    showResponse(setupDelayTime);

    Serial.println("Single TCP Connection setup");
    a.println("AT+CIPMUX=0\r\n");
    showResponse(setupDelayTime);  

    Serial.println("Wifi is setup");
  
}

void loop() {


    Serial.println("Ping: ");
    a.println("AT+PING=\"www.google.com\"");
    showResponse(delayTime);

}



void showResponse(int waitTime){
    long t = millis();
    char c;
 
       while (t + waitTime > millis()){          
           
              while(a.available()) {
                    String inData = a.readStringUntil('\n');
      
                    Serial.println("Command Rx: " + inData);
              }
         }              
}
