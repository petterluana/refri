#include "GerenciaTempo.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;


//http://www.cplusplus.com/reference/ctime/asctime/
//Fun��o para Data e Hora
char* GerenciaTempo:: asctime(const struct tm *timeptr)
{
    static const char wday_name[][4] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char mon_name[][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    static char result[26];
    sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
        wday_name[timeptr->tm_wday],
        mon_name[timeptr->tm_mon],
        timeptr->tm_mday, timeptr->tm_hour,
        timeptr->tm_min, timeptr->tm_sec,
        1900 + timeptr->tm_year);
    return result;
}

void GerenciaTempo::data_hora(){
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf ( "The current date/time is: %s", asctime(timeinfo));

}


