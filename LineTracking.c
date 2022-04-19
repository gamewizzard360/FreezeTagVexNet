#pragma config(Sensor, in1,    lineFollowerLeft,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerRight,    sensorLineFollower)
#pragma config(Motor,  port10,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port1,           leftMotor,     tmotorNormal, openLoop, reversed)

task main()
{
	wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

	int Rthreshold = 527.5;
	int Lthreshold = 795;
	int Cthreshold = 1390;/* found by taking a reading on both DARK and LIGHT    */
	/* surfaces, adding them together, then dividing by 2. */
	while(true)
	{
		// RIGHT sensor sees dark:
		if(SensorValue(lineFollowerRIGHT) < Rthreshold)
		{
			// counter-steer right:
			motor[leftMotor]  = 63;
			motor[rightMotor] = 0;
		}
		// CENTER sensor sees dark:
		if(SensorValue(lineFollowerCENTER) < Cthreshold)
		{
			// go straight
			motor[leftMotor]  = 63;
			motor[rightMotor] = 63;
		}
		// LEFT sensor sees dark:
		if(SensorValue(lineFollowerLEFT) < Lthreshold)
		{
			// counter-steer left:
			motor[leftMotor]  = 0;
			motor[rightMotor] = 63;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
