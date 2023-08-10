#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constituency.h"

void constructConstituency(struct Constituency * const constituency,
    const char * const name, const unsigned int * const neighbours, 
    const unsigned int numNeighbours) {

    constituency->name = NULL;
    constituency->neighbours = NULL;
    constituency->numNeighbours = 0;

    constituency->name = malloc(strlen(name) * sizeof(char));
    constituency->neighbours = malloc(numNeighbours * sizeof(unsigned int));

    memcpy(constituency->name, name, strlen(name) * sizeof(char));
    memcpy(constituency->neighbours, neighbours, numNeighbours * sizeof(unsigned int));
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

struct Constituency * copyConstituencies(struct Constituency * const constituencies, 
    const unsigned int numConstituencies) {

    struct Constituency * newConstituencies = (struct Constituency *) 
        malloc(sizeof(struct Constituency) * numConstituencies);

    constructConstituency(
        &newConstituencies[0], constituencies[0].name,
        constituencies[0].neighbours, constituencies[0].numNeighbours);
    constructConstituency(
        &newConstituencies[1], constituencies[1].name,
        constituencies[1].neighbours, constituencies[1].numNeighbours);
    constructConstituency(
        &newConstituencies[2], constituencies[2].name,
        constituencies[2].neighbours, constituencies[2].numNeighbours);
    constructConstituency(
        &newConstituencies[3], constituencies[3].name,
        constituencies[3].neighbours, constituencies[3].numNeighbours);
    constructConstituency(
        &newConstituencies[4], constituencies[4].name,
        constituencies[4].neighbours, constituencies[4].numNeighbours);

    return newConstituencies;

}
