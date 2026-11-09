const int RED_PIN = 26;
const int BLUE_PIN = 25;
const int BTN_PIN = 27;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) { 
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }
}
