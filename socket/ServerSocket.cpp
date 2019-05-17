#include "ServerSocket.h"
#include "SocketException.h"

/* This class provides an abstraction above the socket class, implementing operation only used
 * by sockets in the server */


//constructor, creates the socket, binds it to a port and listens

ServerSocket::ServerSocket ( int port ) {
    if (!Socket::create()) {
        throw SocketException ( "Could not create server socket." );
    }

    if (!Socket::bind(port)) {
        throw SocketException ( "Could not bind to port." );
    }

    if (!Socket::listen()) {
        throw SocketException ( "Could not listen to socket." );
    }

}

ServerSocket::~ServerSocket()
{
}

//abstraction above the send function for easier use
const ServerSocket& ServerSocket::operator << ( const std::string& s ) const {
    if (!Socket::send(s)) {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;

}

//abstraction above the recv function for easier use
const ServerSocket& ServerSocket::operator >> ( std::string& s ) const {
    if (!Socket::recv(s)) {
        throw SocketException ( "Could not read from socket." );
    }
    return *this;
}

bool ServerSocket::accept ( ServerSocket& sock ) {
    if (!Socket::accept(sock)){
        return false;
    }
    return true;
}
