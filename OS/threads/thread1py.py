import threading
import time
import os

def print_cube():
	while True:
		time.sleep(0.5)
		print('cube')

def print_sq():
	while True:
		time.sleep(0.5)
		print('square')

if __name__ == '__main__':
	print(os.getpid())
	t1 = threading.Thread(target=print_sq)

	t1.start()
	
	print_cube() # main thread

	t1.join()




# When killing the process id from another terminal
# both the threads gets killed
# as one process can have multiple threads
