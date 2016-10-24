import glob
import os

for filename in glob.iglob('**/*.exe', recursive=True):
	print(filename)
	os.remove(filename);
	
for filename in glob.iglob('**/*.o', recursive=True):
	print(filename)
	os.remove(filename);
	
input("Press enter to exit.");