#include<stdio.h>

int main(){
	
	int number,counter,i,j;
	int temp,temp2;
	printf("Enter a number(23-98760) :");
	scanf("%d",&number);
	
	if(number<23 || number>98760){
		//if our number not in range of 23 and 98760 program gives us a error message
		printf("Error\nPlease Enter a Number Between 23 and 98760");
	
	}
	else{
	
		temp=number;
		temp2=number;
		counter = 1;
		while(temp>=10.0){//in this part we can find digit number of our number
			counter++;
			temp = temp/10;
			
		}
		
		switch(counter){//acording to digit number we can reach our case statement
		
		case 2:
			
			printf("The second digit is : %d\n",(temp2/10));
			printf("The first digit is : %d\n",(temp2%10));
			
		break;
		
		case 3:
			
			printf("The third digit is : %d\n",(temp2/100));
			printf("The second digit is : %d\n",(temp2/10)%10);
			printf("The first digit is : %d\n",(temp2%10));
			
		break;
		
		case 4:
			
			printf("The fourth digit is : %d\n",(temp2/1000));
			printf("The third digit is : %d\n",(temp2/100)%10);
			printf("The second digit is : %d\n",(temp2/10)%10);
			printf("The first digit is : %d\n",(temp2%10));
		
		break;
		
		case 5:
			
			printf("The fifth digit is : %d\n",(temp2/10000));
			printf("The fourth digit is : %d\n",(temp2/1000)%10);
			printf("The third digit is : %d\n",(temp2/100)%10);
			printf("The second digit is : %d\n",(temp2/10)%10);
			printf("The first digit is : %d\n",(temp2%10));
			
			break;
	}
	}
	return 0;
}
