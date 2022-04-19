#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port10,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port1,           leftMotor,     tmotorNormal, openLoop, reversed)

void forward2Ft()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	while(SensorValue[leftEncoder] < 720)
	{
		motor[rightMotor] = 115;
		motor[leftMotor] = 127;
	}
}
void TurnRight()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder] < 320)
	{
		motor[rightMotor] = 127;
		motor[leftMotor] = -127;
	}
}
task main()
{
	wait1Msec(2000);  // 2 Second Delay
	for (int x = 0; x < 4; x ++)
	{
		forward2Ft();
		TurnRight();
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
