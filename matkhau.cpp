#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char* Pwd() {
    char *S = (char *)malloc(40 * sizeof(char));
    if (S == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int ch;
    while ((ch = getch()) != '\r' && ch != '\n' && ch != EOF) {
        printf("%c", '*');
        S[i] = ch;
        i++;
    }

    S[i] = '\0';
    return S;
}

int main() {
    char *password = Pwd();
    printf("\nPassword: %s\n", password);

    // Don't forget to free the allocated memory
    free(password);

    return 0;
}

