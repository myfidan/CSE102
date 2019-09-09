#include<stdio.h>
#include<stdlib.h>

typedef enum{
	male,female
}Gender;

struct customers{
	char name[30];
	char surname[30];
	int number;
	int age;
    char gender[20];
	struct customer* next_c;
};

struct hotel{
	int number;
	int capacity;
	int floor;
	struct customers Custo;
	struct hotel* next_h;
	
};

void add_room_to_end(struct hotel **head_room);
void add_room_after_room_number(struct hotel **head_room);
void add_customer_to_end();
struct hotel* link_customers_to_room(struct hotel **head_room);
void remove_room(struct hotel **head_room);
struct hotel* show_vacancy(struct hotel **head_room);
struct hotel * get_by_floor();
void print_list(struct hotel *head_room);

int main(){
	
	struct hotel *head_room=NULL;
	struct hotel *temp=NULL;
	add_room_to_end(&head_room);
	struct hotel *sirali=show_vacancy(&head_room);
	//link_customers_to_room(&sirali);
	print_list(sirali);
		
	return 0;
}

void add_room_to_end(struct hotel **head_room){
	
	
	FILE *dosya;
	dosya=fopen("rooms.txt","r");
	do{	
		
		struct hotel *new_node=(struct hotel*)malloc(sizeof(struct hotel));
		new_node->next_h=NULL;
	
		if(*head_room==NULL){
			fscanf(dosya,"%d,%d,%d\n",&new_node->number,&new_node->capacity,&new_node->floor);
			*head_room=new_node;		
		}
		else{   
			fscanf(dosya,"%d,%d,%d\n",&new_node->number,&new_node->capacity,&new_node->floor);
			struct hotel *prev=*head_room;
			
			
			while(prev->next_h!=NULL){
				prev=prev->next_h;
			}
			
			prev->next_h=new_node;
		}
	
	}while(!feof(dosya));
	fclose(dosya);
}

struct hotel* show_vacancy(struct hotel **head_room){
	struct hotel *temp1=*head_room;
	struct hotel *temp2=*head_room;
	struct hotel *temp3=*head_room;
	struct hotel *temp4=*head_room;
	struct hotel *sirali=NULL;
	int i,counter;
	i=1;
	while(temp1!=NULL){
		if(temp1->floor==1){
		
				struct hotel *gecici=(struct hotel*)malloc(sizeof(struct hotel));
				gecici->number=temp1->number;
				gecici->floor=temp1->floor;
				gecici->capacity=temp1->capacity;
				
				if(sirali==NULL){
					gecici->next_h=NULL;
					sirali=gecici;
				}
				else{
					struct hotel *prev=sirali;
					while(prev->next_h!=NULL){
						prev=prev->next_h;
					}
					gecici->next_h=NULL;
					prev->next_h=gecici;	
				}
				
		}
		temp1=temp1->next_h;
	}
	
		while(temp2!=NULL){
		if(temp2->floor==2){
		
				struct hotel *gecici=(struct hotel*)malloc(sizeof(struct hotel));
				gecici->number=temp2->number;
				gecici->floor=temp2->floor;
				gecici->capacity=temp2->capacity;
				
				if(sirali==NULL){
					gecici->next_h=NULL;
					sirali=gecici;
				}
				else{
					struct hotel *prev=sirali;
					while(prev->next_h!=NULL){
						prev=prev->next_h;
					}
					gecici->next_h=NULL;
					prev->next_h=gecici;	
				}
				
		}
		temp2=temp2->next_h;
	}
	
		while(temp3!=NULL){
		if(temp3->floor==3){
		
				struct hotel *gecici=(struct hotel*)malloc(sizeof(struct hotel));
				gecici->number=temp3->number;
				gecici->floor=temp3->floor;
				gecici->capacity=temp3->capacity;
				
				if(sirali==NULL){
					gecici->next_h=NULL;
					sirali=gecici;
				}
				else{
					struct hotel *prev=sirali;
					while(prev->next_h!=NULL){
						prev=prev->next_h;
					}
					gecici->next_h=NULL;
					prev->next_h=gecici;	
				}
				
		}
		temp3=temp3->next_h;
	}
	
		while(temp4!=NULL){
		if(temp4->floor==4){
		
				struct hotel *gecici=(struct hotel*)malloc(sizeof(struct hotel));
				gecici->number=temp4->number;
				gecici->floor=temp4->floor;
				gecici->capacity=temp4->capacity;
				
				if(sirali==NULL){
					gecici->next_h=NULL;
					sirali=gecici;
				}
				else{
					struct hotel *prev=sirali;
					while(prev->next_h!=NULL){
						prev=prev->next_h;
					}
					gecici->next_h=NULL;
					prev->next_h=gecici;	
				}
				
		}
		temp4=temp4->next_h;
	}
	
	return sirali;
	
}

struct hotel* link_customers_to_room(struct hotel **head_room){
	FILE *dosya;
	struct hotel* temp=*head_room;
	
	while(temp!=NULL){
		struct hotel *new_node=(struct hotel*)malloc(sizeof(struct hotel));
		do{
			fscanf(dosya,"%d,%s%s,%d,%s",new_node->Custo.number,new_node->Custo.name,new_node->Custo.surname,new_node->Custo.age,new_node->Custo.gender);
			if(new_node->Custo.number==temp->number){
				
			
			}
		}while(!feof(dosya));
	}
}

void remove_room(struct hotel **head_room){
	struct hotel *temp=*head_room;
	
	
}



void print_list(struct hotel *head_room){
	
	while(head_room!=NULL){
		printf("Room %d(Floor %d - Capacity %dx)\n",head_room->number,head_room->floor,head_room->capacity);
		if(head_room->capacity==1){
			printf("->\n");
		}
		if(head_room->capacity==2){
			printf("->\n");
			printf("->\n");
		}
		if(head_room->capacity==3){
			printf("->\n");
			printf("->\n");
			printf("->\n");
		}
		if(head_room->capacity==4){
			printf("->\n");
			printf("->\n");
			printf("->\n");
			printf("->\n");
			
		}
		if(head_room->capacity==5){
			printf("->\n");
			printf("->\n");
			printf("->\n");
			printf("->\n");
			printf("->\n");
		}
		head_room=head_room->next_h;
	}
}
