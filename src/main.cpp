#include "model.h"
using namespace std;

int
main(int argc, char **argv)
{
	cout << "Oprheus 0.1\n";

	Synth synth;
	synth.init("alsa", "/home/bspaans/workspace/fluidsynth/ChoriumRevA.SF2");
	synth.play_Note(Note("C"), 1, 100);
	Sequencer s(&synth);

	s.play();
	return 0;
}
