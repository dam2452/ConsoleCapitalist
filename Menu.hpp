#pragma once
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

    //menu show
    void showMenu();

    void hideMenu();

    void menuDraw();

    //key detection
    void turnOffKeyDetect();

    void turnOnKeyDetect();

    //menu control
    void menuUp();

    void menuDown();

    void menuChoose();

private:
    void toggleMenuPtr(unsigned short pos, bool ptr);

    void detectKey();

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

