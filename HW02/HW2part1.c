#include<stdio.h>
#include<stdlib.h>


/*I declare the menu statements in this function*/
int menu(int std_ct){
        printf("\n--------------------------------------\n");
        printf("Student Score Calculator Menu For %d Student\n",std_ct);
        printf("1)Most Succesfull Student\n");
        printf("2)Most Unsuccesfull Student\n");
        printf("3)Letter Grade Statistics\n");
        printf("4)Calculate Average\n");
        printf("5)Show All Data\n");

    return 0;
}

/*In this funtion I seperate by letter grade and then I print these.*/
int ltr_grd(int grade){
        
        if(grade<60&&grade>=0)
            printf("letter grade:F");
        if(grade<70&&grade>=60)
            printf("letter grade:D");
        if(grade<80&&grade>69)
            printf("letter grade:C");
        if(grade<90&&grade>79)
            printf("letter grade:B");
        if(grade<=100&&grade>=90)
            printf("letter grade:A");
    
    return 0;
        
}

int main(){
    srand(40);
    int std_ct,i,num,sum=0.0,max=0,min=100,SC/*selection from menu*/,a_ct=0,b_ct=0,c_ct=0,d_ct=0,f_ct=0,min_ct,max_ct;
    printf("Enter student count:");
    scanf("%d",&std_ct);
    printf("\n");
    /*In these loops first I checked the range*/
    if(std_ct>=3&&std_ct<=50){
        /*In this loop I produced random numbers.And then I writed "if else" to find out how many people have taken letter grades.After I calculate sum for average.And the finally I find max and min.*/
        for(i=0;i<std_ct;i++){
            
            num=rand()%101;
            printf("%d ",num);
            
            if(num<60&&num>=0)
                f_ct++;
            else if(num<70&&num>=60)
                d_ct++;
            else if(num<80&&num>69)
                c_ct++;
            else if(num<90&&num>79)
                b_ct++;
            else if(num<=100&&num>=90)
                a_ct++;
            
            sum+=num;
            
            if(num<min){
                
                min=num;
                min_ct=i+1;
            
            }
            
            if(num>max){
                
                max=num;
                max_ct=i+1;
            
            }
        }
    }
   
    /*if the number of students is not within this range the program warn and again asks to student count*/
    else{
        while(std_ct<3||std_ct>50){
            
            printf("Not in range!\n");
            
            printf("Enter student count:");
            scanf("%d",&std_ct);
            printf("\n");
            
            if(std_ct>=3&&std_ct<=50){
        
                for(i=0;i<std_ct;i++){
            
                    num=rand()%101;
                    printf("%d ",num);
            
                    if(num<60&&num>=0)
                        f_ct++;
                    else if(num<70&&num>=60)
                        d_ct++;
                    else if(num<80&&num>69)
                        c_ct++;
                    else if(num<90&&num>79)
                        b_ct++;
                    else if(num<=100&&num>=90)
                        a_ct++;
            
                    sum+=num;
            
                    if(num<min){
                
                        min=num;
                        min_ct=i+1;
            
                    }
            
                    if(num>max){
                
                        max=num;
                        max_ct=i+1;
            
                    }
                }
            }
        }
    }

    
    /*And the finally I print the menu and user select 1,2,3,4 or 5 and If user wants to exit menu, select -1. To sum up these while loop and within these are to print the values I found above by the user selection.*/
    while(1){
        
        menu(std_ct);/*printf the menu when I prapared*/
        
        scanf("%d",&SC);
        printf("\n                    Make selection:%d\n",SC);
        
        switch(SC){
            case 1:
                
                printf("\nMost Succesfull Student\n");
                printf("\nindex:%d",max_ct);
                printf("\nScore:%d\n",max);
                ltr_grd(max);
                break;
                
            case 2:
                
                printf("\nMost Unuccesfull Student\n");
                printf("\nindex:%d",min_ct);
                printf("\nScore:%d\n",min);
                ltr_grd(min);
                break;
                
            case 3:
               
                printf("\n%d students gets 'A'",a_ct);
                printf("\n%d students gets 'B'",b_ct);
                printf("\n%d students gets 'C'",c_ct);
                printf("\n%d students gets 'D'",d_ct);
                printf("\n%d students gets 'F'",f_ct);
                break;
                
            case 4:
                /*I divided by one because I have to use double numbers for average calculate*/
                printf("\nThe average of %d student:%.2f",std_ct,((sum/1.0)/(std_ct/1.0)));
                break;
                
            case 5:
                
                printf("\nMost Succesfull Student\n");
                printf("\nindex:%d",max_ct);
                printf("\nScore:%d\n",max);
                ltr_grd(max);
            
                printf("\n\n");
            
                printf("\nMost Unuccesfull Student\n");
                printf("\nindex:%d",min_ct);
                printf("\nScore:%d\n",min);
                ltr_grd(min);
                   
                printf("\n\n");
                   
                printf("\n%d students gets 'A'",a_ct);
                printf("\n%d students gets 'B'",b_ct);
                printf("\n%d students gets 'C'",c_ct);
                printf("\n%d students gets 'D'",d_ct);
                printf("\n%d students gets 'F'",f_ct);
            
                printf("\n\n");
            
                printf("The average of %d student:%.2f",std_ct,((sum/1.0)/(std_ct/1.0)));
                break;
            case -1:
                return 0;
            /*if user don't choose 1,2,3,4,5,-1 the program warn.*/
            default:
                printf("False Selection!!!!\n");
        
        }
            
    }
return 0;   
}
    


    
    
    
    
    
    
   
    
    
    
    
    
