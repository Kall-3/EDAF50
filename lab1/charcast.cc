#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    unsigned char a = 'a';
    signed char b = (signed char)a;
    signed char * c = &b;
    
    cout << a << " " << b << " " << c << endl;

    return 0;
}
