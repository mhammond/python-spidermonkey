/*
 * Copyright 2009 Paul J. Davis <paul.joseph.davis@gmail.com>
 *
 * This file is part of the python-spidermonkey package released
 * under the MIT license.
 *
 */

#ifndef SPIDERMONKEY_H
#define SPIDERMONKEY_H

#include <Python.h>
#include "structmember.h"

#include <jsapi.h>

#ifdef __cplusplus
#include "utils/utils.h"
#endif

#include "convert/convert.h"
#include "javascript/javascript.h"
#include "python/python.h"

#ifdef __cplusplus
extern "C" {
#endif

extern PyObject* SpidermonkeyModule;
extern PyObject* JSError;

#ifdef __cplusplus
}
#endif

#if JS_VERSION < 180
#   define JS_SetPropertyById js_SetProperty
#   define JS_DeletePropertyById2 js_DeleteProperty
#   define JS_GetPropertyById js_GetProperty
#endif

#endif
