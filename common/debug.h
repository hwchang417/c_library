
#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define _DEBUG

#ifdef _DEBUG
#define DEBUG(format, args...) printf(format, ##args)
#else
#define DEBUG(args...)
#endif

#define FAILURE 0
#define SUCCESS 1

#include <stdio.h>
#include <stdlib.h>

#endif

