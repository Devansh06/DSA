
#include"AI.cpp"

//check the column in the grid
int checkx(int a){
   if(a>=150&&a<250)
        return 2;
    if(a>=250&&a<350)
        return 3;
    if(a>=350&&a<450)
        return 4;
    if(a>=450&&a<550)
        return 5;
    if(a>=550&&a<650)
        return 6;
    if(a>=650&&a<750)
        return 7;
    if(a>=750&&a<850)
        return 8;
}
//termination condition
bool terminate(cell c[][11]){
    for(int i=2;i<8;i++)
        for(int j=2;j<9;j++){
            if(c[i][j].checkStatus()==1){
                if(c[i][j].ch==c[i][j+1].ch){
                    if(c[i][j+1].ch==c[i][j+2].ch)
                        if(c[i][j+2].ch==c[i][j+3].ch){
                            return false;
                            break;
                        }
                }
                if(c[i][j].ch==c[i+1][j].ch){
                    if(c[i+1][j].ch==c[i+2][j].ch)
                        if(c[i+2][j].ch==c[i+3][j].ch)
                            return false;
                }

            if(i<6){
                if(c[i][j].ch==c[i+1][j+1].ch){
                    if(c[i+1][j+1].ch==c[i+2][j+2].ch)
                        if(c[i+2][j+2].ch==c[i+3][j+3].ch)
                            return false;
                }
                if(c[i][j].ch==c[i+1][j-1].ch && j>2){
                    if(c[i+1][j-1].ch==c[i+2][j-2].ch)
                        if(c[i+2][j-2].ch==c[i+3][j-3].ch)
                            return false;
            }

          }
        }
    }
    return true;
}
//count the no. of moves
void countmoves(int count){
    Text t2(920,500,"No. of moves:");
    t2.imprint();
    Text t3(920,540,count);
    t3.imprint();
    }
//if comp wins
void compwin(int count){
    Text t(500,150,"GAME OVER!!!");
    t.imprint();
    Text t1(500,170,"You lose!");
    t1.imprint();
    Text t2(920,500,"No. of moves:");
    t2.imprint();
    Text t3(920,540,count);
    t3.imprint();
    }
//if player wins
void playerwin(int count){
    Text t(500,150,"GAME OVER!!!");
    t.imprint();
    Text t1(500,170,"You win!");
    t1.imprint();
    Text t2(920,500,"No. of moves:");
    t2.imprint();
    Text t3(920,540,count);
    t3.imprint();
    }
//makes the board and sets relevent class elments
void makeboard(cell c[][11]){
    int p=0,q=0;
    for(int i=2;i<8;i++){
        for(int j=2;j<9;j++){
            Circle c(200+p,750-q,40);
            p=p+100;
            c.imprint();
        }
        p=0;
        q=q+100;
    }
    p=0;q=0;
    for(int i=2;i<8;i++){
        for(int j=2;j<9;j++){
            c[i][j].readcell(200+p,750-q);
            p=p+100;
        }
    p=0;
    q=q+100;
    }
    //trash
    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            c[i][j].trashcell();
        }
    }
    for(int i=2;i<8;i++){
        for(int j=0;j<2;j++){
            c[i][j].trashcell();
        }
        for(int j=9;j<11;j++){
            c[i][j].trashcell();
        }
    }
    for(int i=8;i<10;i++){
        for(int j=0;j<11;j++){
            c[i][j].trashcell();
        }
    }
}
//2 player game
void play2player(cell c[][11]){
    int i;
    while(1){
    //player1 turn
        int a=getClick();
        int ax=a/65536;
        int j=checkx(ax);
        for(i=2;i<9;i++){
            if(c[i][j].checkStatus()==0)
                break;
        }
        c[i][j].movecircleplayer();
        if(!terminate(c)){
            Text t(500,150,"GAME OVER!!!");
            t.imprint();
            Text t1(500,170,"Player 1 wins");
            t1.setColor(COLOR("red"));
            t1.imprint();
            break;
        }
    //player2 turn
    int b=getClick();
        int bx=b/65536;
        int k=checkx(bx);
        for(i=2;i<9;i++){
            if(c[i][k].checkStatus()==0)
                break;
        }
        c[i][k].movecircleplayer1();
        if(!terminate(c)){
            Text t(500,150,"GAME OVER!!!");
            t.imprint();
            Text t1(500,170,"Player 2 wins");
            t1.setColor(COLOR("yellow"));
            t1.imprint();
            break;
        }
    }
}
//easy mode
void playeasy(cell c[][11]){
    int i,count=0;
    while(true){
        //comp's turn
        int p,n;
                do{
                    n=rand() % 7 +2;
                    for(i=2;i<9;i++){
                        if(c[i][n].checkStatus()==0){
                            p=i;
                            break;
                        }
                    }
                }
                while(c[p][n].checkStatus()==0);
                c[p][n].movecirclecomp();
        if(!terminate(c)){
            compwin(count);
            break;
        }
        //user turn
        int a=getClick();
        int ax=a/65536;
        int j=checkx(ax);
        for(i=2;i<9;i++){
            if(c[i][j].checkStatus()==0)
                break;
        }
        c[i][j].movecircleplayer();
        count++;
        if(!terminate(c)){
            playerwin(count);
            break;
        }
    }
}
//medium mode
void playmedium(cell c[][11]){
    int count=0;
    while(1){
        //computer's turn
        cout<<endl;
        if(make4(c))
            break;
        else if(block4(c));
        else if(make3medium(c));
        else if(make2(c));
        else{
            cout<<"random"<<endl;
            int i, p,n;
                do{
                    n=rand() % 7 +2;
                    for(i=2;i<9;i++){
                        if(c[i][n].checkStatus()==0){
                            p=i;
                            break;
                        }
                    }
                }
                while(c[p][n].checkStatus()==0);
                c[p][n].movecirclecomp();

            if(!terminate(c)){
                compwin(count);
                break;
            }
        }
        cout<<endl;
        //user's turn
        int i;
        int a=getClick();
        int ax=a/65536;
        int j=checkx(ax);
        for(i=2;i<9;i++){
            if(c[i][j].checkStatus()==0)
                break;
        }
        c[i][j].movecircleplayer();
        count++;
        if(!terminate(c)){
            playerwin(count);
            break;
        }
    }
}
//checks one specific strategy
bool strat(cell c[][11]){
    int i,k;
    for(k=0;k<2;k++){
        for(i=3;i<5;i++){
            if(c[i][i+k].ch=='p' && c[i+2][i+2+k].ch=='p' && !c[i+1][i+1+k].checkStatus() && c[i][i+1+k].checkStatus() && !c[i+3][i+3+k].checkStatus() && !c[i-1][i-1+k].checkStatus() && c[i+2][i+3+k].checkStatus()&& c[i-2][i-1+k].checkStatus())
                return true;
        }
    }
    k=2;
    for(i=3;i<5;i++){
        if(c[i][i+k].ch=='p' && c[i+2][i+2+k].ch=='p' && !c[i+1][i+1+k].checkStatus() && c[i][i+1+k].checkStatus() && !c[i+3][i+3+k].checkStatus() && !c[i-1][i-1+k].checkStatus() && c[i+2][i+3+k].checkStatus()&& c[i-2][i-1+k].checkStatus())
                return true;
        k=-1;
    }

    for(k=0;k<2;k++){
        for(i=3;i<5;i++){
            if(c[i][9-i+k].ch=='p' && c[i+2][7-i+k].ch=='p' && !c[i+1][8-i+k].checkStatus() && c[i][8-i+k].checkStatus() && !c[i+3][6-i+k].checkStatus() && !c[i-1][10-i+k].checkStatus() && c[i+2][6-i+k].checkStatus()&& c[i-2][10-i+k].checkStatus())
                return true;
        }
    }
    k=0;
    for(i=3;i<5;i++){
        if(c[i][8-i+k].ch=='p' && c[i+2][6-i+k].ch=='p' && !c[i+1][7-i+k].checkStatus() && c[i][7-i+k].checkStatus() && !c[i+3][5-i+k].checkStatus() && !c[i-1][9-i+k].checkStatus() && c[i+2][5-i+k].checkStatus()&& c[i-2][9-i+k].checkStatus())
                return true;
        k=3;
    }
    return false;
}
//diff level
void playdiff(cell c[][11]){
    bool b=false; int count=0;
    while(1){
        //computer's turn
        cout<<endl;
        if(strat(c)){
            if(make4(c)){
            break;
            }
            else if(block4(c));
            else if(block3(c));
            else if(make3(c));
            else if(make2(c));
            else{
                cout<<"random";
                int i, p,n;
                do{
                    n=rand() % 7 +2;
                    for(i=2;i<9;i++){
                        if(c[i][n].checkStatus()==0){
                            p=i;
                            break;
                        }
                    }
                }
                while(c[p][n].checkStatus()!=0);
                c[p][n].movecirclecomp();
                cout<<endl;
            }
        }
        else if(!strat(c)){
            if(make4(c)){
            b=true;
            break;
            }
            else if(block4(c));
            else if(make3(c));
            else if(block3(c));
            else if(make2(c));
            else{
                cout<<"random";
                int i, p,n;
                do{
                    n=rand() % 7 +2;
                    for(i=2;i<9;i++){
                        if(c[i][n].checkStatus()==0){
                            p=i; break;
                        }
                    }
                    c[p][n].movecirclecomp();
                }
                while(c[p][n].checkStatus()==0);
            }
        }
            if(!terminate(c) ){
                b=true;
                break;
            }
        cout<<endl;
        //user's turn
        int i;
        int a=getClick();
        int ax=a/65536;
        int j=checkx(ax);
        for(i=2;i<9;i++){
            if(c[i][j].checkStatus()==0)
                break;
        }
        c[i][j].movecircleplayer();
        count++;
        if(!terminate(c)){
            b=false;
            break;
        }
        countmoves(count);
    }
    if(b) compwin(count);
        else playerwin(count);

}
//for exiting screen
bool exitscreen(){
    Text t(500,250,"Are you sure want to exit?");
    Text t1(475,300,"Yes");
    int x=textWidth("Yes")+20;
    int y=textheight("Yes")+30;
    Rectangle r1(475,300,x,y);
    Text t2(525,300,"No");
    Rectangle r2(525,300,x,y);
    while(true){
    int c=getClick();
    int cx=c/65536; int cy=c%65536;
        if(cx>=475-x/2&&cx<=475+x/2&&cy>=300-y/2&&cy<=300+y/2)
            return true;
        if(cx>=525-x/2&&cx<=525+x/2&&cy>=300-y/2&&cy<=300+y/2)
            return false;
    }
}

//start of the game
char start(){
    Text t(500,0,"CONNECT FOUR");
    while(t.getY()<240) t.move(0,6);
    Text t1(0,300,"One Player");
    while(t1.getX()<500) t1.move(10,0);
    int x=textWidth("One Player")+50;
    int y=textheight("One Player")+30;
    Rectangle r1(500,300,x,y);
    Text t2(1000,350,"Two Players");
    while(t2.getX()>500) t2.move(-10,0);
    Rectangle r2(500,350,x,y);
    Text t3(500,1000,"Exit");
    while(t3.getY()>400) t3.move(0,-15);
    Rectangle r3(500,400,x,y);
    while(true){
    int c=getClick();
    int cx=c/65536; int cy=c%65536;

        if(cx>=500-x/2&&cx<=500+x/2&&cy>=300-y/2&&cy<=300+y/2){
            t1.hide(); t2.hide(); t3.hide();
            r1.hide(); r2.hide(); r3.hide();
            return 'o';
        }
        if(cx>=500-x/2&&cx<=500+x/2&&cy>=350-y/2&&cy<=350+y/2){
            t1.hide(); t2.hide(); t3.hide();
            r1.hide(); r2.hide(); r3.hide();
            return 'd';
        }
        if(cx>=500-x/2&&cx<=500+x/2&&cy>=400-y/2&&cy<=400+y/2){
            t1.hide(); t2.hide(); t3.hide();
            r1.hide(); r2.hide(); r3.hide();
            return 'q';
        }
    }
}
//returns whether to play easy, medium and difficult
char difflevel(){
    Text t(500,350,"Choose Difficulty level");
    Text t1(500,400,"EASY");
    int x=textWidth("EASY")+50;
    int y=textheight("EASY")+30;
    Rectangle r1(500,400,x,y);
    Text t2(500,450,"MEDIUM");
    Rectangle r2(500,450,x,y);
    Text t3(500,500,"DIFFICULT");
    Rectangle r3(500,500,x,y);
    while(true){
    int c=getClick();
    int cx=c/65536;
    int cy=c%65536;
        if(cx>=500-x/2&&cx<=500+x/2&&cy>=400-y/2&&cy<=400+y/2){
            t.hide();
            t1.hide();r1.hide();
            t2.hide();r2.hide();
            t3.hide();r3.hide();
            return 'e';
        }
        if(cx>=500-x/2&&cx<=500+x/2&&cy>=450-y/2&&cy<=450+y/2){
            t.hide();
            t1.hide();r1.hide();
            t2.hide();r2.hide();
            t3.hide();r3.hide();
            return 'm';
        }
        if(cx>=500-x/2&&cx<=500+x/2&&cy>=500-y/2&&cy<=500+y/2){
            t.hide();
            t1.hide();r1.hide();
            t2.hide();r2.hide();
            t3.hide();r3.hide();
            return 'd';
        }
    }
}











