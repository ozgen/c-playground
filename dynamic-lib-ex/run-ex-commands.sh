gcc -g -fPIC StringFunctions.c -shared -o libStrigFunctions.so

gcc -I./ -c main.c -o main.o

gcc -o main main.o ./libStrigFunctions.so

./main