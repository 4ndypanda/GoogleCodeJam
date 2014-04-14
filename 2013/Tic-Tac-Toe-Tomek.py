def win(count, player):
    return count[player] == 4 or count[player] == 3 and count['T'] == 1

def state(board):
    draw = True
    diag1 = {'X': 0, 'O': 0, 'T': 0, '.': 0}
    diag2 = {'X': 0, 'O': 0, 'T': 0, '.': 0}
    for i in range(4):
        row = {'X': 0, 'O': 0, 'T': 0, '.': 0}
        col = {'X': 0, 'O': 0, 'T': 0, '.': 0}
        for j in range(4):
            row[board[i][j]] += 1
            col[board[j][i]] += 1
            if board[i][j] == '.' or board[j][i] == '.':
                draw = False                
        diag1[board[i][i]] += 1
        diag2[board[i][3 - i]] += 1
        if win(row, 'X') or win(col, 'X'):
            return "X won"
        if win(row, 'O') or win(col, 'O'):
            return "O won"
    if win(diag1, 'X') or win(diag2, 'X'):
        return "X won"
    if win(diag1, 'O') or win(diag2, 'O'):
        return "O won"
    return "Draw" if draw else "Game has not completed"

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        board = []
        for i in range(4):
            board.append(raw_input())
        print "Case #{}: {}".format(t, state(board))
        raw_input()
    
if __name__ == "__main__":
    main()