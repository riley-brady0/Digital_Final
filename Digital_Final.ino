int ledPin = 16;
int LEDPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int LEDAmt = 8;

int verbPots[3] = {A14, A15, A16};
int chorusPots[4] = {A17, A18, A19, A20};
int chorAmt = 4;
int verbAmt = 3;
int PotAmt = 7;

void setup() {
  Serial2.begin(9600);

  //LEDs
  pinMode(ledPin, OUTPUT);
  for (int i = 0; i < LEDAmt; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }
}

void loop() {
  Serial2.write(255);

  //Reverb knobs
  int knob1 = map(analogRead(verbPots[0]), 0, 1023, 0, 100);  // Room size
  Serial2.write(knob1);
  int knob2 = map(analogRead(verbPots[1]), 0, 1023, 0, 100);  // Damping
  Serial2.write(knob2);
  int knob3 = map(analogRead(verbPots[2]), 0, 1023, 0, 100);  // Mix
  Serial2.write(knob3);

  //Chorus Knobs
  int knob4 = map(analogRead(chorusPots[0]), 0, 1023, 0, 100);  // Delay
  Serial2.write(knob4);
  int knob5 = map(analogRead(chorusPots[1]), 0, 1023, 0, 100);  // Length
  Serial2.write(knob5);
  int knob6 = map(analogRead(chorusPots[2]), 0, 1023, 0, 100);  // Voices
  Serial2.write(knob6);
  int knob7 = map(analogRead(chorusPots[3]), 0, 1023, 0, 100);  // Mix
  Serial2.write(knob7);
  delay(100);

}