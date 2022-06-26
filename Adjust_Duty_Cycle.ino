const int numSamples = 10;
const int analogPin = 0;
const float divFactor = 1.9; //found from experimentation
int analogVal;
int sum;
float voltage;
float analogInput;
float dutyCycle;
float scaledDC;

void setup() {
  Serial.begin(9600);
  dutyCycle = 50;
}

void loop() {
  scaledDC = scaleDutyCycle(dutyCycle);
  
}

float scaleDutyCycle(float dc) {
  //take 10 analog samples
  for (int i = 0; i < numSamples; i++) {
    analogVal = analogRead(analogPin);
    sum += analogVal;
    delay(10); //avoid potentially jumbled readings
  }

  //calculate voltage and print to serial monitor
  voltage = ((float)sum / (float)numSamples * 5.0 / 1023.0) * (float)divFactor;
  Serial.print("V = ");
  Serial.println(voltage);
  scaledDC = dc / (voltage / 9.0);
  Serial.print("DC = ");
  Serial.println(scaledDC);
  sum = 0;
  
  return scaledDC;
}
