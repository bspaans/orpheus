class Sequencer {

	public:
		Sequencer(Synth *s);
		void play();
		void stop();
		void sync();
		void notify(Message);
		void attach(Instrument instr);
		Synth *synth;

	private:
		std::vector<Instrument> instruments;
		float tick;
		bool playing;

		void notify_instruments(Message);
		void bar_tick();
};
