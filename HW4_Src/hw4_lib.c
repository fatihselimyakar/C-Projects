/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include<stdio.h>

/*this function calculates the f's integral*/
double integral(double f(double x), double xs, double xe, double delta){
    /*I use the math formula:"lim(delta)*sum(1 to n)(xs+(k*delta)/n)*/
    int i,n;
    double sum=0;/*it is the sum*/
    n=(xe-xs)/delta;/*from delta=(b-a)/n*/
    for(i=1;i<n;i++){
        sum=sum+delta*f(xs+delta*i);
        /*I gathered the fields of small squares.*/
    }
    printf("\nintegral=%f",sum);
    return sum;
}

/*this function calculates the f's double integrals !!(dydx)!!*/
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){
    /*I use the midpoint rule.Actually it is the same method to finding integral but It provides integration with x and y*/
    int i,n,n2,j;
    double sum1=0;
    n=(xe-xs)/delta;/*from delta=(b-a)/n* for x*/
    n2=(ye-ys)/delta;/*from delta=(b-a)/n* for y*/
    for(j=1;j<n2;j++){/*integration for y*/
        for(i=1;i<n;i++){/*integration for x*/
            sum1=sum1+f(xs+delta*i,ys+delta*j)*delta*delta;
            /*I gathered the volume of small squares.*/
        }
        
    }
    printf("\ndouble integral=%f",sum1);
    return sum1;
}

/*this function finds the f's numeric derivatives*/
int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
    /*first derivative coming from the given formula:(f(x+eps)-f(x-eps))/(2*eps)*/
    *d1=(f(x+eps)-f(x-eps))/(2*eps);
    /*second derivative coming from the given formula:(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps)*/
    *d2=(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);
    /*for divided by 0*/
    if(eps==0){
        return -1;
    }
    else
        return 1;
}

/*This function is compare actual derivative and numeric derivative*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
    double der1,der2;
    derivatives(f,x,eps,&der1,&der2);/*I calculate the f(x)'s first numeric derivative(der1) and f's second numeric derivative(der2)*/
    *e1=d1(x)-der1;/*d1(x) is given function that is f(x)'s actual first derivative and e1 is variation of d1(x) and der1*/
    printf("\nnumeric derivative=%f actual derivative=%f",der1,d1(x));
    *e2=d2(x)-der2;/*d2 is given function that is f's actual second derivative and e2 is variation of d2(x) and der2*/
    printf("\nnumeric second order derivative=%f actual second order derivative=%f",der2,d2(x));
    /*for the absolute value*/
    if(*e1<0){
        *e1=*e1*(-1);
    }
    if(*e2<0){
        *e2=*e2*(-1);
    }
    return 0;
}

    

/*This function finding the roots of f(x) function by the Newton's method.I found taking root here in the middle of the beginning and the end of the initial value.*/
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
    double der1,der2,x0=1/*in this value is mid value*/,x_temp,eps=0.001,error;
    int i;
    for(i=1;i<=4;i++){
        error=2;/*I set the 2 the error because the program should enter the loop*/
        while(error>0.0000001||error<-0.0000001){/*if the error is too small the loop will end*/
            /*Newton's method applying*/
            derivatives(f,x0,eps,&der1,&der2);
            x_temp=x0;
            x0=x0-f(x0)/der1;
            error=x_temp-x0;
        }
        if(i==1){/*To assign x1 to a first value*/
            *x1=x0;
            x0=-2147483648;/*in this part I initialize the too small number because of end point at the next loop part*/
        }
        else if(i==2){/*To assign x2 to a second value*/
            *x2=x0;
            x0=2147483648;/*in this part I initialize the big number because of beginning point at the next loop part*/
        }
        else if(i==3){/*To assign x3 to a third value*/
            *x3=x0;
        }
        else if(i==4){/*To assign x4 to a forth value*/
            *x4=x0;
        }
        
    }
    return 0;
}
