#include <common.hpp>
#include <hardware_driver.hpp>

void HW_Driver::wheel_forward(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, HIGH);
    digitalWrite(backward_pin, LOW);
}

void HW_Driver::wheel_backward(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, LOW);
    digitalWrite(backward_pin, HIGH);
}

void HW_Driver::wheel_stop(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, HIGH);
    digitalWrite(backward_pin, HIGH);
}

void HW_Driver::wheel_move_speed(uint8_t pin, int speed)
{
    analogWrite(pin, speed);
}

int HW_Driver::qtr_read(uint8_t pin)
{
    return digitalRead(pin);
}

double HW_Driver::ultra_read(uint8_t trigger_pin, uint8_t echo_pin, uint32_t max_distance)
{
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    auto val = pulseIn(echo_pin, HIGH, max_distance * 58) / 58.0;
    return val;
}