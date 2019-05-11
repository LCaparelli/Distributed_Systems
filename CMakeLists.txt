cmake_minimum_required(VERSION 3.14)
project(epDSID2)

set(CMAKE_CXX_STANDARD 14)

add_executable(epDSID2 ServerEndpoint.cpp socket/Socket.cpp socket/Socket.h socket/ServerSocket.cpp socket/ServerSocket.h model/AccountModel.cpp service/AccountService.cpp service/AccountService.h)