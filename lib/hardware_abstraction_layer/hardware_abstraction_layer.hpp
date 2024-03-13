#ifndef _HW_DRIVER_HPP_

#include <common.hpp>

// Hardware abstraction layer
class HW_HAL
{
public:
    static void turn_left(int left_speed, int right_speed);  //
    static void turn_right(int left_speed, int right_speed); //
    static void forward(int speed);    //
    static void backward(int speed);   //
    static void emerg_stop();
    static tri_qtr_t qtr_read();
    static double ultra_read(uint32_t max_distance);
};


#endif // !_HW_DRIVER_HPP_