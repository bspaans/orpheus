extern "C" class Sequencer;

class Instrument {

	public:
		void play();
		void attach(Instrument instr);
		void attach(Sequencer *sequencer);
		void notify(Message msg);

		std::string name;
		std::vector<Instrument> following_instr;
		Sequencer *seq;
	private:
		//InstrumentOptions options;
		//ImprovisationAlgorithm algorithm;
		int GUID;
		void notify_instruments(Message msg);
		void notify_sequencer(Message msg);
};
