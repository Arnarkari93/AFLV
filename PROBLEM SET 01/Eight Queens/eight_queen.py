#!/usr/bin/python3

board[8][8]

for i in board:
	for j in board:
		board[i][j] = '.'

for i in board:
	for j in board:
		print(board[i][j])