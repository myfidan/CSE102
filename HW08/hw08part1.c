#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
typedef enum{
	M,P,S,B,T,X
}type_enum;

typedef struct{
	
	int pos_x,pos_y,jump_x,jump_y,data;
	type_enum type;
	char text[10];
}block;

block board_init(block board[][10]);
block print_board(block board[][10]);
block play_game(block board[][10],int yer,int counter);
block multiplay_game(block board[][10],int yer,int counter1,int counter2);

int main(){
	
	int counter1=0;
	int counter2=0;
	
	srand(time(NULL));
	block board[10][10];
	board_init(board);
	print_board(board);
	play_game(board,1,0);  /*Single game*/
	//multiplay_game(board,1,counter1,counter2); /*multiplayer game*/
	return 0;
}

block board_init(block board[][10]){
	int r,c;
	int temp=1;
	
		for(r=0; r<10; r++){
			for(c=0; c<10; c++){
				board[r][c].type=X;
			}
		}
		
		strcpy(board[4][9].text,"S{1}");  		board[4][9].type=S;
		strcpy(board[3][9].text,"M{11}"); 		board[3][9].type=M;
		strcpy(board[6][8].text,"M{28}");		board[6][8].type=M;
		strcpy(board[5][7].text,"S{12}");		board[5][7].type=S;
		strcpy(board[1][6].text,"M{52}");		board[1][6].type=M;
		strcpy(board[5][5].text,"S{22}");		board[5][5].type=S;
		strcpy(board[9][4].text,"S{44}");		board[9][4].type=S;
		strcpy(board[6][4].text,"M{77}");		board[6][4].type=M;
		strcpy(board[7][3].text,"S{52}");		board[7][3].type=S;
		strcpy(board[1][3].text,"M{77}");		board[1][3].type=M;
		strcpy(board[5][2].text,"M{83}");		board[5][2].type=M;
		strcpy(board[2][2].text,"S{68}");		board[2][2].type=S;
		strcpy(board[1][1].text,"M{94}");		board[1][1].type=M;
		strcpy(board[8][0].text,"S{56}");		board[8][0].type=S;
		strcpy(board[7][0].text,"S{72}");		board[7][0].type=S;
		
		board[2][8].type=P;
		board[1][7].type=B;
		board[9][6].type=T;
		board[5][6].type=B;
		board[2][5].type=P;
		board[0][5].type=B;
		board[3][4].type=T;
		board[7][3].type=B;
		board[8][2].type=T;
		board[8][1].type=B;
		board[5][1].type=P;
		board[2][0].type=T;
		
		for(r=9; r>=0; r--){
			board[r][9].data=temp;
			temp++;
		}
		
		for(r=0; r<10; r++){
			board[r][8].data=temp;
			temp++;
		}
		
		for(r=9; r>=0; r--){
			board[r][7].data=temp;
			temp++;
		}
		
		for(r=0; r<10; r++){
			board[r][6].data=temp;
			temp++;
		}
		
		for(r=9; r>=0; r--){
			board[r][5].data=temp;
			temp++;
		}
		
		for(r=0; r<10; r++){
			board[r][4].data=temp;
			temp++;
		}	
		
		for(r=9; r>=0; r--){
			board[r][3].data=temp;
			temp++;
		}
		
		for(r=0; r<10; r++){
			board[r][2].data=temp;
			temp++;
		}
		
		for(r=9; r>=0; r--){
			board[r][1].data=temp;
			temp++;
		}
		
		for(r=0; r<10; r++){
			board[r][0].data=temp;
			temp++;
		}
}

block print_board(block board[][10]){
	int r,c;
	for(c=0; c<10; c++){
		for(r=0; r<10; r++){
			if(board[r][c].type==P) printf("P ");
			else if(board[r][c].type==B) printf("B ");
			else if(board[r][c].type==T) printf("T ");
			else if(board[r][c].type==M) printf("%s ",board[r][c].text);
			else if(board[r][c].type==S) printf("%s ",board[r][c].text);
			else if(board[r][c].data<10) printf("%d  ",board[r][c].data);
			else printf("%d ",board[r][c].data);
		}
		printf("\n");
	}
	printf("\n");
	
}

block play_game(block board[][10],int yer,int counter){
	//x columb y row

	int move;
		
		if(yer==100){
			printf("%d\n",yer);
			return;
		}
	
		
		move = 1+rand()%6;
		//p
		if(yer+move==13 || yer+move==48 || yer+move==85){  printf("%d\n",yer); play_game(board,yer,counter++);}
		//s
		else if(yer+move==6){  printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,1,counter++);}
		else if(yer+move==25){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,12,counter++);}
		else if(yer+move==45){  printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,22,counter++);}
		else if(yer+move==60){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,44,counter++);}
		else if(yer+move==63){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,52,counter++);}
		else if(yer+move==73){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,68,counter++);}
		else if(yer+move==98){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,72,counter++);}
		else if(yer+move==99){ printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,56,counter++);}
		//m
		else if(yer+move==7) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,11,counter++);}
		else if(yer+move==17) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,28,counter++);}
		else if(yer+move==32) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,52,counter++);}
		else if(yer+move==57) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,77,counter++);}
		else if(yer+move==69) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,77,counter++);}
		else if(yer+move==76) {printf("%d\n",yer); printf("%d\n",yer+move); play_game(board,83,counter++);}
		else if(yer+move==89) {printf("%d\n",yer);printf("%d\n",yer+move);  play_game(board,94,counter++);}
		
		else if(yer+move==29){ printf("%d\n",yer); play_game(board,yer+5,counter++);}
		else if(yer+move==36){ printf("%d\n",yer); play_game(board,yer+5,counter++);}
		else if(yer+move==50){ printf("%d\n",yer); play_game(board,yer+5,counter++);}
		else if(yer+move==66){ printf("%d\n",yer); play_game(board,yer+5,counter++);}
		else if(yer+move==82){ printf("%d\n",yer); play_game(board,yer+5,counter++);}
		
		else if(yer+move==40){ printf("%d\n",yer); play_game(board,yer-5,counter++);}
		else if(yer+move==54){ printf("%d\n",yer); play_game(board,yer-5,counter++);}
		else if(yer+move==79){ printf("%d\n",yer); play_game(board,yer-5,counter++);}
		else if(yer+move==93){ printf("%d\n",yer); play_game(board,yer-5,counter++);}
		
		else{
			if(yer+move>100) play_game(board,yer,counter++);	
			else{
				printf("%d\n",yer);
				yer+=move;
				play_game(board,yer,counter++);	
			}
		}
		
	
	}

block multiplay_game(block board[][10],int yer,int counter1,int counter2){
	
		int move;
		
	printf("\n%d",yer);
	counter1++;
	while(yer!=100){
		
		
		//p
		if(yer+move==13 || yer+move==48 || yer+move==85){ printf("\n%d",yer); counter1++;}
		//s
		else if(yer+move==6){printf("\n%d",yer+move); yer=1; counter1++;} 
		else if(yer+move==25){printf("\n%d",yer+move); yer=12; counter1++;} 
		else if(yer+move==60){printf("\n%d",yer+move); yer=44; counter1++;} 
		else if(yer+move==63){printf("\n%d",yer+move); yer=52; counter1++;} 
		else if(yer+move==73){printf("\n%d",yer+move); yer=68; counter1++;} 
		else if(yer+move==98){printf("\n%d",yer+move); yer=72; counter1++;} 
		else if(yer+move==99){printf("\n%d",yer+move); yer=56; counter1++;} 
		//m
		else if(yer+move==7) {printf("\n%d",yer+move); yer=11; counter1++;} 
		else if(yer+move==17){printf("\n%d",yer+move); yer=28; counter1++;} 
		else if(yer+move==32){printf("\n%d",yer+move); yer=52; counter1++;} 
		else if(yer+move==57){printf("\n%d",yer+move); yer=77; counter1++;} 
		else if(yer+move==69){printf("\n%d",yer+move); yer=77; counter1++;} 
		else if(yer+move==89){printf("\n%d",yer+move); yer=94; counter1++;}
		
		else if(yer+move==29){printf("\n%d",yer); yer+=5; counter1++;} 
		else if(yer+move==36){printf("\n%d",yer); yer+=5; counter1++;}
		else if(yer+move==50){printf("\n%d",yer); yer+=5; counter1++;}
		else if(yer+move==66){printf("\n%d",yer); yer+=5; counter1++;}
		else if(yer+move==82){printf("\n%d",yer); yer+=5; counter1++;}
		
		else if(yer+move==40){printf("\n%d",yer); yer-=5; counter1++;} 
		else if(yer+move==54){printf("\n%d",yer); yer-=5; counter1++;}
		else if(yer+move==79){printf("\n%d",yer); yer-=5; counter1++;}
		else if(yer+move==93){printf("\n%d",yer); yer-=5; counter1++;}
		
		else{
			if(yer+move>100)counter1++;
			else{
				yer+=move;
				printf("\n%d",yer);	
				counter1++;
			}
		}
		move = 1+rand()%6;
	}
		
	printf("\n\n*****First Player Move Counter=%d\n",counter1);
	
	yer=1;
	
	printf("\n%d",yer);
	counter2++;
	while(yer!=100){
		
	
		//p
		if(yer+move==13 || yer+move==48 || yer+move==85){ printf("\n%d",yer); counter1++;}
		//s
		else if(yer+move==6){printf("\n%d",yer+move); yer=1; counter2++;} 
		else if(yer+move==25){printf("\n%d",yer+move); yer=12; counter2++;} 
		else if(yer+move==45){printf("\n%d",yer+move); yer=22; counter2++;} 
		else if(yer+move==60){printf("\n%d",yer+move); yer=44; counter2++;} 
		else if(yer+move==63){printf("\n%d",yer+move); yer=52; counter2++;} 
		else if(yer+move==73){printf("\n%d",yer+move); yer=68; counter2++;} 
		else if(yer+move==98){printf("\n%d",yer+move); yer=72; counter2++;} 
		else if(yer+move==99){printf("\n%d",yer+move); yer=56; counter2++;} 
		//m
		else if(yer+move==7) {printf("\n%d",yer+move); yer=11; counter2++;} 
		else if(yer+move==17){printf("\n%d",yer+move); yer=28; counter2++;} 
		else if(yer+move==32){printf("\n%d",yer+move); yer=52; counter2++;} 
		else if(yer+move==57){printf("\n%d",yer+move); yer=77; counter2++;} 
		else if(yer+move==69){printf("\n%d",yer+move); yer=77; counter2++;} 
		else if(yer+move==76){printf("\n%d",yer+move); yer=83; counter2++;} 
		else if(yer+move==89){printf("\n%d",yer+move); yer=94; counter2++;}
		
		else if(yer+move==29){printf("\n%d",yer); yer+=5; counter2++;} 
		else if(yer+move==36){printf("\n%d",yer); yer+=5; counter2++;}
		else if(yer+move==50){printf("\n%d",yer); yer+=5; counter2++;}
		else if(yer+move==66){printf("\n%d",yer); yer+=5; counter2++;}
		else if(yer+move==82){printf("\n%d",yer); yer+=5; counter2++;}
		
		else if(yer+move==40){printf("\n%d",yer); yer-=5; counter2++;} 
		else if(yer+move==54){printf("\n%d",yer); yer-=5; counter2++;}
		else if(yer+move==79){printf("\n%d",yer); yer-=5; counter2++;}
		else if(yer+move==93){printf("\n%d",yer); yer-=5; counter2++;}
		
		else{
			if(yer+move>100)counter2++;
			else{
				yer+=move;
				printf("\n%d",yer);	
				counter2++;
			}
		}
		move = 1+rand()%6;
	}
	
	printf("\n\nSecond Player Move Counter = %d\n",counter2);
	
	
	if(counter1>counter2) printf("\n*****Player 2 Win*****");
	if(counter1<counter2) printf("\n*****Player 1 Win*****");
	if(counter1==counter2) printf("\n*****Draw*****");
}

