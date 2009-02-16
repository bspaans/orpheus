#include "model.h"

Sequencer::Sequencer(Synth *s)
{
	synth = s;
	playing = true;
	
}


void
Sequencer::play()
{
	while (playing) 
	{
		(*synth).play_Note(Note("C"), 1, 100);
		notify_instruments();
		sync();
		(*synth).stop_Note(Note((char *)"C"), 1);
	}
}


void
Sequencer::stop()
{
	playing = false;

}



void
Sequencer::sync()
{
	tick += DTICK;
	std::cout << tick << "\n";
	(*synth).sleep(DTICK * 1000);
}


void
Sequencer::notify()
{


}


void
Sequencer::notify_instruments()
{
	std::vector<Instrument>::iterator iter = instruments.begin();

	while (iter < instruments.end()) 
	{
		(*iter).notify();
		iter++;
	}
}


void
Sequencer::attach(Instrument instr)
{
	instruments.push_back(instr);

}
