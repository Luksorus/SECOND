	
#include <bits/stdc++.h>

using namespace std;

struct node {
    int KeyMin, KeyMax;
    node *Left;
    node *Right;
};
node *buildTree( int KeyMin, int KeyMax){
    node* root = new node(KeyMin,KeyMax);
    if(KeyMin < KeyMax){
        if (KeyMax - KeyMin > 1) {
            int KeyMid = (KeyMax+KeyMin)/2;
            root -> Left = buildTree(KeyMin,KeyMid);
            root -> Right = buildTree(KeyMid, KeyMax);
        }
        return root;
    }
    else return nullptr;

}

void printTree(node *&root){
    if(root == nullptr){
        return;
    }
    else{
        printTree(root-> Left);
        cout <<"{ "<< root->KeyMin<<", " << root->KeyMax<<"}" <<endl;
        printTree(root -> Right);
    }
}
int searchX(node *&root, int x){
    int  count = 0;
    if (root == nullptr) return 0;
    if (root->KeyMin <= x && root->KeyMax >= x) {
        count++;
    }
    return count + searchX(root->Left,x)+ searchX(root->Right,x);
}

int searchSum(node *&root, int KeyMin, int KeyMax){
    int sum = 0;
    if(root == nullptr && KeyMax - KeyMin <1) return 0;
    if (root->Left !=nullptr || root->Right !=nullptr) return searchSum(root->Left,KeyMin,KeyMax) + searchSum(root->Right,KeyMin,KeyMax);
    if( root->KeyMax <= KeyMax && root->KeyMax > KeyMin) sum+=root->KeyMax;

    return sum;
}



void help(){
    cout << "Commands:" << endl
         << " 1) help" << endl
         << " 2) buildTree" << endl
         << " 3) printTree " << endl
         << " 4) searchSum" << endl
         << " 5) exit " << endl
         ;

}
int main(){
    node *root = new node();
    int KeyMin,KeyMax,x,a,b;
    string command;
    bool flag = false;
    while(flag!=true){
        cin>> command;
        if(command == "searchX") {
            cin>> x;
            cout <<searchX(root,x)<<endl;
        }
        else if(command == "buildTree"){
            cout << "Start and end otrez" <<endl;
            cin>> KeyMin >> KeyMax;
            root = buildTree(KeyMin,KeyMax);
        }
        else if(command == "help") help();
        else if(command == "printTree") printTree(root);
        else if(command == "searchSum"){
            cout << "Start and End"<<endl;
            cin >> a >> b;
            cout<<searchSum(root,a,b) +a <<endl;
        }
        else if(command == "exit") flag = true;
    }
}
