// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print_start()
{
    std::cout << "Start message!... wait for 5 seconds..." << std::endl;
}

void print_end(const boost::system::error_code& /*e*/)
{
    std::cout << "... Done!" << std::endl;
}

int main()
{
    boost::asio::io_context io;

    print_start();
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.async_wait(&print_end);

    io.run();

    return 0;
}