#include "../httplib.h"
#include <iostream>

int main(void)
{
    httplib::Client cli("localhost", 8080);

    if (auto res = cli.Get("/hiii")) {
        if (res->status == 200) {
            std::cout << res->body << std::endl;
        }
    }
    else {
        auto err = res.error();
    }
}
