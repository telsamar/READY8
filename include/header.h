//
// Created by dmoon on 3/9/20.
//

#ifndef CLI_HEADER_H
#define CLI_HEADER_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/thread/thread.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks.hpp>
#include <string>
//#include <boost/thread/pthread/recursive_mutex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using Endpoint = boost::asio::ip::tcp::endpoint;
using Acceptor = boost::asio::ip::tcp::acceptor;
using Context = boost::asio::io_context;
using Socket = boost::asio::ip::tcp::socket;

const static unsigned PORT_NUM = 8001;
const static unsigned MAX_SYM = 1024;
const static Endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), PORT_NUM);


class My_client{
public:
    My_client(Context *io, std::string uname);
    void start_work();
    void cycle();
    void ping_ok(const std::string& msg);
    void reader();
//    void set_uname(std::string new_name);
    void ans_analysis();
    void ask_list();
    void cli_list(const std::string& msg);
//    std::string get_uname();
//    Socket &get_sock();
private:
    Socket sock_;
    std::string _username;
    char _buff[MAX_SYM];
    unsigned sym_read = 0;
    bool working = false;
};

#endif //CLI_HEADER_H
