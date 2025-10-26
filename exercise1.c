/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

//#include "taylor_sine.h"
#include <math.h>
/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */

long long int factorial(int x){
    long long int sum = 1;
    for(int i = x;i>0;i--){
        sum = sum * i;
    }
    return sum;
}

double power(double x,int y){
    double sum = x;
    
    for(int i = 1;i<y;i++){
        sum = sum * x;
    }
    return sum;
}

double taylor_sine(double x, int n) {
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series
    double sum = x;
    for(int i = 1;i<n;i++){
        if(i%2){
            sum = sum - power(x,i*2+1)/factorial(i*2+1);
        }
        else{
            sum = sum + power(x,i*2+1)/factorial(i*2+1);
        }
    }
    
    return sum; // placeholder - replace with your implementation
}


