#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class SuperFraction {
private:
    long long a;
    long long b;

public:

    SuperFraction() : a(0), b(1) {}

    SuperFraction(long long a_val, long long b_val) {
        if (b_val == 0) {
            a = 0;
            b = 1;
        } else {
            long long divisor = gcd(abs(a_val), abs(b_val));
            a = static_cast<long long>(ceil(static_cast<double>(a_val) / divisor));
            b = static_cast<long long>(ceil(static_cast<double>(b_val) / divisor));
        }
    }


    void print() const {
        cout << a << "/" << b;
    }


    SuperFraction operator+(const SuperFraction& other) const {
        long long denom = lcm(b, other.b);
        long long num = a * (denom / b) + other.a * (denom / other.b);
        return SuperFraction(num, denom);
    }

private:
  
    long long gcd(long long a, long long b) const {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    
    long long lcm(long long a, long long b) const {
        return (a * b) / gcd(a, b);
    }
};

class SuperExtraMegaWowOfFractions {
private:
     vector<SuperFraction> fractions;

public:
   
    void addFraction(const SuperFraction& fraction) {
        fractions.push_back(fraction);
    }

    void printAll() const {
        for (const auto& fraction : fractions) {
            fraction.print();
            cout << " ";
        }
        cout << std::endl;
    }


    SuperFraction sumAll() const {
        SuperFraction sum;
        for (const auto& fraction : fractions) {
            sum = sum + fraction;
        }
        return sum;
    }
};
#include "main3_4.cpp"
