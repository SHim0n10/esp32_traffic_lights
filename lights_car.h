#pragma once

#include "led.h"

class Lights_car
{
  private:
    Led green;
    Led yellow;
    Led red;

  public:
    Lights_car(Led green_led, Led yellow_led, Led red_led);
    void setGreen();
    void setYellow();
    void setRed();
};