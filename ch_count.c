#include <stdio.h>

int main() {
    char str[100];
    int count = 0;

    printf("Enter a string: ");
    // fgets reads the whole line, including spaces
    fgets(str, sizeof(str), stdin); 

    // Loop through the string until the null terminator
    while (str[count] != '\0') {
        count++;
    }

    // fgets includes the newline character (\n), so we subtract 1
    if (count > 0 && str[count - 1] == '\n') {
        count--;
    }

    printf("Total characters: %d\n", count);

    return 0;
}

