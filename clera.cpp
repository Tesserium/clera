#include<ncurses/curses.h>
#include<iostream>
#include<chrono>
#include<cstdlib>

#define FRAMERATE (100)
#define FPS (1000/(FRAMERATE))
#define MILLISEC() (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count())
#define rf() wrefresh(stdscr)
#define mv(x, y) wmove(stdscr, (y), (x))
#define TINY ((LINES >= 3) && (COLS >= 5))
#define SMALL ((LINES >= 6) && (COLS >= 20))
#define MEDIUM ((LINES >= 12) && (COLS >= 40))
/* not implemented.
#define LARGE ((LINES >= 28) && (COLS >= 80))
#define LARGER ((LINES >= 56) && (COLS >= 160))
*/
using namespace std;

// MEDIUM frames
string medium[20]={R"(                                        
                                        
                                        
                                        
                                        
                                        
                                        
                .                       
          )QCYOwZZf'                    
        "|YXC0c0xvX).                   
           `>_t_I^                      )",R"(                                        
                                        
                                        
                                        
         .mm*bdCaCb{.                   
      `JwhkkbddOdbdapJ                  
       hmmdZdapbwmwbOdp00               
     .`0hkphbakkbbdkhkpdh               
     'Zmdabab*haddaho*Zm                
         .rkk*o*k|                      
            'k>c.                       )",R"(                                        
                                        
                                        
        pkh*hokoa#aha'                  
    .bohooa#ahhkbkkhhp<                 
    hao###MM#aha*oh#bh*                 
     *a*haoa*MM**ahk#o*h#b.             
     .kb*ha#h*#ohbkh**#*#o.             
     .kz"`*ao*#W##dhMWoc.               
        .kkwb#B##apt...                 
            bbkhd..                     )",R"(                                        
                                        
      .BMWBWbpB#M*WWi.                  
      B*o#B$$BBB$$BBMWBM.               
  .BBWBBBBBBBBBBBBBMMW$B.               
  'BMB$#BMB$BWB$BBWBBBBB.               
   .WB#$BBB$#B#WWBBBWBMB$W<.            
     ###BMBBMBo$BBBB$WBB*W#`            
       ..'.WWv**BM.YW$h[^`              
      ."!+kC{cMbhdda_,'                 
          ..o0bfX!. ''                  )",R"(                                        
          mM*M.ao*#Bm,                  
     aBW#bbko$M$$WW$$*@$                
     mobbbk$B$B$$$$$$$BB$<              
 .$$MMM*o*BBBBB$BBB$$$$$$k              
 'B*MBWBBWBBBBBBBBB$MW$$$.              
  .MBBBBaBMBBBBBBBBBB$#$BBk.            
     WBBa0W#hh*h#*#odopaQOp*            
       .'   `_/J00 I/[f[/>.             
     '`Il~<_+)tjj]_nz;<'.               
        .  :_[[_}_Il`:^.                )",R"(            +} pph*##'                  
      Q**Qdmbaabmha*WW$b`               
    rCkhmZZ0BW##*#bka#h*Mx              
   ..mp0QJJdkwkOmkM0mwWpw#.             
 'ZMhw0QJObwmwpmZmd#mmoamho             
 ICYCCQQQC0mmmbmpdpdwwpo#..             
  .zY0w0QQww000ZmhwbQJmOwbCr            
     ,0CJzzJ;1xYzXj}fXvf0Owr|           
        ..  '-_/z}",_"i)[("             
     ,"!I+_->[|1]1<1f~;i..              
       ''  :<]-][_l;,"l.                )",R"(        '0m0mpdpfckddk#Wk.              
     .0bwCOJJ0pommChooMMo#.             
    jYQhYcczh*#*bhoJCZwaoobY            
    .nCXcvczOCm0YQpCvvXmkcOd            
  fZpXvvvxzzzvnnnvCCxnzh0JQk.           
  YzvnnnxxnnxxxxxxxxxnYzQ!;             
  "nxxvvnnvccxjjjtxxjrrxCZOc .          
      tnvrj|t.I</f'.{|[|{XC1)Y          
           .,]~[/+,';''!:!j'            
    .,"ii]}_+~}{1)[]-x-I'.              
       '  .:+]]}[-!I::^'.               )",R"(       "zJ0dZmpoZQOOQ0h*h*BZ            
     `YYYXcXYzXbZJXXddpdo**a            
    iJmmXccvcYoMOCbaXQQZphkwII          
   :. JXzcvzdwQdmzYOonvXJdYZJ`          
  i0dzzcvvzXzXzvvncJpnncOZJQd           
  vCcvvvxxxnnxxxxxnxjxvJC/_(            
  ^rrxxnvvnrnvr1[|}]}{txYJQ]r1'         
        f),[{" `,!, ^}<{1|Y}Itv         
           `i>!_-|>^.I..''/'            
    .`:i>+{{~~-_-)|[])/<`               
       .  .;]]}}{]+>I;''.               )",R"(       XvCYCCYYZoZmz0CcbadhkM;          
     ,YXzzccvncZCnnnxmpQXzOao|          
    .QCYXcvnvcXbaxmkaJCmbbabO.          
   .x'!cccvvddb0dpJCmoxnYYZ0Zw]         
   xpnzccvcQJXzYzcvzYzvvJ0p0O>          
  <Qccvvnxxnvjxnxxxnx[jvQn/)i           
   txjrrxnnxjrn/[<)`]]}jcYx]j{|'        
            `,!..`:  ";<~)n(I;~i        
           .i>>_<_]"'':'. `-.           
    .";I-+1{++>-_||)[(t{'.              
       . 'Il]}[[{-~~l`'..               )",R"(      .vzXXYzccXCJYXJcvvnwhhopW'        
     }fQXXznxnncXxxxxnxCxnnzmOO         
    .xvJcccvnxnznxxdphdnYOdkzX.         
    `+`tvczvXhmb0OYCwYbnncJpQ]Yr        
   ^fJnzcnvvvJYzCCzcJJmnnvmkww<         
   jzcccvnnxxcjfnxrrff}f/n)t],.         
    -jrt|frjt/{tf:;I`:>+|t|fl|1->       
              .^. .^. ':;i]~_,"I]       
           `[il_i;+i.''"'  "..          
     ""!+-~}]-__][1{())!I.              
        ."i>[(}{]+_<l^'...              )",R"(       tXYXXzvczzJ0nvcvnnnncZpwOa.      
     IvJ0czcnxnnvnxxxnxxxxxxnvcn.       
     "j/cvcvvnxxxxxxZz0dxxxrj}i.        
     .;:tfvzcvdX0CQJvwZpJnxXoc~n[       
    .1vnczvvnnzJXJQXzQwwwjvQhmm,        
   '|ccccvnnxxrjrrr1||(-f(-<)\"..        
     .{)1-"|)+-_]],'^ ':I]i~<"l_}t.     
                ....'. .''`^^"''^:      
           .I_:Il;;I:...''  .'          
    .':<>--<{}+_{[1}1([I"`.             
         "~<_](1]]<l,^'..               )",R"(       ^CJYYYcnvzXOYnnvnnxxxxcmZnQi     
     .|tQJcvvnnnnnxxxxnnxnfrrnvc-.      
      _)|xnvvvnnxxxJJnnxnxxjt!`         
      '++jjcccnYcO0JXnJkncvfcat~+;      
     '1nvccvvnncXXYJJnCmZZ|(r0JC        
    ")vccvvnnxj/tnnj>({[1)[;"I..        
       i-{I'<+_;i_+i.. .'`I;l:^"I+|'    
                  . ..  ....'''..'`     
          ..!>i,,,"`^^'....  .          
    .."<i<[i>{}+}-+[[[>:^''             
        .:~>]+|1[<!;`''..               )",R"(        fQCYXzcnnXJQvnnnnnxxxxx0nvnx    
       ]{zYXvvvvvvnnxrrncnnX1}(x<i      
       `_[-f(1/nnnnnXmvvnnnvf}'         
        ;)|(zvvnnvnzvxxxkbzJY(w|];,     
       _tczXzcnnnczXzXrJZZzxl_){t.      
      {rvcnnxxjt[]|tt1`,;>--^``..       
        .`l:'">;;'i_i    ..'`"`''`i;,   
                      .   .  ........   
           ^';:"'``...''....            
     .'I>>l>I<-+__>]-+;"`...            
        .,!<+~-1_<;"'....               )",R"(        I{ZQXzzzccJJYnxxrjjrj)}jYvnnrx  
       .:!)nXcnxtvXzvvjtjxncCnI;_`      
        `!":+]jrrxvvzYJwvznzJv1-I       
          }{QQccvrrjnxj/xYQXwk<zv+^`    
        '+nJJXzvjj1vCvrxt0XJ|"`lll:.    
       "<vnn|//)[]ilj[1<...;l"'..       
           ....`:``.`;I     .......'"^' 
                               ...  ... 
           ^"'``..'.......  .           
     .."<i;;ll-<]~!I-I"'''..            
        '^l>i]-~_I"`'... .              )",R"(         `:[fnvXYX(nvXvfr[+_(x|;l]t|11+`
         '"i+[{}fjtfzzj|1))(fJx{"`'     
        ..''':;^_j|jnvJf()frYvx{>>.     
           `~xcx)n(}(|jj{}fcXOOi>l;"..  
          .lfXfxrj}([/([-~>]}-^'.```.   
         :]||]+~]+;^`<;~l'  .'`...      
                ..'..  '.       ..  ..''
                                        
            ''.......     .             
      .`<;^`II:l[I::;^''...             
        .'^!>>-+<"'...                  )",R"(          '`I<}{(1|)||j{[]_<!]1-^^'""^[+
          .'`";!i~)|)rj]_iIli]t|-^..    
          ....``>:i!i;-(}<i~(|}-I^^'.   
            ."1Z}-|(_+<]-[!>>+/)+^"`'.  
            `>1(}}{~!>}~I;:,`,,^'.....  
           `~+!,,,;"'''^`^`    .        
                  ....                 .
                                        
             .....                      
      .."``'^^`"i,^^`'....              
        ..'"l+]-"'...                   )",R"(           ..'^,I;II;l!iI,::"`^l+,......
            ...''^",,",;;;;^```;I"`'.   
            .....!,`^^^",,<"``,I:^'...  
               `,<:,:!:::I;"``'`,,'.... 
              .^:;::",""Il`.'. ....  .  
             .^"`'.''' ... ..           
                      .                 
                                        
               ..                       
       .''..'..'``''...                 
         ..'l]~!`....                   )",R"(             ....'``''.''`'''....'^'.   
              .....'`''''''''.........  
                 ..;'...''''`'....'...  
                 ...'''`'''``. . ..'.   
                 .'''.''''``.           
                .'...                   
                                        
                                        
                                        
       ..............                   
           .^lI'..                      )",R"(                   ............    ..   
                    .'...........       
                   .''..........    .   
                    ...........     .   
                   ...........          
                  ..                    
                                        
                                        
                                        
               ...                      
           ..`^..                       )",R"(                                        
                       .                
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        )"};

void play_frame(int64_t f)
{
    if(f <= FPS) // in the first second the bomb crashes on the ground
    {
	clear(); rf();
	double col = (COLS - 4) / 2.0 / ((double)FPS) * f;
	double acc = 2 * (LINES - 1) / ((double)(FPS * FPS));
	double lin = acc * f * f / 2;
	mv(col, lin);
	addch('O');
	rf();
	return;
    }
    if(f <= FPS + 20)
    {
	clear(); rf();
	int f_ = f - FPS - 1;
	int col = COLS / 2 - 20;
	int lin = LINES - 11;
	mv(col, lin);
	for(int i = 0; i < medium[f_].length(); i++)
	{
	    if(medium[f_][i]=='\n')
	    {
		mv(col, ++lin);
	    }
	    else addch(medium[f_][i]);
	}
	rf();
    }
    return;
}

int clera()
{
    initscr();
    if(!TINY)
    {
	endwin();
	cout << "How did you get such a tiny terminal window??" << endl;
	return 0;
    }
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    int64_t frame = -1;
    int64_t beginning = MILLISEC();
    for (;;)
    {
	int64_t now = MILLISEC();
	if((now - beginning) / FRAMERATE > frame)
	{
	    frame = (now - beginning) / FRAMERATE;
	    play_frame(frame);
	}
	if(getch() != ERR || frame > FPS + 20)
	{
	    return 0; // people nowadays are busy & they probably don't have the time to watch the whole animation.
	}
    }
    endwin();
    return 0;
}

int main(int argc, const char** argv)
{
    int ret = clera();
    system("clear");

    return ret;
}

