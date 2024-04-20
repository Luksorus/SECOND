#include "iostream"
#include "cmath"
using namespace std;

class Triangle{
public:
    double a,b,c;
    bool exst_tr(){
        return ((a+b)>c && (a+c)>b && (b+c)>a);
    };


    void set(double a,double b,double c) {
        Triangle::a = a;
        Triangle::b = b;
        Triangle::c = c;
    }



    void show(){
        cout <<"A = "<< a <<","<<" B = "<< b<<","<<" C = " << c  << endl;
    };
    double perimetr(){
        return a+b+c;
    };
    double square(){
        double pp =(a+b+c)/2;
        return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
    };
};
#include "main1_1.cpp"
