#include <stdio.h>

int main() {
    int nf, w, base = 0, next = 0, tx = 0, choice;

    printf("Enter total frames to send: ");
    scanf("%d", &nf);
    printf("Enter window size: ");
    scanf("%d", &w);

    while (base < nf) {
        while (next < base + w && next < nf) {
            printf("[Tx] Frame %d\n", next);
            next++;
            tx++;
        }

        printf("\nStatus for Frame %d (1 = Received, 0 = Lost): ", base);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("[GBN] Retransmitting from Frame %d\n\n", base);
            next = base; 
        } else {
            printf("[Rx] ACK %d received\n\n", base + 1);
            base++; 
        }
    }
    printf("Transmission complete! Total sent: %d\n", tx);
    return 0;
}

