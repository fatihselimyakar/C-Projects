/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>


#include "hw4_lib.h"
#include "hw4_io.h"



/*
** Testing derivative calculations..
**
*/


/*There are using  4 functions for the testing*/
double f(double x) { return (x*x); }
double f2(double x,double y){ return x*x+(y/3); }
double d1(double x) { return 2.0*x; }
double d2(double x) { return 2.0; }
    
/*this function tests the function of compare_derivatives()*/
void test_compare_derivatives() {
	double e1, e2;
	printf("\n\n************COMPARE DERIVATIVES TEST**************");
    compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("\ne1=%f e2=%f\n",e1,e2);
}

/*this function tests the function of integral()*/
void test_integral(){
    printf("\n\n**********INTEGRAL TEST*************");
    integral(f,2,5,0.001);
}

/*this function tests the function of integral2()*/
void test_integral2(){
    printf("\n\n*******DOUBLE INTEGRAL TEST**********");
    integral2(f2,0,1,0,1,0.001);
}

/*this function tests the function of derivatives()*/
void test_derivatives(){
    printf("\n\n***********DERIVATIVES TEST*************");
    double d1, d2;
    derivatives(f,2,0.0001,&d1,&d2);
    printf("\nderivative=%f second order derivative=%f",d1,d2);
}

/*this function tests the functions of polynomial*/
void test_polynomial(){
    printf("\n\n***********POLYNOMİAL TEST**************");
    double a0,a1,a2,a3,a4;
    printf("\n3.degree polynomial");
    read_polynomial3(&a0,&a1,&a2,&a3);
    write_polynomial3(a0,a1,a2,a3);
    printf("\n4.degree polynomial");
    read_polynomial4(&a0,&a1,&a2,&a3,&a4);
    write_polynomial4(a0,a1,a2,a3,a4);
}

/*this function tests the function of find_roots()*/
void test_find_roots(){
    printf("\n\n*********FİND ROOTS TEST*****************");
    double x1,x2,x3,x4;
    find_roots(f,&x1,&x2,&x3,&x4);
    printf("\nRoots are:%f %f %f %f",x1,x2,x3,x4);
}


/*
** main function for testing the functions...
**
*/

/*the main tests(run) all of these functions*/
int main(void) {
	test_compare_derivatives();
    test_integral();
    test_integral2();
    test_derivatives();
    test_polynomial();
    test_find_roots();
	return (0);
} /* end main */
