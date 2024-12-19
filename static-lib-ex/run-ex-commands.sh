gcc -c StringFunctions.c -o lib_stringFunctions.o

ar rcs lib_stringFunctions.a lib_stringFunctions.o

ar -t lib_stringFunctions.a

gcc -I./ -c main.c -o main.o

gcc -o main main.o ./lib_stringFunctions.a

./main