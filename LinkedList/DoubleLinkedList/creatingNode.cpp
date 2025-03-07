#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

void print(Node* &head ){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    return 0;
}
