#include "Header.h"
using namespace Acts;

int main()
{ 
    while (true) {
        start:
        ConsoleOUT(Openning);
        ConsoleOUT(Choose_menu);
        ConsoleOUT(Command_mark);
        int User_choose = choose();
        DefaultColor();
        if (User_choose == 3) {
            do {
                ListOfTaskBooks(); //????
            } while (TTB_Conslole(All_Stack[All_Stack.size() - 1]));
        }
        else if (User_choose == 4) {
            auto tb = new TaskBook();
            switch (TemporaryTaskBook(tb)) {
            case false:
                goto start;
            default:
                delete tb;
                return 0;
            }
        }
        else if (User_choose == 5) { return 0; }
    }
    return 0;
}
