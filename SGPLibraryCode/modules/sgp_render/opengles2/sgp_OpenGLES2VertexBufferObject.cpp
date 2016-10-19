#define BUFFER_OFFSET(i) ((char *)NULL + (i))

/*-----------------------------------------------
Name:	createVAO
Params:	none
Result:	Creates one vertex array object.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::createVAO()
{
	m_pRenderDevice->extGlGenVertexArray(1, &m_VAOID);
}

/*-----------------------------------------------
Name:	BindVAO
Params:	none
Result:	Binds this VAO.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::bindVAO()
{
	m_pRenderDevice->extGlBindVertexArray(m_VAOID);
}

/*-----------------------------------------------
Name:	unBindVAO
Params:	none
Result:	unBinds this VAO.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::unBindVAO()
{
	m_pRenderDevice->extGlBindVertexArray(0);
}

/*-----------------------------------------------
Name:	DeleteVAO
Params:	none
Result:	Releases VAO and frees all memory.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::deleteVAO()
{
	m_pRenderDevice->extGlDeleteVertexArray(1, &m_VAOID);
}

/*-----------------------------------------------
Name:	setVAOPointer
Params:	index - Specifies the index of the generic vertex attribute to be modified
		size - number of components per generic vertex attribute.. Must be 1, 2, 3, 4.
		type - data type of each component in the array
		normalized - whether fixed-point data values should be normalized
		stride -  the byte offset between consecutive generic vertex attributes.
		pointer - a offset of the first component of the first generic vertex attribute 
		in the array in the data store of the buffer 
		currently bound to the GL_ARRAY_BUFFER target
Result:	define an array of generic vertex attribute data.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::setVAOPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}




/*-----------------------------------------------
Name:	createVBO
Params:	
		BufferType - Vertex Buffer or Index Buffer
Result:	Creates vertex buffer object.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::createVBO(SGP_BUFFER_TYPE BufferType)
{
	if( BufferType == SGPBT_VERTEX )
	{
		glGenBuffers(1, &m_VBOBufferID[0]);
	}
	else if( BufferType == SGPBT_INDEX )
	{
		glGenBuffers(1, &m_VBOBufferID[1]);
	}
}

/*-----------------------------------------------
Name:	deleteVBO
Params:	BufferType - Vertex Buffer or Index Buffer
Result:	Releases VBO and frees all memory.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::deleteVBO(SGP_BUFFER_TYPE BufferType)
{
	if( BufferType == SGPBT_VERTEX_AND_INDEX )
	{
		glDeleteBuffers(1, &m_VBOBufferID[0]);
		glDeleteBuffers(1, &m_VBOBufferID[1]);
		m_bDataUploaded = false;
		m_bIndexUploaded = false;
		m_Data.clearQuick();
		m_Index.clearQuick();
	}
	else if( BufferType == SGPBT_VERTEX )
	{
		glDeleteBuffers(1, &m_VBOBufferID[0]);
		m_bDataUploaded = false;
		m_Data.clearQuick();
	}
	else if( BufferType == SGPBT_INDEX )
	{
		glDeleteBuffers(1, &m_VBOBufferID[1]);
		m_bIndexUploaded = false;
		m_Index.clearQuick();
	}
}

/*-----------------------------------------------
Name:	mapBufferToMemory
Params:	iUsageHint - GL_READ_ONLY, GL_WRITE_ONLY...
		BufferType - Vertex Buffer or Index Buffer
Result:	Maps whole buffer data to memory and returns pointer to data.
---------------------------------------------*/
void* COpenGLES2VertexBufferObject::mapBufferToMemory(SGP_BUFFER_TYPE BufferType, GLenum iUsageHint)
{
	void* ptrRes = NULL;
	if( BufferType == SGPBT_VERTEX )
	{
		if( !m_bDataUploaded )
			return NULL;
		ptrRes = m_pRenderDevice->extGlMapBuffer(GL_ARRAY_BUFFER, iUsageHint);
	}
	else if( BufferType == SGPBT_INDEX )
	{
		if( !m_bIndexUploaded )
			return NULL;
		ptrRes = m_pRenderDevice->extGlMapBuffer(GL_ELEMENT_ARRAY_BUFFER, iUsageHint);
	}
	return ptrRes;
}

/*-----------------------------------------------
Name:	mapSubBufferToMemory
Params:	iUsageHint - GL_READ_ONLY, GL_WRITE_ONLY...
		uiOffset - data offset (from where should data be mapped).
		uiLength - length of data
		BufferType - Vertex Buffer or Index Buffer
Result:	Maps specified part of buffer to memory.
---------------------------------------------*/
void* COpenGLES2VertexBufferObject::mapSubBufferToMemory(SGP_BUFFER_TYPE BufferType, GLenum iUsageHint, uint32 uiOffset, uint32 uiLength)
{
	void* ptrRes = NULL;
	if( BufferType == SGPBT_VERTEX )
	{
		if( !m_bDataUploaded )
			return NULL;
		ptrRes = m_pRenderDevice->extGlMapBufferRange(GL_ARRAY_BUFFER, uiOffset, uiLength, iUsageHint);
	}
	else if( BufferType == SGPBT_INDEX )
	{
		if( !m_bIndexUploaded )
			return NULL;
		ptrRes = m_pRenderDevice->extGlMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, uiOffset, uiLength, iUsageHint);
	}
	return ptrRes;
}

/*-----------------------------------------------
Name:	unmapBuffer
Params:	BufferType - Vertex Buffer or Index Buffer
Result:	Unmaps previously mapped buffer.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::unmapBuffer(SGP_BUFFER_TYPE BufferType)
{
	if( BufferType == SGPBT_VERTEX_AND_INDEX )
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOBufferID[0]);
		m_pRenderDevice->extGlUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VBOBufferID[1]);
		m_pRenderDevice->extGlUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	}
	else if( BufferType == SGPBT_VERTEX )
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOBufferID[0]);
		m_pRenderDevice->extGlUnmapBuffer(GL_ARRAY_BUFFER);
	}
	else if( BufferType == SGPBT_INDEX )
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VBOBufferID[1]);
		m_pRenderDevice->extGlUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	}
}

/*-----------------------------------------------
Name:	BindVBO
Params:	BufferType - Vertex Buffer or Index Buffer
Result:	Binds this VBO.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::bindVBO(SGP_BUFFER_TYPE BufferType)
{
	if( BufferType == SGPBT_VERTEX )
		glBindBuffer(GL_ARRAY_BUFFER, m_VBOBufferID[0]);
	else if( BufferType == SGPBT_INDEX )
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VBOBufferID[1]);
}

void COpenGLES2VertexBufferObject::initVBOBuffer(SGP_BUFFER_TYPE BufferType, int iBufferSize, GLenum iUsageHint)
{
	if( BufferType == SGPBT_VERTEX )
		glBufferData(GL_ARRAY_BUFFER, iBufferSize, NULL, iUsageHint);
	else if( BufferType == SGPBT_INDEX )
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, iBufferSize, NULL, iUsageHint);
}

void COpenGLES2VertexBufferObject::initVBOBuffer(SGP_BUFFER_TYPE BufferType, const void* ptrData, int iBufferSize, GLenum iUsageHint)
{
	if( BufferType == SGPBT_VERTEX )
		glBufferData(GL_ARRAY_BUFFER, iBufferSize, ptrData, iUsageHint);
	else if( BufferType == SGPBT_INDEX )
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, iBufferSize, ptrData, iUsageHint);
}


/*-----------------------------------------------
Name:	uploadDataToGPU
Params:	iUsageHint - GL_STATIC_DRAW, GL_DYNAMIC_DRAW...
		BufferType - Vertex Buffer or Index Buffer
Result:	Sends data to GPU.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::uploadDataToGPU(SGP_BUFFER_TYPE BufferType, GLenum iDrawingHint)
{
	if( BufferType == SGPBT_VERTEX )
	{
		glBufferData(GL_ARRAY_BUFFER, m_Data.size(), (const GLvoid*)m_Data.getRawDataPointer(), iDrawingHint);
		m_bDataUploaded = true;
		m_Data.clearQuick();
	}
	else if( BufferType == SGPBT_INDEX )
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Index.size()*sizeof(uint16), (const GLvoid*)m_Index.getRawDataPointer(), iDrawingHint);
		m_bIndexUploaded = true;
		m_Index.clearQuick();
	}
}

/*-----------------------------------------------
Name:	addData
Params:	ptrData - pointer to arbitrary data
		uiDataSize - data size in bytes
		buffertype - Vertex Buffer or Index Buffer
Result:	Adds arbitrary data to VBO.
---------------------------------------------*/
void COpenGLES2VertexBufferObject::addData(SGP_BUFFER_TYPE buffertype, const void* ptrData, uint32 uiDataSize)
{
	if( buffertype == SGPBT_VERTEX )
	{
		for( uint32 i=0; i<uiDataSize; ++i )
			m_Data.add( *((uint8*)ptrData + i) );
		m_bDataUploaded = false;
	}
	else if( buffertype == SGPBT_INDEX )
	{
		for( uint32 i=0; i<uiDataSize/sizeof(uint16); ++i )
			m_Index.add( *((uint16*)ptrData + i) );
		m_bIndexUploaded = false;
	}
}

/*-----------------------------------------------
Name:	ensureDataSpace
Params:	
		buffertype - Vertex Buffer or Index Buffer
		uiDataSize - data size in bytes
Result:	Increases the VBO array's internal storage to hold a minimum number of elements. 
---------------------------------------------*/
void COpenGLES2VertexBufferObject::ensureDataSpace(SGP_BUFFER_TYPE buffertype, uint32 uiDataSize)
{
	if( buffertype == SGPBT_VERTEX )
	{
		m_Data.ensureStorageAllocated(uiDataSize);
	}
	else if( buffertype == SGPBT_INDEX )
	{
		m_Index.ensureStorageAllocated(uiDataSize/sizeof(uint16));
	}
}


/*-----------------------------------------------
Name:	getDataPointer
Params:	buffertype - Vertex Buffer or Index Buffer
Result:	Returns data pointer (only before uploading).
---------------------------------------------*/
void* COpenGLES2VertexBufferObject::getDataPointer(SGP_BUFFER_TYPE buffertype)
{
	if( buffertype == SGPBT_VERTEX )
	{
		if(m_bDataUploaded)
			return NULL;
		return (void*)m_Data.getRawDataPointer();
	}
	else if( buffertype == SGPBT_INDEX )
	{
		if(m_bIndexUploaded)
			return NULL;
		return (void*)m_Index.getRawDataPointer();
	}
	else
		return NULL;
}
