#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Forest{/*in this part I defined structures forest and botanist*/
	int width,height,flower_x,flower_y;
	char **map;
}Forest;

typedef struct Botanist{
	int coord_x,coord_y,water_bottle_size;
}Botanist;

void init_game(Forest *forest,Botanist *botanist){/*in this function I read the .txt and then initialize the game board*/ 
	int i,j;
	char trash;
	FILE *game;
	game=fopen("init.txt","r");
	/*I get the numbers 3 digit for bottle size,height and width*/
	fscanf(game,"%d",&botanist->water_bottle_size);
	fscanf(game,"%d%c%d%c",&forest->width,&trash,&forest->height,&trash);
	/*I generate the dynamic char array with read width and height information*/
	forest->map =(char **)calloc((forest->height),sizeof(char *));
    forest->map[0]=(char *)calloc((forest->width)*(forest->height),sizeof(char));
	for(i=0;i<forest->height;i++){
		forest->map[i]=(*forest->map+(forest->width)*i);
	}
	
	/*I read the folder and add my dynamic char array*/
	for (i = 0; i <(forest->height);i++){
		for (j = 0; j <(forest->width*2);j++){
			if(j%2==0){/*for the commas(commas are only odd width numbers,and I use this information)*/
				fscanf(game,"%c",&forest->map[i][j/2]);
				if(forest->map[i][j/2]=='B'){/*For the finding 'B' coordinates*/
					botanist->coord_x=j/2;
					botanist->coord_y=i;
				}
				else if(forest->map[i][j/2]=='F'){/*For the finding 'F' coordinates*/
					forest->flower_x=j/2;
					forest->flower_y=i;
				}
			}
			else
				fscanf(game,"%c",&trash);/*for the jumping other array elements*/
		}
    }
	
    fclose(game);
}

void print_map(Forest forest){/*In this function I print the my gaming board*/
	int i,j;
	for (i = 0; i < (forest.height); i++){
		for (j = 0; j < (forest.width); j++){
			printf(" %c",forest.map[i][j]);  
		}
		printf("\n");
	}	
}

void search(Forest forest,Botanist botanist){/*In this function includes recursive function for gaming*/
	int x=botanist.coord_x,y=botanist.coord_y;
	int r;
	if(forest.flower_x==botanist.coord_x&&forest.flower_y==botanist.coord_y){/*the ending condition(If the botanist finds flower)*/
		print_map(forest);
		printf("\nI have found it on (%d,%d)",forest.flower_y,forest.flower_x);
	}
	else if(botanist.water_bottle_size==0){/*the ending condition 2(If the botanist's bottle size equal to 0)*/
		print_map(forest);
		printf("\nHelp! I am on (%d,%d)",botanist.coord_y,botanist.coord_x);
	}
	else{/*recursion part*/
		while(x==botanist.coord_x&&y==botanist.coord_y){/*for ıf the coordinate doesnt change redetect the random value*/
			r=rand()%4;
			/*if botanist is next to the flower*/
			if(forest.map[botanist.coord_y][botanist.coord_x+1]=='F'||forest.map[botanist.coord_y][botanist.coord_x-1]=='F'||forest.map[botanist.coord_y+1][botanist.coord_x]=='F'||forest.map[botanist.coord_y-1][botanist.coord_x]=='F'){
				forest.map[botanist.coord_y][botanist.coord_x]=' ';
				botanist.coord_x=forest.flower_x;
				botanist.coord_y=forest.flower_y;
				botanist.water_bottle_size--;

			}/*if random is 0.for the go to the right side*/
			else if(r==0&&forest.map[botanist.coord_y][botanist.coord_x+1]==' '&&botanist.coord_x!=forest.width-1){
				forest.map[botanist.coord_y][botanist.coord_x+1]='B';
				forest.map[botanist.coord_y][botanist.coord_x]=' ';
				botanist.coord_x=botanist.coord_x+1;
				botanist.water_bottle_size--;

			}
			/*if random is 1.for the go to the left side*/
			else if(r==1&&forest.map[botanist.coord_y][botanist.coord_x-1]==' '&&botanist.coord_x!=0){
				forest.map[botanist.coord_y][botanist.coord_x-1]='B';
				forest.map[botanist.coord_y][botanist.coord_x]=' ';
				botanist.coord_x=botanist.coord_x-1;
				botanist.water_bottle_size--;

			}/*if random is 2.for the go to the bottom side*/
			else if(r==2&&forest.map[botanist.coord_y+1][botanist.coord_x]==' '){
				if(botanist.coord_y+1!=forest.height-1||(botanist.coord_x==forest.flower_x&&botanist.coord_y+1==forest.flower_y-1)){
					forest.map[botanist.coord_y+1][botanist.coord_x]='B';
					forest.map[botanist.coord_y][botanist.coord_x]=' ';
					botanist.coord_y=botanist.coord_y+1;
					botanist.water_bottle_size--;
				}

			}/*if random is 3.for the go to the up side*/
			else if(r==3&&forest.map[botanist.coord_y-1][botanist.coord_x]==' '&&botanist.coord_y!=0){
				forest.map[botanist.coord_y-1][botanist.coord_x]='B';
				forest.map[botanist.coord_y][botanist.coord_x]=' ';
				botanist.coord_y=botanist.coord_y-1;
				botanist.water_bottle_size--;

			}
		}
		/*for the recursivity*/
		search(forest,botanist);
		
	}
	
}

int main(){
	srand(time(NULL));
	Forest forest;
	Botanist botanist;
	init_game(&forest,&botanist);
	print_map(forest);/*first map printing*/
	printf("\n\nSearching...\n\n");
	search(forest,botanist);
}