#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

task main()
{
motor[port2] = -60;
	motor[port3] = -80;
	wait1Msec(1500);
	motor[port2] = -30;
	motor[port3] = -30;
	wait1Msec(530);
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port2] = 90;
	motor[port3] = 90;
	motor[port5] = -90;
	wait1Msec(850);
	motor[port3] = -90;
	wait1Msec(500);
	motor[port3] = 90;
	wait1Msec(850);
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(2000);
	motor[port5] = 0;

}
