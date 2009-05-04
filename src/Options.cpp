#include "model.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


Options::Options()
{
	bpm = 120;
	driver = "";
	soundfont = "default.sf2";
	verbose = false;
}


void
Options::parse_cli_arguments(int argc, char **argv)
{
	int c;

	opterr = 0;

	while (( c = getopt(argc, argv, "b:d:s:v")) != -1)
		switch(c) 
		{
			case 'b': bpm = atof(optarg); break;
			case 'd': driver = optarg; break;
			case 's': soundfont = optarg; break;
			case 'v': verbose = true; break;
		}
}


void
Options::output_options()
{
	std::cout << "============================================================================\n\n";
	std::cout << "Driver: " << driver << '\n';
	std::cout << "Soundfont: " << soundfont << '\n';
	std::cout << "Bpm: " << bpm << "\n\n";
	std::cout << "============================================================================\n\n";
}


Sequencer
Options::get_sequencer()
{
	if (verbose) output_options();
	synth.init(driver, soundfont);
	Sequencer s(&synth, this);
	s.bpm = bpm;
	return s;
}



