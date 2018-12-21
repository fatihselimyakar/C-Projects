#include<stdio.h>

int main(){
    int num,num2,digit,counter=0,fir_dig,sec_dig,th_dig,for_dig,fif_dig;
    /*I get the number with user*/
    printf("Enter the number:");
    scanf("%d",&num);
    
    /*I defined the num2 variable because the num variable will change after the loop.*/
    num2=num;
    
    /*basicly I use the math rule: I get the mod then I find the first digit, and for pass the second digit at the and of the loop I divide 10. And I repeat these events.In the final I assign 5 different variable by my counter because in the end  of the program I will(have to) print reverse numbers.*/
    while(num>0){
        digit=num%10;
        counter++;
        if(counter==5){
            fif_dig=digit;
        }
        else if(counter==4){
            for_dig=digit;
        }
        else if(counter==3){
            th_dig=digit;
        }
        else if(counter==2){
            sec_dig=digit;
        }
        else if(counter==1){
            fir_dig=digit;
        }
        num=num/10;
    }
    /*In this if-else statements I provide upper and lower bounds from incoming the homework-pdf by num2, and I provide intermediate bounds for number of digits.And depending on these conditions my variables are printed.*/
    if(num2>=10000&&num2<98760){
        printf("\nthe fifth digit:%d",fif_dig);
        printf("\nthe forth digit:%d",for_dig);
        printf("\nthe third digit%d",th_dig);
        printf("\nthe second digit:%d",sec_dig);
        printf("\nthe first digit:%d\n",fir_dig);  
    }
    else if(num2>=1000&&num2<10000){
        printf("\nthe forth digit:%d",for_dig);
        printf("\nthe third digit%d",th_dig);
        printf("\nthe second digit:%d",sec_dig);
        printf("\nthe first digit:%d\n",fir_dig); 
    }
    else if(num2>=100&&num2<1000){
        printf("\nthe third digit%d",th_dig);
        printf("\nthe second digit:%d",sec_dig);
        printf("\nthe first digit:%d\n",fir_dig);
    }
    else if(num2>23&&num2<100){
        printf("\nthe second digit:%d",sec_dig);
        printf("\nthe first digit:%d\n",fir_dig);
    }
    /*if user do not follow these conditions, the program warn user.*/
    else{
        printf("the number must be between 23 and 98760\n");
    }
    
return 0;

}
