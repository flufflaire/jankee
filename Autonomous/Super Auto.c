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
	motor[port8] = -50;
	wait1Msec(550);
	motor[port8] = 0;
	motor[port4] = 127;
	motor[port5] = -127;
	wait1Msec(500);
  motor[port4] = 0;
	motor[port5] = 0;
	motor[port2] = 127;
	motor[port3] = -127;
	wait1Msec(2000);
	motor[port2] = -50;
	motor[port3] = -50;
	motor[port4] = 127;
	motor[port5] = -127;
	wait1Msec(550);
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port2] = 127;
	motor[port3] = -127;
	wait1Msec(1150);
	motor[port2] = 50;
	motor[port3] = -50;
	motor[port4] = -127;
	motor[port5] = 127;
	motor[port6] = 60;
	motor[port7] = -60;
	wait1Msec(1000);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	wait1Msec(1000);
	motor[port9] = -100;
	wait1Msec(500); //Second Stage
	motor[port9] = 0;
	wait1Msec(500);
	motor[port8] = 50;
	wait1Msec(600);
	motor[port2] = -127;
	motor[port3] = 127;
	wait1Msec(1200);
	motor[port2] = 127;
	motor[port3] = 127;
	wait1Msec(1300);
	motor[port2] = 127;
	motor[port3] = -127;
	wait1Msec(2700);
	motor[port2] = 127;
	motor[port3] = 127;
	wait1Msec(400);
	motor[port2] = 127;
	motor[port3] = -127;
	wait1Msec(500);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port8] = -50;
	wait1Msec(550);
	motor[port8] = 0;
	motor[port4] = 127;
	motor[port5] = -127;
	wait1Msec(1000);
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port2] = -127;
	motor[port3] = 127;
	wait1Msec(1000);
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port6] = 50;
	motor[port7] = -50;
	motor[port4] = -127;
	motor[port5] = 127;
	wait1Msec(1000);
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
}
