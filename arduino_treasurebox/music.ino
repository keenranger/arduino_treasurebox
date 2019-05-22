#define speakerpin 6
int congraturation_melody[] = {
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,//5
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,//5
  NOTE_D5, 0, 0,//3
  0, NOTE_D4, NOTE_E4, NOTE_FS4,//4
  NOTE_G4, NOTE_D4,//2
  0, NOTE_G4, NOTE_FS4, NOTE_G4,//4
  NOTE_A4, NOTE_E4,//2
  0, NOTE_D4, NOTE_E4, NOTE_FS4,//4
  NOTE_B4, NOTE_A4, NOTE_A4, NOTE_G4,//4
  NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_FS4,//4
  NOTE_D4//1
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int congraturation_duration[] = {
  4, 8, 4, 8, 4,
  4, 8, 4, 8, 4,
  4, 4, 2,
  4, 4, 4, 4,
  2, 2,
  4, 4, 4, 4,
  2, 2,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  1
};
void wrong_music() {
  int noteDuration = 800;
  tone(speakerpin, NOTE_A3, 1000);

  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);

  noTone(speakerpin);
}
void congraturation_music_part1() {
  for (int thisNote = 0; thisNote < 13; thisNote++) {

    int noteDuration = 1000 / congraturation_duration[thisNote];
    tone(speakerpin, congraturation_melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(speakerpin);
  }
}

void congraturation_music_part2() {
  for (int thisNote = 13; thisNote < 38; thisNote++) {

    int noteDuration = 800 / congraturation_duration[thisNote];
    tone(speakerpin, congraturation_melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(speakerpin);
  }
}
