#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

struct puzzle
{
  int num1;
  int num2;
  int sum;
  string num_word1;
  string num_word2;
  string sum_word;
  string letters;
};


int atIndex(char, string);

void makePuzzle(puzzle&, int, int, string, string, string, string);
//Global constraints: These must be fulfilled prior to any puzzle generation.


bool constraint1(string, string, string);//constraint 2: length sum ==
                                         //length of longest between
                                         //num1 and num2 or length of longest +1
                                         //because 999 + 999, the highest 3 digit number = 1998, 4 digits.


bool constraint2(string, string, string, string&); //constraint 3: Number of unique letters is <= 10
//once these three conditions hold, a puzzle can be generated.

//puzzle creation/solving
vector<int> generateSolution(puzzle&, int);

bool checkSolution(puzzle& , vector<int>, int);
