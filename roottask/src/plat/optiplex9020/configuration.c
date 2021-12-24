/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <utils/arith.h>
#include <roottask_platform_config/config.h>


struct mmio mmio0s[] = {{0xf7f00000, 17}, {0xf7f39000, 12}};
struct mmio mmio1s[] = {{0xf7dc0000, 17}};

static device_t devices[] = {{"wm0", 20, ARRAY_SIZE(mmio0s), mmio0s, {0, 25, 0}},
    {"wm1", 16, ARRAY_SIZE(mmio1s), mmio1s, {3, 0, 0}}
};

device_t *get_devices(void)
{
    return devices;
}

int get_num_devices(void)
{
    return ARRAY_SIZE(devices);
}
