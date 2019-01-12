#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "helper.h"
#include <vector>

class ImperialStarship {
};

class DeathStar : public ImperialStarship, public ShieldedStarship, public AttackingStarship {
public:
    DeathStar(ShieldPoints shield, AttackPower attack)
        : ShieldedStarship(shield),
        AttackingStarship(attack){}
};

class ImperialDestroyer : public ImperialStarship, public ShieldedStarship, public AttackingStarship {
public:
    ImperialDestroyer(ShieldPoints shield, AttackPower attack)
        : ShieldedStarship(shield),
        AttackingStarship(attack){}
};

class TIEFighter : public ImperialStarship, public AttackingStarship, public ShieldedStarship {
public:
    TIEFighter(ShieldPoints shield, AttackPower attack)
        : ShieldedStarship(shield),
        AttackingStarship(attack){}
};

class Squadron : public ImperialStarship {

private:
    std::vector <Starship> ships;

public:
    Squadron(std::vector <Starship> &ships) {
        this->ships = ships;
    }
};

#endif //STARWARS2_IMPERIALFLEET_H
