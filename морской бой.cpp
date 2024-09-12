#include <iostream>
#include <windows.h>
#include <cwchar>
using namespace std;



int main()
{   
    int func;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "Russian");
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "Морской бой \n";

    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "---------------------\n";
    std::cout << "Убитый корабль - ";
    SetConsoleTextAttribute(hConsole, 4);
    std::cout << "x \n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "Промах - ";
    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "Z \n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "---------------------\n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "Перед игрой советую ознакомится с правилами на сайте - \n";
    SetConsoleTextAttribute(hConsole, 5);
    std::cout << "https://goo.su/rUuA \n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "---------------------\n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "Введите цифру для выполнения команды...\n";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "1 - Начать игру\n";
    std::cout << "2 - Выход\n";
    std::cin >> func;
    if (func == 1)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "Игра \n";
    }
}

