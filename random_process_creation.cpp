#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <Windows.h>
int id=0;
const int data=14;

int random(){
	srand ( time(NULL) );
	return (rand() % 100);
}
struct PCB{
	int process_id,duration,data;
	PCB *next;
} *front=NULL, *rear = NULL;

void create_process(){
	if(front==NULL){
		front	= new PCB;
		rear 	= front;
	}else{
		rear->next = new PCB;
		rear = rear->next;
	}
	rear->next=NULL;
	rear->process_id = ++id;
	rear->duration	 = random();
	rear->data		 = random()+data;
}
PCB* dequeue(){
	struct PCB *temp;
	if(front==NULL){
		return NULL;
	}else if(front==rear){
		temp=front;
		front=rear=NULL;
	}else{
		temp=front;
		front=front->next;
	}
	return temp;
}
void display(PCB *temp){
	printf("\n\nExecuting process %d",temp->process_id);
		printf(".");
		Sleep(500);
		printf(" .");
		Sleep(500);
		printf(" .");
		Sleep(temp->duration*10);
}
void display_waiting(){
	printf("\nNo Process, Processor is idle.");
	printf(".");
	Sleep(500);
	printf(" .");
	Sleep(500);
	printf(" .");
}
int main(){
	char end;
	int operation;
	PCB *current_process;
	do{
		if(random()%2==0) create_process();
		current_process=dequeue();
		
		if(current_process==NULL){
			display_waiting();
		}	
		else{
			display(current_process);
		}
		//printf("\n\nDo you want to end program? Enter 'y' or 'n' : ");
		//end=getche();
	}while(end!='y');
	return 0;
}

