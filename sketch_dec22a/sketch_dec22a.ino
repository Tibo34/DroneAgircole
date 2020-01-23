
#include <math.h>
#include <dht11.h>


#include <stdlib.h>
#include <stdio.h>


#define DHT11PIN A0 // broche dht11
#define lm35Pin A2 // lm35
#define fp=fopen("D:/Adruino","w");

float tempdht; // On initialise la variable de température
float humidtedht;
int b=3975;
dht11 DHT11;
float tempLm35;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11  test!!");
}

void loop() { 
  // initialisation lecture température et humidité
  DHT11.read(DHT11PIN);
  File *fp;
  fp=fopen("D:/Adruino","w");
  fprintf(fp,"This is testing ... \n");
  fclose(fp);
  
  Serial.print("Humidité (%) : ");
  Serial.print((float)DHT11.humidity,2);// lecture humidité
  Serial.print("\t");
  Serial.print("Température (°C) : ");// lecture température
  Serial.println((float)DHT11.temperature,2); 
  delay(2000); //un délai pour que le tout soit lisible
}
