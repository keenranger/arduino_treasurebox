
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include "pitches.h"


void right_answer();
void wrong_answer(int correct_nums, int ans[]);
void wrong_music();
void congraturation_music_part1();
void congraturation_music_part2();
void led_normal();
void led_congraturation();
void led_wrong();

//5v -> button -> pin(input pullup)
const int button_pin[5] = {9, 10, 11, 12, 13};
const int real_ans[4] = {1, 9, 8, 4};
int ans[4] = {0, 0, 0, 0};
int i;


const int lcd_i2c_addr = 0x27;
LiquidCrystal_I2C lcd(lcd_i2c_addr, 16, 2);//uno A4 SDA A5 SCL
Adafruit_NeoPixel strip = Adafruit_NeoPixel(200, 5, NEO_GRB + NEO_KHZ800);
Servo opener;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button_pin[0], INPUT_PULLUP);
  pinMode(button_pin[1], INPUT_PULLUP);
  pinMode(button_pin[2], INPUT_PULLUP);
  pinMode(button_pin[3], INPUT_PULLUP);
  pinMode(button_pin[4], INPUT_PULLUP);
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  opener.attach(3);
}

void loop() {
  int button_state[5] = {digitalRead(button_pin[0]), digitalRead(button_pin[1]),
                         digitalRead(button_pin[2]), digitalRead(button_pin[3]),
                         digitalRead(button_pin[4])//check the status buttton normal -> 1 pressed -> 0
                        };
  for (i = 0; i < 4; i++) {//add one to the number of each position
    if (button_state[i] == 0) {
      ans[i] += 1;
      ans[i] %= 10;//make 0 when number become 10
    }
  }

  lcd.setCursor(0, 0);          //order : column,row
  lcd.print("Guess the Number!");

  for (i = 0; i < 4; i++) { //display 4 numbers
    lcd.setCursor(i, 1);
    lcd.print(ans[i]);
  }
  led_normal();
  if (button_state[4] == 0) { //when button 5 pressed
    int correct_nums = 0;
    for (i = 0; i < 4; i++) { //4개 배열 맞나 검사
      if (ans[i] == real_ans[i])
        correct_nums++;
    }
    if (correct_nums == 4)
      right_answer();
    else
      wrong_answer(correct_nums, ans);
  }

  delay(100);
}
