const int buz = 10;
int S = 2;
void setup() {
  pinMode(buz, OUTPUT);
  pinMode(S, INPUT);

}

void loop() {
  int sv = digitalRead(S);

  if (sv == 0) {

    tone(buz, 4500);
    delay(2500);
    tone(buz, 2000);


  } else {
    noTone(buz);
  }

}
