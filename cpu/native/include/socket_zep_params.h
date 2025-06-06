/*
 * Copyright (C) 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#pragma once

/**
 * @addtogroup drivers_socket_zep
 * @{
 */

/**
 * @file
 * @brief  Configuration parameters for the @ref drivers_socket_zep driver
 * @author Martine Lenders <m.lenders@fu-berlin.de>
 */

#include "socket_zep.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Number of allocated parameters at @ref socket_zep_params
 *
 * @note    This was decided to only be confiruable on compile-time to be
 *          more similar to actual boards
 */
#if !defined(SOCKET_ZEP_MAX) || defined(DOXYGEN)
#  define SOCKET_ZEP_MAX              (1)
#endif

/**
 * @brief   socket_zep configurations
 */
extern socket_zep_params_t socket_zep_params[SOCKET_ZEP_MAX];

#ifdef __cplusplus
}
#endif

/** @} */
