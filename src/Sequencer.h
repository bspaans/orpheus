class Sequencer {

	public:
		Sequencer();
		void play();
		void stop();
		void sync();
		void notify();
		void attach(Instrument instr);

	private:
		std::vector<Instrument> instruments[];
		signed float tick;
		int bars;
		int current_bar;
		bool playing;
		void notify_instruments();
		void tick();
		void bar_tick();

};
