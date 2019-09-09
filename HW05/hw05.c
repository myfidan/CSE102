#include<stdio.h>

typedef enum {white_man, black_man, white_king, black_king, empty} piece;
typedef enum {white = 10, black = 20} player;
void init_board(piece board[][8]);
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_1();
void sample_game_2();
void init_game_2();

int main(){
	piece board[8][8];
	//sample_game_1();
	sample_game_2();
	return 0;
}

void init_board(piece board[][8]){
	int r,c;
	for(r=0,c=0; c<8; c++){
		board[r][c]=empty;
	}
	for(r=1; r<3; r++){
		for(c=0; c<8; c++){
			board[r][c]=black_man;
		}
	}
	for(r=3; r<5; r++){
		for(c=0; c<8; c++){
			board[r][c]=empty;
		}
	}
	for(r=5; r<7; r++){
		for(c=0; c<8; c++){
			board[r][c]=white_man;
		}
	}
	for(r=7,c=0; c<8; c++){
		board[r][c]=empty;
	}
	
}


void display_board(piece board[][8]){
	int r,c;
	for(r=0; r<8; r++){
		for(c=0; c<8; c++){
			if(board[r][c]==empty) printf("-");
			else if(board[r][c]==white_man) printf("w");
			else if(board[r][c]==black_man) printf("b");
			else if(board[r][c]==white_king) printf("W");
			else if(board[r][c]==black_king) printf("B");
		}
		printf("\n");
		
	}
	
}

void init_game_2(piece board[][8]){
	int r,c;
	for(r=0; r<8; r++){
		for(c=0; c<8; c++){
			board[r][c]=empty;
		}
	}
	for(r=1,c=2; c<6; c++){
		board[r][c]=black_man;
	}
	for(r=2,c=1; c<5; c++){
		board[r][c]=black_man;
	}
	board[2][6]=black_man;
	board[2][7]=black_man;		

	for(r=3,c=0; c<3; c++){
		board[r][c]=black_man;
	}
	board[3][5]=black_man;
	board[3][7]=black_man;
	board[4][5]=black_man;
	
	for(r=4,c=2; c<5; c++){
		board[r][c]=white_man;
	}
	for(r=5,c=0; c<5; c++){
		board[r][c]=white_man;
	}
	for(r=6,c=2; c<6; c++){
		board[r][c]=white_man;
	}
	board[4][6]=white_man;
	board[4][7]=white_man;
	board[5][6]=white_man;
	board[5][7]=white_man;
}




int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	
	if(from_x<0 || from_x>7 || from_y<0 || from_y>7) return -2;
	if(to_x<0 || to_x>7 || to_y<0 || to_y>7) return -2;
	if(board[to_x][to_y] != empty) return -2;
	if(from_x!=to_x&& from_y!=to_y) return -2;
	if(p == white && (board[from_x][from_y] != white_man && board[from_x][from_y] != white_king)) return -1;
	if(p == black && (board[from_x][from_y] != black_man && board[from_x][from_y] != black_king)) return -1;

	


	if(p==white && board[from_x][from_y]==white_man){
		if(from_x<to_x) return -2;
		
		if((board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king && board[from_x-2][from_y]==empty) || (board[from_x][from_y+1]==black_man || board[from_x][from_y+1]==black_king && board[from_x][from_y+2]==empty) ||
			(board[from_x][from_y-1]==black_man || board[from_x][from_y-1]==black_king && board[from_x][from_y-2]==empty)){//tas alabilme durumunu zorunlu yapan if 
			
			if(to_x==from_x-2){
				if(to_x==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
					board[from_x-1][from_y]=empty;
					return 1;	
				}
			else{
				board[to_x][to_y]=white_man;
				board[from_x][from_y]=empty;
				board[from_x-1][from_y]=empty;
				return 1;
			}
			
		}
	//sagda alýncak tas varsa oynanmasý zorunlu olan
			else if(to_y==from_y+2){
				board[to_x][to_y]=white_man;
				board[from_x][from_y]=empty;
				board[from_x][from_y+1]=empty;
				return 1;
			}
	//solda alýncak tas varsa oynanmasý zorunlu olan
			else if(to_y==from_y-2){
				board[to_x][to_y]=white_man;
				board[from_x][from_y]=empty;
				board[from_x][from_y-1]=empty;
				return 1;
			}
			else return 0;
			
		}
		if(to_x<from_x-1) return -2;
		if(to_y<from_y-1) return -2; // son eklenenler
		if(to_y>from_y+1) return -2;
		
		if(to_x==0) board[to_x][to_y]=white_king;
		else board[to_x][to_y]=white_man;
		board[from_x][from_y]=empty;
	
}
	

	else if(p=black && board[from_x][from_y]==black_man){
		if(to_x<from_x) return -2;
		
		
		if((board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king && board[from_x+2][from_y]==empty) || (board[from_x][from_y+1]==white_man || board[from_x][from_y+1]==white_king && board[from_x][from_y+2]==empty)
		   || (board[from_x][from_y-1]==white_man || board[from_x][from_y-1]==white_king && board[from_x][from_y-2]==empty)){//asagida alýncak tas varsa oynanmasý zorunlu olan
			
			if(to_x==from_x+2){
				if(to_x==7){
				
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				return 1;
				}
			else{
				board[to_x][to_y]=black_man;
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				return 1;
				}
			}
			
			
			else if(to_y==from_y+2){
				board[to_x][to_y]=black_man;
				board[from_x][from_y]=empty;
				board[from_x][from_y+1]=empty;
				return 1;		
			}
		
			else if(to_y==from_y-2){
				board[to_x][to_y]=black_man;
				board[from_x][from_y]=empty;
				board[from_x][from_y-1]=empty;
				return 1;
			}
			else return 0;
		}
		if(to_x>from_x+1) return -2;
		if(to_y<from_y-1) return -2; // son eklenenler
		if(to_y>from_y+1) return -2;
		
		if(to_x==7) board[to_x][to_y]=black_king;
		else board[to_x][to_y]=black_man;
		board[from_x][from_y]=empty;
}
		else if(p=white && board[from_x][from_y]==white_king){
			int counter_right=0; int counter_left=0; int counter_down=0; int counter_up=0; int kontrol=0;
			int i;
			for(i=from_y; i<8; i++){
				if((board[from_x][i]==black_man || board[from_x][i]== black_king) && board[from_x][i+1]==empty){
					counter_right++;
					if(counter_right>0){
						kontrol++;
						if(to_y==i+1){
							board[to_x][to_y]=white_king;
							board[from_x][from_y]=empty;
							board[from_x][i]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_y; i>=0; i--){
				if((board[from_x][i]==black_man || board[from_x][i]== black_king) && board[from_x][i-1]==empty){
					counter_left++;
					if(counter_left>0){
						kontrol++;
						if(to_y==i-1){
							board[to_x][to_y]=white_king;
							board[from_x][from_y]=empty;
							board[from_x][i]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_x; i>=0; i--){
				if((board[i][from_y]==black_man || board[i][from_y]== black_king) && board[i-1][from_y]==empty){
					counter_up++;
					if(counter_up>0){
						kontrol++;
						if(to_x==i-1){
							board[to_x][to_y]=white_king;
							board[from_x][from_y]=empty;
							board[i][from_y]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_x; i<8; i++){
				if((board[i][from_y]==black_man || board[i][from_y]== black_king) && board[i+1][from_y]==empty){
					counter_down++;
					if(counter_down>0){
						kontrol++;
						if(to_x=i+1){
							board[to_x][to_y]=white_king;
							board[from_x][from_y]=empty;
							board[i][from_y]=empty;
							return 1;
						}
					}
				}
			}
			if(kontrol==0){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_king;
			}
			

}
	else if(p=black && board[from_x][from_y]==black_king){
		
		int counter_right=0; int counter_left=0; int counter_down=0; int counter_up=0; int kontrol=0;
			int i;
			for(i=from_y; i<8; i++){
				if((board[from_x][i]==white_man || board[from_x][i]== white_king) && board[from_x][i+1]==empty){
					counter_right++;
					if(counter_right>0){
						kontrol++;
						if(to_y==i+1){
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[from_x][i]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_y; i>=0; i--){
				if((board[from_x][i]==white_man || board[from_x][i]== white_king) && board[from_x][i-1]==empty){
					counter_left++;
					if(counter_left>0){
						kontrol++;
						if(to_y==i-1){
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[from_x][i]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_x; i>=0; i--){
				if((board[i][from_y]==white_man || board[i][from_y]== white_king) && board[i-1][from_y]==empty){
					counter_up++;
					if(counter_up>0){
						kontrol++;
						if(to_x==i-1){
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[i][from_y]=empty;
							return 1;
						}
					}
				}
			}
			for(i=from_x; i<8; i++){
				if((board[i][from_y]==white_man || board[i][from_y]== white_king) && board[i+1][from_y]==empty){
					counter_down++;
					if(counter_down>0){
						kontrol++;
						if(to_x=i+1){
							board[to_x][to_y]=black_king;
							board[from_x][from_y]=empty;
							board[i][from_y]=empty;
							return 1;
						}
					}
				}
			}
			if(kontrol==0){
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_king;
			}
		
	}


}


int check_end_of_game(piece board[][8]){
	int counter_white=0,counter_black=0;
	int r,c;
	for(r=0; r<8; r++){
		for(c=0; c<8; c++){
			if(board[r][c]==white_man || board[r][c]==white_king) counter_white++;
			if(board[r][c]==black_man || board[r][c]==black_king) counter_black++;
		}
	}
	if(counter_white==0) return black;
	else if(counter_black==0) return white;
	else return -1;
}
	



void sample_game_1(){

	piece board[8][8];
	int x1,y1,x2,y2;
	printf("******Current Board******\n");
	init_board(board);
	display_board(board);
	x1=5,y1=1,x2=4,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=1,x2=3,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=1,x2=2,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=1,x2=0,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=5,x2=3,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=2,x2=4,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=7,x2=3,y2=7;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=6,x2=4,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=4,x2=3,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=4,x2=4,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=4,x2=5,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=4,x2=5,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=6,x2=7,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=7,x2=6,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=7,y1=6,x2=5,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=6,x2=5,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=2,x2=3,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=2,x2=7,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=3,x2=5,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=2,x2=3,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=0,y1=1,x2=0,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=2,x2=4,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=0,y1=2,x2=2,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=2,x2=5,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=7,y1=2,x2=4,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=2,x2=4,y2=7;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=7,x2=6,y2=7;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=0,x2=5,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=0,x2=3,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=1,x2=4,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=5,x2=4,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=1,x2=6,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=5,x2=5,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=5,x2=4,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=7,x2=6,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=3,x2=6,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=1,x2=3,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=6,y1=0,x2=5,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=7,x2=4,y2=7;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=5,x2=4,y2=6;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=7,x2=4,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=3,x2=5,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=0,x2=4,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=0,x2=3,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=0,x2=3,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=1,y1=0,x2=2,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=5,y1=4,x2=5,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=1,y1=4,x2=2,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=3,y1=2,x2=3,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=2,y1=3,x2=4,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board); 	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");

	x1=4,y1=3,x2=6,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);  	if(check_end_of_game(board)==black)printf("\n*****The Winner is Black*****\n");	if(check_end_of_game(board)==white)printf("\n*****The Winner is White*****\n");


}

void sample_game_2(){
	
	piece board[8][8];
	int x1,y1,x2,y2;
	printf("******Current Board******\n");
	init_game_2(board);
	display_board(board); 
	
	x1=5,y1=1,x2=4,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=3,y1=1,x2=5,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=4,y1=3,x2=3,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=4,y1=5,x2=4,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=4,y1=3,x2=4,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=3,y1=3,x2=3,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=3,y1=1,x2=1,y2=1;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=1,y1=2,x2=1,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=5,y1=3,x2=4,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=5,y1=1,x2=5,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=5,y1=3,x2=5,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=5,y1=5,x2=7,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=4,y1=3,x2=3,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=2,y1=3,x2=4,y2=3;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=5,y1=6,x2=5,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=7,y1=5,x2=4,y2=5;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,black); display_board(board);
	x1=4,y1=6,x2=4,y2=4;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=4,y1=4,x2=4,y2=2;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=4,y1=2,x2=4,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=4,y1=0,x2=2,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
	x1=2,y1=0,x2=0,y2=0;  printf("\nAfter playing [%d][%d] to [%d][%d]\n",x1,y1,x2,y2); move(board,x1,y1,x2,y2,white); display_board(board);
}




