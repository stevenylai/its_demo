public class CarTest {
    public UART port;
    public byte counter;
    public byte [] input;
    public byte [] output;

    public CarTest(UART port, int id) {
	this.port = port;
	this.counter = (byte)0xF0;
	this.input = new byte[6];
	this.input[0] = (byte)0xFF;
	this.input[1] = (byte)4;
	this.input[2] = (byte)id;
	this.output = new byte[5];
    }
    public boolean validated(byte[]output, int len) {
	if (len < this.output.length)
	    return false;
	else {
	    if (output[0] != (byte)0xFF)
		return false;
	    if (output[1] != this.input[2])
		return false;
	    for (int i = 2; i < len; i++) {
		if (output[i] != (byte)(this.counter & 0xFF))
		    return false;
	    }
	    return true;
	}
    }
    public void test() {
	while (true) {
	    for (int i = 3; i < this.input.length; i++) {
		this.input[i] = this.counter;
	    }
	    //System.out.println("Writing: " + String.format("0x%02X ", this.counter));
	    this.port.writeBytes(this.input);
	    boolean finished = false;

	    while (!finished) {
		int read = this.port.readBytes(output);
		if (this.validated(output, read)) {
		    this.counter = (byte)(this.counter + 1);
		    if (this.counter == (byte)0xFE) {
			this.counter = (byte)0;
		    }
		    finished = true;
		} else {
		    System.out.print("Error in getting input. Expected: " + String.format("0x%02X ", this.counter));
		    System.out.print(". Actual: ");
		    for (int i = 0; i < read; i++)
			System.out.print(String.format("0x%02X ", output[i]) + " ");
		    System.out.println("");
		}
	    }
	    /*
	    try {
		Thread.sleep(100);
	    } catch (Exception e) {}
	    */
	}
    }
    public static void main(String[] args) {
	UART port = new UART();
	if (port.open("COM20", 9600) != null) {
	    CarTest tester = new CarTest(port, 1);
	    tester.test();
	}
    }
}