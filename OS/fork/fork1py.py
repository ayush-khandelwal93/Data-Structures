import os
import time

def print_sq():
	while True:
		time.sleep(0.7)
		print('square')

def print_cube():
	while True:
		time.sleep(0.7)
		print('cube')

if __name__ == '__main__':
	t1 = os.fork()
	
	if t1 > 0: 
		print("Parent process and id is : ", os.getpid()) 
  
    # t1 equals to 0 means child process 
	else: 
		print("Child process and id is : ", os.getpid())
	
	if t1 > 0:
		print_sq()

    # n equals to 0 means child process 
	else:
		print_cube()

# if Kill parent process id from terminal
# child process keeps running
