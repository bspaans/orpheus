#include "model.h"

Sequencer::Sequencer()
{
	
}


void
Sequencer::play()
{
	playing = true;
}


void
Sequencer::stop()
{
	playing = false;

}


void
Sequencer::instrument_tick()
{
	if (playing && current_bar < bars) 
	{
		notify_instruments();
		sync();
	}
}



void
Sequencer::sync()
{
	tick += DTICK;
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
