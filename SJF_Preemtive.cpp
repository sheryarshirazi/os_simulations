//--------------------------------------------------------------------SJF non preemtive-----------------------------------------
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <ctime> 
#include <dos.h>
using namespace std;

//--------------global scope---------
int processes,time_period=0,id=0;
float Avg_TA=0,Avg_Wait=0;
bool cont=true;

//--------------random number---------
int random(){
	int max=4,min=1;
	int range=(max-min)+1;
	return ( min+int(range*rand()/(RAND_MAX + 1.0)) );
}

//--------------PCB---------
struct PCB{
	int process_id,burst,wait,turn_around,arrival_time,surf_time;
	PCB *next;
}*front=NULL, *rear = NULL;

//--------------Enqueue---------
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
	rear->surf_time		= val;
	printf("\n\nProcess %d created, has AT: %d and Burst : %d",rear->process_id,rear->arrival_time,rear->surf_time);
}
//--------------Dequeue---------
void dequeue(){
	struct PCB *temp;
	int empty=0;
	
	if(front->next==NULL){
			cont=false;
	}
	if(front==NULL){
		empty=1;
	
	}else if(front->next==NULL){ //'front==rear' didnt suitable in this case
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
		printf("\n\nProcess %d executed completely, its Wait: %d and TA: %d",temp->process_id,temp->wait,temp->turn_around);
	}
}
//--------------Place---------
//Place process of lowest burst at front of queue
void place(){
	struct PCB *curr,*prev,*low,*back_low;
	if(front!=NULL){
		back_low = front;
		prev	 = front;
		curr 	 = front;
		low 	 = front;
		
		do{
			//printf("\nid :  %d  burst : %d ",curr->process_id,curr->burst);
			if( curr->burst < low->burst ){
				low=curr;
				back_low=prev;
			}
			prev=curr;
			curr=curr->next;
		}while(curr!=NULL);
		//printf("\n\nProcess %d has lowest burst (%d) : ",low->process_id,low->burst);
		
		if(low!=front){// place in front if it is not in front
			back_low->next	= low->next;
			low->next		= front;
			front			= low;
		}
		
	}
}

//-------------- display--------------
void display(){
	printf("\n\t\t\tDisplay Queue\n\n");
	PCB *cursor=front;
	if(front==NULL) printf("\nError : Queue is empty.");
	else {
		do{
			printf("\nId : \t %d \t burst :  %d \t Add : %d \t Next :\t %d",cursor->process_id,cursor->burst,cursor,cursor->next);
			cursor=cursor->next;
		}while(cursor!=NULL);
		
	}
}

//--------------Execution---------
void surf(){
	if(front!=NULL){
		display();
		place();
		display();
		if(front->burst>0){
			front->burst--;
		}else{
			dequeue();
			time_period--; // neglecting realistic situation
		}
	}
	time_period++;
	
}
//--------------Display AWT and TA---------
void display_chart(){
	printf("\n\n\nAverage Waiting Time is \t: \t %.3f\nAverage Turn Around Time is \t: \t %.3f ",Avg_Wait/id,Avg_TA/id);
}
//--------------Main---------
int main(){
	srand((unsigned)time(0));
	char end;
	int i;
	do{
		printf("\nEnter number of processes you want to create for thier 'AWT' : ");
		scanf("%d",&processes);
		if(processes<1){
			printf("Can not create processes.");
		}else{
			//reseting if user run program again
				id=time_period=Avg_TA=Avg_Wait=0;
				cont=true;
				
			for(i=0;cont;i++){ //// continue the program until given number of processes excute completely
				int val=random();
				if(val%2==0 && val<10 && id< processes){// create randomly with burst less than 10 and create processes how the user wants
					enqueue(val);
				}
				surf();
			}
			display_chart();
	
		}
		printf("\n\nDo you want to end program? Enter 'y' or 'n' : ");
		end=getche();
		system("cls");
	}while(end!='y');
	return 0;
}
