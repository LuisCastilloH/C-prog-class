#include <omp.h>
#include <stdio.h>

int main()
{
    printf("Num of threads %d\n", omp_get_num_threads());
    #pragma omp parallel
    {
        printf("Num of threads %d\n", omp_get_num_threads());
        int id = omp_get_thread_num();
        printf("hello(%d) ", id);
        printf("world(%d) \n", id);
    }

    return 0;
}
