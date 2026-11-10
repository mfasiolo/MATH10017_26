# swap two elements in an vector 
swap <- function(v, i, j){
  tmp <- v[i]
  v[i] <- v[j]
  v[j] <- tmp
  cat(sprintf("I am swapping %d with %d \n",  v[i], v[j]))
  return(v)
}

# find the index of the largest element in an vector
find_max_idx <- function(v){
  len <- length(v)
  idx <- 1
  max <- v[1]
  if (len >= 2) {
    for (i in 2:len){
      if(v[i] > max){
        max <- v[i]
        idx <- i
      }
    }
  }
  cat(sprintf("The largest element is %d \n", max))
  return(idx)
}


# sort an vector
sort <- function(v){
  len <- length(v)
  for (i in 1:(len-1)){
    max_idx <- find_max_idx(v[1:(len-i+1)]) 
    v <- swap(v, max_idx, len - i + 1)
    print(v)
  }
  return(v)
}

# recursive version
sort_v2 <- function(v){
  len <- length(v)
  max_idx <- find_max_idx(v) 
  v <- swap(v, max_idx, len)
  if(len > 1){ 
    v[1:(len-1)] <- sort_v2(v[1:(len-1)])
  }
  return(v)
}

# exchange sort: recursive version
sort_ex_rec <- function(v){
  len <- length(v)
  if(len <= 1){
    return(v)
  } 
  for (i in 1:len){ 
    if(v[i] > v[len]){
      v <- swap(v, i, len)
    }
  }
  v[1:(len-1)] <- sort_ex_rec(v[1:(len-1)])
  return(v)
}

# exchange sort: loop version
sort_ex_loop <- function(v){
  len <- length(v)
  for (m in len:2) {
    for (i in 1:(m-1)){
      if (v[i] > v[m]){ 
        v <- swap(v, i, m) 
      }
    }
  }
  return(v)
}

v <- c(5,3,2,4)
len <- 4

print("testing find_max_idx-----------------------")
# testing find_max_idx
max_idx <- find_max_idx(v)
cat(sprintf("max_idx: %d\n", max_idx))

cat("testing swap-----------------------\n")
#testing swap
v <- swap(v, 1, 2)
v

cat("testing sort-----------------------\n")
#test sort
a <- c(5, 3, 2, 1, 2, 4)
len <- 6
a <- sort(a)
a

b <- c(5, 3, 2, 1, 2, 4)
print("testing sort (recursive)-----------------------")
b <- sort_v2(b)
b

c <- c(5, 3, 2, 1, 2, 4)
print("testing exchange sort (loop)-----------------------")
c <- sort_ex_loop(c)
c

d <- c(5, 3, 2, 1, 2, 4)
print("testing exchange sort (recursive)-----------------------")
d <- sort_ex_rec(d)
d

print("Following the tutorial, sort and sort_v2 will take")
cat(sprintf("(n * (n-1))/2 = %d seconds for a vector of length n =  %d\n", (5*(5-1))/2, 5))
cat(sprintf("(n * (n-1))/2 = %d seconds for a vector of length n =  %d\n", (10*(10-1))/2, 10))
