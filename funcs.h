#pragma once
#include "time.h"
#include "movie.h"
#include "timeslot.h"
using namespace std;

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time helperTime(int minutes);
Time addMinutes(Time time0, int min);
string getMovie(Movie mv);
string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 