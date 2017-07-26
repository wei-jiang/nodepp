#ifndef _HVDEVICENEW_H__
#define _HVDEVICENEW_H__

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
* @brief			ʶ������ʼ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_INFOBEGIN)(PVOID pUserData, DWORD dwCarID);

/**
* @brief			ʶ���������ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_INFOEND)(PVOID pUserData, DWORD dwCarID);

/**
* @brief			���ƻص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @param[out]		pcPlateNo		�����ַ���
* @param[out]		pcAppendInfo	���Ƹ�����Ϣ
* @param[out]		dw64TimeMS		ʶ��ʱ��
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_PLATE)(PVOID pUserData,
												 DWORD dwCarID,
												 LPCSTR pcPlateNo,
												 LPCSTR pcAppendInfo,
												 DWORD dwRecordType,
												 DWORD64 dw64TimeMS);

/**
* @brief			ʶ������ͼ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @param[out]		wImgType		��ͼ����
* @param[out]		wWidth			��ͼ��
* @param[out]		wHeight			��ͼ��
* @param[out]		pbPicData		��ͼ����
* @param[out]		dwImgDataLen	��ͼ���ݳ���
* @param[out]		dw64TimeMS		ʶ��ʱ��
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_BIGIMAGE)(PVOID pUserData,
													DWORD dwCarID, 
													WORD  wImgType,
													WORD  wWidth,
													WORD  wHeight,
													PBYTE pbPicData,
													DWORD dwImgDataLen,
													DWORD dwRecordType,
													DWORD64 dw64TimeMS);

/**
* @brief			ʶ��������Сͼ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @param[out]		wWidth			Сͼ��
* @param[out]		wHeight			Сͼ��
* @param[out]		pbPicData		Сͼ����
* @param[out]		dwImgDataLen	Сͼ���ݳ���
* @param[out]		dw64TimeMS		ʶ��ʱ��
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_SMALLIMAGE)(PVOID pUserData,
													  DWORD dwCarID,
													  WORD wWidth,
													  WORD wHeight,
													  PBYTE pbPicData,
													  DWORD dwImgDataLen,
													  DWORD dwRecordType,
													  DWORD64 dw64TimeMS);

/**
* @brief			ʶ�������ƶ�ֵͼ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		dwCarID			����ID
* @param[out]		wWidth			��ֵͼ��
* @param[out]		wHeight			��ֵͼ��
* @param[out]		pbPicData		��ֵͼ����
* @param[out]		dwImgDataLen	��ֵͼ���ݳ���
* @param[out]		dw64TimeMS		ʶ��ʱ��
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_RECORD_BINARYIMAGE)(PVOID pUserData,
													   DWORD dwCarID,
													   WORD wWidth,
													   WORD wHeight,
													   PBYTE pbPicData,
													   DWORD dwImgDataLen,
													   DWORD dwRecordType,
													   DWORD64 dw64TimeMS);

/**
* @brief			ʶ������Ϣ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		pString			��Ϣ�ַ���
* @param[out]		dwStrLen		��Ϣ�ַ�������
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_STRING)(PVOID pUserData, LPCSTR pString, DWORD dwStrLen);

/**
* @brief			ʶ������Ϣ�ص�����
* @param[out]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		pString			��Ϣ�ַ���
* @param[out]		dwStrLen		��Ϣ�ַ�������
* @param[out]		dwType			��Ϣ�ַ������� ��ʷ��ʵʱ
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_TFD_STRING)(PVOID pUserData, LPCSTR pString, DWORD dwStrLen, DWORD dwType);


/**
* @brief			ͼƬ�ص�����
* @param[out]		pUserData			��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		pbImageData			ͼƬ����
* @param[out]		dwImageDataLen		ͼƬ���ݳ���
* @param[out]		dwImageType			ͼƬ����
* @param[out]		szImageExtInfo		ͼƬ��Ϣ
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_JPEG)(PVOID pUserData,
										 PBYTE pbImageData,
										 DWORD dwImageDataLen,
										 DWORD dwImageType,
										 LPCSTR szImageExtInfo);

/**
* @brief			��Ƶ�ص�����
* @param[out]		pUserData			��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		pbVideoData			��Ƶ֡����
* @param[out]		dwVideoDataLen		��Ƶ֡���ݳ���
* @param[out]		dwVideoType			��Ƶ֡����
* @param[out]		szVideoExtInfo		��Ƶ֡��Ϣ
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_H264)(PVOID pUserData,
										 PBYTE pbVideoData,
										 DWORD dwVideoDataLen,
										 DWORD dwVideoType,
										 LPCSTR szVideoExtInfo);

/**
* @brief			��ʷ��Ƶ�ص�����
* @param[out]		pUserData			��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[out]		pbVideoData			��Ƶ֡����
* @param[out]		dwVideoDataLen		��Ƶ֡���ݳ���
* @param[out]		dwVideoType			��Ƶ֡����
* @param[out]		szVideoExtInfo		��Ƶ֡��Ϣ
* @return			�ɹ�S_OK ʧ�� E_FAILE
*/
typedef INT (CDECL* HVAPI_CALLBACK_HISTORY_VIDEO)(PVOID pUserData,
												  PBYTE pbVideoData,
												  DWORD dwVideoDataLen,
												  DWORD dwVideoType,
												  LPCSTR szVideoExtInfo);


//�ص������Ķ���

/**
* @brief               ��Ƶ�ص�����
* @param[out]          pUserData          ��HVAPI_StartRecvH264Video���õĴ���ص��������û�����ָ��
* @param[out]          dwVedioFlag        ��Ƶ��� ����Ч���ݱ�ǡ���Ч���ݱ�ǡ���ʷ�������
* @param[out]          dwVideoType        ��Ƶ���� ����ʷ��Ƶ��ʵʱ��Ƶ
* @param[out]          dwWidth            ���
* @param[out]          dwHeight			  �߶�
* @param[out]          dw64TimeMS         ��Ƶʱ��
* @param[out]          pbVideoData        ��Ƶ֡����
* @param[out]          dwVideoDataLen     ��Ƶ֡����
* @param[out]          szVideoExtInfo     ��Ƶ������Ϣ
* @return              �ɹ�S_OK ʧ�� E_FAILE
*/
typedef INT (CDECL* HVAPI_CALLBACK_H264_EX)(
												PVOID pUserData,  
												DWORD dwVedioFlag,
												DWORD dwVideoType, 
												DWORD dwWidth,
												DWORD dwHeight,
												DWORD64 dw64TimeMS,
												PBYTE pbVideoData, 
												DWORD dwVideoDataLen,
												LPCSTR szVideoExtInfo
												);

/**
* @brief               jpeg���ص�����
* @param[out]          pUserData          ��HVAPI_StartRecvH264Video���õĴ���ص��������û�����ָ��
* @param[out]          dwImageFlag        ͼƬ��� ����ЧͼƬ���ݡ���ЧͼƬ����
* @param[out]          dwImageType        ͼƬ���� ��������������������
* @param[out]          dwWidth            ���
* @param[out]          dwHeight			  �߶�
* @param[out]          dw64TimeMS         JPEGʱ��
* @param[out]          pbImageData        ͼƬ֡����
* @param[out]          dwImageDataLen     ͼƬ֡����
* @param[out]          szImageExtInfo     JPEG������Ϣ
* @return              �ɹ�S_OK ʧ�� E_FAILE
*/

typedef INT (CDECL* HVAPI_CALLBACK_JPEG_EX)(
											PVOID pUserData,  
											DWORD dwImageFlag,
											DWORD dwImageType, 
											DWORD dwWidth,
											DWORD dwHeight,
											DWORD64 dw64TimeMS,
											PBYTE pbImageData, 
											DWORD dwImageDataLen,
											LPCSTR szImageExtInfo
											);

/**
* @brief               ʶ�����ص�����
* @param[out]          pUserData          ��HVAPI_StartRecvResult���õĴ���ص��������û�����ָ��
* @param[out]          dwResultFlag		  �����־����Ч�����ǡ���Ч�����ǡ�������ʷ�������
* @param[out]          dwResultType		  ������ͣ�ʵʱ�������ʷ���
* @param[out]          dwCarID            ���ID
* @param[out]          pcPlateNo          �����ַ���
* @param[out]          dw64TimeMS		  ���ʱ��
* @param[out]          pPlate			  ����Сͼ
* @param[out]          pPlateBin          ���ƶ�ֵͼ
* @param[out]          pBestSnapshot      ��������ͼ
* @param[out]          pLastSnapshot      ����ͼ
* @param[out]          pBeginCapture      ��һ��ץ��ͼ
* @param[out]          pBestCapture       �ڶ���ץ��ͼ
* @param[out]          pLastCapture       ������ץ��ͼ
* @return              �ɹ�S_OK ʧ�� E_FAILE
*/
//ע�� plate ��ͼ Сͼ ��άͼ �ش���dwCardID��Ϣ��_string �� _tfd_string��dwCardID��Ϣ
typedef INT (CDECL* HVAPI_CALLBACK_RESULT)(
	PVOID pUserData, 
	DWORD dwResultFlag,			
	DWORD dwResultType,		
	DWORD dwCarID,
	LPCSTR pcPlateNo,
	LPCSTR pcAppendInfo,
	DWORD64 dw64TimeMS,
	CImageInfo   Plate,
	CImageInfo   PlateBin,
	CImageInfo   BestSnapshot,
	CImageInfo   LastSnapshot,
	CImageInfo   BeginCapture,
	CImageInfo   BestCapture,
	CImageInfo   LastCapture
	);

/**
* @brief			�����źŴ����ص�����
* @param[in]		pUserData		��HVAPI_SetCallBack���õĴ���ص��������û�����ָ��
* @param[in]		dwTime			����ʱ��
* @param[in]		dwRoadID		��·ͨ��ID
* @param[in]		dwTrigerID		����ID
* @return			0
*/
typedef INT (CDECL* HVAPI_CALLBACK_LISTEN_CMD)(PVOID pUserData,DWORD64 dwTime,DWORD dwRoadID,DWORD dwTrigerID);

/**
* @brief		�����豸
* @param[out]	pdwDeviceCount			�豸��
* @return		�ɹ�S_OK ʧ�� E_FAILE
*/
HV_API_EX HRESULT HVAPI_SearchDeviceCount(DWORD32* pdwDeviceCount);

/**
* @brief		��ȡ�豸IP
* @param[in]	dwIndex			����ʱ���������λ��
* @param[out]	dw64MacAddr		�豸MAC��ַ
* @param[out]	dwIP			�豸IP
* @param[out]	dwMask			����
* @param[out]	dwGateWay		����
* @return		�ɹ�S_OK ʧ�� E_FAILE
*/
HV_API_EX HRESULT HVAPI_GetDeviceAddr(DWORD32 dwIndex, DWORD64* dw64MacAddr, DWORD32* dwIP,
								   DWORD32* dwMask, DWORD32* dwGateWay);

/**
* @brief		    �����½ӿ� ע�ʹ�����
* @param[in,out]	rgDevInfo	���������豸��Ϣ�ṹ������
* @param[in,out]	pnDevCount	���������豸����
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL, ����ṹ������̫�٣�S_FALSE 
*/
HV_API_EX HRESULT CDECL HVAPI_SearchDeviceEx( CDevBasicInfo* rgDevInfo , INT* pnDevCount );

/**
* @brief		ͨ��MAC��ַ�����豸IP
* @param[in]	dw64MacAddr		�豸MAC��ַ
* @param[in]	dwIP			�豸IP
* @param[in]	dwMask			����
* @param[in]	dwGateWay		����
* @return		�ɹ�S_OK ʧ�� E_FAILE
*/
HV_API_EX HRESULT CDECL HVAPI_SetIPByMacAddr(DWORD64 dw64MacAddr, DWORD32 dwIP, DWORD32 dwMask, DWORD32 dwGateway);

/**
* @brief		������������Ϣ���ȡ�豸������Ϣ
* @param[in]	dwIndex			����ʱ���������λ��
* @param[out]	lpExtInfo		�豸������Ϣ����
* @param[in]	iBufLen			�豸������Ϣ���泤��
* @return		�ɹ�S_OK ʧ�� E_FAILE
*/
HV_API_EX HRESULT HVAPI_GetDeviceInfoEx(int iIndex, LPSTR lpExtInfo, int iBufLen);

/**
* @brief		��ȡ�豸����
* @param[in]	pcIP		�豸IP
* @param[out]	iDeviceType	�豸����
* @return		�ɹ�S_OK ʧ�� E_FAILE
*/
HV_API_EX HRESULT CDECL HVAPI_GetDevTypeEx(PSTR pcIP, int* iDeviceType);

/**
* @brief			���豸���
* @param[in]		szIp			�豸��IP��ַ
* @param[in]		szApiVer		��Ӧ�豸��API�汾��ע��ΪNULL��Ĭ��HVAPI_API_VERSION
* @return			�ɹ����豸�����ʧ�ܣ�NULL
*/
HV_API_EX HVAPI_HANDLE_EX CDECL HVAPI_OpenEx(LPCSTR szIp, LPCSTR szApiVer);

/**
* @brief			�ر��豸���
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_CloseEx(HVAPI_HANDLE_EX hHandle);

/**
* @brief			��ȡ�����豸ʹ�õ�XMLЭ��汾
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[out]		pemProtocolVersion	������ʹ�õ�XMLЭ��汾
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetXmlVersionEx(HVAPI_HANDLE_EX hHandle, PROTOCOL_VERSION* pemProtocolVersion);

/**
* @brief			��ȡ�����豸ʹ�õ�Э��汾
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[out]		pemProtocolVersion	������ʹ�õ�Э��汾
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetProtocolVersionEx(HVAPI_HANDLE_EX hHandle, PROTOCOL_VERSION* pemProtocolVersion);

/**
* @brief			��ȡ����״̬
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		nStreamType		���������ͣ������������ͣ�
* @param[out]		pdwConnStatus	�����ӵĵ�ǰ״̬
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetConnStatusEx(HVAPI_HANDLE_EX hHandle, INT nStreamType, DWORD* pdwConnStatus);

/**
* @brief			��ȡ��������
* @param[in]		hHandle				��Ӧ�豸����Ч���
* @param[in]		nStreamType			���������ͣ������������ͣ�
* @param[out]		pdwReConnectTimes	�����ӵĵ�ǰ��������
* @param[in]		fIsReset			��ȡ����Ƿ񽫸����ӵ�������������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetReConnectTimesEx(HVAPI_HANDLE_EX hHandle, INT nStreamType, DWORD* pdwReConnectTimes, BOOL fIsReset);


/**
* @brief			ִ������
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		szCmd			�������豸����ĳ��������ַ���
* @param[in]		szRetBuf		���ص�ִ�н��(XML��ʽ)
* @param[in]		nBufLen			szRetBuf�������ĳ���
* @param[out]		pnRetLen		ʵ�ʷ��ص�ִ�н�����ȡ�ע��ΪNULL����Ըò�����
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_ExecCmdEx(HVAPI_HANDLE_EX hHandle,
								   LPCSTR szCmd,
								   LPSTR szRetBuf,
								   INT nBufLen,
								   INT* pnRetLen);

/**
* @brief			��ȡ�豸����
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		szParamDoc		��ȡ���Ĳ�����XML��ʽ��
* @param[in]		nBufLen			szParam�������ĳ���
* @param[out]		pnRetLen		ʵ�ʷ��صĲ������ȡ�ע��ΪNULL����Ըò�����
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetParamEx(HVAPI_HANDLE_EX hHandle,
									LPSTR szParamDoc,
									INT nBufLen,
									INT* pnRetLen);

/**
* @brief			�����豸����
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		szParamDoc		Ҫ���浽�豸�Ĳ�����XML��ʽ��
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
* @warning			���Ĺ��Ĳ���Ҫ���豸�´�������Ż���Ч
*/
HV_API_EX HRESULT CDECL HVAPI_SetParamEx(HVAPI_HANDLE_EX hHandle, LPCSTR szParamDoc);

/**
* @brief			�ϴ����ذ���ư������ļ���һ���
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		szParamDoc		Ҫ���浽�豸�Ĳ�����XML��ʽ��
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
* @warning			���Ĺ��Ĳ���Ҫ���豸�´�������Ż���Ч
*/
HV_API_EX HRESULT CDECL HVAPI_SendControllPannelUpdateFileEx(HVAPI_HANDLE_EX hHandle,
														PBYTE pUpdateFileBuffer,
														DWORD dwFileSize);

/**
* @brief			�������������ջص�����
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		pFunc			�ص�����ָ�롣ע��ΪNULLʱ��ʾ�ر�nStreamType���͵���������
* @param[in]		pUserData		����ص��������û�����ָ��
* @param[in]		iVideoID		��Ƶͨ����Ŀǰֻʹ��0
* @param[in]		nStreamType		�ص�����������
* @param[in]		szConnCmd		��������������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetCallBackEx(HVAPI_HANDLE_EX hHandle, PVOID pFunc, PVOID pUserData,
									   INT iVideoID, INT iCallBackType, LPCSTR szConnCmd);


/**
* @brief              ����H264����
* @param[in]          hHandle				�豸���
* @param[in]          pFunc				    �ص�����ָ��
* @param[in]          pUserData			    �û�����
* @param[in]          iVideoID				��Ƶͨ����Ŀǰֻʹ��0
* @param[in]          dw64BeginTimeMS       ��ʼʱ��
* @param[in]          dw64EndTimeMS         ����ʱ�� 
* @param[in]          dwRecvFlag            ���ձ�־ :ʵʱ��Ƶ����ʷ��Ƶ
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartRecvH264Video(
	HVAPI_HANDLE_EX hHandle,
	PVOID pFunc,
	PVOID pUserData,
	INT iVideoID ,       
	DWORD64 dw64BeginTimeMS,
	DWORD64 dw64EndTimeMS,
	DWORD dwRecvFlag
);
/**
* @brief              ֹͣH264����
* @param[in]          hHandle          �豸���
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StopRecvH264Video(HVAPI_HANDLE_EX hHandle);


/**
* @brief              ����MJPEG����
* @param[in]          hHandle				 �豸���
* @param[in]          pFunc					 �ص�����ָ��
* @param[in]          pUserData				 �û�����
* @param[in]          iVideoID				 ��Ƶͨ����Ŀǰֻʹ��0
* @param[in]          dwRecvFlag			 ���ձ�־��������������������
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartRecvMJPEG(
					 HVAPI_HANDLE_EX hHandle,
					 PVOID pFunc,
					 PVOID pUserData,
					 INT iVideoID ,
					 DWORD dwRecvFlag
					 );
/**
* @brief              ֹͣMJPEG����
* @param[in]          hHandle          �豸���
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL  HVAPI_StopRecvMJPEG(HVAPI_HANDLE_EX hHandle);
/**
* @brief              ���ĵ���������״̬
* @param[in]          hHandle          �豸���
* @param[in]          fEnable          �Ƿ�򿪵�������
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetDebugJpegStatus(HVAPI_HANDLE_EX hHandle, BOOL fEnable);

/**
* @brief              �������ս��
* @param[in]          hHandle			�豸���
* @param[in]          pFunc				�ص�����ָ��
* @param[in]          pUserData			�û�����
* @param[in]          iVideoID          ��Ƶͨ����Ŀǰֻʹ��0
* @param[in]          dw64BeginTimeMS       ��ʼʱ��
* @param[in]          dw64EndTimeMS         ����ʱ��
* @param[in]          dwStartIndex			��ʼ֡��
* @param[in]          dwRecvFlag			���ձ�־
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartRecvResult(
						HVAPI_HANDLE_EX hHandle,
						PVOID pFunc,
						PVOID pUserData,
						INT iVideoID,
						DWORD64 dw64BeginTimeMS,
						DWORD64 dw64EndTimeMS,
						DWORD dwStartIndex,
						DWORD dwRecvFlag
					 );
/**
* @brief              ֹͣ�������
* @param[in]          hHandle          �豸���
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StopRecvResult(HVAPI_HANDLE_EX hHandle);


/**
* @brief              ����״̬��Ϣ����
* @param[in]          hHandle				 �豸���
* @param[in]          pFunc					 �ص�����ָ��
* @param[in]          pUserData				 �û�����
* @param[in]          iVideoID				 ��Ƶͨ����Ŀǰֻʹ��
* @param[in]          dwRecvFlag			 ���ձ�־������
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_StartRecvMsg(
	HVAPI_HANDLE_EX hHandle,
	PVOID pFunc,
	PVOID pUserData,
	INT iVideoID ,
	DWORD dwRecvFlag
	);


/**
* @brief		�����źţ����ڿ�բ��
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
*@param[in]   iVideo		   ��Ƶ���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_TriggerSignal(HVAPI_HANDLE_EX hHandle, INT iVideoID);

/**
* @brief		���������źţ� ���ڿ��Ʊ����豸
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
������Ϊ�� SendAlarmTriggerOut
*/
HV_API_EX HRESULT CDECL HVAPI_TriggerAlarmSignal(HVAPI_HANDLE_EX hHandle);


/**
* @brief		����ڰ�����
* @param[in]	hHandle	        ��Ӧ�豸����Ч���
* @param[in]	szWhileNameList	 �������б�,������(����-��Ч��)��$������������:��A11111-2013010101$��A2222-2013010202$��A33333-2013020202   ���ָ��ΪNULL,��ʾ�����á�
* @param[in]	iWhileListLen		�������ַ�����
* @param[in]	szBlackNameList		�����ַ����� ������(����-��Ч��)��$������������:��A11111-2013010101$��A2222-2013010202$��A33333-2013020202   ���ָ���ʾ������
* @param[in]	iListLen		�����ַ������� 
* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_InportNameList(HVAPI_HANDLE_EX hHandle, CHAR* szWhileNaneList, INT iWhileListLen, CHAR* szBlackNameList, INT iBlackListLen);


/**
* @brief		��ȡ�ڰ�����
* @param[in]	hHandle	        ��Ӧ�豸����Ч��� 
* @param[out]	szWhileNameList		�������ַ����������� ������(����-��Ч��)��$������������:��A11111-2013010101$��A2222-2013010202$��A33333-2013020202   
* @param[in/out]	iWhileListLen		����������ָ�룬 ��������ͷ��� 
@param[out]	szBlackNameList		�������ַ����������� ������(����-��Ч��)��$������������:��A11111-2013010101$��A2222-2013010202$��A33333-2013020202   
* @param[in/out]	iBlackListLen		����������ָ�룬 ��������ͷ��� 

* @return		�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/

HV_API_EX HRESULT CDECL HVAPI_GetNameList(HVAPI_HANDLE_EX hHandle, CHAR* szWhileNameList, INT *iWhileListLen, CHAR* szBlackNameList, INT *iBlackListLen);


/**
* @brief              ֹͣ״̬��Ϣ����
* @param[in]          hHandle          �豸���
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL  HVAPI_StopRecvMsg(HVAPI_HANDLE_EX hHandle);

/**
* @brief			�����ַ�����
* @param[in]		hHandle					��Ӧ�豸����Ч���
* @param[in]		szCharacterDataBuff		��������
* @param[in]		nBuffLen				�������ݳ���
* @param[in]		nTopLeftX				�����ַ����Ͻ�����Xֵ
* @param[in]		nTopLeftY				�����ַ����Ͻ�����Yֵ
* @param[in]		nDateType				��������
* @param[in]		nSize					�����С�����أ�
* @param[in]		nR						RGB��Rֵ
* @param[in]		nG						RGB��Gֵ
* @param[in]		nB						RGB��Bֵ
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_SetCharacterValue(HVAPI_HANDLE_EX hHandle, const char* szCharacterDataBuff, 
												  INT nTopLeftX, INT nTopLeftY, INT nDateType, INT nSize, INT nR, INT nG, INT nB);

/**
* @brief			�����ͼ��ƼӺ�����
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		dwEnhanceStyle	�Ӻ촦��ģʽ 0���Ӻ� 1ֻ�Ӻ�Υ�½�� 2ȫ�Ӻ� 3ֻ�Ӻ�ץ��ͼ
* @param[in]		iBrightness		�Ӻ��ͼƬ������ǿ����
* @param[in]		iHubThreshold	���ɫ�ȷ�ֵ
* @param[in]		iCompressRate	�Ӻ촦���ͼƬѹ��Ʒ��
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetEnhanceRedLightFlagEx(HVAPI_HANDLE_EX hHandle, DWORD dwEnhanceStyle, INT iBrightness, INT iHubThreshold, INT iCompressRate);

/**
* @brief			��ʷ���JPEGͼƬ֡��ƼӺ�����
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		dwEnhanceStyle	�Ӻ촦��ģʽ 0���Ӻ� 1�Ӻ�
* @param[in]		iBrightness		�Ӻ��ͼƬ������ǿ����
* @param[in]		iHubThreshold	���ɫ�ȷ�ֵ
* @param[in]		iCompressRate	�Ӻ촦���ͼƬѹ��Ʒ��
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetHistoryVideoEnhanceRedLightFlagEx(HVAPI_HANDLE_EX hHandle, DWORD dwEnhanceStyle, INT iBrightness, INT iHubThreshold, INT iCompressRate);

/**
* @brief			Ԥ���ӿڣ������豸��չ�¹��ܺ��ȡ��ص���չ��Ϣ
* @param[in]		hHandle			��Ӧ�豸����Ч���
* @param[in]		dwType			��Ϣ����
* @param[in]		iBrightness		������Ϣ�Ļ����ַ
* @param[in/out]	iBrightness		������Ϣ�Ļ����ַ���Ⱥ�ʵ�ʷ�����Ϣ����
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetExtensionInfoEx(HVAPI_HANDLE_EX hHandle, DWORD dwType, LPVOID pRetData, INT* iBufLen);

/**
* @brief			�ӽ��������Ϣ�л�ȡĳ����Ϣ
* @param[in]		szAppened			���������Ϣ
* @param[in]		szInfoName			��ȡ����
* @param[out]		szRetInfo			����ִ�
* @param[in]		iRetInfoBufLen		����ִ����滺������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_GetRecordInfoFromAppenedStringEx(LPCSTR szAppened, LPCSTR szInfoName, LPSTR szRetInfo, INT iRetInfoBufLen);

/**
* @brief			�ӽ��������Ϣ����ȡȫ����Ϣÿ��Ŀ��Ϣʹ�ûس�������
* @param[in]		pszXmlPlateInfo			���������Ϣ
* @param[out]		pszPlateInfoBuf			����ִ�������
* @param[in]		iPlateInfoBufLen		����ִ�����������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_ParsePlateXmlStringEx(LPCSTR pszXmlPlateInfo, LPSTR pszPlateInfoBuf, INT iPlateInfoBufLen);

/**
* @brief			�������Сͼ����ת����BMP��ʽ
* @param[in]		pbSmallImageData		����Сͼ����
* @param[in]		nSmallImageWidth		����Сͼ��
* @param[in]		nSmallImageHeight		����Сͼ��
* @param[out]		pbBitmapData			ת�����BMP����
* @param[out]		pnBitmapDataLen			ת�����BMP���ݳ���
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_SmallImageToBitmapEx(PBYTE pbSmallImageData, INT nSmallImageWidth, INT nSmallImageHeight, PBYTE pbBitmapData, INT* pnBitmapDataLen);

/**
* @brief			��ʶ������ֵͼת��ΪBMPλͼ
* @param[in]		pbBinImageData		ʶ������ֵͼ
* @param[in]		pbBitmapData		BMPλͼ���ݴ�Ż�����
* @param[in,out]	pnBitmapDataLen		BMPλͼ���ݴ�Ż��������ȡ��������غ���Ϊ��BMPλͼ����ʵ�ʳ���
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_BinImageToBitmapEx(PBYTE pbBinImageData,
												 PBYTE pbBitmapData,
												 INT* pnBitmapDataLen);

/**
* @brief		������ִ�н��XML�ַ����л�ȡ��Ӧ��Ϣ
* @param[in]	fIsNewXmlProtocol	XMLЭ������
* @param[in]	pszRetXmlStr		ִ������ʱ���ص�ִ�н��XML�ַ���
* @param[in]	pszCmdName			��������
* @param[in]	pszInfoName			��ȡ��Ϣ����
* @param[out]	pszInfoValue		��ȡ��Ϣ����ִ�
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPIUTILS_GetExeCmdRetInfoEx(BOOL fIsNewXmlProtocol, LPCSTR pszRetXmlStr, LPCSTR pszCmdName, 
													  LPCSTR pszInfoName, LPSTR pszInfoValue);


HV_API_EX HRESULT CDECL HVAPI_Capture(HVAPI_HANDLE_EX hHandle, char* szValue);

/**
* @brief              ��185������ʹ�������
* @param[in]          hHandle          �豸���
* @param[in]          dw64CaptureTime    DWORD64�ͣ���ǰϵͳʱ��,Ϊ��1970-01-01 00:00:00��ʼ��Ŀǰ�������ĺ�������Ϊ����ץ��ʱ�䣬���Ϊ�� (NULL)�����Զ���ȡ��ǰʱ��
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SendCaptureCmd(HVAPI_HANDLE_EX hHandle, DWORD64 dw64CaptureTime);

/**
* @brief			���������źż�������
@param[in]			nNum	��������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_OpenListenCMDSever(int nNum);

/**
* @brief			�رմ����źż�������
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_CloseListenCMDSever();

/**
* @brief			���ü����ص�����
* @param[in]		hHandle			��Ӧ�豸��������Ч���
* @param[in]		pFunc			�ص�����ָ��
* @param[in]		pUserData		����ص��������û�����ָ��
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_SetCallBackListen(HVAPI_HANDLE_EX hHandle,PVOID pFunc, PVOID pUserData);

/**
* @brief			���Ӽ����豸���
* @param[in]		szIp			�豸��IP��ַ
* @return			�ɹ����豸�����ʧ�ܣ�NULL
*/
HV_API_EX HVAPI_HANDLE_EX CDECL HVAPI_OpenListenClientEx(LPCSTR szIp);

/**
* @brief			�رռ����豸���
* @param[in]		hHandle			��Ӧ�豸��������Ч���
* @return			�ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_CloseListenClientEx(HVAPI_HANDLE_EX hHandle);


/**
* @brief              ȡ���˿���������(���ֻ��ȡһ��������)
* @param[in]          hHandle          �豸���
* @param[in]          dw64StartTime    ��Ӧ��ȡ��������Ϣ����ʼʱ��,Ϊ��1970-01-01 00:00:00��ʼ��Ŀǰ�������ĺ�����
* @param[in]          dw64EndTime      ��Ӧ��ȡ��������Ϣ�Ľ���ʱ��,Ϊ��1970-01-01 00:00:00��ʼ��Ŀǰ�������ĺ�����
* @param[out]         szRetInfo		   ��Ӧʹ����������ڴ����򣬺������óɹ����������Ϣ�����ڴ�
* @param[in,out]      iLen		       szRetInfo���������ȣ��������غ�Ϊ�ַ���ʵ�ʳ���
* @return             �ɹ���S_OK��ʧ�ܣ�E_FAIL
*/
HV_API_EX HRESULT CDECL HVAPI_GetPCSFlow(HVAPI_HANDLE_EX hHandle, DWORD64 dw64StartTime, DWORD64 dw64EndTime, CHAR* szRetInfo, INT* iLen);

#endif
