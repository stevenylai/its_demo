/*
 * @(#)SimpleRead.java	1.12 98/06/25 SMI
 * 
 * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 * 
 * Sun grants you ("Licensee") a non-exclusive, royalty free, license
 * to use, modify and redistribute this software in source and binary
 * code form, provided that i) this copyright notice and license appear
 * on all copies of the software; and ii) Licensee does not utilize the
 * software in a manner which is disparaging to Sun.
 * 
 * This software is provided "AS IS," without a warranty of any kind.
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN AND
 * ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
 * LICENSEE AS A RESULT OF USING, MODIFYING OR DISTRIBUTING THE
 * SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL SUN OR ITS LICENSORS
 * BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT,
 * INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES,
 * HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING
 * OUT OF THE USE OF OR INABILITY TO USE SOFTWARE, EVEN IF SUN HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * 
 * This software is not designed or intended for use in on-line control
 * of aircraft, air traffic, aircraft navigation or aircraft
 * communications; or in the design, construction, operation or
 * maintenance of any nuclear facility. Licensee represents and
 * warrants that it will not use or redistribute the Software for such
 * purposes.
 */
import java.io.*;
import java.util.*;
import javax.comm.*;

/**
 * Class declaration
 *
 *
 * @author
 * @version 1.8, 08/03/00
 */
public class SerialTest implements Runnable, SerialPortEventListener {
	CommPortIdentifier portId;
	Enumeration		  portList;
	InputStream			  inputStream;
	OutputStream       outputStream;
	SerialPort			  serialPort;
	Thread			  readThread;
	byte [] message={(byte)0xff, (byte)0xfe, (byte)0xfe, (byte)0xfe, (byte)0xfe, (byte)0xfe, (byte)0xfe};

	public static void main(String args[]) {
		SerialTest test;
		if (args.length>0) {
			test=new SerialTest(args[0]);
		} else {
			test=new SerialTest();
		}
		test.open();
		test.read();
		test.write();
	}

	public SerialTest () {
		this("COM1");
	}
	public SerialTest (String defaultPort) {
		boolean	portFound = false;

		portList = CommPortIdentifier.getPortIdentifiers();

		while (portList.hasMoreElements()) {
			portId = (CommPortIdentifier) portList.nextElement();
			if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
				if (portId.getName().equals(defaultPort)) {
					System.out.println("Found port: "+defaultPort);
					portFound = true;
					break;
				} 
			} 
		}
		if (!portFound) {
			System.out.println("port " + defaultPort + " not found.");
		}
 	
	}

	public void open() {
		try {
			serialPort = (SerialPort) portId.open("SerialTest", 2000);
		} catch (PortInUseException e) {
			System.out.println("Port in use.");
		}
   	}
	public void write() {
		try {
			outputStream = serialPort.getOutputStream();
		} catch (IOException e) {
			System.out.println("Write failed.");
		}
		try {
			serialPort.setSerialPortParams(57600, SerialPort.DATABITS_8, 
					   SerialPort.STOPBITS_1, 
					   SerialPort.PARITY_NONE);
		} catch (UnsupportedCommOperationException e) {}

		try {
			serialPort.notifyOnOutputEmpty(true);
		} catch (Exception e) {
			System.out.println("Error setting event notification");
			System.out.println(e.toString());
			System.exit(-1);
		}
		try {
			outputStream.write(message);
		} catch (IOException e) {}
	}
	public void read() {
		try {
			inputStream = serialPort.getInputStream();
		} catch (IOException e) {}

		try {
			serialPort.addEventListener(this);
		} catch (TooManyListenersException e) {}

		serialPort.notifyOnDataAvailable(true);

		try {
			serialPort.setSerialPortParams(57600, SerialPort.DATABITS_8, 
					   SerialPort.STOPBITS_1, 
					   SerialPort.PARITY_NONE);
		} catch (UnsupportedCommOperationException e) {}

		readThread = new Thread(this);

		readThread.start();
	}

	/**
	 * Method declaration
	 *
	 *
	 * @see
	 */
	public void run() {
	try {
		Thread.sleep(20000);
	} catch (InterruptedException e) {}
	} 

	/**
	 * Method declaration
	 *
	 *
	 * @param event
	 *
	 * @see
	 */
	public void serialEvent(SerialPortEvent event) {
		switch (event.getEventType()) {

			case SerialPortEvent.BI:

			case SerialPortEvent.OE:

			case SerialPortEvent.FE:

			case SerialPortEvent.PE:

			case SerialPortEvent.CD:

			case SerialPortEvent.CTS:

			case SerialPortEvent.DSR:

			case SerialPortEvent.RI:

			case SerialPortEvent.OUTPUT_BUFFER_EMPTY:
				break;

			case SerialPortEvent.DATA_AVAILABLE:
				byte[] readBuffer = new byte[20];

			try {
				while (inputStream.available() > 0) {
					int numBytes = inputStream.read(readBuffer);
					for (int i=0; i<numBytes; i++) {
						System.out.print("0x" + Integer.toHexString(unsignedByteToInt(readBuffer[i]))+" ");
					}
				}
			} catch (IOException e) {}
			break;
		}
	}
	public static int unsignedByteToInt(byte b) {
		return (int) b & 0xFF;
	}
}
