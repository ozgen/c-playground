#include <ctype.h>
#include <stdio.h>

int main() {
    char ch = '\0';
    FILE *fp;

    fp = fopen("other.c", "r");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return 1;
    }
    printf("reading from file\n");
    while (1) {
        ch = getc(fp);
        if (ch == EOF) {
            break;
        }
        putc(ch, stdout); // or set File pointer
    }
    printf("closing the file\n");
    fclose(fp);

    char sample_text[] = "Hello World! \n 2nd line of this sentence.";
    int i = 0;
    while (sample_text[i] != '\0') {
        if (sample_text[i] != '\n') {
            putchar(sample_text[i]);
        }
        ++i;
    }

    return 0;
}
