/**
 * Author: Michael W. Lloyd
 * Email: micl_dev@protonmail.com
 * Date: 14/04/2023
 *
 */

#ifndef MONITOR_H
#define MONITOR_H

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

private:
    void update_led_color();

    State state;
    LED_Color led_color;
};

#endif // MONITOR_H