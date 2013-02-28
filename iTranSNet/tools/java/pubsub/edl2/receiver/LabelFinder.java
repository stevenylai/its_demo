package pubsub.edl2.receiver;

import java.util.*;
import java.util.regex.*;

public class LabelFinder {
	public String label;
	public Vector <String> codes;
	Pattern regexp;
	public LabelFinder() {
		regexp = Pattern.compile("(\\w+:\\s*)?(\\w+)(\\s*\\w+)?");
	}
	public LabelFinder(String label, Vector <String> codes) {
		this();
		this.label=label;
		this.codes=codes;
	}
	public int getIdx() {
		for (int i=0; i<codes.size(); i++) {
			String instr = codes.get(i);
			Matcher match = regexp.matcher(instr);
			if (!match.matches()) {
				continue;
			}
			String label = match.group(1);
			if (label!=null)
				label=label.replace(':', ' ').trim();
			if (label!=null && label.equals(this.label))
				return i;
		}
		return -1;
	}
}
