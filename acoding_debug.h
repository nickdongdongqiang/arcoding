#ifndef __ACODING_DEBUG_H__
#define __ACODING_DEBUG_H__

#include <stdio.h>

enum {
    E_INFO = 0,
    E_NOTICE,
    E_DEBUG,
    E_WARRN,
    E_ERROR,
};

#define LOG_LEVEL 0

#ifdef LOG_LEVEL 
#define LOG_OUT(level, color, tag, str, ...)  (\
                            (tag >= LOG_LEVEL)? \
                             fprintf(stdout, color tag "%s:%d:"\
                                    str "\e[0m", __FILE__, __LINE__, \
                                    ##__VA_ARGS__):0); 
#else
#define LOG_OUT(tag, color, str, ...)  
#endif

#define INFO(a, ...) LOG_OUT(E_INOF, "\e[1;32m", "[INFO]", a, ##__VA_ARGS__)
//yellow
#define NOTICE(a, ...) LOG_OUT(E_NOTICE, "\e[1;43m", "[NOTICE]:", a, ##__VA_ARGS__)
//green 
#define DEBUG(a, ...) LOG_OUT(E_DEBUG, "\e[1;42m", "[DEBUG]:", a, ##__VA_ARGS__)
//blue
#define WARRN(a, ...) LOG_OUT(E_WARRN, "\e[1;34m", "[WARRN]:", a, ##__VA_ARGS__)
//red
#define ERROR(a, ...) LOG_OUT(E_ERROR, "\e[1;41m", "[ERROR]:", a, ##__VA_ARGS__)

#endif