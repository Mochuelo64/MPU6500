#include <Arduino.h>
#include <Wire.h>
#include "MPU6050.h"
#include "I2Cdev.h"


MPU6050 sensor;

int ax, ay, az; //Valores RAW del acelerómetro
int gx, gy, gz; //Valores RAW del giroscopio 

void setup() {
  Serial.begin(57600);    //Iniciando monitor serial
  Wire.begin();           //Iniciando I2C  
  sensor.initialize();    //Iniciando el MPU6050

  if (sensor.testConnection()) Serial.println("Conección Exitosa");
  else Serial.println("Error");
}

void loop() {
  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);

  //Mostrar las lecturas separadas por un [tab]
  Serial.print("a[x y z] g[x y z]:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(100);
}