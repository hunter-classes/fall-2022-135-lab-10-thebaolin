#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

Time t0 = {0, 0};
Time t1 = {1, 11};
Time t2 = {22, 59};
Time t3 = {16, 18};

TEST_CASE("minutesSinceMidnight"){
    CHECK(minutesSinceMidnight(t0) == 0);
    CHECK(minutesSinceMidnight(t1) == 71);
    CHECK(minutesSinceMidnight(t2) == 1379);
    CHECK(minutesSinceMidnight(t3) == 978);
}

TEST_CASE("minutesUntil") {
    CHECK(minutesUntil(t0, t1) == 71);
    CHECK(minutesUntil(t1, t0) == -71);
    CHECK(minutesUntil(t1, t2) == 1308);
    CHECK(minutesUntil(t2, t3) == -401);
    CHECK(minutesUntil(t3, t2) == 401);
}

TEST_CASE("getMovie"){
    Movie testMovie = {"Beewb", THRILLER, 111};
    CHECK(getMovie(testMovie) == "Beewb THRILLER (111 min)");
    testMovie.duration = 123;
    CHECK(getMovie(testMovie) == "Beewb THRILLER (123 min)");
    testMovie.genre = ACTION;
    CHECK(getMovie(testMovie) == "Beewb ACTION (123 min)");
    testMovie.title = "Beewb 2.0";
    CHECK(getMovie(testMovie) == "Beewb 2.0 ACTION (123 min)");
}

TEST_CASE("getTimeSlot"){
    Movie testMovie = {"BEEWB", ACTION, 60};
    TimeSlot testTimeslot = {testMovie, {12, 30}};
    CHECK(getTimeSlot(testTimeslot) == "BEEWB ACTION (60 min) [starts at 12:30, ends by 13:30] ");
    testTimeslot.movie.duration = 120;
    CHECK(getTimeSlot(testTimeslot) == "BEEWB ACTION (120 min) [starts at 12:30, ends by 14:30] ");
    testTimeslot.movie.genre = THRILLER;
    CHECK(getTimeSlot(testTimeslot) == "BEEWB THRILLER (120 min) [starts at 12:30, ends by 14:30] ");
    testTimeslot.movie.title = "BEEWB 2.0";
    CHECK(getTimeSlot(testTimeslot) == "BEEWB 2.0 THRILLER (120 min) [starts at 12:30, ends by 14:30] ");
    testTimeslot.startTime = {8, 30};
    CHECK(getTimeSlot(testTimeslot) == "BEEWB 2.0 THRILLER (120 min) [starts at 8:30, ends by 10:30] ");
}

TEST_CASE("scheduleAfter"){
    Movie testMovie = {"The Empire Strikes Back", ACTION, 124};
    TimeSlot testTimeslot = {testMovie, {12, 30}};
    CHECK(getTimeSlot(scheduleAfter(testTimeslot, testMovie)) == "The Empire Strikes Back ACTION (124 min) [starts at 14:34, ends by 16:38] ");
    TimeSlot before = {{"Beewb", ACTION, 111}, {12, 30}};
    Movie next = {"Beewb 2.0", COMEDY, 30};
    CHECK(getTimeSlot(before) == "Beewb ACTION (111 min) [starts at 12:30, ends by 14:21] ");
    CHECK(getTimeSlot(scheduleAfter(before,next)) == "Beewb 2.0 COMEDY (30 min) [starts at 14:21, ends by 14:51] ");

}

TEST_CASE("timeOverlap"){
    Movie test1 = {"Beewb", DRAMA, 124};
    TimeSlot testTimes1 = {test1, {12, 30}};
    Movie test2 = {"Smile", THRILLER, 144};
    TimeSlot testTimes2 = {test2, {13, 30}};
    CHECK(timeOverlap(testTimes1, testTimes2) == true);
    CHECK(timeOverlap(testTimes2, testTimes1) == true);
    testTimes2.startTime = {14, 34};
    CHECK(timeOverlap(testTimes1, testTimes2) == false);
    CHECK(timeOverlap(testTimes2, testTimes1) == false);
}