// event_factory.h

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 15/04/2023
 */

#ifndef PICOMACHINE_EVENT_FACTORY_H
#define PICOMACHINE_EVENT_FACTORY_H

#include "event.h"

class EventFactory {
public:
    // Create a new event with the given buffer size
    template<typename T>
    static PicoMachine_Event<T>* create_event(uint32_t buffer_size);
};

#endif // PICOMACHINE_EVENT_FACTORY_H
