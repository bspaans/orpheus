class RockDrum: public ImprovisationAlgorithm {
	public:
		RockDrum();
		NoteContainer get_notes();
		float get_duration();

	private:
		int counter;
};
