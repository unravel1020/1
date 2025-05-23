#ifdef __cplusplus
#define EXPORT extern "C" __declspec (dllexport)
#else
#define EXPORT __declspec (dllexport)
#endif 

#include "math.h"  
#include "vmath.h"  
using namespace vmath;
//////////////////////////////////////////////////////////////////////////自动生成物体数据定义//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_BZP_BASEMOD_NUM                 500      //普通标志最大基础模型数
#define W3D_MAX_BZP_MOD_NUM                          1000    //普通标志最大模型数
#define W3D_MAX_DMBZ_BASEMOD_NUM             100      //地面标志最大基础模型数
#define W3D_MAX_DMBZ_MOD_NUM                      1000    //地面标志最大模型数
#define W3D_MAX_DMBH_BASEMOD_NUM             100      //病害最大基础模型数
#define W3D_MAX_DMBH_MOD_NUM                      1000      //病害最大模型数
#define W3D_MAX_DMBX_BASEMOD_NUM             100      //地面标线最大基础模型数
#define W3D_MAX_DMBX_MOD_NUM                      1000      //地面标线最大模型数
#define W3D_MAX_HL_BASEMOD_NUM             100      //护栏最大基础模型数
#define W3D_MAX_HL_MOD_NUM                      1000      //护栏最大模型数
#define W3D_MAX_KBBZ_BASEMOD_NUM             100      //可变标志最大基础模型数
#define W3D_MAX_KBBZ_MOD_NUM                      1000      //可变标志最大模型数
#define W3D_MAX_LC_BASEMOD_NUM             500      //路产最大基础模型数
#define W3D_MAX_LC_MOD_NUM                      3000      //路产最大模型数
#define W3D_MAX_ExRoad_MOD_NUM                      100      //额外道路最大模型数
//////////////////////////////////////////////////////////////////////////数据定义//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_DTMOD_NUM                             1000       //最大支持的动态模型数量
#define W3D_MAX_DTMOD_TEX_NUM                    1000        //单个动态模型最大的纹理数量
#define W3D_MAX_YZCJ_MOD_NUM                        1000      //预置场景最大模型数

#define W3D_MAX_DbClkLimRg_MOD_NUM                              500      //双击限制物体最大数量

#define W3D_MAX_MAIN_RENDER_TEX_NUM 8//主渲染最大纹理数

#define W3D_MAX_DY_TRAFFIC_OBJECT_NUM     1000      //最大动态交通目标数量
#define W3D_DyTraObj_MAX_FRAME_POOL_NUM  1000     //动态交通元素数据帧缓冲池最大数量
#define W3D_MAX_DyTraObj_MOD_N                        500       //动态交通元素模型最大数量

#define W3D_MAX_UserPlugInDLL_N                           500     //最大支持加载的用户第三方DLL数量

#define W3D_MAX_EVENT_DELAY_N                        1000     //最大延时的事件个数

#define W3D_MAX_PT_MOD_NUM                              1000      //普通模型最大模型数
#define W3D_MAX_FM_MOD_NUM                              500      //封面模型最大模型数
#define W3D_MAX_PLAYER_MOTION_NUM              500      //用户最大操作数
#define GroupMod_ID_Num                                            1000    //一个复合模型中最多可以有1000个子模型
#define W3D_MAX_GROUP_MOD_NUM                      1000    //最大复合模型数量
#define W3D_MAX_CUBEMAP_TEXSIZE                     8192      //最大立方图纹理尺寸
#define W3D_MAX_COLLD_MOD_NUM                      1000      //最大碰撞模型数量
#define W3D_MAX_DLIGHT_GENSHADOW_NUM   5//最大D光源阴影发生数量为5
#define W3D_MAX_SLIGHT_GENSHADOW_NUM   5//最大S光源阴影发生数量为5
#define W3D_MAX_CLIGHT_GENSHADOW_NUM   5//最大C光源阴影发生数量为5
#define W3D_MAX_SHADOW_NUM                            W3D_MAX_DLIGHT_GENSHADOW_NUM + W3D_MAX_SLIGHT_GENSHADOW_NUM + W3D_MAX_CLIGHT_GENSHADOW_NUM     //最大的阴影数量 (方向5+点光5+聚光5)      
#define W3D_MAX_DLIGHT_NUM                               64//最大D光源数量为64
#define W3D_MAX_SLIGHT_NUM                               64//最大S光源数量为64
#define W3D_MAX_CLIGHT_NUM                               64//最大C光源数量为64
#define W3D_MAX_BasicGraph_Memory_Size               10000//基础图形最大内存大小
#define W3D_MAX_MOD_ROT_SERL_N                     50//物体旋转最多序列数
#define W3D_MAX_MAINWIN_TITLEWORD_LEN     100//主窗口最大标题文字长度
#define W3D_MAX_SYSERRORSTATUSINFO_NUM             1000      //最大系统错误状态信息数量
#define W3D_MAX_MSGLIST_LEN             1000      //最大消息列表长度
//////////////////////////////////////////////////////////////////////////消息定义//////////////////////////////////////////////////////////////////////////
#define WM_W3DMSG                                                     WM_USER + 0x00001000 //转发消息基准
//////////////////////////////////////////////////////////////////////////路径长度//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_PATH_LEN                                                     500//最大路径长度

//////////////////////////////////////////////////////////////////////////鼠标按钮信息//////////////////////////////////////////////////////////////////////////
#define W3D_MOUSEMOVE_STATUS 0
#define W3D_MOUSEWHEEL_STATUS 1
#define W3D_LBUTTONDOWN_STATUS 2
#define W3D_LBUTTONUP_STATUS 3
#define W3D_MBUTTONDOWN_STATUS 4
#define W3D_MBUTTONUP_STATUS 5
#define W3D_RBUTTONDOWN_STATUS 6
#define W3D_RBUTTONUP_STATUS 7
#define W3D_LBUTTONDBLCLK_STATUS 8
#define W3D_RBUTTONDBLCLK_STATUS 9

//////////////////////////////////////////////////////////////////////////鼠标按钮信息//////////////////////////////////////////////////////////////////////////
#define W3D_LBUTTON_STATUS 0
#define W3D_RBUTTON_STATUS 1

//////////////////////////////////////////////////////////////////////////动画播放状态//////////////////////////////////////////////////////////////////////////
#define W3D_ANIM_STATUS_PLAY 1  //动画正在播放
#define W3D_ANIM_STATUS_END 2  //动画已播放完毕
#define W3D_ANIM_STATUS_STOP 3  //动画被停止 

//////////////////////////////////////////////////////////////////////////声音播放状态//////////////////////////////////////////////////////////////////////////
#define MAX_PLAYSOUNDTHREAD_N 20//最大的声音播放线程数
#define W3D_SOUND_STATUS_PLAY 1  //声音正在播放
#define W3D_SOUND_STATUS_END 2  //声音已播放完毕 

//////////////////////////////////////////////////////////////////////////物体类型定义//////////////////////////////////////////////////////////////////////////
#define W3D_SCENE_MOD 1//场景物体
#define W3D_PT_MOD 2//PT物体
#define W3D_FM_MOD 3//封面物体

///////////LOD信息结构////////////////////////////
struct LODInfo
{
	float         fLODStart;//LOD层级起始距离
	DWORD dwLODTexScl;//LOD层级的纹理缩放
};

///////////颜色预处理参数结构////////////////////////////
struct ColPreProcParamInfo
{
	BOOL   bSetClrCol;//设置颜色清除功能
	float     fClrColR;//清空颜色R分量
	float     fClrColG;//清空颜色G分量
	float     fClrColB;//清空颜色B分量
	float     fClrColA;//清空颜色A分量
	BOOL   bSetGryScl;//设置颜色灰度化功能
    	DWORD dwGrySclMode;//灰度化方式
	BOOL   bSetHgLgtExt;//设置高光提取功能
	float     fHgLgtExtLowThrhld;//高光提取低阈值
	float     fHgLgtExtHgThrhld;//高光提取高阈值
};

/////////////////////////////////////引擎消息类型/////////////////////////////////////
struct W3DMsgInfo
{
	UINT uMsg;
	ULONGLONG wParam;
	LONGLONG    lParam;
};

////////////////////////////////////////系统性能信息////////////////////////////////////////
struct W3DSysPerformanceInfo
{
	DWORD dwRenderFPS;//渲染FPS
	DWORD dwFrameStreamFPS;//推流FPS
};

////////////////////////////////////////阴影设置信息////////////////////////////////////////
struct ShadowInfo
{
	DWORD dwShadowTraceModID;
	BOOL bShadowAbsLightPos;
	BOOL bShadowTraceUser;
	float   fShadowRenderFOV;
	float   fShadowNearPlane;
	float   ShadowOffsetX;
	float   ShadowOffsetY;
	float   fShadowViewDis;
	float   fShadowDis;
	float ShadowMinBias;
	float ShadowMaxBias;
	float ShadowContrast;
	float ShadowStartLightPosX;
	float ShadowStartLightPosY;
	float ShadowStartLightPosZ;
	float ShadowEndLightPosX;
	float ShadowEndLightPosY;
	float ShadowEndLightPosZ;
};

////////////////////////////////////////////引擎系统错误状态格式////////////////////////////////////////////
struct W3DSysErrorStatusInfo
{
	DWORD dwErrorStatusCode;//错误状态码
	DWORD dwSubErrorStatusCode;//子错误状态码
        BOOL      bValid;//内部使用
};

////////////////////////////////////////////模型包络结构体////////////////////////////////////////////
struct W3DModEnvelopeInfo
{
	vec3 vEnvPoint[9];//1个中心点+8个盒子包络顶点
};

////////////////////////////////////////////用户公共数据定义声明////////////////////////////////////////////
#define W3D_COMMON_USER_DATA_MAX_LEN      1000//每个公共数据最大长度
#define W3D_COMMON_USER_DATA_MAX_STRING_LEN      100//公共数据中最大字符串长度
#define W3D_COMMON_USER_DATA_TYPE_BOOL      1//bool类型
#define W3D_COMMON_USER_DATA_TYPE_INT          2//int类型
#define W3D_COMMON_USER_DATA_TYPE_DWORD 3//DWORD类型
#define W3D_COMMON_USER_DATA_TYPE_FLOAT    4//float类型
#define W3D_COMMON_USER_DATA_TYPE_DOUBLE 5//double类型
#define W3D_COMMON_USER_DATA_TYPE_CHAR     6//char类型
#define W3D_COMMON_USER_DATA_TYPE_WCHAR 7//wchar类型

////////////////////////////////////////////普通模型自定义状态信息////////////////////////////////////////////
struct PTModCustomInfo
{
	char         szInRoadSec[50];//所属路段
	DWORD dwStatus;//运行状态
};

////////////////////////////////////////////动态交通元素帧格式///////////////////////////////////////////////
struct DyTraObjFrameData
{ 
	DWORD vehicleId;//车辆id
	WCHAR plateNo[50];//车牌号
	LONGLONG timeStamp;//帧时间戳
	double     lon;//车辆经度
	double     lat;//车辆纬度
	double     ele;//车辆高度
	DWORD speed;//车辆速度
	DWORD heading;//车辆航线角
	DWORD wid;//车辆宽
	DWORD len;//车辆长
	DWORD hei;//车辆高
	DWORD basicVehicleClass;
	DWORD fuelType;//车辆燃料类型
	DWORD fuelN;//剩余燃料数量
	///////////////插件内部使用//////////////
	BOOL     bFrameValid;//帧是否有效
	///////////////////////////////////////////////////////
};
//////////建立三维场景预置信息集////////
struct W3DBuildInfo
{
	/////////////分辨率设置///////////
	int iWid;//窗口宽
	int iHei;//窗口高 
	/////////////默认位置设置///////////
	int iPosX;//窗口位置x
	int iPosY;//窗口位置y
	/////////////加载场景号///////////
	DWORD dwSelScene;
};
//GPS基础校准信息
struct GPSCalibInfo
{
	//GPS基准XYZ
	float fGPSjzx;
	float fGPSjzy;
	float fGPSjzz;
	//GPS基准放大XYZ
    float fGPSdx;
	float fGPSdy;
	float fGPSdz;
};
//普通标志选择信息
struct BzpSelInfo
{ 
	DWORD bzpN;//普通标志种类数量
	DWORD id;//此目标的序号
	float        x;
	float        y;
	float        z;
	float        ra;
	DWORD dwType;
};
//可变标志选择信息
struct KBBZSelInfo
{ 
	DWORD kbbzN;//可变标志种类数量
	DWORD id;//此目标的序号
	float        x;
	float        y;
	float        z;
	float        wid;
	float        hei;
	float        ra;
	DWORD type;
};
//护栏选择信息
struct HLSelInfo
{ 
	DWORD hlN;//护栏种类数量
	DWORD id;//此目标的序号
	float        startx;
	float        starty;
	float        startz;
	float        endx;
	float        endy;
	float        endz;
	DWORD type;
};
//地面标线选择信息
struct DMBXSelInfo
{ 
	DWORD dmbxN;//地面标线种类数量
	DWORD id;//此目标的序号
	float        startx;
	float        starty;
	float        startz;
	float        endx;
	float        endy;
	float        endz;
	DWORD type;
};

//地面标志选择信息
struct DMBZSelInfo
{ 
	DWORD dmbzN;//地面标志种类数量
	DWORD id;//此目标的序号
	float         x;
	float         y;
	float         z;
	float         len;
	float         wid;
	DWORD type;
};   

//病害选择信息
struct BHSelInfo
{ 
	DWORD bhN;//病害种类数量
	DWORD id;//此目标的序号
	float         x;
	float         y;
	float         z;
	float         len;
	float         wid;
	DWORD type;
};   

//路产选择信息
struct LCSelInfo
{ 
	DWORD LCN;//路产种类数量
	DWORD id;//此目标的序号
	float        x;
	float        y;
	float        z;
	float        sx;
	float        sy;
	float        sz;
	float        ra;
	DWORD dwType;
};
//观察者信息
struct ViewUserInfo
{ 
	//观察者用户当前位置坐标
	float posX;
	float posY;
	float posZ;
	//观察者用户看远处的位置坐标
	float farposX;
	float farposY;
	float farposZ;
	//观察者视角
	float fViewAng;
}; 

//道路信息
struct RoadInfo
{
	float                  fRoadLaneWid;//车道宽
	DWORD          dwRoadLaneN;//车道数量
};

//总选择信息结构体
struct W3DSelectedObjInfo
{
	DWORD        type;
	BzpSelInfo      bzpinfo;
	KBBZSelInfo  kbbzinfo;
	LCSelInfo       lcinfo;
	HLSelInfo       hlinfo;
	DMBXSelInfo dmbxinfo;
	DMBZSelInfo dmbzinfo;
	BHSelInfo       bhinfo;
	DWORD         ptmodid;
	DWORD         scenemodid;
	DWORD         fmmodid;
};

#define W3D_USER_LOAD_TEX_STATUS_NONE 0//用户此次读取纹理操作没有状态
#define W3D_USER_LOAD_TEX_STATUS_FAILED 1//用户此次读取纹理操作失败
#define W3D_USER_LOAD_TEX_STATUS_SUCCESS 2//用户此次读取纹理操作成功
#define W3D_USER_LOAD_TEX_STATUS_FINISH 3//用户此次读取纹理操作已完成

//用户加载纹理贴图信息
struct W3DUserLoadTexInfo
{
	int            iTexLevel;//纹理层级
	BOOL     bTexRGBScale;//纹理是否启用RGB缩放
	float         fTexScaleR;//纹理缩放R分量
	float         fTexScaleG;//纹理缩放G分量
	float         fTexScaleB;//纹理缩放B分量
	DWORD dwTexIndex;//加载的纹理索引
	char         szTexFilePath[MAX_PATH];//纹理文件路径
};

//获得封面物体加载贴图状态
EXPORT BOOL W3DGetFMModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//获得PT物体加载贴图状态
EXPORT BOOL W3DGetPTModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//获得场景物体加载贴图状态
EXPORT BOOL W3DGetSceneModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//场景物体加载贴图
EXPORT BOOL W3DSceneModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//PT物体加载贴图
EXPORT BOOL W3DPTModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//FM物体加载贴图
EXPORT BOOL W3DFMModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//设置场景物体雾穿透率
EXPORT BOOL W3DSetSceneModFogPenetrate(DWORD dwModID,float fFgPentrt);

//设置PT物体雾穿透率
EXPORT BOOL W3DSetPTModFogPenetrate(DWORD dwModID,float fFgPentrt);

//设置封面物体雾穿透率
EXPORT BOOL W3DSetFMModFogPenetrate(DWORD dwModID,float fFgPentrt);

//设置场景清除颜色
EXPORT BOOL W3DSetSceneClearColor(float fColR,float fColG,float fColB,float fColA);

//设置渲染FOV
EXPORT BOOL W3DSetRenderFOV(float fFOV);

//设置渲染近平面
EXPORT BOOL W3DSetRenderNearPlane(float fNearPlane);

//设置用户视线范围
EXPORT BOOL W3DSetUserViewRange(float fViewRange);

//设置场景物体组的位置(间接改变)
EXPORT BOOL W3DSetSceneModGroupPosIndirectly(DWORD dwModNum,
																					   DWORD* pdwModIDList,
																					   DWORD* pdwChangeTransModeList,
																					   DWORD* pdwChangeRotModeList,
																					   DWORD* pdwChangeSclModeList,
																					   vec3* pvTransList,
																					   vec4* pvRotList,
																					   vec3* pvSclList);

//设置PT物体组的位置(间接改变)
EXPORT BOOL W3DSetPTModGroupPosIndirectly(DWORD dwModNum,
																				   DWORD* pdwModIDList,
																				   DWORD* pdwChangePosModeList,
																				   DWORD* pdwChangeTransModeList,
																				   vec3* pvTransList,
																				   mat4* pmTransList,
																				   DWORD* pdwChangeRotModeList,
																				   vec4* pvRotList,
																				   mat4* pmRotList,
																				   DWORD* pdwChangeRotSelModeList,
																				   DWORD* pdwRoSerlNList,
																				   vec4** pvRoSerlList,
																				   DWORD* pdwChangeSclModeList,
																				   vec3* pvSclList,
																				   mat4* pmSclList);

//设置基础图形颜色后处理信息
EXPORT BOOL W3DSetBasicGraphColPostProcInfo(DWORD   dwClPstProcN,
																					DWORD* pdwClPstProcID);

//设置PT物体的位置(间接改变)
EXPORT BOOL W3DSetPTModPosIndirectly(DWORD dwModID,
																		 DWORD dwChangePosMode,
																		 DWORD dwChangeTransMode,
																		 vec3 vTrans,
																		 mat4 mTrans,
																		 DWORD dwChangeRotMode,
																		 vec4 vRot,
																		 mat4 mRot,
																		 DWORD dwChangeRotSelMode,
																		 DWORD dwRoSerlN,
																		 vec4* vRoSerl,
																		 DWORD dwChangeSclMode,
																		 vec3 vScl,
																		 mat4 mScl);


//获得封面模型的旋转序列
EXPORT BOOL W3DGetFMModRoSerl(DWORD dwModID,
																DWORD* pdwRoSerlN,
																vec4*      pvRoSerl);


//设置封面模型的旋转序列
EXPORT BOOL W3DSetFMModRoSerl(DWORD dwModID,
																DWORD dwRoSerlN,
																vec4*      vRoSerl);

//设置场景物体的位置(间接改变)
EXPORT BOOL W3DSetSceneModPosIndirectly(DWORD dwModID,
																			 DWORD dwChangeTransMode,
																			 DWORD dwChangeRotMode,
																			 DWORD dwChangeSclMode,
																			 vec3 vTrans,vec4 vRot,vec3 vScl);

//高精度延时
EXPORT BOOL W3DHighPrecisionDelay(LONGLONG llDelayTime);

//设置动态物理物体对指定物理物体的碰撞检测有效性
EXPORT BOOL W3DSetColldCheckOnMod(DWORD dwModID,
																	   DWORD dwOnModType,
																	   DWORD dwOnModID,
																	   BOOL     bColldCheck,
																	   BOOL     bClldChckValid);

//设置LOD信息
EXPORT BOOL W3DSetLODInfo(DWORD dwLODType,DWORD dwSetLODLevel,LODInfo* pstLODInfo);

//设置引擎全局贴图缩放
EXPORT BOOL W3DSetGlobalTextureScale(DWORD dwTexScl);

//获得场景物体位置信息
EXPORT BOOL W3DGetSceneModPosInfo(DWORD dwModID,vec3* pvTrans,vec4* pvRot,vec3* pvScl);

//设置渲染帧率限制
EXPORT BOOL W3DSetRenderFPSLimit(BOOL bEnableMaxRdrFPSlim,DWORD dwMaxRdrFPSlim,    
									BOOL bEnableMinRdrFPSlim,DWORD dwMinRdrFPSlim);

//设置场景物体颜色预处理后处理功能
EXPORT BOOL W3DSetSceneModColPrePostProc(DWORD  dwModID,
																				  DWORD  dwColPostProcN,
																				  DWORD* pdwColPostProcIDList,
																				  DWORD* pdwColPreProcFuncList,
																				  float*         pfColPreProcAlphaList);

//设置PT物体颜色预处理后处理功能
EXPORT BOOL W3DSetPTModColPrePostProc(DWORD  dwModID,
																			 DWORD  dwColPostProcN,
																			 DWORD* pdwColPostProcIDList,
																			 DWORD* pdwColPreProcFuncList,
																			 float*         pfColPreProcAlphaList);

//设置封面物体颜色预处理后处理功能
EXPORT BOOL W3DSetFMModColPrePostProc(DWORD  dwModID,
																			  DWORD  dwColPostProcN,
																			  DWORD* pdwColPostProcIDList,
																			  DWORD* pdwColPreProcFuncList,
																			  float*         pfColPreProcAlphaList);

//设置颜色预处理参数
EXPORT BOOL W3DSetColPreProcInfo(ColPreProcParamInfo* pstColPrePrcPrm); 

//设置用户控制物体运动灵敏度模式
EXPORT BOOL W3DSetUserCrtlModMoveSensi(float fSensi);

//设置用户控制物体运动速度
EXPORT BOOL W3DSetUserCrtlModMoveSpeed(BOOL bChangeFBSpd,
                                                                        		float   fFBSpd,    
											BOOL bChangeLRSpd,
                                                                  		        float   fLRSpd, 
											BOOL bChangeFastSpd,
                                                           		                float   fFastSpd);

//设置推流模式
EXPORT BOOL W3DSetFrameStreamMode(DWORD dwFrmStrmMode);

//设置推流速度
EXPORT BOOL W3DSetFrameStreamSpeed(DWORD dwFrmStrmSpeed);

//获得系统的性能信息
EXPORT BOOL W3DGetSysPerformanceInfo(W3DSysPerformanceInfo* pstSysPerfInfo);

//设置主窗口显示模式
EXPORT BOOL W3DSetMainWinShowMode(DWORD dwMode);

//设置主窗口位置
EXPORT BOOL W3DSetMainWinPos(int iWinX,int iWinY,int iWinWid,int iWinHei);

//设置引擎系统语言
EXPORT BOOL W3DSetSysLanguage(DWORD dwLanguageCode);

//异步方式启动引擎
EXPORT BOOL W3DAsynProxy(WCHAR* wszAppPath,HWND hParentHwnd, W3DBuildInfo* pstW3DBuildInfo);

//设置选择模式
EXPORT BOOL W3DSetSelectMode(BOOL bChangeMode,DWORD dwSelMode,
						  		 BOOL bChangeInputMode,DWORD dwInputMode);

//用户视点追踪PT物体
EXPORT BOOL W3DUserViewTracePTMod(DWORD dwTraceModID,
							     		     float fTracePosX,float fTracePosY,float fTracePosZ,
							    		     float fTraceFarPosX,float fTraceFarPosY,float fTraceFarPosZ);

//查询用户光标显示状态
EXPORT BOOL W3DGetUserCursorShow(BOOL* pbOnHide);

//显示用户光标
EXPORT BOOL W3DShowUserCursor(BOOL bShow);

//获得最近的错误码
EXPORT BOOL W3DGetLastError(DWORD* pdwErrorCode);

//设置全局模式下的操控模式
EXPORT BOOL W3DSetOpnModeOnGV(BOOL bChangeOpnMode,DWORD dwOpnMode,BOOL bChangeDbClkMode,BOOL bDbClkEnable);

//按屏幕位置选择物体
EXPORT BOOL W3DSelectModFromScrPos(int iScrPosX,int iScrPosY);

//设置PT模型的纹理ID
EXPORT BOOL W3DSetPTModTexID(DWORD dwModID,DWORD dwTexModID);

//设置PT模型使用纹理组中的哪一个
EXPORT BOOL W3DSetPTModTexFromTexGroup(DWORD dwModID,DWORD dwTexIDInTexGroup);


//设置场景物体的纹理ID
EXPORT BOOL W3DSetSceneModTexID(DWORD dwModID,DWORD dwTexModID);

//设置阴影信息
EXPORT BOOL W3DSetShadowInfo(DWORD dwShaID,ShadowInfo* pstShaInfo);

//设置碰撞检测距离
EXPORT BOOL W3DSetColldCheckDis(float fColldDis);

//判断一点是否在一个物体内
EXPORT BOOL W3DCheck3DPointInMod(DWORD dwModID,
							                                 DWORD dwModType,
															 mat4 mModMatrix,
															 vec3 vCheck3DPoint);


//设置PT物体是否为动态物理物体控制物体
EXPORT BOOL W3DSetPTModDyPhyCtrlMod(DWORD dwModID,DWORD dwMode);

//设置PT物体是否为动态物理物体
EXPORT BOOL W3DSetPTModDyPhyMod(DWORD dwModID,DWORD dwMode);

//设置场景物体虚拟颜色
EXPORT BOOL W3DSetSceneModVirtualColor(DWORD dwModID,
																	float fColR,
																	float fColG,
																	float fColB,
																	float fColA);

//设置场景物体基础颜色
EXPORT BOOL W3DSetSceneModBasicColor(DWORD dwModID,
																  float fColR,
																  float fColG,
																  float fColB,
																  float fColA);

//设置路产模型的旋转序列
EXPORT BOOL W3DSetLCModRoSerl(DWORD dwModID,
						                                DWORD dwRoSerlN,
														vec4*      vRoSerl);

//设置地面标志的基础颜色
EXPORT BOOL W3DSetDMBZBasicColor(DWORD dwModID,
															 DWORD dwMode,
															 float fColR,float fColG,float fColB,float fColA);

//设置地面病害的基础颜色
EXPORT BOOL W3DSetDMBHBasicColor(DWORD dwModID,
															 DWORD dwMode,
															 float fColR,float fColG,float fColB,float fColA);

//设置普通标志的基础颜色
EXPORT BOOL W3DSetBzpBasicColor(DWORD dwModID,
							                            DWORD dwMode,
													    float fColR,float fColG,float fColB,float fColA);

//设置路产的基础颜色
EXPORT BOOL W3DSetLCBasicColor(DWORD dwModID,
							                           DWORD dwMode,
													   float fColR,float fColG,float fColB,float fColA);

//设置地面标线的基础颜色
EXPORT BOOL W3DSetDMBXBasicColor(DWORD dwModID,
																			 DWORD dwMode,
																			 float fColR,float fColG,float fColB,float fColA);

//设置护栏的基础颜色
EXPORT BOOL W3DSetHLBasicColor(DWORD dwModID,
																	   DWORD dwMode,
																	   float fColR,float fColG,float fColB,float fColA);

//设置可变标志的基础颜色
EXPORT BOOL W3DSetKBBZBasicColor(DWORD dwModID,
																			DWORD dwMode,
																			float fColR,float fColG,float fColB,float fColA);

//设置PT物体的选择模式
EXPORT BOOL W3DSetPTSelectMode(DWORD dwModID,DWORD dwMode);

//设置场景物体的选择模式
EXPORT BOOL W3DSetSceneModSelectMode(DWORD dwModID,DWORD dwMode);

//设置封面物体的选择模式
EXPORT BOOL W3DSetFMModSelectMode(DWORD dwModID,DWORD dwMode);

//设置选择点的位置
EXPORT BOOL W3DSetSelectPointPos(int x,int y);

//获得当前场景编号
EXPORT BOOL W3DSetCurrentSceneIdentity(DWORD* pdwSceneID);

//设置用户控制物体视点转动速度
EXPORT BOOL W3DSetUserCrtlModViewRotSpeed(BOOL bChangeRotSpeed,
									                                        float     fRotSpeed,
																			BOOL bChangeUpDnViewRotSpeed,
																			float     fUpDnViewRotSpeed,
																			BOOL bChangeFarUpDnViewRotSpeed,
																			float     fFarUpDnViewRotSpeed);

//设置用户控制物体的模式
EXPORT BOOL W3DSetUserCrtlModMode(DWORD dwCtrlMode,
													  DWORD dwCtrlModID,
						                              DWORD dwViewMode,
													  BOOL bResetViewPos);

//获得道路信息
EXPORT BOOL W3DGetRoadInfo(RoadInfo* pInfo);

//更新道路模型信息
EXPORT BOOL W3DUpdateRoadMod(BOOL               bUpdateVer,
													   float*                 pfRdVerMemory,
													   DWORD           dwRdVerMemSize,
													   BOOL               bUpdateTex,
													   float*                 pfRdTexMemory,
													   DWORD           dwRdTexMemSize,
													   BOOL               bUpdateNor,
													   float*                 pfRdNorMemory,
													   DWORD           dwRdNorMemSize);

//获得渲染的道路GPS点
EXPORT BOOL W3DGetRoadRenderGPSPoint(DWORD* pdwMemSize,
								                                    float*         pfMemory,
																	DWORD* dwRenderSegN);

//获得道路原始GPS点
EXPORT BOOL W3DGetRoadOrignGPSPoint(DWORD* pdwMemSize,
								                                  float*         pfMemory,
																  DWORD* dwOrignSegN);

//计算两个gps点之间的距离
EXPORT double W3DCalcGPSPointDistance(double dGPSLat1, double dGPSLng1, double dGPSHei1,
								                               double dGPSLat2, double dGPSLng2, double dGPSHei2,
															   double dEarthRadius);

//设置基础图形的点大小线宽度
EXPORT BOOL W3DSetBasicGraph(float fSize,float fWidth);

//更新基础图形信息
EXPORT BOOL W3DUpdateBasicGraphInfo(DWORD dwPointN,
															   DWORD dwPointStartPos,
															   DWORD dwLineN,
															   DWORD dwLineStartPos,
															   DWORD dwTriangleN,
															   DWORD dwTriangleStartPos,
															   float*       pfVertexMemory, 
															   DWORD dwVertexMemSize,
															   float*       pfColorMemory,
															   DWORD dwColorMemSize);

//获得场景偏移
EXPORT BOOL W3DGetSceneOffset(float* poffsetX,
													 float* poffsetY,
													 float* poffsetZ);

//获得光标在仿真界面中的坐标
EXPORT BOOL W3DGetScreenCursorPos(DWORD* pdwX,DWORD* pdwY);

//屏幕2D坐标转世界3D坐标
EXPORT BOOL W3DGen3DPosFromScreenPos(int x, int y,
																			float* pdpox,float* pdpoy,float* pdpoz,
																			float* plocdpox,float* plocdpoy,float* plocdpoz);

//停止查询所有普通模型渲染的信息
EXPORT BOOL W3DStopInquireALLPTModRenderInfo();

//停止普通模型渲染的信息
EXPORT BOOL W3DStopInquirePTModRenderInfo(DWORD  dwInquireType);

//查询普通模型渲染的信息
EXPORT BOOL W3DInquirePTModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//停止查询所有地面标志模型渲染的信息
EXPORT BOOL W3DStopInquireALLDMBZModRenderInfo();

//停止查询地面标志模型渲染的信息
EXPORT BOOL W3DStopInquireDMBZModRenderInfo(DWORD  dwInquireType);

//查询地面标志模型渲染的信息
EXPORT BOOL W3DInquireDMBZModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//停止查询所有路产模型渲染的信息
EXPORT BOOL W3DStopInquireALLLCModRenderInfo();

//停止查询路产模型渲染的信息
EXPORT BOOL W3DStopInquireLCModRenderInfo(DWORD  dwInquireType);

//查询路产模型渲染的信息
EXPORT BOOL W3DInquireLCModRenderInfo(DWORD  dwInquireType,
																	DWORD  dwInquireModN,
																	DWORD* pdwReturnModN,
																	mat4*        pmReturnMatrix,
																	BOOL*     pbReturnDataFinsh);

//停止查询所有护栏模型渲染的信息
EXPORT BOOL W3DStopInquireALLHLModRenderInfo();

//停止查询护栏模型渲染的信息
EXPORT BOOL W3DStopInquireHLModRenderInfo(DWORD  dwInquireType);

//查询护栏模型渲染的信息
EXPORT BOOL W3DInquireHLModRenderInfo(DWORD  dwInquireType,
																	DWORD  dwInquireModN,
																	DWORD* pdwReturnModN,
																	mat4*        pmReturnMatrix,
																	BOOL*     pbReturnDataFinsh);

//停止查询所有地面标线模型渲染的信息
EXPORT BOOL W3DStopInquireALLDMBXModRenderInfo();

//停止查询地面标线模型渲染的信息
EXPORT BOOL W3DStopInquireDMBXModRenderInfo();

//查询地面标线模型渲染的信息
EXPORT BOOL W3DInquireDMBXModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//停止为PT物体提供多实例渲染的模型矩阵
EXPORT BOOL W3DStopALLPTInstancedModMatrix(DWORD dwTimeOut);

//为PT物体提供多实例渲染的模型矩阵
EXPORT BOOL W3DSetPTInstancedModMatrix(DWORD dwModID,
									                                 mat4*       pmMatrixData,
																	 DWORD dwMatrixN);
//判断两个4x4矩阵是否一样
EXPORT BOOL W3DCompMatrix4x4(mat4 mA,mat4 mB);

//设置场景雾的参数
EXPORT BOOL W3DSetSceneFogInfo(BOOL bOn,vec4 vColor,float fExt,float fInst,
															  vec3 vVertDirt,float fVertDsty,DWORD dwMode,float fMaxDsty,
															  vec3 vOrignPos,DWORD dwOrignMode);

//获得场景雾的参数
EXPORT BOOL W3DGetSceneFogInfo(BOOL* pbOn,vec4* pvColor,float* pfExt,float* pfInst,
															   vec3* pvVertDirt,float* pfVertDsty,DWORD* pdwMode,float* pfMaxDsty,
															   vec3* pvOrignPos,DWORD* pdwOrignMode);

//设置用户物体追踪模式
EXPORT BOOL W3DSetUserViewTraceMode(BOOL bChangeMode,BOOL bOn,
										 BOOL bChangeTraceModID,DWORD dwTraceModID,
										 BOOL bChangeAutoTrace,BOOL bAutoTrace,
										 BOOL bChangeTracePos,
										 float   fTracePosX,float   fTracePosY,float   fTracePosZ,
										 float   fTraceFarPosX,float   fTraceFarPosY,float   fTraceFarPosZ);

//设置用户控制模型的跳跃力量
EXPORT BOOL W3DSetUserCrtlModJumpStrgn(float fJumpStrgn);

//设置渲染的亮度
EXPORT BOOL W3DSetRenderBrightness(float fBrightness);

//设置灰度滤镜效果
EXPORT BOOL W3DSetGrayScaleFilter(BOOL bOn,float fGrayLevel);

//暂停用户对PT物体的控制
EXPORT BOOL W3DPauseUserCrtlMod(BOOL bPause);

//查询封面物体总数量
EXPORT BOOL W3DGetFMModNum(DWORD* pdwNum);

//查询封面物体显示状态
EXPORT BOOL W3DGetFMModShowStatus(DWORD dwModID,DWORD* pdwMode);

//设置封面物体显示
EXPORT BOOL W3DSetFMModShow(DWORD dwModID,DWORD dwMode);

//设置封面模型使用纹理组中的哪一个
EXPORT BOOL W3DSetFMModTexFromTexGroup(DWORD dwModID,DWORD dwTexIDInTexGroup);

//查询动画播放状态
EXPORT BOOL W3DInquireAnimStatus(DWORD   dwModID,
																		DWORD   dwAnimType,
																		DWORD* pdwStatus1,
																		DWORD* pdwStatus2);

//获得动画中的关键点实时位置
EXPORT BOOL W3DSetKeyPointPosInAnim(DWORD   dwModID,
																				DWORD   dwAnimType,
																				DWORD   dwKeyPointN,
																				DWORD*  pdwKeyPointID,
																				vec4*         pReturnKeyPointInfo);

//停止背景音乐
EXPORT BOOL W3DStopBGSound();

//立即播放背景音乐
EXPORT BOOL W3DPlayBGSoundImmly(char*       pszSoundFileName,
						                                    DWORD dwSoundVolume);

//查询背景声音播放状态
EXPORT BOOL W3DInquireBGSoundStatus(DWORD* pdwStatus);

//设置背景音乐音量
EXPORT BOOL W3DSetBGSoundVolume(DWORD dwSoundVolume);

//播放背景音乐
EXPORT BOOL W3DPlayBGSound(char*       pszSoundFileName,
						                                          DWORD dwSoundVolume);
 
//查询声音播放状态
EXPORT BOOL W3DInquireSoundStatus(DWORD dwPlayPosID, DWORD* pdwStatus);

//给指定的物体停止声音
EXPORT BOOL W3DStopModSound(DWORD dwPlayPosID);

//指定的物体从开始播放声音
EXPORT BOOL W3DPlayModSoundFromStartByPos(DWORD   dwModID,
																			 DWORD   dwModType,
																			 DWORD   dwSoundVolume,//初始音量
																			 char*         pszSoundFileName,
																			 BOOL       bPlayByDis,
																			 DWORD   dwPlayPosID,
																			 DWORD   dwPlayDeviceID, 
																			 BOOL       bAddExist,
																			 DWORD   dwDisMode);

//给指定的物体添加声音通过通道
EXPORT BOOL W3DAddModSoundByPlayPos(DWORD   dwModID,
																	 DWORD   dwModType,
								                                     DWORD   dwSoundVolume,//初始音量
																	 char*         pszSoundFileName,
																	 BOOL       bPlayByDis,
																	 DWORD   dwPlayPosID,
																	 DWORD   dwPlayDeviceID, 
																	 BOOL       bAddExist,
																	 DWORD   dwDisMode);

//给指定的PT物体添加声音
EXPORT BOOL W3DAddPTModSound(DWORD   dwModID,
						                                 DWORD   dwSoundVolume,//初始音量
														 char*         pszSoundFileName,
														 BOOL       bPlayByDis,
														 BOOL*     pbSuccessAdd,
														 DWORD* pdwPlayPosID,
														 DWORD   dwDisMode);

//开启用户视点震动模式
EXPORT BOOL W3DUserViewShakeMode(float fRange);

//获得单个的鼠标按钮状态
EXPORT BOOL W3DGetSingleMouseButtonStatus(DWORD dwButtonType,bool* pStatus);

//获得所有的鼠标按钮状态
EXPORT BOOL W3DGetAllMouseButtonStatus(int ListLen,bool* pbStatusList);

//获得单个的鼠标事件状态
EXPORT BOOL W3DGetSingleMouseEventStatus(DWORD dwEventType,bool* pStatus);

//获得所有的鼠标事件状态
EXPORT BOOL W3DGetAllMouseEventStatus(int ListLen,bool* pbStatusList);

//获得单个的按键信息
EXPORT BOOL W3DGetSingleKeyInfo(char key,bool* pResult);

 //获得所有的按键信息
EXPORT BOOL W3DGetKeysInfo(bool* pbKeys);

//立即停止动画
EXPORT BOOL W3DStopAnimImmly(DWORD dwModID,DWORD dwAnimTypeID);

 //停止动画
EXPORT BOOL W3DStopAnim(DWORD dwModID);

//设置普通物体是否绘制文字
EXPORT BOOL W3DSetPTDrawWord(DWORD dwModID,DWORD dwMode);

//设置封面物体是否绘制文字
EXPORT BOOL W3DSetFMDrawWord(DWORD dwModID,DWORD dwMode);

//立即从头播放动画
EXPORT BOOL W3DPlayAnimFromStartImmly(DWORD dwModID,
																					DWORD dwAnimTypeID,
																					DWORD dwPlayInterval,
																					DWORD dwPlayTime,
																					DWORD dwPlayMode,
																					BOOL     bCannotInterrupt);

//立即播放动画
EXPORT BOOL W3DPlayAnimImmly(DWORD dwModID,
																    DWORD dwAnimTypeID,
																    DWORD dwPlayInterval,
																    DWORD dwPlayTime,
																    DWORD dwPlayMode,
																    BOOL     bCannotInterrupt);

//添加播放动画请求
EXPORT BOOL W3DAddAnimRequest(DWORD dwModID,
													   DWORD dwAnimTypeID,
													   DWORD dwPlayInterval,
													   DWORD dwPlayTime,
													   DWORD dwPlayMode,
													   BOOL     bCannotInterrupt);

//添加播放动画列表请求
EXPORT BOOL W3DAddAnimListRequest(DWORD   dwModN,
													 DWORD* pdwModIDList,
													 DWORD* pdwAnimTypeIDList,
													 DWORD* pdwPlayIntervalList,
													 DWORD* pdwPlayTimeList,
													 DWORD* pdwPlayModeList,
													 BOOL*     pbCannotInterruptList);
//立即播放动画列表
EXPORT BOOL W3DPlayAnimListImmly(DWORD   dwModN,
												  DWORD* pdwModIDList,
												  DWORD* pdwAnimTypeIDList,
												  DWORD* pdwPlayIntervalList,
												  DWORD* pdwPlayTimeList,
												  DWORD* pdwPlayModeList,
												  BOOL*     pbCannotInterruptList);
//立即从头播放动画列表
EXPORT BOOL W3DPlayAnimListFromStartImmly(DWORD   dwModN,
																 DWORD* pdwModIDList,
																 DWORD* pdwAnimTypeIDList,
																 DWORD* pdwPlayIntervalList,
																 DWORD* pdwPlayTimeList,
																 DWORD* pdwPlayModeList,
																 BOOL*     pbCannotInterruptList);
//停止动画列表
EXPORT BOOL W3DStopAnimList(DWORD dwModN, DWORD* pdwModIDList);
//立即停止动画列表
EXPORT BOOL W3DStopAnimListImmly(DWORD dwModN,DWORD* pdwModIDList,DWORD* pdwAnimTypeIDList);

//设置普通物体是否接收碰撞检测
EXPORT BOOL W3DSetPTColldCheck(DWORD dwModID,BOOL bColldCheckOn);

//设置普通物体是否接收重力
EXPORT BOOL W3DSetPTGravityCtrl(DWORD dwModID,BOOL bGravityCtrlOn,BOOL bResetGravity);

//设置用户跟踪视点
EXPORT BOOL W3DSetUserViewTracePos(float fPosX,
															  float fPosY,
															  float fPosZ,					  
															  float fFarPosX,
															  float fFarPosY,
															  float fFarPosZ);

//获得用户公共数据
EXPORT BOOL W3DGetUserCommonData(DWORD dwDataType,DWORD dwDataIndex,void* pDataReturn,BOOL bImmlyImplt);

//保存用户公共数据
EXPORT BOOL W3DSaveUserCommonData(DWORD dwDataType,DWORD dwDataIndex,void* pDataSave,BOOL bImmlyImplt);


//获得普通物体位置(一般物体 物理物体 物理控制物体 适用)
EXPORT BOOL W3DGetPTModPos(DWORD dwModID,
							                                       vec3* pvTrans,
																   vec4* pvRot,
																   vec3* pvScl);

//获得动态物理物体位置(物理物体 适用)
EXPORT BOOL W3DGetDyPhyModPos(DWORD dwModID,
								                                         mat4* pmTrans,
																		 mat4* pmRot,
																		 mat4* pmScl);


//设置普通物体位置(非物理物体 非物体控制物体 适用)
EXPORT BOOL W3DSetPTModPos(DWORD dwModID,
																   DWORD dwChangeMode,
																   vec3 vTrans,vec4 vRot,vec3 vScl);

//设置封面物体位置
EXPORT BOOL W3DSetFMModPos(DWORD dwModID,
						                           DWORD dwChangeMode,
						                           vec3 vTrans,vec4 vRot,vec3 vScl);

//设置物理控制物体位置(物体控制物体 适用)
EXPORT BOOL W3DSetDyCtrlModPos(DWORD dwModID,
													     DWORD dwChangeTransMode,
													     vec3 vTrans,
														 DWORD dwChangeRotMode,
														 vec4 vRot,
														 DWORD dwChangeSclMode,
														 vec3 vScl);

//改变动态物理物体的位置(间接改变)(物理物体 适用)
EXPORT BOOL W3DSetPhyModPos(DWORD dwModID,
													 DWORD dwChangeTransMode,
													 DWORD dwChangeRotMode,
													 DWORD dwChangeSclMode,
													 vec3 vTrans,vec4 vRot,vec3 vScl,
													 mat4 mTrans,mat4 mRot,mat4 mScl);

//设置动态物理物体位置(直接改变)(物理物体 适用)
EXPORT BOOL W3DSetDyPhyModPos(DWORD dwModID,
								                                         DWORD bChangeTransMode,
																		 mat4 mTrans,
																		 DWORD bChangeRotMode,
																		 mat4 mRot,
																		 DWORD bChangeSclMode,
																		 mat4 mScl);

//设置PT物体的摩擦系数
EXPORT BOOL W3DSetPhyModFiction(DWORD dwModID,float fModFiction);

//设置PT物体的重量
EXPORT BOOL W3DSetPhyModWeight(DWORD dwModID,float fModWeight);

//设置PT物体的力量
EXPORT BOOL W3DSetPhyModForce(DWORD dwModID,float fModForce);

//无延迟的延时函数
EXPORT BOOL  W3DEventDelay(BOOL bReset,DWORD dwIndex, DWORD dwTime);

//清理PT物体的触发信息
EXPORT BOOL W3DCleanPTModTriggerInfo(DWORD dwModID);

//清理场景物体的触发信息
EXPORT BOOL W3DCleanSceneModTriggerInfo(DWORD dwModID);

//查询动态物理物体是否有碰撞发生
EXPORT BOOL W3DCheckPhyModColld(DWORD dwModID,BOOL* pbColld);

//查询PT物体的触发信息
EXPORT BOOL W3DInquirePTModTriggerInfo(DWORD dwModID,
																					DWORD dwFromModID,
																					BOOL*   pbResult);

//查询场景物体的触发信息
EXPORT BOOL W3DInquireSceneModTriggerInfo(DWORD dwModID,
																						DWORD dwFromModID,
																						BOOL*   pbResult);

//获得PT物体的全包络位置 注意:如果此物体使用了自动面向用户 包络不准确
EXPORT BOOL W3DGetPTModEnvelopePos(DWORD                        dwModID,
																 W3DModEnvelopeInfo* pstModEnvelopeInfo);

//使用指定的矩阵计算PT物体的全包络位置
EXPORT BOOL W3DCompPTModEnvelopePosByMatrix(DWORD                        dwModID,
																              W3DModEnvelopeInfo* pstModEnvelopeInfo,
																			  mat4                               mModMatrix);

//获得预置场景物体的全包络位置
EXPORT BOOL W3DGetSceneModEnvelopePos(DWORD                        dwModID,
																	  W3DModEnvelopeInfo* pstModEnvelopeInfo);

//获得封面物体的位置(中心点)
EXPORT BOOL W3DGetFMModPos(DWORD dwModID,vec3* pvPos);

//获得预置场景物体的位置(中心点)
EXPORT BOOL W3DGetSceneModPos(DWORD dwModID,vec3* pvPos);

//设置场景物体的位置
EXPORT BOOL W3DSetSceneModPos(DWORD dwModID,
															   BOOL bChangeTrans,
															   vec3 vTrans,
															   BOOL bChangeRot,
															   vec4 vRot,
															   BOOL bChangeScl,
															   vec3 vScl);

//查询场景物体总数量
EXPORT BOOL W3DGetSceneModNum(DWORD* pdwNum);

//查询场景物体显示状态
EXPORT BOOL W3DGetSceneModShowStatus(DWORD dwModID,DWORD* pdwMode);

//设置场景物体隐藏
EXPORT BOOL W3DSetSceneModHide(DWORD dwModID,DWORD dwMode);

 //设置场景物体显示
EXPORT BOOL W3DSetSceneModShow(DWORD dwModID,DWORD dwMode);

//暂停系统
EXPORT BOOL W3DPauseSys(BOOL bPause);

//查询光源数量
EXPORT BOOL W3DGetLightNum(DWORD* pDLightNum,DWORD* pSLightNum,DWORD* pCLightNum);

//设置光源数量
EXPORT BOOL W3DSetLightNum(DWORD DLightNum,DWORD SLightNum,DWORD CLightNum);

//设置普通物体聚光参数设置
EXPORT BOOL W3DSetPTModConeLightInfo(DWORD dwModID,
																				   BOOL bChangeAm,
																				   float AmbientR,float AmbientG,float AmbientB,
																				   BOOL bChangeCol,
																				   float LightColorR,float LightColorG,float LightColorB,
																				   BOOL bChangePos,
																				   float LightPosx,float LightPosy,float LightPosz,
																				   BOOL bChangeDir,
																				   float LightDx,float LightDy,float LightDz,
																				   BOOL bChangeSn,
																				   float Shininess,
																				   BOOL bChangeSg,
																				   float Strength,
																				   BOOL bChangeDc,
																				   float Decay,
																				   BOOL bChangeExp,
																				   float Exponent,
																				   BOOL bChangeCutOff,
																				   float CosCutOff);

//设备普通物体点光参数
EXPORT BOOL W3DSetPTModSpotLightInfo(DWORD dwModID,
																				  BOOL bChangeAm,
																				  float AmbientR,float AmbientG,float AmbientB,
																				  BOOL bChangeCol,
																				  float LightColorR,float LightColorG,float LightColorB,
																				  BOOL bChangePos,
																				  float LightPosx,float LightPosy,float LightPosz,
																				  BOOL bChangeSn,
																				  float Shininess,
																				  BOOL bChangeSg,
																				  float Strength,
																				  BOOL bChangeDc,
																				  float Decay);

//设置PT物体真实显示
EXPORT BOOL W3DSetPTModReal(DWORD dwModID,BOOL bReal);

//设置场景物体真实模式
EXPORT BOOL W3DSetSceneModReal(DWORD dwModID,BOOL bReal);

//设置PT物体真实模式
EXPORT BOOL W3DSetPTModRealMode(DWORD dwModID,
								                                 BOOL      bChangeRV,
								                                 BOOL      bRealOnRV,
																 BOOL      bChangeGV,
																 BOOL      bRealOnGV,
																 BOOL      bChangeAV,
																 BOOL      bRealOnAV,
																 BOOL      bChangeWV,
																 BOOL      bRealOnWV,
																 BOOL      bChangeFV,
																 BOOL      bRealOnFV);


//设置预置场景物体真实模式
EXPORT BOOL W3DSetSceneModRealMode(DWORD dwModID,
																				 BOOL      bChangeRV,
																				 BOOL      bRealOnRV,
																				 BOOL      bChangeGV,
																				 BOOL      bRealOnGV,
																				 BOOL      bChangeAV,
																				 BOOL      bRealOnAV,
																				 BOOL      bChangeWV,
																				 BOOL      bRealOnWV,
																				 BOOL      bChangeFV,
																				 BOOL      bRealOnFV);

//设置普通物体是否隐藏
EXPORT BOOL W3DSetPTModHide(DWORD dwModID,DWORD dwMode);

//查询普通物体总数量
EXPORT BOOL W3DGetPTModNum(DWORD* pdwNum);

//查询普通物体显示状态
EXPORT BOOL W3DGetPTModShowStatus(DWORD dwModID,DWORD* pdwMode);

//设置普通物体是否显示
EXPORT BOOL W3DSetPTModShow(DWORD dwModID,DWORD dwMode);

//设置普通物体类型
EXPORT BOOL W3DSetPTModType(DWORD dwModID,DWORD dwType);

//设置封面物体基础颜色
EXPORT BOOL W3DSetFMModBasicColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//设置封面物体虚拟颜色
EXPORT BOOL W3DSetFMModVirtualColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//设置普通物体虚拟颜色
EXPORT BOOL W3DSetPTModVirtualColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//设置普通物体基础颜色
EXPORT BOOL W3DSetPTModBasicColor(DWORD dwModID,
																			  float fColR,
																			  float fColG,
																			  float fColB,
																			  float fColA);

//设备普通物体材质属性
EXPORT BOOL W3DSetPTModMaterial(DWORD dwModID,
									                                     BOOL bChangeA,
																		 float ar,float ag,float ab,
																		 BOOL bChangeD,
																		 float dr,float dg,float db, 
																		 BOOL bChangeS,
																		 float sr,float sg,float sb, 
																		 BOOL bChangeE,
																		 float er,float eg,float eb, 
																		 BOOL bChangeNs,
																		 float ns,
																		 BOOL bChangeMt,
																		 float mt);

//设备普通物体方向光参数
EXPORT BOOL W3DSetPTModDirectionLightInfo(DWORD dwModID,
																						 BOOL bChangeAm,
																						 float AmbientR,float AmbientG,float AmbientB,
																						 BOOL bChangeCol,
																						 float LightColorR,float LightColorG,float LightColorB,
																						 BOOL bChangeDir,
																						 float LightDx,float LightDy,float LightDz,
																						 BOOL bChangeSn,
																						 float Shininess,
																						 BOOL bChangeSg,
																						 float Strength);

//设置用户视点锁定模式
EXPORT BOOL W3DSetUserViewLockMode(DWORD dwMode);
//设置普通模型的文字
EXPORT BOOL W3DSetPTModWord(DWORD dwModID,
						                              BOOL bChangeWord,
													  WCHAR* word,
													  BOOL bChangeWordCol,
													  float fWordR,float fWordG,float fWordB,
													  BOOL bChangeWordTran,
													   float fTranX,float fTranY,float fTranZ,
													   BOOL bChangeWordRot,
													   float fRotRa,float fRotX,float fRotY,float fRotZ,
													   BOOL bChangeWordScale,
													   float fSclX,float fSclY,float fSclZ);
//设置封面模型的文字
EXPORT BOOL W3DSetFMModWord(DWORD dwModID,
						                              BOOL bChangeWord,
													  WCHAR* word,
													  BOOL bChangeWordCol,
													  float fWordR,float fWordG,float fWordB,
													  BOOL bChangeWordTran,
													   float fTranX,float fTranY,float fTranZ,
													   BOOL bChangeWordRot,
													   float fRotRa,float fRotX,float fRotY,float fRotZ,
													   BOOL bChangeWordScale,
													   float fSclX,float fSclY,float fSclZ);
//获得普通模型的自定义信息
EXPORT BOOL W3DGetPTModCustomInfo(DWORD dwModID,PTModCustomInfo* p);
//设置普通模型的自定义信息
EXPORT BOOL W3DSetPTModCustomInfo(DWORD dwModID,PTModCustomInfo* p);
//获得普通模型的旋转序列
EXPORT BOOL W3DGetPTModRoSerl(DWORD dwModID,DWORD* pdwRoSerlN,vec4* pvRoSerl);
//设置普通模型的旋转序列
EXPORT BOOL W3DSetPTModRoSerl(DWORD dwModID,DWORD dwRoSerlN,vec4* vRoSerl);
//启用帧推流功能
EXPORT BOOL W3DSetFrameStream(DWORD  dwMode,BYTE* pStreamMem,BOOL* pbReadyToGenFrame);
//获得仿真窗口大小
EXPORT BOOL W3DGetWindowInfo(DWORD* pdwWindowWidth,DWORD* pdwWindowHeight,HWND* hWindow);
//设置全局模式鼠标滚轮灵敏度
EXPORT BOOL W3DSetGVSensi(float fSensi);
//获得系统状态
EXPORT BOOL W3DGetSystemStatus(DWORD* dwStatus,DWORD* dwInfo);
 //重置预置场景的用户视点
EXPORT BOOL W3DResetSceneUserViewPoint(DWORD dwMode);
//设置用户视点
EXPORT BOOL W3DSetUserViewPoint(ViewUserInfo* viewinfo,BOOL bAutoGenViewAngle);
//是否自动生成车道线开关
EXPORT BOOL W3DAutoGenLaneLine(DWORD dwMode);
//动态交通元素仿真灵敏度控制
EXPORT BOOL W3DDyTraObjSimSensi(float fSensi);
//动态交通元素重置
EXPORT BOOL W3DResetDyTraObj(DWORD dwObjID,DWORD dwTmOut);
//动态交通元素差值数据设置
EXPORT BOOL W3DSetDyTraObjVehNum(DWORD dwVehN);
//动态交通元素仿真接口
EXPORT BOOL W3DDynamicTrafficObjectSim(DyTraObjFrameData* stFrameData);
//动态交通元素异步仿真接口
EXPORT BOOL W3DDynamicTrafficObjectAsynSim(DyTraObjFrameData* stFrameData);
//查询元素
EXPORT BOOL W3DInquireObject(DWORD dwCategory,DWORD dwID);
//环绕浏览
EXPORT BOOL W3DRingView();
//定点环绕浏览
EXPORT BOOL W3DRingViewOnPos(float farposx,float farposy,float farposz,float userposy,float dis,float startang);
//设置仿真的显示模式
EXPORT BOOL W3DSetSceneDrawMode(DWORD dwMode);
//设置路面显示模式
EXPORT BOOL W3DSetRoadShowMode(DWORD dwMode,DWORD dwTexID);
//设置提示信息板显示时间
EXPORT BOOL W3DSetTipShowTime(DWORD dwTime);
//查询当前观察者信息
EXPORT BOOL W3DInquireViewUserInfo(ViewUserInfo* viewinfo);
//新增某一个路产元素
EXPORT BOOL W3DAddLCInfo(LCSelInfo* lcinfo);
//删除某一个路产元素
EXPORT BOOL W3DDelLCInfo(DWORD id);
//保存路产信息
EXPORT BOOL W3DSaveLCInfo();
//设置转发客户窗口的句柄
EXPORT BOOL W3DSetClientWin(HWND hClietWn,DWORD dwMode);
//设置消息队列模式
EXPORT BOOL W3DSetMessageListMode(DWORD dwMode);
//获得最早的消息
EXPORT BOOL W3DGetFirstMessage(BOOL* pbMsgExist,W3DMsgInfo* pstFirstMsg);
//设置路产的信息
EXPORT BOOL W3DSetLCInfo(LCSelInfo* lcinfo);

//设置地面标志的信息
EXPORT BOOL W3DSetDMBZInfo(DMBZSelInfo* dmbzinfo);

//设置病害的信息
EXPORT BOOL W3DSetBHInfo(BHSelInfo* bhinfo);
//获得可变标志的信息
EXPORT BOOL W3DGetKbbzInfo(KBBZSelInfo* kbbzinfo);
//获得普遍标志的信息
EXPORT BOOL W3DGetBzpInfo(BzpSelInfo* bzpinfo);
//设置可变标志的信息
EXPORT BOOL W3DSetKbbzInfo(KBBZSelInfo* kbbzinfo);
//设置普遍标志的信息
EXPORT BOOL W3DSetBzpInfo(BzpSelInfo* bzpinfo);
//结束选择交通元素
EXPORT BOOL W3DFinishSelectObj();

//获得交通GPS的校准信息
EXPORT BOOL W3DGetTrafficGPSCalibInfo(GPSCalibInfo* gpscab);

//查询是否有交通元素被选中 并返回选中的元素信息
EXPORT BOOL W3DInquireSelectedObj(W3DSelectedObjInfo* pstSelObjInfo);

//地面导向提示开关
EXPORT BOOL W3DRdDirctTip(BOOL bOn);
//选择路面整体的纹理贴图
EXPORT BOOL W3DSetRoadTex(DWORD dwTexID);
//是否显示原始gps路网点
EXPORT BOOL W3DShowOrignGPSPoint(BOOL bShow);
//病害提示开关
EXPORT BOOL W3DDMBHTip(DWORD dwMode);
//路产提示开关
EXPORT BOOL W3DLCTip(DWORD dwMode);
//可变标志提示开关
EXPORT BOOL W3DKBBZTip(DWORD dwMode);
//普通标志提示开关
EXPORT BOOL W3DBzpTip(DWORD dwMode);
//全局提示开关
EXPORT BOOL W3DGlobalTip(BOOL bOn);
//俯视浏览
EXPORT BOOL W3DAerialView();
//全局浏览
EXPORT BOOL W3DGlobalView();
//自动巡检
EXPORT BOOL W3DAutoTraceWander(BOOL bOn);
//追踪漫游
EXPORT BOOL W3DTraceWander();
//自由漫游
EXPORT BOOL W3DFreeWander();
//关闭仿真系统
EXPORT BOOL W3DExitSys();

//设置加载交通数据库的类型
EXPORT BOOL W3DSetLoadTrafficDatabaseInfo(BOOL bLoadBzp,
																		BOOL bLoadKbbz,
																		BOOL bLoadHL,
																		BOOL bLoadDMBX,
																		BOOL bLoadDMBZ,
																		BOOL bLoadBH,
																		BOOL bLoadLC);

//自动刷新仿真
EXPORT BOOL W3DAutoSim(BOOL bOn);
//手动刷新仿真
EXPORT BOOL W3DManualSim();
//仿真入口函数
EXPORT BOOL W3DProxy(WCHAR* wszAppPath,HWND   hParentHwnd, W3DBuildInfo* pstW3DBuildInfo);
  