#include<iostream>
#include "mysqrt.h" 

double mysqrt(double value){
    std::cout<<"custom Implementation"<<std::endl;
    if(value<=0){
        return 0;
    }
    else{
        double approx = value;  // Initial guess
        double betterApprox = (approx + value / approx) / 2.0;
    
        while (std::abs(approx - betterApprox) > 0.00001) { // Precision threshold
            approx = betterApprox;
            betterApprox = (approx + value / approx) / 2.0;
        }   
        return betterApprox;
    } 
    
}