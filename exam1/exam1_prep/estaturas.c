#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    char *name;
    int age;
    double height;
} member;

int main() {
    FILE *inputFile, *outputFile;
    char name_file[] = "input.txt";
    inputFile = fopen(name_file, "r");

    if (inputFile == NULL) {
        printf("Error!\n");
        exit(1);
    }


    return 0;
}
