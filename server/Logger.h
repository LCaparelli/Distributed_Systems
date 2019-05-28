//
// Created by danil on 27/05/2019.
//

#ifndef EPDSID2_LOGGER_H
#define EPDSID2_LOGGER_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sstream>

class Logger {
public:
    void write_to_log(std::string log_entry);


private:
    std::stringstream buffer;
    std::ofstream log_file;
    pthread_mutex_t log_mutex;
    void flush_to_file();
    int get_stream_size(std::stringstream& ss);


};

#endif //EPDSID2_LOGGER_H
