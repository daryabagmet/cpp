const int button1Pin = 2; 
const int button2Pin = 3;
const int numLEDs = 9; 

int ledPins[numLEDs] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

enum Mode {
  RANDOM,
  ALTERNATING,
  CHASE
};

Mode currentMode = RANDOM; 
bool isOn = false; 

void setup() {
  pinMode(button1Pin, INPUT_PULLUP); 
  pinMode(button2Pin, INPUT_PULLUP);

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }
}

void loop() {
  if (digitalRead(button1Pin) == LOW) {
    switchMode(); 
    delay(200); 
  }

  if (digitalRead(button2Pin) == LOW) {
    toggleOnOff();
    delay(200); 
  }

  if (isOn) { 
    switch (currentMode) {
      case RANDOM:
        displayRandom();
        break;
      case ALTERNATING:
        displayAlternating();
        break;
      case CHASE:
        displayChase();
        break;
    }
  } else {
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void switchMode() {
  currentMode = static_cast<Mode>((static_cast<int>(currentMode) + 1) % 3);
}

void toggleOnOff() {
  isOn = !isOn;
}

void displayRandom() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], random(2)); 
  }
}

void displayAlternating() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], i % 2);
  }
}

void displayChase() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}
