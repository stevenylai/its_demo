includes AM;
interface MsgBuffer {
	command TOS_MsgPtr getBuffer();
	command bool checkAvailBuffer();
	command void returnBuffer(TOS_MsgPtr avail);
}
