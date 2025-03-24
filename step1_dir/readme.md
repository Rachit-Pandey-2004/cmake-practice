#
# Exercise 1 - Building a Basic Project :

>cmake file support both upper and lower case commands though we gonna use everything in lower case

- Create **CMakeLists.txt** file
- Start with declaring minimum cmake version using **cmake_minimun_required()**
- To start the project we use **project()** to set the project name *(must be declared after cmaek version declaration )*
- at last declare the executable command using **add_executable()**



1. get to the root dir where *CMakeLists.txt* is stored 
2. mkdir **build**
3. cd **build**
4. Then run **cmake ..**
5. then run **make** command
6. then run the project with the name declare of the project

## Project Directory structure:

project_root/        
│-- CMakeLists.txt   
│-- tutorial.cxx *or src/tutorial.cxx*     
│-- build/           
files (recommended)

### CMakeLists.txt :
```ruby
cmake_minimum_required(VERSION 3.10)
project(Tutorial1)
add_executable(Tutorial1 tutorial.cpp)
```
### tutorial.cpp :
```ruby
#include<iostream>
int main(){
    std::cout<<"hello there!"<<std::endl;
    return 0;
}
```
#
# Exercise 2 - Specifying the C++ Standard :
* cmake has some special variable which are created behind the scene and had some meaning in the build process and can be explicitly define to infunce the build by using the **"CMAKE_variableName"**
* we use set to define the variabele explicitly.
* set -> sets normal, cache or environment variable \
***set(variable value)***
> don't define a variable in cxx code with "cmake_"

## Goal :
To add a feature that requires minimum C++11.\
*Use variable CMAKE_CXX_STANDARD and CMAKE_CXX_STANDARD_REQUIRED*.

- CMAKE_CXX_STANDARD → Defines the C++ version to be used.
- CMAKE_CXX_STANDARD_REQUIRED → Ensures that the compiler must support the specified standard.
### CMakeLists.txt :
```ruby
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(Tutorial1)
add_executable(Tutorial1 tutorial.cpp)
```
### tutorial.cpp :
```ruby
#include<iostream>
#include <string> // for stod
#include<stdlib.h> // for atol
int main(){
    std::string str="123";
    char str1[] = "5672345";
    int var=std::stod(str); // c++10 standard it return the error code
    long int var2 = std::atol(str1); //c++98 standard
    std::cout<<var2<<" hello there! "<<var<<std::endl;
    return 0;
}
```
#
# Exercise 3 -Adding a Version Number and Configured Header File :
>we use this method to avoid duplication and make a single file of truth

In this exercise we will define th eproject verion to the meta header of the .cxx file
### Use Case :
- Avoid hardcoding the version in multiple places ```(CMakeLists.txt and source code)```.
- Use **configure_file()** to generate a header file dynamically, keeping the version consistent.
- Make *CMakeLists.txt* the single source of truth for project details

### Step to follow :
#### 1. Define version in CMakeLists.txt -
Use **project** to define project name and version \
project(```Tutorial1 VERSION 1.0```)

This will define variables:
- Tutorial1_VERSION_Major = 1
- Tutorial1_VERSION_Minor = 0
### 2. Generate a header file using ```configure_file()```
We use a template header file and change the variable in it using the *configure_file()* function.\
```configure_file(TutorialConfig.h.in TutorialConfig.h)```
- TutorialConfig.h.in is an input template 
- TutorialConfig.h is an output which is generated after changing the version values in the input template.
### 3. Generate the Header file template :
This contain placeholder value that will be replaced by CMake
>TutorialConfig.h.in
```ruby
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```
### 4. Defining where to search for header to be moudified :
For this we use **target_include_directories** command in cmakelists.txt
```ruby
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
```
here we define :
- Target (executable target) = Tutorial1 ~ this mean we are specifying the include directories of the target executable.
- Scope (public, private and interface)
- Path (cmake variable ```"${PROJECT_BINARY_DIR}"```) that store the build directory path. 
> use target_include_directories command after add_executable() because first create the target then only we can link it.

#### Scope in cmake :
- PRIVATE : The include directory is used only while compiling this target.
- PUBLIC : The include directory is used for this target and for anything that depends on it.
- INTERFACE : The include directory is only propagated to dependencies, but not used by this target itself.

### CMakeLists.txt :
```ruby
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(Tutorial1 VERSION 1.0)
configure_file(TutorialConfig.h.in TutorialConfig.h)
add_executable(Tutorial1 tutorial.cpp)
target_include_directories(Tutorial1 PUBLIC "${PROJECT_BINARY_DIR}")
```
### tutorial.cpp :
```ruby
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
```