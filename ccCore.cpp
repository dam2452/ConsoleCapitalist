//
// Created by zodia on 28.03.2023.
//
//#include <cstdint>
//std::int64_t test
#include <iostream>
#include "ccCore.h"
#include "Menu.h"
#include "business.h"
#include <iomanip>
#include <fstream>
#include <math.h>1

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <fstream>

#define CLEAR "cls"
#else
#include <unistd.h>
#include <termios.h>

static char getch(){
    struct termios old, current;

    tcgetattr(0, &old);

    current = old;

    // disabling the buffer and the visibility of entered key
    current.c_lflag &= ~ICANON;
    current.c_lflag &= ~ECHO;

    tcsetattr(0, TCSANOW, &current);

    char ch;
    std::cin.get(ch);

    tcsetattr(0, TCSANOW, &old);

    return ch;
}

#define CLEAR "clear"
#endif

std::string ccCore::simplifyNumber(long double value) {
    if(value==0) return "0";
    const char* units[] = {"", "k", "M", "B", "T", "Q"};
    int exponent = static_cast<int>(std::log10(value));
    int unitIndex = std::min(exponent / 3, 5);
    double shortValue = value / std::pow(1000.0, unitIndex);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << shortValue << units[unitIndex];
    return oss.str();
}

void ccCore::drawIntro() {
    std::cout << " ________  ________  ________   ________  ________  ___       _______                         \n"
                 "|\\   ____\\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   __  \\|\\  \\     |\\  ___ \\                        \n"
                 "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\    \\ \\   __/|                       \n"
                 " \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\_____  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\_|/__                     \n"
                 "  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\\\ \\  \\|____|\\  \\ \\  \\\\\\  \\ \\  \\____\\ \\  \\_|\\ \\                    \n"
                 "   \\ \\_______\\ \\_______\\ \\__\\\\ \\__\\____\\_\\  \\ \\_______\\ \\_______\\ \\_______\\                   \n"
                 "    \\|_______|\\|_______|\\|__| \\|__|\\_________\\|_______|\\|_______|\\|_______|                   \n"
                 "                                  \\|_________|                                                \n"
                 "                                                                                              \n"
                 "                                                                                              \n"
                 " ________  ________  ________  ___  _________  ________  ___       ___  ________  _________   \n"
                 "|\\   ____\\|\\   __  \\|\\   __  \\|\\  \\|\\___   ___\\\\   __  \\|\\  \\     |\\  \\|\\   ____\\|\\___   ___\\ \n"
                 "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\___|\\|___ \\  \\_| \n"
                 " \\ \\  \\    \\ \\   __  \\ \\   ____\\ \\  \\   \\ \\  \\ \\ \\   __  \\ \\  \\    \\ \\  \\ \\_____  \\   \\ \\  \\  \n"
                 "  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\___|\\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\____\\ \\  \\|____|\\  \\   \\ \\  \\ \n"
                 "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\   \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\____\\_\\  \\   \\ \\__\\\n"
                 "    \\|_______|\\|__|\\|__|\\|__|     \\|__|    \\|__|  \\|__|\\|__|\\|_______|\\|__|\\_________\\   \\|__|\n"
                 "                                                                          \\|_________|        \n"
                 "                                                                                              \n"
                 "                                                                                              ";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system(CLEAR);
}

void ccCore::showCredits() {
    menu.hideMenu();
    menuPage = true;
    keyDetectionEnabled = true;
    system(CLEAR);

    std::cout << std::setw(15) << "CREDITS:" << std::endl << std::endl;
    std::cout << "Game concept: Damian Koterba" << std::endl;
    std::cout << "Game design: Damian Koterba" << std::endl;
    std::cout << "Programming: Damian Koterba" << std::endl;
    std::cout << "Graphics: Damian Koterba" << std::endl;
    std::cout << "Sound effects: Damian Koterba" << std::endl;
    std::cout << "Music: Damian Koterba" << std::endl;
    std::cout << "Level design: Damian Koterba" << std::endl;
    std::cout << "Testing: Damian Koterba" << std::endl;
    std::cout << "Marketing: Damian Koterba" << std::endl;
    std::cout << "Production: Damian Koterba" << std::endl;
}

void ccCore::showSettings() {
    menu.hideMenu();
    menuPage = true;
    keyDetectionEnabled = true;
    system(CLEAR);

    std::cout << std::setw(15) << "Settings:" << std::endl << std::endl;
    std::cout << "WIP" << std::endl;
}

void ccCore::exitGame() {
    saveProgress();
    exit(0);
}

void ccCore::hideCursor() {
#ifdef _WIN32
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
#else
    std::cout << "\033[?25l";
    std::cout.flush();
#endif
}

void ccCore::showCursor() {
#ifdef _WIN32
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
#else
    std::cout << "\033[?25h";
    std::cout.flush();
#endif
}

void ccCore::newGame() {
    money = 10;
    bisSetDefault();
    showGame();
}

void ccCore::continueGame() {
    loadSave();
    showGame();
}

void ccCore::ccStart() {
    hideCursor();
    drawIntro();
    while (true) {
        menu.menuDraw();
        drawGame();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void ccCore::drawGame() {
    if (gameActive) {
#ifdef _WIN32
        COORD pos = {0, 0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
#else
        std::cout << "\033[2J\033[1;1H";
#endif

        std::cout << std::string(70, '-') << std::endl;
        std::cout << std::setw(39) <<"Your Cash:" << std::setw(6)<< simplifyNumber(money) <<"$" << std::endl;
        std::cout << std::string(70, '-') << std::endl;
        std::cout << std::setw(0);
        for (size_t i = 0; i < bis.size(); ++i) {
            std::cout << std::setw(5) << i + 1 << ". "
                      << std::setw(15) << bis[i].businessGetName()
                      << std::setw(15) << simplifyNumber(bis[i].businessGetPrice()) << "$"
                      << std::setw(15) << "Owned: " << bis[i].businessGetCount()
                      << std::setw(10) << simplifyNumber(bis[i].businessGetProfit()) << "$/s" << std::endl;
        }
        std::cout << std::string(70, '-') << std::endl;
        std::cout << std::setw(65)<< "CONTROLS: (1,2,3..0) - buying business | (esc) - back to menu" << std::endl;
        std::cout << std::string(70, '-') << std::endl;
        std::cout << std::setw(50)<< "Press E to buy Elon Musk (300mld)" << std::endl;
        std::cout << std::string(70, '-') << std::endl;
        std::cout.flush();
    }
}

void ccCore::bisSetDefault() {
    bis = {
            {"Lemonade",  10,       0.5,    0},
            {"Newspaper", 20,       1,      0},
            {"CarWash",   100,      5,      0},
            {"Pizza",     200,      10,     0},
            {"Donuts",    500,      25,     0},
            {"Seafood",   1000,     50,     0},
            {"Hockey",    10000,    500,    0},
            {"Cinemas",   100000,   5000,   0},
            {"Bank",      1000000,  50000,  0},
            {"Oil",       10000000, 500000, 0}
    };
}

ccCore::~ccCore() {
    saveProgress();
}

ccCore::ccCore(long double money, long double totalProfit) : menu({
    {"Continue",      [this]() { continueGame(); }},
    {"New Game",      [this]() { newGame(); }},
    {"Settings",      [this]() { showSettings(); }},
    {"Credits",       [this]() { showCredits(); }},
    {"Save and Exit", [this]() { exitGame(); }}}),
    money(money), totalProfit(totalProfit) {
    bisSetDefault();
    keyThread = std::jthread{[&]() { detectKey(); }};
    moneyThread = std::jthread{[&]() { moneyUpdate(); }};


}

void ccCore::backToMenu() {
    menu.showMenu();
    menu.turnOnKeyDetect();
    menuPage = false;
    gameActive = false;
    keyDetectionEnabled = false;
    system(CLEAR);
}

void ccCore::showGame() {
    menu.hideMenu();
    menu.turnOffKeyDetect();
    keyDetectionEnabled = true;
    gameActive = true;
    system(CLEAR);
}

void ccCore::detectKey() {
    while (true) {
        //Do zrobienia wyłączanie wątku
        if (keyDetectionEnabled) {
            key = getch();
            //esc key
            switch (key) {
                //esc key
                case 27:
                    if (menuPage) backToMenu();
                    else {
                        saveProgress();
                        (gameActive) ? backToMenu() : showGame();
                    }
                    break;
                    //1 key
                case 49:
                    if (money >= bis[0].businessGetPrice()) {
                        money -= bis[0].businessGetPrice();
                        bis[0].businessBuy();
                    }
                    break;
                    //2 key
                case 50:
                    if (money >= bis[1].businessGetPrice()) {
                        money -= bis[1].businessGetPrice();
                        bis[1].businessBuy();
                    }
                    break;
                    //3 key
                case 51:
                    if (money >= bis[2].businessGetPrice()) {
                        money -= bis[2].businessGetPrice();
                        bis[2].businessBuy();
                    }
                    break;
                    //4 key
                case 52:
                    if (money >= bis[3].businessGetPrice()) {
                        money -= bis[3].businessGetPrice();
                        bis[3].businessBuy();
                    }
                    break;
                    //5 key
                case 53:
                    if (money >= bis[4].businessGetPrice()) {
                        money -= bis[4].businessGetPrice();
                        bis[4].businessBuy();
                    }
                    break;
                    //6 key
                case 54:
                    if (money >= bis[5].businessGetPrice()) {
                        money -= bis[5].businessGetPrice();
                        bis[5].businessBuy();
                    }
                    break;
                    //7 key
                case 55:
                    if (money >= bis[6].businessGetPrice()) {
                        money -= bis[6].businessGetPrice();
                        bis[6].businessBuy();
                    }
                    break;
                    //8 key
                case 56:
                    if (money >= bis[7].businessGetPrice()) {
                        money -= bis[7].businessGetPrice();
                        bis[7].businessBuy();
                    }
                    break;
                    //9 key
                case 57:
                    if (money >= bis[8].businessGetPrice()) {
                        money -= bis[8].businessGetPrice();
                        bis[8].businessBuy();
                    }
                    break;
                    //0 key
                case 48:
                    if (money >= bis[9].businessGetPrice()) {
                        money -= bis[9].businessGetPrice();
                        bis[9].businessBuy();
                    }
                    break;
                    //e key
                case 101:
        if (money >= 300000000) {
            money -= 300000000;
            drawWin();
        }
                    break;
            }
        }
    }
}

void ccCore::moneyUpdate() {
    while (true) {
        if (gameActive) {
            totalProfit = 0.0;
            for (auto &bi: bis)
                totalProfit += bi.businessGetTotalProfit();
            money += totalProfit;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}

void ccCore::loadSave() {
    std::ifstream saveFile("saveCC.txt");
    if (!saveFile.is_open()) {
        std::cerr << "Error opening save file!\n";
        return;
    }
    std::string tempStr;
    long double tempDouble;
    saveFile >> money;
    for (auto &bi: bis) {
        saveFile >> tempStr;
        bi.businessSetName(tempStr);
        saveFile >> tempDouble;
        bi.businessSetCount(tempDouble);
    }
    saveFile.close();
}

void ccCore::saveProgress() {
    std::ofstream saveFile("saveCC.txt");
    if (!saveFile.is_open()) {
        std::cerr << "Error opening save file!\n";
        return;
    }
    saveFile << money << " ";
    for (auto &bi: bis) {
        saveFile << bi.businessGetName();
        saveFile << " ";
        saveFile << bi.businessGetCount();
        saveFile << " ";

    }
    saveFile.close();
}

void ccCore::drawWin() {
    gameActive = false;
    menu.hideMenu();
    saveProgress();
    menuPage = true;
    keyDetectionEnabled = true;
    system(CLEAR);
    std::cout<<"  ___    ___ ________  ___  ___     \n"
               " |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\    \n"
               " \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\\\  \\   \n"
               "  \\ \\    / / \\ \\  \\\\\\  \\ \\  \\\\\\  \\  \n"
               "   \\/  /  /   \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \n"
               " __/  / /      \\ \\_______\\ \\_______\\\n"
               "|\\___/ /        \\|_______|\\|_______|\n"
               "\\|___|/                             \n"
               "                                    \n"
               "                                    \n"
               " ___       __   ___  ________       \n"
               "|\\  \\     |\\  \\|\\  \\|\\   ___  \\     \n"
               "\\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\    \n"
               " \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\   \n"
               "  \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\  \n"
               "   \\ \\____________\\ \\__\\ \\__\\\\ \\__\\ \n"
               "    \\|____________|\\|__|\\|__| \\|__| \n"
               "                                    ";

}


