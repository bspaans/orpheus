class Sequencer {

	public:
		Sequencer(Synth *s, Options *o);
		void play();
		void stop();
		void sync();
		void notify(Message);
		void attach(Instrument instr);
		Synth *synth;
		float bpm;


	private:
		Options *options;
		std::vector<Instrument> instruments;
		float tick;
		bool playing;

		void notify_instruments(Message);
		void bar_tick();
};
