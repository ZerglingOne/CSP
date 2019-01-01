#include "csp.h"

using namespace std;

int main()
{

  
  int int1, int2;
  char holder;
  bool valid = false;
  string word1, word2, word3;
  string hold_string;
  string letter_hold;
  vector<int> answers;
  vector<int> *solution;
  puzzle thePuzzle;
  while(!valid)//while we don't have a valid entry to the entire puzzle
    {
      
      while(!valid)//while we don't have a valid puzzle in the first place
	{
	  cout << "Please enter a cryptarithm\n";
	  cout << "first word =";
	  cin >> word1;
	  cout << "second word=";
	  cin >> word2;
	  cout << "third word=";
	  cin >> word3;
	  if(constraint1(word3, word1, word2))//and run constraints on them
	    valid = constraint2(word3, word1, word2, letter_hold);

	  if(!valid)
	    cout << "Invalid entry, try again\n";
	}
	  
      reverse(word1.begin(), word1.end());
      reverse(word2.begin(), word2.end());
      reverse(word3.begin(), word3.end());
	  
      makePuzzle(thePuzzle, int1, int2, word1, word2, word3,  letter_hold); //build puzzle
      valid = checkSolution(thePuzzle, generateSolution(thePuzzle, 1), 1);//see if it creates a valid puzzle
   
      if(valid)//if the puzzle is valid, go to game mode
	{
	  cout << "puzzle: \n";
	  for(int i = thePuzzle.num_word1.size(); i < thePuzzle.sum_word.size(); i++)
	    cout << " ";
	  hold_string = thePuzzle.num_word1;
	  reverse(hold_string.begin(), hold_string.end());
	  cout << hold_string << endl;
	  for(int i = thePuzzle.num_word2.size(); i < thePuzzle.sum_word.size(); i++)
	    cout << " ";
	  hold_string = thePuzzle.num_word2;
	  reverse(hold_string.begin(), hold_string.end());
	  cout << hold_string << endl;
	  cout << "+__________\n";
	  hold_string = thePuzzle.sum_word;
	  reverse(hold_string.begin(), hold_string.end());
	  cout << hold_string << endl;
	  cout << "enter a z to generate a solution\n";
	  for(int i = 0; i < letter_hold.size(); i++)//you can play to get a proper answer here, or you can enter z
	    {
	      cout << letter_hold[i] << "?" << endl;
	      cin >> holder;
	      if(holder == 'z')
		{
		  generateSolution(thePuzzle, 2);
		  return 0;
		}
	      else
		answers.push_back(holder - 48);
	    }
	  if(checkSolution(thePuzzle, answers, 2))
	    cout << "Correct!\n";
	  else
	    cout << "incorrect!\n";
	}
      
      
      letter_hold = "";
    }
}
