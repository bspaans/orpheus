#include "model.h"
using namespace std;

int
main(int argc, char **argv)
{
	cout << "Oprheus 0.1, Copyright (C) 2009, Bart Spaans\n";
	Options o;
	o.parse_cli_arguments(argc, argv);

	Sequencer s = o.get_sequencer();

	Instrument i;
	Instrument i2;
	RockDrum r;
	i.algorithm = &r;
	i.channel = 9;
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
