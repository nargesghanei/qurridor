#include <iostream>
#include "httplib.h"
#include "client.h"
#include "board.h"
using namespace std;
using namespace httplib;

clint player;

static int i=1;

int main()
{
	Client cli("localhost", 8080);
	cout << "Please Enter your name : " ;
	cin >> player.name;
    
    /*
    struct MultipartFormData {
        std::string name;
        std::string content;
        std::string filename;
        std::string content_type;
    };
    */
	MultipartFormDataItems data = { {"Login", player.name,"",""} };

    if(auto res = cli.Post("/login", data))
    {
		if((res -> body) == "Invalid Request")
        {
			cout << "Login faild ! " << endl;
			return 0;
		}
		else
        {
			cout << "You joined the game successfully !"<< endl;
		}
	}
	else
    {
		cout << "Something went wrong ! please check the connection to server ." << endl;
	}
    
	bool game_is_runing=true;
	string choice="";
	while(game_is_runing)
	{
		string turn = player.name ;
		string bord="";
		data = { {"Turn",turn,"",""} };
		if(auto res = cli.Post("/turn",data))
		{
			bord = res -> body;
		}
		cout << "It's your turn "<<player.name<<endl<<"Please choose : " << endl;
		cout <<bord;
		cout << "Do you want to move(m) or put a wall(w) ? " << endl;
		cin >> choice ;

	}
}