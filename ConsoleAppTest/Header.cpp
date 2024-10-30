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
        break;
    case 1:
        cout << "Hello, welcome to the universal console application called Taskbook!"sv << endl;
        break;
    case 2:
        cout << "Choose action, please: "sv << endl;
        SetColor(LightBlue, Black);
        cout << "  · Create new taskbook - 1\n  · Settings - 2\n  · Open list my taskbooks - 3\n  · Create a temporary task book - 4\n  · Exit - Q\n"sv;
        break;
    case 3:
        SetColor(LightGray, Black);
        cout << "\tYour taskbook on today\n";
        cout << "Enter the number of tasks and after enter the tasks: ";
        break;
    case 4:
        SetColor(LightGray, Black);
        cout << " > ";
        break;
    case 5:
        DefaultColor();
        cout << "Enter the number change task: "sv;
        break;
    case 6:
        SetColor(LightBlue, Black);
        cout << "What is TaskBook name? :\n"sv;
        cout << '\t';
        break;
    case 7:
        SetColor(Red, Black);
        cout << "\nYour need write a number in this field (:\n"sv;
        break;
    case 8:
        SetColor(Red, Black);
        cout << "\nOut of range\n"sv;
        break;
    case 9:
        SetColor(LightGreen, Black);
        cout << "\tYour taskbook on today\n";
        SetColor(LightGray, Black);
        cout << "Enter the number of tasks and after enter the tasks: ";
        break;
    default:
        break;
    }
    DefaultColor();
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

void WriteTasks(int number_task, TaskBook* TB) {
    int counter{ 0 };
    string user_task{};
    do {
        counter++;
        cout << counter << " - [ ] ";
        getline(cin >> ws, user_task);
        save(user_task, counter);
        user_task = "";
    } while (counter != number_task);
    (*TB).data_mtrx = two_dimensional_array;
}

void OutputTasks(int number_change, TaskBook* TB) {
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
    (*TB).data_mtrx = two_dimensional_array;
}

void OutputTasks(bool value, TaskBook* TB) {
    for (int iter = 0; iter < two_dimensional_array.size(); iter++) {
        for (int j = 0; j < two_dimensional_array[iter].size(); j++) {
            if (j == 2 and two_dimensional_array[iter][j] == " " and value == true) {
                cout << "X";
                two_dimensional_array[iter][2] = "X";
            }
            else {
                cout << two_dimensional_array[iter][j];
            }
        }
        cout << endl;
    }
    (*TB).data_mtrx = two_dimensional_array;
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

int CheckNotComplited(vector<vector<string>>& matrix) {
    int counter{};
    for (auto& iter : matrix) {
        if (iter[2] == " ") {
            counter++;
        }
    }
    return counter;
}


void file_save(vector<vector<string>>& cache) { //rewrite
    
}

void file_save(vector<vector<string>>& cache, TaskBook* Pointer) { //Add info

    ofstream SavedFile("Data.md", ios::app);
    SavedFile << "### " << Pointer->name << endl;
    for (auto& item : cache) {
        for (auto& ch : item) {
            SavedFile << ch;
        }
        SavedFile << endl;
    }
    SavedFile.close();
}


bool Acts::TB_Conslole(TaskBook* Pointer, unsigned int error_code) {
    system("cls");
    ConsoleOUT(error_code);
    OutputTasks(false, Pointer);
    string command{};
    unsigned int not_completed = CheckNotComplited(Pointer->data_mtrx);
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
            OutputTasks(num_change_task, Pointer);
            if (Pointer->stable) { file_save(two_dimensional_array, Pointer); }
            not_completed = CheckNotComplited();
        }
        else if (command == "complete-all") {
            OutputTasks(true, Pointer);
            if (Pointer->stable) { file_save(two_dimensional_array, Pointer); }
            not_completed = CheckNotComplited();
        }
        else if (command == "menu") {
            return false;
        }
    }
}


bool Acts::TemporaryTaskBook(TaskBook* Pointer) {
    two_dimensional_array.clear();
    string name_of_TTB{};
    ConsoleOUT(Named_for_TB);
    cin >> name_of_TTB;
    Pointer->name = name_of_TTB;
    ConsoleOUT(Temporary_taskbook);
    unsigned int number_of_tasks{}, not_completed{};
    cin >> number_of_tasks;
    not_completed = number_of_tasks;
    WriteTasks(number_of_tasks, Pointer);
    All_Stack.push_back(Pointer);
    return TB_Conslole(Pointer, NoProblem);
}

bool Acts::StableTaskBook(TaskBook* Pointer) {
    two_dimensional_array.clear();
    string name_of_STB{};
    ConsoleOUT(Named_for_TB);
    cin >> name_of_STB;
    Pointer->name = name_of_STB;
    Pointer->stable = true;
    ConsoleOUT(Stable_TaskBook);
    unsigned int number_of_tasks{}, not_completed{};
    cin >> number_of_tasks;
    not_completed = number_of_tasks;
    WriteTasks(number_of_tasks, Pointer);
    All_Stack.push_back(Pointer);
    file_save(two_dimensional_array, Pointer);
    return TB_Conslole(Pointer, NoProblem);
}

bool Acts::ListOfTaskBooks() {
    for (int i = 0; i < All_Stack.size(); ++i) {
        cout << i + 1 << " -> " << All_Stack[i]->name << " ";
    }
    auto choose = new int;
    Input:
    ConsoleOUT(Command_mark);
    cin >> *choose;
    if (cin.fail()) { 
        ConsoleOUT(TypeError_Message);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto Input; 
    }
    else if (abs(*choose) <= All_Stack.size()) {
        TaskBook* temp = All_Stack[All_Stack.size() - 1];
        All_Stack[All_Stack.size() - 1] = All_Stack[*choose - 1];
        All_Stack[*choose - 1] = temp;
        delete choose;
        cout << endl;
        return true;
    }
    else {
        return false;
    }
}



