# This is the function we want to maximise; feel free to experiment with a 
# different function if you want.
f <- function(x) {
  return( sin(x/2) + cos(x/4) )
}

# Returns the x that maximizes f(x) in [xt - epsilon, xt + epsilon]
subproblem <- function(xt, epsilon) {
  x <- xt - epsilon
  fmax <- -Inf
  xmax <- x
  
  while (x <= xt + epsilon) {
    val <- f(x)
    if (val > fmax) {
      fmax <- val
      xmax <- x
    }
    x <- x + epsilon/100
  }
  
  return(xmax)
}

# Vectorised version
subproblem_vett <- function(xt, epsilon) {
  xseq <- seq(xt - epsilon, xt + epsilon, by = epsilon/100)
  
  fseq <- f(xseq)
  
  xmax <- xseq[ which.max(fseq) ]

  return(xmax)
}

# Testing hill-climbing 
epsilon <- 0.5
x0 <- -4

xt <- x0
xt_1 <- 100  # previous iterate

while (abs(xt - xt_1) >= 1e-5) {
  xt_1 <- xt
  xt <- subproblem(xt, epsilon)
  cat(sprintf("f(%.4f) = %.4f\n", xt, f(xt)))
}

cat(sprintf("Maximum is at %f with value %f\n", xt, f(xt)))

# Testing vectorized version
xt <- x0
xt_1 <- 100  # previous iterate

while (abs(xt - xt_1) >= 1e-5) {
  xt_1 <- xt
  xt <- subproblem_vett(xt, epsilon)
  cat(sprintf("f(%.4f) = %.4f\n", xt, f(xt)))
}

cat(sprintf("Maximum is at %f with value %f\n", xt, f(xt)))