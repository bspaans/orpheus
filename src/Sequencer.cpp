#include "model.h"

Sequencer::Sequencer(Synth *s)
{
	synth = s;
	playing = true;
	tick = 0.0;
}


void
Sequencer::play()
{
	Message msg(PLAY);
	while (playing) 
	{
		msg.ivalue = tick;
		notify_instruments(msg);
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
	tick++;
	(*synth).sleep(DTICK * 1000);
}


void
Sequencer::notify(Message msg)
{
	if (msg.mtype == PLAY)
	{
		(*synth).play_NoteContainer(msg.notes, 1, 75);
	}
}


void
Sequencer::notify_instruments(Message msg)
{
	std::vector<Instrument>::iterator iter = instruments.begin();

	while (iter < instruments.end()) 
	{
		(*iter).notify(msg);
		iter++;
	}
}


void
Sequencer::attach(Instrument instr)
{
	instruments.push_back(instr);

}
