#include<bits/stdc++.h>
#include "Game.h"
#include "GameConsole.h"
#include "RandomWalk.h"
#include "FlightSimple.h"

using namespace std;

int main() {

	GameConsole* gameconsole = new GameConsole();

	while (1) {
		string s;
		cin >> s;
		if (s == "End") break;

		else if (s == "FlightSimple") {
			int amt;
			cin >> amt;
			FlightSimple* fs = new FlightSimple;
			fs->recharge(amt);
			gameconsole->add_game(*fs);

			vector<string> v;
			string t;
			getline(cin,t);

			istringstream ss(t);

			string words;

			while (ss >> words) {
				v.push_back(words);
			}

			string res = gameconsole->read(v);

			cout << "FlightSimple: " << res << "\n";

		}

		else {
			RandomWalk* rw = new RandomWalk;

			gameconsole->add_game(*rw);

			vector<string> v;
			string t;
			getline(cin,t);

			istringstream ss(t);

			string words;

			while (ss >> words) {
				v.push_back(words);
			}

			string res = gameconsole->read(v);

			cout << "RandomWalk: " << res << "\n";
		}
	}
}