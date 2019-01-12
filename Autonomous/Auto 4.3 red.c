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

	// this for the red & close side

	// go forward
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(1500);

	//stop
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(600);

	//spin flipper
	motor[port6] = 100;
	wait1Msec(2300);
	motor[port6] = 0;
	wait1Msec(600);

	//keep going forward
	motor[port2] = -100;
	motor[port3] = 100;
	wait1Msec(1000);

	//catapult
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port7] = -100;
	wait1Msec(900);
	//while(SensorValue[dgtl12] == 0) motor[port7] = -100;

	//wait for catapult to go to 0
	//start conveyor
	motor[port7] = 0;
	wait1Msec(400);
	motor[port4] = 100;
	wait1Msec(2000);
	motor[port4] = 0;
	wait1Msec(600);

	//shoot!
	motor[port7] = -100;
	wait1Msec(1200);
	motor[port7] = 0;
	wait1Msec(300);

	//nvm (not turning)
	motor[port2] = -100; //-100 to 100
	motor[port3] = 100; //-100 to 100
	wait1Msec(300);
	motor[port2] = -100; //100 to -100
	wait1Msec(2000);
	motor[port2] = 0;
	motor[port3] = 0;

}
