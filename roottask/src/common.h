/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once
#include <autoconf.h>
#include <sel4/bootinfo.h>

#include <vka/vka.h>
#include <vka/object.h>
#include <sel4utils/elf.h>
#include <sel4utils/process.h>
#include <simple/simple.h>
#include <vspace/vspace.h>
#include <rumprun/init_data.h>
#include <platsupport/irq.h>
#include <platsupport/ltimer.h>
#include <platsupport/time_manager.h>
#include <roottask_platform_config/config.h>
#include <utils/page.h>

typedef struct env *env_t;

#define INIT_DATA_NUM_FRAMES BYTES_TO_4K_PAGES(sizeof(init_data_t))
#define N_RUMP_PROCESSES 10
#define MAX_TIMER_IRQS 4

typedef struct rump_process {
    init_data_t *init;
    void *stdio[RR_NUMIO];
    vka_object_t stdio_notifications[RR_NUMIO];
    vka_object_t untypeds[CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS];
    int num_untypeds_devram;
    int num_untypeds;
    int num_untypeds_dev;
    sel4utils_process_t process;
    /* notification to signal client on when a timeout has expired */
    vka_object_t timer_signal;
    vka_object_t init_ep_obj;
    const char *bin_name;
} rump_process_t;

typedef struct rump_env {
    /* An initialised vka that may be used by the test. */
    vka_t vka;
    /* virtual memory management interface */
    vspace_t vspace;
    /* abtracts over kernel version and boot environment */
    simple_t simple;
    /* logical timer interface */
    ltimer_t ltimer;
    /* timer manager - for timeouts */
    time_manager_t time_manager;
    /* operations for hardware io */
    ps_io_ops_t ops;
    /* irq for the serial device */
    cspacepath_t serial_irq;
    /* notification timer and serial input come in on */
    vka_object_t irq_ntfn;
    /* reply object to use for recv on the RT kernel */
    vka_object_t reply_obj;
    /* endpoint for root task to handle faults and rpcs on */
    vka_object_t ep;
    /* list of processes */
    rump_process_t processes[N_RUMP_PROCESSES];
} rump_env_t;

#ifdef CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER
extern void *log_buffer;
#endif //CONFIG_BENCHMARK_USE_KERNEL_LOG_BUFFER

void hog_thread(void *_arg1, void *_arg2, void *_arg3);

extern uint64_t ccount;

void count_idle(void *, void *, void *);

void arch_copy_IOPort_cap(init_data_t *init, rump_env_t *env, sel4utils_process_t *test_process);
void handle_char(rump_env_t *env, int c);
#ifdef CONFIG_ARM_SMMU
seL4_SlotRegion arch_copy_iospace_caps_to_process(sel4utils_process_t *process, rump_env_t *env);
#endif
