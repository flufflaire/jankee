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
	//keep claw closed
	motor[port8] = 70;

	//raise arm
	motor[port2] = 127;
	motor[port3] = 127;
	motor[port4] = -127;
	motor[port5] = -127;

	wait10Msec(100);

	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;

	wait10Msec(10);

	//move forward to pick up mobile goal
	motor[port2] = -120;
	motor[port3] = 120;

	wait10Msec(500);

	motor[port2] = 0;
	motor[port3] = 0;

	wait10Msec(10);

	//lower arm
	motor[port2] = -127;
	motor[port3] = -127;
	motor[port4] = 127;
	motor[port5] = 127;

	wait10Msec(750);

	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;

	wait10Msec(10);

	//open claw
	motor[port8] = -100;

	wait10Msec(100);

	motor[port8] = 70;

	wait10Msec(100);

	motor[port8] = 0;

	//raise arm
	motor[port2] = 127;
	motor[port3] = 127;
	motor[port4] = -127;
	motor[port5] = -127;

	wait10Msec(100);

	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;

	wait10Msec(10);

	//turn around
	motor[port2] = 120;
	motor[port3] = 120;

	wait10Msec(200);

	motor[port2] = 0;
	motor[port3] = 0;

	wait10Msec(10);

	//drive back
	motor[port2] = -120;
	motor[port3] = 120;

	wait10Msec(550);

	motor[port2] = 0;
	motor[port3] = 0;

	wait10Msec(10);

	//drop mobile goal in scoring zone
  motor[port2] = 120;
  motor[port3] = -120;

	wait10Msec(100);

	motor[port2] = 0;
	motor[port3] = 0;


}
