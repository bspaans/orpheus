class Sequencer {

	public:
		Sequencer();
		void play();
		void stop();
		void sync();
		void notify();
		void attach(Instrument instr);

	private:
		std::vector<Instrument> instruments;
		float tick;
		bool playing;

		void notify_instruments();
		void bar_tick();
};
