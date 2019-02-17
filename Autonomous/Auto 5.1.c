#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

//port 2: Wheel (positive)
//port 3: Wheel (positive)
//port 4: Feeder (positive)
//port 5: Intake (positive)
//port 6: Flywheel (positive)
//port 7: Flywheel (negative)

task main()
{
	for (int i = 0; i < 85; i++) {
			motor[port6] = i;
			motor[port7] = -i;
	}
	wait1Msec(5500);
	motor[port4] = 90;
	wait1Msec(1000);
	motor[port4] = 0;
	motor[port2] = -80;
	motor[port3] = -100;
	for (int i = 100; i > 40; i--) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(3000);
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port2] = 80;
	motor[port3] = 100;
	wait1Msec(4000);
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(2000);

}
