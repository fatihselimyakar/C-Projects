#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum{P=-1,S=-2,M=-3,B=-4,T=-5,num=-6}/*I did typedef for the my block struct.I assign to negative value because it could be confuse other values*/
block_type;

typedef struct block{/*I define the struct in this part*/
	block_type type;
	char text[10];
	int data,pos_x,pos_y,jump_x,jump_y; 
}block;

void init_board(block board[][10]){/*this function defines the board for the game*/
	int i,j;
	for(i=0 ; i<10; i++){
		for(j=0 ; j<10; j++){
			if(i==0||i==2||i==4||i==6||i==8){/*for increasing rows to the right*/
				board[i][j].data=(9-i)*10+j+1;/*it is the formula that finds the data*/
				board[i][j].pos_x=j;
				board[i][j].pos_y=i;
				board[i][j].type=num;/*I define the type is num(number)*/
			}
			else if(i==1||i==3||i==5||i==7||i==9){/*for decreasing rows to the right*/
				board[i][j].data=(10-i)*10-j;/*it is the formula that finds the data*/
				board[i][j].pos_x=j;
				board[i][j].pos_y=i;
				board[i][j].type=num;/*I define the type is num(number)*/
			}
		}
	}
	/*in this part I assign one by one type jump_x jump_y and text for all board's indexes*/
	board[9][3].type=M;
	board[9][3].jump_x=0;
	board[9][3].jump_y=8;
	sprintf(board[9][3].text,"M{11}");
	
	
	board[9][4].type=S;
	board[9][4].jump_x=9;
	board[9][4].jump_y=9;
	sprintf(board[9][4].text,"S{1} ");
	
	board[8][2].type=P;
	board[8][2].jump_x=-1;
	board[8][2].jump_y=-1;
	sprintf(board[8][2].text,"  P  ");
	
	board[8][6].type=M;
	board[8][6].jump_x=2;
	board[8][6].jump_y=7;
	sprintf(board[8][6].text,"M{28}");
	
	board[7][1].type=B;
	board[7][1].jump_x=-1;
	board[7][1].jump_y=-1;
	sprintf(board[7][1].text,"  B  ");
	
	board[7][5].type=S;
	board[7][5].jump_x=1;
	board[7][5].jump_y=8;
	sprintf(board[7][5].text,"S{12}");
	
	board[6][1].type=M;
	board[6][1].jump_x=1;
	board[6][1].jump_y=4;
	sprintf(board[6][1].text,"M{52}");
	
	board[6][5].type=B;
	board[6][5].jump_x=-1;
	board[6][5].jump_y=-1;
	sprintf(board[6][5].text,"  B  ");
	
	board[6][9].type=T;
	board[6][9].jump_x=-1;
	board[6][9].jump_y=-1;
	sprintf(board[6][9].text,"  T  ");
	
	board[5][0].type=B;
	board[5][0].jump_x=-1;
	board[5][0].jump_y=-1;
	sprintf(board[5][0].text,"  B  ");
	
	board[5][2].type=P;
	board[5][2].jump_x=-1;
	board[5][2].jump_y=-1;
	sprintf(board[5][2].text,"  P  ");
	
	board[5][5].type=S;
	board[5][5].jump_x=8;
	board[5][5].jump_y=7;
	sprintf(board[5][5].text,"S{22}");
	
	board[4][3].type=T;
	board[4][3].jump_x=-1;
	board[4][3].jump_y=-1;
	sprintf(board[4][3].text,"  T  ");
	
	board[4][6].type=M;
	board[4][6].jump_x=6;
	board[4][6].jump_y=2;
	sprintf(board[4][6].text,"M{77}");
	
	board[4][9].type=S;
	board[4][9].jump_x=6;
	board[4][9].jump_y=5;
	sprintf(board[4][9].text,"S{44}");
	
	board[3][1].type=M;
	board[3][1].jump_x=6;
	board[3][1].jump_y=2;
	sprintf(board[3][1].text,"M{77}");
	
	board[3][4].type=B;
	board[3][4].jump_x=-1;
	board[3][4].jump_y=-1;
	sprintf(board[3][4].text,"  B  ");
	
	board[3][7].type=S;
	board[3][7].jump_x=1;
	board[3][7].jump_y=4;
	sprintf(board[3][7].text,"S{52}");
	
	board[2][2].type=M;
	board[2][2].jump_x=2;
	board[2][2].jump_y=3;
	sprintf(board[2][2].text,"S{68}");
	
	board[2][5].type=M;
	board[2][5].jump_x=7;
	board[2][5].jump_y=1;
	sprintf(board[2][5].text,"M{83}");
	
	board[2][8].type=T;
	board[2][8].jump_x=-1;
	board[2][8].jump_y=-1;
	sprintf(board[2][8].text,"  T  ");
	
	board[1][1].type=M;
	board[1][1].jump_x=3;
	board[1][1].jump_y=0;
	sprintf(board[1][1].text,"M{94}");
	
	board[1][5].type=P;
	board[1][5].jump_x=-1;
	board[1][5].jump_y=-1;
	sprintf(board[1][5].text,"  P  ");
	
	board[1][8].type=B;
	board[1][8].jump_x=-1;
	board[1][8].jump_y=-1;
	sprintf(board[1][8].text,"  B  ");
	
	board[0][2].type=T;
	board[0][2].jump_x=-1;
	board[0][2].jump_y=-1;
	sprintf(board[0][2].text,"  T  ");
	
	board[0][7].type=S;
	board[0][7].jump_x=1;
	board[0][7].jump_y=2;
	sprintf(board[0][7].text,"S{72}");
	
	board[0][8].type=S;
	board[0][8].jump_x=5;
	board[0][8].jump_y=4;
	sprintf(board[0][8].text,"S{56}");
	
}


void print_board(block board[][10]){/*I print the assigned board*/
	int i,j;
	for(i=0;i<10;i++){/*I generate nested loop for the print all indexes*/
		for(j=0;j<10;j++){
			if(i==0&&j==9){/*for the finish's printing*/
				printf("100{Finish}");
			}
			else if(i==9&&j==9){/*for the start's printing*/
				printf("1{Start}");
			}
			else if(board[i][j].type!=num){/* for the T,M,S,P,B's printing*/
				printf("%s",board[i][j].text);
			}
			else if(board[i][j].data<10){/* for the one digit number's printing*/
				printf("  %d  ",board[i][j].data);
			}
			else /*for the normal data number's printing*/
				printf(" %d  ",board[i][j].data);
		}
	printf("\n\n");
	}
}

int dice_f(){/*for the changing for all loop's cycle.I made dice function*/
	return (rand()%6)+1;
}

int single_player(block board[][10],int data,int *ct,int ctp){/*this functions provides us single player's game moves*/
	int i,j,x,y,dice,temp;
	
	dice=dice_f();/*I determine the dice value with using dice_f and add my parameter data*/
	data=data+dice;
	
	for(y=0;y<10;y++){/*I find the new data's x and y*/
		for(x=0;x<10;x++){
			if(board[y][x].data==data){
				i=y;
				j=x;
			}
		}
	}
	ctp++;/*ctp is for printing counter(it is change in every loop cycle)*/
	(*ct)++;/* (*ct) is for the memorize maximum count*/
	
	if(data>100){/*for the finish recursion*/
		data=data-dice;
		single_player(board,data,ct,ctp);
		
	}
	else if(data!=100){/*for conditions*/
		if(board[i][j].type==M||board[i][j].type==S){
			data=board[board[i][j].jump_y][board[i][j].jump_x].data;
			single_player(board,data,ct,ctp);
			
		
		}
		else if(board[i][j].type==P){
			data=data-dice;
			single_player(board,data,ct,ctp);
			
		
		}
		else if(board[i][j].type==B){
			data=data+5;
			single_player(board,data,ct,ctp);
			
			
		}
		else if(board[i][j].type==T){
			data=data-5;
			single_player(board,data,ct,ctp);
			
		
		}
		else{
			single_player(board,data,ct,ctp);
			
		}
	}
	else if(data==100){
		printf("\ndata:%d\ndice:%d\ncounter:%d\n ",data,dice,ctp);
		return *ct;/*if data==100 memorize the counter*/
		
	} 
	printf("\ndata:%d \ndice:%d \ncounter:%d\n",data,dice,ctp);
	
	return *ct;
}

void two_player(block board[][10],int data,int *ct,int ctp){/*this function is two player's game*/
	
	int player1,player2;
	printf("\n**player1's game**\n");
	player1=single_player(board,data,ct,ctp);
	printf("\n**player2's game**\n");
	player2=single_player(board,data,ct,ctp);
	if(player1<player2){/*fewer one is win this game*/
		printf("\nPLAYER 1 WİN.\nPlayer 1's counter is:%d\nPlayer 2's counter is:%d",player1,player2);
	}
	else if(player1>player2){
		printf("\nPLAYER 2 WİN.\nPlayer 2's counter is:%d\nPlayer 1's counter is:%d",player2,player1);
	} 
}





	

int main(){
	int ct=0;
	srand(time(NULL));
	block board[10][10];
	init_board(board);
	printf("***PRINT BOARD***\n\n");
	print_board(board);
	printf("\n***SINGLE PLAYER FUNCTION***\n");
	printf("\ncounter:%d",single_player(board,1,&ct,0));
	printf("\n***TWO PLAYER FUNCTION***\n");
	two_player(board,1,&ct,0);

	
}