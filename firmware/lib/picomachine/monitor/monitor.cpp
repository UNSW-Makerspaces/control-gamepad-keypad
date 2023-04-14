/**
 * Author: Michael W. Lloyd
 * Email:  micl_dev@protonmail.com
 * Date:   14/04/2023
 *
 */

#include "monitor.h"

Machine::Machine() {
    state = State::WAIT;
    led_color = LED_Color::LED_BLUE;
}

void Machine::set_state(State new_state) {
    state = new_state;
    update_led_color();
}


State Machine::get_state() const {
    return state;
}

LED_Color Machine::get_led_color() const {
    return led_color;
}

void Machine::update_led_color() {
    switch (state) {
        case State::RUNNING:
            led_color = LED_Color::LED_GREEN;
            break;
        case State::STARTING:
        case State::IDLE:
            led_color = LED_Color::LED_YELLOW;
            break;
        case State::STOPPING:
            led_color = LED_Color::LED_RED;
            break;
        case State::WAIT:
            led_color = LED_Color::LED_BLUE;
            break;
    }
}

void Machine::start() {
    if (state == State::WAIT || state == State::IDLE) {
        set_state(State::STARTING);
    }
}

void Machine::stop() {
    if (state == State::RUNNING) {
        set_state(State::STOPPING);
    }
}

void Machine::pause() {
    if (state == State::RUNNING) {
        timestamp_paused = time(NULL);
        set_state(State::IDLE);
    }
}

void Machine::restart() {
    if (state == State::IDLE) {
        set_state(State::STARTING);
    }
}
