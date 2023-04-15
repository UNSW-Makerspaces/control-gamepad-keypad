// event.h

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 15/04/2023
 */

#ifndef PICOMACHINE_EVENT_H
#define PICOMACHINE_EVENT_H

#include <cstdint>
#include "pico/stdlib.h"
#include "pico/util/queue.h"

#ifndef PICOMACHINE_MONITOR_H
#include "monitor.h"
#endif // PICOMACHINE_MONITOR_H

template<typename T>
class PicoMachine_Event {
public:
    // Constructor
    PicoMachine_Event(uint32_t buffer_size);

    // Destructor
    ~PicoMachine_Event();

    // Add data to the feedback buffer
    bool enqueue(const T& data);

    // Get data from the feedback buffer
    bool dequeue(T& data);

    // Check if the buffer is empty
    // NOTE: If you want to improve something, check how many events have empty buffers
    //       almost always, and refactor them.
    bool is_empty() const;

    // Check if the buffer is full
    // NOTE: If this happens, something is very wrong.
    bool is_full() const;

    // Handle the event, to be implemented by subclasses
    virtual void handle_event() = 0;

    // Update the event state and possibly call handle_event()
    // Implemented by subclasses 
    virtual void update() = 0;
    // NOTE: Implementations should go something along the lines of: 
    /**     
     *      T data;
     *      while (dequeue(data)) {
     *          Perform any preprocessing or filtering here, if needed
     *          handle_event();
     *      }
     */

    // Subscribe a callback function to be called when the event occurs
    void subscribe(void (*callback)(T));

    // Determine if this event is interested in the given data
    virtual bool is_interested(const T& data) = 0;

    // Determine if the event has completed its lifecycle
    virtual bool is_completed() = 0;

    // Dispose of the event and perform any necessary cleanup
    virtual void dispose() = 0;

protected:
    // FIXME: Comment
    queue_t fbBuf;

    // List of subscribed callback functions
    std::vector<void (*)(T)> subscribers;

private:
    uint32_t buffer_size;
};

#ifndef PICOMACHINE_EVENT_TEMPLATE
#include "event.tpp"
#endif // PICOMACHINE_EVENT_TEMPLATE 

#endif // PICOMACHINE_EVENT_H
