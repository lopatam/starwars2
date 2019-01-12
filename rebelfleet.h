#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>
#include "helper.h"

#define pr if(1)

#define explorer_id 1;
#define starcruiser_id 2;
#define xwing_id 3;

class RebelStarship {
};

//TODO: zastanowić się nad zmianą funkcji fabrykujących na sprytne wskaźniki


class Explorer : public RebelStarship, public ShieldedStarship, public MovingStarship {

public:
    Explorer(ShieldPoints shield, Speed speed)
        : ShieldedStarship(shield),
          MovingStarship(speed) {

        assert(speed >= 299796 && speed <= 2997960);
    }

	Explorer createExplorer(ShieldPoints shield, Speed speed) {
		return new Explorer(shield, speed);
	}
};

class StarCruiser : public RebelStarship, public ShieldedStarship, public MovingStarship {

public:
    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack)
        : ShieldedStarship(shield),
          MovingStarship(speed),
          AttackingStarship(attack) {

        assert(speed >= 99999 && speed <= 299795);
    }

	StarCruiser createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
		return new StarCruiser(shield, speed, attack);
	}

};

class XWing : public RebelStarship, public ShieldedStarship, public MovingStarship {

public:
    XWing(ShieldPoints shield, Speed speed, AttackPower attack)
        : ShieldedStarship(shield),
          MovingStarship(speed),
          AttackingStarship(attack) {

        assert(speed >= 299796 && speed <= 2997960);
    }

	XWing createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
		return new XWing(shield, speed, attack);
	}
};

#endif //STARWARS2_REBELFLEET_H
