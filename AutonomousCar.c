//======================================================================
//
// Coursework ESCREVER MAIS
// 
// 
//
// author: Diogo Alexandre Da Silva Nobrega, University of Hertfordshire
//         
//======================================================================

#include <stdlib.h>
#include <curses.h>

//======================================================================
// Global Variables
//
// These variables are pretending to be the environment.
// Speed is not actually speed. But the percentage of high pulse duration in a cycle (PWM).
// Speed can be set as to the car as a whole, or separately, to the left wheels and right wheels.
// IR sensors are set initially to 1. (Object detected in front of the robot).
// Line Follower sensors are set initially to 1. (Line detected underneath the robot).
//
//======================================================================

int Speed_value = 0; //variable to hold percentage of high pulse duration in relation to cycle duration. Ranges from 0<=Speed_value<=100
int LeftWheels_Status = 1; //variable to hold status of left wheels pin. Varies between 0 and 1.
int RightWheels_Status = 1; //variable to hold status of right wheels pin. Varies between 0 and 1.
int IrLeft_value = 1; //variable to hold detection of object on IR left sensor. Varies between 0 (no detection) and 1 (detection).
int IrRight_value = 1; //variable to hold detection of object on IR right sensor. Varies between 0 (no detection) and 1 (detection).
int IrLineLeft_value = 1; //variable to hold detection of a line on IR left ground sensor. Varies between 0 (no detection) and 1 (detection).
int IrLineRight_value = 1; //variable to hold detection of a line on IR right ground sensor. Varies between 0 (no detection) and 1 (detection).

//======================================================================
// Empty Functions
//======================================================================

void delay(int delay){ //empty function to pretend existance of delay()
} 

int initio_Init(){  //empty function to pretend existance of delay()
}

//======================================================================
// Sensors functions
//======================================================================


// IR Sensor Functions 

bool initio_IrRight(void) {
  //IR right sensor. Function returns 1 if an object is being detected in the IR right sensor, or 0 if it is not detecting.  
  mvprintw(6,1,"Sensor: initio_IrRight () = %d\n", IrRight_value); //mvprintw is used in this current implementation as it enables the programmer
  return IrRight_value;                                            //to customize the output by allowing to specify cursor position to print at.
}

bool initio_IrLeft(void) {
  //IR right sensor. Function returns 1 if an object is being detected in the IR right sensor, or 0 if it is not detecting 
  mvprintw(5,1,"Sensor: initio_IrLeft () = %d\n", IrLeft_value); 
  return IrLeft_value;
}

// Line Sensors Functions
bool initio_IrLineRight(void) {
  //Line Follower right sensor. Function returns 1 if the line is being detected underneath the robot in the right sensor, 
  //or 0 if it is not detecting it   
  mvprintw(8,1,"Sensor: initio_IrLineRight () = %d\n", IrLineRight_value);
  return IrLineRight_value;
}

bool initio_IrLineLeft(void) {
  //Line Follower right sensor. Function returns 1 if the line is being detected underneath the robot in the left sensor, 
  //or 0 if it is not detecting it    
  mvprintw(7,1,"Sensor: initio_IrLineLeft () = %d\n", IrLineLeft_value);
  return IrLineLeft_value;
}

// Wheels sensors
bool initio_wheelSensorRight(void) {
  //Right wheels sensor. Returns the status of the right wheels position sensor connected to the pin. '1' if everything is fine, '0' otherwise.
  mvprintw(1,1,"Sensor: initio_wheelSensorRight () = %d\n", RightWheels_Status);
  return RightWheels_Status;
}
bool initio_wheelSensorLeft(void) {
  //Left wheels sensor. Returns the status of the right wheels position sensor connected to the pin. '1' if everything is fine, '0' otherwise.
  mvprintw(1,1,"Sensor: initio_wheelSensorLeft () = %d\n", LeftWheels_Status);
  return LeftWheels_Status;
}

//======================================================================
// Actuators functions
//======================================================================

//Drive forward
void initio_DriveForward(int Speed){
  //Initio function sets the parameter speed value to both wheels' motors, thus, the robot moves forward.
  //Output notifies of control change.
  Speed_value = Speed; //Added to update global variable Speed_value, which is printed out in some testing functions.
  mvprintw(12,1,"Control: initio_DriveForward () = %d\n", Speed_value);
}
//Stop
void initio_Stop(void){
  //Initio function sets the parameter speed value to '0' to both wheels' motors, thus, the robot stops moving.
  //Output notifies of control change.
  Speed_value = 0;  
  mvprintw(12,1,"Control: initio_Stop ()\n");
}
//Drive Reverse
void initio_DriveReverse(int Speed){
  //Initio function sets the parameter speed value to both wheels' motors, thus, the robot moves forward.
  //Output notifies of control change.
  Speed_value = Speed;
  mvprintw(12,1,"Control: initio_DriveBackwards () = %d\n", Speed_value);
}
//Spin Right
void initio_SpinRight(int Speed){
  //Initio function sets the parameter speed value to the left wheels' motor and sets the speed_value to '0' in the right wheels' motor
  //thus, the robot spins right.
  //Output notifies of control change.
  Speed_value = Speed;
  mvprintw(12,1,"Control: initio_SpinRight () = %d\n", Speed_value);
}
//Spin Left
void initio_SpinLeft(int Speed){
  //Initio function sets the parameter speed value to the right wheels' motor and sets the speed_value to '0' in the left wheels' motor
  //thus, the robot spins left.
  //Output notifies of control change.
  Speed_value = Speed;
  mvprintw(12,1,"Control: initio_SpinLeft () = %d\n", Speed_value);
}

//======================================================================
// Functionalities  
//======================================================================

void Obstacle_Avoidance (int argc, char *argv[]) {
  //Obstacle avoidance function takes the input of the IR sensors. If any of them detect an object, robot stops.
  
  int ch = 0; // sets a variable to hold the output of getch()
  int IrL, IrR;	// status of infrared sensors
  int LfL, LfR;	// status of line sensors    
  
  while (ch != 'q'){ //makes sure the output of getch() held in ch is not 'q'. When pressing 'q' while loop will stop.
    mvprintw(16,1,"Press 'q' to end program");

    IrL = initio_IrLeft(); //Sets local variale 'IrL' to the IrLeft value. (1 if it detects an object, 0 if it does not.)
    IrR = initio_IrRight(); //Sets local variale 'IrR' to the IrRight value. (1 if it detects an object, 0 if it does not.)
    LfL = initio_IrLineLeft(); //Sets local variale 'LfL' to the IrLineLeft value. (1 if it detects the line, 0 if it does not.)
    LfR = initio_IrLineRight(); //Sets local variale 'LfR' to the IrLineRight value. (1 if it detects the line, 0 if it does not.)

    if (IrL==0 && IrR==0){ //Both IR sensors do not detect any object
        initio_DriveForward (70); //Robot drives forward at speed '70' (default speed was set to 70 to make the robot less prone to error in a real world environment)
    }
    else { //If any of the sensors detect an object
        initio_Stop(); //Robot stops.
    }
    ch = getch(); //reads a single character entered in the keyboard. Does not use any buffer, key pressed is immediately returned.
    if (ch != ERR){ //if getch() != 'q', prints a warning in the console showing the key pressed.
      mvprintw(17,1,"Key code: '%c' (%d)", ch, ch);
    }
    refresh(); //updates output window each time the loop is ran
    delay(100); //Delays the loop restart
  }
}

void Line_Follower(int argc, char *argv[]) 
{
  int ch = 0;
  int IrL, IrR;
  int LfL, LfR;	

  initio_DriveForward(70); //Robot starts moving forward at speed '70'
  mvprintw(3,1,"Control: initio_DriveForward () = %d\n", Speed_value); //Line of code added just for appearance purposes.


  while (ch != 'q') {
    mvprintw(16,1,"Press 'q' to end program\n"); 

    IrL = initio_IrLeft(); //Sets local variale 'IrL' to the IrLeft value. (1 if it detects an object, 0 if it does not.)
    IrR = initio_IrRight(); //Sets local variale 'IrR' to the IrRight value. (1 if it detects an object, 0 if it does not.)
    LfL = initio_IrLineLeft(); //Sets local variale 'LfL' to the IrLineLeft value. (1 if it detects the line, 0 if it does not.)
    LfR = initio_IrLineRight(); //Sets local variale 'LfR' to the IrLineRight value. (1 if it detects the line, 0 if it does not.)

    if (IrL != 0 || IrR != 0) { //Detects if any object is ahead.
      mvprintw(13,1,"Action 1: Stop (IR sensors: %d, %d)\n", IrL, IrR);
      initio_Stop (); // Stop
    }
    // No object ahead, so line following can proceed
    else if (LfL == 1 && LfR == 1) { //Both sensors detect the line underneath
      mvprintw(13,1,"Action 2: Straight (Line sensors: %d, %d)\n", LfL, LfR);
      initio_DriveForward(70); //Robot moves straight forward at speed '70'
    }
    else if ( LfL == 1 && LfR == 0 ) {//Right sensor does not detect the line, thus, the robot is too much on the right.
      mvprintw(13,1,"Action 3: Spin left (Line sensors: %d, %d)\n", LfL, LfR);
      initio_SpinLeft(70); //Robot spins left at speed '70'
    }
    else if ( LfL == 0 && LfR == 1 ) {//Left sensor does not detect the line, thus, the car is too much on the Left.
      mvprintw(13,1,"Action 4: Spin right (Line sensors: %d, %d)\n", LfL, LfR);
      initio_SpinRight(70); //Robot spins right at speed '70'
    }
    else { //Last possible situation, is both sensors not detecting the line, thus, the line was lost.
      mvprintw(13,1,"Lost my line (Line sensors: %d, %d)\n", LfL, LfR);
      initio_Stop(); //Robot stops.
    }

    ch = getch();
    if (ch != ERR){
      mvprintw(17,1,"Key code: '%c' (%d)\n", ch, ch);
    }
    refresh();
    delay(100); //Delays the loop restart
  } 
}

//======================================================================
// Test functions to replace integration in robot   
//======================================================================

void Test_ObstacleAvoidance(int argc, char *argv[]) {
  //Test function aims to test any possible situation that the robot can run in to, with regards to the IR sensors.

  mvprintw(1,1,"Situation 1 - Obstacle Avoidance Test With No Object Ahead");
  mvprintw(10,1,"Car should move forward.\n"); 
  //First situation, there is no objects ahead. Robot should just move forward.
  IrLeft_value = 0; //No objects detected
  IrRight_value = 0;
  Obstacle_Avoidance(argc,argv); //Obstacle avoidance function is ran. Output should be 'Control: initio_DriveForward()...'.
  erase(); //cleans output window

  mvprintw(1,1,"Situation 2 - Obstacle Avoidance Test With Object On Left Side");
  mvprintw(10,1,"Car should stop.\n");
  //Second situation, there is an object ahead, detected on the left IR sensor. Robot should stop.
  IrLeft_value = 1; //Object detected in left IR sensor
  IrRight_value = 0;
  Obstacle_Avoidance(argc,argv); //Obstacle avoidance function is ran. Output should be 'Control: initio_Stop()...'.
  erase();

  mvprintw(1,1,"Situation 3 - Obstacle Avoidance Test With Object On Right Side");
  mvprintw(10,1,"Car should stop.\n");
  //Third situation, there is an object ahead, detected on the right IR sensor. Robot should stop.
  IrLeft_value = 0; //Object detected in right IR sensor
  IrRight_value = 1;
  Obstacle_Avoidance(argc,argv); //Obstacle avoidance function is ran. Output should be 'Control: initio_Stop()...'.
  erase();

  mvprintw(1,1,"Situation 4 - Obstacle Avoidance Test With Object Ahead");
  mvprintw(10,1,"Car should stop.\n");
  //Fourth situation, there is an object ahead, detected on both IR sensors. Robot should stop.
  IrLeft_value = 1; //Object detected in both IR sensors
  IrRight_value = 1;
  Obstacle_Avoidance(argc,argv); //Obstacle avoidance function is ran. Output should be 'Control: initio_Stop()...'.
  erase();

}



void Test_LineFollower_NoObject(int argc, char *argv[]) {
  //Test function aims to to test any possible line follower situation, without any object being detected ahead.
  
  IrLeft_value = 0; //No object detected in any sensor
  IrRight_value = 0;

  mvprintw(1,1,"Situation 1 - Line Follower Test With No Obstacle Detected");
  mvprintw(10,1,"Car should stop.\n");
  //First situation, car should stop as the line was lost
  IrLineLeft_value = 0; //No line detected in any sensor
  IrLineRight_value = 0;
  Line_Follower(argc,argv); //Line follower function is ran. Output should be 'Control: initio_Stop()...'.
  erase();

  mvprintw(1,1,"Situation 2 - Line Follower Test With No Obstacle Detected");
  mvprintw(10,1,"Car should spin left.\n");
  //Second situation, car should spin left as the robot is positioned too much on the right side.
  IrLineLeft_value = 1; //Line follower left sensor detects the line
  IrLineRight_value = 0;
  Line_Follower(argc,argv); //Line follower function is ran. Output should be 'Control: initio_SpinLeft()...'
  erase();

  mvprintw(1,1,"Situation 3 - Line Follower Test With No Obstacle Detected");
  mvprintw(10,1,"Car should spin right.\n");
  //Third situation, car should spin right as the robot is positioned too much on the left side.
  IrLineLeft_value = 0; //Line follower right sensor detects the line
  IrLineRight_value = 1;
  Line_Follower(argc,argv); //Line follower function is ran. Output should be 'Control: initio_SpinRight()...'
  erase();

  mvprintw(1,1,"Situation 4 - Line Follower Test With No Obstacle Detected");
  mvprintw(10,1,"Car should move forward.\n");
  //Fourth situation, car should move forward as the robot is positioned correctly on top of the line.
  IrLineLeft_value = 1; //Both line follower sensors detect the line
  IrLineRight_value = 1;
  Line_Follower(argc,argv); //Line follower function is ran. Output should be 'Control: initio_DriveForward()...'
  erase();

  }



void Test_LineFollower_RightObject(int argc, char *argv[]) {
  //Test function aims to to test any possible line follower situation, with an object being detected on the right side.

  IrLeft_value = 0; //Object detected in the right IR sensor
  IrRight_value = 1;

  //In any of the situations the outcome should be the same. The robot should stop as there is an object ahead.
  //The line follower function will be ran. The output should be 'Control: initio_Stop()...'
  
  mvprintw(1,1,"Situation 1 - Line Follower Test With Obstacle In Right Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is not detected in any line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 2 - Line Follower Test With Obstacle In Right Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in left line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 3 - Line Follower Test With Obstacle In Right Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is detected in right line follower sensor.
  IrLineRight_value = 1;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 4 - Line Follower Test With Obstacle In Right Side");  
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in both line follower sensors
  IrLineRight_value = 1;
  Line_Follower(argc,argv);    
  erase();

  }



void Test_LineFollower_LeftObject(int argc, char *argv[]) {
  //Test function aims to to test any possible line follower situation, with an object being detected on the left side.

  IrLeft_value = 1; //Object detected in the left IR sensor
  IrRight_value = 0;

  //In any of the situations the outcome should be the same. The robot should stop as there is an object ahead.
  //The line follower function will be ran. The output should be 'Control: initio_Stop()...'
  mvprintw(1,1,"Situation 1 - Line Follower Test With Obstacle In Left Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is not detected in any line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 2 - Line Follower Test With Obstacle In Left Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in left line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 3 - Line Follower Test With Object In Left Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is detected in right line follower sensor.
  IrLineRight_value = 1;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 4 - Line Follower Test With Object In Left Side");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in both line follower sensors.
  IrLineRight_value = 1;
  Line_Follower(argc,argv);    
  erase();

}



void Test_LineFollower_FrontObject(int argc, char *argv[]) {
  //Test function aims to to test any possible line follower situation, with an object being detected on both IR sensors.
  
  IrLeft_value = 1;
  IrRight_value = 1;

  //In any of the situations the outcome should be the same. The robot should stop as there is an object ahead.
  //The line follower function will be ran. The output should be 'Control: initio_Stop()...'

  mvprintw(1,1,"Situation 1 - Line Follower Test With Obstacle In Front");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is not detected in any line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 2 - Line Follower Test With Obstacle In Front");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in left line follower sensor.
  IrLineRight_value = 0;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 3 - Line Follower Test With Obstacle In Front");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 0; //Line is detected in right line follower sensor.
  IrLineRight_value = 1;
  Line_Follower(argc,argv);
  erase();

  mvprintw(1,1,"Situation 4 - Line Follower Test With Obstacle In Front");
  mvprintw(10,1,"Car should stop.\n");
  IrLineLeft_value = 1; //Line is detected in both line follower sensors.
  IrLineRight_value = 1;
  Line_Follower(argc,argv);   
  erase(); 
}



void Test_Situation_1(int argc, char *argv[]){
  //Test function will mimic the following situation:
  //Robot will be positioned to much to the right side (oriented parallelly to the line), thus, 
  //the line follower will be set to 1 on the left side, but, set to 0 on the right side. There will not be any objects in front of the robot.
  //Therefore, it should:
  //-Spin left (until it alignes both sensors with the line). The robot will not be oriented correctly yet (will be aiming slightly towards the left.)
  //-Drive forward (until it loses the line on the left sensor, as it will be moving diagonally to the left.)
  //-Spin right (until it alignes both sensors with the line, finally with the correct orientation.)
  //-Drive forward

  IrLeft_value = 0; //No object detected ahead
  IrRight_value = 0;

  IrLineLeft_value = 1; //Robot offset towards the right side, thus, IrLineLeft_value = 1 and IrLineRight_value = 0
  IrLineRight_value = 0;

  mvprintw(1,1,"Phase 1 - Robot positioned on right side of the line");
  mvprintw(10,1,"Car should spin left");
  Line_Follower(argc,argv);
  erase();
  IrLineLeft_value = 1; //Both sensors detect the line after spinning
  IrLineRight_value = 1;

  mvprintw(1,1,"Phase 2 - Robot positioned on top of the line, oriented diagonally");
  mvprintw(10,1,"Card should drive forward");
  Line_Follower(argc,argv);
  erase();
  IrLineLeft_value = 0; //Left sensor lost the line after moving forward
  IrLineRight_value = 1;

  mvprintw(1,1,"Phase 3 - Robot positioned on left side of the line");
  mvprintw(10,1,"Card should spin right");
  Line_Follower(argc,argv);
  erase();
  IrLineLeft_value = 1; //Both sensors detect the line after spinning
  IrLineRight_value = 1;

  mvprintw(1,1,"Phase 4 - Robot positioned on top of the line, oriented correctly");
  mvprintw(10,1,"Car should drive forward");
  Line_Follower(argc,argv);
  erase();
}



void Test_Situation_2(int argc, char *argv[]){
  //Test function will mimic the following situation:
  //Robot will be positioned to much to the left side (oriented parallelly to the line), thus, 
  //the line follower will be set to 0 on the left side, but, set to 1 on the right side. There will not be any objects in front of the robot.
  //Therefore, it should:
  //-Spin right (until it alignes both sensors with the line). The robot will not be oriented correctly yet (will be aiming slightly towards the right.)
  //-Drive forward (until it loses the line on the right sensor, as it will be moving diagonally to the right.)
  //-Spin left (until it alignes both sensors with the line, finally with the correct orientation.)
  //-Drive forward

  IrLeft_value = 0; // No object ahead
  IrRight_value = 0;

  IrLineLeft_value = 0; //Robot offset towards the left side, thus, IrLineLeft_value = 0 and IrLineRight_value = 1
  IrLineRight_value = 1;

  mvprintw(1,1,"Phase 1 - Robot positioned on left side of the line");
  mvprintw(10,1,"Car should spin right");
  Line_Follower(argc,argv);
  IrLineLeft_value = 1; //Both sensors detect the line, after spinning
  IrLineRight_value = 1;
  erase();

  mvprintw(1,1,"Phase 2 - Robot positioned on top of the line, oriented diagonally");
  mvprintw(10,1,"Card should drive forward");
  Line_Follower(argc,argv);
  IrLineLeft_value = 1; //Right sensor lost the line after moving forward
  IrLineRight_value = 0;
  erase();

  mvprintw(1,1,"Phase 3 - Robot positioned on right side of the line");
  mvprintw(10,1,"Card should spin left");
  Line_Follower(argc,argv);
  IrLineLeft_value = 1; //Both sensors detect the line after spinning
  IrLineRight_value = 1;
  erase();

  mvprintw(1,1,"Phase 4 - Robot positioned on top of the line, oriented correctly");
  mvprintw(10,1,"Car should drive forward");
  Line_Follower(argc,argv);
  erase();
}



void Test_Situation_3(int argc, char *argv[]){
  //Test function will mimic the following situation:
  //Robot lost the line. Therefore it should stop.

  IrLeft_value = 0; // No object ahead
  IrRight_value = 0;

  IrLineLeft_value = 0; //Robot lost the line, thus, IrLineLeft_value = 0 and IrLineRight_value = 0
  IrLineRight_value = 0;

  mvprintw(1,1,"Phase 1 - Robot lost the line");
  mvprintw(10,1,"Car should stop");
  Line_Follower(argc,argv);
  erase();
}


void Test_Situation_4(int argc, char *argv[]){
  //Test function will mimic the following situation:
  //Robot will move forward with no objects ahead.
  //Robot will have an object being detected by its IR sensors, making the robot stop.
  //Object will move away, making the robot restart to move forward.

  IrLeft_value=0; //Initially no object ahead
  IrRight_value=0;

  mvprintw(1,1,"Phase 1 - Robot does not have any objects ahead");
  mvprintw(10,1,"Robot should move forward.");
  Obstacle_Avoidance(argc, argv);
  erase();

  IrLeft_value=1; //Both IR sensors detect an object
  IrRight_value=1;

  mvprintw(1,1,"Phase 2 - Robot has objects ahead");
  mvprintw(10,1,"Robot should stop when detecting the object.");
  Obstacle_Avoidance(argc, argv);
  erase();

  IrLeft_value=0; //Object moves away, and IR sensors do not detect an object
  IrRight_value=0;

  mvprintw(1,1,"Phase 3 - Robot does not have any objects ahead, obstacle moved away");
  mvprintw(10,1,"Robot should restart moving forward.");
  Obstacle_Avoidance(argc, argv);
  erase();
}


//======================================================================
// Main Loop
//======================================================================

int main (int argc, char *argv[])
{
  WINDOW *mainwin = initscr();  // curses: init screen
  noecho();                    // curses: prevent the key being echoed
  cbreak();                     // curses: disable line buffering 
  nodelay(mainwin, TRUE);       // curses: set getch() as non-blocking 
  keypad (mainwin, TRUE);       // curses: enable detection of cursor and other keys

  initio_Init ();               // initio: init the library


  //Test Functions
  Test_LineFollower_FrontObject(argc,argv);
  Test_LineFollower_LeftObject(argc,argv);
  Test_LineFollower_NoObject(argc,argv);
  Test_LineFollower_RightObject(argc,argv);
  Test_ObstacleAvoidance(argc,argv);
  Test_Situation_1(argc,argv);
  Test_Situation_2(argc,argv);
  Test_Situation_3(argc,argv);
  Test_Situation_4(argc,argv);
  


  //Obstacle_Avoidance(argc, argv); // commented out as it won't be used in this current implementation 
  //Line_Follower(argc, argv); // commented out as it won't be used in this current implementation
  endwin();           // curses: cleanup the library
  return EXIT_SUCCESS;
}