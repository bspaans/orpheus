#include "model.h"


Instrument::Instrument()
{
	duration = 0.0;
	algorithm = NULL;
	channel = 1;
}



void
Instrument::notify(Message msg)
{
	switch(msg.mtype)
	{
		case PLAY:
			play();
			break;
		case FOLLOW:
			follow(msg.notes, msg.fvalue, msg.ivalue);
			break;
	}
}



void
Instrument::play()
{
	if (algorithm != NULL) 
	{
		Message msg(FOLLOW);
		msg.notes = (*algorithm).get_notes();
		duration = (*algorithm).get_duration();
		msg.ivalue = channel;
		msg.fvalue = duration;
		notify_instruments(msg);
		msg.mtype = PLAY;
		notify_sequencer(msg);
	}
}


void
Instrument::follow(NoteContainer n, float dur, int chan)
{
	if (n.notes.size() != 0)
		n.notes[0].octave++;

	duration = dur;
	Message msg(PLAY);
	msg.notes = n;
	msg.ivalue = channel;
	notify_sequencer(msg);
}

void
Instrument::attach(Instrument instr)
{
	following_instr.push_back(instr);
}


void
Instrument::attach(Sequencer *sequencer)
{
	seq = sequencer;
}



void
Instrument::notify_instruments(Message msg)
{
	std::vector<Instrument>::iterator iter = following_instr.begin();

	while (iter < following_instr.end()) 
	{
		(*iter).notify(msg);
		iter++;
	}
}



void
Instrument::notify_sequencer(Message msg)
{
	if (seq != NULL)
		(*seq).notify(msg);
}
