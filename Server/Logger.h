#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <shared_mutex>

class Logger
{
public:
    
    Logger() { logger_file.open("logger.txt", std::ios::in | std::ios::out); }
    ~Logger() { logger_file.close(); }

    void setInfo(const std::string& from, const std::string& to, const std::string& text);
    void getInfo();
    friend std::fstream& operator >>(std::fstream& is, Logger& obj);
    friend std::fstream& operator <<(std::fstream& os, const Logger& obj);

private:
    std::string from_;
    std::string to_;
    std::string text_;
    std::fstream logger_file;
    std::shared_mutex shared_mutex;
};

