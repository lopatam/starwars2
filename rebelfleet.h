#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>
#include "helper.h"
#include <memory>

#define pr if(1)

#define explorer_id 1;
#define starcruiser_id 2;
#define xwing_id 3;

class RebelStarship {
};

class Explorer : public RebelStarship, public ShieldedStarship, public MovingStarship {

public:
    Explorer(ShieldPoints shield, Speed speed)
        : ShieldedStarship(shield),
          MovingStarship(speed) {

        assert(speed >= 299796 && speed <= 2997960);
    }
};

class StarCruiser : public RebelStarship, public ShieldedStarship, public MovingStarship, public AttackingStarship {

public:
    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack)
        : ShieldedStarship(shield),
          MovingStarship(speed),
          AttackingStarship(attack) {

        assert(speed >= 99999 && speed <= 299795);
    }
};

class XWing : public RebelStarship, public ShieldedStarship, public MovingStarship, public AttackingStarship {

public:
    XWing(ShieldPoints shield, Speed speed, AttackPower attack)
        : ShieldedStarship(shield),
          MovingStarship(speed),
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
