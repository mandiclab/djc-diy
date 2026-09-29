#include <MIDIUSB.h>

// ---------- PUSH BUTTONS ----------
const int buttonPins[] = {5, 7, 10, 14, 15, 16};
const byte buttonNotes[] = {60, 61, 62, 63, 64, 65};
bool buttonStates[6] = {0};

// ---------- PUSH BUTTONS ON ANALOG PIN (resistor ladder 10k/10k/20k) ----------
const byte NOTE_1 = 66;
const byte NOTE_2 = 67;

bool note1On = false;
bool note2On = false;

// ADC reference zones
const int BTN1_MIN = 20;  // ~30
const int BTN1_MAX = 40;

const int BTN2_MIN = 41;  // ~90
const int BTN2_MAX = 160;


// ---------- POTENTIOMETERS ----------
const int potPins[] = {A0, A1, A2, A3, A7, A8, A9};
const byte potCCs[] = {10, 11, 12, 13, 14, 15, 16};
int potValues[7] = {0};
const int potThreshold = 2;

// ---------- POT CALIBRATION (centered span) ----------
const int ADC_MID = 512;     // middle of 10-bit ADC
const int SPAN_A7_A9 = 900;  // measured travel
const int SPAN_A8    = 600;  // measured travel

const int A7_MIN = ADC_MID - (SPAN_A7_A9 / 2);
const int A7_MAX = ADC_MID + (SPAN_A7_A9 / 2);
const int A8_MIN = ADC_MID - (SPAN_A8    / 2);
const int A8_MAX = ADC_MID + (SPAN_A8    / 2);
const int A9_MIN = ADC_MID - (SPAN_A7_A9 / 2);
const int A9_MAX = ADC_MID + (SPAN_A7_A9 / 2);

// ---------- ROTARY ENCODERS ----------
const int encoderAPins[] = {0, 3};
const int encoderBPins[] = {1, 2};
const byte encoderCCs[] = {20, 21};

int encoderLastStates[] = {0, 0};

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 2; i++) {
    pinMode(encoderAPins[i], INPUT_PULLUP);
    pinMode(encoderBPins[i], INPUT_PULLUP);
    encoderLastStates[i] = digitalRead(encoderAPins[i]);
  }
}

void loop() {
  // ------------------ PUSH BUTTONS ------------------
  for (int i = 0; i < 6; i++) {
    bool pressed = !digitalRead(buttonPins[i]);

    if (pressed && !buttonStates[i]) {
      noteOn(buttonNotes[i]);
      buttonStates[i] = true;
    } else if (!pressed && buttonStates[i]) {
      noteOff(buttonNotes[i]);
      buttonStates[i] = false;
    }
  }

// ------------------ PUSH BUTTONS ON ANALOG PIN ------------------
int val = analogRead(A6);

// Button 1 (10k to GND)
if (val > BTN1_MIN && val < BTN1_MAX) {
  if (!note1On) {
    noteOn(NOTE_1);
    note1On = true;
  }
} else {
  if (note1On) {
    noteOff(NOTE_1);
    note1On = false;
  }
}

// Button 2 (10k + 10k to GND)
if (val > BTN2_MIN && val < BTN2_MAX) {
  if (!note2On) {
    noteOn(NOTE_2);
    note2On = true;
  }
} else {
  if (note2On) {
    noteOff(NOTE_2);
    note2On = false;
  }
}

  handlePots();
  handleEncoders();

  delay(5); // debounce
}

// ------------------ MIDI FUNCTIONS ------------------

void noteOn(byte pitch) {
  midiEventPacket_t noteOnMsg = {0x09, 0x90, pitch, 127};
  MidiUSB.sendMIDI(noteOnMsg);
  MidiUSB.flush();
}

void noteOff(byte pitch) {
  midiEventPacket_t noteOffMsg = {0x08, 0x80, pitch, 0};
  MidiUSB.sendMIDI(noteOffMsg);
  MidiUSB.flush();
}

void handlePots() {
  static unsigned long lastReadTime = 0;
  const unsigned long readInterval = 10;

  if (millis() - lastReadTime < readInterval) return;
  lastReadTime = millis();

  for (int i = 0; i < 7; i++) {
    int raw = analogRead(potPins[i]);

    // ------------------ POT CALIBRATION (A7/A8/A9) ------------------
    if (i == 4) raw = constrain(raw, A7_MIN, A7_MAX); // A7 centered span
    if (i == 5) raw = constrain(raw, A8_MIN, A8_MAX); // A8 centered span
    if (i == 6) raw = constrain(raw, A9_MIN, A9_MAX); // A9 centered span

    int mapped;
    if (i == 4) mapped = map(raw, A7_MIN, A7_MAX, 0, 127);
    else if (i == 5) mapped = map(raw, A8_MIN, A8_MAX, 0, 127);
    else if (i == 6) mapped = map(raw, A9_MIN, A9_MAX, 0, 127);
    else mapped = raw / 8; // default: 0-1023 -> 0-127

    if (abs(mapped - potValues[i]) >= potThreshold) {
      potValues[i] = mapped;
      sendCC(potCCs[i], mapped);
    }
  }
}

void sendCC(byte cc, byte val) {
  midiEventPacket_t ccMsg = {0x0B, 0xB0, cc, val};
  MidiUSB.sendMIDI(ccMsg);
  MidiUSB.flush();
}

void handleEncoders() {
  for (int i = 0; i < 2; i++) {
    int currentState = digitalRead(encoderAPins[i]);

    if (currentState != encoderLastStates[i]) {
      int bState = digitalRead(encoderBPins[i]);
      byte directionValue;

      if (currentState == bState) {
        directionValue = 0x41;
      } else {
        directionValue = 0x3F;
      }

      midiEventPacket_t cc = {0x0B, 0xB0, encoderCCs[i], directionValue};
      MidiUSB.sendMIDI(cc);
      MidiUSB.flush();

      encoderLastStates[i] = currentState;
    }
  }
}
