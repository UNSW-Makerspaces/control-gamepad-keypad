// event.tpp 

/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 */

#ifndef PICOMACHINE_EVENT_TEMPLATE
#define PICOMACHINE_EVENT_TEMPLATE 


template<typename T>
PicoMachine_Event<T>::PicoMachine_Event(uint32_t buffer_size) : buffer_size(buffer_size) {
    queue_init(&fbBuf, sizeof(T), buffer_size);
}

template<typename T>
PicoMachine_Event<T>::~PicoMachine_Event() {
    queue_remove(&fbBuf);
}

template<typename T>
bool PicoMachine_Event<T>::enqueue(const T& data) {
    return queue_try_add(&fbBuf, &data);
}

template<typename T>
bool PicoMachine_Event<T>::dequeue(T& data) {
    return queue_try_remove(&fbBuf, &data);
}

template<typename T>
bool PicoMachine_Event<T>::is_empty() const {
    return queue_is_empty(&fbBuf);
}

template<typename T>
bool PicoMachine_Event<T>::is_full() const {
    return queue_is_full(&fbBuf);
}

#endif // PICOMACHINE_EVENT_TEMPLATE


// vim:ft=cpp
