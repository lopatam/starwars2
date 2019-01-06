#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>

#define explorer_id 1;
#define starcruiser_id 2;
#define xwing_id 3;


using ShieldPoints = int;
using Speed = int;
using AttackPower = int;

class RebelStarship {
protected:
    ShieldPoints shieldValue;
    Speed speedValue;
    AttackPower attackValue;
public:
    RebelStarship() {

    }

    ShieldPoints getShield() {
        return shieldValue;
    }

    Speed getSpeed() {
        return speedValue;
    }

    void takeDamage(AttackPower damage) {
        if (shieldValue > damage) shieldValue -= damage;
        else shieldValue = 0;
    }

    AttackPower getAttackPower() {
        return attackValue;
    }
};

class Explorer : public RebelStarship {
protected:


public:
    Explorer(ShieldPoints shield, Speed speed) : RebelStarship(shield, speed, -1) {
        assert(speed >= 299796 && speed <= 2997960);
    }

    AttackPower getAttackPower = delete;
};

class StarCruiser : public RebelStarship {
protected:


public:
    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) : RebelStarship(shield, speed, attack) {
        assert(speed >= 99999 && speed <= 299795);
    }


};

class XWing : public RebelStarship {
protected:

public:
    XWing(ShieldPoints shield, Speed speed, AttackPower attack) : RebelStarship(shield, speed, attack) {
        assert(speed >= 299796 && speed <= 2997960);
    }


};

//poniżej jest próba napisania tych function

class Factory {
public:
    public RebelStarship createShip(int id, ShieldPoints shield, Speed speed, AttackPower attack) {
        if (id == explorer_id) return new Explorer(shield, speed);

        if (id == starcruiser_id) return new StarCruiser(shield, speed, attack);

        if(id == xwing_id) return new XWing(shield, speed, attack);

        return nullptr;
    }
};
class ExplorerFactory : public Factory {
public:
    public Explorer createExplorer(ShieldPoints shield, Speed speed, AttackPower attack) {
        return //????
    }
};


#endif //STARWARS2_REBELFLEET_H
