import java.util.*;
import java.io.*;
import net.tinyos.util.*;
import net.tinyos.message.*;

public class MoteIFAck extends MoteIF implements MessageListener, Runnable {
	public static int TOS_UART_ADDR=0x007e;
	public static int TOSH_HEADER_ACK_LENGTH=0x007e;
	public static short MSG_SEND=0xff;
	public static short MSG_ACK=0xfe;
	public static short MSG_BCAST=0xfd;
	ArrayList<MessageListener>listeners;
	ArrayList<Message>msgTemplate;

	public MoteIFAck () {
		MsgACK msg = new MsgACK();
		super.registerListener(msg, this);
		this.listeners=new ArrayList<MessageListener>();
		this.msgTemplate=new ArrayList<Message>();
	}
	public void send(int dest_addr, Message msg) throws IOException {
		// WARNING: may not work!!!
		byte[] data = new byte [msg.dataGet().length+MoteIFAck.TOSH_HEADER_ACK_LENGTH];
		for (int i=0; i<msg.dataGet().length; i++) {
			data[i]=msg.dataGet()[i];
		}
		MsgACK wrapper = new MsgACK(data, msg.dataGet().length);
		wrapper.set_am_type((short)msg.amType());
		wrapper.set_type((short)MoteIFAck.MSG_SEND);
		wrapper.set_source(MoteIFAck.TOS_UART_ADDR);

		Message toSend = msg.clone(data.length);
		toSend.dataSet(data);
		super.send(dest_addr, wrapper);
	}
	public void messageReceived(int dest_addr, Message msg) {
		int msg_len=msg.dataGet().length-MoteIFAck.TOSH_HEADER_ACK_LENGTH;
		MsgACK ackMsg = new MsgACK(msg.dataGet(), msg_len);
		int am_type=(int)ackMsg.get_am_type();
		System.out.println("Message received, length: "+msg_len+", am: "+am_type);
		for (int i=0; i<this.listeners.size(); i++) {
			int listenerType = this.msgTemplate.get(i).amType();
			System.out.println("Checking listeners: "+i+", am: "+listenerType);
			if (listenerType==am_type) {
				Message stripped_msg = msgTemplate.get(i).clone(msg_len);
				stripped_msg.dataSet(msg.dataGet());
				stripped_msg.amTypeSet(am_type);
				this.listeners.get(i).messageReceived(dest_addr, stripped_msg);
			}
		}
		// Send ACK here if necessary
	}
	public void registerListener(Message m, MessageListener listener) {
		this.msgTemplate.add(m);
		this.listeners.add(listener);
	}
	public void run() {
		while (true)
			try {
				Thread.sleep(500);
			} catch (Exception e) {
				e.printStackTrace();
			}
	}
}
