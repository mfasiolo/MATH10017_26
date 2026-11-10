###############
# Basic solution
###############

start_time <- Sys.time()
n <- 5000

num_primes <- 0

for (i in 2:n){
  num_factors <- 0
  for (j in 1:i){
    if(i %% j == 0){
      num_factors <- num_factors + 1
    }
  }
  if (num_factors == 2){
    num_primes <- num_primes + 1
  }
}

print(num_primes)
end_time <- Sys.time()
end_time - start_time # <- This is the running time

# What it the time complexity? Approximate number of operations as a function of n.
# Try to comment out the if(i %% j == 0){ ... part
# The code is now much faster: this is the computational bottleneck
# The number of times we are running i %% j == 0 is n * (n + 1) / 2
# so the time complexity is O( n^2 )


###############
# Faster solution
###############

start_time <- Sys.time()
n <- 5000

num_primes <- 1 # Two is a prime
odds <- seq(3, n, by = 2)

# We need to search only among odd numbers
for (i in odds){
  prime <- TRUE
  # If we search between 2 and i-1 we can conclude that i is not 
  # a prime as soon as we find one factor
  for (j in 2:(i-1)){
    if(i %% j == 0){
       prime <- FALSE
       break
      }
    }
  if (prime){
    num_primes = num_primes + 1
  }
}

print(num_primes)
end_time <- Sys.time()
end_time - start_time


###############
# Even faster solution
###############

start_time <- Sys.time()
n <- 5000

num_primes <- 1 # Two is a prime
odds <- seq(3, n, by = 2)

# We need to search only among odd numbers
for (i in odds){
  prime <- TRUE
  # We only need to search for odd factors up to sqrt(i)
  # We do not look at even facts because we know that primes are odd 
  # (hence can't have even factors)
  for (j in odds[odds <= sqrt(i)]){
    if(i %% j == 0){
      prime <- FALSE
      break
    }
  }
  if (prime){
    num_primes = num_primes + 1
  }
}

print(num_primes)
end_time <- Sys.time()
end_time - start_time
