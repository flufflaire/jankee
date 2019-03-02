
task main()
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
  wait1Msec(1000);
	motor[port2] = 0;
	motor[port3] = 0;


}
