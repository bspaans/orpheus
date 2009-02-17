extern "C" class Sequencer;

class Options {

	public:
		Options();
		void parse_cli_arguments(int argc, char **argv);
		void output_options();
		Sequencer get_sequencer();

		Synth synth;
		float bpm;
		char *driver;
		char *soundfont;
		bool verbose;
};
