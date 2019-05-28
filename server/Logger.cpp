#include <string>
#include "Logger.h"
#include <iostream>
#include <fstream>

#define LOG_PATH "../logs/logs.txt"

void Logger::write_to_log(std::string log_entry) {
    buffer << log_entry + "\n";
}

void Logger::flush_logs_to_file() {
    pthread_mutex_lock(&log_mutex);
    log_file.open (LOG_PATH, std::ios_base::app);
    log_file << buffer.str();
    log_file.close();
    pthread_mutex_unlock(&log_mutex);
    buffer.str(std::string());
}

