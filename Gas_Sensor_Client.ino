/* This is for the gas sensor client */
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(6,7);

#include <Wire.h>

void setup() {
//  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event

}

void loop () {
  delay(100);
}

void requestEvent() {
  char sensorString[22] = "";
  /* Our sensors are: */
  /* A0: MQ8 */
  /* A1: MQ9 */
  /* A2: Air quality */
  /* A3: HCHO sensor */
  int sensor0 = analogRead(A0);
  int sensor1 = analogRead(A1);
  int sensor2 = analogRead(A2);
  int sensor3 = analogRead(A3);
//  mySerial.print('B');
//  mySerial.print(sensor0);
//  mySerial.print(',');
//  mySerial.print(sensor1);
//  mySerial.print(',');
//  mySerial.print(sensor2);
//  mySerial.print(',');
//  mySerial.println(sensor3);
  sprintf(sensorString, "B%04d,%04d,%04d,%04d\n", sensor0, sensor1, sensor2, sensor3);
  Serial.println(sensorString);
  Wire.write(sensorString);
}


