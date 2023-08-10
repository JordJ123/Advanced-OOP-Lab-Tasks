#ifndef CONSITUENCY
#define CONSITUENCY

//#pragma Pack(1)
//If specificed, sets the byte size of a variable to a multiple of n (1 in this case)
//If not specificed, the size is a multiple of the word size with padding added if need
//Saves memory but reduces performance so not worth it as small amount of memory is used anyway
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