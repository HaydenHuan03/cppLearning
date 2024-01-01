#include <iostream>
using namespace std;

// Program-1.1
class Word {
    public:
        string phrase;
        Word* next;
        Word* prev;
        Word(string s) {
            phrase = s;
            next = NULL;
            prev = NULL;
        }
};

int main(int argc, char *argv[]) {

    Word* w1 = new Word("andy");
    Word* w2 = new Word("met");
    Word* w3 = new Word("alice");
    Word* w4 = new Word("yesterday");

    w1->next = w2;
    w2->next = w3;
    w3->next = w4;
    w4->next = w1;

    w1->prev = w4;
    w2->prev = w1;
    w3->prev = w2;
    w4->prev = w3;

    Word* w = w1;
    cout << w->phrase << " ";
    w = w->next;
        while(w != w1)
        {
            cout << w->phrase << " ";
            w = w->next;
        }
    cout << endl;
        
    Word* pw = w4;
    cout << pw->phrase << " ";
    pw = pw->prev;
        while (pw != w4)
        { 
            cout << pw->phrase << " ";
            pw = pw->prev;
        }
        

    system("pause");
    return 0;
}