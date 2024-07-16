#include "Header.h"

void SetColor(int text, int background) {
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
    case 2:
        SetColor(LightGray, Black);
        cout << "\tYour taskbook on today\n";
        cout << "Enter the number of tasks and after enter the tasks: ";
        DefaultColor();
        break;
    case 3:
        SetColor(LightGray, Black);
        cout << " > ";
        break;
    default:
        break;
    }
}

int choose() {
    char choosing{};
    bool right_input = true;
    do {
        cin >> choosing;
        switch (choosing)
        {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case 'q':
            return 5;
        case 'Q':
            return 5;
        default:
            right_input = false;
            break;
        }
    } while (right_input == false);
}


void Temporary_tasks::save(string user_task, int number_task) {
    for (int i = 1; i <= number_task; i++) {
        vector<string> one_line;
        string num = to_string(i);
        one_line = { num, " - [", " ", "] " };
        two_dimensional_array.push_back(one_line);
    }
}

void Temporary_tasks::WriteTasks(int number_task) {
    int counter{ 0 };
    string user_task{};
    do {
        counter++;
        cout << counter << " - [ ] ";
        getline(cin >> ws, user_task);
        user_task = "";
    } while (counter != number_task);
}
