# Report

Reversi is a zero-sum game in which the total amount of "payoff" is constant. In other words, any game situation is as good for player A as it is bad for player B, and vice versa.

A greedy algorithm will always choose the best move from current position ignoring the fact that subsequent moves can make the player loose. Hence we need to look forward. This is achieved by searching in a \textit{game tree} in which each board positions are organized. In a game tree, every node corresponds to a board position. The children of each node \textbf{N} are the different positions that result from a single move in \textbf{N}, made by the player whose turn it is at \textbf{N}. The root of the tree is the starting position, or the position from which we want to find a move. The leaves (nodes which have no children) in the game tree correspond to terminating positions; positions in which the game has ended.

The term minimax comes from the game theory idea of attempting to MINImize your MAXimum loss. Thus, when playing reversi a player using a minimax algorithm will choose the best possible move by assigning a value to each move based on all of the possible outcomes from every subsequent move, and choosing the move that either provides the most opportunities to win, or the least opportunities for the opponent to win.

Negamax is a slight simplification of minimax, and its code implementation is based on the principle that an opponent who is using a perfect strategy will be looking to make the inverse of a minimax move, thus their move will be the NEGAtive of your MAXimum move. 

Alpha-beta pruning is a way to speed up our search procedure that runs slightly more efficiently as instead of evaluating every single POSSIBLE move, it stops evaluating all subsequent moves after it has been found that a move is worse than a previous move.
For alpha-beta pruning(ABP) to work, the depth first search should have discovered a leaf node with a value which makes searching the current node irrelevant. If that does not happen, in the worst case, time wise, ABP will give results equivalent to minimax or negamax.
