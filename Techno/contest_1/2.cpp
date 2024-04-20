#include "iostream"
#include "cmath"
using namespace std;

class Triangle{
public:
    double a,b,c;
    bool exst_tr(){
        return ((a+b)>c && (a+c)>b && (b+c)>a);
    };

    Triangle(double a1, double b1, double c1){
        a = a1;
        b = b1;
        c = c1;
        if(!exst_tr()){
            a=3;
            b=4;
            c=5;
        }
        
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
#include "main1_2.cpp"
