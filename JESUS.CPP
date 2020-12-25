#include <iostream>

using namespace std;
class Node
{public:
    int data;
    Node * prev;
    Node * next;
};
typedef Node node;
void swapPointer(Node **a, Node**b);
int getSize(Node* node);
node*addSameSize(Node * head1,Node*head2,int *carry);
void addCarryToRemaining(Node*head1, Node*cur,int * carry,Node** result);
void addList(Node* head1,Node*head2,Node**result)
void push1(Node**head_ref,int new_data);

/* Function to insert a node at the
beginging of the Doubly Linked List */
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node();
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = (*head_ref);     
    if((*head_ref) != NULL) 
    (*head_ref)->prev = new_node ; 
 
    (*head_ref) = new_node; 
} 
 
/* Function to print nodes in a given doubly linked list 
This function is same as printList() of singly linked list */
void printList(Node *node) 
{ 
    while(node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
int len(Node **ptr)
{
    int len=0;
    while(*ptr!=NULL)
    {
        *ptr=(*ptr)->next;len++;
    }return len;
}
Node* multiply(Node ** head,Node ** head1,Node** result)
{

Node* tail,*tail1;
tail=*head;
tail1=*head1;
while(tail->next!=NULL) tail=tail->next;
while(tail1->next!=NULL) tail1=tail1->next;
int ln = len(head);
int len1=len(head1);
//printf("%d %d",ln,len(head));
//printf("%d %d",tail->data,tail1->data);
int array[len1][ln+len1-1]={0}; for(int i=0;i<len1;i++) for(int j=0;j<ln+len1-1;j++) array[i][j]=0;
//printf("%d",array[2][1]);
Node*tl1=tail1;
for(int i=0;i<len1;i++)
{
    Node*tal=tail;
    int carry=0,j=0;
    while(tal!=NULL)
    {
        //printf("%d*%d=%d",tal->data,tl1->data,tal->data*tl1->data);
        int num=tal->data*tl1->data+carry;
        carry=num/10;
        array[i][i+j]=num%10;
        tal=tal->prev;
        j++;
    }printf("\n");
    tl1=tl1->prev;
}

/**for(int i=0;i<len1;i++,printf("\n"))
for(int j=0;j<=ln+len1-2;j++)
printf("%d ",array[i][j]);**/
int carry=0;int reslt[ln+len1-1];
Node * rslt=NULL;
for(int i=0;i<=ln+len1-1;i++)
{   int num=carry;
    for(int j=0;j<len1;j++)
    {num+=array[j][i];
    //printf("\t%d",array[j][i]);
    }//cout<<endl;
    reslt[i]=num%10;
    //printf("%d",reslt[i]);
    //push(&rslt,num%10);
    carry=num/10;
    //printf("%d+",num%10);
}
for(int i=ln+len1-1;i>=0;i--)
printf("%d",reslt[i]);
printList(rslt); 
printf("OK!");
return rslt;
}

int main()
{
    Node * head=NULL;
    push(&head,5);
    push(&head,1);
    push(&head,1);
    
    Node* head1=NULL;
    push(&head1,0);
    push(&head1,1);
    push(&head1,1);
    printList(head);cout<<endl;
    printList(head1);
    //printList(head);
    Node * result =NULL;
    multiply(&head,&head1,&result);
}

node*addSameSize(Node* head1,Node*head2,int * carry)
{
    if(head1==NULL) return NULL;
    
    int sum;
    Node * Result = new Node[(sizeof(Node))];
    result->next = addSameSize(head1>next,head2->next,carry)
    sum=head1->data + head2->data + *carry;
    *cfarry=sum/10;
    sum=sum%10;
    
    result->data = sum;//a

    return result;    
    
    
    
    
    
    
    
}

void addCarryToRemaining(Node* head1, Node *cur,int * carry,Node** result)
{
    int sum;
    
    if(head1!=cur)
    {addCarryToRemaining(head1->next, cur,carry,result);
    sum=head1->data + *carry;
    *carry=sum/10;
    sum=sum%10;
    push1(result,sum);
    }
    
    
    
    
}

void addList(Node* head1,Node*head2,Node**result)
{
    Node*cur;
    
    if(head1==NULL)
    {
        *result=head2; return;
    }
    else if(head2==NULL)
    {
        *result=head1; return;
    }
    int size1=getSize(head1);
    int size2=getSize(head2);
    int carry=0;
    if(sixe1==size2)
    *result = addSaneSize(head1,head2,&carry);
    
    else{
        int diff = abs(size1 - size2);
        if(size1<size2)
        swapPointer(&head1,&head2);
        
        for(cur=head1;dif--;cur=cur->next);
        *result=addSameSize(cur,,head2,&carry);
        addCarryToRemaining(head1,cur,&carry,result);
        
    }
    if(carry)
    push1(result,carry);
}

int getSize(Node*node)
{
    int size==0;
    while(node!=NULL)
    {
        node=node->nexr;
        size++;
    }
    return size;
}


void swapPointer(Node **a,Node **b)
{
    Node*t=*a;
    *a=*b;
    *b=t;
}
//F
void push1(Node**head_ref,int new_data)
{
    Node * new_node=new Node[(sizeof(Node))];
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
