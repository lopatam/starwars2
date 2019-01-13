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
            if (actTime > maxTime) actTime = actTime % (maxTime + 1);
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
    //void attack(std::shared_ptr<ImperialStarship> imperialShip, std::shared_ptr<)
    void attack(std::shared_ptr<ImperialStarship> const &imperialShip, std::shared_ptr<RebelStarship> const &rebelShip) {
        rebelShip -> takeDamage(imperialShip -> getAttackPower());
        auto checkType = std::dynamic_pointer_cast<AttackingStarship>(rebelShip);
        if(checkType == nullptr) {
        }
        else {
            imperialShip -> takeDamage(checkType -> getAttackPower());
        }
    }

public:
    void tick(Time timestep) {

        if (countRebelFleet() == 0) {           // gdy któraś frakcja nie ma już statków, to czas się nie przesuwa
            if (countImperialFleet() == 0) {    // nie wiem czy to czemuś szkodzi, chyba nie
                std::cout << "DRAW\n";
                return;
            }
            std::cout << "IMPERIUM WON\n";
            return;
        }
        if (countImperialFleet() == 0) {
            std::cout << "REBELLION WON\n";
            return;
        }
        if (myClock.canAttackNow()) {
            for (const auto& imperialShip : imperialShips) {
                for (const auto& rebelShip : rebelShips) {
                    if (imperialShip -> getShield() > 0 && rebelShip -> getShield() > 0)
                        attack(imperialShip, rebelShip);
                }
            }


        }
        myClock.passTime(timestep);
    }
    size_t countRebelFleet() {
        size_t result = 0;
        for (const auto& ship : rebelShips) result += ship -> getAlive();
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
        Builder ship(std::shared_ptr<RebelStarship> const &s) {
            rebelShips.push_back(s);
            return *this;
        }
        Builder ship(std::shared_ptr<ImperialStarship> const &s) {
            imperialShips.push_back(s);
            return *this;
        }
        SpaceBattle build() {
            return SpaceBattle(rebelShips, imperialShips, sTime, mTime);
        }
    };

};


#endif //STARWARS2_BATTLE_H