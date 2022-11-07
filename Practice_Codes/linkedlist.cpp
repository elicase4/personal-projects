#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
  public: 
    int data;
    Node* link;
};

class LinkedList{
  public:
    LinkedList(){
      Node* head;
      head = NULL;
    }

    ~LinkedList(){
      Node* temp = head;
      while (temp != NULL){
        Node* temp_2 = temp;
        temp = temp->link;
        delete temp_2;
      }
    }

    void append(int value){
      if (head == NULL) {
        head = new Node();
        head->data = value;
      } else {
        Node* next = new Node();
        Node* temp = head;
        Node* store = NULL;
        while(temp != NULL){
          store = temp;
          temp = temp->link;
        }
        store->link = next;
        next->data = value;
      }
    }

   Node* find_prev(Node* head, int position){
     int count = 0;
     Node* search = head;
     while (count < (position-1) && search != NULL){
       search = search->link;
       count++;
     }
     return search;
   }

   void insert(int value, int position){
      if (head == NULL){
        if (position == 0){
          head = new Node();
          head->data = value;
        } else{
          cout << "The requested position is invalid, as the linked list must be initialized with position 0." << endl;
        }
      } else if (position == 0){
          Node* next = new Node();
          next->data = value;
          next->link = head;
          head = next;
      } else {
          Node* prev = find_prev(head, position);
          if (prev == NULL){
            cout << "The requested position is invalid, as it is out of bounds for the linked list." << endl;
          } else{
            Node* next = new Node();
            next->data = value;
            next->link = prev->link;
            prev->link = next;
          }
      }
    }

    void remove(int position){
      Node* prev = find_prev(head, position);
      if (prev == NULL || prev->link == NULL){
        cout << "The requested position is invalid, as it is out of bounds for the linked list." << endl;
      } else{
        Node* temp = prev->link;
        if (prev->link != NULL){
          prev->link = temp->link;
        } else{
          prev->link = NULL;
        }
        delete temp;
      }
    }

    void print(){
      Node* temp = head;
      int counter = 0;
      cout << "---------------------------" << endl;
      while (temp != NULL){
        printf("(value,position) = (%d,%d)\n", temp->data, counter);
        temp = temp->link;
        counter++;
      }
      cout << "---------------------------" << endl;
    }

  private:
    Node* head;
};

int main(void){
  LinkedList A;
  A.insert(2, 0);
  A.insert(4, 0);
  A.insert(17, 1);
  A.append(11);
  A.insert(8, 1);
  A.print();
  A.remove(1);
  A.print();
  A.append(12);
  A.print();
  A.remove(4);
  A.print();
  A.remove(4);
  A.remove(4);
  A.print();

  return 0;
}
