# sdf2root
Converting SDF file generated by EPOCH to ROOT file format.  
This converter needs ROOT and CMake.  

## How to install  
cmake .  
make  
sudo make install  

## How to use  
sdf2root "options" "Input SDF file name"  
options:  
-a: all information (mesh and macro particle)  
-m: all mesh information  
-p: all macro particle  
