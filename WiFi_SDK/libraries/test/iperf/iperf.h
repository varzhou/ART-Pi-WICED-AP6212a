/*
 * $ Copyright Broadcom Corporation $
 */

/** @file
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                     Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/
/* determined based on the console thread stack size */
#define WICED_DEFAULT_IPERF_STACK          (4096)
/* determined based on usual test procedures */
#define WICED_DEFAULT_IPERF_PRIORITY       (6)

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

int iperf( int argc, char **argv );

#ifdef __cplusplus
} /*extern "C" */
#endif

