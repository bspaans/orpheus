#include "model.h"
using namespace std;

int
main(int argc, char **argv)
{
	cout << "Orpheus 0.1, Copyright (C) 2009, Bart Spaans\n";
	Options o;
	o.parse_cli_arguments(argc, argv);

	// Get sequencer from options
	Sequencer s = o.get_sequencer();

	// Initialize instruments
	Instrument i;
	Instrument i2;


	Swing8 r;
	RandomSoloist ra;


	i.algorithm = &r;
	i.channel = 9;
	i2.algorithm = &ra;

	i2.following = FOLLOW_MELODY;
	std::string iname("Instrument");
	std::string i2name("Instr");
	i.name = iname;
	i2.name = i2name;

	i.attach(&s);
	i2.attach(&s);

	i.attach(i2);
	s.attach(i);
	s.attach(i2);


	s.play();
	return 0;
}
