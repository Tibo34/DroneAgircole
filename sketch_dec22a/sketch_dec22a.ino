
#include <math.h>
#include <dht11.h>
#include <stdlib.h>
#include <stdio.h>
#include <SD.h>
#include <SoftwareSerial.h> 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>



#define DHT11PIN A0 // broche dht11 capteur humidité et température
#define photocellPin A14// broche capetur luminosité

#define SEALEVELPRESSURE_HPA (1013.25)



float tempdht; // On initialise la variable de température
float humidtedht;

dht11 DHT11;

Adafruit_BME280  bme;
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);


int photocellReading;
             
File myFile;
//const byte HC12RxdPin = 4;    
//const byte HC12TxdPin = 5;    
//SoftwareSerial HC12(HC12TxdPin,HC12RxdPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11  test!!");
  if (!bme.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");  
   while(1);
  }
  
    // see if the card is present and can be initialized:
  /*if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    return;
  }
   myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
     while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }*/
 
}

void loop() { 

  // initialisation lecture température et humidité
  DHT11.read(DHT11PIN);
  photocellReading = analogRead(photocellPin);
  // BME

  Serial.print("BME : ");
 Serial.println(bme.readTemperature());
  
  // DHT11 
  float humidite=DHT11.humidity;
  float temperature=DHT11.temperature;
  String strAffiche="Lecture capteur : \n";
  

  
  String strHumidite=String(humidite,2);
  String strTemp=String(temperature,2);
  String humMessage=" DHT11 : Humidité (%) : ";
  String temMess=" - Température (°C) : ";
  String strphoto=String(photocellReading,DEC);
  String messhoto=" lecture lumoinosité : Analog reading = ";
  strAffiche+=humMessage+strHumidite+temMess+strTemp+messhoto+strphoto;
 
 // the raw analog reading
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 10) {
    strAffiche+=" - Noir ";     
  } else if (photocellReading < 200) {
     strAffiche+=" - Sombre ";    
  } else if (photocellReading < 500) {      
      strAffiche+=" - Sombre ";     
  } else if (photocellReading < 800) {
      strAffiche+=" - Lumineux "; 
  } else {
      strAffiche+=" - Tres lumineux ";     
  }
  Serial.println(strAffiche);

  /*if(HC12.available()){                         
    
    Serial.write(HC12.read());   
           
    
    } 
    
  if(Serial.available()){                  
    
    HC12.write(Serial.read());   
    
    }*/
  delay(2000); //un délai pour que le tout soit lisible
}
