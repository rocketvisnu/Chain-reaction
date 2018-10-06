#include<iostream.h>
#include<conio.h>
#include<ctype.h>
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
	friend void changeboard(game,int,int,int);
}player[2][4][4];
//recursive function to change the board values
void changeboard(game obj,int pos,int row,int col){
	if(row==0&&col==0){
		if(obj[pos][row][col].val()>=2){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==0&&col==3){
		if(obj[pos][row][col].val()>=2){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3&&col==0){
		if(obj[pos][row][col].val()>=2){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3&&col==3){
		if(obj[pos][row][col].val()>=2){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==0){
		if(obj[pos][row][col].val()>=3){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(row==3){
		if(obj[pos][row][col].val()>=3){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(col==0){
		if(obj[pos][row][col].val()>=3){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else if(col==3){
		if(obj[pos][row][col].val()>=3){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}else{
		if(obj[pos][row][col].val()>=4){
			obj[pos][row][col].zero();
			board[row][col]='0';
			changeboard(obj[pos][row+1][col],pos,row+1,col);
			changeboard(obj[pos][row-1][col],pos,row-1,col);
			changeboard(obj[pos][row][col+1],pos,row,col+1);
			changeboard(obj[pos][row][col-1],pos,row,col-1);
		}else{
			if(pos==0){
				obj[pos][row][col].assign(role1);
				board[row][col]='a';
			}
			else{
				obj[pos][row][col].assign(role2);
				board[row][col]='b';
			}
		}
	}
}
//end
int main(){
	cout<<"\t\t\t\t\tChain Reaction Game :\n\n";
	//Initialising the board
	clrscr();
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
	while(trail--){	
		//player 1 
		if(turn%2==0){
			cout<<"PLAYER a :\n";	
			flag=0;
			cout<<"Enter the row and col value :";
			cin>>row>>col;
			if(board[row][col]=='0'||board[row][col]=='a'){



				//For the corner values
				if(row==0&&col==0){
							if(obj[0][row][col].val()>=2){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row][col+1],0,row,col+1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==0&&col==3){
							if(obj[0][row][col].val()>=2){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row][col-1],0,row,col-1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==3&&col==0){
							if(obj[0][row][col].val()>=2){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row-1][col],1,row-1,col);
								changeboard(obj[0][row][col+1],0,row,col+1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
							}
				}else if(row==3&&col==3){
							if(obj[0][row][col].val()>=2){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row-1][col],0,row-1,col);
								changeboard(obj[0][row][col-1],0,row,col-1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
							}
						}else if(row==0){
							if(obj[0][row][col].val()>=3){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row][col-1],0,row,col-1);
								changeboard(obj[0][row][col+1],0,row,col+1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(row==3){
							if(obj[0][row][col]>=3){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row-1][col],0,row-1,col) ;
								changeboard(obj[0][row][col-1],0,row,col-1);
								changeboard(obj[0][row][col+1],0,row,col+1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(col==0){
							if(obj[0][row][col].val()>=3){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row-1][col],0,row-1,col);
								changeboard(obj[0][row][col+1],0,row,col+1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
								}
						}else if(col==3){
							if(obj[0][row][col].val()>=3){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row-1][col],0,row-1,col);
								changeboard(obj[0][row][col-1],0,row,col-1);
							}else{
									obj[0][row][col].assign(role1);
									board[row][col]='a';
							}
						}else{
							if(obj[0][row][col].val()>=4){
								obj[0][row][col].zero();
								board[row][col]='0';
								changeboard(obj[0][row+1][col],0,row+1,col);
								changeboard(obj[0][row-1][col],0,row-1,col);
								changeboard(obj[0][row][col+1],0,row,col+1);
								changeboard(obj[0][row][col-1],0,row,col-1);
							}else{
									obj[0][row][col].assign(role1);
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
						cout<<board[i][j]<<player[0][i][j].val()<<" ";
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
							if(obj[1][row][col].val()>=2){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row][col+1],1,row,col+1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==0&&col==3){
							if(obj[1][row][col].val()>=2){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row][col-1],1,row,col-1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==3&&col==0){
							if(obj[1][row][col].val()>=2){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row-1][col],1,row-1,col);
								changeboard(obj[1][row][col+1],1,row,col+1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
							}
				}else if(row==3&&col==3){
							if(obj[1][row][col].val()>=2){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row-1][col],1,row-1,col);
								changeboard(obj[1][row][col-1],1,row,col-1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
							}
						}else if(row==0){
							if(obj[1][row][col].val()>=3){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row][col-1],1,row,col-1);
								changeboard(obj[1][row][col+1],1,row,col+1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(row==3){
							if(obj[1][row][col].val()>=3){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row-1][col],1,row-1,col) ;
								changeboard(obj[1][row][col-1],1,row,col-1);
								changeboard(obj[1][row][col+1],1,row,col+1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(col==0){
							if(obj[1][row][col].val()>=3){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row-1][col],1,row-1,col);
								changeboard(obj[1][row][col+1],1,row,col+1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
								}
						}else if(col==3){
							if(obj[1][row][col].val()>=3){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row-1][col],1,row-1,col);
								changeboard(obj[1][row][col-1],1,row,col-1);
							}else{
									obj[1][row][col].assign(role1);
									board[row][col]='b';
							}
						}else{
							if(obj[1][row][col].val()>=4){
								obj[1][row][col].zero();
								board[row][col]='0';
								changeboard(obj[1][row+1][col],1,row+1,col);
								changeboard(obj[1][row-1][col],1,row-1,col);
								changeboard(obj[1][row][col+1],1,row,col+1);
								changeboard(obj[1][row][col-1],1,row,col-1);
							}else{
									obj[1][row][col].assign(role1);
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
						cout<<board[i][j]<<player[1][i][j].val()<<" ";
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