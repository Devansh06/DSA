#include"Gameplay.cpp"
main_program{
   simplecpp::srand(time(NULL));
    cell c[10][11];
    initCanvas("Connect four",1000,1000);
    while(1){
        char s=start();
        if(s=='o'){                 //if s returns one player mode
            char d=difflevel();     //choose difficulty level
            Rectangle r1(500,500,700,600);
            r1.imprint(1);
            makeboard(c);
            if(d=='e')
                playeasy(c);            //easy level
            if(d=='m')
                playmedium(c);          //medium level
            if(d=='d')
                playdiff(c);            //difficult level
            break;
        }
        else if(s=='d') {           //if s returns two player mode
            Rectangle r1(500,500,700,600);
            r1.imprint(1);
            makeboard(c);
            play2player(c);
            break;

        }
        else{
            if(exitscreen()) break;
            else continue;
        }
    }
    wait(5);
}
