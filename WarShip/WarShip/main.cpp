//
//  main.cpp
//  cpp-test
//
//  Created by Geeth Madhushan on 2021-01-31.
//

#include <iostream>

// below are the constants and global vairables.

const int BATTLEGROUND_LENGTH = 7;
const int BATTLEGROUND_HEIGHT = 9;

std::string battleground[BATTLEGROUND_HEIGHT][BATTLEGROUND_LENGTH];

enum class AttackType {STRAIGHT, LISH};

int a_position[2];
int b_position[2];

int missile_position[2];

// below are the action methods.

void printMessage(const char * message) {
    std::cout << message;
}

void updateMissilePosition(int x, int y) {
    missile_position[0] = y;
    missile_position[1] = x;
}

void updatePositionA(int x, int y) {
    a_position[0] = y;
    a_position[1] = x;
}

void updatePositionB(int x, int y) {
    b_position[0] = y;
    b_position[1] = x;
}

void updatePositions(int xa, int ya, int xb, int yb) {
    updatePositionA(xa, ya);
    updatePositionB(xb, yb);
}

void initiateBattleGround() {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 6; j++) {
            battleground[i][j] = "  -  ";
        }
    }
}

void drawBattleGround() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 6; j++) {
            std::cout << battleground[i][j];
        }
        
        std::cout << "\n";
    }
}

void emptyBattleGround() {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 6; j++) {
            battleground[i][j] = "  -  ";
        }
    }
    
    updatePositions(-1, -1, -1, -1);
    
    drawBattleGround();
}

void putShipInBattleGround(int xa, int ya, int xb, int yb) {
    if (BATTLEGROUND_HEIGHT > ya && BATTLEGROUND_HEIGHT > yb) {
        if (BATTLEGROUND_LENGTH > xa && BATTLEGROUND_LENGTH > xb) {
            battleground[ya][xa] = "| a |";
            battleground[yb][xb] = "| b |";
            
            updatePositions(xa, ya, xb, yb);
            
            drawBattleGround();
        }
    }
}

void putMissileInBattleGround(int x, int y) {
    if (BATTLEGROUND_HEIGHT > y && BATTLEGROUND_LENGTH > x) {
        battleground[y][x] = "  *  ";
        
        updateMissilePosition(x, y);
        
        drawBattleGround();
    }
}

void lauchStraightAttack(int *from, int *to) {
    // todo
    putMissileInBattleGround(to[1], to[0]);
}

bool attackStraight(std::string from, int* to) {
    if (from == "a") {
        if (a_position[0] - to[0] == 0 || a_position[1] - to[1] == 0 || a_position[0] - to[0] == a_position[1] - to[1]) {
            std::cout << "Launching straight attack from A... \n";
            lauchStraightAttack(a_position, to);
            
            return true;
        } else {
            return false;
        }
    } else if (from == "b") {
        if (b_position[0] - to[0] == 0 || b_position[1] - to[1] == 0 || b_position[0] - to[0] == b_position[1] - to[1]) {
            std::cout << "Launching straight attack from B... \n";
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void attack(std::string from, int* to, AttackType attackType) {
    bool isAttackLaunched = false;
    
    switch (attackType) {
        case AttackType::STRAIGHT:
            isAttackLaunched = attackStraight(from, to);
            break;
        
        case AttackType::LISH:
            std::cout << "Lish attack from " + from;
            isAttackLaunched = true;
            break;
            
        default:
            break;
    }
    
    if (isAttackLaunched) {
        std::cout << "Attack launched successfully!";
    } else {
        std::cout << "Attack failed to launch!";
    }
}

int main(int argc, const char * argv[]) {
    
    initiateBattleGround();
    
    putShipInBattleGround(3, 2, 5, 4);
    std::cout << "\n";
    
    int attackToCoordinates[2];
    attackToCoordinates[0] = 5;
    attackToCoordinates[1] = 6;
    
    attack("a", attackToCoordinates, AttackType::STRAIGHT);
    
    printMessage("\nWelcome to the battleground!\n");
    return 0;
}
