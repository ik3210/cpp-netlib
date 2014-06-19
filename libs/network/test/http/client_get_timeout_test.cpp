
// Copyright 2010 Dean Michael Berris. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MODULE HTTP Client Get Timeout Test
#include <boost/network/include/http/client.hpp>
#include <boost/test/unit_test.hpp>
#include "client_types.hpp"

namespace http = boost::network::http;

BOOST_AUTO_TEST_CASE_TEMPLATE(http_get_test_timeout_1_0, client, client_types) {
    typename client::request request("http://localhost:12121/");
    typename client::response response_;
    client client_;
    boost::uint16_t port_ = port(request);
    typename client::response::string_type temp;
    BOOST_CHECK_EQUAL ( 12121, port_ );
    BOOST_CHECK_THROW ( response_ = client_.get(request); temp = body(response_); , std::exception );
}

BOOST_AUTO_TEST_CASE_TEMPLATE(http_get_test_timeout_with_options, client, client_types) {
    typename client::request request("http://commondatastorage.googleapis.com/cpp-netlib-downloads/0.11.0/cpp-netlib-0.11.0.zip");
    typename client::response response;
    typename client::options options;
    client client_(options.timeout(1));
    typename client::response::string_type temp;
    BOOST_CHECK_THROW ( response = client_.get(request); temp = body(response); , std::exception );
}

#ifdef BOOST_NETWORK_ENABLE_HTTPS

BOOST_AUTO_TEST_CASE_TEMPLATE(https_get_test_timeout_with_options, client, client_types) {
    typename client::request request("https://codeload.github.com/cpp-netlib/cpp-netlib/zip/0.11-devel");
    typename client::response response;
    typename client::options options;
    client client_(options.timeout(1));
    typename client::response::string_type temp;
    BOOST_CHECK_THROW ( response = client_.get(request); temp = body(response); , std::exception );
}

#endif
