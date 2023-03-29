//
// Created by zodia on 27.03.2023.
//

#ifndef CC2_MENU_H
#define CC2_MENU_H

#include <memory>
#include <vector>
#include <thread>
#include <functional>
#include <map>
#include <condition_variable>

class Menu {
public:
    explicit Menu(const std::vector<std::pair<std::string, std::function<void()>>> &menuPos = {},
                  unsigned short menuCurrent = 0,
                  unsigned short menuLast = 0);

    ~Menu();

    void showMenu();

    void hideMenu();

    void turnOffKeyDetect();

    void turnOnKeyDetect();

    void menuChoose();

    void menuDraw();

    void menuUp();

    void menuDown();

    void detectKey();

    void toggleMenuPtr(unsigned short pos, bool ptr);

private:
    void menuSelect();

    bool menuActive = true;

    bool keyDetectionEnabled = true;

    unsigned short menuPosCount;
    std::vector<std::pair<std::string, std::function<void()>>> menuPos;
    unsigned short menuCurrent;
    unsigned short menuPrevious;
    std::jthread keyThread;
    std::atomic<int> key;
};


#endif //CC2_MENU_H
