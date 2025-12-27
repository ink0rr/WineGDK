#ifndef XDUMMY_H
#define XDUMMY_H

#include "../../private.h"

#include <string.h>

struct x_dummy
{
    IXDummyImpl IXDummyImpl_iface;
    LONG ref;
};

#endif