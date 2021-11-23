/*
No specific question
*/

// Java program for the above approach

import java.util.*;
import java.util.regex.*;
class GFG {

	// Function to extract all the URL
	// from the string
	public static void extractURL(
		String str)
	{

		// Creating an empty ArrayList
		List<String> list
			= new ArrayList<>();

		// Regular Expression to extract
		// URL from the string
		String regex
			= "\\b((?:https?|ftp|file):"
			+ "//[-a-zA-Z0-9+&@#/%?="
			+ "~_|!:, .;]*[-a-zA-Z0-9+"
			+ "&@#/%=~_|])";

		// Compile the Regular Expression
		Pattern p = Pattern.compile(
			regex,
			Pattern.CASE_INSENSITIVE);

		// Find the match between string
		// and the regular expression
		Matcher m = p.matcher(str);

		// Find the next subsequence of
		// the input subsequence that
		// find the pattern
		while (m.find()) {

			// Find the substring from the
			// first index of match result
			// to the last index of match
			// result and add in the list
			list.add(str.substring(
				m.start(0), m.end(0)));
		}

		// IF there no URL present
		if (list.size() == 0) {
			System.out.println("-1");
			return;
		}

		// Print all the URLs stored
		for (String url : list) {
			System.out.println(url);
		}
	}

	// Driver Code
	public static void main(String args[])
	{

		// Given String str
		String str
			= "Welcome to https:// www.geeksforgeeks"
			+ ".org Computer Science Portal";

		// Function Call
		extractURL(str);
	}
}
