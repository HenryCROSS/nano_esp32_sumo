#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <microTuple.h>
#include <ArxContainer.h>

struct tri_qtr_t {
    int front_left, front_right, back;
};

enum class action_t { 
    INIT,
    EDGE_FORWARD,
    EDGE_TURN_LEFT,
    EDGE_TURN_RIGHT,
    ATTACK_FORWARD_TOO_CLOSE,
    ATTACK_FORWARD_CLOSE,
    ATTACK_FORWARD,
    SEARCH,
    SEARCH_FORWARD,
};

#endif // !_TYPES_HPP_