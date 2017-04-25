#include<simplecpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>

//returns a pair <direction, coordinate> where direction is North, Northeast, etc (clockwise)
//and coordinate is in the form x*8 + y
std::vector< std::pair<int, int> > get_directions(int board[][8], int x, int y, int color) {
    std::vector< std::pair<int, int> > directions;
    if(board[x][y]) {
        return directions;
    }
    //north
    if((y < 6) && (board[x][y+1] == -color)) {
        for(int i=y+2; i < 8; i++) {
            if(!board[x][i]) {
                break;
            } else if(board[x][i] == color) {
                directions.push_back(std::make_pair<int, int>(0, x*8+i));
                break;
            }
        }
    }
    //northeast
    if((y < 6) && (x < 6) && (board[x+1][y+1] == -color)) {
        for(int i=0; (x+i+2 < 8) && (y+i+2 < 8); i++) {
            if(!board[x+i+2][y+i+2]) {
                break;
            } else if(board[x+i+2][y+i+2] == color) {
                directions.push_back(std::make_pair<int, int>(1, (x+i+2)*8+(y+i+2)));
                break;
            }
        }
    }
    //east
    if((x < 6) && (board[x+1][y] == -color)) {
        for(int i=x+2; i < 8; i++) {
            if(!board[i][y]) {
                break;
            } else if(board[i][y] == color) {
                directions.push_back(std::make_pair<int, int>(2, i*8+y));
                break;
            }
        }
    }
    //southeast
    if((y > 1) && (x < 6) && (board[x+1][y-1] == -color)) {
        for(int i=0; (x+i+2 < 8) && (y-i-2 >= 0); i++) {
            if(!board[x+i+2][y-i-2]) {
                break;
            } else if(board[x+i+2][y-i-2] == color) {
                directions.push_back(std::make_pair<int, int>(3, (x+i+2)*8+(y-i-2)));
                break;
            }
        }
    }
    //south
    if((y > 1) && (board[x][y-1] == -color)) {
        for(int i=y-2; i >= 0; i--) {
            if(!board[x][i]) {
                break;
            } else if(board[x][i] == color) {
                directions.push_back(std::make_pair<int, int>(4, x*8+i));
                break;
            }
        }
    }
    //southwest
    if((y > 1) && (x > 1) && (board[x-1][y-1] == -color)) {
        for(int i=0; (x-i-2 >= 0) && (y-i-2 >= 0); i++) {
            if(!board[x-i-2][y-i-2]) {
                break;
            } else if(board[x-i-2][y-i-2] == color) {
                directions.push_back(std::make_pair<int, int>(5, (x-i-2)*8+(y-i-2)));
                break;
            }
        }
    }
    //west
    if((x > 1) && (board[x-1][y] == -color)) {
        for(int i=x-2; i >= 0; i--) {
            if(!board[i][y]) {
                break;
            } else if(board[i][y] == color) {
                directions.push_back(std::make_pair<int, int>(6, i*8+y));
                break;
            }
        }
    }
    //northwest
    if((y < 6) && (x > 1) && (board[x-1][y+1] == -color)) {
        for(int i=0; (x-i-2 >= 0) && (y+i+2 < 8); i++) {
            if(!board[x-i-2][y+i+2]) {
                break;
            } else if(board[x-i-2][y+i+2] == color) {
                directions.push_back(std::make_pair<int, int>(7, (x-i-2)*8+(y+i+2)));
                break;
            }
        }
    }
    return directions;
}

//returns all moves for a players on the current board. Each pair has a coordinate in the form
//x*8+y, and a vector of pairs, each pair contains a direction and an endpoint in the form x*8+y
std::vector< std::pair<int, std::vector< std::pair<int, int> > > > get_moves(int board[][8], int color) {
    std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves;
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            //if cell is already full then break here
            moves.push_back(std::make_pair<int, std::vector< std::pair<int, int> > >(i*8+j, get_directions(board, i, j, color)));
            if(!moves.back().second.size()) {
                moves.pop_back();
            }
        }
    }
    return moves;
}

//makes a move and flips the appropriate pieces
void make_move(int board[][8], int x, int y, int color, std::vector< std::pair<int, int> > directions) {
    for(auto it=directions.begin(); it != directions.end(); it++) {
        int i = x;
        int j = y;
        while((i != ((*it).second/8)) || (j != ((*it).second&7))) {
            board[i][j] = color;
            if(i < ((*it).second/8)) {
                i++;
            } else if((i > (*it).second/8)) {
                i--;
            }
            if(j < ((*it).second&7)) {
                j++;
            } else if(j > ((*it).second&7)) {
                j--;
            }
        }
    }
}

void make_move2(int board[][8], int x, int y, int color, std::vector< std::pair<int, int> > directions) {
    for(auto it=directions.begin(); it != directions.end(); it++) {
        int i = x;
        int j = y;
        while((i != ((*it).second/8)) || (j != ((*it).second&7))) {
            board[i][j] = color;
            Circle c(85+90*i,715-90*j, 35);
            c.setFill(true);
            if(color == -1)
                c.setColor(COLOR(240,240,225));
            else if(color == 1)
                c.setColor(COLOR(0,0,0));
            c.imprint();
            if(i < ((*it).second/8)) {
                i++;
            } else if((i > (*it).second/8)) {
                i--;
            }
            if(j < ((*it).second&7)) {
                j++;
            } else if(j > ((*it).second&7)) {
                j--;
            }
        }
    }
}

//undoes a move (needs directions data so it can unflip stuff)
void undo_move(int board[][8], int x, int y, int color, std::vector< std::pair<int, int> > directions) {
    for(auto it=directions.begin(); it != directions.end(); it++) {
        int i = x;
        int j = y;
        while((i != ((*it).second/8)) || (j != ((*it).second&7))) {
            board[i][j] = -color;
            if(i < ((*it).second/8)) {
                i++;
            } else if((i > (*it).second/8)) {
                i--;
            }
            if(j < ((*it).second&7)) {
                j++;
            } else if(j > ((*it).second&7)) {
                j--;
            }
        }
        board[i][j] = color;
    }
    board[x][y] = 0;
}

int score(int board[][8], int color) {
    int sum = 0;
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            sum += board[i][j];
        }
    }
    return sum * color;
}

//Largely the same pseudocode from the negamax wikipedia article, but adapted for the rules of othello
int negamax_aux(int board[][8], int color, int depth, int alpha, int beta) {
    if(depth == 0) {
        return score(board, color);
    }
    std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves = get_moves(board, color);
    if(moves.size() == 0) {
        if(get_moves(board, -color).size() == 0) {
            return score(board, color);
        }
        int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
        if(val >= beta) {
            return val;
        }
        if(val > alpha) {
            alpha = val;
        }
    } else {
        for(auto it=moves.begin(); it != moves.end(); it++) {
            make_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
            int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
            undo_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
            if(val >= beta) {
                return val;
            }
            if(val > alpha) {
                alpha = val;
            }
        }
    }
    return alpha;
}

//parent function to negamax_aux, this function actually maintains the current best move
int negamax(int board[][8], int color, int depth) {
    int alpha = -65;
    int beta = 65;
    std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves = get_moves(board, color);
    int move = moves[0].first;
    for(auto it=moves.begin(); it != moves.end(); it++) {
        make_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
        int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
        undo_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
        if(val >= beta) {
            return (*it).first;
        }
        if(val > alpha) {
            alpha = val;
            move = (*it).first;
        }
    }
    return move;
}

int index_y(int a){
   if(a>=40&&a<130)
        return 7;
    if(a>=130&&a<220)
        return 6;
    if(a>=220&&a<310)
        return 5;
    if(a>=310&&a<400)
        return 4;
    if(a>=400&&a<490)
        return 3;
    if(a>=490&&a<580)
        return 2;
    if(a>=580&&a<670)
        return 1;
    if(a>=670&&a<760)
        return 0;
}

int index_x(int a){
   if(a>=40&&a<130)
        return 0;
    if(a>=130&&a<220)
        return 1;
    if(a>=220&&a<310)
        return 2;
    if(a>=310&&a<400)
        return 3;
    if(a>=400&&a<490)
        return 4;
    if(a>=490&&a<580)
        return 5;
    if(a>=580&&a<670)
        return 6;
    if(a>=670&&a<760)
        return 7;
}

//run with ./othello [int] where int is the depth that AI searches. Default is 3 ply.
int main() {
    initCanvas("Othello", 1100,800);
    Rectangle border(400,400,720,720);
    border.setFill(true); border.setColor(COLOR(0,80,0)); border.imprint(); border.hide();
    Line V1(130,40,130,760), H1(40,130,760,130);
    Line V2(220,40,220,760), H2(40,220,760,220);
    Line V3(310,40,310,760), H3(40,310,760,310);
    Line V4(400,40,400,760), H4(40,400,760,400);
    Line V5(490,40,490,760), H5(40,490,760,490);
    Line V6(580,40,580,760), H6(40,580,760,580);
    Line V7(670,40,670,760), H7(40,670,760,670);

    Circle c33(85+90*3,715-90*3, 35);
    c33.setFill(true); c33.setColor(COLOR(240,240,225)); c33.imprint(); c33.hide();
    Circle c34(85+90*3,715-90*4, 35);
    c34.setFill(true); c34.setColor(COLOR(0,0,0)); c34.imprint(); c34.hide();
    Circle c43(85+90*4,715-90*3, 35);
    c43.setFill(true); c43.setColor(COLOR(0,0,0)); c43.imprint(); c43.hide();
    Circle c44(85+90*4,715-90*4, 35);
    c44.setFill(true); c44.setColor(COLOR(240,240,225)); c44.imprint(); c44.hide();

    int depth = 3;

    int board[8][8];
    memset(board, 0, sizeof(board));
    board[3][3] = board[4][4] = -1;
    board[3][4] = board[4][3] = 1;
    int turn = -1;
    while(true) {
        std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves= get_moves(board, turn);
        if(moves.size() == 0) {
            turn = -turn;
            moves = get_moves(board, turn);
            if(moves.size() == 0) {
                int result = score(board,-1);
                if(result>0){
                    Text Result(950, 500, "YOU WON!!");
                    Result.imprint();
                }
                else if(result < 0){
                    Text Result(950,500, "I BEAT YOU!!");
                    Result.imprint();
                }
                else{
                    Text Result(950,500, "IT'S A DRAW!!");
                    Result.imprint();
                }
                Text Final(950,380,"Final Score:");
                Text Score(950,420, score(board,-1));
                Final.imprint();
                Score.imprint();
                wait(3);
                return 0;
            }
        } else {
            int x, y;
            if(turn == -1) {
                int a = getClick();
                x = index_x(a/65536), y = index_y(a%65536);

                for(auto it=moves.begin(); it != moves.end(); it++) {
                    if(x*8+y == ((*it).first)) {
                        make_move2(board, x, y, turn, (*it).second);
                        turn = -turn;
                        break;
                    }
                }
            } else {
                x = negamax(board, turn, depth);
                for(auto it=moves.begin(); it != moves.end(); it++) {
                    if(x == ((*it).first)) {
                        make_move2(board, x/8, x%8, turn, (*it).second);
                        turn = -turn;
                        break;
                    }
                }
            }
        }
        Text Final(950,380,"Score:");
        Final.imprint();
        Text Score(950,420, score(board,-1));
        wait(1);
    }
    return 0;
}
