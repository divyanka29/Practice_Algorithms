/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as*/ 
#include <iostream>

using namespace std;

  struct Node
  {
     int data;
     struct Node *next;
  };

Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    Node* newNode = new Node{data, NULL};
    if(!head)
    {
        if(position == 0)
        {
            return newNode;
        }
        return NULL;
    }
    if(position ==0)
    {
        newNode->next = head;
        return newNode;
    }
    auto temp = head;
    
    int i =1;
    while(temp->next)
    {
        if(i==position)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp=temp->next;
        i++;
    }
    temp->next= newNode;
    return head;
    
}

Node* Delete(Node *head, int position)
{
  // Complete this method
  cout<< "position to remove : " << position <<"\n";
    if(!head)
    {
        return NULL;
    }
    if(position ==0 )
    {
        head = head->next;
        return head;
    }
    auto temp = head->next;
    auto prev = head;
    int count =1;
    while(temp)
    {
        if(count == position)
        {
            prev->next = temp->next;
            delete(temp);
            return head;
        }
        count++;
        temp=temp->next;
        prev=prev->next;
    }
    return head;
}

void PrintLL(Node * head)
{
    auto temp = head;
    while(temp)
    {
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout <<"NULL\n";
}

void push_back(Node** head, int data)
{
  Node* newNode = new Node{data, NULL};
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  auto temp = *head;
  while(temp->next)
  {
    temp = temp->next;
  }
  temp->next = newNode;

}

int main()
{
  Node * head = new Node{2, NULL};
  push_back(&head, 5);
  push_back(&head, 3);
  push_back(&head, 0);
  cout<< "before insert \n";  
  PrintLL(head);
  head = InsertNth(head, 9, 2);
  cout<< "after insert \n";  
  PrintLL(head);

  return 0;
}
