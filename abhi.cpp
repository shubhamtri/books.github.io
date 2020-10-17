#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
int data;
Node * next;
};

Node *head=NULL;

void creatLinkList(){
  cout<<"Enter The Data You Want to enter in the LinkedList"<<"\n";
  Node* newNode=new Node();
  Node* temp=new Node();
  cin>>newNode->data;
  if(head==NULL){
    head=newNode;
  }else{
    temp = head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
  }
}

void display(){
    Node *temp=new Node();
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void reversePrint(Node * head) {

if(head==NULL){
    return;
}
reversePrint(head->next);
cout<<head->data<<"\n";
}


Node* reversingList(Node * head){
if(head==NULL){
return head;
}
Node* temp=head;
Node* prev=NULL;
Node* next=NULL;
while(temp!=NULL){
next=temp->next;
temp->next=prev;
prev=temp;
temp=next;
}
head=prev;
return head;
}

int main(){
  int choice=1;
  while(choice!=5){
    cout<<"Enter Your Choice \n";
    cout<<"1. Enter Data in a Linked List \n";
    cout<<"2. Display Data in Linked List \n";
    cout<<"3. Display Data in reverse of Linked List \n";
    cout<<"4. reversing of Linked List \n";
    cout<<"5. press 5 to quit \n";
    cin>>choice;
    switch (choice)
    {
    case 1:
      creatLinkList();
      break;
    case 2:
      display();
      break;
      case 3:
        reversePrint(head);
      break;
      case 4:
	head=reversingList(head);
      break;
      case 5:
      break;
    default:
    cout<<"invalid choice";
      break;
    }
  }
  display();
  return 0;
}
