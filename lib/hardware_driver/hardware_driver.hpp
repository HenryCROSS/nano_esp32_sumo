#ifndef _HARDWARE_INTERFACE_HPP_
#define _HARDWARE_INTERFACE_HPP_

class HW_Driver
{
  public:
    static void wheel_forward(uint8_t forward_pin, uint8_t backward_pin);
    static void wheel_backward(uint8_t forward_pin, uint8_t backward_pin);
    static void wheel_stop(uint8_t forward_pin, uint8_t backward_pin);
    static void wheel_move_speed(uint8_t pin, int speed);
    static int qtr_read(uint8_t pin);
    static double ultra_read(uint8_t trigger_pin, uint8_t echo_pin, uint32_t max_distance);
};

#endif // !_HARDWARE_INTERFACE_