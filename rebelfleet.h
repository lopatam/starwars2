#ifndef STARWARS2_REBELFLEET_H
#define STARWARS2_REBELFLEET_H

#include <iostream>
#include <cassert>
#include <cstdio>
#define pr if(1)

#define explorer_id 1;
#define starcruiser_id 2;
#define xwing_id 3;


using ShieldPoints = int;
using Speed = int;
using AttackPower = int;

class RebelStarship {
protected:
    ShieldPoints shieldValue;
    Speed speedValue;
    AttackPower attackValue;
public:
    RebelStarship(ShieldPoints shield, Speed speed, AttackPower attack) :
    shieldValue(shield), speedValue(speed), attackValue(attack) {
		pr printf("konstruktor rebelstarship sie wywoluje i zapisuje %d %d %d\n", shieldValue, speedValue, attackValue);
    }

    ShieldPoints getShield() {
        return shieldValue;
    }

    Speed getSpeed() {
        return speedValue;
    }

    void takeDamage(AttackPower damage) {
        if (shieldValue > damage) shieldValue -= damage;
        else shieldValue = 0;
    }

    AttackPower getAttackPower() {
        return attackValue;
    }
};

//TODO: zastanowić się nad zmianą funkcji fabrykujących na sprytne wskaźniki

class Explorer : public RebelStarship {
protected:


public:
    Explorer(ShieldPoints shield, Speed speed) : shieldValue(shield), speedValue(speed) {
        assert(speed >= 299796 && speed <= 2997960);
    }

    AttackPower getAttackPower = delete;
	Explorer createExplorer(ShieldPoints shield, Speed speed) {
		return new Explorer(shield, speed);
	}
};

class StarCruiser : public RebelStarship {
protected:


public:
    StarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) : RebelStarship(shield, speed, attack) {
        assert(speed >= 99999 && speed <= 299795);
    }
	
	StarCruiser createStarCruiser(ShieldPoints shield, Speed speed, AttackPower attack) {
		return new StarCruiser(shield, speed, attack);
	}

};

class XWing : public RebelStarship {
protected:

public:
    XWing(ShieldPoints shield, Speed speed, AttackPower attack) : RebelStarship(shield, speed, attack) {
        assert(speed >= 299796 && speed <= 2997960);
    }

	XWing createXWing(ShieldPoints shield, Speed speed, AttackPower attack) {
		return new XWing(shield, speed, attack);
	}
};


 


#endif //STARWARS2_REBELFLEET_H
