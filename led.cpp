#include "led.h"

Led::Led(gpio_num_t pin) {
  m_pin = pin;
  
  gpio_reset_pin(m_pin);
  gpio_set_direction(m_pin, GPIO_MODE_INPUT_OUTPUT);
}
Led::Led(){
    
}

void Led::on()
{
    gpio_set_level(m_pin, 1);
}

void Led::off()
{
    gpio_set_level(m_pin, 0);
}

bool Led::getState()
{
    if(gpio_get_level(m_pin) == 1){
        return true;
    }
    else return false;
}