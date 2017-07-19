#ifndef _MICRORL_MISC_H_
#define _MICRORL_MISC_H_

/*
Platform independent interface for implementing some specific function
for AVR, linux PC or ARM
*/

// init platform
void init (void);

// print to stream callback
void print (const char * str);

// get_char from stream
char get_char (void);

// ctrl+c callback
void sigint (void);

int example(int argc, const char* const * argv);

#endif
