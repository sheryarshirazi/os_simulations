#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int no_nodes=0;//storing quantity of nodes.

//------node----
struct node
{
	int data,id;
	struct node *next;
};
struct node *start=NULL,*current_node,*previous_node; //storing starting address of node, here it is null because no node created yet.

//------create node-----
void create_node()
{
	char choice;
	do
	{
		struct node *new_node;
		/* 	- assigning address of new node to 'new_node'.
		   	- (struct node *)malloc(sizeof(struct node)); allocate memory of size 'struct node' dynamically.
		*/
		new_node=(struct node *)malloc(sizeof(struct node));
		no_nodes++;
		
		//getting data for new node from user.
		printf("\nEnter data for node %d (only in int) : ",no_nodes);
		scanf("%d",&new_node->data);
		new_node->id=no_nodes; //assigning id to node using no_nodes.
		
		new_node->next=NULL; //this is end node if no node further created.
		
		/*---case 01----
			- when first node would create.
		*/
		if(start==NULL){
			start=new_node;
			current_node=new_node; // save address of current node because its element 'next' will point to new node i.e case 02.
		}
		/*---case 02---
			- when second or more nodes would create.
		*/
		else{
			previous_node=current_node; // when new node will create current node would become previous.
			current_node=new_node;		
			previous_node->next=new_node; /*	here we are giving address of new node to previous node
											 	using its pointer 'current' i.e previous node pointing new (current) node.
										  */
		}
		printf("\nDo you want to create another ? Enter y or n: ");
		choice=getche();
	}while(choice!='n');
}
void delete_node(){
	struct node *current_node, *previous_node;
	
	char want_delete='n';
	current_node=start; //begin traversing from first node.
	
	while(current_node!=NULL){
		printf("\nnode:\nId=%d and %d",current_node->id,current_node->data);
		printf("\nDo you want to delete node ? enter 'y' or 'n' : ");
		want_delete=getche();
		
		if(want_delete=='y'){
			/*-----case 01------
				- when user want to delete first node.
			*/
			if(current_node==start){
				start=current_node->next; //'start' pointer pointing to second node 'which was next to first node'.
				no_nodes--;
			}
			//removing 'current' between 'previous' and 'next'.
			previous_node->next=current_node->next;
			free(current_node);
			break;
		} 
		previous_node=current_node;
		current_node=previous_node->next;
	}
	
	if(want_delete=='n') printf("\n\nMessage: \"No node deleted.\"");
	else printf("\n\nMessage:\"node deleted.\"");
	
}
//------------------------------------------------------------------

void display_link_list()
{
	//local new node for printing from begining
	struct node *display_pointer=start;
	
	while(display_pointer!=NULL)
	{
		printf("\nNode at '%u' has  id: %d and data :%d.",display_pointer,display_pointer->id,display_pointer->data);
		display_pointer=display_pointer->next;
	}
	printf("\nMessage: \"List is ended.\"");
}
//----------------------------------------------------
void display_menu(){
	printf("Enter number for appropiate operation in linklist\n");
	printf("1 for display list\n");
	printf("2 for create node\n");
	printf("3 for delete node\n");
	printf("Enter here : ");
}
int main(){
	char end='n';
	int op;
	
	do{
		display_menu();
		scanf("%d",&op);
		switch(op){
		
			case 1:
				if(start==NULL){
					printf("\nMessage :\"%d node created yet.\"",no_nodes);
					break;
				}else{
					printf("\n------------Displaying Node------------\n");
					display_link_list();
				}
				break;
			case 2:
				printf("\n------------Node Creation------------\n");
				create_node();
				printf("\nMessage: \"Total %d nodes created yet.\"",no_nodes);
				break;
			case 3:
				
				if(no_nodes==0) printf("\nError: \"Cannot delete nodes because no nodes created yet.\"");
				else{
					printf("\n------------Node Deletion------------\n");
					delete_node();
				} 
				break;
			default:
				printf("Warning: \"Wronge number entered.\"");
		}
		printf("\n\nExit program? Enter y or n : ");
		end=getch();
		printf("\n\n");
	}while(end=='n');
	
	return 0;
}
//----------------------------------------------------
