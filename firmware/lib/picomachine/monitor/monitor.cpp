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

    // Entry debug message to indicate the pause() function is called
    picomachine_debug_log("picomachine", "Machine", "pause", "Entering pause() function");

    if (state == State::RUNNING) {
        timestamp_paused = get_absolute_time();
        set_state(State::IDLE);
        // Exit debug message to indicate machine is pausing
        picomachine_debug_log("picomachine", "Machine", "pause", "Machine is pausing");
    } else {
        // Machine cannot be paused in its current state
        picomachine_debug_log("picomachine", "Machine", "pause", "Machine cannot be paused in its current state");
    }

    return;
}

void Machine::restart() {

    picomachine_debug_log("picomachine", "Machine", "restart", "Entering restart() function");

    if (state == State::IDLE) {

        // Debug message to indicate machine is restarting from paused state
        picomachine_debug_log("picomachine", "Machine", "restart", 
            "Restarting from paused state");

        stop(); // Stop the machine if it's in idle state
                
        start(); // Start the machine again

        // Check if the machine started successfully
        if (state != State::RUNNING) {
            picomachine_debug_log("picomachine", "Machine", "restart", 
                "Failed to start the machine after pausing");
        }

    } else if (state == State::RUNNING) {
        // Debug message that machine was restarted mid-job without pausing
        picomachine_debug_log("picomachine", "Machine", "restart", 
            "Restarting mid-job without pausing");

        stop(); // Stop the machine if it's in running state

        // Check if the machine stopped successfully
        if (state != State::STOPPING) {

            pause(); // Attempt machine state rescue with pause
                     
            if (state == State::IDLE) {
                start(); // Start the machine again if it successfully paused
            } else {
                // Machine failed to stop and pause, entering a critical error state
                picomachine_debug_log("picomachine", "Machine", "restart", 
                    "Critical error: failed to stop and pause the machine");
                // Set the LED to LED_RED
                led_color = LED_Color::LED_RED;
                // Add an attribute "LED_BLINK"
                uint16_t LED_BLINK = 150; // ms delay for the LED to blink
                return;
            }

        } else {

            picomachine_debug_log("picomachine", "Machine", "restart", 
                    "Machine stopped successfully, restarting the job");

            start(); // Start the machine again
                     
        }

    } else {

        // Job was asked to restart in an invalid state
        picomachine_debug_log("picomachine", "Machine", "restart", 
            "Job was asked to restart in an invalid state");

        return;

    }

    // Job was successfully restarted
    picomachine_debug_log("picomachine", "Machine", "restart", "Job successfully restarted");

    return;
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
