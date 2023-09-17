#include <WiFi.h>
//#include <ThingSpeak.h>;//
/*#include "ZMPT101B.h"
#include "ACS712.h"
#include "DHT.h"
#define DHTTYPE DHT11 */


#define vol 35
#define cur 32
#define vib 33
#define tem 34
#define hum 25
#define rel 15

const char* ssid = "OPPO F17";
const char* password = "vcet12345";
//unsigned long myChannelNumber = 1562970;//
//const char * myWriteAPIKey = "AD1P0XOM13TEW92R";//

WiFiClient client;
float volval,curval,temval;
int vibval,humval;

/*ZMPT101B voltageSensor(vol);
ACS712 currentSensor(ACS712_30A, cur);
DHT dht(hum, DHTTYPE);*/

void setup() 
{
pinMode(vol,INPUT);
pinMode(cur,INPUT);
pinMode(vib,INPUT);
pinMode(tem,INPUT);
pinMode(hum,INPUT);
pinMode(rel,OUTPUT);
/*voltageSensor.calibrate();
currentSensor.calibrate();*/
/*dht.begin();
WiFi.begin(ssid, password);*/
//ThingSpeak.begin(client);//
}

void loop() 
{
/*/VOLTAGE SENSOR/*/
volval = voltageSensor.getVoltageAC();
/*/CURRENT SENSOR/*/
curval = currentSensor.getCurrentAC();
/*/VIBRATION SENSOR/*/
if (digitalRead(vib) == LOW)
{
  vibval = 1;
}
else
{
  vibval = 0;
}
/*/TEMPERATURE SENSOR/ */
temval = analogRead(tem);
temval = (temval/1024.0)*500;
/*/HUMIDITY SENSOR/ */
humval = dht.readHumidity();
/*/STATUS RELAY/ */
if (volval > 235 || curval > 6 || vibval == 1 || temval > 100 || humval > 75)
{
digitalWrite(relay,LOW);
stat = 1;
}
else
{
digitalWrite(relay,HIGH);
stat = 0;
}
/*/THINGSPEAK/
ThingSpeak.setField(1, volval);
ThingSpeak.setField(2, curval);
ThingSpeak.setField(3, vibval);
ThingSpeak.setField(4, temval);
ThingSpeak.setField(5, humval);
ThingSpeak.setField(6, stat);
//ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);//
delay(15000);*/
}
