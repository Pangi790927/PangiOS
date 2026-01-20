#ifndef DEBUG_H
#define DEBUG_H

#include "serial.h"

#define DBG(fmt, ...) printf(fmt "\n\n", ##__VA_ARGS__)

#endif
