const int trigPin = 3;
const int echoPin = 2;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int tempPin;
const int READINGNUM = 5;
const int FREQUENCY = 0;
const int AMOUNT = 100;
const int ledPin = 13;
unsigned int readings[READINGNUM];
unsigned int total = 0;
unsigned int total2;
unsigned int time = 0;
float finalisedData[AMOUNT];
double mm;
bool run = true;
// starts at -10 degrees and goes up to 50
unsigned int soundSpeed[] = { 263.3, 264.06, 264.82, 265.58, 266.33, 267.08, 267.83, 268.57, 269.32, 270.06, 270.8, 271.54, 272.28, 273.01, 273.74, 274.47, 275.2, 275.93, 276.65, 277.37, 278.1, 278.81, 279.53, 280.25, 280.96, 281.67, 282.38, 283.09, 283.8, 284.5, 285.2, 285.9, 286.6, 287.3, 288.0, 288.69, 289.38, 290.08, 290.77, 291.45, 292.14, 292.82, 293.51, 294.19, 294.87, 295.55, 296.22, 296.9, 297.57, 298.24, 298.91, 299.58, 300.25, 300.92, 301.58, 302.24, 302.91, 303.57, 304.22, 304.88, 305.54, 306.19, 306.85, 307.5, 308.15, 308.8, 309.44, 310.09, 310.74, 311.38, 312.02, 312.66, 313.3, 313.94, 314.58, 315.21, 315.85, 316.48, 317.11, 317.74, 318.37, 319.0, 319.63, 320.25, 320.88, 321.5, 322.12, 322.74, 323.36, 323.98, 324.6, 325.22, 325.83, 326.45, 327.06, 327.67, 328.28, 328.89, 329.5, 330.1, 330.71, 331.32, 331.92, 332.52, 333.12, 333.72, 334.32, 334.92, 335.52, 336.11, 336.71, 337.3, 337.9, 338.49, 339.08, 339.67, 340.26, 340.85, 341.43, 342.02, 342.6, 343.19, 343.77, 344.35, 344.93, 345.51, 346.09, 346.67, 347.25, 347.82, 348.4, 348.97, 349.55, 350.12, 350.69, 351.26, 351.83, 352.4, 352.97, 353.53, 354.1, 354.66, 355.23, 355.79, 356.35, 356.91, 357.47, 358.03, 358.59, 359.15, 359.71, 360.26, 360.82, 361.37, 361.93, 362.48, 363.03, 363.58, 364.13, 364.68, 365.23, 365.78, 366.33, 366.87, 367.42, 367.96, 368.5, 369.05, 369.59, 370.13, 370.67, 371.21, 371.75, 372.29, 372.83, 373.36, 373.9, 374.43, 374.97, 375.5, 376.03, 376.57, 377.1, 377.63, 378.16, 378.69, 379.21, 379.74, 380.27, 380.8, 381.32, 381.85, 382.37, 382.89, 383.41, 383.94, 384.46, 384.98, 385.5, 386.02};
float duration() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  unsigned int duration = (echoPin, HIGH, 30000);
  return duration;
}

float distance(duration) {
  int temp = 20;
  // Temperature sensor needs to be added 
  float speedOfSound = soundSpeed[temp - 10];
  unsigned int mm = ((speedOfSound)*duration) / 2;
  return mm;
}


float calculateMean(unsigned int array[], int length) {
  float sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }
  return sum / length;
}

float calculateStandardDeviation(unsigned int array[], int length, float mean) {
  float sum;
  for (int i = 0; i < length; i++) {
    sum += pow(array[i] - mean, 2);
  }
  return sqrt(sum / length);
}

float calculateZScore(unsigned int value, float mean, float standardDeviation) {
  return (value - mean) / standardDeviation;
}
void setup(){
  Serial.begin(9600);
  delay(500);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);

}
void loop(){
  while(run == true){
    if(distance(distance())< 500){
      Serial.println(" less than 50 cm away");
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    delay(250);
  }
}