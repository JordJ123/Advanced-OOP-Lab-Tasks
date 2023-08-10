#ifndef CONSITUENCY
#define CONSITUENCY

struct Constituency {
    char *name;
    unsigned int *neighbours;
    unsigned int numNeighbours;
};

void constructConstituency(struct Constituency * const constituency,
    const char * const name, const int * const neighbours, 
    const int numNeighbours);

void destructConstituency(struct Constituency * const constituency);

void printConstituency(struct Constituency * const constituency);

#endif