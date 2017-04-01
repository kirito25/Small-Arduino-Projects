int pin = 13;
unsigned int pinAddress = 0x2f;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  show();
  pinMode(pin, OUTPUT);

  Serial.println("when high");
  digitalWrite(pin, HIGH);
  show();
  Serial.println("when low");
  digitalWrite(pin, LOW);
  show();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int address = 0x25;
  * (int *) address ^= 0x20;
  delay(1000);
}

void show() {
  unsigned int i = 0x20;
  unsigned int j = 0x2f;
  for (; i <= j; i++) {
    Serial.print("Address: ");
    Serial.println(i, HEX);
    Serial.print("Value: ");
    Serial.println(*(int *) i, HEX);
  }
  Serial.println();
}

