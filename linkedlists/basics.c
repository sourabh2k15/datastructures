#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}Node;

//create a newNode of the list style , has a data member and a link member which will contain address to the next member
Node* createNode(int data){
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

//plain vanilla function just prints out the list in this format a->b->c
void printList(Node * root){
  while(root!=NULL){
    if(root->next!=NULL)printf("%d->",root->data);
    else printf("%d\n",root->data);
    root = root->next;
  }
}

// pushes new node onto the start of the list , this requires editing ythe head pointer which is why a pointer to a pointer is used
void push(Node **head,int data){
  Node * newNode = createNode(data);
  newNode->next  = (*head);
  *head = newNode;
}

//returns length of the list
int listlen(Node * root){
  int i=0;
  while(root!=NULL){
    root = root->next;
    i++;
  }
  return i;
}
//prints node data at given key, list given 0 based addressing
void printNode(Node * head,int key){
  while(key--&&head->next!=NULL) head = head->next;
  if(key>0) printf("given key exceeds list length, so spitting last node data :   %d\n",head->data);
  else printf("Node at key is %d\n",head->data);

}

void insertAfter(Node * prevNode,int data){
 Node * newNode = createNode(data);
 if(prevNode==NULL) printf("previous node cannot be null\n");
 else{
   newNode->next = prevNode->next;
   prevNode->next = newNode;
 }
}

void insertAtKey(int key,int data){
  // TODO
  return;
}

void append(Node **head,int data){
 Node * last = (*head);
 Node * newNode = createNode(data);
 if((*head)==NULL){
   (*head) = newNode;
 }else{
   while(last->next!=NULL) last= last->next;
   last->next = newNode;
 }
}

void deleteNode(Node ** head,int key){
 struct node *temp = *head,*prev;

 if(temp!=NULL&&temp->data==key){
   *head = temp->next;
   free(temp);
   return;
 }

 while(temp!=NULL && temp->data!=key){
   prev = temp;
   temp = temp->next;
 }
 if(temp==NULL) return;

 prev->next = temp->next;
 free(temp);
}

void deletenodeKey(Node ** headref,int pos){
  Node * temp = *headref;
  if(pos==0){
   //user wants to delete head
   *headref = (*headref)->next;
   free(temp);
  }else{
    while(pos>1){
      temp = temp->next;
      pos--;
    }
    if(temp==NULL){ printf("position key given is out of list bounds\n"); return;}
    else{
     Node * prev = temp->next;
     temp->next = prev->next;
     free(prev);
    }
  }
}

int main(){
 Node * root = createNode(10);
 Node * first = createNode(9);
 Node * second = createNode(8);

 root->next = first;
 first->next = second;

 push(&root,11);
 printList(root);
 printNode(root,2);
 insertAfter(root,1993);
 append(&root,1992);
 printList(root);
 deleteNode(&root,9);
 printList(root);
 deletenodeKey(&root,8);
 printList(root);
 return 0;
}
