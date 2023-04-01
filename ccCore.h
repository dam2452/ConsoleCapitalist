#ifndef CC2_CCCORE_H
#define CC2_CCCORE_H

#include "business.h"
#include "Menu.h"
#include <vector>

class ccCore {
public:
    explicit ccCore(long double money = 10, long double totalProfit = 0.0);

    ~ccCore();

    [[noreturn]] void ccStart();

    //Menu
    void continueGame();

    void newGame();

    void showCredits();

    void showSettings();

    void exitGame();

    void backToMenu();

    //game
    void showGame();

    void drawGame();

    [[noreturn]] void detectKey();

    [[noreturn]] void moneyUpdate();

    //save
    void saveProgress();

    void loadSave();

    void bisSetDefault();

    static void drawIntro();

    void drawWin();

private:
    Menu menu;
    long double totalProfit;
    long double money;
    std::vector<business> bis;

    //Cursor
    static void hideCursor();

    [[maybe_unused]] static void showCursor();

    //shorting numbers
    static std::string simplifyNumber(long double value);

    //threads
    std::jthread keyThread;
    std::jthread moneyThread;
    std::atomic<int> key;
    bool gameActive = false;
    bool keyDetectionEnabled = false;
    bool menuPage = false;
};

#endif //CC2_CCCORE_H
