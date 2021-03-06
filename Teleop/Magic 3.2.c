#pragma config(Motor,  port2,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,            ,             tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,            ,             tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
  // User control code here, inside the loop

  while (true)
  {
    if (vexRT[Ch2] > 20 || vexRT[Ch2] < -20) motor[port3] = vexRT[Ch2] * -1; // RIGHT WHEEL
		else motor[port3] = 0;
		if (vexRT[Ch3] > 20 || vexRT[Ch3] < -20) motor[port2] = vexRT[Ch3]; // LEFT WHEEL
		else motor[port2] = 0;
		if (vexRT[Btn7D] == 1 && vexRT[Btn7L] == 1) { // BOTTOM
			motor[port4] = 0;
			motor[port5] = 0;
		} else if (vexRT[Btn7L] == 1) {
			motor[port4] = 127;
			motor[port5] = -127;
		} else if (vexRT[Btn7D] == 1) {
			motor[port4] = -127;
			motor[port5] = 127;
		} else {
			motor[port4] = 0;
			motor[port5] = 0;
		}
		if (vexRT[Btn8D] == 1 && vexRT[Btn8R] == 1) { // CLAW
			motor[port9] = 0;
		} else if (vexRT[Btn8R] == 1) {
			motor[port9] = -100;
		} else if (vexRT[Btn8D] == 1) {
			motor[port9] = 100;
		} else {
			motor[port9] = 0;
		}
		if (vexRT[Btn6D] == 1 && vexRT[Btn6U] == 1) { // ARM2
			motor[port8] = 0;
		} else if (vexRT[Btn6U] == 1) {
			motor[port8] = -50;
		} else if (vexRT[Btn6D] == 1) {
			motor[port8] = 50;
		} else {
			motor[port8] = 0;
		}
		if (vexRT[Btn5D] == 1 && vexRT[Btn5U] == 1) { // ARM
			motor[port6] = 20;
			motor[port7] = -20;
		} else if (vexRT[Btn5U] == 1) {
			motor[port6] = 80;
			motor[port7] = -80;
		} else if (vexRT[Btn5D] == 1) {
			motor[port6] = -80;
			motor[port7] = 80;
		} else {
			motor[port6] = 0;
			motor[port7] = 0;
		}
  }
}
