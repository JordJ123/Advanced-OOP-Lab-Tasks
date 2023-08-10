#ifndef CONSITUENCY
#define CONSITUENCY

struct Constituency {
    char *name;
    unsigned int *neighbours;
    unsigned int numNeighbours;
};

void constructConstituency(struct Constituency * const constituency,
    const char * const name, const unsigned int * const neighbours, 
    const unsigned int numNeighbours);

void destructConstituency(struct Constituency * const constituency);

void printConstituency(struct Constituency * const constituency);

struct Constituency * copyConstituencies(struct Constituency * const constituencies, 
    const unsigned int numConstituencies);

#endif