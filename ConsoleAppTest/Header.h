#ifndef HEADER_H
#define HEADER_H
//
#include <iostream>
#include <sstream>
#include <istream>
#include <ostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include<windows.h>
#include <string>
#include <string_view>

using namespace std;
//
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
enum message_code
{
     Openning = 0,
     Choose_menu = 1,
     Temporary_taskbook = 2,
     Command_mark = 3
};
extern vector<vector<string>> two_dimensional_array = {};
// application functions
void SetColor(int text, int background);
void DefaultColor();
void ConsoleOUT(int code_message);
int choose();
// For temporary task book
class Temporary_tasks {
public:
    static void save(string user_task, int number_task);
    static void WriteTasks(int number_task);
};


#endif