#include "model.h"

Swing8::Swing8() {
	counter = 0;
}


NoteContainer
Swing8::get_notes()
{
	NoteContainer n;
	counter++;
	n.add_note(Note((char *)"C", 4));
	return n;
}

float
Swing8::get_duration()
{
	if (counter % 2 == 0)
		return 12;
	return 6;
}
