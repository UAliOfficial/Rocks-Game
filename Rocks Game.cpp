#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stack>

using namespace std;

void gotoxy(int, int);
void vertical_line(int, int, int);
void horizontal_line(int, int, int);
void rectangle(int, int, int, int);
void loading(string, int);
void welcome_screen();
void main_menu();
void default_func();
void play();
void name();
void side_lines();
void box(int, int, int);
void help();

char line_v=179;
char line_h=196;
char top_right=191;
char top_left=218;
char bottom_right=217;
char bottom_left=192;
char top_center=194;
char bottom_center=193;
char left_center=195;
char right_center=180;
char four_ways=197;
char empty_loading=177;
char full_loading=219;
char box_v_border=186;
char box_h_border=205;
char box_r_corner=188;
char box_l_corner=200;
char rocks=216;
char arrow=175;
char m_menu_input;
char exit_input;
char pile;
string player_1;
string player_2;
bool turn_player;
int rock_num;

stack <int> stack_1;
stack <int> stack_2;
stack <int> stack_3;

int A;
int B;
int C;

int main()
{
	welcome_screen();
	main_menu();
}

void gotoxy(int x, int y)
{
	static HANDLE h=NULL;
	if(!h)
	{
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c={x, y};
	SetConsoleCursorPosition(h, c);
}

void vertical_line(int col, int row_1, int row_2)
{
	for(int i=row_1; i<row_2; i++)
	{
		gotoxy(col, i); cout << line_v;
	}
}

void horizontal_line(int row, int col_1, int col_2)
{
	for(int i=col_1; i<col_2; i++)
	{
		gotoxy(i, row); cout << line_h;
	}
}

void rectangle(int a, int b, int c, int d)
{
	vertical_line(c, a+1, b);
	vertical_line(d, a+1, b);
	horizontal_line(a, c+1, d);
	horizontal_line(b, c+1, d);
	gotoxy(c,a); cout << top_left;
	gotoxy(d,a); cout << top_right;
	gotoxy(c,b); cout << bottom_left;
	gotoxy(d,b); cout << bottom_right;
}

void loading(string text, int row, int speed)
{
	gotoxy((100-text.length())/2+1, row); cout << text;
	gotoxy(42, row+1);
	for(int i=0; i<17; i++)
	{
		cout << empty_loading;
	}
	gotoxy(42, row+1);
	for(int i=0; i<17; i++)
	{
		cout << full_loading;
		Sleep(speed);
	}
}

void welcome_screen()
{
	system("cls");
	system("color FD");
	for(int i=0; i<39; i++)
	{
		gotoxy(i, 13); cout << " Rocks Multiplayer Game";
		Sleep(40);
	}
	
	for(int i=0, j=99; i<100 && j>=0; i++, j--)
	{
		gotoxy(j, 4); cout << "*";
		gotoxy(j, 5); cout << "*";
		gotoxy(i, 21); cout << "*";
		gotoxy(i, 22); cout << "*";
		Sleep(30);
	}
	
	gotoxy(85, 24); cout << "M. Usman Ali";
	gotoxy(87, 25); cout << "18-SE-29";
	Sleep(30);
	loading("Loading", 26, 150);
	system("cls");
}

void default_func()
{
	system("color 04");
	Sleep(50);
	system("color 14");
	Sleep(50);
	system("color 24");
	Sleep(50);
	system("color 34");
	Sleep(50);
	system("color 44");
	Sleep(50);
	system("color 54");
	Sleep(50);
	system("color 64");
	Sleep(50);
	system("color 74");
	Sleep(50);
	system("color 84");
	Sleep(50);
	system("color 94");
	Sleep(50);
	system("color A4");
	Sleep(50);
	system("color C4");
	Sleep(50);
	system("color D4");
	Sleep(50);
	system("color E4");
	Sleep(50);
	system("color F4");
	Sleep(50);
	system("color B4");
	Sleep(50);
	gotoxy(12, 14);
	cout << "Wrong Entry! Try Again";
	Sleep(1500);
	gotoxy(12, 14);
	for(int i=0; i<22; i++)
	{
		cout << " ";
	}
	loading("Loading", 16, 100);
	main_menu();
}

void exit()
{
	loading("Loading", 19, 100);
	system("cls");
	system("color 0F");
	horizontal_line(7, 10, 90);
	gotoxy(12, 6); cout << "Do you really want to exit...[Y/N]?";
	gotoxy(12, 8); exit_input=getche();
	gotoxy(12, 6);
	for(int i=0; i<35; i++)
	{
		cout << " ";
	}
	for(int i=10; i<90; i++)			
	{
		gotoxy(i, 7); cout << " ";
	}
	gotoxy(12, 8); 
	for(int i=0; i<34; i++)
	{
		cout << " ";
	}
	gotoxy(12, 9); cout << " ";
	if(exit_input=='y' || exit_input=='Y')
	{
		loading("Exiting", 19, 150);
		system("cls");
		exit(0);
	}
	else
	{
		loading("Loading", 19, 150);
		main_menu();
	}
}

void main_menu()
{
	turn_player=0;
	A=1;
	B=9;
	C=5;
	for(int i=0; i<A; i++)
	{
		stack_1.push(1);
	}
	for(int i=0; i<B; i++)
	{
		stack_2.push(1);
	}
	for(int i=0; i<C; i++)
	{
		stack_3.push(1);
	}
	system("cls");
	system("color B4");
	rectangle(3, 26, 6, 93);
	rectangle(5, 24, 10, 89);
	horizontal_line(4, 14, 86);
	horizontal_line(25, 14, 86);
	vertical_line(8, 7, 23);
	vertical_line(91, 7, 23);
	gotoxy(44, 4); cout << " Main Menu ";
	gotoxy(37, 25); cout << " M. Usman Ali (18-SE-29) ";
	gotoxy(12, 7); cout << "Press relevant key to perform that action.";
	gotoxy(15, 9); cout << "1. Play Game";
	gotoxy(15, 10); cout << "2. Help";
	gotoxy(15, 11); cout << "3. Exit";
	horizontal_line(13, 12, 88);
	gotoxy(12, 14);
	m_menu_input=getche();
	gotoxy(12, 14); cout << " ";
	
	switch(m_menu_input)
	{
		case '1':
			play();
			break;
		case '2':
			help();
			break;
		case '3':
			exit();
			break;
		default:
			default_func();
	}
}

void play()
{
	loading("Loading", 20, 75);
	int sum=stack_1.size()+stack_2.size()+stack_3.size();
	name();
	while(sum!=0)
	{
	system("cls");
	system("color F0");
	if(A==1 && B==9 && C==5)
	{
		//nothing
	}
	else
	{
		gotoxy(13, 26); cout << "Last Move: ";
		if (turn_player==0)
		{
			cout << player_2;
		}
		else
		{
			cout << player_1;
		}
		cout << " removed " << rock_num << " rocks from Pile " << pile << "."; 
	}
	side_lines();
	rectangle(4, 6, 10, 20);
	rectangle(4, 6, 20, 40);
	rectangle(4, 6, 70, 79);
	rectangle(4, 6, 79, 89);
	rectangle(6, 8, 70, 79);
	rectangle(6, 8, 79, 89);
	gotoxy(20, 4); cout << top_center;
	gotoxy(20, 6); cout << bottom_center;
	gotoxy(79, 4); cout << top_center;
	gotoxy(79, 6); cout << four_ways;
	gotoxy(79, 8); cout << bottom_center;
	gotoxy(70, 6); cout << left_center;
	gotoxy(89, 6); cout << right_center;
	gotoxy(38, 2); cout << " Rocks Multiplayer Game ";
	gotoxy(13, 5); cout << "Turn";
	gotoxy(73, 5); cout << "Pile";
	gotoxy(72, 7); cout << "Rocks?";
	gotoxy(20 ,23); cout << "A";
	gotoxy(50 ,23); cout << "B";
	gotoxy(79, 23); cout << "C";
	gotoxy(72, 9);
	cout << "Options: ";
	if(A!=0)
	{
		cout << "A, ";
	}
	if(B!=0)
	{
		cout << "B, ";
	}
	if(C!=0)
	{
		cout << "C, ";
	}
	cout << "\b\b";
	cout << " ";
	if(turn_player==0)
	{
		gotoxy(30-(player_1.length())/2, 5); cout << player_1;
	}
	else
	{
		gotoxy(30-(player_2.length())/2, 5); cout << player_2;
	}
	box(13, 14, A);
	box(43, 14, B);
	box(72, 14, C);
	
	input_pile:
	gotoxy(84, 5); cin >> pile;
	if((pile=='A') || (pile=='B') || (pile=='C') || (pile=='a') || (pile=='b') || (pile=='c'))
	{
		//Do nothing
	}
	else
	{
		gotoxy(70, 9); cout << "                    ";
		gotoxy(71, 9);
		cout << "Select Right Pile!";
		gotoxy(84, 5); cout << " ";
		goto input_pile;
	}
	if((pile=='A'  && A==0) || (pile=='B' && B==0) || (pile=='C' && C==0) || (pile=='a'  && A==0) || (pile=='b' && B==0) || (pile=='c' && C==0))
	{
		gotoxy(70, 9); cout << "                    ";
		gotoxy(71, 9);
		cout << "Empty Pile!";
		gotoxy(71, 10); cout << "Select Another.";
		gotoxy(84, 5); cout << " ";
		goto input_pile;
	}
	
	gotoxy(70, 9); cout << "                    ";
	gotoxy(70, 10); cout << "                    ";
	gotoxy(71, 9);
	cout << "Options: ";
	if(pile=='A' || pile=='a')
	{
		cout << "A " << arrow << " ";
		if (stack_1.size()==1)
		{
			cout << "1";
		}
		else
		cout << "1 - " << stack_1.size();
	}
	
	if(pile=='B' || pile=='b')
	{
		cout << "B " << arrow << " ";
		if (stack_2.size()==1)
		{
			cout << "1";
		}
		else
		cout << "1 - " << stack_2.size();
	}
	
	if(pile=='C' || pile=='c')
	{
		cout << "C " << arrow << " ";
		if (stack_3.size()==1)
		{
			cout << "1";
		}
		else
		cout << "1 - " << stack_3.size();
	}
	
	input_rock:
	gotoxy(84, 7); cout << "  ";
	gotoxy(84, 7); cin >> rock_num;
	
	gotoxy(70, 9); cout << "                    ";
	gotoxy(70, 10); cout << "                    ";
	
	if(pile=='A' || pile=='a')
	{
		if(rock_num>stack_1.size() || rock_num<1)
		{
		gotoxy(70, 9); cout << "Invalid Value!";
		gotoxy(70, 10); cout << "Try Again";
		goto input_rock;
		}
	}
	
	if(pile=='B' || pile=='b')
	{
		if(rock_num>stack_2.size() || rock_num<1)
		{
		gotoxy(70, 9); cout << "Invalid Value!";
		gotoxy(70, 10); cout << "Try Again";
		goto input_rock;
		}
	}
	
	if(pile=='C' || pile=='c')
	{
		if(rock_num>stack_3.size() || rock_num<1)
		{
		gotoxy(70, 9); cout << "Invalid Value!";
		gotoxy(70, 10); cout << "Try Again";
		goto input_rock;
		}
	}
	
	if(pile=='A' || pile=='a')
	{
		for(int i=0; i< rock_num; i++)
		stack_1.pop();
		A=A-rock_num;
	}
	
	if(pile=='B' || pile=='b')
	{
		for(int i=0; i< rock_num; i++)
		stack_2.pop();
		B=B-rock_num;
	}
	
	if(pile=='C' || pile=='c')
	{
		for(int i=0; i< rock_num; i++)
		stack_3.pop();
		C=C-rock_num;
	}
	sum=stack_1.size()+stack_2.size()+stack_3.size();
	turn_player=!turn_player;
	}
	Sleep(1000);
	system("cls");
	system("color A1");
	loading("Loading", 15, 60);
	system("cls");
	vertical_line(4, 0, 30);
	vertical_line(6, 0, 30);
	vertical_line(95, 0, 30);
	vertical_line(93, 0, 30);
	gotoxy(43, 12); cout << "Congratulations!";
	if(turn_player==0)
	{
		gotoxy(43-(player_1.length())/2, 14); cout << player_1 << " won the game.";
	}
	else
	{
		gotoxy(43-(player_2.length())/2, 14); cout << player_2 << " won the game.";
	}
	
	Sleep(800);
	gotoxy(36, 16); cout << "Press any key to Continue...";
	getch();
	gotoxy(36, 16); cout << "                                ";
	loading("Loading", 16, 60);
	main_menu();
	
}

void name()
{
	system("cls");
	system("color 61");
	side_lines();
	rectangle(10, 14, 25, 50);
	rectangle(10, 14, 50, 75);
	rectangle(14, 18, 25, 50);
	rectangle(14, 18, 50, 75);
	gotoxy(50, 10); cout << top_center;
	gotoxy(50, 18); cout << bottom_center;
	gotoxy(25, 14); cout << left_center;
	gotoxy(75, 14); cout << right_center;
	gotoxy(50, 14); cout << four_ways;
	gotoxy(43, 2); cout << " Choose Player ";
	gotoxy(25, 19); cout << "Enter First Name Only!";
	gotoxy(34, 12); cout << "Player 1";
	gotoxy(58, 12); cout << "Player 2";
	gotoxy(25, 20); cout << "Player 1 will have first move.";
	gotoxy(27, 16); cin >> player_1;
	gotoxy(52, 16); cin >> player_2;
	loading("Starting Game", 25, 100);
	system("cls");
}

void side_lines()
{
	vertical_line(4, 2, 28);
	vertical_line(8, 2, 28);
	vertical_line(91, 2, 28);
	vertical_line(95, 2, 28);
	vertical_line(6, 1, 29);
	vertical_line(93, 1, 29);
	horizontal_line(2, 14, 86);
}

void box(int x, int y, int rock)
{
	int count=0;
	for(int i=0; i<8; i++)
	{
		gotoxy(x, y); cout << box_v_border;
		gotoxy(x+14, y); cout << box_v_border;
		y++;
	}
	
	gotoxy(x+1, y);
	for (int i=0; i<13; i++)
	{
		cout << box_h_border;
	}
	
	gotoxy(x, y); cout << box_l_corner;
	gotoxy(x+14, y); cout << box_r_corner;
	int z=x;
	for(int i=0; i<rock; i++)
	{
		gotoxy(x+11, y-2); cout << rocks;
		count++;
		if (count>2)
		{
			count=0;
			x=z;
			y=y-2;
		}
		else
		{
			x=x-4;
		}
	}
}

void help()
{
	loading("Loading", 20, 75);
	system("cls");
	system("color A4");
	side_lines();
	
	gotoxy(47, 2); cout << " Help ";

	char arr_1[]="Rocks is a Multiplayer Game where two players take turn to remove rocks from";
	char arr_2[]="different piles. This game has three piles with different number of rocks in";
	char arr_3[]="them. A player will select pile A, B or C and then can remove rocks from that";
	char arr_4[]="pile. Then, other player will take turn to do same. The player who removes last";
	char arr_5[]="rock will lose. So, each player will have to take such strategy that other player";
	char arr_6[]="will have to remove last rock.";
	char arr_7[]="Developed by Muhammad Usman Ali (18-SE-29)";
	int i=0;
	gotoxy(10, 4);
	while(arr_1[i]!='\0')
	{
		cout << arr_1[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 5);
	while(arr_2[i]!='\0')
	{
		cout << arr_2[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 6);
	while(arr_3[i]!='\0')
	{
		cout << arr_3[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 7);
	while(arr_4[i]!='\0')
	{
		cout << arr_4[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 8);
	while(arr_5[i]!='\0')
	{
		cout << arr_5[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 9);
	while(arr_6[i]!='\0')
	{
		cout << arr_6[i];
		Sleep(50);
		i++;
	}
	i=0;
	gotoxy(10, 11);
	while(arr_7[i]!='\0')
	{
		cout << arr_7[i];
		Sleep(50);
		i++;
	}
	
	gotoxy(10, 13);
	cout << "Press Any Key to goto Main Menu...";
	getch();
	loading("Loading", 20, 75);
	main_menu();
}
