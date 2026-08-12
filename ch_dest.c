#include <stdio.h>
#include <string.h>

#define FLAG 'F'
#define ESC  'E'

void destuffData(const char *stuffed, char *destuffed) {
    int i = 0;
    int j = 0;
    int len = strlen(stuffed);

    // Verify and strip the starting flag
    if (stuffed[0] == FLAG) {
        i = 1;
    }

    // Determine the boundary before the ending flag
    int endLimit = len;
    if (len > 1 && stuffed[len - 1] == FLAG) {
        endLimit = len - 1;
    }

    // Process the stuffed payload
    while (i < endLimit) {
        if (stuffed[i] == ESC) {
            // Found escape character; skip it and take the next literal character
            i++; 
            destuffed[j++] = stuffed[i++];
        } else {
            // Regular data character
            destuffed[j++] = stuffed[i++];
        }
    }
    
   
    destuffed[j] = '\0';
}

int main() {
    char stuffedFrame[200];
    char destuffedData[100];

    printf("Enter the stuffed frame (e.g., FABCEDEF): ");
    scanf("%s", stuffedFrame);

    destuffData(stuffedFrame, destuffedData);

    printf("\n--- Results ---\n");
    printf("Stuffed Frame:   %s\n", stuffedFrame);
    printf("Destuffed Data:  %s\n", destuffedData);

    return 0;
}

