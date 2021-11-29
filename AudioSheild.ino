#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=200,69
AudioOutputI2S           i2s2;           //xy=365,94
AudioConnection          patchCord1(i2s1, 0, i2s2, 0);
AudioConnection          patchCord2(i2s1, 1, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=302,184
// GUItool: end automatically generated code

const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;

int serialVal = 0;

void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.5);
  
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {

  if (Serial2.available() >= 8) {
    int val = Serial2.read();

    if (val == 255) {
      //collecting all (0-100) numbers from the 3.5
      int val1 = Serial1.read();
      int val2 = Serial1.read();
      int val3 = Serial1.read();
      int val4 = Serial1.read();
      int val5 = Serial1.read();
      int val6 = Serial1.read();
      int val7 = Serial1.read();
      //Defining and renaming pot information
      //Verb
      float verbSize = val1 / 100.0;
      float verbDamping = val2 / 100.0;
      float verbMix = val3 / 100.0;
      //Chorus
      float chorusDelay = val4 / 100.0;
      float chorusLength = val5 / 100.0;
      float chorusVoices = val6 / 100.0;
      float chorusMix = val7 / 100.0;

      //Test Display
      //Verb
      Serial.print("VERB:    ");
      Serial.print(verbSize);
      Serial.print(", ");
      Serial.print(verbDamping);
      Serial.print(", ");
      Serial.print(verbMix);
      Serial.print(",      ");
      //Chorus
      Serial.print("CHORUS:    ");
      Serial.print(chorusDelay);
      Serial.print(", ");
      Serial.print(chorusLength);
      Serial.print(", ");
      Serial.print(chorusVoices);
      Serial.print(", ");
      Serial.println(chorusMix);
    }




  }
}
