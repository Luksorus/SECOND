#include <bits/stdc++.h>

using namespace std;

class Figure{
public:
    Figure(){}
    virtual double square() =0;

};

class Triangle: public Figure{
private:
    double a,b,c;
public:
    Triangle(double a,double b,double c):a(a),b(b),c(c){}
    virtual double square(){
        return  sqrt(((a + b + c) / 2) * (((a + b + c) / 2) - a) * (((a + b + c) / 2) - b) * (((a + b + c) / 2) - c)) ;
    }
};

class Rectangle: public Figure{
private:
    double a,b;
public:
    Rectangle(double a,double b):a(a),b(b){}
    virtual double square(){
        return  a*b ;
    }
};

class Trapezoid: public Figure{
private:
    double a,b,h;
public:
    Trapezoid(double a,double b,double h):a(a),b(b),h(h){}
    virtual double square(){
        return  ((a+b)*h)/2 ;
    }
};

#include "main2_1.cpp"
