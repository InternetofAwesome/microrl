#include <stdio.h>
#include <string.h>
#include "../src/microrl.h"
#include "example_misc.h"

// create microrl object and pointer on it
microrl_t rl;
microrl_t * prl = &rl;
microrl_entry_t entries[] = {
		{"example", "Enter any number of arguments. Returns an error if nothing entered.", example},
		{"execute", "Provided as an example of autocomplete", NULL}};

//*****************************************************************************
int main (void/*int argc, char ** argv*/)
{
	init ();
	// call init with ptr to microrl instance and print callback
	prl->entries = entries;
	prl->num_entries = sizeof(entries)/sizeof(entries[0]);
	microrl_init (prl, print);
	// set callback for Ctrl+C
	microrl_set_sigint_callback (prl, sigint);
	while (1) {
		// put received char from stdin to microrl lib
		microrl_insert_char (prl, get_char());
	}
	return 0;
}

int example(int argc, const char* const * argv)
{
	int i;
	if(argc > 1)
	{
		for(i=1; i<argc; i++)
		{
			printf("arg %d: %s\n", i, argv[i]);
		}
		return 0;
	}
	else
	{
		print("No arguments entered.\n");
		return 1;
	}

}