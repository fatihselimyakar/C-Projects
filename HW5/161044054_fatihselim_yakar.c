#include<stdio.h>
#include<stdlib.h>/*I use this one for absolute value function*/

typedef enum {white_man, black_man, white_king, black_king, empty} 
piece;

typedef enum {white = 10, black = 20} 
player;

void init_board(piece board[][8]){/*in this function I generate the dama board*/
    int i,j;
    piece b[8][8]={/*I initialize the dama table in function*/
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
        {black_man,black_man,black_man,black_man,black_man,black_man,black_man,black_man},
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
        {white_man,white_man,white_man,white_man,white_man,white_man,white_man,white_man},
        {empty,empty,empty,empty,empty,empty,empty,empty}
    };
    for(i=0;i<8;i++){/*I fill my piece type board[][]array in initialized dama board*/
        for(j=0;j<8;j++){
            board[i][j]=b[i][j];
        }
    }
    
}
void display_board(piece board[][8]){/*in this function I print the input dama board*/
    int i,j;
    printf("\n");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]==empty){
                printf(" -");
            }
            else if(board[i][j]==white_man){
                printf(" w");
            }
            else if(board[i][j]==black_man){
                printf(" b");
            }
            else if(board[i][j]==white_king){
                printf(" W");
            }
            else if(board[i][j]==black_king){
                printf(" B");
            }
        }
    printf("\n");
    }
}

int capture(piece board[][8], int x, int y, player p){/*in this function provides man's capturing(then I use this function in move function)*/ 
    int i,j;
    if(p==white&&board[x][y]==white_man){/*if player is white and chosing is white_man,program is looking ahead to the right and to the left if there is an opponent and opponent's beside is empty it eats it.*/
        if((board[x-1][y]==black_man||board[x-1][y]==black_king)&&board[x-2][y]==empty){/*for ahead*/
            board[x-1][y]=empty;
            board[x-2][y]=white_man;
            board[x][y]=empty;
        }
        else if((board[x][y+1]==black_man||board[x][y+1]==black_king)&&board[x][y+2]==empty){/*for to the right*/
            board[x][y+1]=empty;
            board[x][y+2]=white_man;
            board[x][y]=empty;
        }
        else if((board[x][y-1]==black_man||board[x][y-1]==black_king)&&board[x][y-2]==empty){/*for to the left*/
            board[x][y-1]=empty;
            board[x][y-2]=white_man;
            board[x][y]=empty;
        }
    }
    else if(p==black&&board[x][y]==black_man){/*if player is black and chosing is black_man,program is looking ahead to the right and to the left if there is an opponent and opponent's beside is empty it eats it.*/
        if((board[x][y+1]==white_man||board[x][y+1]==white_king)&&board[x][y+2]==empty){/*for to the right*/
            board[x][y+1]=empty;
            board[x][y+2]=black_man;
            board[x][y]=empty;
        }
        else if((board[x+1][y]==white_man||board[x+1][y]==white_king)&&board[x+2][y]==empty){/*for ahead*/
            board[x+1][y]=empty;
            board[x+2][y]=black_man;
            board[x][y]=empty;
        }
        else if((board[x][y-1]==white_man||board[x][y-1]==white_king)&&board[x][y-2]==empty){/*for to the left*/
            board[x][y-1]=empty;
            board[x][y-2]=black_man;
            board[x][y]=empty;
        }
    }
    
    return 1;
}

int captureKing(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){/*in this function provides King's capturing and moving(then I use in move function)*/
    int i,j;
    if(p==black&&board[from_x][from_y]==black_king){/*if the choosing black king and player black*/
       if(from_x-to_x==0&&board[to_x][to_y]==empty){
		   if(from_y-to_y>0){/*for to the left side capturing*/
              for(i=from_y-1;i>to_y;i--){
                  if(board[from_x][i]!=empty&&(board[from_x][i]==white_man||board[from_x][i]==white_king)){
                      board[from_x][i]=empty;
                  }
              } 
           }
           else if(from_y-to_y<0){/*for to the right side capturing*/
              for(i=from_y+1;i<to_y;i++){
                  if(board[from_x][i]!=empty&&(board[from_x][i]==white_man||board[from_x][i]==white_king)){
                      board[from_x][i]=empty;
                  }
              } 
           }
        }
        else if(from_y-to_y==0&&board[to_x][to_y]==empty){
           if(from_x-to_x>0){/*for to the top side capturing*/
              for(i=from_x-1;i>to_x;i--){
                  if(board[i][from_y]!=empty&&(board[i][from_y]==white_man||board[i][from_y]==white_king)){
                      board[i][from_y]=empty;
                  }
              } 
           }
           else if(from_x-to_x<0){/*for to the bottom side capturing*/
              for(i=from_x+1;i<to_x;i++){
                  if(board[i][from_y]!=empty&&(board[i][from_y]==white_man||board[i][from_y]==white_king)){
                      board[i][from_y]=empty;
                  }
              } 
           }
        }
        board[from_x][from_y]=empty;/*for the black king's moving*/
        board[to_x][to_y]=black_king;
    }
    else if(p==white&&board[from_x][from_y]==white_king){/*if the player is white and choosing is white_king*/
        if(from_x-to_x==0&&board[to_x][to_y]==empty){
           if(from_y-to_y>0){
              for(i=from_y-1;i>to_y;i--){/*for the left side capturing*/
                  if(board[from_x][i]!=empty&&(board[from_x][i]==black_man||board[from_x][i]==black_king)){
                      board[from_x][i]=empty;
                  }
              } 
           }
           else if(from_y-to_y<0){/*for the right side capturing*/
              for(i=from_y+1;i<to_y;i++){
                  if(board[from_x][i]!=empty&&(board[from_x][i]==black_man||board[from_x][i]==black_king)){
                      board[from_x][i]=empty;
                  }
              } 
           }
        }
        else if(from_y-to_y==0&&board[to_x][to_y]==empty){
           if(from_x-to_x>0){/*for the top side capturing*/
              for(i=from_x-1;i>to_x;i--){
                  if(board[i][from_y]!=empty&&(board[i][from_y]==black_man||board[i][from_y]==black_king)){
                      board[i][from_y]=empty;
                  }
              } 
           }
           else if(from_x-to_x<0){/*for the bottom side capturing*/ 
              for(i=from_x+1;i<to_x;i++){
                  if(board[i][from_y]!=empty&&(board[i][from_y]==black_man||board[i][from_y]==black_king)){
                      board[i][from_y]=empty;
                  }
              } 
           }
        }
        board[from_x][from_y]=empty;/*for the white king's moving*/
        board[to_x][to_y]=white_king;
    }
    

    return 1;
}


int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){/*for the capturing and moving function*/
    if(!(((p==white)&&((board[from_x][from_y]==white_man)||(board[from_x][from_y]==white_king)))||((p==black)&&((board[from_x][from_y]==black_man)||(board[from_x][from_y]==black_king))))){/*checking to see if they are the right man.*/
        printf("ERROR! You dont choose this man\n");
        return -1;
        
    }
    else if((board[to_x][to_y]!=empty)||((board[from_x][from_y]==white_man&&to_x-from_x>0)||(board[from_x][from_y]==black_man&&to_x-from_x<0))){/*it checks to come back and choosing the empty space.*/
        printf("ERROR! You dont turn back!!or this isnt empty\n");
        return -2;
    }
    else if(p==black&&(board[from_x][from_y]==black_king)&&((abs(from_x-to_x)<=8&&from_y-to_y==0)||(from_x-to_x==0&&abs(from_y-to_y<=8)))){/*if the player black and choosing is black_king,this function provides right and left up and down to eat and move.*/
        captureKing(board,from_x,from_y,to_x,to_y,black); 
        
        return 1;
    }
    else if(p==white&&(board[from_x][from_y]==white_king)&&((abs(from_x-to_x)<=8&&from_y-to_y==0)||(from_x-to_x==0&&abs(from_y-to_y)<=8))){/*if the player white and choosing is white_king,this function provides right and left up and down to eat and move.*/
        captureKing(board,from_x,from_y,to_x,to_y,white); 
        
        return 1;
    }
    
    else if(p==white&&(board[from_x][from_y]!=white_king)&&((abs(from_x-to_x)<=2&&from_y-to_y==0)||(from_x-to_x==0&&abs(from_y-to_y)<=2))){/*for the white man's capture and moving*/
        if(to_x!=0){ 
            if(abs(from_x-to_x)==2||abs(from_y-to_y)==2){/*if from and to distance is 2,choosing man is eat any black man*/
                capture(board,from_x,from_y,white);
            }
            else{/*else this white man only move*/
                board[to_x][to_y]=board[from_x][from_y];
                board[from_x][from_y]=empty;
                
            }
        }
        else{/*for switching white king*/
            if(abs(from_x-to_x)==2){/*for capturing again*/
                capture(board,from_x,from_y,white);
                board[to_x][to_y]=white_king;
                board[from_x][from_y]=empty;
            }
            else{
             	/*for only moving*/
                board[to_x][to_y]=white_king;
                board[from_x][from_y]=empty;
                
            }
        }
        
            
        return 1;
    }
    else if(p==black&&(board[from_x][from_y]!=black_king)&&((abs(from_x-to_x)<=2&&from_y-to_y==0)||(from_x-to_x==0&&abs(from_y-to_y)<=2))){/*for the black man's capture and moving*/
        if(to_x!=7){
            if(abs(from_x-to_x)==2||abs(from_y-to_y)==2){/*if from and to distance is 2,choosing man is eat any white man*/
                capture(board,from_x,from_y,black); 
            }
            else{
                board[to_x][to_y]=board[from_x][from_y];/*else this black man only move*/
                board[from_x][from_y]=empty;
           
            }
        }
        else{/*for switching black king*/
            if(abs(from_x-to_x)==2||abs(from_y-to_y)==2){
                capture(board,from_x,from_y,black);
                board[to_x][to_y]=black_king;
                board[from_x][from_y]=empty;
            }
            else{/*for only moving*/
                board[to_x][to_y]=black_king;
                board[from_x][from_y]=empty;
            }
        }
            
        return 1;
    }
    
    else{
        return 0;
    }
    
}

int check_end_of_game(piece board[][8]){/*this funtion checks and of game*/
    int i,j,ctw=0,ctb=0;
    for(i=0;i<8;i++){/*it scans the board array and if whites equal 0,blacks win else the opposite occurs*/
        for(j=0;j<8;j++){
            if(board[i][j]==white_man||board[i][j]==white_king){
                ctw++;
            }
            else if(board[i][j]==black_man||board[i][j]==black_king){
                ctb++;
            }
        }
    }
    if(ctw==0){
        return black;/*black player wins*/
    }
    else if(ctb==0){
        return white;/* white player wins*/
    }
    else{
        return -1;
    }
}

void sample_game_1(){/*It is the random game function*/
    piece board[8][8];
    init_board(board);
    display_board(board);
    move(board,5,0,4,0,white);
    display_board(board);
    move(board,2,0,3,0,black);
    display_board(board);
    capture(board,4,0,white);
    move(board,2,0,0,0,white);
    display_board(board);
    move(board,2,1,3,1,black);
    display_board(board);
    move(board,0,0,0,1,white);
    display_board(board);
    move(board,2,3,3,3,black);
    display_board(board);
    move(board,0,1,4,1,white);
    display_board(board);
    move(board,5,3,4,3,white);
    display_board(board);
    move(board,3,3,5,3,black);
    display_board(board);
    move(board,5,3,7,3,black);
    display_board(board);
    move(board,5,4,4,4,white);
    display_board(board);
    move(board,2,4,3,4,black);
    display_board(board);
    move(board,4,4,2,4,white);
    move(board,2,4,0,4,white);
    display_board(board);
    move(board,7,3,7,0,black);
    display_board(board);
    move(board,4,1,4,2,white);
    display_board(board);
    move(board,7,0,4,0,black);
    display_board(board);
    move(board,4,2,3,2,white);
    display_board(board);
    move(board,2,2,4,2,black);
    display_board(board);
    move(board,5,2,3,2,white);
    display_board(board);
    move(board,1,2,2,2,black);
    display_board(board);
    move(board,3,2,1,2,white);
    display_board(board);
    move(board,1,3,1,1,black);
    display_board(board);
    move(board,5,6,4,6,white);
    display_board(board);
    move(board,4,0,5,0,black);
    display_board(board);
    move(board,4,6,3,6,white);
    display_board(board);
    move(board,5,0,5,6,black);
    display_board(board);
    move(board,5,7,5,5,white);
    display_board(board);
    move(board,2,6,4,6,black);
    display_board(board);
    move(board,0,4,0,6,white);
    display_board(board);
    move(board,2,5,3,5,black);
    display_board(board);
    move(board,0,6,5,6,white);
    display_board(board);
    move(board,2,7,3,7,black);
    display_board(board);
    move(board,5,5,4,5,white);
    display_board(board);
    move(board,3,5,5,5,black);
    display_board(board);
    move(board,5,6,5,1,white);
    display_board(board);
    move(board,5,1,0,1,white);
    display_board(board);
    move(board,3,7,4,7,black);
    display_board(board);
    move(board,0,1,0,7,white);
    display_board(board);
    move(board,1,5,2,5,black);
    display_board(board);
    move(board,0,7,5,7,white);
    display_board(board);
    move(board,2,5,3,5,black);
    display_board(board);
    move(board,5,7,4,7,white);
    display_board(board);
    move(board,3,5,4,5,black);
    display_board(board);
    move(board,4,7,4,1,white);
    display_board(board);
    if(check_end_of_game(board)==white){/*at the end checks winner*/
        printf("WHİTE PLAYER WİNS\n");
    }
    else if(check_end_of_game(board)==black){
        printf("BLACK PLAYER WİNS\n");
    }
    printf("\n********SAMPLE GAME 1 END***********\n");
}






void sample_game_2(){/*the gif's function*/
    piece board[8][8]={/* I initialize a new board for the gif*/
        {empty,empty,empty,empty,empty,empty,empty,empty},
        {empty,empty,black_man,black_man,black_man,black_man,empty,empty},
        {empty,black_man,black_man,black_man,black_man,empty,black_man,black_man},
        {black_man,black_man,black_man,empty,empty,black_man,empty,black_man},
        {empty,empty,white_man,white_man,white_man,black_man,white_man,white_man},
        {white_man,white_man,white_man,white_man,white_man,empty,white_man,white_man},
        {empty,empty,white_man,white_man,white_man,white_man,empty,empty},
        {empty,empty,empty,empty,empty,empty,empty,empty}
    };
    display_board(board);
    move(board,5,1,4,1,white);
    display_board(board);
    move(board,3,1,5,1,black);
    display_board(board);
    move(board,4,3,3,3,white);
    display_board(board);
    move(board,4,5,4,3,black);
    display_board(board);
    move(board,4,3,4,1,black);
    display_board(board);
    move(board,3,3,3,1,white);
    display_board(board);
    move(board,3,1,1,1,white);
    display_board(board);
    move(board,1,2,1,0,black);
    display_board(board);
    move(board,5,3,4,3,white);
    display_board(board);
    move(board,5,1,5,3,black);
    display_board(board);
    move(board,5,3,5,5,black);
    display_board(board);
    move(board,5,5,7,5,black);
    display_board(board);
    move(board,4,3,3,3,white);
    display_board(board);
    move(board,2,3,4,3,black);
    display_board(board);
    move(board,5,6,5,5,white);
    display_board(board);
    move(board,7,5,4,5,black);
    display_board(board);
    move(board,4,6,4,4,white);
    display_board(board);
    move(board,4,4,4,2,white);
    display_board(board);
    move(board,4,2,4,0,white);
    display_board(board);
    move(board,4,0,2,0,white);
    display_board(board);
    move(board,2,0,0,0,white);
    display_board(board);
    printf("\n*******SAMPLE GAME 2 END***********\n");
    
}




int main(){/*I apply in main*/
    sample_game_1();
    sample_game_2();
}