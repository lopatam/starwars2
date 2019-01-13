#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "helper.h"
#include <vector>
#include <memory>

class ImperialStarship : public Starship, public AttackingStarship{
protected:

public:
    ImperialStarship(ShieldPoints shield, AttackPower attack)
            : Starship(shield), AttackingStarship(attack) {}
    ImperialStarship()
            : Starship(0), AttackingStarship(0){}
};

class DeathStar : public ImperialStarship{
public:
    DeathStar(ShieldPoints shield, AttackPower attack)
            : ImperialStarship(shield, attack){}
};

class ImperialDestroyer : public ImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield, AttackPower attack)
            : ImperialStarship(shield, attack){}
};

class TIEFighter : public ImperialStarship {
public:
    TIEFighter(ShieldPoints shield, AttackPower attack)
            : ImperialStarship(shield, attack){}
};

class Squadron : public ImperialStarship {

private:
    std::vector<ImperialStarship> ships;

    void update() {
        alive = 0;
        shieldValue = 0;
        attackValue = 0;
        for(auto &i : ships) {
            alive += i.getAlive();
            shieldValue += i.getShield();
            attackValue += i.getAttackPower();
        }
    }

public:
    explicit Squadron(std::vector<ImperialStarship> &ships) : ships(ships) {
        update();
    }

    /*Squadron(const std::initializer_list<ImperialStarship> &ships) : ships(ships) {
        update();
    }*/ //TODO

    void takeDamage(AttackPower damage) override {
        for(auto &i : ships) {
            i.takeDamage(damage);
        }
        update();
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

std::shared_ptr<Squadron> createSquadron(std::vector <ImperialStarship> &ships) {
    return std::make_shared<Squadron>(ships);
}

/*
std::shared_ptr<Squadron> createSquadron(std::initializer_list <ImperialStarship> const &ships) {
    return std::make_shared<Squadron>(std::initializer_list<ImperialStarship> {ships});
}*/ //TODO

#endif //STARWARS2_IMPERIALFLEET_H
