cmake_minimum_required(VERSION 3.14)
project(epDSID2)

set(CMAKE_CXX_STANDARD 14)

add_executable(epDSID2 server/ServerEndpoint.cpp socket/Socket.cpp socket/Socket.h socket/ServerSocket.cpp socket/ServerSocket.h server/model/AccountModel.cpp server/service/AccountService.cpp server/service/AccountService.h server/ServerEndpoint.h socket/SocketException.h server/Logger.cpp server/Logger.h)
add_executable(client client/main.cpp socket/ClientSocket.cpp socket/Socket.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(epDSID2 Threads::Threads)
target_link_libraries(client Threads::Threads)