#include "Header.h"

int main()
{ 
    ConsoleOUT(Openning);
    ConsoleOUT(Choose_menu);
    int User_choose = choose();
    switch (User_choose)
    {
    case 4:
        ConsoleOUT(Temporary_taskbook);
        unsigned int number_of_tasks{}, not_completed{};
        cin >> number_of_tasks;
        not_completed = number_of_tasks;
        WriteTasks(number_of_tasks);
        while (not_completed != 0) {
            ConsoleOUT(Command_mark);
            string command{};
            getline(cin >> ws, command);         
        }
        break;
    }
    return 0;
}
