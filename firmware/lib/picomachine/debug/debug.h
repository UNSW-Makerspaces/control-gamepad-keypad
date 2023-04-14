#ifdef PICOMACHINE_DEBUG_MODE
#include <cstdio>

inline void picomachine_debug_log(const char* library, const char* cls, const char* func, const char* message) {
    printf("[%s][%s][%s]: %s\n", library, cls, func, message);
}
#else
inline void picomachine_debug_log(const char*, const char*, const char*, const char*) {}
#endif
