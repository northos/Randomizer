This is a simple script to pick a random item out of a .txt file.
In order for it to work properly, each item should be its own line in the file.
There is no need to distinguish the lines other than that.
These files should be in the same directory as the .exe file, or be given as a relative path from that directory.

Program input is straightforward. It will ask for the name of a file; type it in with no special formatting, quotes, or punctiation.
You can then type 'done' to proceed, or enter more file names.
It will output one of the lines from one of the files, chosen at random.
Each line is weighted equally; so using a 50-line and a 100-line file, each line will have a 1/150 chance to be picked, regardless of which file it's in.
You can also input an integer (again, unformatted); in this case, it will output an integer between 1 and what you entered (inclusive).
Entering a number will cause the program to ignore any files entered and JUST output the number.

Some .txt files are included in the repo; these are just examples of files that I've used myself.
