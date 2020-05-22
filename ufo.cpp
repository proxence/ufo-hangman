#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#include "ufo_functions.hpp"

int main()
{

  greet();

  string codeword_array[5] = {"codecademy", "academy", "computer", "arrays", "participants"};
  string answer = "";

  int size = sizeof(codeword_array) / sizeof(codeword_array[5]);

  int misses = 0;

  vector<char> incorrect;

  bool guess = false;

  char letter;

  string game_decision = "yes";

  string codeword = "";

  while (game_decision == "yes")
  {

    int random = rand() % size + 1;
    codeword = codeword_array[random];

    for (int i = 0; i < codeword.length(); i++)
    {
      answer += "_";
    }

    while (answer != codeword and misses < 7)
    {

      display_misses(misses);

      display_status(incorrect, answer);

      cout << "\n\nPlease enter your guess: " << endl;
      cin >> letter;

      for (int i = 0; i < codeword.length(); i++)
      {

        if (letter == codeword[i])
        {

          answer[i] = letter;
          guess = true;
        }
      }

      if (guess)
      {

        cout << "\nCorrect!" << endl;
      }

      else
      {

        cout << "\nIncorrect! The tractor beam pulls the person in further." << endl;
        incorrect.push_back(letter);

        misses++;
      }

      guess = false;
    }
    end_game(answer, codeword);

    answer = "";
    incorrect.clear();

    cout << "\nWould you like to continue? yes/no" << endl;
    cin >> game_decision;
  }
}
