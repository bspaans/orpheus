extern "C" class Sequencer;

class Instrument {

	public:
		Instrument();
		void play();
		void follow(NoteContainer, float, int);
		void attach(Instrument instr);
		void attach(Sequencer *sequencer);
		void notify(Message msg);

		std::string name;
		std::vector<Instrument> following_instr;
		Sequencer *seq;
		float duration;
		int channel;
		ImprovisationAlgorithm *algorithm;
	private:
		//InstrumentOptions options;
		int GUID;
		void notify_instruments(Message msg);
		void notify_sequencer(Message msg);
};
