#include<simplecpp>
#include<stdlib.h>
#include<ctime>
class cell{
    int x, y;
    int status;

    public:
        char ch;
        cell(){                 //constructor
            status=0;
            ch='n';
        }
        void readcell(int a,int b){     //sets coordinates
            x=a;
            y=b;
        }
        void trashcell(){              //sets the cells outside the boundary
            status=1;
            ch='x';
        }
        int checkStatus(){
            return status;
        }
        void changeStatus(){
            if(status){
                status=0;
                ch='n';
            }
            else{
                status=1;
                ch='c';
            }
        }
        void movecirclecomp(){          //moves circle to specified position and sets ch and status
            Circle c(x,150,40);
            c.setColor(COLOR("yellow"));
            c.setFill(1);
            while(c.getY()<y){
                int i=10;
                c.move(0,i);
                i=i+2;
            }
            c.imprint();
            ch='c';
            status=1;
        }
        void movecircleplayer(){        //moves circle of player
            Circle c(x,150,40);
            c.setColor(COLOR("red"));
            c.setFill(1);
            while(c.getY()<y){
                int i=10;
                c.move(0,i);
                i=i+2;
            }
            c.imprint();
            ch='p';
            status=1;
        }
        void movecircleplayer1(){       //needed for 2 players game
            Circle c(x,150,40);
            c.setColor(COLOR("yellow"));
            c.setFill(1);
            while(c.getY()<y){
                int i=5;
                c.move(0,i);
                i=i+2;
            }
            c.imprint();
            ch='q';
            status=1;
        }
};

