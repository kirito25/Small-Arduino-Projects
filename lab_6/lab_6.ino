int psr_pin = 0;
int pir_pin = 2;
int led_pin = 13;
int psr_read = 0;
int pir_read = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(pir_pin, INPUT);
  pinMode(psr_pin, INPUT);
}

void loop() {
  psr_read = analogRead(psr_pin);
  Serial.println(psr_read);
  pir_read = digitalRead(pir_pin);
  digitalWrite(led_pin, pir_read);
}
