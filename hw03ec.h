/*
 * hw03ec.h
 *
 *  Created on: Jan 28, 2020
 *      Author: jschmid20
 */

#ifndef HW03EC_H_
#define HW03EC_H_

enum TimeZone {PACIFIC, MOUNTAIN, CENTRAL, EASTERN};
string tZones[] = {"PACIFIC", "MOUNTAIN", "CENTRAL", "EASTERN"};

class Time{
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time();
	Time(int hrs, int min, int sec);
	int getHours() const {return hours;}
	int getMinutes() const {return minutes;}
	int getSeconds() const {return seconds;}
private:
	int hours;
	int minutes;
	int seconds;
};


class ExtTime:Time{
	friend ostream& operator<<(ostream&, const ExtTime&);
public:
	ExtTime();
	ExtTime(int hrs, int min, int sec, TimeZone tZone);
	TimeZone getTimeZone() const {return time_zone;}

private:
	TimeZone time_zone;
};

class Invoice{
	friend ostream& operator<<(ostream&, const Invoice&);
public:
	Invoice();
	Invoice(Time pTime);

private:
	Time purchase_time;
};

#endif /* HW03EC_H_ */
