
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
