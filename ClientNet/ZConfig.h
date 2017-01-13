#ifndef ZTC_CLIENTNET_ZCONFING_H
#define ZTC_CLIENTNET_ZCONFING_H

#include "../include/ZMacroDefine.h"
#include "../include/ZType.h"

//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <map>
#include <queue>
#include <vector>
#include <hash_map>
#include <stdarg.h>

#ifdef _MSC_VER
	#include <WinSock2.h>
	#include <WS2tcpip.h>
	#include <Windows.h>
#ifdef _WIN32_WCE
	#pragma comment(lib, "ws2.lib")
#else
	#pragma comment(lib, "Ws2_32.lib")
#endif
	#define Hash_map stdext::hash_map
	#define snprintf _snprintf
#elif __GNUC__
	#include <sys/time.h>
	#include <stdint.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <iconv.h>
	#include <pthread.h>
	#include <netdb.h>
	#include <semaphore.h>
	#define Hash_map __gnu_cxx::hash_map
#endif

BEGIN_ZTC_NAMESPACE
//���Ͷ���

#ifdef _MSC_VER
	typedef SOCKET Socket_handle;
	#define close_socket closesocket
#else
	typedef int Socket_handle;
	#define INVALID_SOCKET 0
	#define close_socket close
	#define SOCKET_ERROR -1
#endif

#define INVALID_VALUE 0XFFFF
#define MAX_PATH_LEN 260

/*
�ͻ�������ģ�����ã�ʵ�ú궨��
*/

#define MAX_TCP_MSG_LEN (0xFFFF + 8)
#define MAX_UDP_MSG_LEN (0xFFFF + 6)

/*
TCP��Ϣ�Ľṹ,��Ϣ����Ϊ��Ϣ�峤��
--------------------------------------------------------------------------------
|��Ϣ����|     ��ϢID     |��Ϣ���� |           ��Ϣ��
| 2�ֽ�	 |     4�ֽ�      | 2�ֽ�   |  ����Ϊ��Ϣ����-ǰ��������֮��
--------------------------------------------------------------------------------
*/

/*
UDP��Ϣ�Ľṹ,��Ϣ����Ϊ������Ϣ������
-----------------------------------------------------------------------
|��Ϣ����|     ��ϢID     |           ��Ϣ��
| 2�ֽ�	 |     4�ֽ�      |  ����Ϊ��Ϣ����-ǰ��������֮��
-----------------------------------------------------------------------
*/

// ��Ϣ����ƫ����
#define OFFSET_MSG_TYPE 0
// ��Ϣ������ռ����
#define LEN_MSG_TYPE sizeof(uint16_t)

// ��ϢIDƫ����
#define OFFSET_MSG_ID LEN_MSG_TYPE
// ��ϢID��ռ����
#define LEN_MSG_ID sizeof(uint32_t)

// �������Ϣ���Ȱ�����Ϣͷ���ȣ�Ҳ����������Ϣ������
// ��Ϣ����ƫ����
#define OFFSET_MSG_LEN (LEN_MSG_TYPE + LEN_MSG_ID)
// ��Ϣ������ռ����
#define LEN_MSG_LEN sizeof(uint16_t)

// ��Ϣͷ���ĳ���
#define LEN_TCP_MSG_HEAD (LEN_MSG_TYPE + LEN_MSG_ID + LEN_MSG_LEN)
#define LEN_UDP_MSG_HEAD (LEN_MSG_TYPE + LEN_MSG_ID)

// ��Ϣ��ƫ����
#define OFFSET_TCP_MSG_BODY (LEN_TCP_MSG_HEAD)
#define OFFSET_UDP_MSG_BODY (LEN_UDP_MSG_HEAD)

END_ZTC_NAMESPACE
#endif //ZTC_CLIENTNET_ZCONFING_H