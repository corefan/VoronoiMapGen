char Shader_anim_VS_String[] = 
	"#version 330											\n"\
	"														\n"\
	"layout (location = 0) in vec4 inPosition;				\n"\
	"layout (location = 1) in vec3 inNormal;				\n"\
	"layout (location = 2) in vec2 inCoord;					\n"\
	"layout (location = 3) in vec4 inBoneIndex;				\n"\
	"layout (location = 4) in vec4 inBoneWeight;			\n"\

	"uniform mat4 modelViewProjMatrix;						\n"\
	"uniform mat4 worldMatrix;								\n"\
	"uniform float fFarPlane;								\n"\



	"// TextureAtlas how many parts texture be divided in X and Y								\n"\
	"// TextureAtlas.xy = AtlasNbX, AtlasNbY													\n"\
	"// TextureAtlas.zw = 1.0f/AtlasNbX, 1.0f/AtlasNbY											\n"\
	"uniform vec4 TextureAtlas;																	\n"\
	"uniform vec3 TexIndexUVOffset;		// x is texture index; y,z is uv offset					\n"\
	"uniform vec3 SunDirection;			// Sun Direction 										\n"\

	"uniform samplerBuffer jointTex;															\n"\

	"out float fVertexAlphaPass;																\n"\
	"out vec2 vTexCoordPass;																	\n"\
	"out vec4 vLightPass;				// w save as depth										\n"\

	" void main()																				\n"\
	" {																							\n"\
	"	 mat4 matBone = mat4(0.0);																\n"\
	"    for(int i = 0; i < 4; ++i)																\n"\
    "    {																						\n"\
	"		 matBone[0] += texelFetch(jointTex, int(3*inBoneIndex[i]  )  ) * inBoneWeight[i];	\n"\
    "		 matBone[1] += texelFetch(jointTex, int(3*inBoneIndex[i]+1)  ) * inBoneWeight[i];	\n"\
    "		 matBone[2] += texelFetch(jointTex, int(3*inBoneIndex[i]+2)  ) * inBoneWeight[i];	\n"\
	"    }																						\n"\
	"	 matBone[3] = vec4(0.0, 0.0, 0.0, 1.0);													\n"\

	"	 mat4 mtInvBone = transpose(matBone);													\n"\
	"    vec4 vPosition = mtInvBone * vec4(inPosition.xyz, 1.0);								\n"\
	"	 vPosition = vPosition / vPosition.w;													\n"\
	"	 vec4 vNormal = mtInvBone * vec4(inNormal, 0.0);										\n"\
																								
	" 	 gl_Position = modelViewProjMatrix * vPosition;											\n"\
	"	 vLightPass = worldMatrix * vNormal;													\n"\
	"	 vLightPass = normalize(vLightPass);													\n"\
	
	"	 // Invert the light direction for calculations.										\n"\
    "	 // Calculate the light based on the normal value.										\n"\
    "	 float lightIntensity = clamp(dot(vLightPass.xyz, -SunDirection), 0.0, 1.0);			\n"\
	"	 vLightPass.xyz = vec3(lightIntensity, lightIntensity, lightIntensity);					\n"\

	"	 vTexCoordPass = vec2(																	\n"\
	"		 float( int(TexIndexUVOffset.x) % int(TextureAtlas.x) ) / TextureAtlas.x,			\n"\
	"		 float( int(TexIndexUVOffset.x) / int(TextureAtlas.x) ) / TextureAtlas.y ) +		\n"\
	"			 inCoord.xy * TextureAtlas.zw + TexIndexUVOffset.yz;							\n"\

	"	  // store Depth into vLightPass w channel as current w / farplane						\n"\
	"	  vLightPass.w = gl_Position.w / fFarPlane;												\n"\
	"	  fVertexAlphaPass = inPosition.w;														\n"\
	" }																							\n"\
	"";

char Shader_anim_PS_String[] = 
	"#version 330																	\n"\
	"																				\n"\
	"in float fVertexAlphaPass;														\n"\
	"in vec2 vTexCoordPass;															\n"\
	"in vec4 vLightPass;															\n"\

	"uniform sampler2D gSampler0;													\n"\
	"uniform sampler2D gSamplerLightmap;	// Lightmap	Texture						\n"\
	"uniform vec4 vMaterialColor;													\n"\
	"uniform vec2 vTexCoordLightMap;												\n"\
	"uniform vec4 SunColor;															\n"\
	
	"layout (location = 0) out vec4 outputColor;									\n"\
	"layout (location = 1) out vec4 outputColor1;									\n"\

	"void main()																	\n"\
	"{																				\n"\
	"	vec4 DiffuseColor = texture2D(gSampler0, vTexCoordPass) * vMaterialColor;	\n"\
	"	vec4 LightmapColor = texture2D(gSamplerLightmap, vTexCoordLightMap);		\n"\

	"	outputColor.rgb = DiffuseColor.rgb * vLightPass.rgb * SunColor.rgb;			\n"\
	"	outputColor.rgb += DiffuseColor.rgb * SunColor.a * LightmapColor.a;			\n"\
	"	outputColor.rgb += DiffuseColor.rgb * LightmapColor.rgb;					\n"\
	"	outputColor.a = DiffuseColor.a * fVertexAlphaPass;							\n"\

	"	// Packing a [0-1] float depth value into a 4D vector						\n"\
	"	// where each component will be 8-bits color value							\n"\
	"	const vec4 bitSh = vec4(16777216.0, 65536.0, 256.0, 1.0);					\n"\
	"	const vec4 bitMsk = vec4(0.0, 1.0/256.0, 1.0/256.0, 1.0/256.0);				\n"\
	"	outputColor1 = fract(vLightPass.w * bitSh);									\n"\
	"	outputColor1 -= outputColor1.xxyz * bitMsk;									\n"\
	"}																				\n"\

	"";