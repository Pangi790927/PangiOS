# Building with ct-ng

To build the cross compiler you need to do the following:

Exec `ct-ng menuconfig`

In `Paths and misc options`:
- Replace the top dir entries to contain ${CT_TOP_DIR}

In `Target options`:
- Select target architecture (x86 or TODO:arm)
- Select bitness 64bit

In `C-Library`
- Disable the syscalls supplied with newlib
- Enable finalization function registration using atexit
- Enable retargetable locking (NEW) 
- Disable Optimize newlib for size
- Enable Link Time Optimization

In `C-Compiler`
- Configure TLS -> Y
- Build libstdcxx -> Y
- Build freestanding libstdcxx
- C++

In `Debug facilities`
- gdb

Exec `ct-ng build`
(OPTIONAL) Add to `.gitignore` eventual new files

If errors appear, patch printf get_arg with `(va_list *)` and run `ct-ng build` again.
