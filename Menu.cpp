//
// Created by zodia on 27.03.2023.
//

#include <iostream>
#include <iomanip>
#include "Menu.h"
#include <stdexcept>
#include <conio.h>
#include <windows.h>

#include <condition_variable>
#include <mutex>


#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


void Menu::menuDraw() {
    if(menuActive) {
#ifdef _WIN32
        COORD pos = {0, 0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
#else
        std::cout << "\033[2J\033[1;1H";
#endif

        std::cout << std::string(50,'-') << std::endl;
        for (size_t i = 0; i < menuPosCount; i++) {
            std::cout << std::setw(30)<< menuPos[i].first << std::endl;
        }
        std::cout << std::string(50,'-') << std::endl;
        std::cout << std::setw(0)<< "CONTROLS: (arrow up/down) - move | (enter) - choose" << std::endl;
        std::cout.flush();
    }
}

void Menu::menuUp() {
    if (menuCurrent == 0) {
        menuPrevious = menuCurrent;
        menuCurrent = menuPosCount - 1;
    }
    else if(menuCurrent > 0){
        menuPrevious = menuCurrent;
        menuCurrent--;
    }
    menuSelect();
}

void Menu::menuDown() {
    if (menuCurrent == menuPosCount - 1) {
        menuPrevious = menuCurrent;
        menuCurrent = 0;
    }
    else if(menuCurrent < menuPosCount - 1){
        menuPrevious = menuCurrent;
        menuCurrent++;
    }
    menuSelect();
}

void Menu::hideMenu() {
    menuActive = false;
    turnOffKeyDetect();
}

void Menu::showMenu() {
    menuActive = true;
}

void Menu::toggleMenuPtr(unsigned short pos, bool ptr) {
    if (ptr && menuPos[pos].first[0] != '>')
        menuPos[pos].first = "> " + menuPos[pos].first;

    else if(!ptr && menuPos[pos].first[0] == '>')
    menuPos[pos].first.erase(0, 2);
}

void Menu::menuSelect() {
    toggleMenuPtr(menuPrevious, false);
    toggleMenuPtr(menuCurrent, true);
}

Menu::Menu(const std::vector<std::pair<std::string, std::function<void()>>> & menuPos, unsigned short menuCurrent,
           unsigned short menuLast) : menuPos(menuPos),menuCurrent(menuCurrent), menuPrevious(menuLast) {
    menuPosCount = menuPos.size();
    if (menuCurrent > menuPosCount)
        throw std::invalid_argument("menuCurrent > menuPosCount");

    if(menuCurrent < 0)
        throw std::invalid_argument("menuCurrent < 0");

    if(menuPrevious > menuPosCount)
        throw std::invalid_argument("menuLast > menuPosCount");
    menuSelect();


    keyThread = std::jthread{[&]() { detectKey(); }};
}
void Menu::detectKey() {
    while (true) {
        //Do zrobienia wyłączanie wątku
        if (keyDetectionEnabled) {
            key = getch();
            //arrow up
            if (key == 72) {
                menuUp();
            }
            //arrow down
            if (key == 80) {
                menuDown();
            }
            //enter
            if (key == 13) {
                menuChoose();
            }
        }
    }
}

Menu::~Menu() {
    keyThread.request_stop();
    keyThread.join();
}

void Menu::menuChoose() {
    menuPos[menuCurrent].second();
}

void Menu::turnOnKeyDetect() {
   keyDetectionEnabled = true;
}

void Menu::turnOffKeyDetect() {
    keyDetectionEnabled = false;
}