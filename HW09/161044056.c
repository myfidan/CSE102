#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	
	char map[10][10];
	int width;
	int height;
	int flower_x;
	int flower_y;
	
}Forest;

typedef struct{
	
	int coord_x;
	int coord_y;
	int water_bottle_size;
	
}Botanist;


void init_game (Forest *forest, Botanist *botanist);
void print_map (Forest *forest);
int search (Forest *forest, Botanist *botanist,int move_count);

int main(){
	
	srand(time(NULL));
	
	Forest forest;
	Botanist botanist;
	init_game(&forest,&botanist);
	print_map(&forest);
	printf("\nSearching...\n\n");
	search(&forest,&botanist,0);
	
	return 0;
}

void init_game (Forest *forest, Botanist *botanist){
	
	int x=0,y=-0;
	char ch;
	FILE* dosya;
	dosya=fopen("init.txt","r");

	fscanf(dosya,"%d\n",&botanist->water_bottle_size);
	fscanf(dosya,"%d,%d\n",&forest->height,&forest->width);
	
	do{
		ch=fgetc(dosya);
		
		if(ch=='#' || ch=='B' || ch=='F' || ch==' ' || ch=='\n'){
			if(ch=='B'){botanist->coord_x=x; botanist->coord_y=y;}//cordinates of botanist
			if(ch=='F'){forest->flower_x=x; forest->flower_y=y;}  //cordinates of flower	
			forest->map[x][y]=ch;
			x++;
			if(ch=='\n'){y++; x=0;}
			
		}
	}while(ch!=EOF);
	fclose(dosya);
}

void print_map(Forest *forest){
	
	
	int r=0,c=0;
	for(r=0; r<10; r++){
		for(c=0; c<10; c++){
			printf("%c",forest->map[c][r]);
		}
		printf("\n");
	}
	
}

int search(Forest *forest, Botanist *botanist,int move_count){
	int move;
	
	move=1+rand()%4;
	
	if(move_count==botanist->water_bottle_size){
		print_map(forest);	
		printf("\nHelp! I am on (%d,%d)",botanist->coord_x,botanist->coord_y);
		return 0;
	}
	else{
		
		if(move==1 && forest->map[botanist->coord_x][botanist->coord_y-1] != '#' && botanist->coord_y>0){//up
			move_count++;
			if(forest->map[botanist->coord_x][botanist->coord_y-1]=='F'){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				print_map(forest);
				printf("\nI have found it on (%d,%d)",botanist->coord_x,botanist->coord_y-1);
				return 0;
			}
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x][botanist->coord_y-1]='B';
			botanist->coord_y--;
			return search(forest,botanist,move_count);//recursion
		}
		else if(move==2 && forest->map[botanist->coord_x-1][botanist->coord_y] != '#' && botanist->coord_x>0){//left
			move_count++;
			if(forest->map[botanist->coord_x-1][botanist->coord_y]=='F'){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				print_map(forest);
				printf("\nI have found it on (%d,%d)",botanist->coord_x-1,botanist->coord_y);
				return 0;
			}
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x-1][botanist->coord_y]='B';
			botanist->coord_x--;
			return search(forest,botanist,move_count);//recursion
		}
		else if(move==3 && forest->map[botanist->coord_x+1][botanist->coord_y] != '#' && botanist->coord_x<9){//right
			move_count++;
			if(forest->map[botanist->coord_x+1][botanist->coord_y]=='F'){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				print_map(forest);
				printf("\nI have found it on (%d,%d)",botanist->coord_x+1,botanist->coord_y);
				return 0;
			}
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x+1][botanist->coord_y]='B';
			botanist->coord_x++;
			return search(forest,botanist,move_count);//recursion
		}
		else if(move==4 && forest->map[botanist->coord_x][botanist->coord_y+1] != '#' && botanist->coord_y<9){//down
			move_count++;
			if(forest->map[botanist->coord_x][botanist->coord_y+1]=='F'){
				forest->map[botanist->coord_x][botanist->coord_y]=' ';
				print_map(forest);
				printf("\nI have found it of (%d,%d)",botanist->coord_x,botanist->coord_y+1);
				return 0;
			}
			forest->map[botanist->coord_x][botanist->coord_y]=' ';
			forest->map[botanist->coord_x][botanist->coord_y+1]='B';
			botanist->coord_y++;
			return search(forest,botanist,move_count);//recursion
		}
		
	}
	return search(forest,botanist,move_count);//recursion
	return 0;
}



