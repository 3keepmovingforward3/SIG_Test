import pytest
import sigTestC as sig

def sig_square(x):
    return sig.square(x)

def test_sig_square():
    assert sig_square([1,2,3,4])==[1,4,9,16]
