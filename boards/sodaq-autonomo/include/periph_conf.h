/*
 * Copyright (C) 2016 Kees Bakker, SODAQ
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#pragma once

/**
 * @ingroup     boards_sodaq-autonomo
 * @{
 *
 * @file
 * @brief       Configuration of CPU peripherals for the SODAQ Autonomo board
 *
 * @author      Kees Bakker <kees@sodaq.com>
 */

#include <stdint.h>

#include "cpu.h"
#include "periph_cpu.h"
#include "cfg_clock_default.h"
#include "cfg_rtc_default.h"
#include "cfg_rtt_default.h"
#include "cfg_spi_default.h"
#include "cfg_timer_default.h"
#include "cfg_usbdev_default.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    UART configuration
 * @{
 * See Table 6.1 of the SAM D21 Datasheet
 */
static const uart_conf_t uart_config[] = {
    {
        .dev      = &SERCOM0->USART,
        .rx_pin   = GPIO_PIN(PA,9),
        .tx_pin   = GPIO_PIN(PA,10),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin  = GPIO_UNDEF,
        .cts_pin  = GPIO_UNDEF,
#endif
        .mux      = GPIO_MUX_C,
        .rx_pad   = UART_PAD_RX_1,
        .tx_pad   = UART_PAD_TX_2,
        .flags    = UART_FLAG_NONE,
        .gclk_src = SAM0_GCLK_MAIN,
    },
    {
        .dev      = &SERCOM5->USART,
        .rx_pin   = GPIO_PIN(PB,31),
        .tx_pin   = GPIO_PIN(PB,30),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin  = GPIO_UNDEF,
        .cts_pin  = GPIO_UNDEF,
#endif
        .mux      = GPIO_MUX_D,
        .rx_pad   = UART_PAD_RX_1,
        .tx_pad   = UART_PAD_TX_0_RTS_2_CTS_3,
        .flags    = UART_FLAG_NONE,
        .gclk_src = SAM0_GCLK_MAIN,
    },
    {
        .dev      = &SERCOM4->USART,
        .rx_pin   = GPIO_PIN(PB,13),
        .tx_pin   = GPIO_PIN(PB,14),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin  = GPIO_UNDEF,
        .cts_pin  = GPIO_UNDEF,
#endif
        .mux      = GPIO_MUX_C,
        .rx_pad   = UART_PAD_RX_1,
        .tx_pad   = UART_PAD_TX_2,
        .flags    = UART_FLAG_NONE,
        .gclk_src = SAM0_GCLK_MAIN,
    },
    {
        .dev      = &SERCOM1->USART,
        .rx_pin   = GPIO_PIN(PA,17),
        .tx_pin   = GPIO_PIN(PA,18),
#ifdef MODULE_PERIPH_UART_HW_FC
        .rts_pin  = GPIO_UNDEF,
        .cts_pin  = GPIO_UNDEF,
#endif
        .mux      = GPIO_MUX_C,
        .rx_pad   = UART_PAD_RX_1,
        .tx_pad   = UART_PAD_TX_2,
        .flags    = UART_FLAG_NONE,
        .gclk_src = SAM0_GCLK_MAIN,
    },
};

/* interrupt function name mapping */
#define UART_0_ISR          isr_sercom0
#define UART_1_ISR          isr_sercom5
#define UART_2_ISR          isr_sercom4
#define UART_3_ISR          isr_sercom1

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name ADC configuration
 * @{
 */

/* ADC Default values */
#define ADC_PRESCALER                      ADC_CTRLB_PRESCALER_DIV512

#define ADC_NEG_INPUT                      ADC_INPUTCTRL_MUXNEG_GND
#define ADC_GAIN_FACTOR_DEFAULT            ADC_INPUTCTRL_GAIN_DIV2
#define ADC_REF_DEFAULT                    ADC_REFCTRL_REFSEL_INTVCC1

static const adc_conf_chan_t adc_channels[] = {
    /* port, muxpos/pin */
    /* Use the Arduino pin number order */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PA02 },     /* ADC/AIN[0], A0 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PA06 },     /* ADC/AIN[6], A1 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PA05 },     /* ADC/AIN[5], A2 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PA04 },     /* ADC/AIN[4], A3 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB09 },     /* ADC/AIN[3], A4 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB08 },     /* ADC/AIN[2], A5 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB07 },    /* ADC/AIN[15], A6 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB06 },    /* ADC/AIN[14], A7 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB05 },    /* ADC/AIN[13], A8 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB04 },    /* ADC/AIN[12], A9 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PA07 },     /* ADC/AIN[7], A10 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB03 },    /* ADC/AIN[11], A11 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB02 },    /* ADC/AIN[10], A12 */
    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB01 },     /* ADC/AIN[9], A13 (pin also used for DTR) */

    { .inputctrl = ADC_INPUTCTRL_MUXPOS_PB00 },     /* ADC/AIN[8], BATVOLT */
};

#define ADC_NUMOF                          ARRAY_SIZE(adc_channels)
/** @} */

/**
 * @name    PWM configuration
 * @{
 */
#define PWM_0_EN            1
#define PWM_1_EN            1

#if PWM_0_EN
/* PWM0 channels */
static const pwm_conf_chan_t pwm_chan0_config[] = {
    /* GPIO pin, MUX value, TCC channel */
    { GPIO_PIN(PA, 6), GPIO_MUX_E, 0 },
    { GPIO_PIN(PA, 7), GPIO_MUX_E, 1 },
};
#endif
#if PWM_1_EN
/* PWM1 channels */
static const pwm_conf_chan_t pwm_chan1_config[] = {
    /* GPIO pin, MUX value, TCC channel */
    { GPIO_PIN(PA, 16), GPIO_MUX_F, 0 },
    { GPIO_PIN(PA, 18), GPIO_MUX_F, 2 },
    { GPIO_PIN(PA, 19), GPIO_MUX_F, 3 }
};
#endif

/* PWM device configuration */
static const pwm_conf_t pwm_config[] = {
#if PWM_0_EN
    {TCC_CONFIG(TCC1), pwm_chan0_config, ARRAY_SIZE(pwm_chan0_config), SAM0_GCLK_MAIN},
#endif
#if PWM_1_EN
    {TCC_CONFIG(TCC0), pwm_chan1_config, ARRAY_SIZE(pwm_chan1_config), SAM0_GCLK_MAIN},
#endif
};

/* number of devices that are actually defined */
#define PWM_NUMOF           ARRAY_SIZE(pwm_config)
/** @} */

/**
 * @name    I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    {
        .dev      = &(SERCOM2->I2CM),
        .speed    = I2C_SPEED_NORMAL,
        .scl_pin  = GPIO_PIN(PA, 13),
        .sda_pin  = GPIO_PIN(PA, 12),
        .mux      = GPIO_MUX_C,
        .gclk_src = SAM0_GCLK_MAIN,
        .flags    = I2C_FLAG_NONE
     }
};
#define I2C_NUMOF          ARRAY_SIZE(i2c_config)
/** @} */

#ifdef __cplusplus
}
#endif

/** @} */
