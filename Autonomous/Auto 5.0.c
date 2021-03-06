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
task main() {
	motor[port2] = 95;
	motor[port3] = 100;
	wait1Msec(400);
	motor[port2] = 0;
	motor[port3] = 0;
	for (int i = 0; i < 100; i++) {
			motor[port6] = i;
			motor[port7] = -i;
	}
	wait1Msec(2600);
	for (int i = 100; i > 40; i--) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(400);
	for (int i = 40; i < 100; i++) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(1000);
	for (int i = 100; i > 40; i--) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(400);
	for (int i = 40; i < 100; i++) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(1300);
	for (int j = 0; j < 3; j++) {
		for (int i = 100; i > 40; i--) {
			motor[port6] = i;
			motor[port7] = -i;
		}
		wait1Msec(300);
		for (int i = 40; i < 100; i++) {
			motor[port6] = i;
			motor[port7] = -i;
		}
		wait1Msec(1050);
	}
	wait1Msec(3700);
	motor[port4] = 90;
	wait1Msec(1000);
	motor[port4] = 0;
	motor[port2] = -75;
	motor[port3] = -100;
	for (int i = 100; i > 40; i--) {
		motor[port6] = i;
		motor[port7] = -i;
	}
	wait1Msec(3000);
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port2] = 75;
	motor[port3] = 100;
	wait1Msec(3000);
	motor[port2] = 100;
	motor[port3] = -100;
	wait1Msec(1000);

}
