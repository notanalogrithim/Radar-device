#include <HCSR04.h>
HCSR04 hc(3, 4); //(trig,echo)
int ledPin = 13;
bool run;
double working[10];
bool test(int numReadings = 10) {
  int count = 0;
  float prevDistance = hc.dist(); 
  delay(50);
  for (int i = 0; i < numReadings; i++) {
    float currentDistance = hc.dist();
    delay(50);
    Serial.println(currentDistance);
    if (abs(prevDistance - currentDistance) <= 5) {
      count++;
    }
    prevDistance = currentDistance;
  }
  if (count == numReadings) {
    Serial.println("All distances were stable.");
    return true; 
  } else {
    Serial.println("Not all distances were stable.");
    return false; 
  }
}

void setup() {
  Serial.begin(9600);
  delay(500);
  run = test();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (run == true) {
    double cm = hc.dist();
    Serial.println(cm);
    if(cm < 50){
      Serial.println(" less than 50 cm away");
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    delay(250);
  }
}