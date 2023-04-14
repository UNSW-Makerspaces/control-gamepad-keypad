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

    picomachine_debug_log("picomachine", "Machine", "update_led_color", "Changing LED color");

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
        default:
            led_color = LED_OFF; 
            break; 
    }

    picomachine_debug_log("picomachine", "Machine", 
            "update_led_color", LED_Color_to_string(led_color).c_str());
}

void Machine::start() {

    picomachine_debug_log("picomachine", "Machine", "start", "Starting the machine");

    switch (state) { 
        case State::WAIT: 

            picomachine_debug_log("picomachine", "Machine", "start", 
                    "Job started from the beginning");
            
            set_state(State::STARTING);
            timestamp_started = get_absolute_time();

            break; 
        case State::IDLE: 

            picomachine_debug_log("picomachine", "Machine", "start", "Job was unpaused");

            set_state(State::RUNNING);
            timestamp_started += absolute_time_diff_us(timestamp_paused, get_absolute_time());

            break;
        default: 
            picomachine_debug_log("picomachine", "Machine", "start", 
              "Start condition invalid because machine is busy");
            break; 
    } 

}

void Machine::stop() {

    picomachine_debug_log("picomachine", "Machine", "stop", "Entering stop() function");

    if (state == State::RUNNING) {

        picomachine_debug_log("picomachine", "Machine", "stop", "Halting mid-job");

        set_state(State::STOPPING);
        timestamp_paused = get_absolute_time();

    } else if (state == State::IDLE) {

        picomachine_debug_log("picomachine", "Machine", "stop", 
            "Stopped while paused, canceling the job");

        set_state(State::WAIT);

    } else {

        picomachine_debug_log("picomachine", "Machine", "stop", 
            "Machine cannot stop unless it is stoppable");
        
        // Return early on error and handle accordingly.
        
        return;
    }

    // Exit debug message to indicate that the machine is successfully stopping, print times
    picomachine_debug_log("picomachine", "Machine", "stop", 
        "Exiting stop() function, machine successfully stopping");

    // Get every timed period relevant
    float elapsed_time_running = get_elapsed_time_running();
    float elapsed_time_idle = get_elapsed_time_idle();
    // Debug message showing elapsed_time_running and elapsed_time_idle
    picomachine_debug_log("picomachine", "Machine", "stop", 
            "Elapsed time running: " 
            + std::to_string(elapsed_time_running)
            + ", Elapsed time idle: " 
            + std::to_string(elapsed_time_idle)
        );

    return;
}

void Machine::pause() {

    // FIXME: Add entry debug message to indicate the pause() function is called
    if (state == State::RUNNING) {
        timestamp_paused = get_absolute_time();
        set_state(State::IDLE);
        // FIXME: Add exit debug message to indicate machine is pausing
    }
}

void Machine::restart() {
    // FIXME: Add entry debug message to indicate the restart() function is called
    if (state == State::IDLE) {
        set_state(State::STARTING);
        timestamp_started = get_absolute_time();
        // FIXME: Add exit debug message to indicate machine is restarting
    }
}

float Machine::get_elapsed_time_idle() const {
    if (state == State::IDLE) {
        float elapsed_time = absolute_time_diff_us(timestamp_paused, get_absolute_time()) / 1e6;
        return elapsed_time;
    } else {
        return time_idle;
    }
}

float Machine::get_elapsed_time_running() const {
    if (state == State::RUNNING) {
        float elapsed_time = absolute_time_diff_us(timestamp_started, get_absolute_time()) / 1e6;
        return elapsed_time;
    } else {
        return time_running;
    }
}
