#include <LiquidCrystal_I2C.h>
#include <Wire.h>
void right_answer();
void wrong_answer(int correct_nums);

//5v -> button -> pin(input pullup)
const int button_pin[5] = {9, 10, 11, 12, 13};
const int real_ans[4] = {1, 9, 8, 4};
int ans[4] = {0, 0, 0, 0};
int i;


const int lcd_i2c_addr = 0x27;
LiquidCrystal_I2C lcd(lcd_i2c_addr, 16, 2);//uno A4 SDA A5 SCL

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button_pin[0], INPUT_PULLUP);
  pinMode(button_pin[1], INPUT_PULLUP);
  pinMode(button_pin[2], INPUT_PULLUP);
  pinMode(button_pin[3], INPUT_PULLUP);
  pinMode(button_pin[4], INPUT_PULLUP);
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
  if (button_state[4] == 0) { //when button 5 pressed
    int correct_nums = 0;
    for (i = 0; i < 4; i++) { //4개 배열 맞나 검사
      if (ans[i] == real_ans[i])
        correct_nums++;
    }
    if (correct_nums == 4)
      right_answer();
    else
      wrong_answer(correct_nums);
  }

  delay(100);
}
////////////////
//정답 맞췄을 때//
////////////////
void right_answer() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("!Congraturation!");
  delay(5000);
  lcd.clear();
}
////////////
//틀렸을 때//
////////////
void wrong_answer(int correct_nums) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wrong Answer! :(");
  lcd.setCursor(0, 1);
  lcd.print("Correct number:");
  lcd.setCursor(15, 1);
  lcd.print(correct_nums);
  delay(5000);
  lcd.clear();
}
