int evaluate_position(char board[8][8]) {
    int white = 0, black = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            switch (board[i][j]) {
                case 'Q': white += 9; break;
                case 'R': white += 5; break;
                case 'B': white += 3; break;
                case 'N': white += 3; break;
                case 'p': white += 1; break;

                case 'q': black += 9; break;
                case 'r': black += 5; break;
                case 'b': black += 3; break;
                case 'n': black += 3; break;
                case 'p': black += 1; break;
            }
    return white - black;
}
