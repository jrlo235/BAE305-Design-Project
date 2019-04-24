#define trigPin 13
#define echoPin 12
#define lever 11


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lever, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 23) {  // This is where the Lever On/Off happens
    digitalWrite(lever,HIGH);
  
}
  else {
    digitalWrite(lever,LOW);
  }
     Serial.print(distance);
    Serial.println(" cm");
     //Serial.print(11); //need to write to that it shows the voltage going to pin11
  delay(500);
}
