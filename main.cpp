#include<iostream>
#include<fstream>
#include<map>
#include <dlfcn.h>
#include <stdlib.h>
#include "template.h"
#include  "utils.h"

using namespace std;

int main (){

    int lines ;
    print_message("Enter No. Of Productions you want to add: ");
    cin>>lines;
    int cur_line = 0 ;
    print_message("Enter Productions (lines separated)\n");
    while( cur_line< lines){
        // input line 
        string line;
        cin>>line;
        // generate production template for  current lines
        generate_template(line); // defined in template.h
        cur_line++;
    }

    
    // save program 
    ofstream f ( "lib_temp.cpp" );
    f<<get_template(); // get dynamically generated program
    f.close();

    print_message("Successfully Generated Parser Program\n");

    // create library
    system ( "g++ -fPIC  -o  libtemp.so -shared lib_temp.cpp" );

    // load library
    void * handle;
    void (*func) (const char *);

    handle = dlopen("./libtemp.so",RTLD_LAZY);
     if (!handle) {
        /* fail to load the library */
        fprintf(stderr, "Error:ii %s\n", dlerror());
        return EXIT_FAILURE;
    }

    *(void **) (&func) = dlsym(handle,"start");
    if( !func ) {
         fprintf(stderr, "Error: u %s\n", dlerror());
        dlclose(handle);
        return EXIT_FAILURE;
    }
    

    char loop ='y';
    while(loop == 'y'){
        print_message("Enter String You Want To Parse: \n");
        string input ;
        cin>>input;
        // convering string to char *
        char *input_c;
        input_c = &input[0];


        // calling library function 
        func(input_c);

        // loop termination 
        print_message(" Do You want to Continue:(y/n):");
        cin>>loop;
    }



    // closeing the library
    dlclose(handle);

}

