/*
 * Copyright (C) 2007 Robotics at Maryland
 * Copyright (C) 2007 Steve Moskovchenko <stevenm@umd.edu>
 * All rights reserved.
 *
 * Author: Steve Moskovchenko <stevenm@umd.edu>
 * File:  packages/imu/include/imuapi.h
 */

#ifndef RAM_IMUAPI_H_06_25_2007
#define RAM_IMUAPI_H_06_25_2007

typedef struct _RawIMUData
{
    int messageID;
    int sampleTimer;

    double gyroX;   /* Radians per second */
    double gyroY;   /* Radians per second */
    double gyroZ;   /* Radians per second */

    double accelX;  /* Gs   */
    double accelY;  /* Gs   */
    double accelZ;  /* Gs   */

    double magX;    /* Gauss */
    double magY;    /* Gauss */
    double magZ;    /* Gauss */

    double tempX;   /* Degrees C */
    double tempY;   /* Degrees C */
    double tempZ;   /* Degrees C */
    int checksumValid;
} RawIMUData;

/** Opens a serial channel to the imu using the given devices
 *
 *  @param  devName  Device filename
 *
 *  @return  The file descriptor of the device file.
 */
int openIMU(const char * devName);

/** Read the latest IMU measurements into the given structure
 *
 *  @param fd  The device file returned by openIMU
 */
int readIMUData(int fd, RawIMUData * imu);

#endif // RAM_IMUAPI_H_06_25_2007
