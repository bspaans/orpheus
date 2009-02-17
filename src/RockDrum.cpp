#include "model.h"

RockDrum::RockDrum()
{
	counter = 1;
}

NoteContainer
RockDrum::get_notes()
{
	NoteContainer n;
	n.add_note(Note("A#", 2));

	if (counter == 1)
		n.add_note(Note("C", 2));
	else if (counter == 5)
		n.add_note(Note("E", 2));

	counter++;
	if (counter > 8)
		counter = 1;
	return n;
}


float
RockDrum::get_duration()
{	
	return 8.0;
}
