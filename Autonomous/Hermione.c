#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

//port 2 & 3 - wheels
//port 4 - bottom roller
//port 5 - top roller
//port 6 & 7 - flywheel
//port 8 - arm
task main() {
	int flywheel = 0;
	while (flywheel < 100) {
		flywheel++;
		motor[port6] = flywheel;
		motor[port7] = flywheel * -1;
	}
	wait1Msec(400);
	motor[port5] = 100;
	wait1Msec(500);
	while (flywheel > 0) {
		flywheel -= 2;
		motor[port6] = flywheel;
		motor[port7] = flywheel * -1;
	}
	motor[port2] = 100;
	motor[port3] = 100;
	wait1Msec(500);
	motor[port3] = -100;
	motor[port4] = -100;
	wait1Msec(1000);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
}
