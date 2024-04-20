#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
public:
    double a,b,c;

    double get_a(){
        return a;
    }

    double get_b(){
        return b;
    }

    double get_c(){
        return c;
    }

    Triangle(double a1, double b1, double c1){
        a = a1, b = b1, c = c1;
        bool check = exst_tr();
        if (!check) a = 3, b = 4, c = 5;
    }

    double perimetr(){
        return a + b + c;
    }

    double square(){
        double HP = (a + b + c) / 2;
        return sqrt(HP * (HP - a) * (HP - b) * (HP - c));
    }

    void show(){ // все хотят от меня шоу
        cout << "A = " << a << ", ";
        cout << "B = " << b << ", ";
        cout << "C = " << c << endl;
    }

    bool is_similar(Triangle &t2){
        return a / t2.a == b/t2.b && b/t2.b == c/t2.c;
    }

    bool exst_tr(){
        int flag = 1;
        if (a <= 0 && b <= 0 && c <= 0){
            flag = 0;
        } else if ((a + b <= c) && (a + c <= b) && (b + c <= a)){
            flag = 0;
        }
        return flag;
    }
};

class Circle{
public:
    float r, x, y;

    Circle(float r1, float x1, float y1){
        r = r1, x = x1, y = y1;
    }

    void set_circle(float r1, float x1, float y1){
        r = r1, x = x1, y = y1;
    }

    float square(){
        return M_PI * pow(r, 2.);
    }

    bool triangle_around(Triangle  &t){
        int flag = 0;
        float a = t.a, b = t.b, c = t.c;
        float s = t.square();
        if (s == ((a * b * c) / (4 * r))) flag = 1;
        return flag;
    }

    bool triangle_in(Triangle &t){
        int flag = 0;
        float ph = t.perimetr() / 2;
        float s = t.square();
        if (r == s / ph) flag = 1;
        return flag;
    }

    bool check_circle(Circle &c){
        int flag = 0;
        float x1 = c.x, y1 = c.y, r1 = c.r;
        float first = (sqrt(pow(x1 - x, 2.) + pow(y1 - y, 2.)));
        if (first < r + r1) flag = 1;
        if (first <= abs(r1 - r)) flag = 0;
        return flag;
    }

};

#include "main1_4.cpp"
