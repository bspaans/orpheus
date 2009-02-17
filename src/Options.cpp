#include "model.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


Options::Options()
{
	bpm = 120;
	driver = "";
	soundfont = "default.sf2";
}


void
Options::parse_cli_arguments(int argc, char **argv)
{
	int c;

	opterr = 0;

	while (( c = getopt(argc, argv, 
		"b:d:s:")) != -1)
		switch(c) 
		{
			case 'b':
				bpm = atof(optarg);
				break;
			case 's':
				soundfont = optarg;
				break;
			case 'd':
				driver = optarg;
				break;
		}

	std::cout << bpm << '\n';
	std::cout << driver << '\n';
	std::cout << soundfont << '\n';
}


Sequencer
Options::get_sequencer()
{
	synth.init(driver, soundfont);
	Sequencer s(&synth);
	return s;
}



