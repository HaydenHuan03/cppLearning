#include <iostream>
using namespace std;

class nodeStack
{
    int data;

    public:
        nodeStack *next;
        nodeStack(int b){
            data = b;
            next = NULL;
        }

        int getData(){
            return data;
        }
};

class stack
{
    private: // pengisytiharan ahli data
        nodeStack *top;
    public : // pengisytiharan ahli fungsi
        stack(){
            top = NULL;
        }

        bool isEmpty(){
            return top == NULL;
        }

        void push(int b){
            nodeStack *nn = new nodeStack(b);

            if(!isEmpty()){
                nn->next = top;
            }
            top = nn;
        } // insert item into stack
        void pop(){
            if(isEmpty())
                cout << "The stack is empty." << endl;
            else{
                nodeStack *temp = top;
                top = temp->next;
                temp->next = NULL;
                delete temp;
            }
        } // delete item from stack

        int stackTop(){
            return top->getData();
        } // get content at top stack

        void disp(){
            nodeStack *temp = top;

            cout << "Stack: ";
            while(temp){
                cout << temp->getData() << " ";
                temp = temp->next;
            }

            cout << endl;
        }
};

int main(){
    stack s;

    s.pop();
    s.push(10);
    s.disp();
    s.push(5);
    s.disp();
    s.push(81);
    s.disp();
    s.pop();
    s.disp();
    s.pop();
    s.disp();
    s.pop();
    s.disp();
    s.pop();

    system("pause");
    return 0;
}