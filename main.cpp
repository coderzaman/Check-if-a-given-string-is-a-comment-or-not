#include <iostream>
#include <stack>
using namespace std;

int main() {
    string input;
    cout << "Enter the input: ";
    getline(cin, input);

    stack<char> multiLineStack;

    int i = 0;
    bool isSingleLineComment = false;
    bool isMultiLineComment = false;

    while (i < input.size() - 1) {
        if (input[i] == '/' && input[i + 1] == '/') {
            isSingleLineComment = true;
            break;
        }

        if (input[i] == '/' && input[i + 1] == '*') {
            multiLineStack.push('/');
            multiLineStack.push('*');
            i++;
        }

        if (!multiLineStack.empty() && multiLineStack.top() == input[i] && input[i+1] == '/') {
            isMultiLineComment = true;
            break;
        }

        i++;
    }

    if (isSingleLineComment) {
        cout << "The input is a single-line comment.";
    } else if (isMultiLineComment && !multiLineStack.empty()) {
        cout << "The input is a multi-line comment.";
    } else {
        cout << "The input is not a comment.";
    }

    return 0;
}
