#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>
#include "helper.h"


class RebelStarship : public Starship{
protected:
    Speed speedValue;
public:
    RebelStarship(ShieldPoints shield, Speed speed)
            : Starship(shield), speedValue(speed) {}
    Speed getSpeed() {
        return speedValue;
    }
};



class Explorer : public RebelStarship{

public:
    Explorer(ShieldPoints shield, Speed speed)
            : RebelStarship(shield, speed) {
        assert(speed >= 299796 && speed <= 2997960);
    }
};

class StarCruiser : public RebelStarship, public AttackingStarship {

public:
    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack)
            : RebelStarship(shield, speed),
              AttackingStarship(attack) {
        assert(speed >= 99999 && speed <= 299795);
    }
};

class XWing : public RebelStarship, public AttackingStarship {

public:
    XWing(ShieldPoints shield, Speed speed, AttackPower attack)
            : RebelStarship(shield, speed),
              AttackingStarship(attack) {

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
