#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>
#include <memory>
#define pr if(1)    // do debugowania, potem się wywali


using ShieldPoints = int;
using Speed = int;
using AttackPower = int;

class RebelStarship {
protected:
    size_t alive = 1;
    ShieldPoints shieldValue = 0;
    Speed speedValue = 0;
    AttackPower attackValue = 0;
    RebelStarship(ShieldPoints shield, Speed speed, AttackPower attack) :
            shieldValue(shield), speedValue(speed), attackValue(attack) {
        pr printf("konstruktor rebelstarship sie wywoluje i zapisuje %d %d %d\n", shieldValue, speedValue, attackValue);
    }
    RebelStarship(){
        pr printf("pusty konstruktor rebelstarship: %d %d %d\n", shieldValue, speedValue, attackValue);
    }
    virtual bool canAttack() {  // TODO: canAttack() będzie potrzebne w funkcji attack()
        return true;            // żeby attack() mogła wywołać canAttack() trzeba będzie "zfriendować"
    }

public:

    ShieldPoints getShield() {
        return shieldValue;
    }

    Speed getSpeed() {
        return speedValue;
    }

    void takeDamage(AttackPower damage) {
        if (shieldValue > damage) shieldValue -= damage;
        else {
            shieldValue = 0;
            alive = 0;
        }
    }

    AttackPower getAttackPower() {
        return attackValue;
    }
};


class Explorer : public RebelStarship {
protected:
    bool canAttack() override {
        return false;
    }
public:
    Explorer(ShieldPoints shield, Speed speed){
        RebelStarship::shieldValue = shield;
        RebelStarship::speedValue = speed;
        assert(speed >= 299796 && speed <= 2997960);
    }
    AttackPower getAttackPower() = delete;
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

std::shared_ptr<Explorer> createExplorer(ShieldPoints shield, Speed speed) {
    return std::make_shared<Explorer>(shield, speed);
}

std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
    return std::make_shared<StarCruiser>(shield, speed, attack);
}

std::shared_ptr<XWing> createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
    return std::make_shared<XWing>(shield, speed, attack);
}

 


#endif //STARWARS2_REBELFLEET_H
