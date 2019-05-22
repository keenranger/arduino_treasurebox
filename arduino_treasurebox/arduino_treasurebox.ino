#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//5v -> button -> pin
const int button1_pin = 9;
const int button2_pin = 10;
const int button3_pin = 11;
const int button4_pin = 12;
const int button5_pin = 13;

const int real_ans = 1984;
int ans = 0;

const int lcd_i2c_addr = 0x27;
LiquidCrystal_I2C lcd(lcd_i2c_addr, 16, 2);//uno A4 SDA A5 SCL

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);
  pinMode(button3_pin, INPUT_PULLUP);
  pinMode(button4_pin, INPUT_PULLUP);
  pinMode(button5_pin, INPUT_PULLUP);
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
  int button1_state = digitalRead(button1_pin);
  int button2_state = digitalRead(button2_pin);
  int button3_state = digitalRead(button3_pin);
  int button4_state = digitalRead(button4_pin);
  int button5_state = digitalRead(button5_pin);

  if (button1_state == 0)
    ans += 1000;
  if (button2_state == 0)
    ans += 100;
  if (button3_state == 0)
    ans += 10;
  if (button4_state == 0)
    ans++;
  if (ans >= 10000) {
    lcd.clear();
    ans -= 10000;
  }

  lcd.setCursor(0, 0);          // 0번째 줄 0번째 셀부터 입력하게 합니다.
  lcd.print("Guess the Number!");
  lcd.setCursor(0, 1);
  lcd.print(ans);
    
  delay(100);
  /*
    // random 함수를 사용하여 0부터 2까지의 숫자중 랜덤하게 값을 받습니다.
    int value = random(0, 3);
    // 랜덤 값이 0이라면 아래의 조건을 실행합니다.
    if (value == 0) {
    // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0, 0);          // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("  KocoaFab.cc  ");       // 문구를 출력합니다.
    }
    // 랜덤 값이 1이라면 아래의 조건을 실행합니다.
    else if (value == 1) {
    lcd.setCursor(0, 1);          // 1번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.print("  Hello World!!  ");     // 문구를 출력합니다.
    }
    // 랜덤 값이 2이라면 아래의 조건을 실행합니다.
    else if (value == 2) {
    // 0번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0, 0);
    // 아래의 문장을 출력합니다.
    lcd.print("  KocoaFab.cc  ");
    // 1번째 줄 0번째 셀부터 입력하게 합니다.
    lcd.setCursor(0, 1);
    // 아래의 문장을 출력합니다.
    lcd.print("  Hello World!!  ");
    }
    // 1초간 대기합니다.
    delay(1000);
    // LCD의 모든 내용을 삭제합니다.
    lcd.clear();
  */
}
