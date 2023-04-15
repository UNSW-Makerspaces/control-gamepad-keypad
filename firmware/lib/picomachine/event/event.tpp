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
PicoMachine_Event<T>::PicoMachine_Event(Machine &machine) : machine(machine) {
    allocate_buffer();
}

template <typename T>
PicoMachine_Event<T>::~PicoMachine_Event() {
    deallocate_buffer();
}

template <typename T>
void PicoMachine_Event<T>::update() {
    // Check for new events and handle them accordingly
    // Example: handle_event(event_type);
}

template <typename T>
void PicoMachine_Event<T>::handle_event(T event) {
    // Handle the event and perform appropriate action on the Machine based on the event type
    // Example:
    // switch (event) {
    //     case EventType::START:
    //         machine.start();
    //         break;
    //     case EventType::STOP:
    //         machine.stop();
    //         break;
    //     // Other cases...
    // }
}

// Allocates memory for the buffer
template <typename T>
void PicoMachine_Event<T>::allocate_buffer() {
    // Example: fbBuf = new uint8_t[buffer_size];
}

// Deallocates memory for the buffer
template <typename T>
void PicoMachine_Event<T>::deallocate_buffer() {
    // Example: delete[] fbBuf;
}

// Inserts data into the buffer
template <typename T>
void PicoMachine_Event<T>::set_buffer_data(uint8_t data) {
    // Example: fbBuf[write_index] = data;
    //          write_index = (write_index + 1) % buffer_size;
}

// Retrieves data from the buffer
template <typename T>
uint8_t PicoMachine_Event<T>::get_buffer_data() {
    // Example: uint8_t data = fbBuf[read_index];
    //          read_index = (read_index + 1) % buffer_size;
    //          return data;
}

#endif // PICOMACHINE_EVENT_TEMPLATE
