/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 */

#ifndef PICOMACHINE_EVENT_H
#define PICOMACHINE_EVENT_H

#include "monitor.h"

class Event {
public:
    static void start(Machine &machine);
    static void stop(Machine &machine);
    static void pause(Machine &machine);
    static void
    restart(Machine &machine);
};

#endif // PICOMACHINE_EVENT_H
