#include "model.h"
using namespace std;

int
main(int argc, char **argv)
{
	cout << "Oprheus 0.1, Copyright (C) 2009, Bart Spaans\n";


	Synth synth;
	synth.init("alsa", "/home/bspaans/workspace/fluidsynth/ChoriumRevA.SF2");
	Sequencer s(&synth);

	Instrument i;
	Instrument i2;
	std::string iname("Instrument");
	std::string i2name("Instr");
	i.name = iname;
	i2.name = i2name;
	i.attach(&s);
	i2.attach(&s);
	s.attach(i);
	s.attach(i2);


	s.play();
	return 0;
}
