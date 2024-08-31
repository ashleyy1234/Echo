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
  digitalWrite(LED_red, HIGH); // HIGH or LOW
  long duration , distance;
  digitalWrite (trigPin , LOW); // start trig at 0
  delayMicroseconds (2);
  digitalWrite (trigPin , HIGH); //The rising edge of trig pulse
  delayMicroseconds (10); // decides duration of trig pulse
  digitalWrite (trigPin , LOW); //falling edge of the trig pulse
  // NOTE: echo pin reads HIGH till it receives the reflected signal
  duration = pulseIn (echoPin , HIGH ); // Reading the duration for which echoPin was HIGH givesa
  //you the time the sensor receives a reflected signal at the echo pin
  distance = (duration / 2) / 29.1; //Calculate the distance of the reflecting surface in cm

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


