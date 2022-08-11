#include "Logger.h"

void Logger::setInfo(const std::string& from, const std::string& to, const std::string& text)
{
    mutex.lock();
    logger_file << from << " : " << to << " : " << text << std::endl;
    mutex.unlock();
}

void Logger::getInfo()
{
    mutex.lock();
    logger_file >> from_ >> to_;
    getline(logger_file, text_);
    mutex.unlock();
    std::cout << from_ << " : " << to_ << " : " << text_ << std::endl;
}

std::fstream& operator >>(std::fstream& is, Logger& obj)
{
    is >> obj.from_;
    is >> obj.to_;
    is >> obj.text_;
    return is;
}
std::fstream& operator <<(std::fstream& os, const Logger& obj)
{
    os << obj.from_;
    os << ' ';
    os << obj.to_;
    os << ' ';
    os << obj.text_;
    return os;
}
