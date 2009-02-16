class Sequencer {

	public:
		Sequencer(Synth *s);
		void play();
		void stop();
		void sync();
		void notify();
		void attach(Instrument instr);
		Synth *synth;

	private:
		std::vector<Instrument> instruments;
		float tick;
		bool playing;

		void notify_instruments();
		void bar_tick();
};
