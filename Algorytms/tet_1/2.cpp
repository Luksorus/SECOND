#include <bits/stdc++.h>

using namespace std;
struct node{
    node *left;
    node *right;
    string data;
    vector<string>count;
    node(string value,string data_nomer):left(nullptr),right(nullptr),data(value){count.push_back(data_nomer);}
};


node* searchn(node*&t, string key){
    if(t ==nullptr ){
        return nullptr;
    }
    if( (t -> data) == key){
       return t;
    }
    else{
       return searchn((t-> data > key)? t->left: t->right,key);
    }

}

node * insert(node*& root, string data_chel, string data_nomer){
    if (root == nullptr) root = new node(data_chel,data_nomer);
    else if( (root -> data) > data_chel){
        if( root -> left == nullptr){
            root -> left = new node(data_chel,data_nomer);
        }
        else{
            insert(root ->left, data_chel,data_nomer);
        }
    }else if( root -> data < data_chel){
        if( root -> right == nullptr){
            root -> right = new node(data_chel,data_nomer);
        }
        else{
            insert(root ->right, data_chel,data_nomer);
        }
    }
    else root ->count.push_back(data_nomer);

    return root;
}

void printnode(node*& root){
    if(root == nullptr){
        return;
    }
    else{
        printnode(root-> left);
        cout << root->data << ":" <<endl;
        for (vector<string>::const_iterator number = root->count.begin(); number != root->count.end(); number++)
            cout << number-root->count.begin() +1<< ") " << *number<<endl;
        printnode(root -> right);
    }
}


node *getMax(node *&n) {
    if (n == nullptr) return nullptr;
    if (n->right == nullptr) return n;
    return getMax(n->right);
}

node *deleteNode(node *&n, string data_chel) {
    if (n == nullptr) return nullptr;
    else if (n->data > data_chel) n->left = deleteNode(n->left, data_chel);
    else if (n->data < data_chel) n->right = deleteNode(n->right, data_chel);
    else {
        if (n->left == nullptr || n->right == nullptr)
            n = (n->left == nullptr) ? n->right : n->left;
        else {
            node *maxLeft = getMax(n->left);
            n->data = maxLeft->data;
            n->left = deleteNode(n->left, maxLeft->data);
        }
    }

    return n;
}
void help(){
    cout << "Commands:" << endl
         << " 1) help" << endl
         << " 2) add" << endl
         << " 3) delchel " << endl
         << " 4) delnomer " << endl
         << " 5) search " << endl
         << " 6) list " << endl
         << " 7) exit" << endl;
}

void search(node*n){
    string data_chel;
    cout<<"Chel"<<endl;
    cin>> data_chel;
    node*ns= searchn(n,data_chel);
    if(ns == nullptr){
        cout<<"net chela"<<endl;
        return;
    }
    for (vector<string>::const_iterator number = ns->count.begin(); number != ns->count.end(); number++){
        cout << number-ns->count.begin() +1<< ") " << *number<<endl;}
}
void delete_nomer(node*n){
    string data_chel,data_nomer;
    cout<<"Chel,nomer"<<endl;
    cin>> data_chel>>data_nomer;
    node*ns= searchn(n,data_chel);
    if(ns == nullptr){
        cout<<"net chela"<<endl;
        return;
    }
    vector<string>::iterator position = find(n->count.begin(), n->count.end(), data_nomer);
    if (position == n->count.end()) {
        cout << "Net nomer" << endl;
        return;
    }
    n->count.erase(position);
    cout<< "Succsesful"<< endl;
}
void add(node*&n){
    string data_chel,data_nomer;
    cout<<"Chel,nomer"<<endl;
    cin>> data_chel>>data_nomer;

    n=insert(n,data_chel,data_nomer);
    cout<< "Succsesful"<< endl;
}

void delete_chel(node*&n){
    string data_chel;
    cout<<"Chel"<<endl;
    cin>> data_chel;
    n=deleteNode(n,data_chel);
    cout<< "Succsesful"<< endl;
}






int main() {
    node *n = nullptr;
    bool flag = false;
    string command;

    while(!flag == true){
        cin>>command;
        if(command == "help") help();
        else if(command == "add") add(n);
        else if(command == "delchel")delete_chel(n);
        else if(command == "delnomer") delete_nomer(n);
        else if(command == "search") search(n);
        else if(command == "list") printnode(n);
        else if(command == "exit") flag= true;

    }
    cout<< "Succsesful"<< endl;
}
