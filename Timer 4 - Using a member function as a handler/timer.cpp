// timer.cpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class printer
{
public:
    // construct with zero
    printer(boost::asio::io_context& io)
            : timer_(io, boost::posix_time::seconds(1)),
              count_(0)
    {
        timer_.async_wait(boost::bind(&printer::print, this));
    }

    // destruct then done
    ~printer()
    {
        std::cout << "Final count is " << count_ << std::endl;
    }

    void print()
    {
        std::cout << "Start count is " << count_ << std::endl;


        // while?
        if (count_ < 5)
        {
            std::cout << count_ << std::endl;
            ++count_;

            timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
            timer_.async_wait(boost::bind(&printer::print, this));
        }
    }

private:
    boost::asio::deadline_timer timer_;
    int count_;
};

int main()
{
    boost::asio::io_context io;
    printer p(io);
    io.run();

    return 0;
}