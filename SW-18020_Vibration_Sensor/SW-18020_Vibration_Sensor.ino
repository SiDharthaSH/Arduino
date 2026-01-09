const unsigned char sensorPin = 12;
const unsigned char ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int sensorRetval = digitalRead(sensorPin);
  Serial.print(sensorRetval);
  Serial.println("");
  if ( sensorRetval == LOW) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
