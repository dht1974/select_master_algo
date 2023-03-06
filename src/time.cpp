#include "time.h"

/* Return the UNIX time in microseconds */
ustime_t ustime(void) 
{
    struct timeval tv;
    long long ust;

    gettimeofday(&tv, NULL);
    ust = ((long long)tv.tv_sec)*1000000;
    ust += tv.tv_usec;
    return ust;
}

/* Return the UNIX time in milliseconds */
mstime_t mstime(void) 
{
    return ustime()/1000;
}

