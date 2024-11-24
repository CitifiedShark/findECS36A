#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
This program determines whether a substring exists within a string
If it does, then it also displays the index at which the substring first appears in the string

1. Ask for the user input for the substring and string
2. Find out if the substring exists in the string
3. Find the index that the substring first appears in the string
4. displays the index that the substring first appears in the string to the user
*/
int findIndex(const char substring[100], const char string[100]) {
    int index;
    char *addressSubStr = strstr(string, substring); //Address of substring in string
/*
This function finds the index at which the substring first appears in the string
@substring[100]: is the substring from user input
@string[100] is the string from user input
@index: is the index at which the substring first appears in the string
@*addressSubStr: is the address of the substring
@returns 0 for completion
*/
    index = addressSubStr - string; //Subtract by string so we only get location of substring, not location in whole computer

    printf("\"%s\" first appears at index %d in \"%s\".\n", substring, index, string);

    return 0;
}

int find(const char substring[100], const char string[100]) {
/*
This function finds out if the substring appears in the string
If not, tell the user that 
@substring[100]: is the substring from user input
@string[100]: is the string from user input
@returns 0 for completion
*/
    if (strlen(substring) == 0) { //When the substring has nothing ("")
        printf("\"%s\" first appears at index 0 in \"%s\".\n", substring, string);
    } else if (strstr(string, substring) != NULL) {
        findIndex(substring, string);
    } else { //When the substring is not in string
        printf("\"%s\" does not appear in \"%s\".\n", substring, string);
        exit(0); 
    }

    return 0;
}

int removeNewLine(char string[100]) {
/*
This function removes the newline component from the strings of user input so it doesn't show during output
@string[100]: is either string or substring that the user inputted
@returns 0 for completion 
*/
    for (int i = 0; i < (int)strlen(string); i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
        }
    }
    
    return 0;
}


int main() {
    char string[100];
    char substring[100];
/*
This function organizes the whole program
1. Ask for input
2. Remove the \n
3. Find out if the substring is in the string
@string[100]: is the string from user input
@substring[100]: is the string from user input
*/ 

    /* Ask for user input and remove newline*/
    printf("Enter the string to search: ");
    fgets(string, 100, stdin);
    removeNewLine(string);

    printf("Enter the substring to search for: ");
    fgets(substring, 100, stdin);
    removeNewLine(substring);

    /* Find out if substring is in string */
    find(substring, string);

    return 0;
}