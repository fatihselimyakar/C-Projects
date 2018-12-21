#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int power(x,y){/*This function allow me get the kind of number's power*/
    int i;
    for(i=1;i<y;i++){
        x*=x;
    }
    return x;
}

/*this function get the number like scanf but between mini and maxi*/
int getInt(int mini,int maxi){
    int num;
    scanf("%d",&num);
    while(num<mini||num>maxi){/*if the number is not in the range this error generate*/
        printf("Please enter between %d and %d:",mini,maxi);
        scanf("%d",&num);
    }

return num;
    
}

/*this function generated a random value between min and max*/
int numberGeneratorBetweenRange(int min,int max){
    int num;
    do{
        num=rand()%(max+1);/*this part provide the upper bound.I used to max+1 because of to include max value*/
    }
    while(num<min);/*this part provide the lower bound*/

return num;

}

/*this function is game of horse*/
void horseRacingGame(){
    int i,j,noh/*number of horse*/,slc/*horse selection*/,num,min=100,min_ct,min2_ct,min2=100,ct=0;
    noh=numberGeneratorBetweenRange(3,5);/*I generate number of horse randomly between 3 and 5*/
    printf("Number of Horse:%d\n",noh);
    printf("Horse Number:");
    slc=getInt(1,noh);/*I get the user's choose between 1 and number of horse*/
    printf("Racing starts...\n");
    for(i=1;i<=noh;i++){/*in this part(for loop) I generate horse's time values and testing these*/
        
        printf("Horse %d:",i);
        num=numberGeneratorBetweenRange(10,20);/*I generate horse's time values*/
        
        for(j=0;j<num;j++){/*I print this values with for loop*/
            printf("-");
        }
        printf("\n");
        if(num<=min){/*I calculate the final minimum value for "No winner" issue*/
                
            min=num;
            min_ct=i;/*I calculate index of min*/
            
        }
        if(num<min2){/*I calculte the first minimum value for "No winner" issue*/
                
            min2=num;
            min2_ct=i;/*I calculate index of min2*/
        }
    }
    if(min2==min&&min2_ct!=min_ct){/*if these final and first minimum value are the same and their indexes are different, 
    I will print Now winner*/
            printf("No winner!\n");
    }
    else if(slc==min_ct){/*if user's selection=minimum's index user wins*/
        printf("You Win!\n");
    }
    else{/*print loser and winner*/
        printf("You lose!Winner is Horse %d\n",min_ct);
    }
}

void triangleOfSequences(){/*I draw like a basic triangle(2 for loop)*/
    int value,i,j,k;
    value=numberGeneratorBetweenRange(2,10);/* I generate a random number between 2 and 10 for row's number*/
    for(i=1;i<=value;i++){/*normal triangle draw nested loop*/
        k=i;/*for increase the column*/
        for(j=0;j<i;j++){
            printf("%d ",k);/*print the value*/
            k=k+i;/*for the increase righter side for column*/
        }
    printf("\n");
    }
}

void countOccurrence(){
    int bigNumber,searchNumber,ct=0,digit,digit_test,dct=0/*digit counter*/;
    printf("Big Number:");/*I get the big number(positive integer)*/
    bigNumber=getInt(1,2147483647);
    printf("Search Number:");/*I get the search number(positive integer)*/
    searchNumber=getInt(1,2147483647);
    digit_test=searchNumber;/*for the searchNumber's digit number I assigned searchNumber to digit_test*/
    while(digit_test>0){
        digit_test=digit_test/10;
        dct++;/*dct is the searchNumber's digit number*/
    }
    while(bigNumber>0){
        digit=bigNumber%(power(10,dct));/*for the find all of digit I calculate the mod*/
        if(digit==searchNumber){/*If the mod=searchNumver count occurrence*/
            ct++;
        }
        bigNumber=bigNumber/10;/*for the pass lefter digit*/
        
    }
    printf("Occurrence:%d\n\n",ct);
    
}

void menu(){/*this function is the user's selection*/
    int slc,ctrl=1;
    do{
        printf("\n1.Horse Racing Game\n");
        printf("2.Occurence Counter\n");
        printf("3.Triangle of Sequences\n");
        printf("0.Exit\n");
        scanf("%d",&slc);/*I used to scanf because If I used to getInt,I have never restart the menu*/
        printf("\n");
        switch(slc){
            case 1:
                horseRacingGame();
                break;
            case 2:
                countOccurrence();
                break;
            case 3:
                triangleOfSequences();
                break;
            case 0:/*if ctrl=0 program close*/
                ctrl=0;
                break;
            default:/*if user enter the different value(don't 0,1,2,3) the menu restart*/
                ctrl=1;
        }
        
        
    }
    while(ctrl!=0);/*the control value is not zero program continue*/
}

int main(){
    srand(time(NULL));/*for the random values*/
    menu();
    
    return 0;    
    
}