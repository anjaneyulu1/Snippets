#include <bits/stdc++.h> 
using namespace std; 

class Node {
  public:
  
  Node(int _data)
  {
    data = _data;
    next = NULL;
  }
  int data;
  Node* next;
};

Node* insertAtBegin(Node *head, int data)
{
  Node* newHead = new Node(data);
  if(head == NULL) return newHead;
	
  newHead->next = head;
}

Node* insertAtEnd(Node *head, int data)
{
  Node* newHead = new Node(data);
  if(head == NULL) return newHead;
  
  while(head->next)
  {
    head = head->next;
  }
  
  head->next = newHead;
  return newHead;
}

Node* insertAfter(Node* head, int afterNode, int data)
{
  Node* newHead = new Node(data);
  if(head == NULL) return newHead;
  
  while (head)
  {
      if(head->data == afterNode)
      {
        newHead->next = head->next;
        head->next = newHead;
        break;
      }
      head = head->next;
  }
  return newHead;
}

Node* deleteNode(Node* head, int data)
{
    Node* effectHead = head;
  if(head == NULL) return effectHead;
  if(head->data == data)
  {
      effectHead = head->next;
      delete head; return effectHead;
  }
  
  while (head->next)
  {
      if(head->next->data == data)
      {
          Node* del = head->next;
        head->next = head->next->next;
        delete del;
        break;
      }
      head = head->next;
  }
  return effectHead;
}

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout <<node->data << " --> ";
        node = node->next;  
    }  
}  

void cleanMemory(Node* head)
{
    if(head == NULL) return;
 while(head->next)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}
/* Driver code*/
int main() 
{ 
  Node* head = new Node(1);
  head->next = new Node(2);
  insertAtEnd(head, 3);
  insertAtEnd(head, 4);
  insertAtEnd(head, 5);
  insertAtEnd(head, 7);
  
  insertAfter(head, 5, 6);
  head = insertAtBegin(head, 0);
  
  
  printList(head);
  head = deleteNode(head, 5);
  cout << ":: After deleting 5\n";
  printList(head);
  cleanMemory(head);
  return 0; 
}
