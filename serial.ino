/* serial.ino
 * ~~~~~~~~~~
 * Please do not remove the following notices.
 * License: GPLv3. http://geekscape.org/static/arduino_license.html
 * ----------------------------------------------------------------------------
 *
 * Arduino serial buffer is 128 characters.
 * At 115,200 baud (11,520 cps) the buffer is filled 90 times per second.
 * Need to run this handler every 10 milliseconds.
 *
 * At 38,400 baud (3,840 cps) the buffer is filled 30 times per second.
 * Need to run this handler every 30 milliseconds.
 *
 * To Do
 * ~~~~~
 * - This module is just plain ugly ... fix it !
 */

byte output_1 = false;
byte output_2 = false;

byte serialInitialized = false;

void serialInitialize(void) {
  Serial.begin(DEFAULT_BAUD_RATE);

  pinMode(PIN_OUTPUT_1, OUTPUT);
  pinMode(PIN_OUTPUT_2, OUTPUT);

  serialInitialized = true;
}

void serialHandler(void) {
  if (! serialInitialized) serialInitialize();

  if (Serial.available()) {
    char ch = Serial.read();

    if (ch == '1') {
      output_1 = ! output_1;
      digitalWrite(PIN_OUTPUT_1, output_1);
    }

    if (ch == '2') {
      output_2 = ! output_2;
      digitalWrite(PIN_OUTPUT_2, output_2);
    }
  }
}
