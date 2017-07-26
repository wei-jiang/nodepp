#ifndef _HVCAMARA_H__
#define _HVCAMARA_H__

#include "HvDeviceBaseType.h"
#include "HvDeviceCommDef.h"

#ifdef HVDEVICE_EXPORTS
#define HV_API_EX extern "C" __declspec(dllexport)
#elif HVDEVICE_LIB
#define HV_API_EX
#else
#define HV_API_EX extern "C" __declspec(dllimport)
#endif

#define HVAPI_API_VERSION_EX	"2.0"
typedef PVOID HVAPI_HANDLE_EX;         /**< HvAPI������� */

/**
* @brief		������Ƶ��֡��
* @param[in]	hHandle				��Ӧ�豸����Ч���
* @param[in]	nStreamId			��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	nFps				֡��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetStreamFps(HVAPI_HANDLE_EX hHandle, INT nStreamId, INT nFps);

/**
* @brief		����H264���ʿ��Ʒ�ʽ
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nType			0��VBR ,1 CBR
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetH264BitRateControl(HVAPI_HANDLE_EX hHandle, INT nType );

/**
* @brief		����H264����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nBitRate		��Χ 32768~8388608(32Kbps-8Mbps)
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetH264BitRate(HVAPI_HANDLE_EX hHandle, INT nBitRate );

/**
* @brief		����JPEGѹ������
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nJpegCompressRate		��Χ 20��80
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetJpegCompressRate(HVAPI_HANDLE_EX hHandle, INT nJpegCompressRate );


/**
* @brief		�����ַ����ӿ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	fOSDEnable		0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDEnable(HVAPI_HANDLE_EX hHandle, INT nStreamId ,BOOL fOSDEnable);
/**
* @brief		���ó����ַ����ӿ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	fOSDEnable		0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDPlateEnable(HVAPI_HANDLE_EX hHandle, INT nStreamId ,BOOL fOSDEnable);

/**
* @brief		�����ַ�����-ʱ����ӿ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	fEnable			�ַ�����ʱ����ӿ��أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDTimeEnable(HVAPI_HANDLE_EX hHandle, INT nStreamId, BOOL fEnable);

/**
* @brief		�����ַ�����λ��
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	nPosX			����λ��X���꣬��Χ: 0~ͼ���
* @param[in]	nPosY			����λ��Y���꣬��Χ��0~ͼ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDPos( HVAPI_HANDLE_EX hHandle,INT nStreamId, INT nPosX ,INT nPosY );

/**
* @brief		�����ַ���������
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	nFontSize		�����С����Χ��16~32
* @param[in]	nColorR			������ɫRֵ����Χ0��255
* @param[in]	nColorG			������ɫGֵ����Χ0��255
* @param[in]	nColorB			������ɫBֵ����Χ0��255
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDFont(HVAPI_HANDLE_EX hHandle, INT nStreamId ,INT nFontSize ,
										 INT nColorR ,INT nColorG,INT nColorB);
/**
* @brief		�����ַ������ַ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID��0��H264,1:MJPEG
* @param[in]	szText			�����ַ��� ���ȷ�Χ��0��255
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOSDText(HVAPI_HANDLE_EX hHandle, INT nStreamId,CHAR* szText  );

/**
* @brief		����CVBS��ʽ
* @param[in]	hHandle		��Ӧ�豸����Ч���
* @param[in]	nMode		CVBS��ʽ����Χ��0:PAL,1:NTSC
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetCVBDisPlayMode(HVAPI_HANDLE_EX hHandle, INT nMode );

/**
* @brief		�����ֶ�����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nShutter		���ţ���Χ��100~30000
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualShutter(HVAPI_HANDLE_EX hHandle, INT nShutter );

/**
* @brief		�����ֶ�����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nGain			���棬��Χ��0~42
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualGain(HVAPI_HANDLE_EX hHandle, INT nGain );

/**
* @brief		����AWB����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			AWB����,��Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetAWBEnable(HVAPI_HANDLE_EX hHandle, INT nEnable );

/**
* @brief		�����ֶ�RGB
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nGainR			Rֵ����Χ��0��255
* @param[in]	nGainG			Gֵ����Χ��0��255
* @param[in]	nGainB			Bֵ����Χ��0��255
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualRGB(HVAPI_HANDLE_EX hHandle, INT nGainR, INT nGainG, INT nGainB  );


/**
* @brief		����AGCʹ�ܿ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			���أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetAGCEnable(HVAPI_HANDLE_EX hHandle, INT nEnable );


/**
* @brief		����AGC��׼ֵ
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nLightBaseLine	��׼ֵ����Χ��0��255
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetAGCLightBaseLine(HVAPI_HANDLE_EX hHandle, INT nLightBaseLine );


/**
* @brief		����AGC����
* @param[in]	hHandle		��Ӧ�豸����Ч���
* @param[in]	rgZone		AGC����ֵ����Χ��0�������⣬1��������
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetAGCZone(HVAPI_HANDLE_EX hHandle, INT rgZone[16] );

/**
* @brief		��ȡAGC�������,16��ֵ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	rgZone[16]	    ACG����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_GetAGCZone(HVAPI_HANDLE_EX hHandle, INT rgZone[16]);


/**
* @brief		����AGC����
* @param[in]	hHandle		��Ӧ�豸����Ч���
* @param[in]	nShutterMin ,AGC��С���ţ���Χ�� 100~30000
* @param[in]	nShutterMax ,AGC�����ţ���Χ�� 100~30000
* @param[in]	nGainMin    ,AGC��С���棬��Χ�� 0~42
* @param[in]	nGainMax    ,AGC������棬��Χ�� 0~42
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetAGCParam(HVAPI_HANDLE_EX hHandle,INT nShutterMin , INT nShutterMax ,
										  INT nGainMin , INT nGainMax );

/**
* @brief		��������LUT
* @param[in]	hHandle				��Ӧ�豸����Ч���
* @param[in]	rgLUT				LUT��
* @param[in]	nLUTPointCount		LUT��������Χ��8
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetLUT(HVAPI_HANDLE_EX hHandle, CHvPoint rgLUT[] , INT nLUTPointCount );

/**
* @brief		��ȡ����LUT״̬
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	rgLUT			LUT��״̬
* @param[in]	pnLUTPointCount	LUT������
** @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_GetLUT(HVAPI_HANDLE_EX hHandle, CHvPoint rgLUT[] , INT* pnLUTPointCount );


/**
* @brief		��������ֵ
* @param[in]	hHandle		 ��Ӧ�豸����Ч���
* @param[in]	nBrightness ,����ֵ����Χ��0��255  
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetBrightness(HVAPI_HANDLE_EX hHandle, INT nBrightness );


/**
* @brief		���öԱȶ�
* @param[in]	hHandle		 ��Ӧ�豸����Ч���
* @param[in]	nContrast    �Աȶ�ֵ����Χ��0��255  
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetContrast(HVAPI_HANDLE_EX hHandle, INT nContrast );


/**
* @brief		�������
* @param[in]	hHandle		 ��Ӧ�豸����Ч���
* @param[in]	nSharpness    �Աȶ�ֵ����Χ��0��255  
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetSharpness(HVAPI_HANDLE_EX hHandle, INT nSharpness );


/**
* @brief		���ñ��Ͷ�
* @param[in]	hHandle		 ��Ӧ�豸����Ч���
* @param[in]	nSaturation   ���Ͷ�ֵ����Χ��0��255  
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetSaturation(HVAPI_HANDLE_EX hHandle, INT nSaturation );


/**
* @brief		���ÿ�̬����
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	fEnable		  ��̬���أ���Χ��0���رգ�1����  
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetWDREnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable  );


/**
* @brief		���ÿ�̬�ȼ�
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	nLevel		  ��̬�ȼ�����Χ��0������1���У�2��ǿ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetWDRLevel(HVAPI_HANDLE_EX hHandle, INT nLevel );

/**
* @brief		������Ƶ����TNF����
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	fEnable		  ��Ƶ���뿪�أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDeNoiseTNFEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );


/**
* @brief		������Ƶ����SNF����
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	fEnable		  ��Ƶ���뿪�أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDeNoiseSNFEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );

/**
* @brief		������Ƶ����ģʽ
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	nMode		  ��Ƶ����ģʽ����Χ��0���ٶ� ��1������ ���ýӿ������踴λ��Ч
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDeNoiseMode(HVAPI_HANDLE_EX hHandle, INT nMode );

/**
* @brief		������Ƶ������Ͽ���
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	nMode		  ��Ƶ���뿪�أ���Χ��0��SNF,1:TNF,2:TNF+SNF
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDeNoiseSwitch(HVAPI_HANDLE_EX hHandle, INT nSwitch );

/**
* @brief		������Ƶ����ȼ�
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	nLevel		  ��Ƶ����ȼ�����Χ��0: �Զ� 1������2���У�3��ǿ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDeNoiseLevel(HVAPI_HANDLE_EX hHandle,INT nLevel );


/**
* @brief		�����˹�Ƭģʽ
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	nMode		  �˹�Ƭģʽ����Χ��0: �Զ���1�����˺��� ��2�������˺���
										 �������÷��Զ�ģʽ ���ϲ��ã�2 ������ã�1��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetFilterMode(HVAPI_HANDLE_EX hHandle, INT nMode );


/**
* @brief		�����˹�Ƭʹ��
* @param[in]	hHandle	      ��Ӧ�豸����Ч���	
* @param[in]	fEnable		  �˹�Ƭʹ�ܣ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetCtrlCplEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );


/**
* @brief		����DC��Ȧ�Զ�����
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	fEnable		  DC��Ȧ�Զ����ƿ��أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetDCIRIS(HVAPI_HANDLE_EX hHandle, BOOL fEnable );


/**
* @brief		����IP��Ϣ
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	szIP		  IP�ַ���
* @param[in]	szMask		  ���������ַ���
* @param[in]	szGateWay	  �����ַ���
* @param[in]	szDNS		  DNS�ַ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetIPInfo(HVAPI_HANDLE_EX hHandle, CHAR* szIP 
										,CHAR* szMask 
										,CHAR* szGateWay 
										,CHAR* szDNS  );

/**
* @brief		����RTSP�ಥ����
* @param[in]	hHandle	      ��Ӧ�豸����Ч���
* @param[in]	fEnable		RTSP�ಥ���أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetRTSPMulticastEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );


/**
* @brief		����ʱ��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	nYear		��
* @param[in]	nMon		��
* @param[in]	nDay		��
* @param[in]	nHour		ʱ
* @param[in]	nMin		��
* @param[in]	nSec		��
* @param[in]	nMSec		����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetTime(HVAPI_HANDLE_EX hHandle, INT nYear , INT nMon , INT nDay , INT nHour ,INT nMin , INT nSec , INT nMSec );

/**
* @brief		����ʱ��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	nZoneNum	 ʱ����� 0~24
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetTimeZone(HVAPI_HANDLE_EX hHandle, INT nZoneNum );

/**
* @brief		����NTP������IP
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	szIP		 NTP������IP�ַ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetNTPServerIP(HVAPI_HANDLE_EX hHandle, CHAR* szIP );


/**
* @brief		����NTP������IP
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	dw32UpdateIntervalMS		 ����NTP������ʱ����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetNTPServerUpdateInterval(HVAPI_HANDLE_EX hHandle,DWORD32 dw32UpdateIntervalMS );


/**
* @brief		����NTP����
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	fEnable		 NTP���񿪹� 0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetNTPEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );

/*
* @brief		����OC��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	fEnable		 ���أ���Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetOCGate(HVAPI_HANDLE_EX hHandle, BOOL fEnable );

/*
* @brief		����ɫ��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	nValue		 ��Χ��0:���Զ���; 32; 40 ;52 ;55 ; 60 ;70 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetColor(HVAPI_HANDLE_EX hHandle, INT nValue );

/*
* @brief		����2D���뿪��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	fEnable		 ��Χ��0���رգ�1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_Set2DDeNoiseEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable );

/*
* @brief		����2D����ǿ��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	nValue		 ��Χ��0��255
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_Set2DDeNoiseStrength(HVAPI_HANDLE_EX hHandle, INT nValue );

/*
* @brief		����GAMMA����
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	fEnable		 ��Χ��0�� �رգ� 1����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetGammaEnable(HVAPI_HANDLE_EX hHandle, BOOL fValue );

/*
* @brief		����GAMMAǿ��
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	fValue		 ��Χ��1��5
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetGammaStrength(HVAPI_HANDLE_EX hHandle, INT nValue );

/**
* @brief		��λ�豸
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_ResetDevice(HVAPI_HANDLE_EX hHandle , INT nRetsetMode );

/**
* @brief		�ָ�Ĭ������
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  
*/
HV_API_EX HRESULT CDECL HVAPI_RestoreDefaultParam(HVAPI_HANDLE_EX hHandle);

/**
* @brief		�ָ���������
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_RestoreFactoryParam(HVAPI_HANDLE_EX hHandle);

/**
* @brief		��ȡ�豸������Ϣ
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	pbasicInfo	 �豸������Ϣ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetDevBasicInfo(HVAPI_HANDLE_EX hHandle, CDevBasicInfo* pbasicInfo  );

/**
* @brief		��ȡ����ģʽ
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	pnRunMode	����ģʽָ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetRunMode(HVAPI_HANDLE_EX hHandle, INT* pnRunMode );

/**
* @brief		��ȡ�豸״̬
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	pState	 ״̬�ṹ��ָ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetDevState(HVAPI_HANDLE_EX hHandle, CDevState* pState  );

/**
* @brief		��ȡ�豸״̬
* @param[in]	hHandle	     ��Ӧ�豸����Ч���
* @param[in]	pReportBuf	 ��λ�����ڴ�ָ��
* @param[in]	pnBufLen	 ��λ�������ݳ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetResetReport(HVAPI_HANDLE_EX hHandle,CHAR* pReportBuf, INT* pnBufLen  );

/**
* @brief		��ȡ�豸״̬
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	pnResetCount	��λ����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetResetCount(HVAPI_HANDLE_EX hHandle, INT* pnResetCount );

/**
* @brief		��ȡ�豸״̬
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szLog			������־�����ڴ�ָ��
* @param[in]	pnLogLen		������־���ݳ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetLog(HVAPI_HANDLE_EX hHandle, CHAR* szLog , INT* pnLogLen );

/**
* @brief		��ȡ�豸״̬
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	pVideoState		��Ƶ״̬
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetVideoState(HVAPI_HANDLE_EX hHandle, CVideoState* pVideoState );

/**
* @brief		��ȡ���״̬
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	pCameraState	���״ָ̬��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetCameraState(HVAPI_HANDLE_EX hHandle, CCameraState* pCameraState );


/**
* @brief		��ȡ���������Ϣ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	pCameraBasicInfo	���������Ϣָ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetCameraBasicInfo(HVAPI_HANDLE_EX hHandle, CCameraBasicInfo* pCameraBasicInfo );

/**
* @brief		��ȡӲ�̼�ⱨ��
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szReport		��ⱨ��
* @param[in]	piReportLen		��ⱨ�泤��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetHddCheckReport(HVAPI_HANDLE_EX hHandle, CHAR* szReport , INT *piReportLen  );

/**
* @brief		��ȡ�ַ�������Ϣ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	nStreamId		��Ƶ��ID
* @param[in]	pOSDInfo		�ַ�������Ϣ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetOSDInfo(HVAPI_HANDLE_EX hHandle,  INT nStreamId , COSDInfo* pOSDInfo  );


/**
* @brief		��¼
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szUserName		�û����ַ���  ���ȷ�Χ��4��16�ֽ�
* @param[in]	szPassword		�����ַ���  ���ȷ�Χ��4��16�ֽ�
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_Login(HVAPI_HANDLE_EX hHandle, CHAR* szUserName ,  CHAR* szPassword  );

/**
* @brief		�����û�
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szUserName		�û����ַ��� ���ȷ�Χ��4��16�ֽ�
* @param[in]	szPassword		�����ַ���  ���ȷ�Χ��4��16�ֽ�
* @param[in]	nAuthority		�û��ȼ�
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
* @Remark		�˽ӿڵ���ǰ����ɹ�����HVAPI_Login
*/
HV_API_EX HRESULT CDECL HVAPI_AddUser( HVAPI_HANDLE_EX hHandle, CHAR* szUserName , CHAR* szPassword,  INT nAuthority );

/**
* @brief		ɾ���û�
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szUserName		�û����ַ���  ���ȷ�Χ��4��16�ֽ�
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
* @Remark		�˽ӿڵ���ǰ����ɹ�����HVAPI_Login
*/
HV_API_EX HRESULT CDECL HVAPI_DelUser(HVAPI_HANDLE_EX hHandle, CHAR* szUserName );

/**
* @brief		��ȡ�û��б�
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	rgUserInfo		�û���Ϣ�б�
* @param[in]	pnUserCount		�û���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
* @Remark		�˽ӿڵ���ǰ����ɹ�����HVAPI_Login
*/
HV_API_EX HRESULT CDECL HVAPI_GetUsersList(HVAPI_HANDLE_EX hHandle, CUserInfo rgUserInfo[] , INT* pnUserCount );

/**
* @brief		�޸��û���Ϣ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szUserName		�û����ַ���  ���ȷ�Χ��4��16�ֽ�
* @param[in]	szOldPassword	�����ַ���	  ���ȷ�Χ��4��16�ֽ�
* @param[in]	szNewPassword	�����ַ���	  ���ȷ�Χ��4��16�ֽ�
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
* @Remark		�˽ӿڵ���ǰ����ɹ�����HVAPI_Login
*/
HV_API_EX HRESULT CDECL HVAPI_ModUser(HVAPI_HANDLE_EX hHandle,CHAR* szUserName ,CHAR* szOldPassword, CHAR* szNewPassword );
/**
* @brief		����ͼƬ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	pCapImage		ץ��ͼ�ڴ�ָ��
* @param[in]	pnCapImageSize	ץ��ͼ�ڴ��С
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_TriggerImage(HVAPI_HANDLE_EX hHandle, PBYTE pCapImage , INT* pnCapImageSize );


/**
* @brief		�����豸���ڼ�⹦��
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	nCOMNum			������������
* @param[in]	fEnable	        ���ر�ʶ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartCOMCheck(HVAPI_HANDLE_EX hHandle, INT nCOMNum, BOOL fEnable );


/**
* @brief		�������ʹ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetSharpnessEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable);

/**
* @brief		���������Ȧ�Ŵ� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_ZoomDCIRIS(HVAPI_HANDLE_EX hHandle); 

/**
* @brief		���������Ȧ��С 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_ShrinkDCIRIS(HVAPI_HANDLE_EX hHandle); 



/**
* @brief		�ڰ�ͼģʽ
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	fEnable	        ������־
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetGrayImageEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable); 


/**
* @brief		����ͬ��
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	nLevel	        ����ͬ��ģʽ
* @param[in]	dwDelayMS	    ͬ����ʱ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetACSync(HVAPI_HANDLE_EX hHandle, INT nLevel, DWORD32 dw32DelayMS); 

/**
* @brief		���õ�����������
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	fEnable			������������
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetDebugJpegStatus(HVAPI_HANDLE_EX hHandle, BOOL fEnable);  

/**
* @brief		�����Զ������������
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartCameraTest(HVAPI_HANDLE_EX hHandle);  

/**
* @brief		����jpeg�Զ�ѹ��ʹ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetAutoJpegCompressEnable(HVAPI_HANDLE_EX hHandle,  BOOL fEnable);

/**
* @brief		��ȡ���Եȼ�
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetTraceRank(HVAPI_HANDLE_EX hHandle, INT nlevel);

/**
* @brief		����jpeg�Զ�ѹ������
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetAutoJpegCompressParam (HVAPI_HANDLE_EX hHandle, INT nMaxCompressRate, INT nMinCompressRate, INT nImageSize);

/**
* @brief		����ͼ����ǿʹ��
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetImageEnhancementEnable(HVAPI_HANDLE_EX hHandle, BOOL fEnable);

/**
* @brief		���ú�ƼӺ���ֵ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetEnRedLightThreshold(HVAPI_HANDLE_EX hHandle, INT nValue);

/**
* @brief		�������ӱ�Ե��ǿ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetEdgeEnhance(HVAPI_HANDLE_EX hHandle, INT nValue);

/**
* @brief		��ȡ��Ƶ�ɼ�������Ϣ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetRunStatusString(HVAPI_HANDLE_EX hHandle, CHAR* szRunStatusString, INT* pnRunStatusStringLen  );

/**
* @brief		��ȡ�������������״̬
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetCameraWorkState(HVAPI_HANDLE_EX hHandle, CHAR* szStatus, INT* pnStatusStringLen  );

/**
* @brief		��ȡӲ��״̬
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetHDDStatus(HVAPI_HANDLE_EX hHandle, CHAR* szStatus, INT* pnStatusStringLen  );


/**
* @brief		���ô���ץ������IO�ڴ�������
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetTGIO(HVAPI_HANDLE_EX hHandle, INT nValue  );

/**
* @brief		��ȡ����ץ������IO�ڴ�������
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetTGIO(HVAPI_HANDLE_EX hHandle, INT* pnValue  );

/**
* @brief		���ô������IO��״̬ 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetF1IO(HVAPI_HANDLE_EX hHandle, INT nPolarity, INT nType);

/**
* @brief		��ȡ�������IO��״̬
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetF1IO(HVAPI_HANDLE_EX hHandle, INT* pnPolarity, INT* pnType);


/**
* @brief		���ò����IO��״̬ 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetEXPIO(HVAPI_HANDLE_EX hHandle, INT nPolarity, INT nType);


/**
* @brief		��ȡ�����IO��״̬ 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetEXPIO(HVAPI_HANDLE_EX hHandle, INT* pnPolarity, INT* pnType);


/**
* @brief		���ñ���IO��״̬ 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetALMIO(HVAPI_HANDLE_EX hHandle, INT nPolarity, INT nType);


/**
* @brief		��ȡ����IO��״̬ 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetALMIO(HVAPI_HANDLE_EX hHandle, INT* pnPolarity, INT* pnType);

/**
* @brief		����MJPEG����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetMJPEGRect(HVAPI_HANDLE_EX hHandle, CHvPoint PosTopLeft, CHvPoint PosLowerRight);


/**
* @brief		����ɫ�� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetColorGradation(HVAPI_HANDLE_EX hHandle, INT nValue);

/**
* @brief		������Ƶ������� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetVedioRequestControl(HVAPI_HANDLE_EX hHandle, BOOL fEnable,  DWORD32 dwIP, INT nPort);

/**
* @brief		����AE���� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetAEScene(HVAPI_HANDLE_EX hHandle, INT nMode);

/**
* @brief		��ȡAE���� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetAEScene(HVAPI_HANDLE_EX hHandle, INT* pnMode);


/**
* @brief		��ȡ�豸�� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetCustomizedDevName(HVAPI_HANDLE_EX hHandle, CHAR* pszDevName, INT* pnDevNameLen);


/**
* @brief		�����豸�� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetCustomizedDevName(HVAPI_HANDLE_EX hHandle, CHAR* pszDevName);


/**
* @brief		����H264����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nBitRate		
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_SetH264SecondBitRate(HVAPI_HANDLE_EX hHandle, INT nBitRate );


/**
* @brief		��ȡH264����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	pnBitRate		
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL  ��������쳣��S_FALSE
*/
HV_API_EX HRESULT CDECL HVAPI_GetH264SecondBitRate(HVAPI_HANDLE_EX hHandle, INT* pnBitRate );

/**
* @brief		����ץ��
* @param[in]	hHandle			��Ӧ�豸����Ч���	
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SoftTriggerCapture(HVAPI_HANDLE_EX hHandle);

/**
* @brief		����ץ�Ŀ���
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			ʹ�ܿ���
* @param[in]	nValue			ץ�Ŀ���ֵ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualCaptureShutter(HVAPI_HANDLE_EX hHandle, INT nEnable, INT nValue);

/**
* @brief		����ץ������
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			ʹ�ܿ���
* @param[in]	nValue			ץ������ֵ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualCaptureGain(HVAPI_HANDLE_EX hHandle, INT nEnable, INT nValue);

/**
* @brief		����ץ��RGB����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			ʹ�ܿ���
* @param[in]	nValueR			ץ��R����
* @param[in]	nValueG			ץ��G����
* @param[in]	nValueB			ץ��B����
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualCaptureRGB(HVAPI_HANDLE_EX hHandle, INT nEnable, INT nValueR, INT nValueG, INT nValueB);

/**
* @brief		����ץ�����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nEnable			ʹ�ܿ���
* @param[in]	nValue			ץ�����ֵ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetManualCaptureSharpen(HVAPI_HANDLE_EX hHandle, INT nEnable, INT nSharpen);

/**
* @brief		����LED����
* @param[in]	hHandle			��Ӧ�豸����Ч���
* @param[in]	nValue			����ֵ
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetExpPluseWidth(HVAPI_HANDLE_EX hHandle, INT nValue);

#endif
