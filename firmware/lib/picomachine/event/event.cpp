/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 *
 */

#include "event.h"
#include "monitor.h"

void Event::start(Machine &machine) {
    if (machine.get_state() == State::WAIT || machine.get_state() == State::IDLE) {
        machine.set_state(State::STARTING);
    }
}

void Event::stop(Machine &machine) {
    if (machine.get_state() == State::RUNNING) {
        machine.set_state(State::STOPPING);
    }
}

void Event::pause(Machine &machine) {
    if (machine.get_state() == State::RUNNING) {
        machine.set_state(State::IDLE);
    }
}

void Event::restart(Machine &machine) {
    if (machine.get_state() == State::IDLE) {
        machine.set_state(State::STARTING);
    }
}
