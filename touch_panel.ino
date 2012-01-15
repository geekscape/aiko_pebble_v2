/* touchPanel.ino
 * ~~~~~~~~~~~~~~
 * Please do not remove the following notices.
 * License: GPLv3. http://geekscape.org/static/arduino_license.html
 * ----------------------------------------------------------------------------
 *
 * To Do
 * ~~~~~
 * - None, yet.
 */

// Taken from http://kousaku-kousaku.blogspot.com/2008/08/arduino_24.html
#ifdef MEGA
#define ANALOG_OFFSET 54
#else
#define ANALOG_OFFSET 14
#endif

#define xLowAnalog  5
#define xLow       (xLowAnalog + ANALOG_OFFSET)
#define xHigh      (3 + ANALOG_OFFSET)
#define yLowAnalog  2
#define yLow       (yLowAnalog + ANALOG_OFFSET)
#define yHigh      (4 + ANALOG_OFFSET)

void touchPanelHandler(void) {
  pinMode(xLow,OUTPUT);
  pinMode(xHigh,OUTPUT);
  digitalWrite(xLow,LOW);
  digitalWrite(xHigh,HIGH);

  digitalWrite(yLow,LOW);
  digitalWrite(yHigh,LOW);

  pinMode(yLow,INPUT);
  pinMode(yHigh,INPUT);

  // xLow has analog port -14 !!
  int x = analogRead(yLowAnalog);

  pinMode(yLow,OUTPUT);
  pinMode(yHigh,OUTPUT);
  digitalWrite(yLow,LOW);
  digitalWrite(yHigh,HIGH);

  digitalWrite(xLow,LOW);
  digitalWrite(xHigh,LOW);

  pinMode(xLow,INPUT);
  pinMode(xHigh,INPUT);

  // yLow has analog port -14 !!
  int y = analogRead(xLowAnalog);

  lcdPosition(2, 13);

  if  (x > 99  &&  y > 99) {
    lcdWriteNumber(x);
    lcdWriteString(",");
    lcdWriteNumber(y);
  }
  else {
    lcdWriteString("       ");
  }
}

int touch(
  int x, int y, int xMin, int xMax, int yMin, int yMax) {

  return(x >= xMin  &&  x <= xMax  &&  y >= yMin  &&  y <= yMax);
}

/* ------------------------------------------------------------------------- */
