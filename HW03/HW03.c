#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();

int main(){
	srand(time(NULL));
	menu();
	
	return 0;
}

void menu(){
	int selection;
	do{
		printf("1. Horse Racing Game\n");
		printf("2. Occurrence Counter\n");
		printf("3. Triangle of Sequences\n");
		printf("\n           Make Selection:");
		scanf("%d",&selection);
		switch(selection){
			
			case 1://horse racing
				horseRacingGame();
			break;
			
			case 2://occurrence counter
				countOccurrence();
				printf("\n");
			break;
			
			case 3://triangle of Sequences
				triangleOfSequences();
				printf("\n");
			break;
			
			case 0://exit
				
			break;
			
			default:
				printf("Error-Enter {1,2,3 or 0}!!\n");
	}
}while(selection!=0);
	
}

int getInt(int mini, int maxi){
	int value;
	do{
	
	printf("Enter a number between %d and %d: ",mini,maxi);
	scanf("%d",&value);
	
	if(value<=maxi && value >= mini) return value;
	
	}while(value<=maxi && value >= mini);
	

}


int numberGeneratorBetweenRange(int min, int max){
	
	int number;
	number=min + rand()%(max-min+1);
	return number;
}

void horseRacingGame(){

	
	int number_of_horses,horse_number,speed,i,j,min;
	number_of_horses = numberGeneratorBetweenRange(3,5);
	printf("Number of Horse:%d\n",number_of_horses);
	horse_number = getInt(3,5);
	printf("Horse Number:%d\n",horse_number);
	printf("Racing starts...\n");
	min = 20;
	int sayac;
	for(i=1; i <= number_of_horses; i++){
		speed = numberGeneratorBetweenRange(10,20);
		if(min > speed){
			min = speed;
			sayac = i;
		}
		printf("Horse %d:",i);
		for(j=0; j<speed; j++){
			printf("-");
		}
		printf("\n");
	}
	if(sayac==horse_number){
		printf("You win!\n");
	}
	else{
		printf("You lose!Winner is %d\n",sayac);
	}
	
}

void countOccurrence(){
	int bn;//big number
	int sn;//search number
	int i=0,j=0;//variables
	int result=0;
	printf("Big Number:");
	scanf("%d",&bn);
	printf("\nSearch Number:");
	scanf("%d",&sn);
	int temp = sn; //a temp variable which hold the search number
	int counter = 10;
	while(temp >= 1){
		temp = temp/10;
		if(temp >= 1){
			counter *= 10;
		}
	}
	while(i==0){
		j = bn%counter;
		if(j == sn){
			result++;
		}
		bn = bn/10;
		if(bn==0){
			i=-1;
		}
		
	}
	printf("\nOccurrence: %d",result);
}


void triangleOfSequences(){
	
	int number,i,j;
	number = numberGeneratorBetweenRange(2,10);
	printf("Outpur(for %d)\n",number);
	for(i=1; i<=number; i++){
		for(j=1; j<=i; j++){
			printf("%d ",i*j);
			
		}
		printf("\n");
	}
	
	
	
}
	
	
	

