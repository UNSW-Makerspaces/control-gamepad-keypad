// event_dispatcher.h

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 15/04/2023
 */

#ifndef PICOMACHINE_EVENT_DISPATCHER_H
#define PICOMACHINE_EVENT_DISPATCHER_H

#include "event.h"
#include <vector>

class EventDispatcher {
public:
    // Add a new event to the list of active events
    void add_event(PicoMachine_Event* event);

    // Dispatch the data to the events interested in it
    template<typename T>
    void dispatch(const T& data);

    // Update all active events and remove the completed ones
    void update_events();

private:
    // List of active events
    std::vector<PicoMachine_Event*> active_events;
};

#endif // PICOMACHINE_EVENT_DISPATCHER_H
