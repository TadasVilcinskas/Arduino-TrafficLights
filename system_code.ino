// Define pins for LEDs
const int carRedPin = 8;
const int carYellowPin = 9;
const int carGreenPin = 10;

const int personRedPin = 5;
const int personGreenPin = 6;

// Define pins for ultrasonic sensor
const int trigPin = 11;
const int echoPin = 12;

// Define distance threshold in centimeters
const int distanceThreshold = 30;

void setup() {
  // Set LED pins as outputs
  pinMode(carRedPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);

  pinMode(personRedPin, OUTPUT);
  pinMode(personGreenPin, OUTPUT);

  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  int distance = getDistance();

  // Check if the distance is within the threshold
  if (distance > 0 && distance <= distanceThreshold) {
    // Object detected - switch to yellow, then red
    digitalWrite(carGreenPin, LOW);
    digitalWrite(carYellowPin, HIGH);
    delay(3000); // Yellow for 3 seconds
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carRedPin, HIGH);
    digitalWrite(personRedPin, LOW);
    digitalWrite(personGreenPin, HIGH);

    // Wait for 6 seconds if an object remains within range
    distance = getDistance();
    while (distance > 0 && distance <= distanceThreshold) {
      distance = getDistance();
      for (int i = 0; i <= 24; i++) {  // Timer resets if object is in range
        delay(250);
        distance = getDistance();
        if (distance <= 30) {
          i = 0;
        }
      }
    }

    // Back to green
    digitalWrite(carRedPin, LOW);
    digitalWrite(carGreenPin, HIGH);
    digitalWrite(personRedPin, HIGH);
    digitalWrite(personGreenPin, LOW);

  } else {
    // No object detected - stay on green
    digitalWrite(carGreenPin, HIGH);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carRedPin, LOW);
    digitalWrite(personRedPin, HIGH);
    digitalWrite(personGreenPin, LOW);
  }

  delay(250); // Short delay before next loop iteration
}

// Function to get distance from HC-SR04 sensor
int getDistance() {
  // Send a 10-microsecond pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from Echo
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}
