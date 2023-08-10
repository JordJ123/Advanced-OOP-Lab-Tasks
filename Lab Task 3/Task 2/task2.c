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

    //Print
    int i;
    struct Constituency * most = &constituencies[0];
    struct Constituency * least = &constituencies[0];
    for (i = 0; i < numConstituencies; i++) {
        printConstituency(&constituencies[i]);
        printf("\n");
        if (most->numNeighbours < constituencies[i].numNeighbours) {
            most = &constituencies[i];
        }
        if (least->numNeighbours > constituencies[i].numNeighbours) {
            least = &constituencies[i];
        }
    }
    printf("\n");

    //Most Neighbours
    printf("%s has the most bordering constituencies:\n", most->name);
    for (i = 0; i < most->numNeighbours; i++) {
          char * name = constituencies[most->neighbours[i]].name;
          printf("%*s\n", 4 + (int) strlen(name), name);
    };
    printf("\n");

    //Least Neighbours
    printf("%s has the least bordering constituencies:\n", least->name);
    for (i = 0; i < least->numNeighbours; i++) {
          char * name = constituencies[least->neighbours[i]].name;
          printf("%*s\n", 4 + (int) strlen(name), name);
    };

    //Destruct
    for (i = 0; i < numConstituencies; i++) {
        destructConstituency(&constituencies[i]);
    }

    return 0;
}