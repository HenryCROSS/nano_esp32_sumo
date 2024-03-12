#include <common.hpp>
#include <debug.hpp>
#include <hardware_interface.hpp>

const int TEST_SPEED = 100;

void debug::motor_test(){
    HW_API::forward(TEST_SPEED);
    delay(1000);
    HW_API::emerg_stop();
    delay(1000);
    HW_API::turn_left(TEST_SPEED, TEST_SPEED);
    delay(1000);
    HW_API::emerg_stop();
    delay(1000);
    HW_API::turn_right(TEST_SPEED, TEST_SPEED);
    delay(1000);
    HW_API::emerg_stop();
    delay(999999);
}

void debug::sensor_test(){
    // G::left_on_line = digitalRead(G::SENSOR_L_PIN);
    // G::right_on_line = digitalRead(G::SENSOR_R_PIN);
    // HW_API::qtr_read();
    // Serial.print("left_on_line: ");
    // Serial.print(G::left_on_line);
    // Serial.print("------");
    // Serial.print("right_on_line: ");
    // Serial.print(G::right_on_line);
    delay(500);
}

void debug::correct_direction_test(){
    delay(1000);
    HW_API::forward(TEST_SPEED);
    delay(2000);
    HW_API::emerg_stop();
    delay(9999999);
}

void debug::serial_send_delay_test(){
    auto msg = Serial.readString();
    if(msg == "Ready"){
        Serial.write("Start");
        Serial.write("Test");
    }
}

void debug::serial_recv_delay_test(){
    auto msg = Serial.readString();
    if(msg == "Ready"){
        msg = Serial.readString();
        if(msg == "Start"){
            auto start = micros();
            msg = Serial.readString();
            auto end = micros();
            Serial.print("delay ");
            Serial.print((end - start));
            Serial.println("micro sec");
        }
    }
}