long distance, old_distance, velocity, acceleration, old_velocity, old_duration;
const int pingPin = 5;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
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

  old_distance = distance;
  distance = cm;                            // distance in meters (m)
  //delta_t = (duration - old_duration) * 1000;    // turn duration to seconds (s)
  old_velocity = velocity;
  velocity = (distance - old_distance); /// delta_t) * 1000000;   // velocity in meter/seconds (m/s)

  Serial.print("Velocity: ");
  Serial.println(velocity);


  acceleration = (velocity - old_velocity);  // acceleration in (m^2/s)
  Serial.print("Acceleration: ");
  Serial.println(acceleration);

  Serial.println();
  
  delay(1000);
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
