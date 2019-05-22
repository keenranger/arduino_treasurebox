void led_normal() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  }
  strip.show();
  //  colorWipe(strip.Color(255,   0,   0)     , 50); // Red
  //  colorWipe(strip.Color(  0, 255,   0)     , 50); // Green
  //  colorWipe(strip.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
  //
  //  whiteOverRainbow(75, 5);
  //
  //  pulseWhite(5);
  //
}
void led_congraturation() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
  }
  strip.show();
}

void led_wrong() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show();
}
