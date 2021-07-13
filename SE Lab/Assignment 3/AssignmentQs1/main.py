# Abhinandan De
# 19CS10069

class Vector:
    def __init__(self, *args):
        if isinstance(args[0], int):        # checks if args[0] is of type int or not!
            self._coords = [0] * args[0]    # array of args[0] integers
        else:
            self._coords = args[0]          # basically sets the whole list!

    def __len__(self):
        return len(self._coords)            # returns the length of the list of coordinates

    def match(self, other):
        return len(self) == len(other)

    def okRange(self, j):                   # checks if index is in the specified range
        if j in range(0, len(self)):
            return True
        return False

    def __getitem__(self, j):               # returns an item at a particular index
        if self.okRange(j):
            return self._coords[j]
        else:
            self.rangeErr()

    def __setitem__(self, j, val):          # sets an item at a particular index
        if self.okRange(j):
            self._coords[j] = val
        else:
            self.rangeErr()

    def rangeErr(self):
        print("The index is out of range!")

    def dimErr(self):
        print("Cant perform the operation as dimensions of the vectors don't match!")

    def __add__(self, other):               # adds one vector to another and returns a new instance of the newly created vector
        if self.match(other):
            temp = []
            for i in range(len(self)):
                temp.append(self[i] + other[i])
            return Vector(temp)
        else:
            self.dimErr()

    def __eq__(self, other):                # checks for equality of two vectors
        if self.match(other):
            for i in range(len(self)):
                if self[i] != other[i]:
                    return False
            return True
        else:
            return False

    def __ne__(self, other):                            # returns True if vectors aren't equal
        return not self.__eq__(other)

    def __str__(self):                                  # returns a string form of the current vector
        s = "<"
        for i in range(len(self)-1):
            s += (str(self[i]) + ", ")
        s += (str(self[i]) + ">")
        return s

    def __sub__(self, other):                           # returns a new instance of a vector u - v
        temp = other.__neg__()
        temp = self.__add__(temp)
        return Vector(temp)

    def __neg__(self):                                  # negative of a given vector
        return self.__rmul__(-1)

    def __rmul__(self, value):                          # returns a new instance of a vector which is a scalar multiplication of the existing vector with value
        temp = []
        for i in range(len(self)):
            temp.append(value * self[i])
        return Vector(temp)

    def __mul__(self, other):                           # u.v (dot product of two vectors)
        if isinstance(other, int):
            return self.__rmul__(other)
        else:
            if self.match(other):
                res = 0
                for i in range(len(self)):
                    res += (self[i] * other[i])
                return res
            else:
                self.dimErr()


def main():

    v1 = Vector([3, 6, 7, 4, 5])
    v2 = Vector(7)
    v2[1] = -2
    v2[4] = -6
    v2[3] = 4
    v3 = Vector([1, 2, 3, 4, 5])
    v4 = Vector([0, 0, 0, 0, 0])
    print(v1)
    print(v2)
    print(v3)
    print(len(v1))
    print(v2 != v4)
    print(v1 + v3)
    print(v1 - v3)
    print(v3)
    print(-v3)
    print(v3 * 3)
    print(3 * v3)
    print(v1 * v3)
    print(v1[0])
    v1[0] = 10
    print(v1[0])

    # Some erroneous fragments
    v2[9] = 6
    print(v1 + v2)  # prints None!


if __name__ == '__main__':
    main()