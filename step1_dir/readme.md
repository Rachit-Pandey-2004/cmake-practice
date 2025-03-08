# Exercise 1 - Building a Basic Project :

>cmake file support both upper and lower case commands though we gonna use everything in lower case

- Create **CMakeLists.txt** file
- Start with declaring minimum cmake version using **cmake_minimun_required()**
- To start the project we use **project()** to set the project name *(must be declared after cmaek version declaration )*
- at last declare the executable command using **add_executable()**

## To execute :

1. get to the root dir where *CMakeLists.txt* is stored 
2. mkdir **build**
3. Then run **cmake ..**
4. then run **make** command
4. then run the project with the name declare of the project

## Project Directory structure:

project_root/        
│-- CMakeLists.txt   
│-- tutorial.cxx *or src/tutorial.cxx*     
│-- build/           
files (recommended)


# Exercise 2 - Specifying the C++ Standard :



>[guide Link:](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#exercise-1-building-a-basic-project)