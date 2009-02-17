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
	tick += 0.01;
	(*synth).sleep(10);
	float dtick = 4.0 / (0.01 / (60.0 / bpm));
	std::vector<Instrument>::iterator iter = instruments.begin();
	while (iter < instruments.end()) 
	{
		(*iter).duration = subtract_values((*iter).duration, dtick);
		iter++;
	}
}


void
Sequencer::notify(Message msg)
{
	if (msg.mtype == PLAY)
	{
		(*synth).play_NoteContainer(msg.notes, msg.ivalue, 75);
	}
}


void
Sequencer::notify_instruments(Message msg)
{
	std::vector<Instrument>::iterator iter = instruments.begin();

	while (iter < instruments.end()) 
	{
		if ((*iter).duration <= 0.0)
			(*iter).notify(msg);
		iter++;
	}
}


void
Sequencer::attach(Instrument instr)
{
	instruments.push_back(instr);

}
