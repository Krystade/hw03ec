//============================================================================
// Name        : hw03ec.cpp
// Author      : Jack Schmid -- CS1C T/Th 3:30-5:50 -- Professor Kath
// Description : Base Init List, Overloading & Friends. C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "hw03ec.h"

//Default Time constructor
Time::Time(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}
//Overloaded Time constructor
Time::Time(int hrs, int min, int sec){
	hours = hrs;
	minutes = min;
	seconds = sec;
}

//Default ExtTime constructor
ExtTime::ExtTime():Time(){
	time_zone = PACIFIC;
}
//Overloaded ExtTime constructor
ExtTime::ExtTime(int hrs, int min, int sec, TimeZone tZone):Time(hrs, min, sec){
	time_zone = tZone;
}

//Default Invoice constructor
Invoice::Invoice():purchase_time(){
}
//Overloaded Invoice constructor
Invoice::Invoice(Time pTime):purchase_time(pTime){
}


int main() {
	ExtTime* timeExt = new ExtTime(10, 5, 55, CENTRAL);
	Time* time = new Time(20, 12, 9);
	Invoice* invoice = new Invoice(*time);
	cout << *timeExt << endl << *invoice << endl;
	return 0;
}
//Overloaded Time insertion opertator
//Returns an ostream object that can be used to print the Time object's data using cout 
ostream& operator<<(ostream& out, const Time&  timeOut){
	out << "Time: ";
	if (timeOut.hours < 10)
		out << '0';
	out << timeOut.hours << ':';

	    if (timeOut.minutes < 10)
	    	out << '0';
	    out << timeOut.minutes << ':';

	    if (timeOut.seconds < 10)
	    	out << '0';
	    out << timeOut.seconds;
	    return out;
}

//Overloaded ExtTime insertion opertator
//Returns an ostream object that can be used to print the ExtTime object's data using cout 
ostream& operator<<(ostream& out, const ExtTime&  timeOut){
	out << Time(timeOut);
	out << " Time Zone: " << tZones[timeOut.time_zone];
	return out;
}

//Overloaded Invoice insertion opertator
//Returns an ostream object that can be used to print the Invoice object's data using cout 
ostream& operator<<(ostream& out, const Invoice&  invoiceOut){
	out << "Invoice Purchase ";
	out << invoiceOut.purchase_time;
	return out;
}
