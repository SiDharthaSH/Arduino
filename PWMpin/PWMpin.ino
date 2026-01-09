const int pwmPin = 6;

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  for (int Val = 0; Val <= 255; ++Val) {
    analogWrite(pwmPin, Val);
    delay(50);
  }
  for (int Val = 255; Val >= 0; --Val) {
    analogWrite(pwmPin, Val);
    delay(50);
  }
}