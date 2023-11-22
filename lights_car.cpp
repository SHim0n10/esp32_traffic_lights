#include "lights_car.h"

#include "led.h"

Lights_car::Lights_car(Led green_led, Led yellow_led, Led red_led)
{
    green = green_led;
    yellow = yellow_led;
    red = red_led;
};

void Lights_car::setGreen()
{
    yellow.off();
    red.off();
    green.on();
}

void Lights_car::setYellow()
{
    if (red.getState()){
        green.off();
        yellow.on();
        red.on();
    }
    else {
        green.off();
        yellow.on();
        red.off();
    }
}

void Lights_car::setRed()
{
    green.off();
    yellow.off();
    red.on();
}
