#include <stdio.h>
#include <string.h>

typedef struct {
    int count;
    int attackBonus;
    int defenseBonus;
} Troop;

typedef struct {
    int leftFlank;
    int front;
    int rightFlank;
    int courtyard;
} BattleResults;

typedef struct {
    int leftFlankTroops;
    int frontTroops;
    int rightFlankTroops;
    int leftFlankTools[2];
    int frontTools[3];
    int rightFlankTools[2];
} Wave;

typedef struct {
    int attackBonusMelee;
    int attackBonusRanged;
    int wallReduction;
    int moatReduction;
    int gateReduction;
} AttackTools;

typedef struct {
    int moatStrength;
    int wallStrength;
    int gateStrength;
    int meleeStrength;
    int rangedStrength;
} Defense;

int calculateLosses(int attackStrength, int defenseStrength, int attackType, int defenseType) {
    int MELEE;
    int RANGED;
    if (attackType == MELEE && defenseType == MELEE) {
        return attackStrength - (defenseStrength * 1.2);
    } else if (attackType == RANGED && defenseType == MELEE) {
        return attackStrength - (defenseStrength * 0.8);
    } else if (attackType == RANGED && defenseType == RANGED) {
        return attackStrength - (defenseStrength * 1.2);
    } else if (attackType == MELEE && defenseType == RANGED) {
        return attackStrength - (defenseStrength * 0.8);
    }
    return 0;
}

void simulateFlank(Troop *attacker, Troop *defender, BattleResults *results) {
    results->leftFlank = calculateLosses(attacker[0].count, defender[0].count, attacker[1].count, defender[1].count);
}

int main() {
    Defense defense = {
        .moatStrength = 100,
        .wallStrength = 205,
        .gateStrength = 0,
        .meleeStrength = 100,
        .rangedStrength = 100
    };
    AttackTools tools = {
        .moatReduction = 50,
        .wallReduction = 160,
        .gateReduction = 0
    };
    int finalMeleeStrength = 0;
    int finalRangedStrength = 0;
    printf("Final Melee Strength: %d%%\n", finalMeleeStrength);
    printf("Final Ranged Strength: %d%%\n", finalRangedStrength);

    return 0;
}
