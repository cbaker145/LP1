#ifndef MESSAGE_STRUCT
#define MESSAGE_STRUCT

#include<string.h>

using namespace std;

struct Time{
	int hour, minute, second;
};
struct Date{
	int year, month, day; 
};
struct Message{
	Date date;
	Time time;
	string content;
	
	int compare_dates(Message &target);
};

#endif
