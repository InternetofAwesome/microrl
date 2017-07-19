#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h> 
#include <string.h>
#include "../../src/config.h"

//*****************************************************************************
//dummy function, no need on linux-PC
void init (void){
};

//*****************************************************************************
// print callback for microrl library
void print (const char * str)
{
	fprintf (stdout, "%s", str);
	fflush(stdout);
}


//*****************************************************************************
// get char user pressed, no waiting Enter input
char get_char (void)
{
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}


//*****************************************************************************
void sigint (void)
{
	print ("^C catched!\n\r");
}
