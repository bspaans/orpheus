extern "C" class Sequencer;

class Options {

	public:
		Options();
		void parse_cli_arguments(int argc, char **argv);
		Sequencer get_sequencer();

		Synth synth;
		float bpm;
		char *driver;
		char *soundfont;
		bool debug;
		bool verbose;
};
