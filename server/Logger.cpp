#include <string>
#include "Logger.h"
#include <iostream>
#include <fstream>

#define LOG_PATH "logs/logs.txt"

void Logger::write_to_log(std::string log_entry) {
    if (log_entry.length() + get_stream_size(buffer) < 1024)
        buffer << log_entry + "\n";
    else flush_to_file();
}

int Logger::get_stream_size(std::stringstream& ss) {
    ss.seekg(0, std::ios::end);
    int size = ss.tellg();
    return size;
}

void Logger::flush_to_file() {
    pthread_mutex_lock(&log_mutex);
    log_file.open (LOG_PATH);
    log_file << buffer.str();
    log_file.close();
    pthread_mutex_unlock(&log_mutex);
    buffer.clear();
}

