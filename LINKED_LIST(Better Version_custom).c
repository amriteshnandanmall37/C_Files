#include<stdio.h>
#include<stdlib.h>
//Inserting element at beginning
typedef struct node  //Now 'node' is alias for struct node.
{
   int data;
   struct node *next;

}node;
node *head=NULL;

void insertatbeg(int num)  //Function for inserting element at beginning
{
   if(head==NULL){
   head=(node*)malloc(sizeof(node));
   if(head==NULL){
   printf("Not enough memory");
   exit(1);
   }
   head->data=num;
   head->next=NULL;
   }
   else
   {
     node *newhead=malloc(sizeof(node)); //No need to typecast the void pointer because its implicit
     if(newhead==NULL){
      printf("Not enough memory.");
      exit(1);
     }
     newhead->data=num;
     newhead->next=head;
     head=newhead;
   }
   
}

void search(int search)
{
   node *ptr;
   ptr=head;
   int i=0,flag=0;
   if(ptr==NULL)
   {
      printf("Linked list not created(NO ELEMENTS.)");
      system("pause");
      exit(1);
   }
   while(ptr->data!=search)
   {
      ptr=ptr->next;
      i++;
      if(ptr==NULL){
      flag=1;
         break;
      }
   }
   if(flag==1)
   printf("Element not found.");
   else
   printf("Element %d found at position index: %d\n",search,i);
}

void display()
{
   node *ptr=head;
   while(ptr!=NULL)
   {
      printf("%d->",ptr->data);
      ptr=ptr->next;
   }
   printf("NULL");
}
//Memory freeing function
void memory_free()
{
   node *ptr=head;
   while(ptr!=NULL)
   {
      node *temp=ptr;
      ptr=ptr->next;
      free(temp);
   }
   head=NULL;
}
int main()
{
   int num;
   while(1){  //Creating linked list
      printf("Enter any character other than numbers to end inserting:");
   printf("\nEnter the elements at beginning:\n");
   int flag=scanf("%d",&num);    //scanf returns 0 when doesn't assign any input which can be used here to break loop on completion by user
   if(flag==0)
   break;
   insertatbeg(num);
}
   printf("\n");
   display();
   printf("\nEnter the element to be searched: ");
   int element;
   getchar(); //For clearing input buffer due to scanf in line 91
   scanf("%d",&element);
   search(element);
   memory_free();
   system("pause");
   return 0;

}