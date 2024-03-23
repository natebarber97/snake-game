#include <iostream>
#include <random>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "snake.h"

struct Fruit {
    int rowCoord;
    int colCoord;

    void set() {
        rowCoord = rand() % 17 + 2;
        colCoord = rand() % 79 + 4;
        if (colCoord % 2 == 0) {
            colCoord = colCoord - 1;
        }
    }
};

void render(Snake& s, Fruit& f) {
    system("cls");

    // generate game screen using an array of strings
    std::string render[20];
    render[0] = "-----------------------------------------------------------------------------------";
    render[19] = "-----------------------------------------------------------------------------------";
    for (int i = 1; i < 19; i++) {
        render[i] = "|                                                                                 |";
    }

    // add snake to screen
    s.showSnakeOnScreen(render);

    // add fruit to screen
    // if snake's head is in fruit's coordinates, snake grows bigger and fruit is relocated
    if (render[f.rowCoord][f.colCoord] == 'O') {
        f.set();
        s.addNode();
    }
    else {
        render[f.rowCoord][f.colCoord] = '#';
    }

    // display game screen with snake and fruit
    for (int i = 0; i < 20; i++) {
        std::cout << render[i] << std::endl;
    }

    std::cout << "current score: " << s.getScore();
    std::cout << "\t\t\t\t\t\tpress x to quit" << std::endl;
}

// WASD key controls
void userInput(Snake& s) {
    if (_kbhit()) {
        switch(getch()) {
            case 'w':
                s.setDir('u');
                break;
            case 's':
                s.setDir('d');
                break;;
            case 'a':
                s.setDir('l');
                break;
            case 'd':
                s.setDir('r');
                break;
            case 'x':
                std::cout << "Thank you for playing!" << std::endl;
                Sleep(3000);
                system("cls");
                exit(0);
            default:
                std::cout << "invalid input" << std::endl;
        }
    }
}

int main() {

    system("cls");
    std::cout << "Welcome to Nate's snake game!" << std::endl;
    std::cout << "\nUse the WASD keys to control the movement of the snake" << std::endl;
    std::cout << "\nEat fruit to increase your score, but make sure not to eat your own tail!" << std::endl;
    std::cout << "\npress any key when ready." << std::endl;

    // when user presses a key, begin game loop
    if (getch()) {
        bool repeat = true;
        while (repeat) {
        
            // initialize first snake and fruit
            Snake mySnake;
            Fruit myFruit;
            myFruit.set();

            // game loop continues while snake doesn't touch own tail
            while (!mySnake.isTouching()) {
                render(mySnake, myFruit);
                userInput(mySnake);
                mySnake.moveSnake();
                Sleep(200);
            }
            
            // When snake dies, display game over message and clear input
            std::cout << "\nYou bit yourself! Your final score is " << mySnake.getScore() << " points. Press enter to continue." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');

            // user can try again by pressing 'y' or exit out of the game loop by pressing any other key
            std::cout << "Would you like to play again? Press the 'y' key to replay, or any other key to quit." << std::endl;
            if (getch() != 'y') {
                repeat = false;
            }
        }

        std::cout << "\nThank you for playing! have a great day!" << std::endl;
        Sleep(3000);
        system("cls");
    }

    return 0;
}