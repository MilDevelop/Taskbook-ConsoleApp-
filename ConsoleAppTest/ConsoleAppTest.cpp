#include "Header.h"

int main()
{ 
    ConsoleOUT(Openning);
    ConsoleOUT(Choose_menu);
    ConsoleOUT(Command_mark);
    int User_choose = choose();
    DefaultColor();
    if (User_choose == 4) {
        ConsoleOUT(Temporary_taskbook);
        unsigned int number_of_tasks{}, not_completed{};
        cin >> number_of_tasks;
        not_completed = number_of_tasks;
        WriteTasks(number_of_tasks);
        while (not_completed != 0) {
            ConsoleOUT(Command_mark);
            string command{}, cmd;
            cin >> command;
            //if (command == "change_status")
        }
    }
    else if (User_choose == 5) { return 0; }
    return 0;
}
