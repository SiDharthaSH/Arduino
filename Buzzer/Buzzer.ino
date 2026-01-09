const unsigned char buzzerPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (unsigned char i = 0; i < 5; ++i) {
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }

  for (unsigned char i = 0; i < 10; ++i) {
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    delay(50);
  }
}
