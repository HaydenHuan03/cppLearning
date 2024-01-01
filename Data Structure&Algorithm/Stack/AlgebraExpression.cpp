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

int precedence(char ch){
    switch(ch){
//+- have to less than %
        case '/':
        case '*':
        case '%': return 4;
        case '+':
        case '-': return 2;
        default : return 0;
    }
}

int main(){
    string input;
    Stack s;
    char postfix[N];
    char ch, chpop, op1, op2;
    int result;

    cout << "Enter your algebraic expression: ";
    getline(cin, input);

    int count = input.size();
    s.push('#');
    int j = 0;

    for(int i = 0; i < count; i++){
        ch = input[i];

        if((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z'))
            postfix[j++] = ch;
        if(ch == '(')
            s.push(ch);
        if(ch == ')'){
            ch = s.stackTop();
            s.pop();
            while(ch != '('){
                postfix[j++] = ch;
                ch = s.stackTop();
                s.pop();
            }
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
            while(!s.isEmpty() && (precedence(s.stackTop()) >= precedence(ch))){
                chpop = s.stackTop();
                s.pop();
                postfix[j++] = chpop;
            }
            s.push(ch);
        }
    }

    while(s.stackTop() != '#'){
        ch = s.stackTop();
        s.pop();
        postfix[j++]= ch;
    }

    postfix[j] = '\0';

    cout << "Postfix expression = " << postfix << endl;

    system("pause");
    return 0;
}