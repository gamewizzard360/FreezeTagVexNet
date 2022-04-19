#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

void Clear() //Clear shaft encoders
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}
void Forward(float x) //x is inches
{
	Clear();
	while(sensorValue[rightEncoder] < ((360*x)/14.137))
	{
		motor[leftMotor] = 63.5;
		motor[rightMotor] = 63.5;
	}
}
void PointTurnLeft(float x)//x is desired degrees
{
	Clear();
	while(sensorValue[rightEncoder] < ((26.407*x)/14.137))
	{
		motor[rightMotor] = 63.5;
		motor[leftMotor] = -63.5;
	}
}
void Backwards(float x)
{
	Clear();
	while(sensorValue[rightEncoder] > (-360*x)/14.137)
	{
		motor[leftMotor] = -63.5;
		motor[rightMotor] = -63.5;
	}
}
task main()
{
	Clear(); //reset shaft encoders
	Forward(42); //go forward 42 inches or 3.5 feet
	PointTurnLeft(180); //turn left 180 degrees
	Backwards(120); //go back 10ft or 120 inches
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
