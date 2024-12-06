#include <ctype.h>
#include <stdio.h>

int getc(FILE *stream); // example to show file pointer param

int main() {
    char ch = '\0';
    FILE *fp;

    if (fp = fopen("other.c", "rw")) {
        ch = getc(fp);

        while (ch != EOF) {
            ch = getc(fp);
            printf("%c", ch);
        }
        fclose(fp);
    }
    fp = fopen("other.c", "r");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return 1;
    }
    printf("reading from file\n");
    while (1) {
        ch = fgetc(fp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
    printf("closing the file\n");
    fclose(fp);

    while (isspace(ch = getchar())); // read as long as space does not
    ungetc(ch, stdin);   // put back the non-space characher
    printf("char is %c\n", getchar());


    // ch = getc(stdin);
    // printf("type %c\n", ch);
    // printf("type %c using getchar\n", getchar());
    // int c = 0;
    // while (c = getchar() != EOF) {
    //     printf("%c", c);
    //     // use Ctrl + D to exit
    // }

    return 0;
}
