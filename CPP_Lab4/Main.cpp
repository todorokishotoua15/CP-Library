// Roll - IMT2021016
#include<bits/stdc++.h>
#include "GameConsole.h"
#include "RandomWalk.h"
#include "FlightSimple.h"


 

using namespace std;

int main() {

	GameConsole gameconsole = GameConsole(); 

	vector<pair<string,string>> result;

	while (1) {
		string s;
		getline(cin,s);  //getting whole line as input
		
		if (s[0] == 'E') break; // first letter of line distinguishes all kinds of input

		else if (s[0] == 'F') {
			
			// splitting whitespaces
			string word1, amt_str;

			istringstream ss1(s); 
			
			ss1 >> word1;
			ss1 >> amt_str; 

			//converting string to number
			stringstream ss2;
			ss2 << amt_str;
			int amt;
			ss2 >> amt;

			// creating game instance and adding game to console
			FlightSimple* fs = new FlightSimple();
			fs->recharge(amt);
			gameconsole.add_game(fs);
			gameconsole.start();
			
			// list of keystrokes
			vector<string> v;
			string t;
			getline(cin,t);

			istringstream ss(t);

			string words;

			while (ss >> words) {
				v.push_back(words);
			}

			
			// passing all keystrokes to console
			string res = gameconsole.read(v);

			// displaying result of gameplay
			cout << "FlightSimple: " << res << "\n";

		}

		else {

			// creating game instances and adding the game to console
			RandomWalk* rw = new RandomWalk;

			gameconsole.add_game(rw);

			// keystroke list
			vector<string> v;
			string t;

			// getting entire line as input
			getline(cin,t);

			// splitting whitespaces
			istringstream ss(t);

			string words;

			while (ss >> words) {
				v.push_back(words);
			}

			// start the game and give all keystrokes to console
			gameconsole.start();
			string res = gameconsole.read(v);

			// displaying the result of the gameplay
			cout << "RandomWalk: " << res << "\n";
		}
	}

	// displaying result of each game
	
}