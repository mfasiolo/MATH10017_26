
## ---------- Subproblem: local argmax on [xt - eps, xt + eps] ----------

subproblem <- function(xt, epsilon) {
  x <- xt - epsilon
  fmax <- -Inf
  xmax <- x
  step <- epsilon / 100
  while (x <= xt + epsilon) {
    fx <- f(x)
    if (fx > fmax) {
      fmax <- fx
      xmax <- x
    }
    x <- x + step
  }
  xmax
}


## ---------- Hill climbing (greedy local search using subproblem) ----------

hill_climb <- function(epsilon, x0, tol = 1e-5) {
  xt   <- x0
  xt_1 <- -Inf  # previous iterate
  while (abs(xt - xt_1) >= tol) {
    xt_1 <- xt
    xt   <- subproblem(xt, epsilon)
    cat(sprintf("f(%.4f) = %.4f\n", xt, f(xt)))
  }
  cat(sprintf("Maximum is at %f with value %f\n", xt, f(xt)))
  xt
}


## ---------- Gradient ascent (maximize f using step along +grad) ----------

gradient_ascent <- function(epsilon, x0, tol = 1e-5) {
  xt   <- x0
  xt_1 <- -Inf
  while (abs(xt - xt_1) >= tol) {
    xt_1 <- xt
    xt   <- xt + epsilon * df(xt)
    cat(sprintf("f(%.4f) = %.4f\n", xt, f(xt)))
  }
  cat(sprintf("Maximum is at %f with value %f\n", xt, f(xt)))
  invisible(xt)
}


## Testing the algorithms

### 1st Problem 
f <- function(x)  sin(x / 2) + cos(x / 4)
df <- function(x) cos(x / 2) / 2 - sin(x / 4) / 4

# Hill climbing
hill_climb(epsilon = 0.5, x0 = -4)

# Gradient ascent
gradient_ascent(epsilon = 0.5, x0 = -4)

### 2nd Problem
f <- function(x)  -x * x
df <- function(x) -2 * x

# Hill climbing
hill_climb(epsilon = 0.2, x0 = -4)

# Gradient ascent
gradient_ascent(epsilon = 0.2, x0 = -4)