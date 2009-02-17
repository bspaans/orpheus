#include "model.h"


Instrument::Instrument()
{
	duration = 0.0;
	algorithm = NULL;
	channel = 1;
	following = NO_FOLLOW;
}



void
Instrument::notify(Message msg)
{
	switch(msg.mtype)
	{
		case PLAY:
			play(); break;
		case FOLLOW:
			follow(msg.notes, msg.fvalue, msg.ivalue); break;
	}
}



void
Instrument::play()
{
	if (following == NO_FOLLOW && algorithm != NULL) 
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

	Message msg(FOLLOW);
	msg.ivalue = channel;
	msg.fvalue = duration;
	duration = dur;
	msg.notes = n;

	if (following == FOLLOW_RHYTHM && algorithm != NULL)
	{
		if (n.notes.size() != 0)
			msg.notes = (*algorithm).get_notes();

		notify_instruments(msg);
		msg.mtype = PLAY;
		notify_sequencer(msg);
	}
	else if (following == FOLLOW_MELODY)
	{

		notify_instruments(msg);
		msg.mtype = PLAY;
		notify_sequencer(msg);
	}
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
