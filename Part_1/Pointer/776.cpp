#include <iostream>

using namespace std;


int main() {

    // int* p = malloc(sizeof(int) * 100); -> only works with C compiler
    int* p = (int*)malloc(sizeof(int) * 100);
    free(p);
    p = NULL;

    return 0;
}