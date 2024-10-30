#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <string_view>
#ifdef _WIN32

#include <Windows.h>

#ifdef max
#undef max

#endif


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
     NoProblem = 0,
     Openning = 1,
     Choose_menu = 2,
     Temporary_taskbook = 3,
     Command_mark = 4,
     Number_of_stat = 5,
     Named_for_TB = 6,
     TypeError_Message = 7,
     ListError_Message = 8,
     Stable_TaskBook = 9
};


//Define TaskBook
struct TaskBook {
    vector<vector<string>> data_mtrx;
    string name; //Fucking up this string !!!
    bool stable = false;
    pair<int, int> place_in_SavedFile;
    TaskBook() : data_mtrx(NULL), name("Untitled TaskBook") {};
    TaskBook(vector<vector<string>>& data, string& name) : data_mtrx(data), name(name) {};
    TaskBook(string& name) : data_mtrx(NULL), name(name) {};
    TaskBook(vector<vector<string>>& data) : data_mtrx(data), name("Untitled TaskBook") {};
};
    

inline vector<vector<string>> two_dimensional_array;
inline vector<TaskBook*> All_Stack;

// application functions
void SetColor(int text, int background);
void DefaultColor();
void ConsoleOUT(int code_message);
int choose();
// For temporary task book

void save(string user_task, int number_task);
void OutputTasks(int number_change, TaskBook* TB);
void OutputTasks(bool value, TaskBook* TB);
void WriteTasks(int number_task, TaskBook* TB);
int CheckNotComplited();
int CheckNotComplited(vector<vector<string>>& matrix);
//for stable TaskBook
void file_save(vector<vector<string>>& cache); //rewrite
void file_save(vector<vector<string>>& cache, TaskBook* Pointer); //add info
//Actions for menu
namespace Acts {
    bool TB_Conslole(TaskBook* Pointer, unsigned int error_code);
    bool TemporaryTaskBook(TaskBook* Pointer);
    bool StableTaskBook(TaskBook* Pointer);
    bool ListOfTaskBooks();
}

#endif

#endif
