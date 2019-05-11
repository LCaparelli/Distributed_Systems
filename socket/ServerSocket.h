//
// Created by darocha on 11/05/19.
//

#ifndef EPDSID2_SERVERSOCKET_H
#define EPDSID2_SERVERSOCKET_H
// Definition of the ServerSocket class
#include "Socket.h"


class ServerSocket : private Socket
{
 public:

  ServerSocket ( int port );
  ServerSocket (){}
  virtual ~ServerSocket();

  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;

  void accept ( ServerSocket& );

};

#endif
