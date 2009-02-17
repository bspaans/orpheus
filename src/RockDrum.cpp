#include "model.h"

RockDrum::RockDrum()
{
	counter = 1;
}

NoteContainer
RockDrum::get_notes()
{
	NoteContainer n;
	if (RANDOM() <= 0.1)
		n.add_note(Note((char *)"A#", 2));
	else if (RANDOM() <= 0.1)
		n.add_note(Note((char *)"A#", 2));

	if (counter == 1){
		n.add_note(Note((char *)"C", 2));
		n.add_note(Note((char *)"C#", 3));
	}
	else if (counter == 5)
		n.add_note(Note((char *)"E", 2));
	else if (counter >= 7)
	{
		if (RANDOM() <= 0.2)
			n.add_note(Note((char *)"B", 2));
		else if (RANDOM() <= 0.2)
			n.add_note(Note((char *)"A", 2));
	}

	counter++;
	if (counter > 8)
		counter = 1;
	return n;
}


float
RockDrum::get_duration()
{	
	// swing
	if (counter % 2 == 0)
		return triplet(8.0);
	else
		return subtract_values(8.0, triplet(8.0));
}
