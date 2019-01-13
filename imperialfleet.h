#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "helper.h"
#include <vector>
#include <memory>

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

    Squadron(std::initializer_list <Starship> &ships) {
        this->ships = ships;
    }
};

std::shared_ptr<DeathStar> createDeathStar(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<DeathStar>(shield, attack);
}

std::shared_ptr<ImperialDestroyer> createImperialDestroyer(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<ImperialDestroyer>(shield, attack);
}

std::shared_ptr<TIEFighter> createTIEFighter(ShieldPoints shield, AttackPower attack) {
    return std::make_shared<TIEFighter>(shield, attack);
}

std::shared_ptr<Squadron> createSquadron(std::vector <Starship> &ships) {
    return std::make_shared<Squadron>(ships);
}

std::shared_ptr<Squadron> createSquadron(std::initializer_list <Starship> &ships) {
    return std::make_shared<Squadron>(ships);
}

#endif //STARWARS2_IMPERIALFLEET_H
