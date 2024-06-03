import ctypes

# Load the shared library
lib = ctypes.CDLL("./test.so")
print("Hello from pyth.py")
lib.py_func()
