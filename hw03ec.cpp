//============================================================================
// Name        : hw03ec.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Define Time, ExtTime, and Invoice classes. Instantiate an ExtTime
// 				 object and an Invoice object. Override << operators for ExtTime
//				 and Invoice classes and use it to display to the console.
//============================================================================

#include <iostream>
using namespace std;
#include "hw03ec.h"

Time::Time(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}
Time::Time(int hrs, int min, int sec){
	hours = hrs;
	minutes = min;
	seconds = sec;
}


ExtTime::ExtTime():Time(){
	time_zone = PACIFIC;
}
ExtTime::ExtTime(int hrs, int min, int sec, TimeZone tZone):Time(hrs, min, sec){
	time_zone = tZone;
}

Invoice::Invoice():purchase_time(){
}
Invoice::Invoice(Time pTime):purchase_time(pTime){
}


int main() {
	ExtTime* timeExt = new ExtTime(10, 5, 55, CENTRAL);
	Time* time = new Time(20, 12, 9);
	Invoice* invoice = new Invoice(*time);
	cout << *timeExt << endl << *invoice << endl;
	return 0;
}

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

ostream& operator<<(ostream& out, const ExtTime&  timeOut){
	out << Time(timeOut);
	out << " Time Zone: " << tZones[timeOut.time_zone];
	return out;
}

ostream& operator<<(ostream& out, const Invoice&  invoiceOut){
	out << "Invoice Purchase ";
	out << invoiceOut.purchase_time;
	return out;
}
