# SIG_Test
CPython Module 

I'd never made a CPython module before, so it took ~1.5 hours.  

I was given the task of creating a CPython module that:  
1. Takes in a Python list
2. Squares each value
3. Returns the new list

# Extra Credit
## TestPyPi
https://test.pypi.org/project/sigTestC/

## Compatibility w/ other OSs  
Originally built in WSL2, which the packager treated as Linux.
I used auditwheel to remove the Linux specific C libs.  
Pypi doesn't allow OS specific wheels, it wants the "many" designation.
