
#include "header/RBTree.h"
#include "header/avlTree.h"
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

    int n,i,vet[1000000];
                   n=1000000;

    for(i=0; i<n; i++){
        vet[i] = randInt(n);
    }

    AvlTreeInt tree = newBinaryTreeInt();

    t = conometro();

    for(i=0;i<n;i++){
        insertAvlTreeInt(tree,vet[i]);
    }

    t = conometro() - t;
    printf("%ld micro segundos \n",t );
}
