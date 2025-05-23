#ifdef __cplusplus
#define EXPORT extern "C" __declspec (dllexport)
#else
#define EXPORT __declspec (dllexport)
#endif 

#include "math.h"  
#include "vmath.h"  
using namespace vmath;
//////////////////////////////////////////////////////////////////////////�Զ������������ݶ���//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_BZP_BASEMOD_NUM                 500      //��ͨ��־������ģ����
#define W3D_MAX_BZP_MOD_NUM                          1000    //��ͨ��־���ģ����
#define W3D_MAX_DMBZ_BASEMOD_NUM             100      //�����־������ģ����
#define W3D_MAX_DMBZ_MOD_NUM                      1000    //�����־���ģ����
#define W3D_MAX_DMBH_BASEMOD_NUM             100      //����������ģ����
#define W3D_MAX_DMBH_MOD_NUM                      1000      //�������ģ����
#define W3D_MAX_DMBX_BASEMOD_NUM             100      //�������������ģ����
#define W3D_MAX_DMBX_MOD_NUM                      1000      //����������ģ����
#define W3D_MAX_HL_BASEMOD_NUM             100      //����������ģ����
#define W3D_MAX_HL_MOD_NUM                      1000      //�������ģ����
#define W3D_MAX_KBBZ_BASEMOD_NUM             100      //�ɱ��־������ģ����
#define W3D_MAX_KBBZ_MOD_NUM                      1000      //�ɱ��־���ģ����
#define W3D_MAX_LC_BASEMOD_NUM             500      //·��������ģ����
#define W3D_MAX_LC_MOD_NUM                      3000      //·�����ģ����
#define W3D_MAX_ExRoad_MOD_NUM                      100      //�����·���ģ����
//////////////////////////////////////////////////////////////////////////���ݶ���//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_DTMOD_NUM                             1000       //���֧�ֵĶ�̬ģ������
#define W3D_MAX_DTMOD_TEX_NUM                    1000        //������̬ģ��������������
#define W3D_MAX_YZCJ_MOD_NUM                        1000      //Ԥ�ó������ģ����

#define W3D_MAX_DbClkLimRg_MOD_NUM                              500      //˫�����������������

#define W3D_MAX_MAIN_RENDER_TEX_NUM 8//����Ⱦ���������

#define W3D_MAX_DY_TRAFFIC_OBJECT_NUM     1000      //���̬��ͨĿ������
#define W3D_DyTraObj_MAX_FRAME_POOL_NUM  1000     //��̬��ͨԪ������֡������������
#define W3D_MAX_DyTraObj_MOD_N                        500       //��̬��ͨԪ��ģ���������

#define W3D_MAX_UserPlugInDLL_N                           500     //���֧�ּ��ص��û�������DLL����

#define W3D_MAX_EVENT_DELAY_N                        1000     //�����ʱ���¼�����

#define W3D_MAX_PT_MOD_NUM                              1000      //��ͨģ�����ģ����
#define W3D_MAX_FM_MOD_NUM                              500      //����ģ�����ģ����
#define W3D_MAX_PLAYER_MOTION_NUM              500      //�û���������
#define GroupMod_ID_Num                                            1000    //һ������ģ������������1000����ģ��
#define W3D_MAX_GROUP_MOD_NUM                      1000    //��󸴺�ģ������
#define W3D_MAX_CUBEMAP_TEXSIZE                     8192      //�������ͼ����ߴ�
#define W3D_MAX_COLLD_MOD_NUM                      1000      //�����ײģ������
#define W3D_MAX_DLIGHT_GENSHADOW_NUM   5//���D��Դ��Ӱ��������Ϊ5
#define W3D_MAX_SLIGHT_GENSHADOW_NUM   5//���S��Դ��Ӱ��������Ϊ5
#define W3D_MAX_CLIGHT_GENSHADOW_NUM   5//���C��Դ��Ӱ��������Ϊ5
#define W3D_MAX_SHADOW_NUM                            W3D_MAX_DLIGHT_GENSHADOW_NUM + W3D_MAX_SLIGHT_GENSHADOW_NUM + W3D_MAX_CLIGHT_GENSHADOW_NUM     //������Ӱ���� (����5+���5+�۹�5)      
#define W3D_MAX_DLIGHT_NUM                               64//���D��Դ����Ϊ64
#define W3D_MAX_SLIGHT_NUM                               64//���S��Դ����Ϊ64
#define W3D_MAX_CLIGHT_NUM                               64//���C��Դ����Ϊ64
#define W3D_MAX_BasicGraph_Memory_Size               10000//����ͼ������ڴ��С
#define W3D_MAX_MOD_ROT_SERL_N                     50//������ת���������
#define W3D_MAX_MAINWIN_TITLEWORD_LEN     100//���������������ֳ���
#define W3D_MAX_SYSERRORSTATUSINFO_NUM             1000      //���ϵͳ����״̬��Ϣ����
#define W3D_MAX_MSGLIST_LEN             1000      //�����Ϣ�б���
//////////////////////////////////////////////////////////////////////////��Ϣ����//////////////////////////////////////////////////////////////////////////
#define WM_W3DMSG                                                     WM_USER + 0x00001000 //ת����Ϣ��׼
//////////////////////////////////////////////////////////////////////////·������//////////////////////////////////////////////////////////////////////////
#define W3D_MAX_PATH_LEN                                                     500//���·������

//////////////////////////////////////////////////////////////////////////��갴ť��Ϣ//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////��갴ť��Ϣ//////////////////////////////////////////////////////////////////////////
#define W3D_LBUTTON_STATUS 0
#define W3D_RBUTTON_STATUS 1

//////////////////////////////////////////////////////////////////////////��������״̬//////////////////////////////////////////////////////////////////////////
#define W3D_ANIM_STATUS_PLAY 1  //�������ڲ���
#define W3D_ANIM_STATUS_END 2  //�����Ѳ������
#define W3D_ANIM_STATUS_STOP 3  //������ֹͣ 

//////////////////////////////////////////////////////////////////////////��������״̬//////////////////////////////////////////////////////////////////////////
#define MAX_PLAYSOUNDTHREAD_N 20//�������������߳���
#define W3D_SOUND_STATUS_PLAY 1  //�������ڲ���
#define W3D_SOUND_STATUS_END 2  //�����Ѳ������ 

//////////////////////////////////////////////////////////////////////////�������Ͷ���//////////////////////////////////////////////////////////////////////////
#define W3D_SCENE_MOD 1//��������
#define W3D_PT_MOD 2//PT����
#define W3D_FM_MOD 3//��������

///////////LOD��Ϣ�ṹ////////////////////////////
struct LODInfo
{
	float         fLODStart;//LOD�㼶��ʼ����
	DWORD dwLODTexScl;//LOD�㼶����������
};

///////////��ɫԤ��������ṹ////////////////////////////
struct ColPreProcParamInfo
{
	BOOL   bSetClrCol;//������ɫ�������
	float     fClrColR;//�����ɫR����
	float     fClrColG;//�����ɫG����
	float     fClrColB;//�����ɫB����
	float     fClrColA;//�����ɫA����
	BOOL   bSetGryScl;//������ɫ�ҶȻ�����
    	DWORD dwGrySclMode;//�ҶȻ���ʽ
	BOOL   bSetHgLgtExt;//���ø߹���ȡ����
	float     fHgLgtExtLowThrhld;//�߹���ȡ����ֵ
	float     fHgLgtExtHgThrhld;//�߹���ȡ����ֵ
};

/////////////////////////////////////������Ϣ����/////////////////////////////////////
struct W3DMsgInfo
{
	UINT uMsg;
	ULONGLONG wParam;
	LONGLONG    lParam;
};

////////////////////////////////////////ϵͳ������Ϣ////////////////////////////////////////
struct W3DSysPerformanceInfo
{
	DWORD dwRenderFPS;//��ȾFPS
	DWORD dwFrameStreamFPS;//����FPS
};

////////////////////////////////////////��Ӱ������Ϣ////////////////////////////////////////
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

////////////////////////////////////////////����ϵͳ����״̬��ʽ////////////////////////////////////////////
struct W3DSysErrorStatusInfo
{
	DWORD dwErrorStatusCode;//����״̬��
	DWORD dwSubErrorStatusCode;//�Ӵ���״̬��
        BOOL      bValid;//�ڲ�ʹ��
};

////////////////////////////////////////////ģ�Ͱ���ṹ��////////////////////////////////////////////
struct W3DModEnvelopeInfo
{
	vec3 vEnvPoint[9];//1�����ĵ�+8�����Ӱ��綥��
};

////////////////////////////////////////////�û��������ݶ�������////////////////////////////////////////////
#define W3D_COMMON_USER_DATA_MAX_LEN      1000//ÿ������������󳤶�
#define W3D_COMMON_USER_DATA_MAX_STRING_LEN      100//��������������ַ�������
#define W3D_COMMON_USER_DATA_TYPE_BOOL      1//bool����
#define W3D_COMMON_USER_DATA_TYPE_INT          2//int����
#define W3D_COMMON_USER_DATA_TYPE_DWORD 3//DWORD����
#define W3D_COMMON_USER_DATA_TYPE_FLOAT    4//float����
#define W3D_COMMON_USER_DATA_TYPE_DOUBLE 5//double����
#define W3D_COMMON_USER_DATA_TYPE_CHAR     6//char����
#define W3D_COMMON_USER_DATA_TYPE_WCHAR 7//wchar����

////////////////////////////////////////////��ͨģ���Զ���״̬��Ϣ////////////////////////////////////////////
struct PTModCustomInfo
{
	char         szInRoadSec[50];//����·��
	DWORD dwStatus;//����״̬
};

////////////////////////////////////////////��̬��ͨԪ��֡��ʽ///////////////////////////////////////////////
struct DyTraObjFrameData
{ 
	DWORD vehicleId;//����id
	WCHAR plateNo[50];//���ƺ�
	LONGLONG timeStamp;//֡ʱ���
	double     lon;//��������
	double     lat;//����γ��
	double     ele;//�����߶�
	DWORD speed;//�����ٶ�
	DWORD heading;//�������߽�
	DWORD wid;//������
	DWORD len;//������
	DWORD hei;//������
	DWORD basicVehicleClass;
	DWORD fuelType;//����ȼ������
	DWORD fuelN;//ʣ��ȼ������
	///////////////����ڲ�ʹ��//////////////
	BOOL     bFrameValid;//֡�Ƿ���Ч
	///////////////////////////////////////////////////////
};
//////////������ά����Ԥ����Ϣ��////////
struct W3DBuildInfo
{
	/////////////�ֱ�������///////////
	int iWid;//���ڿ�
	int iHei;//���ڸ� 
	/////////////Ĭ��λ������///////////
	int iPosX;//����λ��x
	int iPosY;//����λ��y
	/////////////���س�����///////////
	DWORD dwSelScene;
};
//GPS����У׼��Ϣ
struct GPSCalibInfo
{
	//GPS��׼XYZ
	float fGPSjzx;
	float fGPSjzy;
	float fGPSjzz;
	//GPS��׼�Ŵ�XYZ
    float fGPSdx;
	float fGPSdy;
	float fGPSdz;
};
//��ͨ��־ѡ����Ϣ
struct BzpSelInfo
{ 
	DWORD bzpN;//��ͨ��־��������
	DWORD id;//��Ŀ������
	float        x;
	float        y;
	float        z;
	float        ra;
	DWORD dwType;
};
//�ɱ��־ѡ����Ϣ
struct KBBZSelInfo
{ 
	DWORD kbbzN;//�ɱ��־��������
	DWORD id;//��Ŀ������
	float        x;
	float        y;
	float        z;
	float        wid;
	float        hei;
	float        ra;
	DWORD type;
};
//����ѡ����Ϣ
struct HLSelInfo
{ 
	DWORD hlN;//������������
	DWORD id;//��Ŀ������
	float        startx;
	float        starty;
	float        startz;
	float        endx;
	float        endy;
	float        endz;
	DWORD type;
};
//�������ѡ����Ϣ
struct DMBXSelInfo
{ 
	DWORD dmbxN;//���������������
	DWORD id;//��Ŀ������
	float        startx;
	float        starty;
	float        startz;
	float        endx;
	float        endy;
	float        endz;
	DWORD type;
};

//�����־ѡ����Ϣ
struct DMBZSelInfo
{ 
	DWORD dmbzN;//�����־��������
	DWORD id;//��Ŀ������
	float         x;
	float         y;
	float         z;
	float         len;
	float         wid;
	DWORD type;
};   

//����ѡ����Ϣ
struct BHSelInfo
{ 
	DWORD bhN;//������������
	DWORD id;//��Ŀ������
	float         x;
	float         y;
	float         z;
	float         len;
	float         wid;
	DWORD type;
};   

//·��ѡ����Ϣ
struct LCSelInfo
{ 
	DWORD LCN;//·����������
	DWORD id;//��Ŀ������
	float        x;
	float        y;
	float        z;
	float        sx;
	float        sy;
	float        sz;
	float        ra;
	DWORD dwType;
};
//�۲�����Ϣ
struct ViewUserInfo
{ 
	//�۲����û���ǰλ������
	float posX;
	float posY;
	float posZ;
	//�۲����û���Զ����λ������
	float farposX;
	float farposY;
	float farposZ;
	//�۲����ӽ�
	float fViewAng;
}; 

//��·��Ϣ
struct RoadInfo
{
	float                  fRoadLaneWid;//������
	DWORD          dwRoadLaneN;//��������
};

//��ѡ����Ϣ�ṹ��
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

#define W3D_USER_LOAD_TEX_STATUS_NONE 0//�û��˴ζ�ȡ�������û��״̬
#define W3D_USER_LOAD_TEX_STATUS_FAILED 1//�û��˴ζ�ȡ�������ʧ��
#define W3D_USER_LOAD_TEX_STATUS_SUCCESS 2//�û��˴ζ�ȡ��������ɹ�
#define W3D_USER_LOAD_TEX_STATUS_FINISH 3//�û��˴ζ�ȡ������������

//�û�����������ͼ��Ϣ
struct W3DUserLoadTexInfo
{
	int            iTexLevel;//����㼶
	BOOL     bTexRGBScale;//�����Ƿ�����RGB����
	float         fTexScaleR;//��������R����
	float         fTexScaleG;//��������G����
	float         fTexScaleB;//��������B����
	DWORD dwTexIndex;//���ص���������
	char         szTexFilePath[MAX_PATH];//�����ļ�·��
};

//��÷������������ͼ״̬
EXPORT BOOL W3DGetFMModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//���PT���������ͼ״̬
EXPORT BOOL W3DGetPTModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//��ó������������ͼ״̬
EXPORT BOOL W3DGetSceneModLoadTexStatus(DWORD dwModID,DWORD* pdwStatus);

//�������������ͼ
EXPORT BOOL W3DSceneModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//PT���������ͼ
EXPORT BOOL W3DPTModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//FM���������ͼ
EXPORT BOOL W3DFMModLoadTexture(DWORD dwModID,W3DUserLoadTexInfo* pstLdTexInfo);

//���ó���������͸��
EXPORT BOOL W3DSetSceneModFogPenetrate(DWORD dwModID,float fFgPentrt);

//����PT������͸��
EXPORT BOOL W3DSetPTModFogPenetrate(DWORD dwModID,float fFgPentrt);

//���÷���������͸��
EXPORT BOOL W3DSetFMModFogPenetrate(DWORD dwModID,float fFgPentrt);

//���ó��������ɫ
EXPORT BOOL W3DSetSceneClearColor(float fColR,float fColG,float fColB,float fColA);

//������ȾFOV
EXPORT BOOL W3DSetRenderFOV(float fFOV);

//������Ⱦ��ƽ��
EXPORT BOOL W3DSetRenderNearPlane(float fNearPlane);

//�����û����߷�Χ
EXPORT BOOL W3DSetUserViewRange(float fViewRange);

//���ó����������λ��(��Ӹı�)
EXPORT BOOL W3DSetSceneModGroupPosIndirectly(DWORD dwModNum,
																					   DWORD* pdwModIDList,
																					   DWORD* pdwChangeTransModeList,
																					   DWORD* pdwChangeRotModeList,
																					   DWORD* pdwChangeSclModeList,
																					   vec3* pvTransList,
																					   vec4* pvRotList,
																					   vec3* pvSclList);

//����PT�������λ��(��Ӹı�)
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

//���û���ͼ����ɫ������Ϣ
EXPORT BOOL W3DSetBasicGraphColPostProcInfo(DWORD   dwClPstProcN,
																					DWORD* pdwClPstProcID);

//����PT�����λ��(��Ӹı�)
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


//��÷���ģ�͵���ת����
EXPORT BOOL W3DGetFMModRoSerl(DWORD dwModID,
																DWORD* pdwRoSerlN,
																vec4*      pvRoSerl);


//���÷���ģ�͵���ת����
EXPORT BOOL W3DSetFMModRoSerl(DWORD dwModID,
																DWORD dwRoSerlN,
																vec4*      vRoSerl);

//���ó��������λ��(��Ӹı�)
EXPORT BOOL W3DSetSceneModPosIndirectly(DWORD dwModID,
																			 DWORD dwChangeTransMode,
																			 DWORD dwChangeRotMode,
																			 DWORD dwChangeSclMode,
																			 vec3 vTrans,vec4 vRot,vec3 vScl);

//�߾�����ʱ
EXPORT BOOL W3DHighPrecisionDelay(LONGLONG llDelayTime);

//���ö�̬���������ָ�������������ײ�����Ч��
EXPORT BOOL W3DSetColldCheckOnMod(DWORD dwModID,
																	   DWORD dwOnModType,
																	   DWORD dwOnModID,
																	   BOOL     bColldCheck,
																	   BOOL     bClldChckValid);

//����LOD��Ϣ
EXPORT BOOL W3DSetLODInfo(DWORD dwLODType,DWORD dwSetLODLevel,LODInfo* pstLODInfo);

//��������ȫ����ͼ����
EXPORT BOOL W3DSetGlobalTextureScale(DWORD dwTexScl);

//��ó�������λ����Ϣ
EXPORT BOOL W3DGetSceneModPosInfo(DWORD dwModID,vec3* pvTrans,vec4* pvRot,vec3* pvScl);

//������Ⱦ֡������
EXPORT BOOL W3DSetRenderFPSLimit(BOOL bEnableMaxRdrFPSlim,DWORD dwMaxRdrFPSlim,    
									BOOL bEnableMinRdrFPSlim,DWORD dwMinRdrFPSlim);

//���ó���������ɫԤ���������
EXPORT BOOL W3DSetSceneModColPrePostProc(DWORD  dwModID,
																				  DWORD  dwColPostProcN,
																				  DWORD* pdwColPostProcIDList,
																				  DWORD* pdwColPreProcFuncList,
																				  float*         pfColPreProcAlphaList);

//����PT������ɫԤ���������
EXPORT BOOL W3DSetPTModColPrePostProc(DWORD  dwModID,
																			 DWORD  dwColPostProcN,
																			 DWORD* pdwColPostProcIDList,
																			 DWORD* pdwColPreProcFuncList,
																			 float*         pfColPreProcAlphaList);

//���÷���������ɫԤ���������
EXPORT BOOL W3DSetFMModColPrePostProc(DWORD  dwModID,
																			  DWORD  dwColPostProcN,
																			  DWORD* pdwColPostProcIDList,
																			  DWORD* pdwColPreProcFuncList,
																			  float*         pfColPreProcAlphaList);

//������ɫԤ�������
EXPORT BOOL W3DSetColPreProcInfo(ColPreProcParamInfo* pstColPrePrcPrm); 

//�����û����������˶�������ģʽ
EXPORT BOOL W3DSetUserCrtlModMoveSensi(float fSensi);

//�����û����������˶��ٶ�
EXPORT BOOL W3DSetUserCrtlModMoveSpeed(BOOL bChangeFBSpd,
                                                                        		float   fFBSpd,    
											BOOL bChangeLRSpd,
                                                                  		        float   fLRSpd, 
											BOOL bChangeFastSpd,
                                                           		                float   fFastSpd);

//��������ģʽ
EXPORT BOOL W3DSetFrameStreamMode(DWORD dwFrmStrmMode);

//���������ٶ�
EXPORT BOOL W3DSetFrameStreamSpeed(DWORD dwFrmStrmSpeed);

//���ϵͳ��������Ϣ
EXPORT BOOL W3DGetSysPerformanceInfo(W3DSysPerformanceInfo* pstSysPerfInfo);

//������������ʾģʽ
EXPORT BOOL W3DSetMainWinShowMode(DWORD dwMode);

//����������λ��
EXPORT BOOL W3DSetMainWinPos(int iWinX,int iWinY,int iWinWid,int iWinHei);

//��������ϵͳ����
EXPORT BOOL W3DSetSysLanguage(DWORD dwLanguageCode);

//�첽��ʽ��������
EXPORT BOOL W3DAsynProxy(WCHAR* wszAppPath,HWND hParentHwnd, W3DBuildInfo* pstW3DBuildInfo);

//����ѡ��ģʽ
EXPORT BOOL W3DSetSelectMode(BOOL bChangeMode,DWORD dwSelMode,
						  		 BOOL bChangeInputMode,DWORD dwInputMode);

//�û��ӵ�׷��PT����
EXPORT BOOL W3DUserViewTracePTMod(DWORD dwTraceModID,
							     		     float fTracePosX,float fTracePosY,float fTracePosZ,
							    		     float fTraceFarPosX,float fTraceFarPosY,float fTraceFarPosZ);

//��ѯ�û������ʾ״̬
EXPORT BOOL W3DGetUserCursorShow(BOOL* pbOnHide);

//��ʾ�û����
EXPORT BOOL W3DShowUserCursor(BOOL bShow);

//�������Ĵ�����
EXPORT BOOL W3DGetLastError(DWORD* pdwErrorCode);

//����ȫ��ģʽ�µĲٿ�ģʽ
EXPORT BOOL W3DSetOpnModeOnGV(BOOL bChangeOpnMode,DWORD dwOpnMode,BOOL bChangeDbClkMode,BOOL bDbClkEnable);

//����Ļλ��ѡ������
EXPORT BOOL W3DSelectModFromScrPos(int iScrPosX,int iScrPosY);

//����PTģ�͵�����ID
EXPORT BOOL W3DSetPTModTexID(DWORD dwModID,DWORD dwTexModID);

//����PTģ��ʹ���������е���һ��
EXPORT BOOL W3DSetPTModTexFromTexGroup(DWORD dwModID,DWORD dwTexIDInTexGroup);


//���ó������������ID
EXPORT BOOL W3DSetSceneModTexID(DWORD dwModID,DWORD dwTexModID);

//������Ӱ��Ϣ
EXPORT BOOL W3DSetShadowInfo(DWORD dwShaID,ShadowInfo* pstShaInfo);

//������ײ������
EXPORT BOOL W3DSetColldCheckDis(float fColldDis);

//�ж�һ���Ƿ���һ��������
EXPORT BOOL W3DCheck3DPointInMod(DWORD dwModID,
							                                 DWORD dwModType,
															 mat4 mModMatrix,
															 vec3 vCheck3DPoint);


//����PT�����Ƿ�Ϊ��̬���������������
EXPORT BOOL W3DSetPTModDyPhyCtrlMod(DWORD dwModID,DWORD dwMode);

//����PT�����Ƿ�Ϊ��̬��������
EXPORT BOOL W3DSetPTModDyPhyMod(DWORD dwModID,DWORD dwMode);

//���ó�������������ɫ
EXPORT BOOL W3DSetSceneModVirtualColor(DWORD dwModID,
																	float fColR,
																	float fColG,
																	float fColB,
																	float fColA);

//���ó������������ɫ
EXPORT BOOL W3DSetSceneModBasicColor(DWORD dwModID,
																  float fColR,
																  float fColG,
																  float fColB,
																  float fColA);

//����·��ģ�͵���ת����
EXPORT BOOL W3DSetLCModRoSerl(DWORD dwModID,
						                                DWORD dwRoSerlN,
														vec4*      vRoSerl);

//���õ����־�Ļ�����ɫ
EXPORT BOOL W3DSetDMBZBasicColor(DWORD dwModID,
															 DWORD dwMode,
															 float fColR,float fColG,float fColB,float fColA);

//���õ��没���Ļ�����ɫ
EXPORT BOOL W3DSetDMBHBasicColor(DWORD dwModID,
															 DWORD dwMode,
															 float fColR,float fColG,float fColB,float fColA);

//������ͨ��־�Ļ�����ɫ
EXPORT BOOL W3DSetBzpBasicColor(DWORD dwModID,
							                            DWORD dwMode,
													    float fColR,float fColG,float fColB,float fColA);

//����·���Ļ�����ɫ
EXPORT BOOL W3DSetLCBasicColor(DWORD dwModID,
							                           DWORD dwMode,
													   float fColR,float fColG,float fColB,float fColA);

//���õ�����ߵĻ�����ɫ
EXPORT BOOL W3DSetDMBXBasicColor(DWORD dwModID,
																			 DWORD dwMode,
																			 float fColR,float fColG,float fColB,float fColA);

//���û����Ļ�����ɫ
EXPORT BOOL W3DSetHLBasicColor(DWORD dwModID,
																	   DWORD dwMode,
																	   float fColR,float fColG,float fColB,float fColA);

//���ÿɱ��־�Ļ�����ɫ
EXPORT BOOL W3DSetKBBZBasicColor(DWORD dwModID,
																			DWORD dwMode,
																			float fColR,float fColG,float fColB,float fColA);

//����PT�����ѡ��ģʽ
EXPORT BOOL W3DSetPTSelectMode(DWORD dwModID,DWORD dwMode);

//���ó��������ѡ��ģʽ
EXPORT BOOL W3DSetSceneModSelectMode(DWORD dwModID,DWORD dwMode);

//���÷��������ѡ��ģʽ
EXPORT BOOL W3DSetFMModSelectMode(DWORD dwModID,DWORD dwMode);

//����ѡ����λ��
EXPORT BOOL W3DSetSelectPointPos(int x,int y);

//��õ�ǰ�������
EXPORT BOOL W3DSetCurrentSceneIdentity(DWORD* pdwSceneID);

//�����û����������ӵ�ת���ٶ�
EXPORT BOOL W3DSetUserCrtlModViewRotSpeed(BOOL bChangeRotSpeed,
									                                        float     fRotSpeed,
																			BOOL bChangeUpDnViewRotSpeed,
																			float     fUpDnViewRotSpeed,
																			BOOL bChangeFarUpDnViewRotSpeed,
																			float     fFarUpDnViewRotSpeed);

//�����û����������ģʽ
EXPORT BOOL W3DSetUserCrtlModMode(DWORD dwCtrlMode,
													  DWORD dwCtrlModID,
						                              DWORD dwViewMode,
													  BOOL bResetViewPos);

//��õ�·��Ϣ
EXPORT BOOL W3DGetRoadInfo(RoadInfo* pInfo);

//���µ�·ģ����Ϣ
EXPORT BOOL W3DUpdateRoadMod(BOOL               bUpdateVer,
													   float*                 pfRdVerMemory,
													   DWORD           dwRdVerMemSize,
													   BOOL               bUpdateTex,
													   float*                 pfRdTexMemory,
													   DWORD           dwRdTexMemSize,
													   BOOL               bUpdateNor,
													   float*                 pfRdNorMemory,
													   DWORD           dwRdNorMemSize);

//�����Ⱦ�ĵ�·GPS��
EXPORT BOOL W3DGetRoadRenderGPSPoint(DWORD* pdwMemSize,
								                                    float*         pfMemory,
																	DWORD* dwRenderSegN);

//��õ�·ԭʼGPS��
EXPORT BOOL W3DGetRoadOrignGPSPoint(DWORD* pdwMemSize,
								                                  float*         pfMemory,
																  DWORD* dwOrignSegN);

//��������gps��֮��ľ���
EXPORT double W3DCalcGPSPointDistance(double dGPSLat1, double dGPSLng1, double dGPSHei1,
								                               double dGPSLat2, double dGPSLng2, double dGPSHei2,
															   double dEarthRadius);

//���û���ͼ�εĵ��С�߿��
EXPORT BOOL W3DSetBasicGraph(float fSize,float fWidth);

//���»���ͼ����Ϣ
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

//��ó���ƫ��
EXPORT BOOL W3DGetSceneOffset(float* poffsetX,
													 float* poffsetY,
													 float* poffsetZ);

//��ù���ڷ�������е�����
EXPORT BOOL W3DGetScreenCursorPos(DWORD* pdwX,DWORD* pdwY);

//��Ļ2D����ת����3D����
EXPORT BOOL W3DGen3DPosFromScreenPos(int x, int y,
																			float* pdpox,float* pdpoy,float* pdpoz,
																			float* plocdpox,float* plocdpoy,float* plocdpoz);

//ֹͣ��ѯ������ͨģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireALLPTModRenderInfo();

//ֹͣ��ͨģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquirePTModRenderInfo(DWORD  dwInquireType);

//��ѯ��ͨģ����Ⱦ����Ϣ
EXPORT BOOL W3DInquirePTModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//ֹͣ��ѯ���е����־ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireALLDMBZModRenderInfo();

//ֹͣ��ѯ�����־ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireDMBZModRenderInfo(DWORD  dwInquireType);

//��ѯ�����־ģ����Ⱦ����Ϣ
EXPORT BOOL W3DInquireDMBZModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//ֹͣ��ѯ����·��ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireALLLCModRenderInfo();

//ֹͣ��ѯ·��ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireLCModRenderInfo(DWORD  dwInquireType);

//��ѯ·��ģ����Ⱦ����Ϣ
EXPORT BOOL W3DInquireLCModRenderInfo(DWORD  dwInquireType,
																	DWORD  dwInquireModN,
																	DWORD* pdwReturnModN,
																	mat4*        pmReturnMatrix,
																	BOOL*     pbReturnDataFinsh);

//ֹͣ��ѯ���л���ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireALLHLModRenderInfo();

//ֹͣ��ѯ����ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireHLModRenderInfo(DWORD  dwInquireType);

//��ѯ����ģ����Ⱦ����Ϣ
EXPORT BOOL W3DInquireHLModRenderInfo(DWORD  dwInquireType,
																	DWORD  dwInquireModN,
																	DWORD* pdwReturnModN,
																	mat4*        pmReturnMatrix,
																	BOOL*     pbReturnDataFinsh);

//ֹͣ��ѯ���е������ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireALLDMBXModRenderInfo();

//ֹͣ��ѯ�������ģ����Ⱦ����Ϣ
EXPORT BOOL W3DStopInquireDMBXModRenderInfo();

//��ѯ�������ģ����Ⱦ����Ϣ
EXPORT BOOL W3DInquireDMBXModRenderInfo(DWORD  dwInquireType,
									                                      DWORD  dwInquireModN,
																		  DWORD* pdwReturnModN,
									                                      mat4*        pmReturnMatrix,
																		  BOOL*     pbReturnDataFinsh);

//ֹͣΪPT�����ṩ��ʵ����Ⱦ��ģ�;���
EXPORT BOOL W3DStopALLPTInstancedModMatrix(DWORD dwTimeOut);

//ΪPT�����ṩ��ʵ����Ⱦ��ģ�;���
EXPORT BOOL W3DSetPTInstancedModMatrix(DWORD dwModID,
									                                 mat4*       pmMatrixData,
																	 DWORD dwMatrixN);
//�ж�����4x4�����Ƿ�һ��
EXPORT BOOL W3DCompMatrix4x4(mat4 mA,mat4 mB);

//���ó�����Ĳ���
EXPORT BOOL W3DSetSceneFogInfo(BOOL bOn,vec4 vColor,float fExt,float fInst,
															  vec3 vVertDirt,float fVertDsty,DWORD dwMode,float fMaxDsty,
															  vec3 vOrignPos,DWORD dwOrignMode);

//��ó�����Ĳ���
EXPORT BOOL W3DGetSceneFogInfo(BOOL* pbOn,vec4* pvColor,float* pfExt,float* pfInst,
															   vec3* pvVertDirt,float* pfVertDsty,DWORD* pdwMode,float* pfMaxDsty,
															   vec3* pvOrignPos,DWORD* pdwOrignMode);

//�����û�����׷��ģʽ
EXPORT BOOL W3DSetUserViewTraceMode(BOOL bChangeMode,BOOL bOn,
										 BOOL bChangeTraceModID,DWORD dwTraceModID,
										 BOOL bChangeAutoTrace,BOOL bAutoTrace,
										 BOOL bChangeTracePos,
										 float   fTracePosX,float   fTracePosY,float   fTracePosZ,
										 float   fTraceFarPosX,float   fTraceFarPosY,float   fTraceFarPosZ);

//�����û�����ģ�͵���Ծ����
EXPORT BOOL W3DSetUserCrtlModJumpStrgn(float fJumpStrgn);

//������Ⱦ������
EXPORT BOOL W3DSetRenderBrightness(float fBrightness);

//���ûҶ��˾�Ч��
EXPORT BOOL W3DSetGrayScaleFilter(BOOL bOn,float fGrayLevel);

//��ͣ�û���PT����Ŀ���
EXPORT BOOL W3DPauseUserCrtlMod(BOOL bPause);

//��ѯ��������������
EXPORT BOOL W3DGetFMModNum(DWORD* pdwNum);

//��ѯ����������ʾ״̬
EXPORT BOOL W3DGetFMModShowStatus(DWORD dwModID,DWORD* pdwMode);

//���÷���������ʾ
EXPORT BOOL W3DSetFMModShow(DWORD dwModID,DWORD dwMode);

//���÷���ģ��ʹ���������е���һ��
EXPORT BOOL W3DSetFMModTexFromTexGroup(DWORD dwModID,DWORD dwTexIDInTexGroup);

//��ѯ��������״̬
EXPORT BOOL W3DInquireAnimStatus(DWORD   dwModID,
																		DWORD   dwAnimType,
																		DWORD* pdwStatus1,
																		DWORD* pdwStatus2);

//��ö����еĹؼ���ʵʱλ��
EXPORT BOOL W3DSetKeyPointPosInAnim(DWORD   dwModID,
																				DWORD   dwAnimType,
																				DWORD   dwKeyPointN,
																				DWORD*  pdwKeyPointID,
																				vec4*         pReturnKeyPointInfo);

//ֹͣ��������
EXPORT BOOL W3DStopBGSound();

//�������ű�������
EXPORT BOOL W3DPlayBGSoundImmly(char*       pszSoundFileName,
						                                    DWORD dwSoundVolume);

//��ѯ������������״̬
EXPORT BOOL W3DInquireBGSoundStatus(DWORD* pdwStatus);

//���ñ�����������
EXPORT BOOL W3DSetBGSoundVolume(DWORD dwSoundVolume);

//���ű�������
EXPORT BOOL W3DPlayBGSound(char*       pszSoundFileName,
						                                          DWORD dwSoundVolume);
 
//��ѯ��������״̬
EXPORT BOOL W3DInquireSoundStatus(DWORD dwPlayPosID, DWORD* pdwStatus);

//��ָ��������ֹͣ����
EXPORT BOOL W3DStopModSound(DWORD dwPlayPosID);

//ָ��������ӿ�ʼ��������
EXPORT BOOL W3DPlayModSoundFromStartByPos(DWORD   dwModID,
																			 DWORD   dwModType,
																			 DWORD   dwSoundVolume,//��ʼ����
																			 char*         pszSoundFileName,
																			 BOOL       bPlayByDis,
																			 DWORD   dwPlayPosID,
																			 DWORD   dwPlayDeviceID, 
																			 BOOL       bAddExist,
																			 DWORD   dwDisMode);

//��ָ���������������ͨ��ͨ��
EXPORT BOOL W3DAddModSoundByPlayPos(DWORD   dwModID,
																	 DWORD   dwModType,
								                                     DWORD   dwSoundVolume,//��ʼ����
																	 char*         pszSoundFileName,
																	 BOOL       bPlayByDis,
																	 DWORD   dwPlayPosID,
																	 DWORD   dwPlayDeviceID, 
																	 BOOL       bAddExist,
																	 DWORD   dwDisMode);

//��ָ����PT�����������
EXPORT BOOL W3DAddPTModSound(DWORD   dwModID,
						                                 DWORD   dwSoundVolume,//��ʼ����
														 char*         pszSoundFileName,
														 BOOL       bPlayByDis,
														 BOOL*     pbSuccessAdd,
														 DWORD* pdwPlayPosID,
														 DWORD   dwDisMode);

//�����û��ӵ���ģʽ
EXPORT BOOL W3DUserViewShakeMode(float fRange);

//��õ�������갴ť״̬
EXPORT BOOL W3DGetSingleMouseButtonStatus(DWORD dwButtonType,bool* pStatus);

//������е���갴ť״̬
EXPORT BOOL W3DGetAllMouseButtonStatus(int ListLen,bool* pbStatusList);

//��õ���������¼�״̬
EXPORT BOOL W3DGetSingleMouseEventStatus(DWORD dwEventType,bool* pStatus);

//������е�����¼�״̬
EXPORT BOOL W3DGetAllMouseEventStatus(int ListLen,bool* pbStatusList);

//��õ����İ�����Ϣ
EXPORT BOOL W3DGetSingleKeyInfo(char key,bool* pResult);

 //������еİ�����Ϣ
EXPORT BOOL W3DGetKeysInfo(bool* pbKeys);

//����ֹͣ����
EXPORT BOOL W3DStopAnimImmly(DWORD dwModID,DWORD dwAnimTypeID);

 //ֹͣ����
EXPORT BOOL W3DStopAnim(DWORD dwModID);

//������ͨ�����Ƿ��������
EXPORT BOOL W3DSetPTDrawWord(DWORD dwModID,DWORD dwMode);

//���÷��������Ƿ��������
EXPORT BOOL W3DSetFMDrawWord(DWORD dwModID,DWORD dwMode);

//������ͷ���Ŷ���
EXPORT BOOL W3DPlayAnimFromStartImmly(DWORD dwModID,
																					DWORD dwAnimTypeID,
																					DWORD dwPlayInterval,
																					DWORD dwPlayTime,
																					DWORD dwPlayMode,
																					BOOL     bCannotInterrupt);

//�������Ŷ���
EXPORT BOOL W3DPlayAnimImmly(DWORD dwModID,
																    DWORD dwAnimTypeID,
																    DWORD dwPlayInterval,
																    DWORD dwPlayTime,
																    DWORD dwPlayMode,
																    BOOL     bCannotInterrupt);

//��Ӳ��Ŷ�������
EXPORT BOOL W3DAddAnimRequest(DWORD dwModID,
													   DWORD dwAnimTypeID,
													   DWORD dwPlayInterval,
													   DWORD dwPlayTime,
													   DWORD dwPlayMode,
													   BOOL     bCannotInterrupt);

//��Ӳ��Ŷ����б�����
EXPORT BOOL W3DAddAnimListRequest(DWORD   dwModN,
													 DWORD* pdwModIDList,
													 DWORD* pdwAnimTypeIDList,
													 DWORD* pdwPlayIntervalList,
													 DWORD* pdwPlayTimeList,
													 DWORD* pdwPlayModeList,
													 BOOL*     pbCannotInterruptList);
//�������Ŷ����б�
EXPORT BOOL W3DPlayAnimListImmly(DWORD   dwModN,
												  DWORD* pdwModIDList,
												  DWORD* pdwAnimTypeIDList,
												  DWORD* pdwPlayIntervalList,
												  DWORD* pdwPlayTimeList,
												  DWORD* pdwPlayModeList,
												  BOOL*     pbCannotInterruptList);
//������ͷ���Ŷ����б�
EXPORT BOOL W3DPlayAnimListFromStartImmly(DWORD   dwModN,
																 DWORD* pdwModIDList,
																 DWORD* pdwAnimTypeIDList,
																 DWORD* pdwPlayIntervalList,
																 DWORD* pdwPlayTimeList,
																 DWORD* pdwPlayModeList,
																 BOOL*     pbCannotInterruptList);
//ֹͣ�����б�
EXPORT BOOL W3DStopAnimList(DWORD dwModN, DWORD* pdwModIDList);
//����ֹͣ�����б�
EXPORT BOOL W3DStopAnimListImmly(DWORD dwModN,DWORD* pdwModIDList,DWORD* pdwAnimTypeIDList);

//������ͨ�����Ƿ������ײ���
EXPORT BOOL W3DSetPTColldCheck(DWORD dwModID,BOOL bColldCheckOn);

//������ͨ�����Ƿ��������
EXPORT BOOL W3DSetPTGravityCtrl(DWORD dwModID,BOOL bGravityCtrlOn,BOOL bResetGravity);

//�����û������ӵ�
EXPORT BOOL W3DSetUserViewTracePos(float fPosX,
															  float fPosY,
															  float fPosZ,					  
															  float fFarPosX,
															  float fFarPosY,
															  float fFarPosZ);

//����û���������
EXPORT BOOL W3DGetUserCommonData(DWORD dwDataType,DWORD dwDataIndex,void* pDataReturn,BOOL bImmlyImplt);

//�����û���������
EXPORT BOOL W3DSaveUserCommonData(DWORD dwDataType,DWORD dwDataIndex,void* pDataSave,BOOL bImmlyImplt);


//�����ͨ����λ��(һ������ �������� ����������� ����)
EXPORT BOOL W3DGetPTModPos(DWORD dwModID,
							                                       vec3* pvTrans,
																   vec4* pvRot,
																   vec3* pvScl);

//��ö�̬��������λ��(�������� ����)
EXPORT BOOL W3DGetDyPhyModPos(DWORD dwModID,
								                                         mat4* pmTrans,
																		 mat4* pmRot,
																		 mat4* pmScl);


//������ͨ����λ��(���������� ������������� ����)
EXPORT BOOL W3DSetPTModPos(DWORD dwModID,
																   DWORD dwChangeMode,
																   vec3 vTrans,vec4 vRot,vec3 vScl);

//���÷�������λ��
EXPORT BOOL W3DSetFMModPos(DWORD dwModID,
						                           DWORD dwChangeMode,
						                           vec3 vTrans,vec4 vRot,vec3 vScl);

//���������������λ��(����������� ����)
EXPORT BOOL W3DSetDyCtrlModPos(DWORD dwModID,
													     DWORD dwChangeTransMode,
													     vec3 vTrans,
														 DWORD dwChangeRotMode,
														 vec4 vRot,
														 DWORD dwChangeSclMode,
														 vec3 vScl);

//�ı䶯̬���������λ��(��Ӹı�)(�������� ����)
EXPORT BOOL W3DSetPhyModPos(DWORD dwModID,
													 DWORD dwChangeTransMode,
													 DWORD dwChangeRotMode,
													 DWORD dwChangeSclMode,
													 vec3 vTrans,vec4 vRot,vec3 vScl,
													 mat4 mTrans,mat4 mRot,mat4 mScl);

//���ö�̬��������λ��(ֱ�Ӹı�)(�������� ����)
EXPORT BOOL W3DSetDyPhyModPos(DWORD dwModID,
								                                         DWORD bChangeTransMode,
																		 mat4 mTrans,
																		 DWORD bChangeRotMode,
																		 mat4 mRot,
																		 DWORD bChangeSclMode,
																		 mat4 mScl);

//����PT�����Ħ��ϵ��
EXPORT BOOL W3DSetPhyModFiction(DWORD dwModID,float fModFiction);

//����PT���������
EXPORT BOOL W3DSetPhyModWeight(DWORD dwModID,float fModWeight);

//����PT���������
EXPORT BOOL W3DSetPhyModForce(DWORD dwModID,float fModForce);

//���ӳٵ���ʱ����
EXPORT BOOL  W3DEventDelay(BOOL bReset,DWORD dwIndex, DWORD dwTime);

//����PT����Ĵ�����Ϣ
EXPORT BOOL W3DCleanPTModTriggerInfo(DWORD dwModID);

//����������Ĵ�����Ϣ
EXPORT BOOL W3DCleanSceneModTriggerInfo(DWORD dwModID);

//��ѯ��̬���������Ƿ�����ײ����
EXPORT BOOL W3DCheckPhyModColld(DWORD dwModID,BOOL* pbColld);

//��ѯPT����Ĵ�����Ϣ
EXPORT BOOL W3DInquirePTModTriggerInfo(DWORD dwModID,
																					DWORD dwFromModID,
																					BOOL*   pbResult);

//��ѯ��������Ĵ�����Ϣ
EXPORT BOOL W3DInquireSceneModTriggerInfo(DWORD dwModID,
																						DWORD dwFromModID,
																						BOOL*   pbResult);

//���PT�����ȫ����λ�� ע��:���������ʹ�����Զ������û� ���粻׼ȷ
EXPORT BOOL W3DGetPTModEnvelopePos(DWORD                        dwModID,
																 W3DModEnvelopeInfo* pstModEnvelopeInfo);

//ʹ��ָ���ľ������PT�����ȫ����λ��
EXPORT BOOL W3DCompPTModEnvelopePosByMatrix(DWORD                        dwModID,
																              W3DModEnvelopeInfo* pstModEnvelopeInfo,
																			  mat4                               mModMatrix);

//���Ԥ�ó��������ȫ����λ��
EXPORT BOOL W3DGetSceneModEnvelopePos(DWORD                        dwModID,
																	  W3DModEnvelopeInfo* pstModEnvelopeInfo);

//��÷��������λ��(���ĵ�)
EXPORT BOOL W3DGetFMModPos(DWORD dwModID,vec3* pvPos);

//���Ԥ�ó��������λ��(���ĵ�)
EXPORT BOOL W3DGetSceneModPos(DWORD dwModID,vec3* pvPos);

//���ó��������λ��
EXPORT BOOL W3DSetSceneModPos(DWORD dwModID,
															   BOOL bChangeTrans,
															   vec3 vTrans,
															   BOOL bChangeRot,
															   vec4 vRot,
															   BOOL bChangeScl,
															   vec3 vScl);

//��ѯ��������������
EXPORT BOOL W3DGetSceneModNum(DWORD* pdwNum);

//��ѯ����������ʾ״̬
EXPORT BOOL W3DGetSceneModShowStatus(DWORD dwModID,DWORD* pdwMode);

//���ó�����������
EXPORT BOOL W3DSetSceneModHide(DWORD dwModID,DWORD dwMode);

 //���ó���������ʾ
EXPORT BOOL W3DSetSceneModShow(DWORD dwModID,DWORD dwMode);

//��ͣϵͳ
EXPORT BOOL W3DPauseSys(BOOL bPause);

//��ѯ��Դ����
EXPORT BOOL W3DGetLightNum(DWORD* pDLightNum,DWORD* pSLightNum,DWORD* pCLightNum);

//���ù�Դ����
EXPORT BOOL W3DSetLightNum(DWORD DLightNum,DWORD SLightNum,DWORD CLightNum);

//������ͨ����۹��������
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

//�豸��ͨ���������
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

//����PT������ʵ��ʾ
EXPORT BOOL W3DSetPTModReal(DWORD dwModID,BOOL bReal);

//���ó���������ʵģʽ
EXPORT BOOL W3DSetSceneModReal(DWORD dwModID,BOOL bReal);

//����PT������ʵģʽ
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


//����Ԥ�ó���������ʵģʽ
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

//������ͨ�����Ƿ�����
EXPORT BOOL W3DSetPTModHide(DWORD dwModID,DWORD dwMode);

//��ѯ��ͨ����������
EXPORT BOOL W3DGetPTModNum(DWORD* pdwNum);

//��ѯ��ͨ������ʾ״̬
EXPORT BOOL W3DGetPTModShowStatus(DWORD dwModID,DWORD* pdwMode);

//������ͨ�����Ƿ���ʾ
EXPORT BOOL W3DSetPTModShow(DWORD dwModID,DWORD dwMode);

//������ͨ��������
EXPORT BOOL W3DSetPTModType(DWORD dwModID,DWORD dwType);

//���÷������������ɫ
EXPORT BOOL W3DSetFMModBasicColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//���÷�������������ɫ
EXPORT BOOL W3DSetFMModVirtualColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//������ͨ����������ɫ
EXPORT BOOL W3DSetPTModVirtualColor(DWORD dwModID,
								                                float fColR,
																float fColG,
																float fColB,
																float fColA);

//������ͨ���������ɫ
EXPORT BOOL W3DSetPTModBasicColor(DWORD dwModID,
																			  float fColR,
																			  float fColG,
																			  float fColB,
																			  float fColA);

//�豸��ͨ�����������
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

//�豸��ͨ���巽������
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

//�����û��ӵ�����ģʽ
EXPORT BOOL W3DSetUserViewLockMode(DWORD dwMode);
//������ͨģ�͵�����
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
//���÷���ģ�͵�����
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
//�����ͨģ�͵��Զ�����Ϣ
EXPORT BOOL W3DGetPTModCustomInfo(DWORD dwModID,PTModCustomInfo* p);
//������ͨģ�͵��Զ�����Ϣ
EXPORT BOOL W3DSetPTModCustomInfo(DWORD dwModID,PTModCustomInfo* p);
//�����ͨģ�͵���ת����
EXPORT BOOL W3DGetPTModRoSerl(DWORD dwModID,DWORD* pdwRoSerlN,vec4* pvRoSerl);
//������ͨģ�͵���ת����
EXPORT BOOL W3DSetPTModRoSerl(DWORD dwModID,DWORD dwRoSerlN,vec4* vRoSerl);
//����֡��������
EXPORT BOOL W3DSetFrameStream(DWORD  dwMode,BYTE* pStreamMem,BOOL* pbReadyToGenFrame);
//��÷��洰�ڴ�С
EXPORT BOOL W3DGetWindowInfo(DWORD* pdwWindowWidth,DWORD* pdwWindowHeight,HWND* hWindow);
//����ȫ��ģʽ������������
EXPORT BOOL W3DSetGVSensi(float fSensi);
//���ϵͳ״̬
EXPORT BOOL W3DGetSystemStatus(DWORD* dwStatus,DWORD* dwInfo);
 //����Ԥ�ó������û��ӵ�
EXPORT BOOL W3DResetSceneUserViewPoint(DWORD dwMode);
//�����û��ӵ�
EXPORT BOOL W3DSetUserViewPoint(ViewUserInfo* viewinfo,BOOL bAutoGenViewAngle);
//�Ƿ��Զ����ɳ����߿���
EXPORT BOOL W3DAutoGenLaneLine(DWORD dwMode);
//��̬��ͨԪ�ط��������ȿ���
EXPORT BOOL W3DDyTraObjSimSensi(float fSensi);
//��̬��ͨԪ������
EXPORT BOOL W3DResetDyTraObj(DWORD dwObjID,DWORD dwTmOut);
//��̬��ͨԪ�ز�ֵ��������
EXPORT BOOL W3DSetDyTraObjVehNum(DWORD dwVehN);
//��̬��ͨԪ�ط���ӿ�
EXPORT BOOL W3DDynamicTrafficObjectSim(DyTraObjFrameData* stFrameData);
//��̬��ͨԪ���첽����ӿ�
EXPORT BOOL W3DDynamicTrafficObjectAsynSim(DyTraObjFrameData* stFrameData);
//��ѯԪ��
EXPORT BOOL W3DInquireObject(DWORD dwCategory,DWORD dwID);
//�������
EXPORT BOOL W3DRingView();
//���㻷�����
EXPORT BOOL W3DRingViewOnPos(float farposx,float farposy,float farposz,float userposy,float dis,float startang);
//���÷������ʾģʽ
EXPORT BOOL W3DSetSceneDrawMode(DWORD dwMode);
//����·����ʾģʽ
EXPORT BOOL W3DSetRoadShowMode(DWORD dwMode,DWORD dwTexID);
//������ʾ��Ϣ����ʾʱ��
EXPORT BOOL W3DSetTipShowTime(DWORD dwTime);
//��ѯ��ǰ�۲�����Ϣ
EXPORT BOOL W3DInquireViewUserInfo(ViewUserInfo* viewinfo);
//����ĳһ��·��Ԫ��
EXPORT BOOL W3DAddLCInfo(LCSelInfo* lcinfo);
//ɾ��ĳһ��·��Ԫ��
EXPORT BOOL W3DDelLCInfo(DWORD id);
//����·����Ϣ
EXPORT BOOL W3DSaveLCInfo();
//����ת���ͻ����ڵľ��
EXPORT BOOL W3DSetClientWin(HWND hClietWn,DWORD dwMode);
//������Ϣ����ģʽ
EXPORT BOOL W3DSetMessageListMode(DWORD dwMode);
//����������Ϣ
EXPORT BOOL W3DGetFirstMessage(BOOL* pbMsgExist,W3DMsgInfo* pstFirstMsg);
//����·������Ϣ
EXPORT BOOL W3DSetLCInfo(LCSelInfo* lcinfo);

//���õ����־����Ϣ
EXPORT BOOL W3DSetDMBZInfo(DMBZSelInfo* dmbzinfo);

//���ò�������Ϣ
EXPORT BOOL W3DSetBHInfo(BHSelInfo* bhinfo);
//��ÿɱ��־����Ϣ
EXPORT BOOL W3DGetKbbzInfo(KBBZSelInfo* kbbzinfo);
//����ձ��־����Ϣ
EXPORT BOOL W3DGetBzpInfo(BzpSelInfo* bzpinfo);
//���ÿɱ��־����Ϣ
EXPORT BOOL W3DSetKbbzInfo(KBBZSelInfo* kbbzinfo);
//�����ձ��־����Ϣ
EXPORT BOOL W3DSetBzpInfo(BzpSelInfo* bzpinfo);
//����ѡ��ͨԪ��
EXPORT BOOL W3DFinishSelectObj();

//��ý�ͨGPS��У׼��Ϣ
EXPORT BOOL W3DGetTrafficGPSCalibInfo(GPSCalibInfo* gpscab);

//��ѯ�Ƿ��н�ͨԪ�ر�ѡ�� ������ѡ�е�Ԫ����Ϣ
EXPORT BOOL W3DInquireSelectedObj(W3DSelectedObjInfo* pstSelObjInfo);

//���浼����ʾ����
EXPORT BOOL W3DRdDirctTip(BOOL bOn);
//ѡ��·�������������ͼ
EXPORT BOOL W3DSetRoadTex(DWORD dwTexID);
//�Ƿ���ʾԭʼgps·����
EXPORT BOOL W3DShowOrignGPSPoint(BOOL bShow);
//������ʾ����
EXPORT BOOL W3DDMBHTip(DWORD dwMode);
//·����ʾ����
EXPORT BOOL W3DLCTip(DWORD dwMode);
//�ɱ��־��ʾ����
EXPORT BOOL W3DKBBZTip(DWORD dwMode);
//��ͨ��־��ʾ����
EXPORT BOOL W3DBzpTip(DWORD dwMode);
//ȫ����ʾ����
EXPORT BOOL W3DGlobalTip(BOOL bOn);
//�������
EXPORT BOOL W3DAerialView();
//ȫ�����
EXPORT BOOL W3DGlobalView();
//�Զ�Ѳ��
EXPORT BOOL W3DAutoTraceWander(BOOL bOn);
//׷������
EXPORT BOOL W3DTraceWander();
//��������
EXPORT BOOL W3DFreeWander();
//�رշ���ϵͳ
EXPORT BOOL W3DExitSys();

//���ü��ؽ�ͨ���ݿ������
EXPORT BOOL W3DSetLoadTrafficDatabaseInfo(BOOL bLoadBzp,
																		BOOL bLoadKbbz,
																		BOOL bLoadHL,
																		BOOL bLoadDMBX,
																		BOOL bLoadDMBZ,
																		BOOL bLoadBH,
																		BOOL bLoadLC);

//�Զ�ˢ�·���
EXPORT BOOL W3DAutoSim(BOOL bOn);
//�ֶ�ˢ�·���
EXPORT BOOL W3DManualSim();
//������ں���
EXPORT BOOL W3DProxy(WCHAR* wszAppPath,HWND   hParentHwnd, W3DBuildInfo* pstW3DBuildInfo);
  