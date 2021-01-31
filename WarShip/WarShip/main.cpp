//
//  main.cpp
//  cpp-test
//
//  Created by Geeth Madhushan on 2021-01-31.
//

#include <iostream>

// below are the constants and global vairables.

const int BATTLEGROUND_LENGTH = 6;
const int BATTLEGROUND_HEIGHT = 8;

std::string battleground[BATTLEGROUND_HEIGHT][BATTLEGROUND_LENGTH];

enum class AttackType {STRAIGHT, LISH};

int a_position[2];
int b_position[2];

// below are the action methods.

void printMessage(const char * message) {
    std::cout << message;
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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
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

void attack(std::string from, std::string to, AttackType attackType) {
    switch (attackType) {
        case AttackType::STRAIGHT:
            std::cout << "Straight attack from " + from;
            break;
        
        case AttackType::LISH:
            std::cout << "Lish attack from " + from;
            break;
            
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    
    initiateBattleGround();
    putShipInBattleGround(3, 2, 5, 4);
    std::cout << "\n";
    
    attack("a", "b", AttackType::STRAIGHT);
    
    printMessage("\nWelcome to the battleground!\n");
    return 0;
}
