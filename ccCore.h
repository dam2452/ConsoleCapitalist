//
// Created by zodia on 28.03.2023.
//

#ifndef CC2_CCCORE_H
#define CC2_CCCORE_H
#include "business.h"
#include "Menu.h"
#include <vector>

class ccCore {
public:
    ccCore(long double money = 10, long double totalProfit = 0.0);

   ~ccCore();
   void drawWin();
    void bisSetDefault();
    void showCredits();
    void exitGame();
    void drawIntro();
    void drawGame();
    void hideCursor();
    void newGame();
    void showCursor();
    void showGame();
    void backToMenu();
    void detectKey();
    void showingMenu();
    void ccStart();
    void moneyUpdate();
    void saveProgress();
    void loadSave();
    void drawSettings();
    void hideCredits();
    void continueGame();
    void showSettings();
private:
    std::string simplifyNumber(long double value);
    std::vector<business> bis;
    long double totalProfit;
    long double money;
    Menu menu;
    bool gameActive = false;
    std::jthread keyThread;
    std::jthread moneyThread;
    std::atomic <int> key;
    bool keyDetectionEnabled = false;
    bool menuPage = false;
};


#endif //CC2_CCCORE_H
