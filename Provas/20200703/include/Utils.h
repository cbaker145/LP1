#ifndef W5N_UTILS_H
#define W5N_UTILS_H

#include<ctime>
#include<string>
#include<cstring>
#include<iostream>
#include<fstream>

std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();
std::string get_path();
std::string get_format();
bool diary_file_ready();
bool config_file_ready();

#endif
