#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    char name[20];
    int age;
    float height;
} Member;

void bubble_sort(Member mems[], int cont);
void swap(Member *x, Member *y);

int main() {
    FILE *inputFile, *outputFile;
    char name_file[] = "input.txt";
    inputFile = fopen(name_file, "r");

    if (inputFile == NULL) {
        printf("Error!\n");
        exit(1);
    }

    Member mems[100];
    int cont = 0;
    // lectura de archivo
    while( fscanf(inputFile, "%d %s %d %f", &mems[cont].num, mems[cont].name,
           &mems[cont].age, &mems[cont].height) != EOF ) {
        cont += 1;
    }
    if( feof(inputFile) ) {
        printf("File processed correctly\n");
        printf("Numero de integrantes procesados %d\n", cont);
    }
    else {
        printf("Error reading the file\n");
        exit(1);
    }
    fclose(inputFile);

    int ans;
    printf("Cuantos integrantes quieres pasar al archivo?\n");
    scanf("%d", &ans);
    while( ans > cont ) {
        printf("Elige maximo %d jugadores", cont);
        printf("Cuantos integrantes quieres pasar al archivo?\n");
        scanf("%d", &ans);
    }
    Member *memsFinal = malloc(sizeof(Member) * ans);
    bubble_sort(mems, cont);
    for(int i=0; i<ans; i++) {
        memsFinal[i] = mems[i];
    }

    // escritura de archivo
    outputFile = fopen("salidad.txt", "w");
    fprintf(outputFile, "Num\tNom\t\tedad\test\n");
    for(int i=0; i<ans; i++) {
        fprintf(outputFile, "%d\t%s\t\t%d\t%.2f\n", memsFinal[i].num,
                memsFinal[i].name, memsFinal[i].age, memsFinal[i].height);
    }
    fclose(outputFile);
    free(memsFinal);

    return 0;
}

void swap(Member *x, Member *y) {
    Member temp = *x;
    *x = *y;
    *y = temp;
}

void
bubble_sort(Member mems[], int cont) {
    int i, j;
    for (i=0; i<cont-1; i++) {
        for (j=0; j<cont-i-1; j++) {
            if (mems[j].height < mems[j+1].height) {
                swap(&mems[j], &mems[j+1]);
            }
        }
    }
}

