#ifndef STARWARS2_HELPER_H
#define STARWARS2_HELPER_H

#include <algorithm>
#include <cassert>

using AttackPower = int;
using ShieldPoints = int;
using Speed = int;

class Starship {
};

class AttackingStarship : public virtual Starship {

protected:
    AttackPower attackValue;

    AttackingStarship(AttackPower attack) : attackValue(attack) {
        assert(attack >= 0);
    }

public:
    AttackPower getAttackPower() {
        return attackValue;
    }
};

class ShieldedStarship : public virtual Starship {

protected:
    ShieldPoints shieldValue;

    ShieldedStarship(ShieldPoints shield) : shieldValue(shield) {
        assert(shield >=  0);
    }

public:
    ShieldPoints getShield() {
        return shieldValue;
    }

    void takeDamage(AttackPower damage) {
        shieldValue = std::max(shieldValue - damage, 0);
    }

};

class MovingStarship : public virtual Starship {
protected:
    Speed speedValue;

    MovingStarship(Speed speed) : speedValue(speed) {
        assert(speed >= 0);
    }

public:
    Speed getSpeed() {
        return speedValue;
    }
};

#endif //STARWARS2_HELPER_H
