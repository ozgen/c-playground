#include <stdio.h>

int display();

void test_func1(int);
void test_func2(int);

typedef void FunctionPointer(int);

int main() {
    int (*func_ptr)();
    func_ptr = display;
    printf("Address of func_ptr is %p\n", func_ptr);
    func_ptr();

    FunctionPointer *func_ptr2 = NULL;
    func_ptr2 = test_func1;
    func_ptr2(5);
    func_ptr2 = test_func2;

    func_ptr2(4);
    return 0;
}

int display() {
    printf("Hello World!\n");
    return 0;
}

void test_func1(int arg) {
    printf("test_func1 arg is %d\n", arg);
}
void test_func2(int arg) {
    printf("test_func2 arg is %d\n", arg);
}