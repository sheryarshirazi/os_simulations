#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <ctime> 
#include <dos.h>
using namespace std;

int processes,time_period=0,id=0;
float Avg_TA=0,Avg_Wait=0;
bool cont=true;

int random(){
	int max=8,min=1;
	int range=(max-min)+1;
	return ( min+int(range*rand()/(RAND_MAX + 1.0)) );
}


struct PCB{
	int process_id,burst,wait,turn_around,arrival_time,surf_time;
	PCB *next;
}*front=NULL, *rear = NULL;

void enqueue(int val){
	if(front==NULL){
		front=new PCB;
		rear =front;
	}else{
		rear->next=new PCB;
		rear=rear->next;
	}
	rear->next=NULL;
	rear->process_id	= ++id;
	rear->arrival_time	= time_period;
	rear->burst			= val;
	rear->surf_time		=val;
	
}

void dequeue(){
	struct PCB *temp;
	int empty=0;
	
	if(front->process_id==processes){
			cont=false;
	}
	if(front==NULL){
		empty=1;
	
	}else if(front==rear){
		temp=front;
		front=rear=NULL;
	}else{
		temp=front;
		front=front->next;
	}
	if(empty!=1){
		temp->wait	= (time_period) - (temp->arrival_time)-(temp->surf_time);
		temp->turn_around = (temp->wait) + (temp->surf_time);
		
		Avg_TA = Avg_TA + (temp->turn_around);
		Avg_Wait = Avg_Wait + (temp->wait);
		printf("\nid: %d \tAT: %d \tBurst: %d \tWait: %d \tTA: %d",temp->process_id,temp->arrival_time,temp->surf_time,temp->wait,temp->turn_around);
	}
}
void surf(){
	if(front!=NULL){
		if(front->burst>0){
			front->burst--;
			
			
		}else{
			dequeue();
			time_period--; // neglecting realistic situation
		}
	}
	time_period++;
}

void display(){
		printf("\n\nAverage Waiting Time is : %.3f\nAverage Turn Around Time is : %.3f ",Avg_Wait/id,Avg_TA/id);
}

int main(){
	srand((unsigned)time(0));
	char end;
	int i;
	do{
		printf("\nEnter number of processes you want to create for thier 'AWT' : ");
		scanf("%d",&processes);
		
		//reseting if user run program again
			id=time_period=0;
			cont=true; 
			
		while(cont){ // continue the program until given number of processes excute completely.
			int val=random();
			if(val%2==0 && val<10 && id< processes){// create randomly with burst less than 10 and create processes how the user wants
				enqueue(val);
			}
			surf();
		}
		
		display();
		printf("\n\nDo you want to end program? Enter 'y' or 'n' : ");
		end=getche();
	}while(end!='y');
	return 0;
}

/*
Algo
create process()
	id sequentially;
	burst time randomly;
	waiting time;
	turn around;
	
main()
	time_period
	while time_period>0
		create_process(time_period) randomly;
		execute_burst();
		

*/
