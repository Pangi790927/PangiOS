#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"

/* This almost works... */
extern "C" void kernel_main(void)  {
    serial::init();

    DBG("=== SERIAL TEST ===");
    DBG("Line A");
    DBG("Line B");
    DBG("End");

    DBG("I don't get it, why does this break???");
    DBG("And for some reason, it only breaks afterwards");

    /* Never get out of here... */
    while (true)
        asm volatile ("hlt");
}
