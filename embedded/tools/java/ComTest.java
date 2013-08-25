import javax.comm.*;
import java.util.*;
import java.io.*;

public class ComTest {
  public Enumeration portIdentifiers;
  public SerialPort port;
  public InputStream inStream;
  public OutputStream outStream;

  public ComTest() {
    this.portIdentifiers = CommPortIdentifier.getPortIdentifiers();
    this.port = null;
    this.inStream = null;
    this.outStream = null;
  }
  public SerialPort open(String portName, int baudrate) {
    CommPortIdentifier portId = null;
    while (this.portIdentifiers.hasMoreElements()) {
      CommPortIdentifier pid = (CommPortIdentifier) portIdentifiers.nextElement();
      if(pid.getPortType() == CommPortIdentifier.PORT_SERIAL && pid.getName().equals(portName)) {
        portId = pid;
      } else if (pid.getPortType() == CommPortIdentifier.PORT_SERIAL) {
        System.out.println("Port: " + pid.getName() + " is not what we want");
      }
    }
    if (portId == null) {
      System.out.println("Port not found: " + portName);
      return null;
    }
    try {
      this.port = (SerialPort) portId.open(
        "ComTest", // Name of the application asking for the port 
        10000   // Wait max. 10 sec. to acquire port
      );
    } catch(PortInUseException e) {
      System.err.println("Port already in use: " + e);
      return null;
    }
    try {
      // Default parameters
      this.port.setSerialPortParams(
        baudrate,
        SerialPort.DATABITS_8,
        SerialPort.STOPBITS_1,
        SerialPort.PARITY_NONE);
      this.inStream = this.port.getInputStream();
      this.outStream = this.port.getOutputStream();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
    return this.port;
  }

  public int readBytes(byte[] b) {
    try {
      return this.inStream.read(b);
    } catch(IOException e) {
      return 0;
    }
  }
  public void writeBytes(byte[] b) {
    try {
      this.outStream.write(b);
    } catch(IOException e) {
    }
  }
  public void close() {
    try {
      if (this.inStream != null) this.inStream.close();
      if (this.outStream != null) this.outStream.close();
      if (this.port != null) this.port.close();
    } catch(IOException e) {
    }
  }
  public static String byteString (byte [] b, int length) {
    String output = "";
    for (int i = 0; i < length; i++) {
      output += String.format("0x%02X ", b[i]);
    }
    return output;
  }
  public static void main(String[] args) {
    ComTest test = new ComTest();
    byte [] input = new byte [] {(byte)0xFF, (byte)0x04, (byte)0x00, (byte)0x10, (byte)0x00, (byte)0x0A};
    byte [] output = new byte[16];
    if (test.open("COM2", 9600) != null) {
      for (int i = 0; i < 1; i++) {
        System.out.println("Writing: " + byteString(input, input.length));
        test.writeBytes(input);
      }
      int read = test.readBytes(output);
      System.out.println("Read: " + byteString(output, read));
    } else {
      System.out.println("Error opening the serial port!");
    }
  }
}
