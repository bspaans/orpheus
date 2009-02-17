class InstrumentOptions {

	public:
		bool should_play(float tick);
		float wildness;

	private:
		std::vector<float> play_ranges[];
};
