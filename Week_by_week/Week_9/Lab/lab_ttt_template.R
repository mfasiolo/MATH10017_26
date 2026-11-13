create_board <- function() {
 # TODO, create a 3 by 3 matrix full of "*"
}

get_elem <- function(board, i, j) {
  # TODO return element i, j of the board
}

set_elem <- function(board, i, j, value) {
  # TODO set element i, j of the board to "value" (either "0" of "X")
  # and return the updated board
}

print_board <- function(board) {
  # TODO print the board in a tidy format
}

is_playable <- function(board, i, j) {
  # TODO check if element i,j of the board is empty
}

pieces_at_row <- function(board, i, player) {
  # TODO: Count player's pieces at i-th row
}

pieces_at_col <- function(board, j, player) {
  # TODO: Count player's pieces at j-th column
}

pieces_at_diag <- function(board, player) {
  # TODO: Count player's pieces at diagonal line
}

pieces_at_anti_diag <- function(board, player) {
  # TODO: Count player's pieces at anti-diagonal line
}

play_move <- function(board, i, j, player) {
  if (is_playable(board, i, j)) {
    board <- set_elem(board, i, j, player)
  }
  board
}

evaluate_move <- function(board, i, j, player) {
  opponent <- if (player == "X") "O" else "X"
  f_ij <- 0L
  f_ij <- f_ij + pieces_at_row(board, i, player)
  f_ij <- f_ij - pieces_at_row(board, i, opponent)
  f_ij <- f_ij + pieces_at_col(board, j, player)
  f_ij <- f_ij - pieces_at_col(board, j, opponent)
  if (i == j) {
    f_ij <- f_ij + pieces_at_diag(board, player)
    f_ij <- f_ij - pieces_at_diag(board, opponent)
  }
  if (i + j == 4) { # since i,j now run from 1–3
    f_ij <- f_ij + pieces_at_anti_diag(board, player)
    f_ij <- f_ij - pieces_at_anti_diag(board, opponent)
  }
  return( f_ij )
}

ai_play <- function(board, player) {
  # TODO: It plays the next move for the "player",
  # Chooses the playable move (i,j) which is the maximizer of f(i,j)
  # Returns the updated board after playing the move
}

##### Testing the code

game <- create_board()

# TODO initialise the board to 
# X O * 
# * * * 
# * * *
# and then call ai_play(game, 'X') and ai_play(game, 'O') until someone wins!

