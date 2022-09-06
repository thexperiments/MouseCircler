#include "Mouse.h"
#include <math.h>
int responseDelay = 20;     // response delay of the mouse, in ms

void setup() {
  // initialize mouse control:
  Mouse.begin();
}

double radius = 100;
double xpos_old, xpos, ypos_old, ypos= 0;

void loop() { 
  double minAngle = acos(1 - 1/radius);

  for(double angle = 0; angle <= 360; angle += minAngle*0.9)
  {
        xpos = radius * cos(angle);
        ypos = radius * sin(angle);
        Mouse.move(xpos - xpos_old, ypos - ypos_old);
        ypos_old = ypos;
        xpos_old = xpos;
        delay(responseDelay);
  }
  xpos_old, xpos, ypos_old, ypos = 0;
}
