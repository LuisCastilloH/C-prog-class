#include <omp.h>
#include <stdio.h>

void pooh(int id, double A[])
{
    printf("..%d\n", id);
}

int main()
{
    double A[1000];
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        pooh(id, A);
    }
    printf("All done!\n");

    return 0;
}
