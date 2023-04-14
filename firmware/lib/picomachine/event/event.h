/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 */

#ifndef EVENT_H
#define EVENT_H

#include "monitor.h"

class Event {
public:
    static void start(Machine &machine);
    static void stop(Machine &machine);
    static void pause(Machine &machine);
    static void
#endif // EVENT_H
    restart(Machine &machine);
};

#endif // EVENT_H
