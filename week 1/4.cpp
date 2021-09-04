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
};

struct st{
    private:
        node * tail;
    
    public:
    st(){
        tail = NULL;
    }

    int top(){
        if(tail != NULL){
            return tail->val;
        }
        return -1;
    }

    void push(int x){
       node * item = new node(x);
       if(tail == NULL){
           tail = item;
       }else{
            tail->next = item;
            item->prev = tail;
            tail = item;
       }
    }

    void pop(){
        if(tail != NULL){
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
        }
    }

    bool empty(){
        return tail == NULL;
    }

};


int main(){

    int d[] = {1, 10, 2, 3, 5, 4};
    int n = sizeof(d) / sizeof(int);

    st  * s = new st;

    for(int i = 0; i < n; ++i){
        s->push(d[i]);
    }

    while(!s->empty()){
        cout << s->top() << endl;
        s->pop();
    }

    return 0;
}