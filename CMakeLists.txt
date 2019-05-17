cmake_minimum_required(VERSION 3.14)
project(epDSID2)

set(CMAKE_CXX_STANDARD 14)

add_executable(epDSID2 ServerEndpoint.cpp socket/Socket.cpp socket/Socket.h socket/ServerSocket.cpp socket/ServerSocket.h model/AccountModel.cpp service/AccountService.cpp service/AccountService.h ServerEndpoint.h socket/SocketException.h socket/ClientSocket.h socket/ClientSocket.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(epDSID2 Threads::Threads)