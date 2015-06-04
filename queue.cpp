#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//----------PCB------------
int no_nodes=0;

struct PCB{
	int queue_id, data;
	PCB *next;
} *front=NULL, *rear = NULL;
void input_data(){
	system("cls");
	printf("Enter data of node '%d' : ",rear->queue_id);
	scanf("%d",&rear->data);
}
void enqueue(){
	system("cls");
	printf("\n\t\t\t----------Enqueue Node--------------\n\n");
	char end;
	PCB *previous;
	do{
		if(front==NULL){
			front	= new PCB;
			rear 	= front;
		}else{
			rear->next = new PCB;
			rear = rear->next;
			
			//previous	= rear;
			//rear = new PCB;
			//previous->next	= rear;
		}
		rear->next=NULL;
		rear->queue_id=++no_nodes;
		input_data();
		printf("\n\n%d nodes are in queue. Do you want to Enqueue more?\nEnter 'y' or 'n' : ",no_nodes);
		end=getche();
	}while(end!='n');
}
void dequeue(){
	printf("\n\t\t\t----------Dequeue Node--------------\n\n");
	char end;
	struct PCB *temp;
	do{
		if(front==NULL){
			printf("\nError: Queue is empty");
			break;
		}else if(front==rear){
			temp=front;
			front=rear=NULL;
		}else{
			temp=front;
			front=front->next;
		}
		if(front!=NULL){
			printf("\n%d is pop out",temp->queue_id);
			printf("\n\nDo you want to out node from queue? Enter 'y' or 'n' : ");
			end=getche();
		}
		no_nodes--;
	}while(end!='n');
}
void display(){
	system("cls");
	printf("\n\t\t\t----------Display Queue--------------\n\n");
	PCB *cursor=front;
	if(front==NULL) printf("\nError : Queue is empty.");
	else {
		do{
			printf("\nNode %d\n Data :\t %d",cursor->queue_id,cursor->data);
			cursor=cursor->next;
		}while(cursor!=NULL);
		
	}
}
void menu(){
	system("cls");
	printf("\t\t\tFollowing are Queue operation\n 1 for Enqueue\n 2 for Dequeue\n 3 for display Queue\n\nEnter appropiate number : ");
}

int main(){
	char end;
	int operation;
	do{
		
		menu();
		scanf("%d",&operation);
		if(operation==1){
			enqueue();
		}else if(operation==2){
			dequeue();
		}else if(operation==3){
			display();
		}else{
			printf("\nError : Entered wronge number ");
		}
		
		printf("\n\nDo you want to end program? Enter 'y' or 'n' : ");
		end=getche();
	}while(end!='y');
}
