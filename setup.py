from distutils.core import setup, Extension
setup(
    name='sigTestC',
    version='1.2',
    author='Benjamin Blouin',
    author_email='3keepmovingforward3@gmail.com',
    url="https://github.com/3keepmovingforward3/SIG_Test",
    description='Test given for SIG hiring',
    ext_modules=[Extension('sigTestC', ['main.cpp'])])
