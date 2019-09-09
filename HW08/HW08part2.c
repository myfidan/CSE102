#include<stdio.h>
#define array_size 6
char* find_operations(int arr[],int expected_val,char operations[],size_t arr_len,int cursor,int current);

int main(){
	
	int arr[array_size]={25,12,6,10,32,8};
	char ope[array_size-1];
	//char ope[5]="-*--+";
	printf("%d ",find_operations(arr,44,ope,6,0,0));
	return 0;
}

char* find_operations(int arr[],int expected_val,char operations[],size_t arr_len,int cursor,int current)
{
	if(cursor>=arr_len) return 0;
	current+=arr[cursor]+find_operations(arr,44,operations,6,cursor+1,current); 
	operations[cursor]='+';
	current+=arr[cursor]-find_operations(arr,44,operations,6,cursor+1,current);
	current+=arr[cursor]*find_operations(arr,44,operations,6,cursor+1,current);
}

