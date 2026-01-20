#ifndef IO_PORTS_H
#define IO_PORTS_H

#include <stdint.h>

inline void outb (uint16_t port, uint8_t data) {
    asm volatile ("outb %0, %1" : : "a"(data), "Nd"(port));
}

inline void outw (uint16_t port, uint16_t data) {
    asm volatile ("out %%ax, %%dx" : : "a" (data), "d" (port));
}

inline void outd (uint16_t port, uint32_t data) {
    asm volatile ( "out %0, %1" : : "a"(data), "Nd"(port) );
}

inline void inws (uint16_t port, uint32_t buffer, uint32_t count) {
    asm volatile ("cld; rep; insl" : : "D" (buffer), "d" (port), "c" (count));
}

inline uint8_t inb (uint16_t port) {
    uint8_t ret = 0;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

inline uint16_t inw (uint16_t port) {
    uint16_t result = 0;
    asm volatile ("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return  result;
}

inline uint32_t ind (uint16_t port) {
    uint32_t ret = 0;
    asm volatile ("inl %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

inline void io_wait() {
    // 0x80 is for POST and seems safe for a dumy check
    // does the register need to be zeroed? (question on OSDev)
    asm volatile ("outb %%al, $0x80" : : "a"(0));
}

#endif
