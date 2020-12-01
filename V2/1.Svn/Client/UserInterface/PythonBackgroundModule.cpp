///Add
#if defined(__BL_WEATHER_INFO__)
PyObject* backgroundChangeTextureset(PyObject* poSelf, PyObject* poArgs)
{
	char* szFileName;
	if (!PyTuple_GetString(poArgs, 0, &szFileName))
		return Py_BuildException();

	CPythonBackground::Instance().GetMapOutdoorRef().ChangeTextureset(szFileName);
	return Py_BuildNone();
}
#endif

//Find
		{ "Initialize",							backgroundInitialize,						METH_VARARGS },
		
///Add
#if defined(__BL_WEATHER_INFO__)
		{ "ChangeTextureset",					backgroundChangeTextureset,					METH_VARARGS },
#endif