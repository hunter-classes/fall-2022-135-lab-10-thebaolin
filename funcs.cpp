#include <iostream>
#include <string>
#include "movie.h"
#include "time.h"
#include "timeslot.h"
using namespace std;

//A
int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}
int minutesUntil(Time earlier, Time later){
    return ((later.h - earlier.h) * 60 ) + (later.m - earlier.m);
}

//B
Time helperTime(int minutes){
    return {minutes / 60, minutes % 60};
}
Time addMinutes(Time time0, int min){
    return helperTime(minutesSinceMidnight(time0) + min);
}

//C
string getMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + to_string(mv.duration) + " min)";
}

string getTimeSlot(TimeSlot ts){
    return getMovie(ts.movie) + " [starts at " + getTime(ts.startTime) + ", ends by " + getTime(addMinutes(ts.startTime, ts.movie.duration)) + "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot nextTimeslot = {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
    return nextTimeslot;
}

