#ifndef STARWARS2_IMPERIALFLEET_H
#define STARWARS2_IMPERIALFLEET_H

#include "helper.h"
#include <vector>

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
    explicit Squadron(std::vector<ImperialStarship> &ships) {   // czy to zadziała dla tych initializer_list?
        this->ships = ships;
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
//TODO: dopisać funkcję fabrykującą squadronu, dla vektora i dla initializer_list

#endif //STARWARS2_IMPERIALFLEET_H