#include "template.h"
#include "utils.h"
#include<string>
#include<iostream>
#include<map>

using namespace std;



// include part 
string include_part = R"(
#include<iostream>

using namespace std;
extern string line = "";
extern char cur =line[0];
extern int pos = 0 ;

)";



// match function  part 
string match_function =R"(
int match(char t)
{
    if (cur == t) {
        pos ++;
        cur =line[pos]; 
    }
    else
        printf("Error at pos %d",pos);
    return 0;
})";


// output_funct part
string output_funct=R"(
extern "C" void start (const char *s) {
    line = s;
    cur = line[pos];
    E();

    if( cur == '$' ){
        cout<<"Parsing Done\n";
    }else{
       cout<< "Error Occured During Parsing \n";
    }

}
)";




string funct_declaration ="";
// for storing function names already in the funct_declaration
map<char,int> function_declaration_mp;


// generates the template for the given input string 
// e.g  ip: E->ab|A
// then it will generate one function corrospnig to the recusive descemt parser 
void generate_template(string line){

    string function_template_begin = R"(
 void )" ;
    function_template_begin+=line[0] ;
    function_template_begin+= R"( () {
    )";
    
    string function = " int temp_pos = pos ;\n ";
    int if_stmt = 1 ,open_bracket = 1;
    for( int i =3;i<line.size();i++){
        if( line[i] =='|') {
            function += R"(
                if( cur=='$'){
                    return ;
                }
            )";
            if(open_bracket>1) {
                function+='}';
                open_bracket--;
            }
            
            function+=R"(
                pos = temp_pos;
                cur = line[pos];
            )";
            if_stmt = 1;
            continue;
        }
        
        // null symbol
        if(line[i]=='^'){
            continue;
        }
        
       if( isTerminal(line[i])){
            // matches statement 
            
            if( if_stmt) {
                function+= " if( cur== " ;
                function+=  "'" ;
                function+= line[i] ;
                function +=  "'){"
                                "match('" ;
                function+= line[i];
                function+= "');";
                if_stmt = 0 ; 
                open_bracket++;
            }
            else{
                function+= "match('" ;
                function+= line[i];
               function += "');";
            }
        }else{
            function +=  line[i];
            function += "();";
            if(!function_declaration_mp[line[i]]){
                funct_declaration+= "void ";
                funct_declaration+= line[i];
                funct_declaration+="();\n";
                function_declaration_mp[line[i]] = 1;
            }
        }

    }
    if(open_bracket>1)
    {
        open_bracket--;
        function+=R"(
                if( cur=='$'){
                    return ;
                }
            )";
        while(open_bracket--)
        function+="}\n";
    }


    string end_block = R"(
        }
    )";


    output_funct = function_template_begin + function + end_block + output_funct;

}


// returns the generated program 
string get_template(){

    return include_part + match_function + funct_declaration + output_funct;

}
