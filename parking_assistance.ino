const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int redPin = 6;    // Leg 1 of LED
const int greenPin = 7;  // Leg 2 of LED

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // --- 1. Get Distance ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);

  // --- 2. The Logic Zones ---
  
  if (distance == 0) {
    // Error state (Sensor not reading) - Turn everything off to avoid noise
    noTone(buzzerPin);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  }
  else if (distance < 10) {
    // DANGER ZONE (< 10cm)
    // LED: RED
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    
    // Sound: High Pitch Alarm
    tone(buzzerPin, 2000); 
    delay(100); 
    noTone(buzzerPin);
    delay(50); // Very fast beeping
  }
  else if (distance >= 10 && distance < 25) {
    // WARNING ZONE (10-25cm)
    // LED: YELLOW (Red + Green ON)
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    
    // Sound: Lower Pitch, Slower Beep
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  }
  else {
    // SAFE ZONE (> 25cm)
    // LED: GREEN
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    
    // Sound: Silence
    noTone(buzzerPin);
    delay(100);
  }
}