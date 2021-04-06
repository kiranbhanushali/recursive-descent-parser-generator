
#include<iostream>

using namespace std;
string line = "";
char cur =line[0];
int pos = 0 ;


int match(char t)
{
    if (cur == t) {
        pos ++;
        cur =line[pos]; 
    }
    else
        printf("Error at pos %d",pos);
    return 0;
}
 void E () {
     int temp_pos = pos ;
  if( cur== 'a'){match('a');match('b');
                if( cur=='$'){
                    return ;
                }
            }
                pos = temp_pos;
                cur = line[pos];
             if( cur== 'a'){match('a');match('b');match('c');
                if( cur=='$'){
                    return ;
                }
            }

        }
    
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
