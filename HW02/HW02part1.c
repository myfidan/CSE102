#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int letter(int x);

int main(){
	
	int student,selection,max,min,index_min,index_max,i;
	double avarage,grades_toplam;
	char letter1,letter2;
	int x=0;
	int y=101;
	grades_toplam=0;
	int A,B,C,D,F;
	A=0;
	B=0;
	C=0;
	D=0;
	F=0;
	for(;;){//infinite loop while users input -1
	printf("Enter Student Count:");
	scanf("%d",&student);
	srand(time(NULL));
	int counter=0;
	if(student>2 && student<51){
	
		for(i=0; i<student; i++){
			counter++;
			max=rand()%100;
			grades_toplam+=max;
			
			if(max>=90){
				A++;
			}
			if(max<90 && max>=80){
				B++;
			}
			if(max<80 && max>=70){
				C++;
			}
			if(max<70 && max>=60){
				D++;
			}
			if(max<60){
				F++;
			}
			if(max>x){
				x=max;//biggest grade
				index_max=i;//index of biggest grade
			}
			if(max<y){
				y=max; //min grade
				index_min=i; //index of smallest grade
			}
			printf("%d ",max);
			
		}
		
		if(x>=90){//numbers of letter grades
			letter1='A';
		}
		if(x<90 && x>=80){
			letter1='B';
		}
		if(x<80 && x>=70){
			letter1='C';
		}
		if(x<70 && x>=60){
			letter1='D';
		}
		if(x<60){
			letter1='F';
		}
		
		if(y>=90){
			letter2='A';
		}
		if(y<90 && y>=80){
			letter2='B';
		}
		if(y<80 && y>=70){
			letter2='C';
		}
		if(y<70 && y>=60){
			letter2='D';
		}
		if(y<60){
			letter2='F';
		}
		
		for(;;){//infinite loop for menu only if users input -1 can exit 
		
		printf("\n------------------------------------\n");
		printf("Student Score Calculator Menu for %d Student\n",student);
		
		printf("\n1) Most Successful Student\n");
		printf("2) Most Unsuccessful Student\n");
		printf("3) Letter Grade Statistics\n");
		printf("4) Calculate Average\n");
		printf("5) Show all Data\n");
		printf("\n             Make Selection : ");
		scanf("%d",&selection);
		
		
		switch(selection){
			
			case 1://most succesful student
				
				printf("\nMost Succesfully student:\n");
				printf("Index: %d\n",index_max+1);
				printf("Score: %d\n",x);
				printf("Letter Grade: %c\n",letter1);
			break;	
				
			case 2://most unsuccesfull student
				
				printf("\nMost Unsuccesfully student:\n");
				printf("Index: %d\n",index_min+1);
				printf("Score: %d\n",y);
				printf("Letter Grade: %c\n",letter2);
			
			break;
			
			case 3://Letter grade students
			
			printf("%d student got letter grade 'A'\n",A);
			printf("%d student got letter grade 'B'\n",B);
			printf("%d student got letter grade 'C'\n",C);
			printf("%d student got letter grade 'D'\n",D);
			printf("%d student got letter grade 'F'\n",F);
			
			break;
			
			case 4://Calculate Average
			
				avarage= grades_toplam/student;
				printf("\nThe avarage Score of %d Student is %.2lf\n",student,avarage);
			break;
		
		
			case 5://Show all data
				printf("\nMost Succesfully student:\n");
				printf("Index: %d\n",index_max+1);
				printf("Score: %d\n",x);
				printf("Letter Grade: %c\n",letter1);
				
				printf("\nMost Unsuccesfully student:\n");
				printf("Index: %d\n",index_min+1);
				printf("Score: %d\n",y);
				printf("Letter Grade: %c\n\n",letter2);
				
			
				printf("%d student got letter grade 'A'\n",A);
				printf("%d student got letter grade 'B'\n",B);
				printf("%d student got letter grade 'C'\n",C);
				printf("%d student got letter grade 'D'\n",D);
				printf("%d student got letter grade 'F'\n",F);
				
				avarage= grades_toplam/student;
				printf("\nThe avarage Score of %d Student is %.2lf\n",student,avarage);
			break;
			
			case -1:  //-1 stop
				return 0;
				
			
			default:
				printf("False Selection!!!\n");
		}
		}

		}
	else{
		//if number of student not in range give user a error message and back to
		//enter student count statemant because of infinite for loop
		printf("Not in range!!!\n");
		
	}
}
	
	return 0;
}




