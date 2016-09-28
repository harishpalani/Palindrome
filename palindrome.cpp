#include <iostream>
#include <string.h>

using namespace std;

int reverse(char *input, char *reversedWord) {
    int i = 0;

    if (*input == '\0') {
        return i;
    } else {
        i = reverse(input + 1, reversedWord);
    }

    reversedWord[i] = *input;
    i++;
    return i;
}

int main() {
    
    // Request user input
    char input[81];
    cout << "Welcome to the Palindrome Checker!\n\n" << "Enter your phrase below." << endl;
    cin.get(input, 81, '\n');

    for (int i = 0; i < 81; i++) {
        if ((input[i] < 48) || (input[i] > 57 && input[i] < 65) || (input[i] > 90 && input[i] < 97) || (input[i] > 122)) {
            if (input[i] != '\0') {
                input[i] = '#';
            }
        }
        if (input[i] == '\0') { break; }
    }
    
    char originalWord[81];
    char reversedWord[81];
    
    int count = 0;
    for (int j = 0; j < 81; j++) {
        if (input[j] != '#') {
            input[j] = toupper(input[j]);
            originalWord[count] = input[j];
            count++;
        }
        if (input[j] == '\0') { break; }
    }

    reverse(originalWord, reversedWord);

    int c = 0;
    for (int k = 0; k < 81; k++) {
        if (originalWord[k] != '\0') {
            c++;
        } else {
            break;
        }
    }
    reversedWord[c] = '\0';

    cout << '\n' << "Original: " << originalWord << " / " << "Reversed: " << reversedWord << '\n' << endl;

    if (strcmp(originalWord, reversedWord) == 0) {
        cout << originalWord << " is a palindrome." << endl;
    } else {
        cout << originalWord << " is not a palindrome." << endl;
    }

    return 0;
}
