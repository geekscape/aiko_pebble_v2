/* light.ino
 * ~~~~~~~~~
 * Please do not remove the following notices.
 * License: GPLv3. http://geekscape.org/static/arduino_license.html
 * ----------------------------------------------------------------------------
 *
 * To Do
 * ~~~~~
 * - Use run-time average.
 */

byte lightValue = 0;

void lightHandler(void) {
  lightValue = analogRead(PIN_ANALOG_LIGHT);

//Serial.print("Light: ");
//Serial.println(lightValue);
}

/* ------------------------------------------------------------------------- */
