#include "lights_pedestrian.h"

Lights_pedestrian::Lights_pedestrian(Led green_led, Led red_led)
{
    
    green = green_led;
    red = red_led;
};

void Lights_pedestrian::setGreen()
{
    red.off();
    green.on();
}

void Lights_pedestrian::setRed()
{
    green.off();
    red.on();
}