#include "Sequencer.h"
#define TICKS_PER_SEC 50.0
#define DTICK (1.0 / TICKS_PER_SEC)


Sequencer::Sequencer()
{
	
}



Sequencer::play()
{
	playing = true;
}


Sequencer::stop()
{
	playing = false;

}


Sequencer::tick()
{
	if (playing && current_bar < bars) 
	{
		notify_instruments();
		sync();
	}
}

Sequencer::sync()
{
	tick += DTICK;
	//sleep(DTICK)
}


Sequencer::notify()
{


}


Sequencer::notify_instruments()
{
	std::vector<Instrument>::iterator iter = instruments.begin();

	while (iter < instruments.end()) 
	{
		(*iter).notify();
		*iter++;
	}
}



Sequencer::attach(Instrument instr)
{
	instruments.push_back(instr);

}
