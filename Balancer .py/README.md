# This program explores parsing strings and working with files in Python.

The Python script shall open a Java source file (or can be C / C++, any source code file that follows the convention of commenting out a line of code by "//" or with multi line comments "/* */") specified in the *command line argument* provided at run-time, strip it of comments and save the comment-free version in a new file. The script will then verify that the source file meets the rudimentary syntax for balanced parantheses, brackets, and braces. That is, every opening punctuation requires matching closing punctuation. A left curly-bracket requires a right curly-bracket for balance

**To run the Python Script use ```python /path/to/balanced.py /path/to/Driver.java``` make sure the command line arguments are spaced out. If you open the shell / terminal in the same directory as the files there's no need to specify the path to the files in the arguments, you can just use the program names.**

### Comments
The delivered solution shall ignore the symbols if they appear in a comment. Recall that you may comment out a line of code by either using the // symbol sequence or by starting a older, c-style multi-line comment using /* and */. Before balancing the source file, the Python script shall strip the specified input Java file of all its comments. It shall then save the comment-free version of the input file using the same name as the input file but with .nocom as the file extension.

**Comment symbols inside strings, such as "Hello these are two slashes//" will not be removed as they're not actually comments, they're still technically strings**

**Opening / Closing parantheses, brackets, braces symbols inside strings, such as "{(([Hello these are symbols}}}])" will not be looked at for balancing as they're not actually used for anything, they're still technically strings**

### Data Structure
The data structure used was a **stack** to help me implement this program solution. 
