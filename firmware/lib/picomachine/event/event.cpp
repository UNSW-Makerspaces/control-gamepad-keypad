/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 */

#ifndef PICOMACHINE_EVENT_H
#include "monitor.h"
#endif // PICOMACHINE_EVENT_H
       //
#ifndef PICOMACHINE_EVENT_TEMPLATE
#include "event.tpp"
#endif // PICOMACHINE_EVENT_TEMPLATE
       //
template <typename T>
class Event {
public:
    static void start(T &mach);
    static void stop(T &mach);
    static void pause(T &mach);
    static void restart(T &mach);
};


