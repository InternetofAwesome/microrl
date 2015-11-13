#include <stdio.h>
#include <string.h>
#include "../src/microrl.h"
#include "example_misc.h"

// create microrl object and pointer on it
microrl_t rl;
microrl_t * prl = &rl;
microrl_entry_t entries[] = {{"list", "print a list", NULL},
		{"lister", "print a list", NULL},
		{"otherstuff", "Do something", NULL}};


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

