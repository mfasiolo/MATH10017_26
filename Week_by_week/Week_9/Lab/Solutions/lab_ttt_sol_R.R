create_board <- function(nrow = 3, ncol = 3) {
  matrix(rep("*", nrow * ncol), nrow = nrow, ncol = ncol)
}

get_elem <- function(board, i, j) {
  if (i < 1 || i > nrow(board) || j < 1 || j > ncol(board)) {
    cat("invalid indices!\n")
    return("N")
  }
  return( board[i, j] )
}

set_elem <- function(board, i, j, value) {
  if (i < 1 || i > nrow(board) || j < 1 || j > ncol(board)) {
    cat("invalid indices!\n")
    return(board)
  }
  board[i, j] <- value
  return( board )
}

print_board <- function(board) {
  for (i in 1:nrow(board)) {
    for (j in 1:ncol(board)) {
      cat(board[i, j], " ")
    }
    cat("\n")
  }
}

##### Game logic helpers #####

is_playable <- function(board, i, j) {
  get_elem(board, i, j) == "*"
}

pieces_at_row <- function(board, i, player) {
  sum(board[i, ] == player)
}

pieces_at_col <- function(board, j, player) {
  sum(board[, j] == player)
}

pieces_at_diag <- function(board, player) {
  sum(diag(board) == player)
}

pieces_at_anti_diag <- function(board, player) {
  sum(diag(board[ , ncol(board):1]) == player)
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

play_move <- function(board, i, j, player) {
  if (is_playable(board, i, j)) {
    board <- set_elem(board, i, j, player)
  }
  return( board )
}

ai_play <- function(board, player) {
  i_max <- 1L; j_max <- 1L; max_score <- -Inf
  for (i in 1:3) {
    for (j in 1:3) {
      if (is_playable(board, i, j)) {
        s <- evaluate_move(board, i, j, player)
        if (s > max_score) {
          max_score <- s
          i_max <- i
          j_max <- j
        }
      }
    }
  }
  play_move(board, i_max, j_max, player)
}

##### Demo (main) #####

game <- create_board()

game <- play_move(game, 1, 1, "X")
game <- play_move(game, 1, 2, "O")
print_board(game)

cat("AI plays...\n")
game <- ai_play(game, "X"); print_board(game)

cat("AI plays...\n")
game <- ai_play(game, "O"); print_board(game)

cat("AI plays...\n")
game <- ai_play(game, "X"); print_board(game)

cat("AI plays...\n")
game <- ai_play(game, "O"); print_board(game)

cat("AI plays...\n")
game <- ai_play(game, "X"); print_board(game)