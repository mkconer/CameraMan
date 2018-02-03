// Arduino Camera Man
// Mark Conner version 1.0


#include <SoftwareSerial.h>             // Bluetooth communication
SoftwareSerial myBluetooth(10, 11);     // Bluetooth RX(pin 10), TX(pin(11)

#include <Servo.h>                      // Servo library 
Servo myservo;                          // Servo name

void setup()
{
  myservo.attach(9);                    // Servo signal wire to pin 9  
  Serial.begin(115200);                 // Serial communications to computer
  
  myBluetooth.begin(9600);              // Bluetooth communication - DO NOT MODIFY speed
}

void loop()
{
  
  if(myBluetooth.available()> 0 )       // receive number from bluetooth
  {
    int servopos = myBluetooth.read();  // save the received number to servopos
    Serial.println(servopos);           // serial print servopos current number received from bluetooth
    myservo.write(servopos);            // rotate the servo the angle received from the android app
  }


}


