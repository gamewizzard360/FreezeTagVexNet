#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port10,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port1,           leftMotor,     tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/*----------------------------------------------------------------------------------------------------*\
|*                              - Forward for Distance with Encoders -                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward for 5 rotations of the left shaft encoder.       *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" model, but may not be needed for all robot configurations.                      *|
|*    2)  Whichever encoder is being used for feedback should be cleared just before it starts        *|
|*        counting by using the "SensorValue(encoder) = 0;".  This helps ensure consistancy.          *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 1,2  rightEncoder        VEX Shaft Encoder     Right side                        *|
|*    Digital - Port 3,4  leftEncoder         VEX Shaft Encoder     Left side                         *|
\*----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
void ResetSensors()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}
void TurnRight()
{
	ResetSensors();
	while (SensorValue[leftEncoder] < 320)
	{
		motor[rightMotor] = -127;
		motor[leftMotor] = 127;
	}
}
void TurnLeft()
{
	ResetSensors();
	while (SensorValue[rightEncoder] < 320)
	{
		motor[rightMotor] = 127;
		motor[leftMotor] = -127;
	}
}
void GoForward(float x)
{
	ResetSensors();
	while (SensorValue[leftEncoder] < (x/12)*360)
	{
		motor[leftMotor] = 127;
		motor[rightMotor] = 115;
	}
}
void Stop()
{
	motor[leftMotor] = -1;
	motor[rightMotor] = -1;
	wait1Msec(1000);
}
task main()
{
	wait1Msec(2000); //wait 2 seconds
	GoForward(20);
	TurnLeft();
	GoForward(24);
	TurnRight();
	GoForward(20);
	TurnRight();
	GoForward(14);
	Stop();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++