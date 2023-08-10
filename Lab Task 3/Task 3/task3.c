// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <string.h>

#include "constituency.h"

int main() {

    //Construct
    const int numConstituencies = 5;
    struct Constituency constituencies[numConstituencies];
    constructConstituency(
        &constituencies[0], "Swansea East",
        (unsigned int[]){1, 2, 3, 4}, 4);
    constructConstituency(
        &constituencies[1], "Swansea West",
        (unsigned int[]){0, 2}, 2);
    constructConstituency(
        &constituencies[2], "Gower",
        (unsigned int[]){0, 1, 3}, 3);
    constructConstituency(
        &constituencies[3], "Neath",
        (unsigned int[]){0, 2, 4}, 3);
    constructConstituency(
        &constituencies[4], "Aberavon",
        (unsigned int[]){0 , 3}, 2);

    //Copy
    struct Constituency * copy = copyConstituencies(constituencies,
        numConstituencies);
    int i = 0;
    for(i = 0; i < numConstituencies; i++) {
        destructConstituency(&constituencies[i]);
    }
    

    //Print
    struct Constituency * most = &copy[0];
    struct Constituency * least = &copy[0];
    for (i = 0; i < numConstituencies; i++) {

        printConstituency(&copy[i]);
        printf("\n");
        if (most->numNeighbours < copy[i].numNeighbours) {
            most = &copy[i];
        }
        if (least->numNeighbours > copy[i].numNeighbours) {
            least = &copy[i];
        }
    }
    printf("\n");

    //Most Neighbours
    printf("%s has the most bordering constituencies:\n", most->name);
    for (i = 0; i < most->numNeighbours; i++) {
          char * name = copy[most->neighbours[i]].name;
          printf("%*s\n", 4 + (int) strlen(name), name);
    };
    printf("\n");

    //Least Neighbours
    printf("%s has the least bordering constituencies:\n", least->name);
    for (i = 0; i < least->numNeighbours; i++) {
          char * name = copy[least->neighbours[i]].name;
          printf("%*s\n", 4 + (int) strlen(name), name);
    };

    //Destruct
    for (i = 0; i < numConstituencies; i++) {
        destructConstituency(&copy[i]);
    }

    return 0;
}