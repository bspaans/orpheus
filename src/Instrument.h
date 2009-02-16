class Instrument {

	public:
		void play();
		void attach(Instrument instr);
		void notify();

		std::string name;
	private:
		//InstrumentOptions options;
		//ImprovisationAlgorithm algorithm;
		int GUID;
};
