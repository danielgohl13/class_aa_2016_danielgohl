#include "sorts.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

long int conometro(){
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec*1e6 + now.tv_usec);
}

unsigned int randInt(unsigned int max){

    static unsigned int currentSeed;
    unsigned int seed = (unsigned) time(NULL);

    if(currentSeed == seed)
        seed += (rand() % seed) * 2;
    else
        currentSeed = seed;
    srand(seed);
    return max <= 0 ? rand() : rand() % (max + 1);
}


int main(int argc, char const *argv[]) {
    long int t;


    int n,i,vet[100];
              n=0;

    for(i=100; i>=n; i--){
        vet[i] = i;
        //printf("%d\n",vet[i] );
    }

    t = conometro();
    intMergeSort(vet-1,n);
    t = conometro() - t;
    printf("%ld micro segundos \n",t );
}
