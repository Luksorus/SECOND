#include "iostream"
#include "cmath"
using namespace std;

class Triangle{
public:
    double a,b,c;
    Triangle(double a, double b, double c) {
        if (!exst_tr(a, b, c)) {
            this->a = 3;
            this->b = 4;
            this->c = 5;
            throw WrongTriangleSideException();
        } else {
            this->a = a;
            this->b = b;
            this->c = c;
        }
    }

    bool exst_tr(double a, double b, double c){
        return ((a+b)>c && (a+c)>b && (b+c)>a);
    };


    



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
class WrongTriangleSideException {};
};
#include "main4_1.cpp"
