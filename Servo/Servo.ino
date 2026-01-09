#include <Servo.h>

Servo myservo;

// red is positive and brown is ground

void setup() {
  myservo.attach(13); // yellow wire
}

void loop() {
    myservo.write(-10);
    delay(100);
    myservo.write(10);
    delay(100);
}
