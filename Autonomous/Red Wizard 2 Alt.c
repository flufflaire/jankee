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
	motor[port2] = 90;
	motor[port3] = 90;
	motor[port5] = 80;
	wait1Msec(1500);
	motor[port5] = -90;
	motor[port2] = -90;
	motor[port3] = -90;
	wait1Msec(300);
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(1000);
	motor[port2] = -90;
	motor[port3] = 90;
	wait1Msec(330);
	motor[port2] = 90;
  wait1Msec(700);
	motor[port2] = -90;
	motor[port3] = -90;
	wait1Msec(500);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port5] = 80;

}
