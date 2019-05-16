cmake_minimum_required(VERSION 3.14)
project(epDSID2)

include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 14)

add_executable(epDSID2 ServerEndpoint.cpp socket/Socket.cpp socket/Socket.h socket/ServerSocket.cpp socket/ServerSocket.h model/AccountModel.cpp service/AccountService.cpp service/AccountService.h ServerEndpoint.h socket/SocketException.h socket/ClientSocket.h socket/ClientSocket.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(epDSID2 Threads::Threads)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")