#include <SPI.h>
#include <Adafruit_VL53L0X.h>
#include <Arduino.h>
#include <cmath> // used for the cos and sin math

//variable land
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

VL53L0X_RangingMeasurementData_t measure;

const int SAMPLE_SIZE = 10;
float readings[SAMPLE_SIZE];

float x;
float y;
float A; 



void setup() { 
  //esp32 initialization for constant/automatic sensor reading
  
  // put your setup code here, to run once:
    // put your main code here, to run repeatedly:
  Serial.begin(115200);

  while (! Serial) { 
    delay (1);
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

  Serial.print("Reading a measurement... ");

  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);

    A = 0; // example angle for now
    
    const float DEG_TO_RAD = 3.14159265f / 180.0f; 
    float radians = A * DEG_TO_RAD; 
    float distance = measure.RangeMilliMeter; // example radius for now

    x = distance * cos(radians);
    y = distance * sin(radians);

    Serial.print("X: ");
    Serial.println(x);

    Serial.print("Y: ");
    Serial.println(y);

  } else {
    Serial.println(" out of range ");
  }
  
//void Loop() {
//float distance * A 


}

  {
    delay(100);
  }
}