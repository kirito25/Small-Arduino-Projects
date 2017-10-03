int motor = 3;
long distance, old_distance, velocity, acceleration, old_velocity, old_duration;
const int pingPin = 5;
bool motor_status = false;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm, delta_t;
  old_duration = duration;
  duration = ping(pingPin);           //duration in microseconds
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print("Distiance: ");
  Serial.print(inches);
  Serial.print("in = ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm < 15) { 
    vibe();
    motor = true;
  }
  else if (cm > 15 && motor_status) { 
    stop_vibe();
    motor_status = false; 
  }
  delay(1000);
}

void vibe() {
  digitalWrite(motor, HIGH);
  //delay(1000);
  //digitalWrite(motor, LOW);
  //delay(5000);
}
void stop_vibe() {
  digitalWrite(motor, LOW);
}
/* Returns duration of a ping */
int ping(int pingPin) {
  int duration; /* duration of round trip pulse in microseconds */
  pinMode(pingPin, OUTPUT); /* set pingPin for output first */
  digitalWrite(pingPin, LOW); /* write a LOW value for a short time */
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH); /* send a pulse at least 5 microseconds in length */
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW); /* end the pulse */
  pinMode(pingPin, INPUT); /* set the pingPin for input */
  duration = pulseIn(pingPin, HIGH); /* and get round trip duration in microseconds */
  return duration;
}



long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
