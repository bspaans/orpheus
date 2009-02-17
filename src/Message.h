typedef enum msg_type {
	PLAY,
	STOP
} msg_type;

class Message {

	public:
		Message(msg_type);

		NoteContainer notes;
		int ivalue;
		float fvalue;
		std::string svalue;
		msg_type mtype;

};
