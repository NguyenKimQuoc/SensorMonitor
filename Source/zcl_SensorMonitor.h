/**************************************************************************************************
  Filename:       zcl_genericapp.h
  Revised:        $Date: 2014-06-19 08:38:22 -0700 (Thu, 19 Jun 2014) $
  Revision:       $Revision: 39101 $

  Description:    This file contains the ZigBee Cluster Library Home
                  Automation Sample Application.


  Copyright 2006-2014 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED ?AS IS? WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

#ifndef ZCL_SENSORMONITOR_H
#define ZCL_SENSORMONITOR_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "zcl.h"


// Added to include ZLL Target functionality
#if defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  #include "zcl_general.h"
  #include "bdb_tlCommissioning.h"
#endif

/*********************************************************************
 * CONSTANTS
 */
#define SENSORMONITOR_ENDPOINT            1
// Added to include ZLL Target functionality
#define SENSORMONITOR_NUM_GRPS            2


// Application Events
//#define SENSORMONITOR_MAIN_SCREEN_EVT          0x0001
//#define SENSORMONITOR_EVT_LONG                 0x0002
//#define SENSORMONITOR_END_DEVICE_REJOIN_EVT    0x0004  
  
/* SENSORMONITOR_TODO: define app events here */
  
#define SENSORMONITOR_REPORT_EVT                 0x0001
#define SENSORMONITOR_READ_SENSORS_EVT           0x0002
#define SENSORMONITOR_CHECK_KEY_RELEASE_EVT        0x0004
#define SENSORMONITOR_OLED_OFF_EVT              0x0008  
#define SENSORMONITOR_FIRST_REPORT_EVT              0x0010  
// Application Display Modes
#define GENERIC_MAINMODE      0x00
#define GENERIC_HELPMODE      0x01
  
#define SENSORMONITOR_END_DEVICE_REJOIN_DELAY 10000

/*********************************************************************
 * MACROS
 */
  
#define BASIC       ZCL_CLUSTER_ID_GEN_BASIC
#define POWER_CFG   ZCL_CLUSTER_ID_GEN_POWER_CFG
#define TEMPERATURE        ZCL_CLUSTER_ID_MS_TEMPERATURE_MEASUREMENT
#define HUMIDITY    ZCL_CLUSTER_ID_MS_RELATIVE_HUMIDITY
//#define PRESSURE    ZCL_CLUSTER_ID_MS_PRESSURE_MEASUREMENT
#define IDENTIFY     ZCL_CLUSTER_ID_GEN_IDENTIFY
#ifdef OUTDOOR_LONG_RANGE
#define SENSORMONITOR_REPORT_DELAY ((uint32) 300000) //5 minutes
#else
#define SENSORMONITOR_REPORT_DELAY ((uint32) 1800000) //1 minute  
#endif  
/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */

extern int16 TemperatureValue;
extern uint16 HumidityValue;

// Added to include ZLL Target functionality
#if defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  extern bdbTLDeviceInfo_t tlSensorMonitor_DeviceInfo;
#endif

extern SimpleDescriptionFormat_t zclSensorMonitor_SimpleDesc;

extern CONST zclCommandRec_t zclSensorMonitor_Cmds[];

extern CONST uint8 zclCmdsArraySize;

// attribute list
extern CONST zclAttrRec_t zclSensorMonitor_Attrs[];
extern CONST uint8 zclSensorMonitor_NumAttributes;

// Identify attributes
extern uint16 zclSensorMonitor_IdentifyTime;
extern uint8  zclSensorMonitor_IdentifyCommissionState;

// SENSORMONITOR_TODO: Declare application specific attributes here


/*********************************************************************
 * FUNCTIONS
 */
//static void zclSensorMonitor_OnOffCB(uint8);
 /*
  * Initialization for the task
  */
extern void zclSensorMonitor_Init( byte task_id );

/*
 *  Event Process for the task
 */
extern UINT16 zclSensorMonitor_event_loop( byte task_id, UINT16 events );

/*
 *  Reset all writable attributes to their default values.
 */
extern void zclSensorMonitor_ResetAttributesToDefaultValues(void);


/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ZCL_SENSORMONITOR_H */
