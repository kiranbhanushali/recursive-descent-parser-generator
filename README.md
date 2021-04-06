# Overview

This program **generates** the recursive descet parser and executes in current system. 

# Idea

For example grammer  E->bA. 
its recursive parser algo looks like 
```
E()
{
    if (l == 'i') {
        match('b');
        A()
        return success;
    }
    else 
	     return failure;
}


```

**This is static .
if we have N productions we have to write N functions and corrosponding RHS.
In this program we give input as grammer rules( productions) 
and program will automatically generates this functions . and using dlfcn library we can run generated programms run time**



##  Run locally 
### Requirements 
* G++ compiler 

### Steps 
* clone repo via git clone 
	```
	https://github.com/kiranbhanushali/recursive-descent-parser-generator.git
	```
* locate directory and  run make in terminal  to compile 
		```
			make
			```
* for running run make run command 
	``` make run ```


