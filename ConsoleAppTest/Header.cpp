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
        cout << "  � Create new taskbook - 1\n  � Settings - 2\n  � Open list my taskbooks - 3\n  � Create a temporary task book - 4\n  � Exit - Q\n"sv;
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
    case 4:
        DefaultColor();
        cout << "Enter the number change task: "sv;
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
            return 0;
        }
    } while (right_input == false);
}


void save(string user_task, int num_task) {
    vector<string> one_line;
    string num = to_string(num_task);
    one_line = { num, " - [", " ", "] ", user_task};
    two_dimensional_array.push_back(one_line);
}

void WriteTasks(int number_task) {
    int counter{ 0 };
    string user_task{};
    do {
        counter++;
        cout << counter << " - [ ] ";
        getline(cin >> ws, user_task);
        save(user_task, counter);
        user_task = "";
    } while (counter != number_task);
}

void OutputTasks(int number_change) {
    for (int iter = 0; iter < two_dimensional_array.size(); iter++) {
        for (int j = 0; j < two_dimensional_array[iter].size(); j++) {
            if (j == 2 and two_dimensional_array[iter][j] == " " and iter == number_change - 1) {
                cout << "X";
                two_dimensional_array[iter][2] = "X";
            }
            else if (j == 2 and two_dimensional_array[iter][j] == "X" and iter == number_change - 1) {
                cout << " ";
                two_dimensional_array[iter][2] = " ";
            }
            else {
                cout << two_dimensional_array[iter][j];
            }
        }
        cout << endl;
    }
}

void OutputTasks(bool value) {
    for (int iter = 0; iter < two_dimensional_array.size(); iter++) {
        for (int j = 0; j < two_dimensional_array[iter].size(); j++) {
            if (j == 2 and two_dimensional_array[iter][j] == " ") {
                cout << "X";
                two_dimensional_array[iter][2] = "X";
            }
            else if (j == 2 and two_dimensional_array[iter][j] == "X") {
                cout << " ";
                two_dimensional_array[iter][2] = " ";
            }
            else {
                cout << two_dimensional_array[iter][j];
            }
        }
        cout << endl;
    }
}

int CheckNotComplited() {
    int counter{};
    for (auto& iter : two_dimensional_array) {
        if (iter[2] == " ") {
            counter++;
        }
    }
    return counter;
}

bool Acts::TemporaryTaskBook() {
    ConsoleOUT(Temporary_taskbook);
    unsigned int number_of_tasks{}, not_completed{};
    cin >> number_of_tasks;
    not_completed = number_of_tasks;
    WriteTasks(number_of_tasks);
    string command{};
    while (not_completed != 0) {
        ConsoleOUT(Command_mark);
        string command{};
        cin >> command;
        if (command == "q") {
            return true;
        }
        else if (command == "change_status") {
            ConsoleOUT(Number_of_stat);
            int num_change_task{};
            cin >> num_change_task;
            OutputTasks(num_change_task);
            not_completed = CheckNotComplited();
        }
        else if (command == "change_status -all") {
            OutputTasks(true); //In Developing)
            not_completed = CheckNotComplited();
        }
        else if (command == "menu") {
            return false;
        }
    }
}