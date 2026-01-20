#include "serial.h"

extern "C" int puts(const char *str) {
    serial::sendstr(str);
    return 0;
}