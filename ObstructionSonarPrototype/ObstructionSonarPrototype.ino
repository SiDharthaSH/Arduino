const unsigned char sigPin = 12; // Signal Pin
const unsigned char rsPin = 11; // Range Setting Pin
const unsigned char msPin = 10; // Mode Setting Pin
const unsigned char oLedPin = 9; // Obstruction Mode Led Indicator
const unsigned char sLedPin = 8; // Sonar Mode Led Indicator
const unsigned char buzzerPin = 7; // Buzzer Pin

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
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);
  pinMode(sigPin, INPUT);
  return pulseIn(sigPin, HIGH);
}

void loop() {
  distance = scan();
  if (digitalRead(rsPin) == LOW) {
    modeIndicator();
    range = scan();
    range += 10; // grace detection range
  } else if (digitalRead(msPin) == LOW) {
    modeIndicator('o');
    if (distance < range) {
      Serial.print("[O] IN +");
      Serial.println(range - distance);
      tone(buzzerPin, 800);
      delay(200);
      noTone(buzzerPin);
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
      Serial.print("[O] OUT -");
      Serial.println(distance - range);
    }
  }
}