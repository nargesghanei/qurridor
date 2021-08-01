#include<iostream>
#include<string>
using namespace std;

struct clint
{
    string name="";
    int key=0;
};
/*
class check
{
    public:
        
        static bool check_valid_movement(int cur , string go)
        {
            if(go=="u")
            {
                if(21<=cur<=41) return false;
            }
            else if(go=="d")
            {
                if(861<=cur<=881) return false;
            }
            else if(go=="r")
            {
                if((cur+1)%84==21) return false;
            }
            else if(go=="l")
            {
                if((cur%84)==21) return false;
            }
            else if(go=="u" || go=="d" || go=="l" || go=="r") return true;
            else {return false;}
        }

        static bool chech_valid_wall(int w1 , int w2)
        {
            if((w1==w2+2 || w1==w2-2 || w1==w2+84 || w1==w2-84) && (21<=w1<=881) && (21<=w2<=881) && (w1!=451) && (w2!=451))  return true;
            else return false;
        }
};
*/