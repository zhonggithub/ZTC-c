/*
* Copyright (c) 2013 ZZ
* All rights reserved.
* 
* File Name       : ZClientNet.h
* File Identifier :
* Abstract        :
* 
* Current Version : 1.0
* Author          : ZZ
* Completion Date : 2014.9.25 20:14:31
*
* Replace Version : 
* Original Author :
* Completion Date : 2014.9.25 20:14:31
*/

#ifndef ZTC_CLIENTNET_ZCLIENTNET_H
#define ZTC_CLIENTNET_ZCLIENTNET_H

#include "../include/ZMacroDefine.h"
#include "ZConfig.h"

BEGIN_ZTC_NAMESPACE

//����״̬
enum ConnectState
{
	Unconnected, //δ����
	Connecting, //������
	Connected //�Ѿ�����
};

/*
Tcp�������������һ�����ӣ��ṩ�����ϵ����в���
*/
class ZITcp
{
public:
	virtual ~ZITcp(){}
	//���ӷ��������첽
	virtual int connect(const char *pIP, uint16_t port) = 0;
	virtual int connect(uint32_t ip, uint16_t port) = 0;
	//�Ͽ����ӣ�ͬ��
	virtual int disconnect() = 0;
	//�������첽
	virtual int reconnect() = 0;
	//�Ƿ���������
	virtual bool isConnected() = 0;
	//��ǰ״̬
	virtual ConnectState state() = 0;
	//������Ϣ
	virtual int send(const char* pData, uint32_t len) = 0;
	virtual int send(uint16_t msgType, uint32_t msgID, const char* pMsg, uint32_t msgLen) = 0;
	//��ȡ���յ�����Ϣ
	virtual int frontMsg(const char** pMsg, uint32_t* len) = 0;
	//��Ϣ����
	virtual int popMsg() = 0;
};


//UDP ����
class ZIUdp
{
public:
	virtual ~ZIUdp(){}
	//��ʼ��
	virtual int open(const char* ip, uint16_t port) = 0;
	virtual int open(const char* ip, const char* port) = 0;
	//�ر�
	virtual int close() = 0;
	//������Ϣ
	virtual int send(const char* pData, uint32_t len) = 0;
	virtual int send(uint16_t msgType, uint32_t msgID, const char* pMsg, uint32_t msgLen) = 0;
	//��ȡ���յ�����Ϣ
	virtual int frontMsg(const char** pMsg, uint32_t* len) = 0;
	//��Ϣ����
	virtual int popMsg() = 0;
};

/*
������,�ṩ����ײ����
*/
class ZINetFrame
{
public:
	virtual ~ZINetFrame(){}
	//�ַ������¼�
	virtual int dispatch() = 0;
	//����������tcp����
	virtual ZITcp* create_tcp() = 0;
	virtual void release_tcp(ZITcp* pTcp) = 0;
	//����������udp����
	virtual ZIUdp* create_udp() = 0;
	virtual void release_udp(ZIUdp* pUdp) = 0;

};

//�������������ܵĽӿ�
ZTC_API ZINetFrame* create_net_frame();
ZTC_API void release_net_frame(ZINetFrame* pFrame);
ZTC_API uint16_t ntohs(const void* data);
ZTC_API uint32_t ntohl(const void* data);

END_ZTC_NAMESPACE

#endif //ZTC_CLIENTNET_ZCLIENTNET_H