/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  motor[port2] = 90;
	motor[port3] = 90;
	motor[port5] = 80;
	wait1Msec(1500);
	motor[port5] = 0;
	motor[port2] = -90;
	motor[port3] = -90;
	wait1Msec(300);
	motor[port2] = 0;
	motor[port3] = 0;
	wait1Msec(1000);
	motor[port2] = -90;
	motor[port3] = 90;
	wait1Msec(480);
	motor[port3] = -90;
  wait1Msec(1200);
	motor[port2] = 0;
	motor[port3] = 0;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
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
	int time = 0;

	while(true) {
		//WHEEL VARIABLES
		if (vexRT[Btn7D] == 1 && WH_switch2 == 0) {
			WH_switch1+=2;
			WH_switch2 = 1;
		}
		if (WH_switch1 > 1) WH_switch1 = -1;
		if (vexRT[Btn7D] == 0) WH_switch2 = 0;

		if (WH_switch1 > 0) {
			WH1 = (int) vexRT[Ch2] * .71 * WH_switch1;
			WH2 = (int) vexRT[Ch3] * .71 * WH_switch1;
		} else {
			WH2 = (int) vexRT[Ch2] * .71 * WH_switch1;
			WH1 = (int) vexRT[Ch3] * .71 * WH_switch1;
		}

		//RIGHT WHEEL
    if (WH2 > 25 || WH2 < -25) {
    	if (WH2 - motor[port3] > 20 && WH2 > 0) motor[port3] += 10;
			else if (WH2 - motor[port3] < -20 && WH2 < 0) motor[port3] -= 10;
    	else motor[port3] = WH2;
    } else motor[port3] = 0;

		//LEFT WHEEL
		if (WH1 > 25 || WH1 < -25) {
			if (WH1 - motor[port2] > 20 && WH1 > 0) motor[port2] += 10;
			else if (WH1 - motor[port2] < -20 && WH1 < 0) motor[port2] -= 10;
			else motor[port2] = WH1;
		} else motor[port2] = 0;

		//FLYWHEEL VARIABLES
		if ((vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1) && FW_switch2 == 0) {
			FW_switch1++;
			FW_switch2 = 1;
		}
		if (FW_switch1 == 2) FW_switch1 = 0;
		if (vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0) FW_switch2 = 0;

		if (FW_switch1 == 1 && flywheel < 90) flywheel++;
		else if (FW_switch1 == 0 && flywheel > 0) flywheel --;

		// if (vexRT[Btn8U] == 1 && vexRT[Btn8R] == 1 && FW_switch1 == 0 && flywheel < 50) flywheel = 0;

		//FLYWHEEL
		motor[port6] = flywheel;
		motor[port7] = flywheel * -1;

		//INTAKE VARIABLES
		if (vexRT[Btn5D] == 1 && IN_switch2 == 0) {
			IN_switch1++;
			IN_switch2 = 1;
		} else if (vexRT[Btn8D] == 1 && IN_switch2 == 0) {
			IN_switch1--;
			IN_switch2 = 1;
		}
		if (IN_switch1 == 2 || IN_switch1 == -2) IN_switch1 = 0;
		if (vexRT[Btn5D] == 0 && vexRT[Btn8D] == 0) IN_switch2 = 0;

		//INTAKE
		if (IN_switch1 == 1) motor[port5] = 80;
		else if (IN_switch1 == -1) motor[port5] = -90;
		else motor[port5] = 0;

		//FEEDER VARIABLES
		if (vexRT[Btn5U] == 1 && FE_switch2 == 0) {
			FE_switch1++;
			FE_switch2 = 1;
		}
		if (FE_switch1 == 2) FE_switch1 = 0;
		if (vexRT[Btn5U] == 0) FE_switch2 = 0;

		if (FE_switch1 == 1) time++;
		else time = 0;
		if (time == 10000) FE_switch1 = 0;

		//FEEDER
		if (FE_switch1 == 1) motor[port4] = 90;
		else motor[port4] = 0;

		//ARM
		if (vexRT[Btn7U] == 1) motor[port8] = 100;
		else if (vexRT[Btn7L] == 1) motor[port8] = -100;
		else motor[port8] = 0;
	}
}
