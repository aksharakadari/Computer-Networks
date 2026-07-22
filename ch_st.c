##include <stdio.h>
#include <string.h>

int main() {
    char input[50], stuffed[100] = "F"; 
    int j = 1;

    printf("Enter data string: ");
    scanf(" %49[^\n]", input); 

    for (int i = 0; input[i] != '\0'; i++) {
        
        if (input[i] == 'F') {
            stuffed[j++] = 'X'; 
        }
        stuffed[j++] = input[i];
    }
    
    stuffed[j++] = 'F'; 
    stuffed[j] = '\0';  

    printf("Stuffed Frame: %s\n", stuffed);
    return 0;
}

