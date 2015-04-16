import java.util.logging.*;
import java.io.*;

public class Example {

	private static Logger logger = Logger.getLogger(Example.class.getName());

	public static void  main(String[] args){
		try {
			LogManager.getLogManager().readConfiguration(
					Example.class.getResourceAsStream("./logging.properties"));
		} catch (IOException e) {
			System.err.println("Could not setup logger configuration: " + e.toString());
		}
		
		logger.finest("1 message");
		logger.finer("2 message");
		logger.fine("3 message");
		logger.config("4 message");
		logger.info("5 message");
		logger.warning("6 message");
		logger.severe("7 message");
		logger.severe("8 message");
		logger.warning("9 message");
		logger.info("10 message");
		logger.config("11 message");
		logger.fine("12 message");
		logger.finer("13 message");		
		logger.finest("14 message");		
	}
}
