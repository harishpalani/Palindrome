/**
 * Palindrome
 * 
 * IDEA
 * Create a program that will read in a series of characters; only read in 80 characters at most. Remove all spaces and punctuation. (20 points) 
 * Check to see if the input is the same backwards as it is forwards. If it is a palindrome (the same backwards and forwards), print “Palindrome”.  
 * If not, print “Not a palindrome.” (20 points)
 * 
 * IMPLEMENTATION
 * Read in from cin into a character array. Don’t forget to remove punctuation and spaces!  
 * You probably want to create a second character array, and put all the characters in backwards. Compare the two arrays, and see if they are the same. 
 * There are a number of ways to implement this, so I’m going to leave the implementation details to you. Comments? Comments! (5 points)
 * 
 * @author Harish Palani
 * @version 1.0
 */

#include <iostream>
#include <string.h>

using namespace std;

int reverseWord(char *input, char *reversedWord) {
    int i = 0;

    if (*input == '\0') {
        return i;
    } else {
        i = reverseWord(input + 1, reversedWord);
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
    
    // Identify & mark all punctuation
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
    
    // Remove all punctuation and standardize all letters to uppercase
    int count = 0;
    for (int j = 0; j < 81; j++) {
        if (input[j] != '#') {
            input[j] = toupper(input[j]);
            originalWord[count] = input[j];
            count++;
        }
        if (input[j] == '\0') { break; }
    }
    
    // Determine the reverse of the original input
    reverseWord(originalWord, reversedWord);
    
    // Identify the position of the null-terminating character in the original word
    int c = 0;
    for (int k = 0; k < 81; k++) {
        if (originalWord[k] != '\0') {
            c++;
        } else {
            break;
        }
    }
    reversedWord[c] = '\0';

    // Format & output the results
    cout << '\n' << "Original: " << originalWord << " / " << "Reversed: " << reversedWord << '\n' << endl;
    if (strcmp(originalWord, reversedWord) == 0) {
        cout << originalWord << " is a palindrome." << endl;
    } else {
        cout << originalWord << " is not a palindrome." << endl;
    }

    return 0;
}
