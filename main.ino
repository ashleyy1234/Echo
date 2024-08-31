#define sensorPin A0

// declare pins
const int trigPin = 13;
const int echoPin = 12;
const int  LED_red = 4;
const int  LED_green = 2;
const int  LED_blue = 6;

void setup () {
  // Initialize serial
  Serial.begin (9600);
  delay(500);

  // define pin modes
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(LED_green, OUTPUT);
  pinMode(LED_blue, OUTPUT);
}

void loop () {
  digitalWrite(LED_red, HIGH); 
  long duration , distance;
  digitalWrite (trigPin , LOW); 
  delayMicroseconds (2);
  digitalWrite (trigPin , HIGH); 
  delayMicroseconds (10); 
  digitalWrite (trigPin , LOW); 
  duration = pulseIn (echoPin , HIGH ); 
  distance = (duration / 2) / 29.1;

  Serial.print("distance:");
  Serial.println(distance);
  delay(500);

  if (distance<=10){
    digitalWrite(LED_red, LOW); // HIGH or LOW
    digitalWrite(LED_green, HIGH); // HIGH or LOW
    digitalWrite(LED_blue, LOW); // HIGH or LOW
    bool isTalking=false;
    for (int i=0; i<500; i++){
      if (isTalking){
        digitalWrite(LED_green, LOW); // HIGH or LOW
        digitalWrite(LED_blue, HIGH); // HIGH or LOW
        break;
      }
      int sensorValue = analogRead(sensorPin);
      Serial.println(sensorValue);
      delay(50);
      if (sensorValue>20){
        isTalking=true;
      }
    }
    delay(7000);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
  }
}


