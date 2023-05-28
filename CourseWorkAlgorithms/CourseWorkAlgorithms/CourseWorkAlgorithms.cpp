#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;

bool isOpeningBracket(char c) {
    return c == '(' || c == '{' || c == '[' || c == '<' || c == '/';
}

bool isClosingBracket(char c) {
    return c == ')' || c == '}' || c == ']' || c == '>' || c == '\\';
}

bool isMatchingBracket(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']') || (opening == '<' && closing == '>') || (opening == '/' && closing == '\\');
}

bool isBalanced(const string& sequence) {
    stack<char> brackets;

    for (char c : sequence) {
        if (isOpeningBracket(c)) {
            brackets.push(c);
        }
        else if (isClosingBracket(c)) {
            if (brackets.empty() || !isMatchingBracket(brackets.top(), c)) {
                return false;
            }
            brackets.pop();
        }
        else {
            return false;
        }
    }

    return brackets.empty();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string sequence;
    string filename = "C:/Users/messi/PycharmProjects/CourseWorkAlgorithms/correct_nested_brackets_sequence.txt";
    ifstream input_file(filename);
    if (!input_file) {
        cerr << "Не удалось открыть файл " << filename << endl;
        return 1;
    }
    input_file >> sequence;
    input_file.close();

    int num_tests = 12;

    for (int test = 1; test <= num_tests; ++test) {
        auto start_time = chrono::high_resolution_clock::now();

        if (isBalanced(sequence)) {
            cout << "Тест " << test << ": Последовательность корректна." << endl;
        }
        else {
            cout << "Тест " << test << ": Последовательность некорректна." << endl;
        }

        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

        cout << "Тест " << test << ": Время выполнения алгоритма: " << duration << " микросекунд" << endl;
        cout << endl;
    }

    return 0;
}