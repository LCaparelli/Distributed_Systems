#ifndef EPDSID2_LOGGER_H
#define EPDSID2_LOGGER_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sstream>
#include <ctime>

class Logger {
public:
    void write_to_log(std::string log_entry);
    void flush_logs_to_file();

private:
    std::stringstream buffer;
    std::ofstream log_file;
    pthread_mutex_t log_mutex;
    std::string get_timestamp();
};

#endif //EPDSID2_LOGGER_H
