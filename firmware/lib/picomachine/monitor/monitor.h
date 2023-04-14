/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 *
 */

#ifndef MONITOR_H
#define MONITOR_H


#ifdef PICOMACHINE_DEBUG_MODE
#include <cstdio>

inline void picomachine_debug_log(const char* library, const char* cls, const char* func, const char* message) {
    printf("[%s][%s][%s]: %s\n", library, cls, func, message);
}
#else
inline void picomachine_debug_log(const char*, const char*, const char*, const char*) {}
#endif

enum class State {
    IDLE,
    RUNNING,
    STARTING,
    STOPPING,
    WAIT
};

enum class LED_Color {
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_YELLOW,
    LED_WHITE,
    LED_ORANGE,
    LED_NONE
};


class Machine {
public:
    Machine();

    State get_state() const;
    LED_Color get_led_color() const;

    void set_state(State new_state);
    void start();
    void stop();
    void pause();
    void restart();

private:
    void update_led_color();

    State state;
    LED_Color led_color;
    float starting_progress;
    float stopping_progress;
    float time_running_total;
    float time_running;
    float estimate_done;
    float time_idle_total;
    float time_idle;
    unsigned long timestamp_paused;
};


#endif // MONITOR_H
