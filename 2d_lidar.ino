
#include <SPI.h>
#include <Adafruit_VL53L0X.h>
#include <Arduino.h>
#include <cmath> // used for the cos and sin math

//variable land
Adafruit_VL53L0X lox = Adafruit_VL53L0X();



void setup() { 
  //esp32 initialization for constant/automatic sensor reading
    //math
   VL53L0X_RangingMeasurementData_t measure;
   float A = 0; // example angle for now
   const float DEG_TO_RAD = 3.14159265f / 180.0f; 
   float radians = A * DEG_TO_RAD; 
   float R = measure.RangeMilliMeter; // example radius for now
   float x = R * cos(radians);
   float y = R * sin(radians);
   
  
  // put your setup code here, to run once:
    // put your main code here, to run repeatedly:
Serial.begin(115200);
while (! Serial) { 
  delay (1)
  }

  lox.begin();
  lox.startContinuous();
  lox.setMeasurementTimingBudgetMicroSeconds(20000); // set timing budget to 20ms
  lox.setSignalRateLimit(0.1); // set signal rate limit to 0.1 MCPS
  lox.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18); // first laser range
  lox.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14); // second laser range (more detailed)

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

    const int SAMPLE_SIZE = 10;
    float readings[SAMPLE_SIZE];

    // this is the conversion from degrees to radians
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
  }
  
  {
      delay(100);
  }
}
