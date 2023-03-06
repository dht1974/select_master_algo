#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>

typedef long long mstime_t;
typedef long long ustime_t;

/* Return the UNIX time in microseconds */
extern ustime_t ustime(void);

/* Return the UNIX time in milliseconds */
extern mstime_t mstime(void);

#endif
