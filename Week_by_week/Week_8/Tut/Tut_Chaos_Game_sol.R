
######### Solution: The Chaos Game and Vectorisation

######### Step 1: the corners
# Row k holds the (x, y) coordinates of corner k
V <- matrix(c(0,   0,            # corner 1
              1,   0,            # corner 2
              0.5, sqrt(3)/2),   # corner 3
            nrow = 3, ncol = 2, byrow = TRUE)

plot(V[, 1], V[, 2], xlab = "x", ylab = "y")


######### Step 2: a first (slow) version
# Q1: complete chaos_slow and check we obtain the Sierpinski triangle
chaos_slow <- function(n){
  x <- 0.5; y <- 0.25
  xs <- c(); ys <- c()          # empty results
  for(i in 1:n){
    u <- runif(1)
    k <- as.integer(u * 3) + 1  # corner 1, 2, 3
    x <- (x + V[k, 1]) / 2      # move half-way to corner k
    y <- (y + V[k, 2]) / 2
    xs <- c(xs, x)              # grow one element
    ys <- c(ys, y)             # at a time -- slow!
  }
  return(cbind(xs, ys))
}

pts <- chaos_slow(3e4)
plot(pts[, 1], pts[, 2], pch = ".")   # the Sierpinski triangle appears

# Q2: pch = "." is far better than the default for 30 000 points:
#     the default circles overlap into a black blob, hiding the fractal holes.
plot(pts[, 1], pts[, 2])              # default: a smudge
plot(pts[, 1], pts[, 2], pch = ".")   # dots: the structure is visible




######### Step 3: how fast is it?
for(n in c(2000, 20000, 100000)){
  tic <- Sys.time()
  chaos_slow(n)
  print( Sys.time() - tic )
}

# Q3: multiplying n by 10 multiplies the time by MUCH more than 10
#     (closer to 100), because the cost grows like n^2, not like n.
# Q4: almost all the time goes into "xs <- c(xs, x)": each step R builds a
#     brand-new, longer vector and copies everything across. The actual
#     arithmetic is trivial; the copying dominates.


######### Fix 1: pre-allocate the storage
chaos_prealloc <- function(n){
  x <- 0.5; y <- 0.25
  pts <- matrix(0, nrow = n, ncol = 2)  # allocate now, once
  for(i in 1:n){
    u <- runif(1)
    k <- as.integer(u * 3) + 1
    x <- (x + V[k, 1]) / 2
    y <- (y + V[k, 2]) / 2
    pts[i, ] <- c(x, y)                 # fill an existing row (no copying!)
  }
  return(pts)
}

# Q5: time chaos_prealloc against chaos_slow at n = 1e5
n <- 1e5

tic <- Sys.time(); tmp <- chaos_slow(n);     print( Sys.time() - tic )
tic <- Sys.time(); tmp <- chaos_prealloc(n); print( Sys.time() - tic )
# Pre-allocation alone gives a huge speed-up (often 100x or more):
# the n^2 copying is gone, so the cost now grows only like n.


######### Fix 2: vectorise the randomness
# Make ALL the corner choices in one runif() call, before the loop
choices <- as.integer(runif(6) * 3) + 1   # 6 draws
choices
V[choices, ]                              # one row per chosen corner

# Q6: complete chaos_fast and check it still draws the triangle
chaos_fast <- function(n){
  choices <- as.integer(runif(n) * 3) + 1  # all picks, one call
  Vc <- V[choices, ]                       # all corners, no loop

  pts <- matrix(0, n, 2)                    # pre-allocated (Fix 1)
  x <- 0.5; y <- 0.25
  for(i in 1:n){
    x <- (x + Vc[i, 1]) / 2                 # use Vc[i, ] in place of V[k, ]
    y <- (y + Vc[i, 2]) / 2
    pts[i, ] <- c(x, y)
  }
  return(pts)
}

pts <- chaos_fast(3e4)
plot(pts[, 1], pts[, 2], pch = ".")        # still the Sierpinski triangle

# Q7: time all three versions at n = 1e5
n <- 1e5

tic <- Sys.time(); tmp <- chaos_slow(n);     t_slow     <- Sys.time() - tic
tic <- Sys.time(); tmp <- chaos_prealloc(n); t_prealloc <- Sys.time() - tic
tic <- Sys.time(); tmp <- chaos_fast(n);     t_fast     <- Sys.time() - tic

# A small table of timings (numbers vary by machine)
timings <- data.frame(
  version = c("chaos_slow", "chaos_prealloc", "chaos_fast"),
  seconds = c(as.numeric(t_slow, units = "secs"),
              as.numeric(t_prealloc, units = "secs"),
              as.numeric(t_fast, units = "secs"))
)
print(timings)
# slow >> prealloc > fast : pre-allocation removes the n^2 cost,
# and vectorising runif removes the per-call overhead of n draws.


######### Step 4: a fully vectorised measurement (no loop)
pts <- chaos_fast(1e5)

# Q8: how many points have x-coordinate less than 0.5
sum(pts[, 1] < 0.5)

# Q9: distance from every point to corner 1, at the origin (0, 0)
dist_to_corner1 <- sqrt(pts[, 1]^2 + pts[, 2]^2)
head(dist_to_corner1)


######### Challenge

# Q10: a different ratio.  x <- x + ratio * (V[k,1] - x)
chaos_ratio <- function(n, ratio){
  choices <- as.integer(runif(n) * 3) + 1
  Vc <- V[choices, ]
  pts <- matrix(0, n, 2)
  x <- 0.5; y <- 0.25
  for(i in 1:n){
    x <- x + ratio * (Vc[i, 1] - x)
    y <- y + ratio * (Vc[i, 2] - y)
    pts[i, ] <- c(x, y)
  }
  return(pts)
}

par(mfrow = c(1, 2))
p04 <- chaos_ratio(3e4, ratio = 0.4)
plot(p04[, 1], p04[, 2], pch = ".", main = "ratio = 0.4")
p06 <- chaos_ratio(3e4, ratio = 0.6)
plot(p06[, 1], p06[, 2], pch = ".", main = "ratio = 0.6")
par(mfrow = c(1, 1))
# ratio = 0.5 gives the classic Sierpinski triangle.
# ratio = 0.4 (jumps shorter) pulls the points inward: the copies overlap
#   and the crisp fractal holes are lost. 
# ratio = 0.6 (jumps longer) pushes points outward: the three copies
#   shrink, leave gaps, and no longer tile the triangle cleanly.

# Q11: four corners of a square, pick one of four at random
Vsq <- matrix(c(0, 0,
                1, 0,
                1, 1,
                0, 1), nrow = 4, ncol = 2, byrow = TRUE)

chaos_square <- function(n){
  choices <- as.integer(runif(n) * 4) + 1   # one of four corners
  Vc <- Vsq[choices, ]
  pts <- matrix(0, n, 2)
  x <- 0.5; y <- 0.5
  for(i in 1:n){
    x <- (x + Vc[i, 1]) / 2
    y <- (y + Vc[i, 2]) / 2
    # Change to 1/3 to see a Sierpinski carpet appear:
    # x <- x * 1/3 + Vc[i, 1] * 2/3
    # y <- y * 1/3 + Vc[i, 2] * 2/3
    pts[i, ] <- c(x, y)
  }
  return(pts)
}

psq <- chaos_square(3e4)
plot(psq[, 1], psq[, 2], pch = ".")
# With ratio 1/2 the square just fills up uniformly -- NO fractal appears,
# because half-way jumps to four corners can reach every point in the square.
# (A Sierpinski carpet needs a different rule, e.g. a ratio of 1/3.)

# Q12: colour each point by the corner it jumped to
chaos_fast_col <- function(n){
  choices <- as.integer(runif(n) * 3) + 1
  Vc <- V[choices, ]
  pts <- matrix(0, n, 2)
  x <- 0.5; y <- 0.25
  for(i in 1:n){
    x <- (x + Vc[i, 1]) / 2
    y <- (y + Vc[i, 2]) / 2
    pts[i, ] <- c(x, y)
  }
  return(list(pts = pts, choices = choices))
}

res <- chaos_fast_col(3e4)
plot(res$pts[, 1], res$pts[, 2], pch = ".", col = res$choices)
# Each of the three sub-triangles is dominated by one colour: the corner
# you last jumped to tells you which third of the picture you land in.
