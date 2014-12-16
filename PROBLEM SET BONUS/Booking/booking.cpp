#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;


struct Date
{
	int year, month, day, hour, minutes;

	Date() {
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minutes = 0;
	}

	Date(int _year, int _month, int _day, int _hour, int _minutes) {
		year 	= _year;
		month 	= _month;
		day 	= _day;
		hour 	= _hour;
		minutes = _minutes;
	}

	Date add_minutes(int min) {

		minutes += min;
		while (minutes >= 60) {
			if(hour >= 23) {
				hour = 0;
				if ((is_30days(month) && day == 30) || day == 31) {
					day = 1;
					month++;
				} else if (month == 2){
					if (is_leap_year(year) && day >= 29){
						day = 1;
						month++;
					} else if (!is_leap_year(year) && day == 28) {
						day = 1;
						month++;
					} else {
						day++;
					}
				} else {
					day++;
				}
				if(month >= 13) {
					month = 1;
					year++;
				}
			} else {
				hour++;
			}
			minutes -= 60;
		}
		return *this;
	}

	bool is_30days(int month) {
		if (month == 4 || month == 6 || month == 9 || month == 11){
			return true;
		}
		return false;
	}

	bool is_leap_year(int year) {
		if ((year % 4 == 0) && !(year % 100 == 0))
			return true;
		else if (year % 400 == 0)
			return true;
		return false;
	}

	Date& operator=(const Date &rhs) {
    	
    	if (this != &rhs) {
      		this->year = rhs.year;
      		this->month = rhs.month;
      		this->day = rhs.day;
      		this->hour = rhs.hour;
      		this->minutes = rhs.minutes;
    	}
   		return *this;
  	}

  	bool operator<(const Date& that) const
  	{
  		if (this->year == that.year) {
  			if (this->month == that.month) {
  				if (this->day == that.day) {
  					if (this->hour == that.hour) {
  						if (this->minutes == that.minutes) {
  							return false;
  						} else {
  							return this->minutes < that.minutes;
  						}
  					} else {
  						return this->hour < that.hour;
  					}
  				} else {
  					return this->day < that.day;
  				}

  			} else {
  				return this->month < that.month;
  			}
  		} else {
  			return this->year < that.year;
  		}
  	}


};

struct Booking
{
	string id;
	Date arival, departure;

	Booking(string code, Date _arival, Date _departure, int cleaning) {
		id = code;
		arival = _arival;
		departure = _departure;
	}

	bool dose_overlap(Booking that) {
		return that.arival < this->departure;
	}
};

inline std::ostream& operator << (std::ostream& stream, const Date& dt) {
	stream << dt.year << '-' << dt.month << '-' << dt.day << " "
    	   << dt.hour << ":" << dt.minutes;
    return stream;
}

Booking get_booking(int cleaning);
bool compare_dates(Booking a, Booking b);

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int B, C;
		cin >> B >> C;
		vector<Booking> bookings;
		for (int i = 0; i < B; ++i) {
			bookings.push_back(get_booking(C));
		}
		sort(bookings.begin(), bookings.end(), compare_dates);

		vector<Booking> rooms;
		rooms.push_back(bookings[0]);

		for (int i = 1; i < bookings.size(); ++i)
		{
			bool fits = false;
			for (int j = 0; j < rooms.size(); ++j)
			{
				if (!rooms[j].dose_overlap(bookings[i])) {
					rooms[j] = bookings[i];
					fits = true;
					break;
				}
			}
			if (!fits) {
				rooms.push_back(bookings[i]);
			}
		}
		cout << rooms.size() << endl;
	}
	return 0;
}

bool compare_dates(Booking a, Booking b)
{
	return a.arival < b.arival;
}

Booking get_booking(int cleaning)
{
	string rcode;
		cin >> rcode;
	int _year, _month, _day, _hour, _minutes;
		cin >> _year;
		cin.ignore(2,'-');
		cin >> _month;
		cin.ignore(2,'-');
		cin >> _day;
		cin >> _hour;
		cin.ignore(2,':');
		cin >> _minutes;
	Date _arival = Date(_year, _month, _day, _hour, _minutes);
		cin >> _year;
		cin.ignore(2,'-');
		cin >> _month;
		cin.ignore(2,'-');
		cin >> _day;
		cin >> _hour;
		cin.ignore(2,':');
		cin >> _minutes;
	// cout << _year << "-" << _month << "-" << _day << " " << _hour << ":" << _minutes <<  endl;
	Date _departure = Date(_year, _month, _day, _hour, _minutes);
	_departure = _departure.add_minutes(cleaning);
	return Booking(rcode, _arival, _departure, cleaning);
}