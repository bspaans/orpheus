#include "model.h"


void
Instrument::notify(Message msg)
{
	std::cout << name << msg.ivalue << '\n';
	if (msg.mtype == PLAY)
		play();
}



void
Instrument::play()
{
	Message msg(PLAY);
	NoteContainer n;
	n.add_note((char *)"C#");
	n.add_note((char *)"E#");
	n.add_note((char *)"F");
	msg.notes = n;
	notify_instruments(msg);
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
	(*seq).notify(msg);
}
