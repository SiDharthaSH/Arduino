// goes to base to:-
// 1. start open npn gate
// 2. amplify current (Ie = Ic = hfe * Ib)
const unsigned char basePin = 3;
const unsigned char ledFreq = 5;

void setup() {
  pinMode(basePin, OUTPUT);
}

void loop() {
  for (unsigned short i = 0; i <= 255; ++i) {
    analogWrite(basePin, i);
    delay(ledFreq);
  }
  for (short i = 255; i >= 0; --i) {
    analogWrite(basePin, i);
    delay(ledFreq);
  }
}
