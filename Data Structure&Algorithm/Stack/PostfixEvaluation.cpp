#include <iostream>
using namespace std;
#define N 100

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
    int result, opr1, opr2;
    char ch, op1, op2;
    Stack s;

    cout << "Enter your algebraic expression(without space): ";
    getline(cin, input);

    int count = input.size();
    for(int i = 0; i < count; i++){
        ch = input[i];
        if(ch >= '0' && ch <= '9'){
            s.push(ch);
        }

        else{
            op1 = s.stackTop();
            opr1 = op1 - '0';
            s.pop();
            op2 = s.stackTop();
            opr2 = op2 - '0';
            s.pop();

            switch(ch){
                case '%': result = opr2 % opr1;break;
                case '+': result = opr2 + opr1;break;
                case '-': result = opr2 - opr1;break;
                case '*': result = opr2 * opr1;break;
                case '/': result = opr2 / opr1;
            }
        s.push(result + '0');
        }
    }

    cout << "Result = " << s.stackTop() - '0' << endl;
    s.pop();

    system("pause");
    return 0;
}