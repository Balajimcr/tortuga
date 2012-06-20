/*
 * Copyright (C) 2007 Robotics at Maryland
 * Copyright (C) 2007 Steve Moskovchenko <stevenm@umd.edu>
 * All rights reserved.
 *
 * Author: Steve Moskovchenko <stevenm@umd.edu>
 * File:  packages/imu/test/src/imutest.c
 */

// STD Includes
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Project Includes
#include "drivers/imu/include/imuapi.h"

int main(int argc, char ** argv)
{
    const char* deviceFile = "/dev/ttyUSB0";

    if (argc == 2)
        deviceFile = argv[1];

    int fd = openIMU(deviceFile);

    if(fd == -1)
    {
        printf("Could not find device: \"%s\"\n", deviceFile);
        exit(1);
    }

    RawIMUData imuData;

	int i=0;

    while(1)
    {
        // Calculate angles (taken out of the IMU api)  
/*        double angleMagX = atan2(imuData.magY, imuData.magX);
 	double angleMagY = atan2(imuData.magZ, imuData.magY);
 	double angleMagZ = atan2(imuData.magX, imuData.magZ);
 	
        double angleAccX = atan2(imuData.accelY, imuData.accelX);
 	double angleAccY = atan2(imuData.accelZ, imuData.accelY);
 	double angleAccZ = atan2(imuData.accelX, imuData.accelZ);*/
 	

        readIMUData(fd, &imuData);

	i++;

//	if(i == 10)
	{
		printf("%11f %11f %11f;\n",
//               imuData.accelX, imuData.accelY, imuData.accelZ,
               imuData.magX, imuData.magY, imuData.magZ);
		i=0;
	}
        //printf("%11f %11f %11f  %11f %11f %11f  \n", imuData.angleMagX, imuData.angleMagY, imuData.angleMagZ, imuData.angleAccX, imuData.angleAccY, imuData.angleAccZ);
//        printf("%11f %11f %11f\n", imuData.gyroX, imuData.gyroY, imuData.gyroZ);
//        printf("%9f\n", imuData.gyroX);
    }
    return 0;
}
