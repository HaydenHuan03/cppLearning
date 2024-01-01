#include <iostream>
using namespace std ;

class Node{
  int data ;
  
  public:
    Node* next ;
    Node(int _data = 0){data = _data ; next = NULL ; }
    int getData(){return data; }
};

class List{
  Node *head ;
  
  public:
    List(){head = NULL ; }
    bool isEmpty(){return head == NULL ; }
    
    void insert(int d)
    {
      Node *newNode = new Node(d) ;
      if(isEmpty())
      {
          head = newNode ; // newNode will become the head
      }
      
      else
      {
        newNode->next = head ; //break the old head connection
        head = newNode ; // link the new head
      }
    }
    
    void insertEnd(int d)
    {
      Node *temp = head ; 
      Node *newNode = new Node(d) ;
      
      while(temp->next != NULL)
        temp = temp->next ; //locate the last node
        
      temp->next = newNode ;//insert the newNode at last
    }
    
    void dispList()
    {
      Node* temp ;
      
      temp = head ;
      while(temp) //while(temp != NULL)
      {
        cout << temp->getData() << "   " ;
        temp = temp->next ;
      }
      
      cout << endl ;
    }
    
    void deleteFront()
    {
      Node *temp = head ;
      
      if(temp->next != NULL)
      {
        head = temp->next ; //link head to the next node
        temp->next = NULL ; //break original head 'next' pointer
      }
      
      delete temp ;
    }
    
    void deleteEnd()
    {
      Node *temp = head, *delNode ;
      
      while(temp->next != NULL)
      {
        delNode = temp ; //locate the node before the last
        temp = temp->next ; // assign temp to the next  node
      }
      
      delete temp ; // delete last node
      delNode->next = NULL ;
    }

    void insertMiddle(int d, int sKey){
        Node* temp = head;
        Node* newNode = new Node(d);
        bool found = false;

        while(temp->next != NULL){
            if(temp->getData() == sKey){
                found = true;
                break;
            }

            temp = temp->next;
        }

        if (found){
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertIntoThirdNode(int d, int loc){
        int count = 1;
        Node* temp = head;
        Node* thirdNode = new Node(d);

        while(temp->next != NULL && count < loc){
            temp = temp->next;
            count++;
        }

        thirdNode->next = temp->next;
        temp->next = thirdNode;
    }

    void insertMiddle3(int d, int sKey){
        Node* temp = head, *prev;
        Node* newNode = new Node(d);
        bool found = false;

        while(temp->next != NULL){
            if(temp->getData() == sKey){
                found = true;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if (found){
            newNode->next = temp;
            prev->next = newNode;
        }
    }

    void deleteMiddle(int sKey){
        Node *temp = head, *del;
        bool found = false;

        while(temp->next != NULL){
            if(temp->getData()==sKey){
                found = true;
                break;
            }
            temp = temp->next;
            del = temp->next;
        }

        if(found){
            temp->next = del->next;
            delete del;
        }
    }

    void deleteMiddle2(int sKey){
        Node *temp = head, *prev;
        bool found = false;

        while(temp->next != NULL){
            if(temp->next->getData()==sKey){
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if(found){
            prev->next = temp->next;
            delete temp;
        }
    }
};

int main()
{
    List dataList ;
    int num;
    
    dataList.insert(20) ;
    dataList.dispList() ;
    
    cout << "\nInsert from front" << endl ;  
    dataList.insert(10) ;
    dataList.dispList() ;
    
    cout << "\nInsert 2 value from front" << endl ;
    dataList.insert(30) ;
    dataList.insert(50) ;
    dataList.dispList() ;
    
    cout << "\nInsert from end" << endl ;
    dataList.insertEnd(100) ;
    dataList.dispList() ;
    
    cout << "\nDelete from front" << endl ;
    dataList.deleteFront() ;
    dataList.dispList() ;
    
    cout << "\nDelete from end" << endl ;
    dataList.deleteEnd() ;
    dataList.dispList() ;

    cout << "\nInsert after 20" << endl;
    dataList.insertMiddle(99, 20);
    dataList.dispList();

    cout << "\nInsert into third node" << endl;
    dataList.insertIntoThirdNode(5, 3);
    dataList.dispList();

    cout << "\nInsert before 20" << endl;
    dataList.insertMiddle3(11, 20);
    dataList.dispList();

    cout << "\nDelete after 20" << endl;
    dataList.deleteMiddle(20);
    dataList.dispList();

    cout << "\nDelete before 20" << endl;
    dataList.deleteMiddle2(20);
    dataList.dispList();
  
  return 0 ;
  system("pause");
}