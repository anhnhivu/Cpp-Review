#include <iostream>

using namespace std;

void swap(int* p1, int* p2) {
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    return;
}

int main() {

    int a;
    int b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    swap(&a, &b);
    
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";

    return 0;
}