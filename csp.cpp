#include "csp.h"


bool constraint1(string sum, string num1, string num2)//the length of the sum cannot exceed more than +1 of the operands
{
  int longer;
  if(num1.size() > num2.size())
      longer = num1.size();
  else
      longer = num2.size();

  if((sum.size() - longer) == 0 || (sum.size() - longer) == 1)
    return true;
  else
    return false;
  
}

bool constraint2(string sum, string num1, string num2, string &holder)//the number of unique letters must be <=10
{
  holder = "";
  bool contains = false;
 
  for(int i = 0; i < sum.size(); i++)
    {
      for(int j = 0; j <= holder.size(); j++)
	{
	  if(sum[i] == holder[j])
	    contains = true;
	}
      if(!contains)
	holder+= sum[i];
      
      contains = false;
    }
  for(int i = 0; i < num1.size(); i++)
    {
      for(int j = 0; j <= holder.size(); j++)
	{
	  if(num1[i] == holder[j])
	    contains = true;
	}
      if(!contains)
	holder+= num1[i];
      
      contains = false;
    }
  for(int i = 0; i < num2.size(); i++)
    {
      for(int j = 0; j <= holder.size(); j++)
	{
	  if(num2[i] == holder[j])
	    contains = true;
	}
      if(!contains)
	holder+= num2[i];
      
      contains = false;
    }
  if(holder.size() <= 10)
    return true;
  else
    return false;
}

void makePuzzle(puzzle &thePuzzle, int num1, int num2, string numw1, string numw2, string sumw, string letters)
{//builds puzzle struct
  if(numw1.size() >= numw2.size())
    {
      thePuzzle.num1 = num1;
      thePuzzle.num2 = num2;
      thePuzzle.num_word1 = numw1;
      thePuzzle.num_word2 = numw2;
    }
  else
    {
      thePuzzle.num1 = num2;
      thePuzzle.num2 = num1;
      thePuzzle.num_word1 = numw2;
      thePuzzle.num_word2 = numw1;
    }
  thePuzzle.sum = num1 + num2;
  thePuzzle.sum_word = sumw;
  thePuzzle.letters = letters;
}

bool checkSolution(puzzle &thePuzzle, vector<int> answers, int mode)//takes a set of answers and checks if they're valid
{
  int test1 = 0, test2 = 0, test3 = 0;//3 variables used to test the correctness of the string.
  bool f = false;//used for initializing the array below.
  bool check[10] = {f,f,f,f,f,f,f,f,f,f};//array to check if a digit was used.
  string num_w1 = thePuzzle.num_word1;//hold the puzzle words here
  string num_w2 = thePuzzle.num_word2;
  string sum_w = thePuzzle.sum_word;
  string letters = thePuzzle.letters;//the individual letters here indicate all of the letters in the puzzle
  
  for(int i = 0; i < answers.size(); i++)//answers must be unique
    {
      if(!check[answers[i]])
	check[answers[i]] = true;
      else if(check[answers[i]])
	return false;
    }
 
  if(answers[atIndex(num_w1[num_w1.size()-1], letters)] == 0 || answers[atIndex(num_w2[num_w2.size()-1], letters)] == 0)
	     return false;//leading number cannot be zero
  
  for(int a = 0; a < num_w1.size(); a++)
    test1 += pow(10, a) * answers[atIndex(num_w1[a], letters)];
  
  for(int a = 0; a < num_w2.size(); a++)
    test2 += pow(10, a) * answers[atIndex(num_w2[a], letters)];
  
  for(int a = 0; a < sum_w.size(); a++)
    test3 += pow(10, a) * answers[atIndex(sum_w[a], letters)];

  if(test3 != (test1 + test2))//constraint: the answer must be factual
    return false;
  else
    {
      if(mode == 2)
	{
	  cout << "  ";
	  for(int i = num_w1.size(); i < sum_w.size(); i++)
	    cout << " ";
	  cout << test1 << endl;
	  cout << "+ ";
	  for(int i = num_w2.size(); i < sum_w.size(); i++)
	    cout << " ";
	  cout << test2;
	  cout << endl;
	  cout << "---------\n";
	  cout << "  ";
	  cout << test3 << endl;
	}
      return true;
    }
      
}


vector<int> generateSolution(puzzle &thePuzzle, int mode)//goes through permutations until it finds a valid solution.
{
  int count = 0;
  vector<int> attempt;
  for(int i = 0; i < thePuzzle.letters.size(); i++)
    attempt.push_back(-1);
  bool f = false;
  vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
  while(!checkSolution(thePuzzle, attempt, mode) && next_permutation(digits.begin(), digits.end()))
    {
      
      for(int i = 0; i < attempt.size(); i++)
	attempt[i] = digits[i];
    }
  if(mode == 1)
    return attempt;
  if(mode == 2)
    {
      cout << "One solution is\n";
      for(int i = 0; i < thePuzzle.letters.size(); i++)
	cout << thePuzzle.letters[i];
      cout << endl;
      for(int i = 0; i < attempt.size(); i++)
	cout << attempt[i];
      cout << endl;
    }
  
}
  


int atIndex(char findme, string inme)//little useful function for finding indices.
{
  for(int i = 0; i < inme.size(); i++)
    {
      if(inme[i] == findme)
	return i;
    }
}

