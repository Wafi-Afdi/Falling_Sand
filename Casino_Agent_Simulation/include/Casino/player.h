#pragma once

#include <chrono>

#include "Casino/house_casino.h"

enum PlayerState {
    TOSLOT,
    ONSLOT,
    PLAYING,
    RESULT,
    EXIT,
    OUT
};

class Player {
private:
    int last_result = 0;

    bool x_stop;
    bool y_stop;

    float x_target_slot;
    float y_target_slot;

    float x_target_exit;
    float y_target_exit;

    float x_spawn_m;
    float y_spawn_m;

    int slot;

    float probability_stop;
    float loss_increment_probability;
    float win_increment_probability;

    int money;


    std::chrono::time_point<std::chrono::high_resolution_clock> last_time;

    PlayerState player_state;

    bool canPlayAgain();

    int player_count = 0;

    

public:
    Player(int index, float x_spawn, float y_spawn, float x_slot, float y_slot, float x_exit, float y_exit);

    void exit();
    void play(Casino_Manager& casino_manager);
    void back();
    void check();

    int lastResult();
    bool nextGame(Casino_Manager& casino_manager);

    int getSlot();

    float getXToSlot();
    float getYToSlot();
    float getXToExit();
    float getYToExit();

    PlayerState getState();

    bool out_of_money;
    bool agent_stop;

};
