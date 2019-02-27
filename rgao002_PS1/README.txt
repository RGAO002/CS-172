The design of the code is built upon C++ for the inverted index, in the form of linked list data structure, as what is indicated by the manual. There are two files, a header file 'docIndex.h' and main program 'main.cpp'. The program does all functions completely, including but not limited to:

1. Exclusion of stop words from file 'stoplist.txt' when it comes to word count of each document and denial of input request.
2. Reading all input files through 'data' folder, with accurate information collection and computation.
3. Linked-list data structure that includes two attributes(document id and document frequency) and pointer to the next node.
4. Proper prompts for invalid inputs.

The code applies C++11 features, so in order to compile, make sure to type in 'g++ --std=c++11 main.cpp'. The code perfectly compiles by the command on 'Cloud 9'(c9.io) platform.