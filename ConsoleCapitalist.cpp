#include <windows.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

short menuPosition=0;
bool showMenu=true;
bool showGame=false;
bool winner=false;
const short menuPositions = 2;

std::string StartN="        start ";
std::string StartC="-->     start ";
std::string* startPtr=&StartN;

std::string ExitN="         exit ";
std::string ExitC="-->      exit ";
std::string* exitPtr=&ExitN;

int Lemonade=0,Newspapers=0,Car_wash=0,Pizza=0,
        Donuts=0,Seafood=0,Hockey=0,Cinemas=0,Bank=0,Oil=0;
double Money=10;

void drawWin()
{
    system("cls");
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

void loadSave()
{
    std::fstream save;
    save.open("saveCC.txt",ios::in);

    save >> Money;
    save>>Lemonade;
    save>>Newspapers;
    save>>Car_wash;
    save>>Pizza;
    save>>Donuts;
    save>>Seafood;
    save>>Hockey;
    save>>Cinemas;
    save>>Bank;
    save>>Oil;


    save.close();




}

void saveProgress()
{
    std::fstream save;
    save.open("saveCC.txt",ios::out);

    save << Money << " ";
    save<<Lemonade<<" ";
    save<<Newspapers<<" ";
    save<<Car_wash<<" ";
    save<<Pizza<<" ";
    save<<Donuts<<" ";
    save<<Seafood<<" ";
    save<<Hockey<<" ";
    save<<Cinemas<<" ";
    save<<Bank<<" ";
    save<<Oil<<" ";


    save.close();


}

void keyDetection(){

    if(GetKeyState(VK_ESCAPE) & 0x8000)
    {
        saveProgress();
        Sleep(1000);
        exit(0);
    }
    if(GetKeyState('E') & 0x8000)
    {
        if(Money >= 300000000000)
        {
            Money= Money - 300000000000;
            winner=true;
        }
        Sleep(150);
    }
    if(GetKeyState('1') & 0x8000)
    {
        if(Money >= 10)
        {
            Money= Money - 10;
            Lemonade++;
        }
        Sleep(150);
    }
    if(GetKeyState('2') & 0x8000)
    {
        if(Money >= 20)
        {
            Money= Money - 20;
            Newspapers++;
        }
        Sleep(150);
    }
    if(GetKeyState('3') & 0x8000)
    {
        if(Money >= 100)
        {
            Money= Money - 100;
            Car_wash++;
        }
        Sleep(150);
    }
    if(GetKeyState('4') & 0x8000)
    {
        if(Money >= 200)
        {
            Money= Money - 200;
            Pizza++;
        }
        Sleep(150);
    }
    if(GetKeyState('5') & 0x8000)
    {
        if(Money >= 500)
        {
            Money= Money - 500;
            Donuts++;
        }
        Sleep(150);
    }
    if(GetKeyState('6') & 0x8000)
    {
        if(Money >= 1000)
        {
            Money= Money - 1000;
            Seafood++;
        }
        Sleep(150);
    }
    if(GetKeyState('7') & 0x8000)
    {
        if(Money >= 10000)
        {
            Money= Money - 10000;
            Hockey++;
        }
        Sleep(150);
    }
    if(GetKeyState('8') & 0x8000)
    {
        if(Money >= 100000)
        {
            Money= Money - 100000;
            Cinemas++;
        }
        Sleep(150);
    }
    if(GetKeyState('9') & 0x8000)
    {
        if(Money >= 1000000)
        {
            Money= Money - 1000000;
            Bank++;
        }
        Sleep(150);
    }
    if(GetKeyState('0') & 0x8000)
    {
        if(Money >= 10000000)
        {
            Money= Money - 10000000;
            Oil++;
        }
        Sleep(150);
    }


}

void countMoney()
{

    Money+=(Lemonade * 0.5 + Newspapers * 1 + Car_wash * 5 + Pizza * 10 + Donuts * 25 + Seafood * 50 + Hockey * 500 + Cinemas * 5000 + Bank * 50000 + Oil * 500000);
    Sleep(1000);

}

void drawGame()
{
    system("cls");
std::cout << "--------------------------------------------     Your Cash: " << std::setprecision(1000)<< Money <<"$" << endl;
std::cout<<"1. Lemonade     10$    Owned: "<<Lemonade<<"     0.5$/s"<<endl;
std::cout<<"2. Newspapers   20$    Owned: "<<Newspapers<<"     1$/s"<<endl;
std::cout<<"3. Car wash    100$    Owned: "<<Car_wash<<"     5$/s"<<endl;
std::cout<<"4. Pizza       200$    Owned: "<<Pizza<<"     10$/s"<<endl;
std::cout<<"5. Donuts      500$    Owned: "<<Donuts<<"     25$/s"<<endl;
std::cout<<"6. Seafood    1000$    Owned: "<<Seafood<<"     50$/s"<<endl;
std::cout<<"7. Hockey      10k$    Owned: "<<Hockey<<"     500$/s"<<endl;
std::cout<<"8. Cinemas    100k$    Owned: "<<Cinemas<<"     5000$/s"<<endl;
std::cout<<"9. Bank       1mln$    Owned: "<<Bank<<"     50000$/s"<<endl;
std::cout<<"10. Oil      10mln$    Owned: "<<Oil<<"     500000$/s"<<endl;
std::cout<<"---------------------------------------------"<<endl;
std::cout<<"Use number button to buy your business or esc for exit and save"<<endl;
std::cout<<"---------------------------------------------"<<endl;
std::cout<<"Press E to buy Elon Musk (300mld)"<<endl;




    Sleep(200);

}

void drawIntro() {
std::cout<<" ________  ________  ________   ________  ________  ___       _______                         \n"
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
    Sleep(3000);
    system("cls");
}

void keyPressedMenu(){


    if(GetKeyState(VK_UP) & 0x8000)
    {
if(menuPosition >= 0)
{
    menuPosition--;
}
        Sleep(150);
    }
    if(GetKeyState(VK_DOWN) & 0x8000)
    {
        if(menuPosition <= menuPositions)
        {
            menuPosition++;
        }
        Sleep(150);
    }
    if(GetKeyState(VK_RETURN) & 0x8000) {
        if(startPtr == &StartC)
        {
            showMenu=false;
            loadSave();
            showGame=true;
        }
        else if(exitPtr == &ExitC)
        {
       exit(0);
        }



    }

}

void drawMenu()
{
    switch(menuPosition) {
        case 0:
            startPtr=&StartC;
            exitPtr=&ExitN;
            break;
        case 1:
            exitPtr=&ExitC;
            startPtr=&StartN;
            break;
        default:
            break;
            // code block
    }

std::cout<<"------------------------"<<endl;
std::cout << *startPtr << endl;
std::cout << *exitPtr << endl;
std::cout<<"------------------------"<<endl;
    std::cout<<"Use Arrow and enter"<<endl;
    Sleep(400);
    system("cls");
}


int main()
{

    bool continueLoop=true;
    drawIntro();


while(continueLoop) {

    if(showMenu){
        keyPressedMenu();
        drawMenu();}


    if(showGame){
        keyDetection();
        drawGame();
        countMoney();

    }

if(winner)
{
    showGame=false;
    drawWin();
    Sleep(10000);
    showGame=true;
    winner=false;


}












}

    cin.get();
    return 0;
}