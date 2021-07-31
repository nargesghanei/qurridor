#include<iostream>
#include<string>
using namespace std;

class board
{
	public:
		/*string B[130]={"        ","        ","        ","        ","        ","****A***","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"****C***","        ","        ","        ","        ","        ","        ","        ","        ","        ","****D***",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","        ","        ","        ","        ","        ","        ",
		"        ","        ","        ","        ","        ","****B***","        ","        ","        ","        ","        "};

		string hw[130]={"    0   ","    1   ","    2   ","    3   ","    4   ","    5   ","    6   ","    7   ","    8   ","    9   ","   10   ",
		"   11   ","   12   ","   13   ","   14   ","   15   ","   16   ","   17   ","   18   ","   19   ","   20   ","   21   ",
		"   22   ","   23   ","   24   ","   25   ","   26   ","   27   ","   28   ","   29   ","   30   ","   31   ","   32   ",
		"   33   ","   34   ","   35   ","   36   ","   37   ","   38   ","   39   ","   40   ","   41   ","   42   ","   43   ",
		"   44   ","   45   ","   46   ","   47   ","   48   ","   49   ","   50   ","   51   ","   52   ","   53   ","   54   ",
		"   55   ","   56   ","   57   ","   58   ","   59   ","   60   ","   61   ","   62   ","   63   ","   64   ","   65   ",
		"   66   ","   67   ","   68   ","   69   ","   70   ","   71   ","   72   ","   73   ","   74   ","   75   ","   76   ",
		"   77   ","   78   ","   79   ","   80   ","   81   ","   82   ","   83   ","   84   ","   85   ","   86   ","   87   ",
		"   88   ","   89   ","   90   ","   91   ","   92   ","   93   ","   94   ","   95   ","   96   ","   97   ","   98   ",
		"   99   ","   100  ","   101  ","   102  ","   103  ","   104  ","   105  ","   106  ","   107  ","   108  ","   109  ",
		"   110  ","   111  ","   112  ","   113  ","   114  ","   115  ","   116  ","   117  ","   118  ","   119  ","   120  "};*/
		string brd[1000]={"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","  A ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"  0 ","|","  1 ","|","  2 ","|","  3 ","|","  4 ","|","  5 ","|","  6 ","|","  7 ","|","  8 ","|","  9 ","|"," 10 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 11 ","|"," 12 ","|"," 13 ","|"," 14 ","|"," 15 ","|"," 16 ","|"," 17 ","|"," 18 ","|"," 19 ","|"," 20 ","|"," 21 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 22 ","|"," 23 ","|"," 24 ","|"," 25 ","|"," 26 ","|"," 27 ","|"," 28 ","|"," 29 ","|"," 30 ","|"," 31 ","|"," 32 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 33 ","|"," 34 ","|"," 35 ","|"," 36 ","|"," 37 ","|"," 38 ","|"," 39 ","|"," 40 ","|"," 41 ","|"," 42 ","|"," 43 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 44 ","|"," 45 ","|"," 46 ","|"," 47 ","|"," 48 ","|"," 49 ","|"," 50 ","|"," 51 ","|"," 52 ","|"," 53 ","|"," 54 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"  C ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","  D ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 55 ","|"," 56 ","|"," 57 ","|"," 58 ","|"," 59 ","|"," 60 ","|"," 61 ","|"," 62 ","|"," 63 ","|"," 64 ","|"," 65 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 66 ","|"," 67 ","|"," 68 ","|"," 69 ","|"," 70 ","|"," 71 ","|"," 72 ","|"," 73 ","|"," 74 ","|"," 75 ","|"," 76 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 77 ","|"," 78 ","|"," 79 ","|"," 80 ","|"," 81 ","|"," 82 ","|"," 83 ","|"," 84 ","|"," 85 ","|"," 86 ","|"," 87 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 88 ","|"," 89 ","|"," 90 ","|"," 91 ","|"," 92 ","|"," 93 ","|"," 94 ","|"," 95 ","|"," 96 ","|"," 97 ","|"," 98 ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 99 ","|"," 100","|"," 101","|"," 102","|"," 103","|"," 104","|"," 105","|"," 106","|"," 107","|"," 108","|"," 109",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		"    ","|","    ","|","    ","|","    ","|","    ","|","  B ","|","    ","|","    ","|","    ","|","    ","|","    ",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----",
		" 110","|"," 111","|"," 112","|"," 113","|"," 114","|"," 115","|"," 116","|"," 117","|"," 118","|"," 119","|"," 120",
		"----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----","-","----"
		};
		board(int);
		string print_board();

};
//////////////////////////////////////////////////////////////////
board::board(int num_of_players)
{
    if(num_of_players==2)
	    brd[461]=brd[441]="    ";
	else if(num_of_players==3)
	    brd[461]="    ";
}
//////////////////////////////////////////////////////////////////
/*void board::print_board()
{
	cout<<char(201);                      
	for(int j=0 ; j<11 ; j++)
	{
		for(int i=0 ; i<8 ; i++)
	    {
		    cout<<char(205);
	    }
		if(j!=10)
	        cout<<char(203)<<char(205)<<char(205)<<char(205)<<char(203);
		else
		    cout<<char(187)<<endl;
	}                                    
    int x=0,d=0;
	for(int l=0 ; l<10 ; l++)
	{
        for(int i=0 ; i<12 ; i++)
	    {
		    cout<<char(186);
		    if(i!=0 && i!=11)
		        cout<<"   "<<char(186);
		    if(i!=11 && i!=5)
		        cout<<B[x++];
			else if(i==5 && l==5)
			{
                cout<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177);
				x++;
			}   
			else if(l!=5 && i==5)
		        cout<<B[x++];
		    else
		        cout<<endl;
	    }
		
	    cout<<char(204);
	    for(int j=0 ; j<11 ; j++)
	    {
		    if(j!=0)
		        cout<<char(205)<<char(205)<<char(205)<<char(206);
		    for(int i=0 ; i<8 ; i++)
	            cout<<char(205);
        
		    if(j!=10)
		        cout<<char(206);
		    else
		        cout<<char(185)<<endl;
	    }
		for(int i=0 ; i<12 ; i++)
	    {
		    cout<<char(186);
		    if(i!=0 && i!=11)
		        cout<<"   "<<char(186);
		    if(i!=11)
		        cout<<hw[d++];
		    else
		        cout<<endl;
	    }
	    cout<<char(204);
	    for(int j=0 ; j<11 ; j++)
	    {
		    if(j!=0)
		        cout<<char(205)<<char(205)<<char(205)<<char(206);
		    for(int i=0 ; i<8 ; i++)
	            cout<<char(205);
        
		    if(j!=10)
		        cout<<char(206);
		    else
		        cout<<char(185)<<endl;
	    }
	}

	for(int i=0 ; i<12 ; i++)
	{
		cout<<char(186);
		if(i!=0 && i!=11)
		    cout<<"   "<<char(186);
		if(i!=11)
		    cout<<B[x++];
		else
		    cout<<endl;
    	}

	cout<<char(204);
	    for(int j=0 ; j<11 ; j++)
	    {
		    if(j!=0)
		        cout<<char(205)<<char(205)<<char(205)<<char(206);
		    for(int i=0 ; i<8 ; i++)
	            cout<<char(205);
        
		    if(j!=10)
		        cout<<char(206);
		    else
		        cout<<char(185)<<endl;
	    }

    for(int i=0 ; i<12 ; i++)
	{
		cout<<char(186);
		if(i!=0 && i!=11)
		    cout<<"   "<<char(186);
		if(i!=11)
		    cout<<hw[d++];
		else
		    cout<<endl;
	} 

	cout<<char(200);
	for(int i=0 ; i<11 ; i++)
	{
		if(i!=0)
		    cout<<char(205)<<char(205)<<char(205)<<char(202);
		for(int j=0 ; j<8 ; j++)
		{
			cout<<char(205);
		}
		if(i!=10)
		    cout<<char(202);
		else
		    cout<<char(188);
	}
}*/
//////////////////////////////////////////////////////////////////
string board::print_board()
{
	string map = "";
	for(int i = 0; i<45 ; i++)
	{
		for(int j = 0; j < 21 ; j++)
		{
			map += brd[i*21+j];
		}
		map += '\n';
	}
	return map;
}
//////////////////////////////////////////////////////////////////