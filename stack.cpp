#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int data;
	stack *previous;
} *top_of_stack=NULL;

void push(){
	printf("\n\n----------Push Number--------------\n\n");
	int data;
	char end;
	stack *temp;
	do{
		printf("\nEnter number : ");
		scanf("%d",&data);
		
		if(top_of_stack==NULL){
			top_of_stack=new stack;
			
			top_of_stack->data		= data;
			top_of_stack->previous	= NULL;
		}else{
			 temp=top_of_stack;
			 top_of_stack= new stack;
			 
			 top_of_stack->data		= data;
			 top_of_stack->previous	= temp;
		}
		
		printf("\nDo you want to push more number? Enter 'y' or 'n' : ");
		end=getche();
	}while(end!='n');
}
void pop(){
	char end;
	int data;
	printf("\n\n----------Pop Number--------------\n\n");
	if(top_of_stack==NULL) printf("\n\nError: Cannot pop out. Stack is empty.");
	else{
		do{
			if(top_of_stack!=NULL){
				data=top_of_stack->data;
				top_of_stack=top_of_stack->previous;
				printf("\n%d is pop out.",data);	
			}else{
				printf("\nStack is empty now, Cannot pop out more numbers.");
				break;
			}
			if(top_of_stack!=NULL){
				printf("\nDo you want to pop more number? Enter 'y' or 'n' : ");
				end=getche();	
			}
			
		}while(end!='n');
	}

}
//--------display list------------
void display_list(){
	printf("\n\n----------Display Stack--------------\n\n");
	stack *traverse=top_of_stack;
	if(traverse==NULL) printf("\n\nError: Cannot display stack. Stack is empty.");
	else{
		while(traverse!=NULL){
			printf("\n%d",traverse->data);
			traverse=traverse->previous;
		}
	}
}

//--------menu of functions-------
void display_menu(){
	printf("Following operations :\n 1 for display list (stack)\n 2 for Add number (Push)\n 3 for Get number (Pop)\nEnter appropiate number here : ");
}

//---------main-------------------
int main(){
	char end;
	int operation;
	
	do{
		display_menu();
		scanf("%d",&operation);
		
		switch(operation){
			case 1 :
				display_list();
				break;
			case 2 :
				push();
				break;
			case 3 :
				pop();
				break;
			default :
				printf("Error : Wronge number entered.\n");
				break;
		}
		
		printf("\n\nDo you want to end program? Enter 'y' or 'n' : ");
		end=getche();
		printf("\n\n");
	}while(end!='y');
}
