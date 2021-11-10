#include <ESP8266_Lib.h>

#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "lNiQNz128N_DDN6Eub4zfvK8Qvi574iO"; // token led 

char ssid[] = "AAA";
char pass[] = "123456789";

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); //ต่อขา  RX, TX

#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

void setup()
{
  
  
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(100);

  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}
