#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;

    node(int x){
       val = x;
       next = NULL; 
       prev = NULL;
    }

    //node(int x):val(x),next(NULL),prev(NULL){}

};

struct ll{
    node * head;   
    node * tail;
    int sz;
    ll(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void add(int x){
        node * newNode = new node(x);
        sz++;
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;   
        }
    }

    node * find(int x){
        node * temp = head;
        node * result = NULL;
        while(temp != NULL){
            if(temp->val == x){
                result = temp;
                break;
            }
            temp = temp->next;
        }   
        return result;
    }

    void dl(node * n){
        if(n != NULL){
            sz--;
            if(n->prev == NULL && n->next == NULL){
                head = tail = NULL;
            }else if(n->prev != NULL && n->next != NULL){
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }else if(n->prev == NULL && n->next != NULL){
                head = n->next;
                n->next->prev = NULL;
            }else if(n->next == NULL && n->prev != NULL){
                tail = n->prev;
                n->prev->next = NULL;  
            }
            delete n;
        }
    }

    void dl(int x){
        node * temp = find(x);
        dl(temp);
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void print2(){
        node * temp = tail;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    bool isEmpty(){
        return sz == 0;
    }

};


ll * l = new ll();

void test1(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i < n; ++i){
        l->add(a[i]);
    }

    l->print();
    l->dl(3);
    l->print();
    l->dl(4);
    l->print();
    l->dl(5);
    l->print();
    l->dl(1);
    l->print();
    l->dl(7);
    l->print();
    l->dl(10);
    l->print();
    /*
    expected output:
    1 2 3 4 5 6 7 
    1 2 4 5 6 7 
    1 2 5 6 7 
    1 2 6 7 
    2 6 7 
    2 6 
    2 6 
    */
}

void test2(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i < n; ++i){
        l->add(a[i]);
    }

    while(!l->isEmpty()){
        cout << (l->head)->val << endl;
        l->dl(l->head);
    }
}


int main(){

    //test2();
    test1();

    return 0;
}