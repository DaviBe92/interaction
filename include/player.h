# pragma once
#include "player.h"

class Player {
    public:
        Player(){
            _score = 0;
        }

    void addScore(){
        _score++;
    }

    int getScore(){
        return _score;
    }

    protected:
    int _score;

};