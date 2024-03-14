#include <common.hpp>
#include <hardware_abstraction_layer.hpp>
#include <application.hpp>

static void do_action(action_t action)
{
    static action_t old_action = action_t::INIT;
    static long int time = 0;

    if (action == action_t::SEARCH)
    {
        if (time == 0)
        {
            time = millis();
        }
        // every 1s change strategy
        else if ((millis() - time) >= 1000)
        {
            time = 0;
            if (old_action == action_t::SEARCH)
                action = action_t::SEARCH_FORWARD;
            else
                action = action_t::SEARCH;
        }
        else
        {
            return;
        }
    }
    else if (old_action == action)
    {
        return;
    }
    else
    {
        time = 0;
    }

    switch (action)
    {
    case action_t::EDGE_FORWARD:
        HW_HAL::forward(70);
        break;
    case action_t::EDGE_TURN_LEFT:
        HW_HAL::backward(100);
        delay(100);
        HW_HAL::turn_left(70, 70);
        delay(100);
        break;
    case action_t::EDGE_TURN_RIGHT:
        HW_HAL::backward(100);
        delay(100);
        HW_HAL::turn_right(70, 70);
        delay(100);
        break;
    case action_t::ATTACK_FORWARD_TOO_CLOSE:
        HW_HAL::forward(200);
        break;
    case action_t::ATTACK_FORWARD_CLOSE:
        HW_HAL::forward(100);
        break;
    case action_t::ATTACK_FORWARD:
        if (old_action == action_t::ATTACK_FORWARD_TOO_CLOSE ||
            old_action == action_t::ATTACK_FORWARD_CLOSE)
        {
            HW_HAL::emerg_stop();
            delay(100);
        }
        HW_HAL::forward(70);
        break;
    case action_t::SEARCH:
        if (old_action == action_t::ATTACK_FORWARD_TOO_CLOSE ||
            old_action == action_t::ATTACK_FORWARD_CLOSE)
        {
            HW_HAL::emerg_stop();
            delay(100);
        }
        HW_HAL::turn_right(70, 70);
        break;
    case action_t::SEARCH_FORWARD:
        HW_HAL::forward(70);
        break;
    default:
        break;
    }

    old_action = action;
}

static bool on_edge(int val, int delta = 0)
{
    return val > G::QTR_THRESHOLD + delta;
}

static action_t evaluation(tri_qtr_t tri_qtr, double ultra_dist)
{
    action_t action = action_t::INIT;

    if (on_edge(tri_qtr.front_left) && on_edge(tri_qtr.front_right))
    {
        action = action_t::EDGE_TURN_RIGHT;
    }
    else if (on_edge(tri_qtr.front_left))
    {
        action = action_t::EDGE_TURN_RIGHT;
    }
    else if (on_edge(tri_qtr.front_right))
    {
        action = action_t::EDGE_TURN_LEFT;
    }
    else if (on_edge(tri_qtr.back))
    {
        action = action_t::EDGE_FORWARD;
    }
    else
    {
        if (ultra_dist < 5.0 && ultra_dist > 0)
        {
            action = action_t::ATTACK_FORWARD_TOO_CLOSE;
        }
        else if (ultra_dist < 10.0)
        {
            action = action_t::ATTACK_FORWARD_CLOSE;
        }
        else if (ultra_dist < 40.0)
        {
            action = action_t::ATTACK_FORWARD;
        }
        else
        {
            action = action_t::SEARCH;
        }
    }

    return action;
}

void run()
{
    do_action(
        evaluation(HW_HAL::qtr_read(),
                   HW_HAL::ultra_read(
                       G::ULTRA_MAX_DISTANCE)));
}