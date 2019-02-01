#ifndef __PCH__
#define __PCH__


#ifdef __linux__
#include "./pch_linux.h"
#endif //__linux__

#ifdef _WIN32
#include "./pch_win.h"
#endif //_WIN32

#ifdef __darwin__
#include "./pch_mac.h"
#endif //__darwin__


#endif //__PCH__