#ifndef __SGP_TERRAINTILESHAPE_HEADER__
#define __SGP_TERRAINTILESHAPE_HEADER__

// terrain vertex grid layout in one chunk	9 * 9 vertex

/*
	0   1    2	  3    4    5    6    7    8
	*---**---**---**---**---**---**---**---*
	| \ || \ || / || / || \ || \ || / || / |		
   9*---**---**---**---**---**---**---**---*17			
	| \ || \ || / || / || \ || \ || / || / |		
  18*---**---**---**---**---**---**---**---*26		
	| / || / || \ || \ || / || / || \ || \ |
  27*---**---**---**---**---**---**---**---*35
	| / || / || \ || \ || / || / || \ || \ |
  36*---**---**---**---**---**---**---**---*44
	| \ || \ || / || / || \ || \ || / || / |
  45*---**---**---**---**---**---**---**---*53
	| \ || \ || / || / || \ || \ || / || / |
  54*---**---**---**---**---**---**---**---*62
	| / || / || \ || \ || / || / || \ || \ |
  63*---**---**---**---**---**---**---**---*71
	| / || / || \ || \ || / || / || \ || \ |
  72*---**---**---**---**---**---**---**---*80
*/




/*
	Terrain Chunk state : this chunk may be in one of these SGPTERRAIN_CHUNK_STATE at any time
	CURRETNT Lod Level : only 0 and 1
*/
enum SGPTERRAIN_CHUNK_STATE
{
	SGPTCS_LOD0 = 0,

	SGPTCS_LOD1TOLOD0_UP,
	SGPTCS_LOD1TOLOD0_BOTTOM,
	SGPTCS_LOD1TOLOD0_LEFT,
	SGPTCS_LOD1TOLOD0_RIGHT,
	SGPTCS_LOD1TOLOD0_LEFTUP,
	SGPTCS_LOD1TOLOD0_RIGHTUP,
	SGPTCS_LOD1TOLOD0_LEFTBOTTOM,
	SGPTCS_LOD1TOLOD0_RIGHTBOTTOM,
	SGPTCS_LOD1TOLOD0_SIDE,


	//SGPTCS_LOD0TOLOD1_UP,
	//SGPTCS_LOD0TOLOD1_BOTTOM,
	//SGPTCS_LOD0TOLOD1_LEFT,
	//SGPTCS_LOD0TOLOD1_RIGHT,
	//SGPTCS_LOD0TOLOD1_LEFTUP,
	//SGPTCS_LOD0TOLOD1_RIGHTUP,
	//SGPTCS_LOD0TOLOD1_LEFTBOTTOM,
	//SGPTCS_LOD0TOLOD1_RIGHTBOTTOM,
	//SGPTCS_LOD0TOLOD1_SIDE,

	SGPTCS_LOD1,
};

struct SGPTerrainChunkIndexInfo
{
	SGPTERRAIN_CHUNK_STATE indexstate;
	uint32 indexoffset;
	uint32 indexcount;
};


#define TERRAIN_CHUNK_INDEX_LOD0																	\
	0, 9, 10, 0, 10, 1, 1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13,				\
	4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16, 7, 16, 8, 8, 16, 17,				\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62,	\
	63, 72, 64, 64, 72, 73, 64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	\
	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70, 70, 79, 80, 70, 80, 71	

#define TERRAIN_CHUNK_INDEX_LOD0_COUNT (SGPTT_TILENUM)*(SGPTT_TILENUM)*2*3

#define TERRAIN_CHUNK_INDEX_LOD1																	\
	0, 18, 20, 0, 20, 2, 2, 20, 4, 4, 20, 22, 4, 22, 24, 4, 24, 6, 6, 24, 8, 8, 24, 26,				\
	18, 36, 20, 20, 36, 38, 20, 38, 40, 20, 40, 22, 22, 40, 24, 24, 40, 42, 24, 42, 44, 24, 44, 26,	\
	36, 54, 56, 36, 56, 38, 38, 56, 40, 40, 56, 58, 40, 58, 60, 40, 60, 42, 42, 60, 44, 44, 60, 62,	\
	54, 72, 56, 56, 72, 74, 56, 74, 76, 56, 76, 58, 58, 76, 60, 60, 76, 78, 60, 78, 80, 60, 80, 62

#define TERRAIN_CHUNK_INDEX_LOD1_COUNT (SGPTT_TILENUM>>1)*(SGPTT_TILENUM>>1)*2*3






#define TERRAIN_CHUNK_INDEX_LODLINK_SIDE	\
	0, 10, 2, 2, 10, 11, 2, 11, 12, 2, 12, 4, 4, 12, 13, 4, 13, 14, 4, 14, 6, 6, 14, 15, 6, 15, 16,	6, 16, 8,				\
	8, 16, 26, 16, 25, 26, 25, 34, 26, 26, 34, 44, 34, 43, 44, 43, 52, 44, 44, 52, 62, 52, 61, 62, 61, 70, 62, 62, 70, 80,	\
	70, 78, 80, 69, 78, 70, 68, 78, 69, 68, 76, 78, 67, 76, 68, 66, 76, 67, 66, 74, 76, 65, 74, 66, 64, 74, 65, 64, 72, 74,	\
	54, 72, 64, 54, 64, 55, 46, 54, 55, 36, 54, 46, 36, 46, 37, 28, 36, 37, 18, 36, 28, 18, 28, 19, 18, 19, 10, 0, 18, 10
#define TERRAIN_CHUNK_INDEX_LOD_SIDE		\
	10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16,	16, 24, 25, \
	19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25,	\
	28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34,	\
	37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52,	\
	46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61,	\
	55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61

#define TERRAIN_CHUNK_INDEX_LODLINK_SIDE_COUNT 40*3
#define TERRAIN_CHUNK_INDEX_LOD_SIDE_COUNT (SGPTT_TILENUM-2)*(SGPTT_TILENUM-2)*2*3






#define TERRAIN_CHUNK_INDEX_LODLINK_UP	\
	0, 9, 10, 0, 10, 2, 2, 10, 11, 2, 11, 12, 2, 12, 4, 4, 12, 13,			\
	4, 13, 14, 4, 14, 6, 6, 14, 15, 6, 15, 16, 6, 16, 8, 8, 16, 17
#define TERRAIN_CHUNK_INDEX_LOD_UP		\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62,	\
	63, 72, 64, 64, 72, 73, 64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	\
	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70, 70, 79, 80, 70, 80, 71	

#define TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT 12*3
#define TERRAIN_CHUNK_INDEX_LOD_UP_COUNT (SGPTT_TILENUM-1)*SGPTT_TILENUM*2*3





#define TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM	\
	63, 72, 64, 64, 72, 74, 64, 74, 65, 65, 74, 66, 66, 74, 76, 66, 76, 67, \
	67, 76, 68, 68, 76, 78, 68, 78, 69, 69, 78, 70, 70, 78, 80, 70, 80, 71
#define TERRAIN_CHUNK_INDEX_LOD_BOTTOM		\
	0, 9, 10, 0, 10, 1, 1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13,				\
	4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16, 7, 16, 8, 8, 16, 17,				\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62

#define TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT 12*3
#define TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT (SGPTT_TILENUM-1)*SGPTT_TILENUM*2*3






#define TERRAIN_CHUNK_INDEX_LODLINK_LEFT	\
	0, 10, 1, 0, 18, 10, 10, 18, 19, 18, 28, 19, 18, 36, 28, 28, 36, 37,	\
	36, 46, 37, 36, 54, 46, 46, 54, 55, 54, 64, 55, 54, 72, 64, 64, 72, 73
#define TERRAIN_CHUNK_INDEX_LOD_LEFT		\
	1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13, 4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16, 7, 16, 8, 8, 16, 17,	\
	10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62,	\
	64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70, 70, 79, 80, 70, 80, 71	

#define TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT 12*3
#define TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT (SGPTT_TILENUM-1)*SGPTT_TILENUM*2*3





#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHT	\
	7, 16, 8, 8, 16, 26, 16, 25, 26, 25, 34, 26, 26, 34, 44, 34, 43, 44,	\
	43, 52, 44, 44, 52, 62, 52, 61, 62, 61, 70, 62, 62, 70, 80, 70, 79, 80
#define TERRAIN_CHUNK_INDEX_LOD_RIGHT		\
	0, 9, 10, 0, 10, 1, 1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13, 4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16,	\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22, 13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25,	\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25,	\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34,	\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52,	\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61,	\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61,	\
	63, 72, 64, 64, 72, 73, 64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70

#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT 12*3
#define TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT (SGPTT_TILENUM-1)*SGPTT_TILENUM*2*3






#define TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP	\
	64, 72, 73, 54, 72, 64, 54, 64, 55, 46, 54, 55, 36, 54, 46, 36, 46, 37, 28, 36, 37, 18, 36, 28, 18, 28, 19, 10, 18, 19,	\
	0, 18, 10, 0, 10, 2, 2, 10, 11, 2, 11, 12, 2, 12, 4, 4, 12, 13, 4, 13, 14, 4, 14, 6, 6, 14, 15, 6, 15, 16, 6, 16, 8, 8, 16, 17

#define TERRAIN_CHUNK_INDEX_LOD_LEFTUP		\
	10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62,	\
	64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	\
	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70, 70, 79, 80, 70, 80, 71

#define TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT 22*3
#define TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT (SGPTT_TILENUM-1)*(SGPTT_TILENUM-1)*2*3





#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP	\
	0, 9, 10, 0, 10, 2, 2, 10, 11, 2, 11, 12, 2, 12, 4, 4, 12, 13, 4, 13, 14, 4, 14, 6, 6, 14, 15, 6, 15, 16, 6, 16, 8,	\
	8, 16, 26, 16, 25, 26, 25, 34, 26, 26, 34, 44, 34, 43, 44, 43, 52, 44, 44, 52, 62, 52, 61, 62, 61, 70, 62, 62, 70, 80, 70, 79, 80
#define TERRAIN_CHUNK_INDEX_LOD_RIGHTUP		\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25,							\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25,							\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34,							\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52,							\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61,							\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61,							\
	63, 72, 64, 64, 72, 73, 64, 73, 65, 65, 73, 74, 65, 74, 75, 65, 75, 66, 66, 75, 76, 66, 76, 67,	\
	67, 76, 68, 68, 76, 77, 68, 77, 69, 69, 77, 78, 69, 78, 79, 69, 79, 70

#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT 22*3
#define TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT (SGPTT_TILENUM-1)*(SGPTT_TILENUM-1)*2*3





#define TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM	\
	0, 10, 1, 0, 18, 10, 10, 18, 19, 18, 28, 19, 18, 36, 28, 28, 36, 37, 36, 46, 37, 36, 54, 46, 46, 54, 55, 54, 64, 55, 54, 72, 64,	\
	64, 72, 74, 64, 74, 65, 65, 74, 66, 66, 74, 76, 66, 76, 67, 67, 76, 68, 68, 76, 78, 68, 78, 69, 69, 78, 70, 70, 78, 80, 70, 80, 71
#define TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM		\
	1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13,			\
	4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16, 7, 16, 8, 8, 16, 17,				\
	10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25, 16, 25, 17, 17, 25, 26,	\
	19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25, 25, 34, 35, 25, 35, 26,	\
	28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34, 34, 43, 44, 34, 44, 35,	\
	37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52, 43, 52, 44, 44, 52, 53,	\
	46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61, 52, 61, 53, 53, 61, 62,	\
	55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61, 61, 70, 71, 61, 71, 62

#define TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT 22*3
#define TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT (SGPTT_TILENUM-1)*(SGPTT_TILENUM-1)*2*3





#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM	\
	7, 16, 8, 8, 16, 26, 16, 25, 26, 25, 34, 26, 26, 34, 44, 34, 43, 44, 43, 52, 44, 44, 52, 62, 52, 61, 62, 61, 70, 62, 62, 70, 80,	\
	70, 78, 80, 69, 78, 70, 68, 78, 69, 68, 76, 78, 67, 76, 68, 66, 76, 67,	66, 74, 76, 65, 74, 66, 64, 74, 65, 64, 72, 74,	63, 72, 64
#define TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM		\
	0, 9, 10, 0, 10, 1, 1, 10, 11, 1, 11, 2, 2, 11, 3, 3, 11, 12, 3, 12, 4, 4, 12, 13,	\
	4, 13, 14, 4, 14, 5, 5, 14, 15, 5, 15, 6, 6, 15, 7, 7, 15, 16,						\
	9, 18, 19, 9, 19, 10, 10, 19, 20, 10, 20, 11, 11, 20, 12, 12, 20, 21, 12, 21, 13, 13, 21, 22,	\
	13, 22, 23, 13, 23, 14, 14, 23, 24, 14, 24, 15, 15, 24, 16, 16, 24, 25,				\
	18, 27, 19, 19, 27, 28, 19, 28, 20, 20, 28, 29, 20, 29, 30, 20, 30, 21, 21, 30, 31, 21, 31, 22,	\
	22, 31, 23, 23, 31, 32, 23, 32, 24, 24, 32, 33, 24, 33, 34, 24, 34, 25,				\
	27, 36, 28, 28, 36, 37, 28, 37, 29, 29, 37, 38, 29, 38, 39, 29, 39, 30, 30, 39, 40, 30, 40, 31,	\
	31, 40, 32, 32, 40, 41, 32, 41, 33, 33, 41, 42, 33, 42, 43, 33, 43, 34,				\
	36, 45, 46, 36, 46, 37, 37, 46, 47, 37, 47, 38, 38, 47, 39, 39, 47, 48, 39, 48, 40, 40, 48, 49,	\
	40, 49, 50, 40, 50, 41, 41, 50, 51, 41, 51, 42, 42, 51, 43, 43, 51, 52,				\
	45, 54, 55, 45, 55, 46, 46, 55, 56, 46, 56, 47, 47, 56, 48, 48, 56, 57, 48, 57, 49, 49, 57, 58,	\
	49, 58, 59, 49, 59, 50, 50, 59, 60, 50, 60, 51, 51, 60, 52, 52, 60, 61,				\
	54, 63, 55, 55, 63, 64, 55, 64, 56, 56, 64, 65, 56, 65, 66, 56, 66, 57, 57, 66, 67, 57, 67, 58,	\
	58, 67, 59, 59, 67, 68, 59, 68, 60, 60, 68, 69, 60, 69, 70, 60, 70, 61

#define TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT 22*3
#define TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT (SGPTT_TILENUM-1)*(SGPTT_TILENUM-1)*2*3




static uint16 base_index_tile[] = { TERRAIN_CHUNK_INDEX_LOD0 };
static uint16 lod1_index_tile[] = { TERRAIN_CHUNK_INDEX_LOD1 };

static uint16 chunk_index_tile[] = { 
	TERRAIN_CHUNK_INDEX_LOD0,

	//TERRAIN_CHUNK_INDEX_LODLINK_UP,	TERRAIN_CHUNK_INDEX_LOD_UP,
	//TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM, TERRAIN_CHUNK_INDEX_LOD_BOTTOM,
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFT, TERRAIN_CHUNK_INDEX_LOD_LEFT,
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHT, TERRAIN_CHUNK_INDEX_LOD_RIGHT,
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP, TERRAIN_CHUNK_INDEX_LOD_LEFTUP,
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP, TERRAIN_CHUNK_INDEX_LOD_RIGHTUP,
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM, TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM,
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM, TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM,
	//TERRAIN_CHUNK_INDEX_LODLINK_SIDE, TERRAIN_CHUNK_INDEX_LOD_SIDE,

	TERRAIN_CHUNK_INDEX_LOD1 };

static uint32 chunk_index_count = TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	//TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT +
	//TERRAIN_CHUNK_INDEX_LODLINK_SIDE_COUNT + TERRAIN_CHUNK_INDEX_LOD_SIDE_COUNT +
	TERRAIN_CHUNK_INDEX_LOD1_COUNT;


static SGPTerrainChunkIndexInfo chunk_base_level_0 = 
{
	SGPTCS_LOD0,

	0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};

static SGPTerrainChunkIndexInfo chunk_base_level_1 = 
{
	SGPTCS_LOD1,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT/* + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_SIDE_COUNT + TERRAIN_CHUNK_INDEX_LOD_SIDE_COUNT*/,

	TERRAIN_CHUNK_INDEX_LOD1_COUNT
};

/*
static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_up = 
{
	SGPTCS_LOD1TOLOD0_UP,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_up =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT
};


static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_bottom =
{
	SGPTCS_LOD1TOLOD0_BOTTOM,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_bottom =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT
};


static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_left =
{
	SGPTCS_LOD1TOLOD0_LEFT,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_left =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT
};

static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_right =
{
	SGPTCS_LOD1TOLOD0_RIGHT,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_right =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT
};

static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_leftup =
{
	SGPTCS_LOD1TOLOD0_LEFTUP,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_leftup =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT
};


static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_rightup =
{
	SGPTCS_LOD1TOLOD0_RIGHTUP,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_rightup =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT
};


static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_leftbottom =
{
	SGPTCS_LOD1TOLOD0_LEFTBOTTOM,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_leftbottom =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT
};



static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_rightbottom =
{
	SGPTCS_LOD1TOLOD0_RIGHTBOTTOM,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_rightbottom =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT
};



static SGPTerrainChunkIndexInfo chunk_base_level_1_to_0_side =
{
	SGPTCS_LOD1TOLOD0_SIDE,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_SIDE_COUNT + TERRAIN_CHUNK_INDEX_LOD_SIDE_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_side =
{
	SGPTCS_LOD0,

	TERRAIN_CHUNK_INDEX_LOD0_COUNT + 
	TERRAIN_CHUNK_INDEX_LODLINK_UP_COUNT + TERRAIN_CHUNK_INDEX_LOD_UP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_BOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_BOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFT_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHT_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHT_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTUP_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTUP_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_LEFTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_LEFTBOTTOM_COUNT +
	TERRAIN_CHUNK_INDEX_LODLINK_RIGHTBOTTOM_COUNT + TERRAIN_CHUNK_INDEX_LOD_RIGHTBOTTOM_COUNT,

	TERRAIN_CHUNK_INDEX_LODLINK_SIDE_COUNT + TERRAIN_CHUNK_INDEX_LOD_SIDE_COUNT
};
*/


/*
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_up = 
{
	SGPTCS_LOD0TOLOD1_UP,
	0,
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_bottom = 
{
	SGPTCS_LOD0TOLOD1_BOTTOM,
	0,
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_left = 
{
	SGPTCS_LOD0TOLOD1_LEFT,
	0,
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_right = 
{
	SGPTCS_LOD0TOLOD1_RIGHT,
	0,
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_leftup = 
{
	SGPTCS_LOD0TOLOD1_LEFTUP,
	0,
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_rightup = 
{
	SGPTCS_LOD0TOLOD1_RIGHTUP,
	0, 
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_leftbottom = 
{
	SGPTCS_LOD0TOLOD1_LEFTBOTTOM,
	0, 
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_rightbottom = 
{
	SGPTCS_LOD0TOLOD1_RIGHTBOTTOM,
	0, 
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
static SGPTerrainChunkIndexInfo chunk_base_level_0_to_1_side = 
{
	SGPTCS_LOD0TOLOD1_SIDE,
	0, 
	TERRAIN_CHUNK_INDEX_LOD0_COUNT
};
*/

static uint16 border_index_tile_horizontal_left[] = 
{
	0, 9, 18, 27, 36, 45, 54, 63, 72
};

static uint16 border_index_tile_horizontal_right[] = 
{
	8, 17, 26, 35, 44, 53, 62, 71, 80
};

static uint16 border_index_tile_vertical_up[] = 
{
	0, 1, 2, 3, 4, 5, 6, 7, 8
};

static uint16 border_index_tile_vertical_down[] = 
{
	72, 73, 74, 75, 76, 77, 78, 79, 80
};





#endif		// __SGP_TERRAINTILESHAPE_HEADER__