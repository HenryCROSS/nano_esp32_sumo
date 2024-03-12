#include <common.hpp>
#include <hardware_interface.hpp>

void wheel_forward(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, HIGH);
    digitalWrite(backward_pin, LOW);
}

void wheel_backward(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, LOW);
    digitalWrite(backward_pin, HIGH);
}

void wheel_stop(uint8_t forward_pin, uint8_t backward_pin)
{
    digitalWrite(forward_pin, HIGH);
    digitalWrite(backward_pin, HIGH);
}

void wheel_move_speed(uint8_t pin, int speed)
{
    analogWrite(pin, speed);
}

void car_go_forward(int speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, speed - G::DELTA);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, speed + G::DELTA);
    wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_forward_by_speed(int left_wheel_speed, int right_wheel_speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_speed - G::DELTA);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_speed);
    wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_backward(int speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, speed - G::DELTA);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, speed + G::DELTA);
    wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_go_backward_by_speed(int left_wheel_speed, int right_wheel_speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_speed);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_speed);
    wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_turn_right_by_speed(int left_wheel_forward_speed, int right_wheel_backward_speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_forward_speed);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_backward_speed);
    wheel_forward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
    wheel_backward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
}

void car_turn_left_by_speed(int left_wheel_backward_speed, int right_wheel_forward_speed)
{
    wheel_move_speed(G::LEFT_MOTOR_PIN, left_wheel_backward_speed);
    wheel_move_speed(G::RIGHT_MOTOR_PIN, right_wheel_forward_speed);
    wheel_forward(G::RIGHT_WHEEL_FORWARD_PIN, G::RIGHT_WHEEL_BACKWARD_PIN);
    wheel_backward(G::LEFT_WHEEL_FORWARD_PIN, G::LEFT_WHEEL_BACKWARD_PIN);
}

void HW_API::turn_left(int left_speed, int right_speed)
{
    car_turn_left_by_speed(left_speed, right_speed);
}

void HW_API::turn_right(int left_speed, int right_speed)
{
    car_turn_right_by_speed(left_speed, right_speed);
}

void HW_API::forward(int speed)
{
    car_go_forward(speed);
}

void HW_API::backward()
{
    car_go_backward(75);
}

void HW_API::emerg_stop()
{
    car_go_backward(0);
}

int HW_API::qtr_read(uint8_t pin)
{
    return digitalRead(pin);
}

double HW_API::ultra_read(uint8_t trigger_pin, uint8_t echo_pin)
{
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    auto val = pulseIn(echo_pin, HIGH, G::ULTRA_MAX_DISTANCE * 58) / 58.0;
    return val;
}