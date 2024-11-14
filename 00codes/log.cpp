#include <fstream>
#include <iostream>
#include <string>

enum LogLevel { INFO, WARN, ERROR };

void log_message(const std::string &message, LogLevel level) {
  std::ofstream log_file("log.txt", std::ios::app);
  if (log_file.is_open()) {
    switch (level) {
    case INFO:
      log_file << "[INFO] ";
      break;
    case WARN:
      log_file << "[WARN] ";
      break;
    case ERROR:
      log_file << "[ERROR] ";
      break;
    }

    log_file << message << std::endl;
    log_file.close();
  } else {
    std::cerr << "failed to open log file" << std::endl;
  }
}

int main() {
  log_message("helloworld", LogLevel::INFO);

  return 0;
}