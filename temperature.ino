/* temperature.ino
 * ~~~~~~~~~~~~~~~
 * Please do not remove the following notices.
 * License: GPLv3. http://geekscape.org/static/arduino_license.html
 * ----------------------------------------------------------------------------
 *
 * To Do
 * ~~~~~
 * - Floating point is expensive, improve performance.
 * - Use run-time average.
 */

float temperatureValue    = 0.0f;
byte  temperatureWhole    = 0;
byte  temperatureFraction = 0;

void temperatureHandler(void) {
// Conversion based on MCP9701 with 5V ARef and 10-bit ADC

  temperatureValue = ((float) analogRead(PIN_ANALOG_TEMPERATURE) / 4) - 20.5;

//Serial.print("Temperature: ");
  Serial.println(temperatureValue);

  temperatureWhole = temperatureValue;
  temperatureFraction = (temperatureValue - temperatureWhole) * 100;
}

/* ------------------------------------------------------------------------- */
