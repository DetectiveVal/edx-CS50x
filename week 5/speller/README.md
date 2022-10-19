This is a spellcheck program in which we were challenged to make the runtime as fast as possible. For my hash I used djb2 which can be found at http://www.cse.yorku.ca/~oz/hash.html . I found that this hash function was fast and easy to code. With this hash function I got similar runtimes to the teacher's version of this program.


Usage:

./speller [dictionary] [text] 

"Where dictionary is assumed to be a file containing a list of lowercase words, one per line, and text is a file to be spell-checked."