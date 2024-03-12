#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_

class debug
{
public:
    static void motor_test();
    static void sensor_test();

    static void correct_direction_test();

    static void serial_send_delay_test();
    static void serial_recv_delay_test();
};



#endif // !_DEBUG_HPP_