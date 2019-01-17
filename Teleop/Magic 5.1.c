#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)

task main() {
	int WH_switch1 = -1;
	int WH_switch2 = 0;
	int WH1 = 0;
	int WH2 = 0;
	int FW_switch1 = 0;
	int FW_switch2 = 0;
	int flywheel = 0;
	int IN_switch1 = 0;
	int IN_switch2 = 0;
	int FE_switch1 = 0;
	int FE_switch2 = 0;

	while(true) {
		if (vexRT[Btn7D] == 1 && WH_switch2 == 0) { // WHEEL VARIABLES
			WH_switch1+=2;
			WH_switch2 = 1;
		}
		if (WH_switch1 > 1) WH_switch1 = -1;
		if (vexRT[Btn7D] == 0) WH_switch2 = 0;

		if (WH_switch1 > 0) {
			WH1 = vexRT[Ch2];
			WH2 = vexRT[Ch3];
		} else {
			WH2 = vexRT[Ch2];
			WH1 = vexRT[Ch3];
		}

    if (WH2 > 30 || WH2 < -30) motor[port3] = (int) WH2 * 0.8 * WH_switch1; // RIGHT WHEEL
		else motor[port3] = 0;

		if (WH1 > 30 || WH1 < -30) motor[port2] = (int) WH1 * -0.8 * WH_switch1; // LEFT WHEEL
		else motor[port2] = 0;

		if ((vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1) && FW_switch2 == 0) { //FLYWHEEL VARIABLES
			FW_switch1++;
			FW_switch2 = 1;
		}
		if (FW_switch1 == 2) FW_switch1 = 0;
		if (vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0) FW_switch2 = 0;

		if (FW_switch1 == 1 && flywheel <= 100) flywheel++;
		else if (FW_switch1 == 0 && flywheel >= 50) flywheel--;

		if (vexRT[Btn8U] == 1 && vexRT[Btn8R] == 1) flywheel = 0;

		motor[port6] = flywheel; //flywheel
		motor[port7] = flywheel * -1;

		if (vexRT[Btn5D] == 1 && IN_switch2 == 0) { //INTAKE VARIABLES
			IN_switch1++;
			IN_switch2 = 1;
		} else if (vexRT[Btn8D] == 1 && IN_switch2 == 0) {
			IN_switch1--;
			IN_switch2 = 1;
		}
		if (IN_switch1 == 2 || IN_switch1 == -2) IN_switch1 = 0;
		if (vexRT[Btn5D] == 0 && vexRT[Btn8D] == 0) IN_switch2 = 0;


		if (IN_switch1 == 1) motor[port5] = 80; //intake
		else if (IN_switch1 == -1) motor[port5] = -90;
		else motor[port5] = 0;

		if (vexRT[Btn5U] == 1 && FE_switch2 == 0) { //FEEDER VARIABLES
			FE_switch1++;
			FE_switch2 = 1;
		}
		if (FE_switch1 == 2) FE_switch1 = 0;
		if (vexRT[Btn5U] == 0) FE_switch2 = 0;

		if (FE_switch1 == 1) motor[port4] = 100; //FEEDER
		else motor[port4] = 0;

		if (vexRT[Btn7U] == 1) motor[port8] = 100; //ARM
		else if(vexRT[Btn7L] == 1) motor[port8] = -100;
		else motor[port8] = 0;
	}
}
