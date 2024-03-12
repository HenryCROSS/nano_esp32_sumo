#ifndef _CONFIGS_HPP_
#define _CONFIGS_HPP_

#include <Arduino.h>

#include <types.hpp>

class G
{
#define CS const static

public:
    CS int LEFT_MOTOR_PIN = 6;           // Motor A enable pin
    CS int RIGHT_MOTOR_PIN = 11;          // Motor B enable pin
    CS int RIGHT_WHEEL_FORWARD_PIN = 10;   // Motor B In1 pin
    CS int RIGHT_WHEEL_BACKWARD_PIN = 9; // Motor B In2 pin
    CS int LEFT_WHEEL_FORWARD_PIN = 7;    // Motor A In1 pin
    CS int LEFT_WHEEL_BACKWARD_PIN = 8;   // Motor A In2 pin
    CS int SENSOR_L_PIN = 4;        // qtr sensor
    CS int SENSOR_R_PIN = 5;        // qtr sensor

    CS int ULTRA_MAX_DISTANCE = 100;
    CS int DELTA = 0; // left speed will minus this value

    static void init()
    {
        pinMode(LEFT_MOTOR_PIN,OUTPUT);
        pinMode(RIGHT_MOTOR_PIN,OUTPUT);
        pinMode(RIGHT_WHEEL_FORWARD_PIN,OUTPUT);
        pinMode(RIGHT_WHEEL_BACKWARD_PIN,OUTPUT);
        pinMode(LEFT_WHEEL_FORWARD_PIN,OUTPUT);
        pinMode(RIGHT_WHEEL_BACKWARD_PIN,OUTPUT);
        pinMode(SENSOR_L_PIN,INPUT);
        pinMode(SENSOR_R_PIN,INPUT);
        Serial.begin(9600);
        delay(2000);
    }

#undef CS
};


#endif // !_CONFIGS_HPP_