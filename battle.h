#ifndef STARWARS2_BATTLE_H
#define STARWARS2_BATTLE_H

#include <iostream>
#include <cassert>
#include <cstdio>
#include <memory>
#include <vector>
#include "rebelfleet.h"
#include "imperialfleet.h"


using Time = int;

class SpaceBattle {
protected:
    class Clock {
    private:
        Time actTime, maxTime;
    public:
        Clock(Time t1, Time t2) : actTime(t1), maxTime(t2) {
            assert(actTime <= maxTime);
            assert(actTime >= 0);
            assert(maxTime > 0);
        }
        bool canAttackNow() {
            return ((actTime %2 == 0 || actTime %3 == 0) && actTime %5 != 0);

        }
        void passTime(Time t) {
            assert(t >= 0);
            actTime += t;
            actTime %= maxTime; // NIE JESTEM PEWIEN CZY DOKŁADNIE TAK DZIAŁA TEN CZAS
        }
    };

    std::vector<std::shared_ptr<RebelStarship>>rebelShips;
    std::vector<std::shared_ptr<ImperialStarship>>imperialShips;
    Time sTime, mTime;
    Clock myClock;
    SpaceBattle(std::vector<std::shared_ptr<RebelStarship>>rebel,
            std::vector<std::shared_ptr<ImperialStarship>>imperial,
            Time t1, Time t2)
            : sTime(t1), mTime(t2), myClock(t1, t2) {
        rebelShips = std::move(rebel);
        imperialShips = std::move(imperial);
    }
    void attack(ImperialStarship imperialShip, RebelStarship rebelShip) {
        rebelShip.takeDamage(imperialShip.getAttackPower());
        if (rebelShip.canAttack())
            imperialShip.takeDamage(rebelShip.getAttackPower());
    }

public:
    void tick(Time timestep) {
        if(countRebelFleet())
        if (myClock.canAttackNow()) {
            // TODO: jakieś ataki


        }
        myClock.passTime(timestep);
    }
    size_t countRebelFleet() {
        size_t result = 0;
        for (const auto& ship : rebelShips) result += ship -> getAlive();    // nie wiem czy typ shipa jest ok
        return result;
    }
    size_t countImperialFleet() {
        size_t result = 0;
        for (const auto& ship : imperialShips) result += ship -> getAlive();
        return result;
    }

    class Builder {
    private:
        Time mTime, sTime;
        std::vector<std::shared_ptr<RebelStarship>>rebelShips;
        std::vector<std::shared_ptr<ImperialStarship>>imperialShips;
    public:
        Builder maxTime(Time t) {
            mTime = t;
            return *this;
        }
        Builder startTime(Time t) {
            sTime = t;
            return *this;
        }
        Builder ship(std::shared_ptr<RebelStarship> s) {
            rebelShips.push_back(s);
            return *this;
        }
        Builder ship(std::shared_ptr<ImperialStarship> s) {
            imperialShips.push_back(s);
            return *this;
        }
        SpaceBattle build() {
            return SpaceBattle(rebelShips, imperialShips, sTime, mTime);
        }
    };

};


#endif //STARWARS2_BATTLE_H
