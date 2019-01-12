#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

task main() {
	while (true) {
		if (vexRT[Ch2] > 30 || vexRT[Ch2] < -30) motor[port1] = -1 * vexRT[Ch2]; // RIGHT WHEEL
		else motor[port6] = 0;
		if (vexRT[Ch3] > 30 || vexRT[Ch3] < -30) motor[port10] = vexRT[Ch3]; // LEFT WHEEL
		else motor[port7] = 0;
		if (vexRT[Btn6D] == 1 && vexRT[Btn6U] == 1) { // ARM
			motor[port2] = 0;
			motor[port3] = 0;
		} else if (vexRT[Btn6U] == 1) {
			motor[port2] = 100;
			motor[port3] = -100;
		} else if (vexRT[Btn6D] == 1) {
			motor[port2] = -100;
			motor[port3] = 100;
		} else {
			motor[port2] = 0;
			motor[port3] = 0;
		}
		if (vexRT[Btn5D] == 1 && vexRT[Btn5U] == 1) { // CLAW
    	motor[port8] = 10;
    	motor[port9] = 10;
    } else if (vexRT[Btn5D] == 1) {
    	motor[port8] = 60;
    	motor[port9] = -60;
    } else if (vexRT[Btn5U] == 1) {
    	motor[port8] = -60;
    	motor[port9] = 60;
    } else {
    	motor[port8] = 0;
    	motor[port9] = 0;
    }
	}
}
