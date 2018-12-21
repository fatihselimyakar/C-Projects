/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include<stdio.h>

/*This function gets the 4 number for degree 3 equation from user*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){
    int x;
    printf("\nplease coeff. degree-3:");
    scanf("%lf",&*a3);
    printf("please coeff. degree-2:");
    scanf("%lf",&*a2);
    printf("please coeff. degree-1:");
    scanf("%lf",&*a1);
    printf("please coeff. degree-0:");
    scanf("%lf",&*a0);
    return 0;
}

/*This function gets the 5 number for degree 4 equation from user*/
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){
    int x;
    printf("\nplease coeff. degree-4:");
    scanf("%lf",&*a4);
    printf("please coeff. degree-3:");
    scanf("%lf",&*a3);
    printf("please coeff. degree-2:");
    scanf("%lf",&*a2);
    printf("please coeff. degree-1:");
    scanf("%lf",&*a1);
    printf("please coeff. degree-0:");
    scanf("%lf",&*a0);
    return 0;
}

/*This function prints the degree 3 equation by the input values from read_polynomial3 datas*/
void write_polynomial3(double a0, double a1, double a2, double a3){
    
    double arr[4]={a3,a2,a1,a0};
    int i;
    
    for(i=0;i<4;i++){/*this for loop is print the array's values in polynomial equations*/
    
        if(i!=3&&arr[i]!=0.0){/*if arr[i]=0 I dont write anything*/
        
            if(arr[i]==1.0){/*if the value=1,I write x(I dont write 1x)*/
            
                if(i==2){/*if i=2(degree 1) print only x*/
                    printf("+x");
                }
                    
                else/*if i!=2(degre is not 1) normal printing*/
                    printf("+x^%d",3-i);
                    
            }
                
            else if(arr[i]==-1.0){/*if the value is negative and -1(I dont write -1x) I write x*/
            
                if(i==2){/*for the degree 1 issue*/
                    printf("-x");
                }
                
                else/*for normal printing*/
                    printf("-x^%d",3-i);
            }
                
            else if(arr[i]>0){/*if the value is positive and >1* such as 2,I print +2x*/
            
                if(i==2){/*for the degree 1 issue*/
                    printf("+%.1fx",arr[i]);
                }
                
                else/*for normal printing*/
                    printf("+%.1fx^%d",arr[i],3-i);
            }
                
            else if(arr[i]<0){/*if the value is negative and <-1 such as -2,I print -2x*/
            
                if(i==2){/*for the degree 1 issue*/
                    printf("%.1fx",arr[i]);/*in this issue I dont use - because  while the negative numbers printing,it printing -(number)*/
                }
                    
                else/*for normal printing*/
                    printf("%.1fx^%d",arr[i],3-i);
            }
        }
            
        else if(arr[i]!=0.0){/*for the printing degree 0 issue*/
        
            if(arr[i]>0){
                printf("+%.1f",arr[i]);/*if the value is positive I use +(number)*/
            }
              
            if(arr[i]<0){
                printf("%.1f",arr[i]);/*if the value is negative I use normal number*/
            }
            
        }
        
    }
    
}

/*This function prints the degree 4 equation by the input values from read_polynomial4 datas*/
void write_polynomial4(double a0, double a1, double a2, double a3, double a4){
    
    double arr[5]={a4,a3,a2,a1,a0};
    int i;
    for(i=0;i<5;i++){/*this for loop is print the array's values in polynomial equations*/
        if(arr[i]!=0.0){/*if arr[i]=0 I dont write anything*/
            
            if(i!=4){/*degree 0 issue*/
                
                if(arr[i]==1.0){/*if the value=1,I write x(I dont write 1x)*/
                
                    if(i==3){/*if i=3(degree 1) print only x*/
                        printf("+x");
                    }
                    
                    else/*if i!=3(degre is not 1) normal printing*/
                        printf("+x^%d",4-i);
                }
                
                else if(arr[i]==-1.0){/*if the value is negative and -1(I dont write -1x) I write x*/
                
                    if(i==3){/*for the degree 1 issue*/
                        printf("-x");
                    }
                    
                    else/*for normal printing*/
                        printf("-x^%d",4-i);
                    
                }
                
                else if(arr[i]>0){/*if the value is positive and >1* such as 2,I print +2x*/
                
                    if(i==3){/*for the degree 1 issue*/
                        printf("+%.1fx",arr[i]);
                    }
                    
                    else/*for normal printing*/
                        printf("+%.1fx^%d",arr[i],4-i);
                }
                
                else if(arr[i]<0){/*if the value is negative and <-1 such as -2,I print -2x*/
                    
                    if(i==3){/*for the degree 1 issue*/
                        printf("%.1fx",arr[i]);/*in this issue I dont use - because  while the negative numbers printing,it printing -(number)*/
                    }
                    
                    else/*for normal printing*/
                        printf("%.1fx^%d",arr[i],4-i);
                }
            }
            
            else{/*for the printing degree 0 issue*/
            
                if(arr[i]>0){/*if the value is positive I use +(number)*/
                    printf("+%.1f",arr[i]);
                }
                
                if(arr[i]<0){/*if the value is negative I use normal number*/
                    printf("%.1f",arr[i]);
                
                }
            
            }
    
        }

    }

}




