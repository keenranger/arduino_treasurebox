////////////////
//정답 맞췄을 때//
////////////////
void right_answer() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("!Congraturation!");
  led_congraturation();
  opener.write(0);
  delay(650);
  opener.write(90);
  congraturation_music_part1();
  for (;;) {
    congraturation_music_part2();
  }
  delay(3000);
  lcd.clear();
}
////////////
//틀렸을 때//
////////////
void wrong_answer(int correct_nums, char ans[]) {
  for (i = 0; i < 4; i++) {
    ans[i] = 'A';
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wrong Answer! :(");
  lcd.setCursor(0, 1);
  lcd.print("Correct number:");
  lcd.setCursor(15, 1);
  lcd.print(correct_nums);
  led_wrong();
  wrong_music();
  delay(1000);
  lcd.clear();
  led_normal();
}
