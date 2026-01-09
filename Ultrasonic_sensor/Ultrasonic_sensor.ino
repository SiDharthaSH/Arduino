const unsigned char trigPin = 3;
const unsigned char echoPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // start with clean signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // send trigger signal
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // wait till high signal is detected 
  // return pulse duration in micro secs
  float duration = pulseIn(echoPin, HIGH);

  // speed of sound is 343 m/s
  // 343 * 100 / 1000 * 1000 = 0.0343 cm/microsecs 
  float distance = 0.0343 * duration / 2;

  Serial.println(distance);
  delay(10);
}
