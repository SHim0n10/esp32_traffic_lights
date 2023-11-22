#pragma once

#include "led.h"

class Lights_pedestrian
{
  private:
    Led green;
    Led red;

  public:
    Lights_pedestrian(Led green_led, Led red_led);
    void setGreen();
    void setRed();
};