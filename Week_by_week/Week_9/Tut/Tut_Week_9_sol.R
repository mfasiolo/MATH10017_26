library(imager)

# load the image
img <- load.image("UoB.jpg")
img <- grayscale(img)

# plotting the image
plot(img, axes=FALSE)

# convert the image to a matrix
M <- as.matrix(img)
n <- nrow(M)
m <- ncol(M)

# print out the size of the matrix, in terms of bytes
size1 <- n * m * 8
print(paste("size:", size1, "bytes"))

# compare with
object.size(M) # close enough!

# perform SVD
UDVT <- svd(M)
U <- UDVT$u
D <- diag(UDVT$d)
V <- UDVT$v

# check the SVD correctness using Frobenious norm
sqrt( sum( (M - U%*%D%*%t(V))^2 ) )

# or equivalently
norm(M - U%*%D%*%t(V), type = "F")

# reconstruct the image using truncated SVD results
r1 <- 100
U2 <- U[ , 1:r1]
D2 <- D[1:r1, 1:r1]
V2 <- V[ , 1:r1]
m_2 <- U2%*%D2%*%t(V2)

# plot the compressed image
plot(as.cimg(m_2), axes=FALSE)

# compute the size of matrices required for reconstructing the image
size2 <- (n*r1 + r1 + m*r1)*8
print(paste("size:", size2, "bytes"))

print(paste("compression rate: ", size1/size2))

# the compression loss
norm(M - U2%*%D2%*%t(V2), type = "F")

###### Compression rate and approx error vs r1

svd_compress <- function(U, V, D, r1){
  U2 <- U[ , 1:r1, drop = FALSE]
  D2 <- D[1:r1, 1:r1, drop = FALSE]
  V2 <- V[ , 1:r1, drop = FALSE]
  return( U2 %*% D2 %*% t(V2) )
}

# You can do r1_seq <- 1:200 to get something quicker!
r1_seq <- 1:m

nr1 <- length(r1_seq)
com_rate <- err_rate <- numeric(nr1)
for(ii in 1:nr1){
  cat(".")
  if(!(ii %% 100)){ cat("\n") }
  r1 <- r1_seq[ii]
  M_2 <- svd_compress(U, V, D, r1)
  size_2 <- (n*r1 + r1 + m*r1)*8
  com_rate[ii] <- size1 / size_2
  err_rate[ii] <- sum((M - M_2)^2) / sum(M^2)
}

par(mfrow = c(2, 1))
plot(r1_seq, com_rate, type = 'l')
plot(r1_seq, err_rate, type = 'l')

# Compute size for each r1
size_seq <- size1 / com_rate 

r_100Kb <- r1_seq[size_seq < 1e5] # 1e5 is 100 KBytes

max(r_100Kb) # This is the maximal r1 we can use to use less that 100 KBytes

# We can check it by doing 
object.size(U[ , 1:max(r_100Kb)]) + object.size(V[ , 1:max(r_100Kb)]) + 
object.size(UDVT$d[ 1:max(r_100Kb)]) 
# Just below 100 KBytes

# Compare cumulative sum of singular value with relative error

d_err <- rev(cumsum( rev(UDVT$d^2) ))[2:(nr1+1)] / sum(UDVT$d^2)

par(mfrow = c(1, 1))
plot(err_rate, d_err)
abline(0, 1, col = 2)
# They are the same: the sum of squared singular values quantify the 
# approximation error!

