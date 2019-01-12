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
	int temp = 0;
	int temp1 = 0;
	int x = 1;
	int y = 0;

	while (true) {
		if (vexRT[Btn7D] == 1 && y == 0) {
			x+=2;
			y = 1;
		}
		if (x > 1) x = -1;
		if (vexRT[Btn7D] == 0) y = 0;

    if (vexRT[Ch2] > 30 || vexRT[Ch2] < -30) motor[port3] = (int) vexRT[Ch2] * -0.8 * x; // RIGHT WHEEL
		else motor[port3] = 0;

		if (vexRT[Ch3] > 30 || vexRT[Ch3] < -30) motor[port2] = (int) vexRT[Ch3] * 0.8 * x; // LEFT WHEEL
		else motor[port2] = 0;

		if (vexRT[Btn8D] == 1 && temp1 == 0) {
			temp++;
			temp1 = 1;
		}
		if (temp == 2) temp = 0;
		if (vexRT[Btn8D] == 0) temp1 = 0;
		if (temp == 1) motor[port4] = 100; //Conveyer belt
		else motor[port4] = 0;

		if (vexRT[Btn6D] == 1 || SensorValue[dgtl12] == 0) motor[port5] = -100; //Catapult
		else motor[port5] = 0;

  }
}
