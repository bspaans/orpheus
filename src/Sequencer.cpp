#include "model.h"

Sequencer::Sequencer()
{
	playing = true;
	
}


void
Sequencer::play()
{
	while (playing) 
	{
		notify_instruments();
		sync();
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
	//sleep(DTICK)
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
