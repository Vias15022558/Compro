#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5 // D1 ต่อ IN1
#define RightMotorDir 0  // D3 ต่อ IN2
#define LeftMotorSpeed 4  // D2 ต่อ IN3
#define LeftMotorDir 2  // D4 ต่อ IN4

char auth[] = "mhBFRpBT8QF_8KVO_x-2P4KKb14ZIjGO"; 
char ssid[] = "AAA";
char pass[] = "123456789";

void setup()
{
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);

 pinMode(RightMotorSpeed, OUTPUT);
 pinMode(RightMotorDir, OUTPUT);
 pinMode(LeftMotorSpeed, OUTPUT);
 pinMode(LeftMotorDir, OUTPUT);
}

void loop()
{
 Blynk.run();
}

void halt()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, HIGH);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
 digitalWrite(RightMotorDir, LOW);
 digitalWrite(LeftMotorDir, HIGH);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, LOW);
} 

void left()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, LOW);
 digitalWrite(RightMotorSpeed, LOW);
 digitalWrite(LeftMotorSpeed, HIGH);
}

void progress()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, HIGH); //ทิศทาง
 digitalWrite(RightMotorSpeed, LOW); 
 digitalWrite(LeftMotorSpeed, LOW);
}

void recede()
{
 digitalWrite(RightMotorDir, LOW);
 digitalWrite(LeftMotorDir, LOW);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, HIGH);
}



BLYNK_WRITE(V0)
{
 if (param[0])
 progress();
 else
 halt();
}

BLYNK_WRITE(V1)
{
 if (param[0])
 recede();
 else
 halt();
}

BLYNK_WRITE(V2)
{
 if (param[0])
 right();
 else
 halt();
}

BLYNK_WRITE(V3)
{
 if (param[0])
 left();
 else
 halt();
}
