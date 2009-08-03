/*
 * Copyright 2009 Paul J. Davis <paul.joseph.davis@gmail.com>
 *
 * This file is part of the python-spidermonkey package released
 * under the MIT license.
 *
 */

#include <spidermonkey.h>

#ifndef PyMODINIT_FUNC
#define PyMODINIT_FUNC void
#endif

PyObject* SpidermonkeyModule = NULL;
PyObject* JSError = NULL;

static PyMethodDef spidermonkey_methods[] = {
    {NULL}
};

PyMODINIT_FUNC
initspidermonkey(void)
{
    PyObject* m;
    
    if(PyType_Ready(&RuntimeType) < 0) return;
    if(PyType_Ready(&ContextType) < 0) return;
    if(PyType_Ready(&ObjectType) < 0) return;
    ArrayType.tp_base = &ObjectType;
    if(PyType_Ready(&ArrayType) < 0) return;
    FunctionType.tp_base = &ObjectType;
    if(PyType_Ready(&FunctionType) < 0) return;
    if(PyType_Ready(&IteratorType) < 0) return;
    if(PyType_Ready(&HashCObjType) < 0) return;
    
    m = Py_InitModule3("spidermonkey", spidermonkey_methods,
                            "The Python-Spidermonkey bridge.");
    if(m == NULL) return;

    Py_INCREF(&RuntimeType);
    PyModule_AddObject(m, "Runtime", (PyObject*)&RuntimeType);

    Py_INCREF(&ContextType);
    PyModule_AddObject(m, "Context", (PyObject*)&ContextType);

    Py_INCREF(&ObjectType);
    PyModule_AddObject(m, "Object", (PyObject*)&ObjectType);

    Py_INCREF(&ArrayType);
    PyModule_AddObject(m, "Array", (PyObject*)&ArrayType);

    Py_INCREF(&FunctionType);
    PyModule_AddObject(m, "Function", (PyObject*)&FunctionType);

    //Py_INCREF(IteratorType);

    //Py_INCREF(HashCObjType);

    JSError = PyErr_NewException("spidermonkey.JSError", NULL, NULL);
    PyModule_AddObject(m, "JSError", JSError);
    
    SpidermonkeyModule = m;
}
