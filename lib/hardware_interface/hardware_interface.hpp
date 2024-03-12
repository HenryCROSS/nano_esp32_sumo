#ifndef _HARDWARE_INTERFACE_HPP_
#define _HARDWARE_INTERFACE_HPP_

class HW_API
{
  public:
    static void turn_left(int left_speed, int right_speed);  //
    static void turn_right(int left_speed, int right_speed); //
    static void forward(int speed);    //
    static void backward();   //
    static void emerg_stop();
    static int qtr_read(uint8_t pin);
    static double ultra_read(uint8_t trigger_pin, uint8_t echo_pin);
};

#endif // !_HARDWARE_INTERFACE_