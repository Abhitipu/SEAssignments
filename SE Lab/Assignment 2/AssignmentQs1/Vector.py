# In this python file, only the definations for the magic functions and the basic operations
# for the question segments are provided. There may be the need to add new functions or overload 
# existing ones as per the question requirements.

class Vector:
        
    def __init__(self, *args): 

        # if arg is an int(dimension)
        if isinstance(args[0], int): 
            self._coords = [0]*args[0]

    def __len__(self):
        # return the dimension of the vector

    def __getitem__(self, j):
        # return the jth coordinate of the vector

    def __setitem__(self, j, val):
        # set the jth coordinate of vector to val

    def __add__(self, other):
        # u + v
            
    def __eq__(self, other):
        # return True if vector has same coordinates as other
    
    def __ne__(self, other):
        # return True if vector differs from other
    
    def __str__(self):
        # return the string representation of a vector within <>

    def __sub__(self, other):
        # Soln for Qs. 2
    
    def __neg__(self):
        # Soln for Qs. 3
    
    def __rmul__(self, value):
        return (self * value) 
    
    def __mul__(self, other):
        # Soln for Qs. 4, 5 and 6
    
def main():
    v1 = Vector(5)
    v2 = Vector (7)
    v3 = Vector([1,2,3,4,5])

    # Add suitable print statements to display the results
    # of the different question segments


if __name__ == '__main__':
    main()