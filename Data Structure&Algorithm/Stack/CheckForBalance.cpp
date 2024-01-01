#include <iostream>
#define N 100
using namespace std;

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
    string input;
    Stack s;
    bool cont = true;

    cout << "Enter an expression: ";
    getline(cin, input);
    int count = input.size();
    int i = 0;
    while(i < count){
        char ch = input[i];
        if(ch == '(' || ch == ')'){
            //push opening parentheses
            if(ch == '(')
                s.push(ch);
            //If it is a closing parentheses, check whether it is empty 
            else if(s.isEmpty())
                break;
            //if not empty pop the corresponding opening parentheses from stack
            else
                s.pop();
        }
        i++;
    }

    if((i == count) && s.isEmpty())
        cout << "Balanced." << endl;
    else
        cout << "Not Balanced." << endl;

    system("pause");
    return 0;
}