#include <stdio.h>
#include <string.h>


int main() {
    char str[100];
    sprintf(str, "Hello World from %d!", 55);
    puts(str);

    FILE * f = NULL;
    if ((f = fopen("data2.txt", "r+")) == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(f, "the count number : %d\n", i);
    }
    fclose(f);

    if (fopen("data2.txt", "r+") == NULL) {
        printf("File does not exist\n");
        return 1;
    }
    printf("File contents:\n");
    while (!feof(f)) {
        fgets(str, sizeof(str), f);
        printf("%s", str);
    }

    char * temp = "Mehmet Engineer 35";
    char name[100], title[100];
    int age =0, ret = 0;
    ret = sscanf(temp, "%s %s %d", name, title, &age);
    printf("The name is : %s\n", name);
    printf("The title is : %s\n", title);
    printf("The age is : %d\n", age);

    return 0;
}
