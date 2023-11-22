#include "button.h"

Button::Button(gpio_num_t pin)
{
    m_pin = pin;
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT);
    gpio_set_pull_mode(m_pin, GPIO_PULLUP_ONLY);
}

bool Button::getState()
{
    if (gpio_get_level(m_pin) == 1){
        return true;
    }
    else return false;
}