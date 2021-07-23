//Mutharib Ayub Section Y
//Assignment 4

#include <iostream>
#include <ctime>
using namespace std;

void do_turn(char game[3][3],int player,int choice){
	char sign=0;		//saves either O or X to mark the turn of user
	int row,col;		//row and col saves coords of turn
	int compmove = (rand() % 9)+1;	//generates value for computer's turn
	if (choice==2 or player==1)		//true if input has to be taken from user
	{
		cout<<"Enter your row and col respectively(separated with a space): ";
		cin>>row>>col;
		while ((row<1 or row>3) or (col<1 or col>3) or (game[row-1][col-1]!='_'))
		{
			cout<<"Please enter row and column again (from 1 and 3)(should not be already filled): ";
			cin>>row>>col;
		}
	}
	else		//runs if input has to be taken from computer
	{	
		while(game[(compmove/3)-1][(compmove%3)-1]!='_')
			compmove = (rand() % 9)+1;
		row=compmove/3;
		col=compmove%3;
	}
	if (player==1)
		sign='X';
	else
		sign='O';
	game[row-1][col-1]=sign;

}

bool check_win(char game[3][3],int player){
	char sign=0;
	bool win_check=false;
	if (player==1)
		sign='X';
	else 
		sign='O';
	for (int rowcheck=0;rowcheck<3;rowcheck++)	//horizontal line win check
		if (game[rowcheck][0]==sign and game[rowcheck][1]==sign and game[rowcheck][2]==sign)
			win_check=true;
	for (int colcheck=0;colcheck<3;colcheck++)	//vertical line win check
		if (game[0][colcheck]==sign and game[1][colcheck]==sign and game[2][colcheck]==sign)
			win_check=true;
	if (game[0][0]==sign and game[1][1]==sign and game[2][2]==sign)	//diagonal win check1
		win_check=true;
	if (game[2][0]==sign and game[1][1]==sign and game[0][2]==sign)	//diagonal win check2
		win_check=true;
	return win_check;
}



void print_board(char game[3][3]){	//function to print board
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{
			cout<<game[row][col]<<"  ";
			if (col!=2)
				cout<<"|";
		}
		cout<<endl;
	}
}

int main(){
	srand(time(0));
	char game[3][3];
	int player=1,count=0,choice=0;
	do
	{
		cout<<"Press 1 to play with computer (computer will become player 2) and 2 to play with a second user: ";
		cin>>choice;
	}while (choice!=1 and choice!=2);
	for (int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			game[i][j]='_';
	print_board(game);
	cout<<"Player 1 mark: X     Player 2 mark: O\n";
	while(!check_win(game,1) and !check_win(game,2) and count<9)
	{
		cout<<"\nPlayer "<<player<<"'s turn:\n";
		do_turn(game,player,choice);
		count++;
		if (player==1)
			player=2;
		else
			player=1;	
		print_board(game);
	}
	if(check_win(game,1))
		cout<<"\nPLAYER 1 WON!!\n";
	else if(check_win(game,2))
		cout<<"\nPLAYER 2 WON!!\n";
	else
		cout<<"\nIT WAS A DRAW!!\n";
	
	return 0;
}
