#include<iostream>
#include <string>
#include<stdlib.h>
#include<TutorialConfig.h>
int main(){
    std::cout<<Tutorial1_VERSION_MAJOR <<std::endl;
    std::cout<<Tutorial1_VERSION_MINOR <<std::endl;
    char str[] = "5672345";
    int var=std::stod(str); // c++10 standard it return the error code
    long int var2 = std::atol(str); //c++98 standard
    std::cout<<var2<<" hello there! "<<var<<std::endl;
    return 0;
}