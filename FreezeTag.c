#pragma config(Sensor,dgtl11,Button,sensorTouch)
#pragma config(Motor,port1,rightMotor,tmotorVex393_HBridge,openLoop)
#pragma config(Motor,port6,arm,tmotorServoContinuousRotation,openLoop)
#pragma config(Motor,port10,leftMotor,tmotorVex393_HBridge,openLoop,reversed)
task main(){
	int Stop = 1;
	while (true){
		while (Stop == 1){
			motor[leftMotor] = vexRT[Ch3];
			motor[rightMotor] = vexRT[Ch2];
			if (SensorValue(Button) == 1){
				Stop = Stop*-1;
				wait1Msec(500);}
			if(vexRT[Btn6U] == 1){
				motor[arm] = 127;}
			else if(vexRT[Btn6D] == 1){
				motor[arm] = -127;}
			else{
				motor[arm] = 0;}}
		if (SensorValue(Button) == 1){
			Stop = Stop*-1;
			wait1Msec(500);}}}
