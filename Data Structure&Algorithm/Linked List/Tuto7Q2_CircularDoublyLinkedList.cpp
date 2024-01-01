#include <iostream>
using namespace std;

class ipadNode{
    string Name;
    int GB;
    float Price;

    public: 
        ipadNode* link;
        ipadNode(string _name, int _gb,  float _price){
            Name = _name;
            GB = _gb;
            Price = _price;
            link = NULL;
        }

        void displayInfo(){
            cout << Name << " ,RM " << Price << " , " << GB << " GB" << endl;
        }
};

class List{
    ipadNode *head;

    public:
        List(){
            head = NULL;
        }

        void insert(ipadNode *m){
            if(head == NULL)
                head = m;
            else{
                m->link = head;
                head = m;
            }
        }

        void disp(){
            ipadNode* temp = head;
            while(temp){
                temp->displayInfo();
                temp = temp->link;
            }
        }
};

int main(){
    List list;
    list.insert(new ipadNode("iPad1", 1379, 16));
    list.insert(new ipadNode("iPad2", 1679, 32));
    list.insert(new ipadNode("iPad3", 1979, 64));
    list.disp();
}