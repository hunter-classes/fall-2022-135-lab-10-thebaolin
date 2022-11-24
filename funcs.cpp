#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include <string>
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

string getTimeSlot(TimeSlot ts) {
    Time end = addMinutes(ts.startTime, ts.movie.duration);

    string newstring = getMovie(ts.movie);
    newstring += " [starts at " + to_string(ts.startTime.h) + ":" + to_string(ts.startTime.m) + ", ends by " + to_string(end.h) + ":" + to_string(end.m) + "] ";
    return newstring;
}


//D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot nextTimeslot = {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};

    return nextTimeslot;
}

//E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    TimeSlot early, late;

    if(minutesUntil(ts1.startTime, ts2.startTime) < 0) {
        early = ts2;
        late = ts1;
    }
    else {
        early = ts1; 
        late = ts2;
    }

    if(minutesUntil(early.startTime, late.startTime) < early.movie.duration)
        return true;

    return false;
}
