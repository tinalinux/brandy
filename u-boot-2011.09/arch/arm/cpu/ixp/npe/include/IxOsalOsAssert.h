/*
 * arch/arm/cpu/ixp/npe/include/IxOsalOsAssert.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef IxOsalOsAssert_H
#define IxOsalOsAssert_H

#define IX_OSAL_OS_ASSERT(c)    if(!(c)) \
                                { \
                                    ixOsalLog (IX_OSAL_LOG_LVL_ERROR, IX_OSAL_LOG_DEV_STDOUT, "Assertion failure \n", 0, 0, 0, 0, 0, 0);\
                                    while(1); \
                                }

#endif /* IxOsalOsAssert_H */
