#include <iostream>
#include <vector>
using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator; 
    int denominator; 

public:
    
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) {
        if (denom == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            int divisor = gcd(num, denom);
            numerator = num / divisor;
            denominator = denom / divisor;
            if (numerator >= denominator) {
                numerator %= denominator;
            }
        }
    }


    void print() {
        cout << numerator << "/" << denominator;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
};


template<typename T>
T superSum(const T& arg1, const T& arg2) {
    return arg1 + arg2;
}

template<typename T, size_t N>
T superSum(const T (&arr)[N]) {
    T sum = T();
    for (size_t i = 0; i < N; ++i) {
        sum = sum + arr[i];
    }
    return sum;
}


template<typename T>
T superSum(const vector<T>& vec) {
    T sum = T();
    for (const auto& elem : vec) {
        sum = sum + elem;
    }
    return sum;
}

#include "main3_3.cpp"
