/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 */

#ifndef PICOMACHINE_EVENT_H
#define PICOMACHINE_EVENT_H

#include "monitor.h"

template <typename T>
class PicoMachine_Event {
public:
    explicit PicoMachine_Event(Machine &machine);
    
    void update();
    void handle_event(T event);

private:
    Machine &machine;
};

#include "event.tpp"

#endif // PICOMACHINE_EVENT_H
