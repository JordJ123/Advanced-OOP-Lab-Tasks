#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constituency.h"

void constructConstituency(struct Constituency * const constituency,
    const char * const name, const int * const neighbours, 
    const int numNeighbours) {

    constituency->name = NULL;
    constituency->neighbours = NULL;
    constituency->numNeighbours = 0;

    constituency->name = malloc(strlen(name) * sizeof(char));
    constituency->neighbours = malloc(numNeighbours * sizeof(int));

    memcpy(constituency->name, name, strlen(name) * sizeof(char));
    memcpy(constituency->neighbours, neighbours, numNeighbours * sizeof(int));
    constituency->numNeighbours = numNeighbours;

}

void destructConstituency(struct Constituency * const constituency) {

    free(constituency->name);
    free(constituency->neighbours);

    constituency->name = NULL;
    constituency->neighbours = NULL;
    constituency->numNeighbours = 0;

}

void printConstituency(struct Constituency * const constituency) {
    printf("%s | %i neighbours | [ ", 
        constituency->name, constituency->numNeighbours);
    int i;
    for (i = 0; i < constituency->numNeighbours; i++) {
        printf("%i ", constituency->neighbours[i]);
    }
    printf("]");
}
