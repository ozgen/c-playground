#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    // char buffer[255];
    // int ch = '\0';
    // char *p = NULL;
    //
    // if (fgets(buffer, sizeof(buffer), stdin)) {
    //     p = strchr(buffer, '\n');
    //     if (p) {
    //         *p = '\0';
    //     } else {
    //         while ((ch = getchar()) != '\n' && !feof(stdin) && !ferror(stdin));
    //     }
    // }
    //
    // printf("%s", buffer);

    char * buffer = NULL;
    size_t buffer_size = 32;
    size_t char_count = 0;

    buffer = (char *) malloc(buffer_size *sizeof(char));

    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }
    printf("Enter a string: ");

    char_count = getline(&buffer, &buffer_size, stdin);

    printf("The string you entered is: %s\n", buffer);
    puts(buffer);
    printf("The character count is: %zu\n", char_count);

    return 0;
}
