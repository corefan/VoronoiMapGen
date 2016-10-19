#ifndef __SGP_OPENGLRENDERBATCH_HEADER__
#define __SGP_OPENGLRENDERBATCH_HEADER__

class COpenGLRenderDevice;
class COpenGLStaticBuffer;
class COpenGLDynamicBuffer;
class OpenGLParticleDynamicBuffer;
class COpenGLTextureBufferObject;

#pragma warning (disable:4201) 

// RenderBatch Base virtual class
class ISGPRenderBatch
{
public:
	enum BatchType
	{
		eBatchOpaque = 0,
		eBatchTransparent,

		eBatchParticlePointSprites,
		eBatchParticleLine,
		eBatchParticleQuad,

		eBatchSkinAnim,
		eBatchSkinAnimAlpha,			// Only for render flag

		eBatchLine,

		eBatchNumMax,
	};

	virtual ~ISGPRenderBatch() { }

	virtual void		BuildQueueValue() = 0;
	virtual uint64		GetQueueValue() = 0;
	virtual void		Render();
	virtual void		PreRender();
	virtual void		PostRender();

	BatchType			GetBatchType() { return m_BatchType; }

public:
	BatchType				m_BatchType;
	Vector4D				m_BBOXCenter;
	Matrix4x4				m_MatWorld;
	COpenGLRenderDevice*	m_RenderDevice;
	COpenGLStaticBuffer*	m_pSB;
	COpenGLDynamicBuffer*	m_pVC;

	RenderBatchConfig		m_BatchConfig;

	static int32			m_ShaderProgramIdx;
	static bool				m_SkinAnimShaderLightmapTexSetted;
};


class COpaqueRenderBatch : public ISGPRenderBatch
{
public:
	COpaqueRenderBatch(COpenGLRenderDevice* pRenderDevice)	  
	{ 
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchOpaque; 
		m_MatWorld.Identity();
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }

	union
	{
		struct
		{
			uint64 ulReserved				: 2;    // unused bits
			uint64 uldistance				: 32;	// object distance from camera
			uint64 ulpriority				: 14;   // 14 bits for user given priority (0-16384) (usually Tex ID)
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;
};



class CTransparentRenderBatch : public ISGPRenderBatch
{
public:
	CTransparentRenderBatch(COpenGLRenderDevice* pRenderDevice)
	{ 
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchTransparent;
		m_MatWorld.Identity(); 
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }

	union
	{
		struct
		{
			uint64 ulReserved				: 2;    // unused bits
			uint64 ulpriority				: 14;   // 14 bits for user given priority (0-16384) (usually Tex ID)
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 uldistance				: 32;	// object distance from camera
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;
};

class CParticlePSRenderBatch : public ISGPRenderBatch
{
public:
	CParticlePSRenderBatch(COpenGLRenderDevice* pRenderDevice)
	{
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchParticlePointSprites;
		m_MatWorld.Identity();
		m_pParticleBuffer = NULL;
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }
	virtual void Render();
	virtual void PreRender();
	virtual void PostRender();

	union
	{
		struct
		{
			uint64 ulReserved				: 2;   // unused bits
			uint64 ulpriority				: 14;   // 14 bits for user given priority (0-16384) (usually Tex ID)
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 uldistance				: 32;	// object distance from camera
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;

	OpenGLParticleDynamicBuffer* m_pParticleBuffer;
};

class CParticleLineRenderBatch : public ISGPRenderBatch
{
public:
	CParticleLineRenderBatch(COpenGLRenderDevice* pRenderDevice)
	{
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchParticleLine;
		m_MatWorld.Identity();
		m_pParticleBuffer = NULL;
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }
	virtual void Render();
	virtual void PreRender();
	virtual void PostRender();

	union
	{
		struct
		{
			uint64 ulReserved				: 16;   // unused bits
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 uldistance				: 32;	// object distance from camera
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;

	OpenGLParticleDynamicBuffer* m_pParticleBuffer;
};

class CParticleQuadRenderBatch : public ISGPRenderBatch
{
public:
	CParticleQuadRenderBatch(COpenGLRenderDevice* pRenderDevice)
	{
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchParticleQuad;
		m_MatWorld.Identity();
		m_pParticleBuffer = NULL;
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }
	virtual void Render();
	virtual void PreRender();
	virtual void PostRender();

	union
	{
		struct
		{
			uint64 ulReserved				: 2;   // unused bits
			uint64 ulpriority				: 14;   // 14 bits for user given priority (0-16384) (usually Tex ID)
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 uldistance				: 32;	// object distance from camera
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;

	OpenGLParticleDynamicBuffer* m_pParticleBuffer;
	Vector4D m_TextureAtlas;
};


class CSkinAnimRenderBatch : public ISGPRenderBatch
{
public:
	CSkinAnimRenderBatch(COpenGLRenderDevice* pRenderDevice)	  
	{ 
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchSkinAnim; 
		m_MatWorld.Identity();
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }
	virtual void Render();
	virtual void PreRender();
	virtual void PostRender();

	union
	{
		struct
		{
			uint64 ulReserved				: 18;   // unused bits
			uint64 ulpriority				: 14;   // 14 bits for user given priority (0-16384) (usually Tex ID)
			uint64 ultboid					: 16;	// 16 bits for TBO ID (0-65536)
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;


	uint32 m_TBOID;
};

class CLineRenderBatch : public ISGPRenderBatch
{
public:
	CLineRenderBatch(COpenGLRenderDevice* pRenderDevice)	  
	{ 
		m_RenderDevice = pRenderDevice;
		m_BatchType = eBatchLine; 
		m_MatWorld.Identity();
	}

	virtual void BuildQueueValue();
	virtual uint64 GetQueueValue()	{ return stQueueValue.ulQueueValue; }

	union
	{
		struct
		{
			uint64 ulReserved				: 48;   // unused bits
			uint64 ulshader					: 10;	// 10 bits for shader (0-1024) (usually shader ID)
			uint64 ulqueue_id				: 6;	// 6 bits for user given queue (0-64)
		};
		uint64 ulQueueValue;
	} stQueueValue;
};

typedef Array<COpaqueRenderBatch*>			OpaqueRenderBatchVector;
typedef Array<CTransparentRenderBatch*>		TransparentRenderBatchVector;
typedef Array<CParticlePSRenderBatch*>		ParticlePSRenderBatchVector;
typedef Array<CParticleLineRenderBatch*>	ParticleLineRenderBatchVector;
typedef Array<CParticleQuadRenderBatch*>	ParticleQuadRenderBatchVector;
typedef Array<CSkinAnimRenderBatch*>		SkinAnimRenderBatchVector;
typedef Array<CLineRenderBatch*>			LineRenderBatchVector;

typedef OwnedArray<COpaqueRenderBatch>			OwnedArrayOpaqueRenderBatch;
typedef OwnedArray<CTransparentRenderBatch>		OwnedArrayTransparentRenderBatch;
typedef OwnedArray<CParticlePSRenderBatch>		OwnedArrayParticlePSRenderBatch;
typedef OwnedArray<CParticleLineRenderBatch>	OwnedArrayParticleLineRenderBatch;
typedef OwnedArray<CParticleQuadRenderBatch>	OwnedArrayParticleQuadRenderBatch;
typedef OwnedArray<CSkinAnimRenderBatch>		OwnedArraySkinAnimRenderBatch;
typedef OwnedArray<CLineRenderBatch>			OwnedArrayLineRenderBatch;


#endif		// __SGP_OPENGLRENDERBATCH_HEADER__