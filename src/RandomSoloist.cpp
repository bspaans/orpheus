#include "model.h"
	

RandomSoloist::RandomSoloist()
{

}


NoteContainer
RandomSoloist::get_notes()
{
	NoteContainer n;
	Note no;
	no.from_int(rand() % 127);
	n.add_note(no);
	return n;
}


float
RandomSoloist::get_duration()
{
	return 8.0;
}
