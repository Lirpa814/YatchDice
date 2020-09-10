#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Dice
{
	int value = 0;
	bool doub = false;
	bool thr = false;
};

int main()
{
	srand((unsigned int)time(NULL));

	// make & initialize field
	int field[5];
	for (int i = 0; i < 5; i++)
		field[i] = 0;

	Dice dice[6];
	for (int i = 0; i < 6; i++)
		dice[i].value = 0;

	bool boardState[12];
	for (int i = 0; i < 12; i++)
		boardState[i] = true;

	// input dice value
	//for (int i = 0; i < 5; i++)
	//	field[i] = rand() % 6 + 1;

	// make & initialize checkboard

	//string checkboard[2][15];

	//for (int j = 0; j < 15; j++)
	//	for (int i = 0; i < 2; i++)
	//		checkboard[i][j] = "0\t";
	//checkboard[0][0] = "Aces\t\t";
	//checkboard[0][1] = "Deuces\t\t";
	//checkboard[0][2] = "Threes\t\t";
	//checkboard[0][3] = "Fours\t\t";
	//checkboard[0][4] = "Fives\t\t";
	//checkboard[0][5] = "Sixes\t\t";
	//checkboard[0][6] = "Subtotal\t";
	//checkboard[0][7] = "+35 Bonus\t";
	//checkboard[0][8] = "Choice\t\t";
	//checkboard[0][9] = "4 of a Kind\t";
	//checkboard[0][10] = "Full House\t";
	//checkboard[0][11] = "S. Straight\t";
	//checkboard[0][12] = "L. Straight\t";
	//checkboard[0][13] = "Yatch\t\t";
	//checkboard[0][14] = "Total\t\t";

	string checkboard[15];

	checkboard[0] = "Aces\t\t";
	checkboard[1] = "Deuces\t\t";
	checkboard[2] = "Threes\t\t";
	checkboard[3] = "Fours\t\t";
	checkboard[4] = "Fives\t\t";
	checkboard[5] = "Sixes\t\t";
	checkboard[6] = "Subtotal\t";
	checkboard[7] = "+35 Bonus\t";
	checkboard[8] = "Choice\t\t";
	checkboard[9] = "4 of a Kind\t";
	checkboard[10] = "Full House\t";
	checkboard[11] = "S. Straight\t";
	checkboard[12] = "L. Straight\t";
	checkboard[13] = "Yatch\t\t";
	checkboard[14] = "Total\t\t";

	int scoreboard[15];

	for (int i = 0; i < 15; i++)
		scoreboard[i] = 0;


	/*
	cout << "Field List" << endl;
	for (int i = 0; i < 5; i++)
		cout << field[i] << " ";
	cout << endl;
	*/

	int turn = 12;
	char input = '0';

	int aces = 0;
	int deuces = 0;
	int threes = 0;
	int fours = 0;
	int fives = 0;
	int sixes = 0;

	int choice = 0;

	int f_score = 0; // 4 of a Kind score
	int p_score = 0; // Pull House score
	int s_score = 0; // S.Straight score;
	int l_score = 0; // L.Straight score;
	int y_score = 0; // Yatch score;

	int r_count = 2;

	while (turn--)
	{
		system("cls");

		input = 0;

		aces = 0;
		deuces = 0;
		threes = 0;
		fours = 0;
		fives = 0;
		sixes = 0;

		choice = 0;

		f_score = 0;
		p_score = 0;
		s_score = 0;
		l_score = 0;
		y_score = 0;
		scoreboard[14] = 0;
		scoreboard[6] = 0;

		cout << "Left Turn : " << turn << endl;

		cout << "Current Checkboard" << endl;
		//for (int j = 0; j < 15; j++)
		for (int i = 0; i < 6; i++)
		{
			//for (int i = 0; i < 2; i++)
			//	cout << checkboard[i][j] << " ";
			scoreboard[14] += scoreboard[i] + scoreboard[i+8];
			scoreboard[6] += scoreboard[i];
			cout << checkboard[i] << "\t: " << scoreboard[i];
			cout << "\t\t" << checkboard[i + 8] << "\t: " << scoreboard[i + 8];
			cout << endl;
		}
		cout << checkboard[6] << "\t: " << scoreboard[6] << "/63" << endl;
		cout << checkboard[7] << "\t: " << scoreboard[7] << "\t\t" << endl;
		cout << checkboard[14] << "\t: " << scoreboard[14];
		cout << endl;

		cout << "Roll Dice !" << endl;
		for (int i = 0; i < 5; i++)
			field[i] = rand() % 6 + 1;

		//cout << "Field List" << endl;
		for (int i = 0; i < 5; i++)
			cout << field[i] << " ";
		cout << endl;

		cout << "You can choice .." << endl;
		//
		if (r_count != 0)
			cout << "0. Reroll dice (left : " << r_count << ")" << endl;

		if (boardState[0] == true)
		{
			cout << "1. Aces\t\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 1)
					aces++;
			cout << aces * 1 << endl;
			if (aces == 2)
				dice[0].doub = true;
			else if (aces == 3)
				dice[0].thr = true;
		}

		if (boardState[1] == true)
		{
			cout << "2. Ducese\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 2)
					deuces++;
			cout << deuces * 2 << endl;
			if (deuces == 2)
				dice[1].doub = true;
			else if (deuces == 3)
				dice[1].thr = true;
		}

		if (boardState[2] == true)
		{
			cout << "3. Threes\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 3)
					threes++;
			cout << threes * 3 << endl;
			if (threes == 2)
				dice[2].doub = true;
			else if (threes == 3)
				dice[2].thr = true;
		}

		if (boardState[3] == true)
		{
			cout << "4. Fours\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 4)
					fours++;
			cout << fours * 4 << endl;
			if (fours == 2)
				dice[3].doub = true;
			else if (fours == 3)
				dice[3].thr = true;
		}

		if (boardState[4] == true)
		{
			cout << "5. Fives\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 5)
					fives++;
			cout << fives * 5 << endl;
			if (fives == 2)
				dice[4].doub = true;
			else if (fives == 3)
				dice[4].thr = true;
		}

		if (boardState[5] == true)
		{
			cout << "6. Sixes\t: ";
			for (int i = 0; i < 5; i++)
				if (field[i] == 6)
					sixes++;
			cout << sixes * 6 << endl;
			if (sixes == 2)
				dice[5].doub = true;
			else if (sixes == 3)
				dice[5].thr = true;
		}
		
		if (boardState[6] == true)
		{
			cout << "7. Choice\t: ";
			choice = (aces * 1) + (deuces * 2) + (threes * 3) + (fours * 4) + (fives * 5) + (sixes * 6);
			cout << choice << endl;
		}

		// 점수 수정 필요
		// 나온 눈 * 4 -> 나온 눈 * 4 + 나머지 나온 눈
		if (boardState[7] == true)
		{
			cout << "8. 4 of a Kind\t: ";
			if (aces >= 4 || deuces >= 4 || threes >= 4 || fours >= 4 || fives >= 4 || sixes >= 4)
			{
				if (aces >= 4)
					f_score = aces * 1;
				else if (deuces >= 4)
					f_score = deuces * 2;
				else if (threes >= 4)
					f_score = threes * 3;
				else if (fours >= 4)
					f_score = fours * 4;
				else if (fives >= 4)
					f_score = fives * 5;
				else
					f_score = sixes * 6;
			}
			cout << f_score << endl;
		}

		if (boardState[8] == true)
		{
			int doub_check = 0;
			int thr_check = 0;
			for (int i = 0; i < 5; i++)
			{
				if (dice[i].doub == true)
					doub_check = i;
				else if (dice[i].thr == true)
					thr_check = i;
			}
			cout << "9. Full House\t: ";
			if (doub_check && thr_check)
			{
				p_score = dice[doub_check].value * 2 + dice[thr_check].value * 3;
			}
			cout << p_score << endl;
		}
		
		bool s_straight = false;
		bool l_straight = false;
		
		if (threes != 0 && fours != 0)
		{
			if (deuces != 0 && fives != 0)
			{
				if (aces != 0 || sixes != 0)
					l_straight = true;
				s_straight = true;
			}
			else if (aces != 0 && deuces != 0)
				s_straight = true;
			else if (fives != 0 && sixes != 0)
				s_straight = true;
		}
		
		if (boardState[9] == true)
		{
			cout << "10. S.Straight\t: ";
			if (s_straight)
				s_score = 15;
			cout << s_score << endl;
		}

		if (boardState[10] == true)
		{
			cout << "11. L.Straight\t: ";
			if (l_straight)
				l_score = 30;
			cout << l_score << endl;
		}

		if (boardState[11] == true)
		{
			cout << "12. Yatch\t: ";
			if (aces == 5 || deuces == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5)
				y_score = 50;
			cout << y_score << endl;
		}

		cout << "Choice !" << endl;

		cin >> input;
		//if (input == 0)
		//	system("cls");
		//else if (input == 1)
		//	checkboard[1][0] = to_string(aces * 1);

		switch (input)
		{
		case '0':
			r_count--;
			turn++;
			continue;
			break;
		case '1':
			scoreboard[0] = aces * 1;
			boardState[0] = false;
			break;
		case '2':
			scoreboard[1] = deuces * 2;
			boardState[1] = false;
			break;
		case '3':
			scoreboard[2] = threes * 3;
			boardState[2] = false;
			break;
		case '4':
			scoreboard[3] = fours * 4;
			boardState[3] = false;
			break;
		case '5':
			scoreboard[4] = fives * 5;
			boardState[4] = false;
			break;
		case '6':
			scoreboard[5] = sixes * 6;
			boardState[5] = false;
			break;
		case '7':
			scoreboard[8] = choice;
			boardState[6] = false;
			break;
		case '8':
			scoreboard[9] = f_score;
			boardState[7] = false;
			break;
		case '9':
			scoreboard[10] = p_score;
			boardState[8] = false;
			break;
		case '10':
			scoreboard[11] = 15;
			boardState[9] = false;
			break;
		case '11':
			scoreboard[12] = 30;
			boardState[10] = false;
			break;
		case '12':
			scoreboard[13] = 50;
			boardState[11] = false;
			break;		

		default:
			break;
		}
		if (r_count == 0)
			r_count = 2;
	}
	cout << "Game Over ! " << endl;
	cout << "Your Score is " << scoreboard[14] << endl;

	return 0;
}