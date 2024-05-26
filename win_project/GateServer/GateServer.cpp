﻿#include <iostream>
#include <json/json.h>
#include <json/value.h>
#include <json/reader.h>
#include "CServer.h"
int main()
{
    try {
        unsigned short port = static_cast<unsigned short>(8080);
        net::io_context ioc{ 1 };
        boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
        //信号集异步等待
        signals.async_wait([&ioc](const boost::system::error_code& error, int signal_number) {
            if (error) {
                return;
            }
            ioc.stop();//CTRL c
        });
        std::make_shared<CServer>(ioc, port)->Start();
        ioc.run();
    }
    catch(std::exception const & e){
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}