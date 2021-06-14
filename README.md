# CS50-pset5-Speller

# USAGE:
![image](https://user-images.githubusercontent.com/58123635/121843733-d41e5480-ccb0-11eb-9bbc-982d2c7e336f.png)

You can run the following command in the terminal:
$ ./speller texts/lalaland.txt

Output would look something like this:

MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]
....

WORDS MISSPELLED:     955
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        17756
TIME IN load:         0.03
TIME IN check:        0.01
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.06

## Note the statistics of my hash table C immplementation!

TIME IN load represents the number of seconds that speller spends executing your implementation of load. TIME IN check represents the number of seconds that speller spends, in total, executing your implementation of check. TIME IN size represents the number of seconds that speller spends executing your implementation of size. TIME IN unload represents the number of seconds that speller spends executing your implementation of unload. TIME IN TOTAL is the sum of those four measurements.

## In this pset, I have implemented the following functions in dictionary.c file: load. hash. size. check. unload.

### Some of my own notes, while watching Week5 lecture [video](https://cs50.harvard.edu/x/2021/weeks/5/)

- malloc: returns an addr in memory (stack)
- C symbol for storing an addr: *
- e.g. node *n = malloc(sizeof(node))
### NOTE for pset5 SPELLER:

##### Notice three functions that take pointer as an argument, per the *:
-	bool check(const char *word);
-	unsigned int hash(const char *word);
-	bool load(const char *dictionary);
  
##### Those three prototypes are essentially just:
-	bool check(const string word);
-	unsigned int hash(const string word);
-	bool load(const string dictionary);
