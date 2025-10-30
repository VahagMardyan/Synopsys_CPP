/* This is code testing environment, nothing special*/
#include <iostream>
#include <cmath>
#include <limits>

template<class T>
void print(T value) {
    std::cout<<value<<std::endl;
}

int global;

int main() {
    const int a = 5;
    int b = 10;
    const int c = a + b;
    constexpr int d = 5;
    constexpr int e = d + 1;
    print(e);
    enum EyeColor {
        Brown, // 0 
        Blue, // 1
        Green, // 2
        Gray, // 3
        Other // 4
    };
    EyeColor myEyeColor = Green;

    double x = 0.0;
    while(true) {
        double val = std::exp(x);
        if( std::isinf(val) ) {
            std::cout<<x<<std::endl; // 710 
            break;
        }
        x+=1.0;
    }
    int local; // 
    print(std::exp(709)); // 8.21841e+307
    print(std::exp(710)); // inf
    print(global); // 0
    print(local); // 32766, 32767, ... -> garbage
    return 0;
}