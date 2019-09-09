#include<stdio.h>

void input_date();
void new_date();

int main(){
	
	input_date();
	new_date();
	return 0;
}

void input_date(){
	
	int start_day,start_month,start_year,end_day,end_month,end_year,counter_day;
	int i,j,k,temp_day,temp_month,temp_year,temp_12=12;
	FILE *dosya1;
	dosya1=fopen("input_date.txt","w");
	
	printf("Enter The Start Date\n");
	printf("DAY:"); scanf("%d",&start_day);
	printf("\nMONTH:"); scanf("%d",&start_month);
	printf("\nYEAR:"); scanf("%d",&start_year);
	
	
	
	printf("Enter The End Date\n");
	printf("DAY:"); scanf("%d",&end_day);
	printf("\nMONTH:"); scanf("%d",&end_month);
	printf("\nYEAR:"); scanf("%d",&end_year);
	
	
	for(i=0; i<=end_year-start_year; i++){
		if(i==end_year-start_year) temp_12=end_month;
		for(j=start_month; j<=temp_12; j++){
			if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12) counter_day=31;
			if(j==4 || j==6 || j==9 || j==11 ) counter_day=30;
			
			if(j==2 && (start_year+i)%100==0){
				if((start_year+i)%400==0) counter_day=29;
				else counter_day=28;
			}
			if(j==2 &&(start_year+i)%100!=0){
				if((start_year+i)%4==0) counter_day=29;
				else counter_day=28;
			}
			if(i==end_year-start_year && j==temp_12) counter_day=end_day;
			for(k=start_day; k<=counter_day; k++){
				if(k<10) fprintf(dosya1,"0%d/%d/%d\n",k,j,start_year+i);
				else fprintf(dosya1,"%d/%d/%d\n",k,j,start_year+i);
			}
			start_day=1;
		}
		start_month=1;
	}
	
	fclose(dosya1);
	
}

void new_date(){
	
	FILE *dosya1,*dosya2;
	dosya1=fopen("input_date.txt","r");
	dosya2=fopen("new_date.txt","w");
	int num1,num2,num3,toplam,i,j,k,temp_num2,counter_day;
	temp_num2=num2;
	while(!(feof(dosya1))){
	toplam=0;
	fscanf(dosya1,"%d/%d/%d\n",&num1,&num2,&num3);
	
	
	for(i=1923; i<num3; i++){
		for(j=1; j<=12; j++){
			if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12) counter_day=31;
			if(j==4 || j==6 || j==9 || j==11 ) counter_day=30;
			
			if(j==2 && i%100==0){
				if((i)%400==0) counter_day=29;
				else counter_day=28;
			}
			if(j==2 &&(i)%100!=0){
				if(i%4==0) counter_day=29;
				else counter_day=28;
			}
			for(k=1; k<=counter_day; k++){
				toplam++;
			}
			k=1;
		}
		j=1;
	}
	
	for(j=1; j<num2; j++){
			if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12) counter_day=31;
			if(j==4 || j==6 || j==9 || j==11 ) counter_day=30;
			
			if(j==2 && i%100==0){
				if(i%400==0) counter_day=29;
				else counter_day=28;
			}
			if(j==2 &&i%100!=0){
				if(i%4==0) counter_day=29;
				else counter_day=28;
			}
			for(k=1; k<=counter_day; k++){
				toplam++;
			}
			k=1;
		}
		
		for(k=1; k<=num1; k++){
				toplam++;
		}
		
		
	if(toplam%7==0) fprintf(dosya2,"Sunday,");
	if(toplam%7==1) fprintf(dosya2,"Monday,");
	if(toplam%7==2) fprintf(dosya2,"Tuesday,");
	if(toplam%7==3) fprintf(dosya2,"Wedneyday,");
	if(toplam%7==4) fprintf(dosya2,"Thursday,");
	if(toplam%7==5) fprintf(dosya2,"Friday,");
	if(toplam%7==6) fprintf(dosya2,"Saturday,");
	
	
	
	if(num2==1)fprintf(dosya2,"January %d,%d\n",num1,num3);
	if(num2==2)fprintf(dosya2,"February %d,%d\n",num1,num3);
	if(num2==3)fprintf(dosya2,"March %d,%d\n",num1,num3);
	if(num2==4)fprintf(dosya2,"April %d,%d\n",num1,num3);
	if(num2==5)fprintf(dosya2,"May %d,%d\n",num1,num3);
	if(num2==6)fprintf(dosya2,"June %d,%d\n",num1,num3);
	if(num2==7)fprintf(dosya2,"July %d,%d\n",num1,num3);
	if(num2==8)fprintf(dosya2,"August %d,%d\n",num1,num3);
	if(num2==9)fprintf(dosya2,"September %d,%d\n",num1,num3);
	if(num2==10)fprintf(dosya2,"October %d,%d\n",num1,num3);
	if(num2==11)fprintf(dosya2,"November %d,%d\n",num1,num3);
	if(num2==12)fprintf(dosya2,"December %d,%d\n",num1,num3);

	

	
	}
	
	
	fclose(dosya2);
	fclose(dosya1);
}

