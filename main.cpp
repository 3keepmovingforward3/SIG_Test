#include <Python.h>
#include <array>
#include <iostream>

using namespace std;


// Function 1: A simple 'hello world' function
static PyObject* helloworld(PyObject* self, PyObject* args)
{
    printf("Hello World\n");
    return Py_None;
}

// Function 2: A C fibonacci implementation
// this is nothing special and looks exactly
// like a normal C version of fibonacci would look
int Cfib(int n)
{
    if (n < 2)
        return n;
    else
        return Cfib(n-1)+Cfib(n-2);
}

int Csquare(int pr)
{
	pr*=pr;

    return pr;
}

// Our Python binding to our C function
// This will take one and only one non-keyword argument
static PyObject* square(PyObject* self, PyObject* args)
{
    
    PyObject *int_list;
    int pr_length;
    int *pr;

    if(!PyArg_ParseTuple(args, "O", &int_list))
        return NULL;
    
	pr_length = PyObject_Length(int_list);
	PyObject *return_list = PyList_New(pr_length);
    
	if(pr_length < 0)
	return NULL;
    pr = (int *) malloc(sizeof(int *) * pr_length);
    if(pr == NULL)
        return NULL;
    for (int index = 0; index < pr_length; index++){
	PyObject *item;
	item = PyList_GetItem(int_list, index);
	if(!PyFloat_Check(item))
	    pr[index] = 0;
	pr[index] = PyFloat_AsDouble(item); // Integer Objects are implemented as "long" integer objects
    }
    // return our computed square number
	for (int i = 0; i < pr_length; ++i){
		PyObject* python_int = Py_BuildValue("i", Csquare(pr[i]));
		PyList_SetItem(return_list, i, python_int);
	}
	
    return return_list;
}

// Our Python binding to our C function
// This will take one and only one non-keyword argument
static PyObject* fib(PyObject* self, PyObject* args)
{
    // instantiate our `n` value
    int n;
    // if our `n` value
    if(!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    // return our computed fib number
    return Py_BuildValue("i", Cfib(n));
}

// Our Module's Function Definition struct
// We require this `NULL` to signal the end of our method
// definition
static PyMethodDef myMethods[] = {
    { "helloworld", helloworld, METH_NOARGS, "Prints Hello World" },
    { "fib", fib, METH_VARARGS, "Determine fib sequence" },
    { "square", square, METH_VARARGS, "Determine square of num" },
    { NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule",
    "Test Module",
    -1,
    myMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_myModule(void)
{
    return PyModule_Create(&myModule);
}
