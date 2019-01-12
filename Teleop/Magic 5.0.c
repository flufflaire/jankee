#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

task main() {
	int W_switch1 = -1;
	int W_switch2 = 0;
	int W1 = 0;
	int W2 = 0;
	int FW_switch1 = 0;
	int FW_switch2 = 0;
	int flywheel = 0;

	while(true) {
		if (vexRT[Btn7D] == 1 && W_switch2 == 0) { // WHEEL VARIABLES
			W_switch1+=2;
			W_switch2 = 1;
		}
		if (W_switch1 > 1) W_switch1 = -1;
		if (vexRT[Btn7D] == 0) W_switch2 = 0;

		if (W_switch1 > 0) {
			W1 = vexRT[Ch2];
			W2 = vexRT[Ch3];
		} else {
			W2 = vexRT[Ch2];
			W1 = vexRT[Ch3];
		}

    if (W2 > 30 || W2 < -30) motor[port3] = (int) W2 * -0.8 * W_switch1; // RIGHT WHEEL
		else motor[port3] = 0;

		if (W1 > 30 || W1 < -30) motor[port2] = (int) W1 * 0.8 * W_switch1; // LEFT WHEEL
		else motor[port2] = 0;

		if ((vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1) && FW_switch2 == 0) { //FLYWHEEL VARIABLES
			FW_switch1++;
			FW_switch2 = 1;
		}
		if (FW_switch1 == 2) FW_switch1 = 0;
		if (vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0) FW_switch2 = 0;

		if (FW_switch1 == 1 && flywheel <= 100) flywheel++;
		else if (FW_switch1 == 0 && flywheel >= 40) flywheel--;

		motor[port6] = flywheel; //flywheel controls
		motor[port7] = flywheel * -1;
	}
}
