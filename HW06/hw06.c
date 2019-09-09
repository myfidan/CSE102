#include<stdio.h>

void menu();
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reserve_line(char line[],int line_lenght);

int main(){
	
	menu();
	return 0;
}

int find_size_of_line(char line[]){//satirin uzunlugunu dondurur.
	int size=0;
	int i=0;

		while(line[i] != '\n' && line[i]!=EOF){
			size++;
			i++;
		}
	
	return size;
}

void reserve_line(char line[],int line_lenght){//satiri ters cevirir.
	char b[line_lenght];
	int i;
	int j=0;
	for(i=line_lenght-1; i>=0; i--){
		
		b[j]=line[i];
		j++;
	}
	for(j=0; j<line_lenght; j++){
		line[j]=b[j];
	}

}


void encrypt_open_msg(){
	
	int height,key;	
	int i=0,k=0,satir=0;
	char str[1024],b[1024];
	char karakter;
	int toplam=0;
	printf("\nKey:");
	scanf("%d",&key);
	printf("\n");
	FILE *dosya;
	FILE *dosya2;
	dosya=fopen("open_msg.txt","r");
	
		karakter=fgetc(dosya);
		do{
			
			
			printf("%c",karakter);
			karakter=fgetc(dosya);
			
		}while(karakter!=EOF);
			
		fclose(dosya);
		printf("\n-------------------------------------\n");
		dosya=fopen("open_msg.txt","r");
		dosya2=fopen("secret_msg.txt","w");
		
		do{
			karakter=fgetc(dosya);
			str[i]=karakter;
			
			if(karakter == '\n' || karakter == EOF){
				height=find_size_of_line(str);
				reserve_line(str,height);	
				printf("\n");
				i=-1;
				for(k=0; k<height; k++){
					if(str[k]=='.'){printf("*"); fputc('*',dosya2);}
					else if(str[k]==' '){printf("_"); fputc('_',dosya2);}
					else if(str[k]-key>96){
						printf("%c",str[k]-key); fputc(str[k]-key,dosya2);
					}
					else{
						printf("%c",str[k]-key+26); fputc(str[k]-key+26,dosya2);
					}
						
					
				}
				fputc('\n',dosya2);
			}
			
			i++;
		}while(karakter!=EOF);
		
		
		fclose(dosya2);
		fclose(dosya);

	printf("\n\n");	
}

void decrypt_secret_msg(){

int height,key;	
	int i=0,k=0,satir=0;
	char str[1024],b[1024];
	char karakter;
	int toplam=0;
	printf("\nKey:");
	scanf("%d",&key);
	printf("\n");
	FILE *dosya;
	FILE *dosya3;
	dosya=fopen("secret_msg.txt","r");
	
		karakter=fgetc(dosya);
		do{
			
			
			printf("%c",karakter);
			karakter=fgetc(dosya);
			
		}while(karakter!=EOF);
			
		fclose(dosya);
		printf("\n\n-------------------------------------\n\n");
		dosya=fopen("secret_msg.txt","r");
		dosya3=fopen("open_msg.txt","w");
		
		do{
			karakter=fgetc(dosya);
			str[i]=karakter;
			
			if(karakter == '\n' || karakter == EOF){
				height=find_size_of_line(str);
				reserve_line(str,height);	
				printf("\n");
				i=-1;
				for(k=0; k<height; k++){
					if(str[k]=='*'){printf("."); fputc('.',dosya3);}
					else if(str[k]=='_'){printf(" "); fputc(' ',dosya3);}
					else if(str[k]+key<123){
						printf("%c",str[k]+key); fputc(str[k]+key,dosya3);
					}
					else{
						printf("%c",str[k]+key-26); fputc(str[k]+key-26,dosya3);
					}
						
					
				}
				fputc('\n',dosya3);
			}
			
			i++;
		}while(karakter!=EOF);
		
		
		fclose(dosya3);
		fclose(dosya);
		printf("\n\n");
	
}

void menu(){
	
	int choice;
	do{
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:");
		scanf("%d",&choice);
		switch(choice){
			
			case 1:
				encrypt_open_msg();break;
			case 2:
				decrypt_secret_msg();break;
			
		}
	}while(choice != 0);
	
	
}


