#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "helper.h"
#include <vector>
//#include <initializer_list>
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
    std::vector<std::shared_ptr<ImperialStarship>> ships;

    void update() {
        alive = 0;
        shieldValue = 0;
        attackValue = 0;
        for (const auto &i : ships) {
            alive += i -> getAlive();
            shieldValue += i -> getShield();
            attackValue += i -> getAttackPower();
        }
    }

public:
    explicit Squadron(std::vector<std::shared_ptr<ImperialStarship>> ships) {
        this -> ships = std::move(ships);
        update();
    }

    void takeDamage(AttackPower damage) override {
        for (auto &i : ships) {
            i -> takeDamage(damage);
        }
        update();
    }

    ShieldPoints getShield() override {
        ShieldPoints result = 0;
        for (auto &i : ships) {
            result += i -> getShield();
        }
        return result;
    }

    AttackPower getAttackPower() override{
        AttackPower result = 0;
        for (auto &i : ships) {
            if (i -> getShield() > 0)
                result += i -> getAttackPower();
        }
        return result;
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

std::shared_ptr<Squadron> createSquadron(std::vector <std::shared_ptr<ImperialStarship>> ships) {
    pr printf("wywolanie wektora\n");
    return std::make_shared<Squadron>(ships);
}


/*std::shared_ptr<Squadron> createSquadron(std::initializer_list <std::shared_ptr<ImperialStarship>> const &ships) {
    pr printf("wywolanie listy\n");
    return std::make_shared<Squadron>(ships);
}*/

#endif //STARWARS2_IMPERIALFLEET_H