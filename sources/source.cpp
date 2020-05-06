//
// Created by dmoon on 3/9/20.
//
#include <utility>

#include "header.h"

My_client::My_client(Context *io, std::string uname):sock_(*io), _username(std::move(uname)){}

void My_client::start_work() {
    try {
        sock_.connect(ep);
        working = true;
        cycle();
    }
    catch(boost::system::system_error & err) {
        working = false;
        std::cout << "client terminated" << std::endl;
    }
}

void My_client::cycle() {
    sock_.write_some(boost::asio::buffer("login " + _username + '\n'));
    reader();
    while (working) {
        std::string msg;
        std::getline (std::cin, msg);
        sock_.write_some(boost::asio::buffer(msg + "\n"));
        reader();
    }
}

//void My_client::set_uname(std::string new_name) {
//    _username = std::move(new_name);
//}

void My_client::reader() {
    sym_read = sock_.read_some(boost::asio::buffer(_buff));
    ans_analysis();
}
void My_client::ans_analysis() {
    std::string msg(_buff, 0, sym_read);
    std::cout << msg;
    if (msg.find("ping ") == 0) ping_ok(msg);
    else if (msg.find("clients ") == 0) cli_list(msg);
    else if (msg.find("timed_out") == 0) {working = false;}

}
void My_client::ping_ok(const std::string& msg) {
    std::string str(msg, 5);
    if (str == "client_list_changed\n") ask_list();
}

void My_client::ask_list() {
    write(sock_,boost::asio::buffer("ask_clients\n"));
    reader();
}

void My_client::cli_list(const std::string& msg) {
    std::string str(msg, 8);
}