
#include <SPI.h>
#include "Adafruit_VL53L0X.h"
#include <Arduino.h>
#include <cmath> // used for the cos and sin math

//variable land
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int SAMPLE_SIZE = 10;
float readings[SAMPLE_SIZE];
float R = 5; // example radius for now


void setup() {
  // put your setup code here, to run once:
    // put your main code here, to run repeatedly:
Serial.begin(115200)
while (! Serial) {
  delay (1)
  //esp32 initialization for constant/automatic sensor reading
  lox.begin();
  lox.startContinuous();
  lox.setMeasurementTimingBudgetMicroSeconds(20000);
  lox.setSignalRateLimit(0.1);
  lox.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  }
}

void loop() {


 Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
   VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");

    //math
    float radians = A * DEG_TO_RAD;
    float x = R * cos(radians);
    float y = R * sin(radians);
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  }
  
  {
      delay(100);
  }
}
}
