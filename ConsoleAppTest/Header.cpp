#include "Header.h"

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void DefaultColor() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((Black << 4) | 15));
}

void ConsoleOUT(int code_message) {
    switch (code_message) {
    case 0:
        cout << "Hello, welcome to the universal console application called Taskbook!"sv << endl;
        break;
    case 1:
        cout << "Choose action, please: "sv << endl;
        SetColor(LightBlue, Black);
        cout << "  · Create new taskbook - 1\n  · Settings - 2\n  · Open list my taskbooks - 3\n  · Create a temporary task book - 4\n  · Exit - Q\n"sv;
        DefaultColor();
        break;
    default:
        break;
    }
}

