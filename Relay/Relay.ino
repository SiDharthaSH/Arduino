const unsigned char realyPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(realyPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { // if something is there to read
    String str = Serial.readStringUntil('\n');
    if (strcmp(str, "hi") == 0) {
      Serial.println(str);
    }
  }
}