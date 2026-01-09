const unsigned char trigPin = 12;   // Trigger Signal Pin
const unsigned char echoPin = 11;   // Echo Signal Pin
const unsigned char rsPin = 10;     // Range Setting Pin
const unsigned char msPin = 9;      // Mode Setting Pin
const unsigned char oLedPin = 8;    // Obstruction Mode Led Indicator
const unsigned char sLedPin = 7;    // Sonar Mode Led Indicator
const unsigned char buzzerPin = 6;  // Buzzer Pin

unsigned long range = 0;
unsigned long distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rsPin, INPUT_PULLUP);
  pinMode(msPin, INPUT_PULLUP);
  pinMode(oLedPin, OUTPUT);
  pinMode(sLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("[!] Set Range");
  digitalWrite(oLedPin, LOW);
  digitalWrite(sLedPin, LOW);
  while (digitalRead(rsPin) == HIGH) {}
}

void modeIndicator(char mode = '\0') {
  switch (mode) {
    case 'o':
      digitalWrite(oLedPin, HIGH);
      digitalWrite(sLedPin, LOW);
      break;
    case 's':
      digitalWrite(oLedPin, LOW);
      digitalWrite(sLedPin, HIGH);
      break;
    default:
      digitalWrite(oLedPin, HIGH);
      digitalWrite(sLedPin, HIGH);
  }
}

unsigned long scan() {
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void loop() {
  if (digitalRead(rsPin) == LOW) {
    modeIndicator();
    range = scan();
    range += 10;  // grace detection range
    Serial.print("Range: ");
    Serial.println(range);
  } else {
    distance = scan();
    if (digitalRead(msPin) == LOW) {
      modeIndicator('o');
      if (distance < range) {
        Serial.print("[O] IN +");
        Serial.println(range - distance);
        //tone(buzzerPin, 800);
        digitalWrite(buzzerPin, HIGH);
        delay(200);
        //noTone(buzzerPin);
        digitalWrite(buzzerPin, LOW);
        delay(200);
      } else {
        Serial.print("[O] OUT -");
        Serial.println(distance - range);
      }
    } else {
      modeIndicator('s');
      if (distance < range) {
        unsigned short delayMs = (float)distance / range * 1000;
        Serial.print("[S] IN +");
        Serial.print(range - distance);
        Serial.print(" DELAY ");
        Serial.print(delayMs);
        Serial.println("ms");
        tone(buzzerPin, 800);
        delay(200);
        noTone(buzzerPin);
        delay(delayMs);
      } else {
        Serial.print("[S] OUT -");
        Serial.println(distance - range);
      }
    }
  }
}