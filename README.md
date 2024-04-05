# Some practice in SMART system using C++

## Lab 1 Arduino simple trafic lights simulation

sketch.ino
```
const int redPin = 11; 
const int yellowPin = 10;
const int greenPin = 9;

enum TrafficLightColor {
  RED,
  YELLOW,
  GREEN
};

class TrafficLight {
  private:
    TrafficLightColor color; 

  public:
    TrafficLight() : color(RED) {}

    void changeColor() {
      switch (color) {
          case RED:
              color = GREEN;
              break;
          case YELLOW:
              color = RED;
              break;
          case GREEN:
              color = YELLOW;
              break;
          default:
            Serial.println("Unknown color\n"); 
            break;
      }
    }

    void setColor(TrafficLightColor newColor) {
      color = newColor;
    }

    void simulate() {
      switch (color) {
        case RED:
          digitalWrite(redPin, HIGH);
          digitalWrite(yellowPin, LOW);
          digitalWrite(greenPin, LOW);
          break;
        case YELLOW:
          digitalWrite(redPin, LOW);
          digitalWrite(yellowPin, HIGH);
          digitalWrite(greenPin, LOW);
          break;
        case GREEN:
          digitalWrite(redPin, LOW);
          digitalWrite(yellowPin, LOW);
          digitalWrite(greenPin, HIGH);
          break;
        default: 
          Serial.println("Can't switch color\n"); 
          break;
      }
    }
};

TrafficLight trafficLight;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  trafficLight.simulate();
  delay(3000);
  trafficLight.changeColor(); 
}
```
<img width="673" alt="trafic lights screenshot" src="https://github.com/daryabagmet/cpp/assets/20931427/875822d7-cd42-4008-b4cd-7ded96a3645e">

working demo on https://wokwi.com/projects/393415065610085377

## Lab 2 Arduino Christmas lights simulation

sketch.ino
```
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

```

<img width="667" alt="christmas ligths screenshot" src="https://github.com/daryabagmet/cpp/assets/20931427/45d74c9e-bff1-41d7-ba20-719a82c64304">

working demo on https://wokwi.com/projects/393416688041483265

## Lab 3 Arduino and Seven Segment Disply (4 digits)

sketch.ino
```
#include <SevSeg.h>

SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5}; 
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12,13};
  
  bool resistorsOnSegments = false; 
  bool updateWithDelays = false;
  bool leadingZeros = true; 
  bool disableDecPoint = false; 

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);

  sevseg.setBrightness(100); 
}

void loop() {

sevseg.setNumber(101, 2);
  sevseg.refreshDisplay();
}
```
<img width="669" alt="display screenshot" src="https://github.com/daryabagmet/cpp/assets/20931427/be006c15-f3c6-49bc-9f4e-f4e1bc8714c8">

working demo on https://wokwi.com/projects/393519471545390081

