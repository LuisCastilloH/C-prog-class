/*
 * @author Luis Castillo
 *
 * ADD copyright...
 *
 * Asks the user 5 fractions (num and den). The data is retrieved from the 
 * STDIN. There are different operations available while running the program.
 *
 * OPTIONS:
 *      -h                  Shows program usage
 *      -v                  Verbose mode (more information during execution)
 *      -n <your_name>      To say hi
 *      You can add more here...
 *
 */
#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    int opt;
    int verbose = 0;

    while ((opt = getopt(argc, argv, "hn:v")) != EOF) { //EOF is -1
        switch(opt) {
            case 'h':
                usage(basename(argv[0]), opt);
                break;
            case 'n':
                printf("Welcome to the fraction program %s\n", optarg);
                break;
            case 'v':
                verbose = 1;
                break;
            default:
                break;
        }
    }
    // call main function of the program --> fracc
    fracc(verbose);
    if (verbose) printf("Program terminated with SUCESS\n");
    return 0;
}

