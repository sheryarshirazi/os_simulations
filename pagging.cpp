#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

char logical[12]={'a','b','c','d','e','f','g','h','i','j','k','l'}, physical[16];
int table[4];

int main(){
	int random[4]={2,1,3};
	
	int l,p,x,i,j;
           for(i=0;i<3;i++){
                   l=i*4;
                   p=random[i]*4;
                   
				   for(j=0;j<4;j++){
				   		physical[p++]=logical[l++];
                   }
                   table[i]=random[i];
                   
			}
		   printf("Logical\t\tPhysical\n");
           for(i=0;i<16;i++){
           		if(i<12) printf("%d %c\t\t%d %.3c\n",i,logical[i],i,physical[i]);
           		else printf("\t\t%d %.2c\n",i,physical[i]);
           }
           
          
		   printf("\nTable\n");
		   for(i=0;i<3;i++)
	           printf("%d\t%d\n",i,table[i]);
	       
		   printf("Enter Logical address:");
           scanf("%d",&x);
           
           printf("\nPhysical Address:%d",(table[(x/4)]*4)+(x%4));
           getch();
    }
