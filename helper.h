#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

#include <algorithm>
#include <cassert>
#include <memory>
#define pr if (1)

using AttackPower = int;
using ShieldPoints = int;
using Speed = int;

class SpaceBattle;

class Starship {
    friend SpaceBattle;
protected:
    size_t alive = 1;
    ShieldPoints shieldValue;
public:

    virtual size_t getAlive() {
        return alive;
    }

    explicit Starship(ShieldPoints shield) : shieldValue(shield) {
        assert(shield >= 0);
    }
    virtual ShieldPoints getShield() {
        return shieldValue;
    }
    virtual void takeDamage(AttackPower damage) {
        if(shieldValue < damage) {
            shieldValue = 0;
            alive = 0;
        }
        else shieldValue -= damage;
    }
};

class AttackingStarship {
protected:

    AttackPower attackValue;

    explicit AttackingStarship(AttackPower attack) : attackValue(attack) {
        assert(attack >= 0);
    }

public:
    virtual AttackPower getAttackPower() {
        return attackValue;
    }
};

#endif //STARWARS2_HELPER_H
