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
	motor[port2] = 100;
	motor[port3] = -100;
	wait1Msec(1700);
  motor[port3] = 100;
	wait1Msec(1150);
	motor[port2] = -100;
	wait1Msec(300);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port5] = -100;
	wait1Msec(500);
	while(SensorValue[dgtl12] == 0) motor[port5] = -100;
	motor[port5] = 0;
	wait1Msec(400);
	motor[port4] = 100;
	wait1Msec(2000);
	motor[port5] = -100;
	motor[port4] = 0;
	wait1Msec(700);
	motor[port5] = 0;
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(500);
	motor[port2] = 100;
	wait1Msec(1800);
	motor[port3] = -100;
	wait1Msec(3000);
	motor[port2] = 0;
	motor[port3] = 0;
}
