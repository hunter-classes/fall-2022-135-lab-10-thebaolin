#include <iostream>
#include "funcs.h"
#include "time.h"
using namespace std;

int main(){
    Time time = {8,30};
    cout<< minutesSinceMidnight(time)<< " minutes since midnight from "<< time.h<< ":"<< time.m<< "\n";

    Time later = {12,50};
    cout<< minutesUntil(time,later)<< " minutes from "<< time.h<< ":"<< time.m<< " until "<< later.h<< ":"<< later.m<< "\n";

    Time time0 = {8, 30};
    int add_mins = 75;
    Time time1 = addMinutes(time0, add_mins);
    cout<< time1.h<< ":"<< time1.m<< " is "<< add_mins<< " minutes after "<< time0.h<< ":"<< time0.m<< "\n";

    Movie movie3 = {"Home Alone", DRAMA, 121};
    Movie movie4 = {"Nightmare Before Christmas",THRILLER, 131};

    TimeSlot afternoon = {movie3, {13, 45}};
    TimeSlot night = {movie4, {1, 15}};

    cout<< getTimeSlot(afternoon)<< "\n";
    cout<< getTimeSlot(night)<< "\n";
    
    TimeSlot before = {{"Black Panther", ACTION, 134}, {14, 30}};
    Movie next = {"Back to the Future", COMEDY, 116};
    TimeSlot after = scheduleAfter(before, next);

    cout<< "Before: "<< getTimeSlot(before) << "\n";
    cout<< "After: "<< getTimeSlot(after) << "\n";
    
    cout<< before.movie.title<< " and "<< afternoon.movie.title<< " Overlap: "<< boolalpha << timeOverlap(before, afternoon) << "\n";
    cout<< night.movie.title<< " and "<< after.movie.title<< " Overlap: "<<  boolalpha << timeOverlap(night, after)<< "\n";
}