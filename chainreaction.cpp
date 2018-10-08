#include<iostream>
using namespace std;
int turn=2;
int first=0,flag;
char board[4][4],role1='a',role2='b';
int trail=15,i,j;
class game{
	int value;
	int name;
	public:
	void assign(char n){
		name=n;
		value++;
	}
	int val(){
		return value;
	}
	void zero(){
		value=0;
	}
	friend void changeboard(game**,int,int,int);
};
//recursive function to change the board values
void changeboard(game** obj,int pos,int row,int col){
	if(row==0&&col==0){
		if(obj[row][col].val()>=1){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row,col+1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==0&&col==3){
		if(obj[row][col].val()>=1){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row,col-1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3&&col==0){
		if(obj[row][col].val()>=1){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col+1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3&&col==3){
		if(obj[row][col].val()>=1){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col-1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==0){
		if(obj[row][col].val()>=2){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row,col-1);
			changeboard(obj,pos,row,col+1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3){
		if(obj[row][col].val()>=2){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col-1);
			changeboard(obj,pos,row,col+1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(col==0){
		if(obj[row][col].val()>=2){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col+1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(col==3){
		if(obj[row][col].val()>=2){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col-1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else{
		if(obj[row][col].val()>=3){
			obj[row][col].zero();
			board[row][col]='0';
			changeboard(obj,pos,row+1,col);
			changeboard(obj,pos,row-1,col);
			changeboard(obj,pos,row,col+1);
			changeboard(obj,pos,row,col-1);
		}else{
			if(pos==0){
				obj[row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}
}
//end
int main(){
	game** player1 = new game*[4];
	game** player2 = new game*[4];
    // Each member points to an array of 100 players.
    player1[0] = new game[4];
    player1[1] = new game[4];
    player1[2] = new game[4];
    player1[3] = new game[4];
    player2[0] = new game[4];
    player2[1] = new game[4];
    player2[2] = new game[4];
    player2[3] = new game[4];
	cout<<"\t\t\t\t\tChain Reaction Game :\n\n";
	//Initialising the board
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			board[i][j]='0';
		}
	}
	//end
	//initial display of the board
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<board[i][j]<<" ";
		}cout<<"\n";
	}
	//end
	int row,col;
	while(1){	
		//player 1 
		if(turn%2==0){
			cout<<"PLAYER a :\n";	
			flag=0;
			cout<<"Enter the row and col value :";
			cin>>row>>col;
			cout<<"\n";
			if(board[row][col]=='0'||board[row][col]=='a'){



				//For the corner values
				if(row==0&&col==0){
							if(player1[row][col].val()>=1){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row,col+1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==0&&col==3){
							if(player1[row][col].val()>=1){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row,col-1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==3&&col==0){
							if(player1[row][col].val()>=1){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,1,row-1,col);
								changeboard(player1,0,row,col+1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==3&&col==3){
							if(player1[row][col].val()>=1){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row-1,col);
								changeboard(player1,0,row,col-1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
							}
						}else if(row==0){
							if(player1[row][col].val()>=2){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row,col-1);
								changeboard(player1,0,row,col+1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(row==3){
							if(player1[row][col].val()>=2){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row-1,col) ;
								changeboard(player1,0,row,col-1);
								changeboard(player1,0,row,col+1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(col==0){
							if(player1[row][col].val()>=2){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row-1,col);
								changeboard(player1,0,row,col+1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(col==3){
							if(player1[row][col].val()>=2){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row-1,col);
								changeboard(player1,0,row,col-1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
							}
						}else{
							if(player1[row][col].val()>=3){
								player1[row][col].zero();
								board[row][col]='0';
								changeboard(player1,0,row+1,col);
								changeboard(player1,0,row-1,col);
								changeboard(player1,0,row,col+1);
								changeboard(player1,0,row,col-1);
							}else{
									player1[row][col].assign(role1);
									board[row][col]='a';
				}
	}
				//end






				}else{
					cout<<"Position is already filled. Please enter a valid Positions!!!\n";
					continue;
				}

				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						if(board[i][j]=='b')
						cout<<board[i][j]<<player2[i][j].val()<<" ";
						else
						cout<<board[i][j]<<player1[i][j].val()<<" ";
					}cout<<"\n";
				} 
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
							if(board[i][j]=='b'){
								flag=1;							
							}
					}
				}
				if(flag==0&&first!=0){
					cout<<"PLAYER 1 WINS!!!!";
					return 0;
				}
			turn=1;
			//end
		}else{
			//player 2
			cout<<"PLAYER b :\n";	
			flag=0;
			cout<<"Enter the row and col value :";
			cin>>row>>col;
			if(board[row][col]=='0'||board[row][col]=='b'){



				//For the corner values
				if(row==0&&col==0){
							if(player2[row][col].val()>=1){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row,col+1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==0&&col==3){
							if(player2[row][col].val()>=1){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row,col-1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==3&&col==0){
							if(player2[row][col].val()>=1){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row-1,col);
								changeboard(player2,1,row,col+1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==3&&col==3){
							if(player2[row][col].val()>=1){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row-1,col);
								changeboard(player2,1,row,col-1);
							}else{
								player2[row][col].assign(role1);
									board[row][col]='b';
							}
						}else if(row==0){
							if(player2[row][col].val()>=2){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row,col-1);
								changeboard(player2,1,row,col+1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(row==3){
							if(player2[row][col].val()>=2){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row-1,col) ;
								changeboard(player2,1,row,col-1);
								changeboard(player2,1,row,col+1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(col==0){
							if(player2[row][col].val()>=2){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row-1,col);
								changeboard(player2,1,row,col+1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(col==3){
							if(player2[row][col].val()>=2){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row-1,col);
								changeboard(player2,1,row,col-1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
							}
						}else{
							if(player2[row][col].val()>=3){
								player2[row][col].zero();
								board[row][col]='0';
								changeboard(player2,1,row+1,col);
								changeboard(player2,1,row-1,col);
								changeboard(player2,1,row,col+1);
								changeboard(player2,1,row,col-1);
							}else{
									player2[row][col].assign(role1);
									board[row][col]='b';
				}
	}
				//end






				}else{
					cout<<"Position is already filled. Please enter a valid Positions!!!\n";
					continue;
				}

				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						if(board[i][j]=='b')
						cout<<board[i][j]<<player2[i][j].val()<<" ";
						else
						cout<<board[i][j]<<player1[i][j].val()<<" ";
					}cout<<"\n";
				} 
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
							if(board[i][j]=='a'){
								flag=1;							
							}
					}
				}
				if(flag==0&&first!=0){
					cout<<"PLAYER 2 WINS!!!!";
					return 0;
				}
			turn=2;
			first=1;
			//end
		}
	}
	return 0;
}