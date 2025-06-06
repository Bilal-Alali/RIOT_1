/*
 * Copyright (C) 2018 Inria
 *               2019 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#pragma once

/**
 * @ingroup     boards_common_nrf51
 * @{
 *
 * @file
 * @brief       Shared timer peripheral configuration mapping timers 0, 1, and 2
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#include "periph_cpu.h"

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name    Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = NRF_TIMER0,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_24Bit,
        .irqn     = TIMER0_IRQn,
    },
    {
        .dev      = NRF_TIMER1,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_16Bit,
        .irqn     = TIMER1_IRQn,
    },
    {
        .dev      = NRF_TIMER2,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_16Bit,
        .irqn     = TIMER2_IRQn,
    }
};

#define TIMER_0_ISR         isr_timer0
#define TIMER_1_ISR         isr_timer1
#define TIMER_2_ISR         isr_timer2

/** See @ref timer_init */
#define TIMER_0_MAX_VALUE 0xffffffff
/** See @ref timer_init */
#define TIMER_1_MAX_VALUE 0xffffffff
/** See @ref timer_init */
#define TIMER_2_MAX_VALUE 0xffffffff

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

#ifdef __cplusplus
} /* end extern "C" */
#endif

/** @} */
