#include "Utils.h"

std::string format_current_date(const string &format) {
	time_t current_time = time(nullptr);
	char result[1024];
	strftime(result, sizeof(result), format.c_str(), localtime(&current_time));
	return std::string(result);
}

std::string get_current_date(){
	return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}
