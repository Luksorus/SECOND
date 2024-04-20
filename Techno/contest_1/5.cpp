#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class MyStack{
public:
    vector<int> a;

    void push(int n){
        a.push_back(n);
    }

    void pop(){
        cout << a.back() << endl;
        a.pop_back();
    }

    void back(){
        cout << a.back() << endl;
    }

    void size(){
        cout << a.size() << endl;
    }
    void clear(){
        a.clear();
    }
};
#include "main1_5.cpp"
