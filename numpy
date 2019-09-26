import numpy as np

* Numpy array - from list, special functions
    * np.array(list)
* Array operations
    * np.array1 * np.array2, np.array1 / np.array2, 
    * np.array1 ** np.array2 - array1 raised to the power of array2
    * np.sin(np.array)
    * np.log(np.array) - natual logarithm
    * np.log10(np.array)
    * np.log2(np.array)
    * np.exp(np.array) - exponential
* 2-D arrays
    * np.ones
    * np.zeros
    * np.arange
    * np.linspace - linearly spaced numbers
    * np.array.ndim - no. of dimensions
    * np.array.size - no. of elements in the array
    * np.array.shape - shape of the array
    * np.array.dtype - datatype of elements in the array
    * np.eye - identity matrix
    * np.random.randint(low=1,high=10,size=(4,3,2)) - random matrix of shape (4,3,2), a 3D matrix
    * np.array.reshape - reshape array into any dimensions
    * np.array.ravel() - flatten the array into 1 dimension
* Indexing and slicing
    * mat = np.random.randint(10,100,15).reshape(3,5)
        * Element in row index 1 and column index 2 (double bracket indexing): mat[1][2]
        * Element in row index 1 and column index 2 (single bracket indexing): mat[1,2]
        * Entire row at index 2: mat[2]
        * Entire column at index 3: mat[:,3]
        * Matrix with row indices 1 and 2 and column indices 3 and 4: mat[1:3,3:5]
        * Matrix with row indices 0 and 1 and column indices 1 and 3: mat[0:2,[1,3]]
* Conditional subsetting
    * mat[mat>50]
    * mat*(mat>50)
* Array-array operations
    * mat1 + mat2, mat1 / mat2, mat1 * mat2
    * 3*mat1 - 2*mat2
    * 100 + mat1
    * mat1 ** 3
    * pow(mat1, 0.5)
* Basic linear algebra
    * transpose
        * mat1.T
    * rank
        * np.linalg.matrix_rank(mat)
    * dot
        * np.dot(vec1, vec2) = np.dot(vec2, vec1)
    * matrix multiplication
        * np.matmul(mat1, mat2)
        * np.dot(mat1, vec1)
    * inverse
        * np.linalg.inv(mat)
        * Note: Check if an inverse exists before doing this operation
    * singular value decomposition
        * u,s,v = np.linalg.svd(np.array, compute_uv=1, full_matrices=True)
        * s = singular values
        * reconstruction of np.array = u * diag(s) * v: np.dot(u,np.dot(np.diag(s),v))
    * eigenvalues and eigenvectors
        * w, v = np.linalg.eig(mat1)
        * w = eigen values
        * v = eigen vector
    * solving linear system of equations
        * 2𝑥+5𝑦+𝑧=14
        * 3𝑥−2𝑦−𝑧=−1
        * 𝑥−3𝑦+𝑧=4
        * A = np.array([[2,5,1],[3,-2,-1],[1,-3,1]]) - coefficient matrix
        * B = np.array([14,-1,4]) - constant vector
        * x = np.linalg.solve(A, B)
        * Also, x = np.matmul(np.linalg.inv(A),B)
    * covariance
        * np.cov(df[['Alcohol','Malic acid','Ash']],rowvar=False) (uses pandas dataframe)