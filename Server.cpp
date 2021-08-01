#include <iostream>
#include <vector>
#include "httplib.h"
#include "board.h"
#include "client.h"
using namespace std;
using namespace httplib;


vector <clint> players;

int now=1;
int plays_now=1 ;

int main()
{
    Server srv;
    int num_of_players;
    clint pl;
    
    int cur_A=31 , cur_B=871, cur_C=441 , cur_D=461 , cur;
    cout << "Enter number of players (2 or 3 or 4):  " ;
    //input number of players in the game (2 or 3 or 4)
	cin >> num_of_players ;

    board build_board(num_of_players);

    srv.Post("/login", [&](const Request &req, Response &res)
    {
        bool entered = req.has_file("Login");
		if(!entered || now > num_of_players)
        {
			res.set_content("error !", "Error");
		}
        /*
        inline MultipartFormData Request::get_file_value(const char *key) const {
        auto it = files.find(key);
        if (it != files.end()) { return it->second; }
        return MultipartFormData();
        }
        */
       else
       {
            
			const auto& file = req.get_file_value("Login");
			pl.name = file.content;
			cout <<"Player joined !"<<endl<<"name is: "<<pl.name<<endl<<"key : "<<now<<endl;
            pl.key=now;
            players.push_back(pl);
			string plyr_st = "";
			res.set_content(plyr_st, "Success");
            now++;
		}
	});
    
    srv.Post("/turn", [&](const Request &req, Response &res)
    {
        if (build_board.brd[451]!="    ")
        {
            res.set_content("game is finished ", "Success");
        }
		bool flag = req.has_file("Turn");
		if(!flag)
        {
			res.set_content("error ! ", "Error");
		}
		else
        {
			const auto& file = req.get_file_value("Turn");
			res.set_content(build_board.print_board(), "Success");
		}
        
	});

    
    

    srv.Post("/move", [&](const Request &req, Response &res)
    {
        cout<<"player: "<<plays_now<<endl;

        if(plays_now==1) cur=cur_A;
        else if(plays_now==2) cur=cur_C;
        else if(plays_now==3) cur=cur_D;
        else if(plays_now==0) cur=cur_B;
        

		bool flag = req.has_file("Move");
		if(!flag)
        {
			res.set_content("error!", "Error");
		}
		else if(flag && build_board.brd[451]=="    ")
        {
			const auto& file = req.get_file_value("Move");
			string where=file.content_type;
        
            cout<<"from "<<cur<<" to "<<where<<endl;
            if(where=="u" && build_board.brd[cur-84]=="    " /*&& !(21<=cur<=41)*/)
            {
                string temp=build_board.brd[cur-84];
                build_board.brd[cur-84]=build_board.brd[cur];
                build_board.brd[cur]=temp;
                cur=cur-84;
                plays_now++;
            }
            else if(where=="d" && build_board.brd[cur+84]=="    " /* && !(861<=cur<=881)*/)
            {
                string temp=build_board.brd[cur+84];
                build_board.brd[cur+84]=build_board.brd[cur];
                build_board.brd[cur]=temp;
                cur=cur+84;
                plays_now++;
            }
            else if(where=="r" && build_board.brd[cur+2]=="    " && !((cur+1)%84==21))
            {
                string temp=build_board.brd[cur+2];
                build_board.brd[cur+2]=build_board.brd[cur];
                build_board.brd[cur]=temp;
                cur=cur+2;
                plays_now++;
            }
            else if(where=="l" && build_board.brd[cur-2]=="    " && !((cur%84)==21))
            {
                string temp=build_board.brd[cur-2];
                build_board.brd[cur-2]=build_board.brd[cur];
                build_board.brd[cur]=temp;
                cur=cur-2;
                plays_now++;
            }
            else
            {
                res.set_content("Invalid movement !", "Error");
            }
            if(plays_now-1==1) cur_A=cur;
            else if(plays_now-1==2) cur_C=cur;
            else if(plays_now-1==3) cur_D=cur;
            else if(plays_now-1==0) cur_B=cur;
            plays_now = plays_now % num_of_players;

            //res.set_content(build_board.print_board(), "Success");
            
		}
        else if(build_board.brd[451]!="    ")
        {
            res.set_content("game is finished ", "Over");
            srv.stop();
            return ;
        }
    });

    srv.Post("/wall", [&](const Request &req, Response &res)
    {
        cout<<"player: "<<plays_now<<endl;

		bool flag = req.has_file("Wall");
		if(!flag)
        {
			res.set_content("error!", "Error");
		}
		else if(flag)
        {
			const auto& file = req.get_file_value("Wall");
            string w1=file.filename;
			string w2=file.content_type;
            int wl1,wl2;
            wl1=stoi(w1);wl2=stoi(w2);
            if(((wl1==wl2+2 || wl1==wl2-2 || wl1==wl2+84 || wl1==wl2-84) && (21<=wl1<=881) && (21<=wl2<=881) && (wl1!=451) && (wl2!=451) && build_board.brd[wl1]=="    " && build_board.brd[wl2]=="    "))
                build_board.brd[wl1]=build_board.brd[wl2]="****";
            else
            {
                res.set_content("Invalid places to put the wall !", "Error");
                plays_now--;
            }
        }
        plays_now++;
        plays_now = plays_now % num_of_players;

        //res.set_content(build_board.print_board(), "Success");
	});
    
    /*
    for(int i=1 ; i<=num_of_players ; i++)
    {
        if(i==1) cur=cur_A;
        else if(i==2) cur=cur_B;
        else if(i==3) cur=cur_C;
        else if(i==4) cur=cur_D;
        srv.Post("/move", [&](const Request &req, Response &res)
        {
            bool flag = req.has_file("Move");
		    if(!flag)
            {
			    res.set_content("error!", "Error");
		    }
		    else if(flag)
            {
		    	const auto& file = req.get_file_value("Move");
			    string where=file.content_type; 
                if(where=="u")
                {
                    string temp=build_board.brd[cur-84];
                    build_board.brd[cur-84]=build_board.brd[cur];
                    build_board.brd[cur]=temp;
                    cur=cur-84;
                }   
                else if(where=="d")
                {
                    string temp=build_board.brd[cur+84];
                    build_board.brd[cur+84]=build_board.brd[cur];
                    build_board.brd[cur]=temp;
                    cur=cur+84;
                }
                else if(where=="r")
                {
                    string temp=build_board.brd[cur+2];
                    build_board.brd[cur+2]=build_board.brd[cur];
                    build_board.brd[cur]=temp;
                    cur=cur+2;
                }
                else if(where=="l")
                {
                    string temp=build_board.brd[cur-2];
                    build_board.brd[cur-2]=build_board.brd[cur];
                    build_board.brd[cur]=temp;
                    cur=cur-2;
                } 
            }

            if(i==1) cur_A=cur;
            else if(i==2) cur_B=cur;
            else if(i==3) cur_C=cur;
            else if(i==4) cur_D=cur;
        });
    }*/

    
    

    srv.listen("localhost", 8080);
}