# N-Triangular-Queens
Maximum amount of non attacking queens placed on a triangular board of size. Solution printed. Solved in C using the backtracking algorithm.
N is the length of any side of a triangular chess-like board, or its height;
Example of a placed queen in N=6 size board:<br> ![image](https://user-images.githubusercontent.com/118682717/227608857-0171ba98-ca8a-4773-accb-2a13f5e8fa81.png)
<br>
Rearranged board visualization. Instead of attacking the same row and diagonally both ways the queen can attack the same column, row, and diagonal from top left to bottom right. This is done to simplify the use of two-dimensional array.<br> ![image](https://user-images.githubusercontent.com/118682717/227611920-7358fcda-47c8-488f-a4e1-fc74642ecb14.png)

Notes:<br>
-Whole code is in a single file for simplicity sakes <br>
-This algorithm is in need of optimization in order to run faster with larger numbers (since this algorithm has exponential time complexity).<br>
