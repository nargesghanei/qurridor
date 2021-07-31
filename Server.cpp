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
            players.push_back(pl);
			string plyr_st = "";
			res.set_content(plyr_st, "Success");
            now++;
		}
	});
    
    srv.Post("/turn", [&](const Request &req, Response &res)
    {
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
		bool flag = req.has_file("Move");
		if(!flag)
        {
			res.set_content("error!", "Error");
		}
		else if(flag)
        {
			const auto& file = req.get_file_value("Move");
			string where=file.content_type;
            if(pl.key=='A')
            {
                cur=cur_A;
            }
            else if(pl.key=='B')
            {
                cur=cur_B;
            }
            else if(pl.key=='C')
            {
                cur=cur_C;
            }
            else if(pl.key=='D')
            {
                cur=cur_D;
            }
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
            if(pl.key=='A')
            {
                cur_A=cur;
            }
            else if(pl.key=='B')
            {
                cur_B=cur;
            }
            else if(pl.key=='C')
            {
                cur_C=cur;
            }
            else if(pl.key=='D')
            {
                cur_D=cur;
            }
		}
    });

    srv.Post("/wall", [&](const Request &req, Response &res)
    {
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
            cout<<endl<<file.filename<<endl<<file.content_type<<endl;
            build_board.brd[wl1]=build_board.brd[wl2]="****";
        }
	});

    srv.listen("localhost", 8080);
}