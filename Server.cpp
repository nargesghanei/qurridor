#include <iostream>
#include <vector>
#include "httplib.h"
#include "board.h"
#include "client.h"
using namespace std;
using namespace httplib;

int main()
{
    Server srv;
    int num_of_players;
    vector <clint> players;
    cout << "Enter number of players (2 or 3 or 4):  " ;
    //input number of players in the game (2 or 3 or 4)
	cin >> num_of_players ;

    board build_board(num_of_players);
    build_board.print_board();

    srv.Post("/login", [&](const Request &req, Response &res)
    {
        /*
        inline MultipartFormData Request::get_file_value(const char *key) const {
        auto it = files.find(key);
        if (it != files.end()) { return it->second; }
        return MultipartFormData();
        }
        */
		const auto& file = req.get_file_value("Login");
		clint pl;
		pl.name = file.content;
        players.push_back(pl);
		pl.key = char( players.size() + 64 ) ;
        cout <<"Player joined !"<<endl<<"name is: "<<pl.name<<endl<<"key : "<<pl.key<<endl;
	});

    srv.Post("/turn", [&](const Request &req, Response &res)
    {
		bool flag = req.has_file("Turn");
		const auto& file = req.get_file_value("Turn");
        cout<<build_board.print_board();
        res.set_content(build_board.print_board(), "Success");
	});

    srv.listen("localhost", 8080);
}