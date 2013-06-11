package pubsub.edl2.frontendComposite;

import java.util.*;
import java.io.*;
import java.util.regex.*;
import pubsub.edl2.middlend.*;
import pubsub.edl2.symbols.*;

public class ParserWrapper{
	// Configuration stuff
	private String constantClassName;

	// Compiler stuff
	private GenericTreeNode root;
	private SymbolTable table;
	Parser p;

	public GenericTreeNode getRoot() {
		return root;
	}
	public SymbolTable getTable() {
		return table;
	}
	public void parse(Reader reader) {
		p = new Parser(new Lexer(reader));
		try {
			p.parse();
			root = p.getRoot();
			root.adjust();
			root.traverse(0);
			table = new SymbolTable();
			TypeChecker tc = new TypeChecker();
			try {
				System.out.println("Constructing table...");
				tc.constructTable(root, table);
				//root.constructTable(table);
			} catch (SymbolRedeclarationException e) {
				e.printStackTrace();
			}
			try {
				System.out.println("Type checking...");
				tc.staticTypeCheck(root, table);
				System.out.println("Finished type checking");
			} catch (Exception e) {
				e.printStackTrace();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
