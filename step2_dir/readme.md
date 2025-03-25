#
# Exercise 1 -  Creating a Library :
In this excersie we will how to make and add libraries in our project instead of doing everything in a single file we will learn to divide it into sub directories...\
And properly link it to our binay (executable) file.
##
## Aims of doing this exercise :
- Make ur own library for *maths function* which have its own version ```sqrt()``` implementation
- move the library files into sub directories. 
- modify the cmakelists.txt file to link the library to the executable.
- use the library we created instead of ```std::sqrt()```.

##
## Steps To follow : 
### 1. Set the project structure :
```ruby
project_root/
│── CMakeLists.txt
│── tutorial.cxx
│── build/   # (Will be created during build)
│── libraries # (contains our packages)
    │── MathFunctions.h
    │── MathFunctions.cxx
    │── mysqrt.h
    │── mysqrt.cxx
```
### 2. Creating the library ( libraries/CMakeLists.txt ) :
We use ```add_library()``` to create a library
```ruby
add_library(MyPackage MathFunctions.cpp msqrt.cpp)
```
where  MyPackage -> is the library name.\
And msqrt.cpp is custom implementation.

### 3. Adding Directory :
Since the are funx module are inside the libraries directory we need to add it in cmake.\
We will use ```add_subdirectory()``` to link the directories...
```ruby
add_subdirectory(libraries)
```
- This will tell cmake to look inside /libraries for cmake file of are package.
- Build whatever is defined in that directory.

### 4. Link the Package to the Executable file :
After creating our ```libraries``` we need to connect it to our ```main``` program
We will use ```target_link_libraries()``` to link it to the executable.
```ruby
target_link_libraries(Tutorial2 PUBLIC libraries)
```
This will link ```libraries``` library to our executable

### 5. Define Where to find library header
Here we will define where cmake will find ```MathFunctions.h``` header file which is inside /libraries directory\
We will use ```target_include_directories()``` to resolve the include statement ...
```ruby
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/libraries")
```
- ${PROJECT_BINARY_DIR} → The build directory.
- ${PROJECT_SOURCE_DIR}/MathFunctions → The libraries/ folder where MathFunctions.h is located.
### 6. Use the Library in ```tutorial.cxx``` :
