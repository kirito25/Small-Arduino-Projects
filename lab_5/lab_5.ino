#include <SoftwareSerial.h>
 // “Charge!” can be played using: 1/16th G, C, 1/8th E, 1/4 G, 1/8th E, 1/2 G

int music[] = {0xe6, 0xdf, 0xe3, 0xe6, 0xe3, 0xe6 };
int toneLength[] = {0xd2, 0xd6, 0xd3, 0xd4, 0xd3, 0xd5};
int musicLen = 6;
int tx = 3;
int speaker = 3;
int clearScreen = 12;
int BacklightON = 17;
int BacklightOFF = 18;
SoftwareSerial screen(2, tx); //2 doesnt matter

void setup() {
  // put your setup code here, to run once
  pinMode(tx, OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(57600);
  while (!Serial) { ; }
  Serial.println("Starting now");
  screen.begin(9600);
  delay(100);
  //screen.write(BacklightON);
  //delay(5);
  screen.write(clearScreen);
  screen.write("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  //screen.write(clearScreen);
  //delay(5000);
  //screen.write("Hello World ");
  //delay(500);

  /*
  //Play Music
  for(int i = 0; i < musicLen; i++) {
    screen.write(toneLength[i]);
    screen.write(music[i]);
  }
  */
  
}
