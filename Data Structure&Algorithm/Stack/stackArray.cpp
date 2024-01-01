#include <iostream>
using namespace std;
#define N 5

class Stack
{
    private : // data declaration
        int top ;
        char data[N] ;
    public : // function declaration
        Stack(){
            top = -1;
        }

        bool isFull(){
            return top == 4;
        } // check if stack is Full

        bool isEmpty(){
            return top == -1;
        }// check if stack is empty

        void push(char d){
            if(isFull()){
                cout << "The stack is full" << endl;
            }
            else{
                top++;
                data[top] = d;
            }
        } // insert operation

        void pop(){
            if(isEmpty()){
                cout << "The stack is empty" << endl;
            }
            else{
                top--;
            }
        } // delete operation

        char stackTop(){
            return data[top];
        } // get top value

        void disp(){
            cout << "Stack: ";
            for(int i = top; i >= 0; i--){
                cout << data[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Stack s;

    s.pop();
    s.push('A');
    s.disp();
    s.push('C');
    s.disp();
    s.push('D');
    s.disp();
    s.push('E');
    s.disp();
    s.push('F');
    s.disp();
    s.push('G');
    s.pop();
    s.disp();
    s.pop();
    s.disp();

    system("pause");
    return 0;
}