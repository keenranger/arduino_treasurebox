#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//5v -> button -> pin
const int button_pin[5] = {9, 10, 11, 12, 13};

const int real_ans[4] = {1, 9, 8, 4};
int ans[4] = {0, 0, 0, 0};


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

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
  int i;
  int button_state[5] = {digitalRead(button_pin[0]), digitalRead(button_pin[1]),
                         digitalRead(button_pin[2]), digitalRead(button_pin[3]),
                         digitalRead(button_pin[4])
                        };
  for (i = 0; i < 4; i++) {//add one to the number of each position
    if (button_state[i] == 0) {
      ans[i] += 1;
      ans[i] %= 10;
    }
  }

  //  Serial.print(button_state[0]);
  //  Serial.print(button_state[1]);
  //  Serial.print(button_state[2]);
  //  Serial.print(button_state[3]);
  //  Serial.println(button_state[4]);


  lcd.setCursor(0, 0);          // 0번째 줄 0번째 셀부터 입력하게 합니다.
  lcd.print("Guess the Number!");

  for (i = 0; i < 4; i++) {
    lcd.setCursor(i, 1);
    lcd.print(ans[i]);
  }
  if (button_state[4] == 0) {
    int correct_nums=0;
    for (i = 0; i < 4; i++) {
      if (ans[i] == real_ans[i])
        correct_nums++;
    }
    if (correct_nums == 4) {
      lcd.clear();
      lcd.setCursor(0, 0);          
      lcd.print("!Congraturation!");
      delay(5000);
    }
  }

  delay(100);
}
