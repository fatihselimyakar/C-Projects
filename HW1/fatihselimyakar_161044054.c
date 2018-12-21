#include<stdio.h>
#include<math.h>
/*I decide to use Pi with define because I will use one more times Pi.*/
#define PI 3.14

/*I calculate a general circle's area using with standart pi*r^2 formula*/
double circle_area(double radius){
    
    double area;
    area=(PI*(pow(radius,2)));
    return area;
    
}

/*in this function I calculate side1 and side2's 
hypotenuse because I will use in different function again*/
double calc_hypotenuse(int side1, int side2){
    
    double hypotenuse;
    hypotenuse=sqrt(pow(side1,2)+pow(side2,2));
    return hypotenuse;
    
}

/*in this function, the circle's radius is 1/2 of the rectangle's hypotenuse*/
double calc_radius_of_smallest_circle(int side1, int side2){
    
    double radius;
    /*I use 2.0 because I have to convert double to integer*/
    radius=calc_hypotenuse(side1,side2)/2.0;
    return radius;
    
}


double calc_radius_of_largest_circle(int side1, int side2){
    
    double radius;
    /*I use selection(if) because, in calculate I have to use the short side of rectangle*/
    if(side1>side2){
        radius=side2/2.0;
    }
    else{
        radius=side1/2.0;
    }
    return radius;
        
} 

/*In this function I use calc_hypotenuse function in circle_area 
function because the hypotenuse/2 is radius of smallest circle and 
I have to use in circle_area function*/ 
double calc_area_of_smallest_circle(int side1, int side2){
    
    double area;
    area=circle_area(calc_hypotenuse(side1,side2)/2.0);
    return area;
    
}

/*In this function I use ccalc_radius_of_largest_circle function in circle_area 
function*/
double calc_area_of_largest_circle(int side1, int side2){
    
    double area;
    area=circle_area(calc_radius_of_largest_circle(side1,side2));
    return area;
    
}

/*I calculate area of ordinary square by this formula:side^2*/
double calc_area_of_square(int side){
    
    double area;
    area=pow(side,2);
    return area;
    
}


double calc_area_of_smallest_square(int side1, int side2){
    
    double area;
    /*I use selection(if) because, in calculate I have to use the long side of rectangle*/
    if(side1>side2){
        area=calc_area_of_square(side1);
    }
    else{
        area=calc_area_of_square(side2);
    }
    return area;
    
}

double calc_area_of_largest_square(int side1, int side2){
    
    double area;
    /*I use selection(if) because, in calculate I have to use the short side of rectangle*/
    if(side1<side2)
        area=calc_area_of_square(side1);
    else
        area=calc_area_of_square(side2);
    return area;
    
}

/*I include all functions for print the results*/
void display_results( double largest_circle,
                      double largest_square,
                      double smallest_circle,
                      double smallest_square ){
    
    printf("The area of the largest circle that fits inside a rectangle:%.2f\n",largest_circle);
    printf("The area of the largest square that fits inside the rectangle:%.2f\n",largest_square);
    printf("The area of the smallest circle that surrounds the same rectangle:%.2f\n",smallest_circle);
    printf("The area of the smallest square that surrounds the same rectangle:%.2f\n",smallest_square);

}

int main(){
    /*I get the side1 and side2 values from user*/
    int side1,side2;
    printf("Please enter your rectangle's side1:");
    scanf("%d",&side1);
    printf("Please enter your rectangle's side2:");
    scanf("%d",&side2);
    /*I print results by "display_results" function*/
    display_results( calc_area_of_largest_circle(side1,side2),
                     calc_area_of_largest_square(side1,side2),
                     calc_area_of_smallest_circle(side1,side2),
                     calc_area_of_smallest_square(side1,side2) );
    return 0;

}


