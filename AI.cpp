 #include"Data.h"
bool isBlock3( cell c[][11] , int i, int j){
    if((c[i-1][j-1].ch=='p' && c[i-2][j-2].ch=='p') ||(c[i+1][j-1].ch=='p' && c[i+2][j-2].ch=='p')||(c[i][j-1].ch=='p'   && c[i][j-2].ch=='p')  ||
        (c[i][j+1].ch=='p'  && c[i][j+2].ch=='p')   ||(c[i-1][j+1].ch=='p' && c[i-2][j+2].ch=='p')||(c[i+1][j+1].ch=='p' && c[i+2][j+2].ch=='p')||
        (c[i-1][j-1].ch=='p'&& c[i+1][j+1].ch=='p')||(c[i][j-1].ch=='p'   && c[i][j+1].ch=='p'))
        return true;
    else
        return false;
}

bool isFill(cell c){
    if(c.ch=='p'||c.ch=='x')
        return true;
    else
        return false;
}

bool isMake3(cell c[][11], int i, int j){
    if((c[i-1][j-1].ch=='c' && c[i-2][j-2].ch=='c' && !isFill(c[i+1][j+1])) ||(c[i+1][j-1].ch=='c' && c[i+2][j-2].ch=='c' && !isFill(c[i-1][j+1]))||
       (c[i][j-1].ch=='c'   && c[i][j-2].ch=='c'   && !isFill(c[i][j+1]))   ||(c[i][j+1].ch=='c'   && c[i][j+2].ch=='c'   && !isFill(c[i][j-1]))  ||
       (c[i-1][j+1].ch=='c' && c[i-2][j+2].ch=='c' && !isFill(c[i+1][j-1])) ||(c[i+1][j+1].ch=='c' && c[i+2][j+2].ch=='c' && !isFill(c[i-1][j-1]))||
       (c[i-1][j-1].ch=='c' && c[i+1][j+1].ch=='c'&&(!isFill(c[i+2][j+2])  || !isFill(c[i-2][j-2])))||
       (c[i][j-1].ch=='c'   && c[i][j+1].ch=='c'  &&(!isFill(c[i][j+2])    || !isFill(c[i][j-2])))  ||
       (c[i+1][j-1].ch=='c' && c[i-1][j+1].ch=='c'&&(!isFill(c[i+2][j-2])  || !isFill(c[i-2][j+2]))))
        return true;
    else
        return false;

}

bool isMake4(cell c[][11]){
    int i,j,p,q,k=-2,m=3;
    bool b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+1].ch=='p' && c[i][j+2].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
        }
    if(b){
        if(!c[p][q+3].checkStatus() && c[p-1][q+3].checkStatus()){
            return true;
        }
        else if(c[p][q+3].checkStatus() && !c[p][q-1].checkStatus() && c[p-1][q-1].checkStatus()){
            return true;
        }
    }
    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+1].ch=='p' && c[i][j+3].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
    }
    if(b){
        if(!c[p][q+2].checkStatus() && c[p-1][q+2].checkStatus()){
            return true;
        }
    }

    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+2].ch=='p' && c[i][j+3].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(!c[p][q+1].checkStatus() && c[p-1][q+1].checkStatus()){
            return true;
        }
    }

    b=false;
    for(i=2;i<9;i++){
        for(j=2;j<5;j++){
            if(c[j][i].ch=='p' && c[j+1][i].ch=='p' && c[j+2][i].ch=='p'){
                p=i;q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(!c[q+3][p].checkStatus()){
            return true;
        }
    }
    //along diagonal

    while(k<4){
        if(k<0) m--;
        else m=0;
        b=false;
        for(i=2+m;i<8-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+1][i+1+k].ch=='p' && c[i+2][i+2+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(!c[p+3][p+3+k].checkStatus() && c[p+2][p+3+k].checkStatus()){
                return true;
            }
            else if(c[p+3][p+3+k].checkStatus() && !c[p-1][p-1+k].checkStatus() && c[p-2][p-1+k].checkStatus()){
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+1][i+1+k].ch=='p' && c[i+3][i+3+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(!c[p+1][p+2+k].checkStatus() && !c[p+2][p+2+k].checkStatus()){
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+2][i+2+k].ch=='p' && c[i+3][i+3+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p][p+1+k].checkStatus() && !c[p+1][p+1+k].checkStatus()){
                return true;
            }
        }
        k++;
    }

    k=-2;
    m=2;

    while(k<4){
        if(k<0) m--;
        else m=0;
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+1][9-k-i].ch=='p' && c[i+2][8-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(!c[p+3][7-k-p].checkStatus() && c[p+2][7-k-p].checkStatus()){
                return true;
            }
            else if(c[p+3][7-k-p].checkStatus() && !c[p-1][11-k-p].checkStatus() && c[p-2][11-k-p].checkStatus()){
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+1][9-k-i].ch=='p' && c[i+3][7-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+1][8-k-p].checkStatus() && !c[p+2][8-k-p].checkStatus()){
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+2][8-k-i].ch=='p' && c[i+3][7-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p][9-k-p].checkStatus() && !c[p+1][9-k-p].checkStatus()){
                return true;
            }
        }
        k++;
    }
    return false;
}

bool make2(cell c[][11]){
    cout<<"make2"<<endl;
    int p,q,i,j;
    bool b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if(c[i][j].ch=='c'){
                p=i; q=j;
                b=true;
                break;
            }
        }
        if(b)break;
    }
    if(b){
        if(c[p][q+1].checkStatus()==0 && !isFill(c[p][q+2])){
                c[p][q+1].movecirclecomp();
                return true;
        }
        else if(c[p][q-1].checkStatus()==0 && !isFill(c[p][q-2])){
                c[p][q-1].movecirclecomp();
                return true;
        }
        else if(c[p+1][q+1].checkStatus()==0 && c[p][q+1].checkStatus()==1 && !isFill(c[p+2][q+2])){
                c[p+1][q+1].movecirclecomp();
                return true;
        }
        else if(c[p-1][q-1].checkStatus()==0 && c[p-2][q-1].checkStatus()==1 && !isFill(c[p-2][q-2])){
                c[p-1][q-1].movecirclecomp();
                return true;
        }
        else if(c[p+1][q-1].checkStatus()==0 && c[p][q-1].checkStatus()==1 && !isFill(c[p+2][q-2])){
                c[p+1][q-1].movecirclecomp();
                return true;
        }
        else if(c[p-1][q+1].checkStatus()==0 && c[p-2][q+1].checkStatus()==1 && !isFill(c[p-2][q+2])){
                c[p-1][q+1].movecirclecomp();
                return true;
        }
        else if(c[p+1][q].checkStatus()==0){
                c[p+1][q].movecirclecomp();
                return true;
        }
        else if(c[p][q+1].checkStatus()==0 ){
                c[p][q+1].movecirclecomp();
                return true;
        }
        else if(c[p][q-1].checkStatus()==0 ){
                c[p][q-1].movecirclecomp();
                return true;
        }
    }
    return false;
}

bool make4(cell c[][11]){
    cout<<"make4"<<endl;
    int i,j,p,q,k=-2,m=3;
    bool b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='c' && c[i][j+1].ch=='c' && c[i][j+2].ch=='c'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
        }
    if(b){
        if(c[p][q+3].checkStatus()==0 && c[p-1][q+3].checkStatus()==1){
            c[p][q+3].movecirclecomp();
                return true;
        }
            //cout<<"1 if"<<endl;
        else if(c[p][q+3].checkStatus()==1 && c[p][q-1].checkStatus()==0 && c[p-1][q-1].checkStatus()==1){
            c[p][q-1].movecirclecomp();
            return true;
        }
    }
    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='c' && c[i][j+1].ch=='c' && c[i][j+3].ch=='c'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
    }
    if(b){
        if(c[p][q+2].checkStatus()==0 && c[p-1][q+2].checkStatus()==1){
            c[p][q+2].movecirclecomp();
                return true;
        }
    }

    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='c' && c[i][j+2].ch=='c' && c[i][j+3].ch=='c'){
               p=i; q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(c[p][q+1].checkStatus()==0 && c[p-1][q+1].checkStatus()==1){
            c[p][q+1].movecirclecomp();
                return true;
        }
    }

    b=false;
    for(i=2;i<9;i++){
        for(j=2;j<5;j++){
            if(c[j][i].ch=='c' && c[j+1][i].ch=='c' && c[j+2][i].ch=='c'){
                p=i;q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(c[q+3][p].checkStatus()==0){
            c[q+3][p].movecirclecomp();
                return true;
        }
    }
    //along diagonal
    b=false;
    while(k<4){
        if(k<0) m--;
        else m=0;
        for(i=2+m;i<8-k-2*m;i++){
            if(c[i][i+k].ch=='c' && c[i+1][i+1+k].ch=='c' && c[i+2][i+2+k].ch=='c'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+3][p+3+k].checkStatus()==0 && c[p+2][p+3+k].checkStatus()==1){
                c[p+3][p+3+k].movecirclecomp();
                return true;
            }
            else if(c[p+3][p+3+k].checkStatus()==1 && c[p-1][p-1+k].checkStatus()==0 && c[p-2][p-1+k].checkStatus()==1){
                c[p-1][p-1+k].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='c' && c[i+1][i+1+k].ch=='c' && c[i+3][i+3+k].ch=='c'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+1][p+2+k].checkStatus()==1 && c[p+2][p+2+k].checkStatus()==0){
                c[p+2][p+2+k].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='c' && c[i+2][i+2+k].ch=='c' && c[i+3][i+3+k].ch=='c'){
                p=i;
                b=true;break;
            }
        }
        if(b){
            if(c[p][p+1+k].checkStatus()==1 && c[p+1][p+1+k].checkStatus()==0){
                c[p+1][p+1+k].movecirclecomp();
                return true;
            }
        }
        k++;
    }

    k=-2;
    m=3;

    while(k<4){
        if(k<0) m--;
        else m=0;
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='c' && c[i+1][9-k-i].ch=='c' && c[i+2][8-k-i].ch=='c'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+3][7-k-p].checkStatus()==0 && c[p+2][7-k-p].checkStatus()==1){
                c[p+3][7-k-p].movecirclecomp();
                return true;
            }
            else if(c[p+3][7-k-p].checkStatus()==1 && c[p-1][11-k-p].checkStatus()==0 && c[p-2][11-k-p].checkStatus()==1){
                c[p-1][11-k-p].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='c' && c[i+1][9-k-i].ch=='c' && c[i+3][7-k-i].ch=='c'){
                p=i;
                b=true;break;
            }
        }
        if(b){
            if(c[p+1][8-k-p].checkStatus()==1 && c[p+2][8-k-p].checkStatus()==0){
                c[p+2][8-k-p].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='c' && c[i+2][8-k-i].ch=='c' && c[i+3][7-k-i].ch=='c'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p][9-k-p].checkStatus()==1 && c[p+1][9-k-p].checkStatus()==0){
                c[p+1][9-k-p].movecirclecomp();
                return true;
            }
        }
        k++;
    }
    return false;
}

bool block4(cell c[][11]){
    cout<<"block4"<<endl;
    int i,j,p,q,k=-2,m=3;
    bool b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+1].ch=='p' && c[i][j+2].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
        }
    if(b){
        if(!c[p][q+3].checkStatus() && c[p-1][q+3].checkStatus()){
            c[p][q+3].movecirclecomp();
                return true;
            }
        else if(c[p][q+3].checkStatus() && c[p][q-1].checkStatus()==0 && c[p-1][q-1].checkStatus()==1){
            c[p][q-1].movecirclecomp();
                return true;
            }
    }
    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+1].ch=='p' && c[i][j+3].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
            if(b) break;
    }
    if(b){
        if(c[p][q+2].checkStatus()==0 && c[p-1][q+2].checkStatus()==1){
            c[p][q+2].movecirclecomp();
                return true;
        }
    }
    b=false;
    for(i=2;i<8;i++){
        for(j=2;j<9;j++){
            if (c[i][j].ch=='p' && c[i][j+2].ch=='p' && c[i][j+3].ch=='p'){
               p=i; q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(c[p][q+1].checkStatus()==0 && c[p-1][q+1].checkStatus()==1){
            c[p][q+1].movecirclecomp();
                return true;
        }
    }
    b=false;
    for(i=2;i<9;i++){
        for(j=2;j<5;j++){
            if(c[j][i].ch=='p' && c[j+1][i].ch=='p' && c[j+2][i].ch=='p'){
                p=i;q=j;
                b=true; break;
            }
        }
        if(b) break;
    }
    if(b){
        if(c[q+3][p].checkStatus()==0){
            c[q+3][p].movecirclecomp();
                return true;
        }
    }
    //along diagonal

    while(k<4){
        if(k<0) m--;
        else m=0;
        b=false;
        for(i=2+m;i<8-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+1][i+1+k].ch=='p' && c[i+2][i+2+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+3][p+3+k].checkStatus()==0 && c[p+2][p+3+k].checkStatus()==1){
                c[p+3][p+3+k].movecirclecomp();
                return true;
            }
            else if(c[p+3][p+3+k].checkStatus()==1 && c[p-1][p-1+k].checkStatus()==0 && c[p-2][p-1+k].checkStatus()==1){
                c[p-1][p-1+k].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+1][i+1+k].ch=='p' && c[i+3][i+3+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+1][p+2+k].checkStatus()==1 && c[p+2][p+2+k].checkStatus()==0){
                c[p+2][p+2+k].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][i+k].ch=='p' && c[i+2][i+2+k].ch=='p' && c[i+3][i+3+k].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p][p+1+k].checkStatus()==1 && c[p+1][p+1+k].checkStatus()==0){
                c[p+1][p+1+k].movecirclecomp();
                return true;
            }
        }
        k++;
    }

    k=-2;
    m=2;

    while(k<4){
        if(k<0) m--;
        else m=0;
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+1][9-k-i].ch=='p' && c[i+2][8-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+3][7-k-p].checkStatus()==0 && c[p+2][7-k-p].checkStatus()==1){
                c[p+3][7-k-p].movecirclecomp();
                return true;
            }
        else if(c[p+3][7-k-p].checkStatus()==1 && c[p-1][11-k-p].checkStatus()==0 && c[p-2][11-k-p].checkStatus()==1){
            c[p-1][11-k-p].movecirclecomp();
            return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+1][9-k-i].ch=='p' && c[i+3][7-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p+1][8-k-p].checkStatus()==1 && c[p+2][8-k-p].checkStatus()==0){
                c[p+2][8-k-p].movecirclecomp();
                return true;
            }
        }
        b=false;
        for(i=2+m;i<7-k-2*m;i++){
            if(c[i][10-k-i].ch=='p' && c[i+2][8-k-i].ch=='p' && c[i+3][7-k-i].ch=='p'){
                p=i;
                b=true; break;
            }
        }
        if(b){
            if(c[p][9-k-p].checkStatus()==1 && c[p+1][9-k-p].checkStatus()==0){
                c[p+1][9-k-p].movecirclecomp();
                return true;
            }
        }
        k++;
    }
    return false;
}

void renewArray(char *ch,int length, char removed){
    for(int p=0;p<length;p++){
        if(ch[p]==removed){
            for(int q=p;q<length-1;q++){
                ch[q]=ch[q+1];
            }
            break;
        }
    }

}

bool block3(cell c[][11]){
    cout<<"block3"<<endl;
    int i,j;
    for(i=2;i<8;i++)
        for(j=2;j<9;j++){
        if(!c[i][j].checkStatus() && c[i-1][j].checkStatus()){
            int n=10;
            char ch[]={'a','b','c','d','e','f','g','h','i','j'};

            while(n>0){
                int a;
                char choice;
                a=rand()%n;
                choice=ch[a];

                switch(choice){
                    case 'a': if(c[i-1][j-1].ch=='p' && c[i-2][j-2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            for(int p=0;p<n-1;p++)
                                ch[p]=ch[p+1];
                            break;
                    case 'b': if(c[i+1][j-1].ch=='p' && c[i+2][j-2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'b');
                            break;
                    case 'c': if(c[i][j-1].ch=='p' && c[i][j-2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'c');
                            break;
                    case 'd': if(c[i][j+1].ch=='p' && c[i][j+2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'d');
                            break;
                    case 'e': if(c[i-1][j+1].ch=='p' && c[i-2][j+2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'e');
                            break;
                    case 'f': if(c[i+1][j+1].ch=='p' && c[i+2][j+2].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'f');
                            break;
                    case 'g': if(c[i-1][j-1].ch=='p' && c[i+1][j+1].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'g');
                            break;
                    case 'h': if(c[i+1][j-1].ch=='p' && c[i-1][j+1].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'h');
                            break;
                    case 'i': if(c[i][j-1].ch=='p' && c[i][j+1].ch=='p' && c[i-1][j].checkStatus()){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            renewArray(ch,n,'i');
                            break;
                    case 'j': if(c[i-1][j].ch=='p' && c[i-2][j].ch=='p'){
                                c[i][j].changeStatus();
                                if(isMake4(c))
                                    c[i][j].changeStatus();
                                else{
                                    c[i][j].movecirclecomp();
                                    return true;
                                }
                            }
                            break;
                }
                n--;
            }
        }
    }
    return false;
}

bool make3(cell c[][11]){
    cout<<"make3"<<endl;
	int i,j;
    for(i=2;i<8;i++)
            for(j=2;j<9;j++){
                if(c[i][j].checkStatus()==0 && c[i-1][j].checkStatus()==1){
                    if(isMake3(c,i,j) && isBlock3(c,i,j)){
                        c[i][j].changeStatus();
                        if(isMake4(c))
                            c[i][j].changeStatus();
                        else{
                            c[i][j].movecirclecomp();
                            return true;
                        }
                    }
                }
            }
    int n=10;
    char ch[]={'a','b','c','d','e','f','g','h','i','j'};

    for(i=2;i<8;i++)
        for(j=2;j<9;j++){
            if(c[i][j].checkStatus()==0 && c[i-1][j].checkStatus()==1){
                n=10;
                while(n>0){
                    int a;
                    char choice;
                    a=rand()%n;
                    choice=ch[a];

                    switch(choice){
                        case 'a': if(c[i-1][j-1].ch=='c' && c[i-2][j-2].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                for(int p=0;p<n-1;p++)
                                    ch[p]=ch[p+1];
                                break;
                        case 'b': if(c[i+1][j-1].ch=='c' && c[i+2][j-2].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'b');
                                break;
                        case 'c': if(c[i][j-1].ch=='c' && c[i][j-2].ch=='c'){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'c');
                                break;
                        case 'd': if(c[i][j+1].ch=='c' && c[i][j+2].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'d');
                                break;
                        case 'e': if(c[i-1][j+1].ch=='c' && c[i-2][j+2].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'e');
                                break;
                        case 'f': if(c[i+1][j+1].ch=='c' && c[i+2][j+2].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'f');
                                break;
                        case 'g': if(c[i-1][j-1].ch=='c' && c[i+1][j+1].ch=='c'){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'g');
                                break;
                        case 'h': if(c[i+1][j-1].ch=='c' && c[i-1][j+1].ch=='c'){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'h');
                                break;
                        case 'i': if(c[i][j-1].ch=='c' && c[i][j+1].ch=='c'){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                renewArray(ch,n,'i');
                                break;
                        case 'j': if(c[i-1][j].ch=='c' && c[i-2][j].ch=='c' ){
                                    c[i][j].changeStatus();
                                    if(isMake4(c))
                                        c[i][j].changeStatus();
                                    else{
                                        c[i][j].movecirclecomp();
                                        return true;
                                    }
                                }
                                break;
                    }
                n--;
            }
        }
    }
    return false;
}

bool make3medium(cell c[][11]){
    cout<<"make3"<<endl;
	int i,j;
    int n=10;
    char ch[]={'a','b','c','d','e','f','g','h','i','j'};

    for(i=2;i<8;i++)
        for(j=2;j<9;j++){
            if(c[i][j].checkStatus()==0 && c[i-1][j].checkStatus()==1){
                n=10;
                while(n>0){
                    int a;
                    char choice;
                    a=rand()%n;
                    choice=ch[a];

                    switch(choice){
                        case 'a': if(c[i-1][j-1].ch=='c' && c[i-2][j-2].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                for(int p=0;p<n-1;p++)
                                    ch[p]=ch[p+1];
                                break;
                        case 'b': if(c[i+1][j-1].ch=='c' && c[i+2][j-2].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'b');
                                break;
                        case 'c': if(c[i][j-1].ch=='c' && c[i][j-2].ch=='c'){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'c');
                                break;
                        case 'd': if(c[i][j+1].ch=='c' && c[i][j+2].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'d');
                                break;
                        case 'e': if(c[i-1][j+1].ch=='c' && c[i-2][j+2].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'e');
                                break;
                        case 'f': if(c[i+1][j+1].ch=='c' && c[i+2][j+2].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'f');
                                break;
                        case 'g': if(c[i-1][j-1].ch=='c' && c[i+1][j+1].ch=='c'){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'g');
                                break;
                        case 'h': if(c[i+1][j-1].ch=='c' && c[i-1][j+1].ch=='c'){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'h');
                                break;
                        case 'i': if(c[i][j-1].ch=='c' && c[i][j+1].ch=='c'){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                renewArray(ch,n,'i');
                                break;
                        case 'j': if(c[i-1][j].ch=='c' && c[i-2][j].ch=='c' ){
                                        c[i][j].movecirclecomp();
                                        return true;
                                }
                                break;
                    }
                n--;
            }
        }
    }
    return false;
}
