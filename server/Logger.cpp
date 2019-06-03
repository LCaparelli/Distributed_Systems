#include <string>
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <cstring>

#define LOGS_PATH "../logs/"

std::string Logger::get_timestamp() {
    std::time_t current_time = std::time(nullptr);
    auto timestamp = ctime(&current_time);
    timestamp[strlen(timestamp) - 1] = '\0';
    return timestamp;
}

//writes the log_entry to the buffer
void Logger::write_to_log(std::string log_entry) {
    buffer << get_timestamp() << ": " << log_entry + "\n";
}

//writes the contents of the buffer to a file
void Logger::flush_logs_to_file() {
    pthread_mutex_lock(&log_mutex);
    log_file.open (LOGS_PATH, std::ios_base::app);
    log_file << buffer.str();
    log_file.close();
    pthread_mutex_unlock(&log_mutex);
    buffer.str(std::string());
}