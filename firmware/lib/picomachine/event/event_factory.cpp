// event_factory.cpp

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 15/04/2023
 */

#include "event_factory.h"

template<typename T>
PicoMachine_Event<T>* EventFactory::create_event(uint32_t buffer_size) {
    return new PicoMachine_Event<T>(buffer_size);
}
