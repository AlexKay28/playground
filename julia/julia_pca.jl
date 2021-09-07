using mlpack

size = 10

X_old = rand(size, size)
X_new = mlpack.pca(X_old, new_dimensionality=size)

print("X_old:\n", X_old, "\n")
print("X_new:\n", X_new, "\n")

