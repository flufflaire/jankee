#pragma config(Sensor, dgtl12, ,               sensorTouch)
#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

task main() {

	// this for the red & back side
  // version 1 go straight platform

	// go forward
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(1500);

	//stop
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(600);

	//turn
	motor[port2] = -100;
	motor[port3] = -100;
	wait1Msec(900);

	//stop
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(600);

	//keep going forward
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(2000);

}
