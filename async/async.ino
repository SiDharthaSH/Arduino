unsigned long ms_from_start = 0;

#define LED1 11
unsigned long ms_prev_led1_state_change = 0;
unsigned long led1_state = LOW;
unsigned long led1_interval = 1000;

#define LED2 12
unsigned long ms_prev_led2_state_change = 0;
unsigned long led2_state = LOW;
unsigned long led2_interval = 2000;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  ms_from_start = millis();

  if (ms_from_start - ms_prev_led1_state_change >= led1_interval) {
    // led1_state = (led1_state + 1) % 2
    if (led1_state == LOW) {
      led1_state = HIGH;
    } else {
      led1_state = LOW;
    }
    digitalWrite(LED1, led1_state);
    ms_prev_led1_state_change = ms_from_start;
  }

  if (ms_from_start - ms_prev_led2_state_change >= led2_interval) {
    // led1_state = (led1_state + 1) % 2
    if (led2_state == LOW) {
      led2_state = HIGH;
    } else {
      led2_state = LOW;
    }
    digitalWrite(LED2, led2_state);
    ms_prev_led2_state_change = ms_from_start;
  }
}