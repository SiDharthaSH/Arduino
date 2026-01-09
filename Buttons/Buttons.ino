const unsigned char onPin = 9;
const unsigned char offPin = 8;
const unsigned char ledPin = 6;

void setup() {
  Serial.begin(9600); // use serial monitor at 9600 baudrate to check output
  pinMode(onPin, INPUT_PULLUP); // HIGH voltage is passing by default and LOW when button pressed
  pinMode(offPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(onPin) == LOW) {
    digitalWrite(ledPin, HIGH); // analogWrite takes val of 0-255
    Serial.println("Turned ON");
  }

  if (digitalRead(offPin) == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println("Turned OFF");
  }
}