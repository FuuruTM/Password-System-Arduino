#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int white = SSD1306_WHITE;
int button[] = {11, 7, 1};
int led[] = {13, 8, 5};
int code[] = {13, 5, 8};
int correct = 0;
int counter = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  welcome();
}

void loop() {
  playerturn();
}

int waitbutton() {
  while (true) {
    for(int i = 0; i < 3; i++) {
      if(digitalRead(button[i]) == LOW) {
        delay(50);
        return i;
      }
    }
  }
}

void playerturn() {
  for(int i = 0; i < 3; i++) {
    int pressed = waitbutton();
    int check = code[i];
    digitalWrite(led[pressed], HIGH);
    delay(250);
    digitalWrite(led[pressed], LOW);
    delay(250);
    counter++;
    if(check == led[pressed]) {
      correct++;
    }
  if(correct == 3) {
    for(int i = 0; i < 3; i++) {
      masuk();
      digitalWrite(3, HIGH);
      tone(9, 250);
      delay(250);
      digitalWrite(3, LOW);
      noTone(9);
      delay(250);

      counter = 0;
     } 
    }
    if(counter == 3) {
      passinc();
      tone(9, 250);
      delay(360);
      noTone(9);
      tone(9, 300);
      delay(360);
      noTone(9);

      counter = 0;
      delay(50);
    }
  }
  correct = 0;
}

void welcome() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 25);
  display.setTextColor(white);
  display.print("Silahkan Masukkan");
  display.setCursor(33, 37);
  display.println("Password!!");

  display.display();
}

void passinc() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 25);
  display.setTextColor(white);
  display.print("PASSWORD SALAH!!!");
  display.setCursor(21, 37);
  display.println("Masukkan Ulang!");

  display.display();
}

void masuk() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 25);
  display.setTextColor(white);
  display.print("PASSWORD BENAR!!!");
  display.setCursor(6, 37);
  display.println("Anda Berhasil Masuk!");

  display.display();
}