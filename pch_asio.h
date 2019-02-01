#ifndef __PCH_ASIO__
#define __PCH_ASIO__

    #ifdef ASIO_STANDALONE
    #include <asio.hpp>
    using asio::io_service;
    using asio::ip::address;
    using asio::ip::tcp;
    #endif//ASIO_STANDALONE

#endif //__PCH_ASIO_