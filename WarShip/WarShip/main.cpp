//
//  main.cpp
//  cpp-test
//
//  Created by Geeth Madhushan on 2021-01-31.
//

#include <iostream>

void printMessage(const char * message) {
    std::cout << message;
}

void drawBattleGround() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << "| - | ";
        }
        
        std::cout << "\n";
    }
}

void putShipInBattleGround(int xa, int ya, int xb, int yb) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 6; j++) {
            if (xa == j && ya == i) {
                std::cout << "| a |";
            } else if (xb == j && yb == i) {
                std::cout << "| b |";
            } else {
                std::cout << "  -  ";
            }
        }
        
        std::cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    
//    drawBattleGround();
    putShipInBattleGround(3, 2, 5, 4);
    
    printMessage("\nWelcome to the battleground!\n");
    return 0;
}
