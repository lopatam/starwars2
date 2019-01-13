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
public:
    explicit Squadron(std::vector<ImperialStarship> &ships) : ships(ships) {
    }

    Squadron(const std::initializer_list<ImperialStarship> &ships) : ships(ships) {
    }

    //TODO: trzeba napisać override do funkcji getShield, takeDamage i getAttackPower
    //mój pomysł na te funkcje: napisać prywatną funkcję update() która rekurencyjnie policzy w squadronie liczbę
    //żywych statków, sumę tarcz, sumę ataków i zapiszę wszystkie te wartości do zmiennych alive, attackValue,
    //shieldValue.
    //update wywoływałaby się przy każdym wywołaniu tych trzech powyższych funkcji (być może za wolne będzie?)
    //overridy tych trzech funkcji wyżej wyglądałyby następująco:
    //  {
    //      update()
    //      return <wartość którą chcemy zwrócić>
    //  }
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

std::shared_ptr<Squadron> createSquadron(std::initializer_list <ImperialStarship> const &ships) {
    return std::make_shared<Squadron>(std::initializer_list<ImperialStarship> {ships});
}

#endif //STARWARS2_IMPERIALFLEET_H
