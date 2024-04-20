#include <iostream>
#include <vector>
#include <algorithm>

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
    int a;
    int b;

public:
    Fraction() {
        a = 0;
        b = 1;
    }

    Fraction(int a1, int b1) {
        if (b1 == 0) {
            a = 0;
            b = 1;
        }
        else {
            int divisor = gcd(a1, b1);
            a = a1 / divisor;
            b = b1 / divisor;
            if (a >= b) {
                a = a % b;
            }
        }
    }

    void print() {
        cout << a << "/" << b << endl;
    }

    friend bool operator==(const Fraction& f1, const Fraction& f2) {
        return f1.a == f2.a && f1.b == f2.b;
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.a * f2.b + f2.a * f1.b, f1.b * f2.b);
    }
};

class SetOfFractions {
    vector<Fraction> fractions;

public:
    bool isEmpty() {
        return fractions.empty();
    }

    void append(Fraction f) {
        if (find(fractions.begin(), fractions.end(), f) == fractions.end()) {
            fractions.push_back(f);
        }
    }

    void exclude(Fraction f) {
        auto it = find(fractions.begin(), fractions.end(), f);
        if (it != fractions.end()) {
            fractions.erase(it);
        }
    }

    Fraction sum() {
        Fraction total;
        for (const Fraction& f : fractions) {
            total = total + f;
        }
        return total;
    }
};


#include "main3_1.cpp"

