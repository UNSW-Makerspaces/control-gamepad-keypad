// event_dispatcher.cpp

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 15/04/2023
 */

#include "event_dispatcher.h"

void EventDispatcher::add_event(PicoMachine_Event* event) {
    active_events.push_back(event);
}

template<typename T>
void EventDispatcher::dispatch(const T& data) {
    for (auto& event : active_events) {
        if (event->is_interested(data)) {
            event->enqueue(data);
        }
    }
}

void EventDispatcher::update_events() {
    for (auto it = active_events.begin(); it != active_events.end();) {
        PicoMachine_Event* event = *it;
        event->update();
        if (event->is_completed()) {
            event->dispose();
            it = active_events.erase(it);
        } else {
            ++it;
        }
    }
}
