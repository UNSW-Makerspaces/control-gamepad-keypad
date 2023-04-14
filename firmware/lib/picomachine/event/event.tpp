/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 *
 */

#ifndef PICOMACHINE_EVENT_TEMPLATE
#define PICOMACHINE_EVENT_TEMPLATE 

#include "monitor.h"

template <typename T>
void Event<T>::start(T &machine) {
    machine.start();
}

template <typename T>
void Event<T>::stop(T &machine) {
    machine.stop();
}

template <typename T>
void Event<T>::pause(T &machine) {
    machine.pause();
}

template <typename T>
void Event<T>::restart(T &machine) {
    machine.restart();
}

#endif // PICOMACHINE_EVENT_TEMPLATE
