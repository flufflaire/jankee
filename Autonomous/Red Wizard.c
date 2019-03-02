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
	for(int i = 0; i < 90; i++) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(4000);
	motor[port4] = 90;
	wait1Msec(1000);
	motor[port4] = 0;
	for(int i = 90; i > 0; i--) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	motor[port2] = 80;
	motor[port3] = 80;
	wait1Msec(850);
	motor[port2] = -80;
	wait1Msec(530);
	motor[port3] = -80;
	motor[port6] = 0;
	motor[port7] = 0;
	wait1Msec(1400);
	motor[port2] = -40;
	motor[port3] = -40;
	wait1Msec(500);
	motor[port2] = 0;
	motor[port3] = 0;


}
