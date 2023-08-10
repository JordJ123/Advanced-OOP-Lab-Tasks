#include "arrays.h"

double mean(int length, int *arr) {
    double mean = 0;
    int i;
    for (i = 0; i < length; i++) {
        mean += arr[i];
    }
    return mean / length;
}