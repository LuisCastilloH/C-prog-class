#include <stdio.h>
#include <string.h>

#define SIZE_ARR 30

int main() {
    char str[SIZE_ARR];
    int digit_count[10] = {0};
    int i, len;
    printf("Escribe un string (que incluya numeros y letras)\n");
    scanf("%s", str);
    len = strlen(str);

    // check if char is digit
    for (i=0; i<len; i++) {
        if( *(str+i) >= '0' && *(str+i) <= '9' ) {
            /*digit_count[(int) *(str+i) - '0'] += 1; // possible option 1*/
            *(digit_count + (int)*(str+i)-'0') += 1; // possible option 2
        }
    }

    // console output
    for (i=0; i<10; i++) {
        printf("Digito %d: %d veces\n", i, *(digit_count+i));
    }

    return 0;
}

