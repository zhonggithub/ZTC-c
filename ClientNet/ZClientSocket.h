/*
* Copyright (c) 2013 ZZ
* All rights reserved.
* 
* File Name       : ZClientSocket.h
* File Identifier :
* Abstract        : �ṩ������������TCP, UDP����
* 
* Current Version : 1.0
* Author          : ZZ
* Completion Date : 2014.10.26 19:10:53
*
* Replace Version : 
* Original Author :
* Completion Date : 2014.10.26 19:10:53
*/

#ifndef ZTC_CLIENTNET_ZCLIENTSOCKET_H
#define ZTC_CLIENTNET_ZCLIENTSOCKET_H

#include "../include/ZMacroDefine.h"
#include "ZConfig.h"

BEGIN_ZTC_NAMESPACE

/*
������Tcp����
*/
class ZTC_CLASS ZBtcp
{
public:
	ZBtcp();
	virtual ~ZBtcp();

	int connect(const char* ip, unsigned short port);
	int connect(unsigned int ip, unsigned short port);
	int connect(unsigned int ip, unsigned short port, int timeout);
	int disconnect();

	/* timeout˵��:
	 * timeout��λΪ��
	 * time > 0 Ϊ�����ĳ�ʱ����, ���޶�ʱ�������û����������, �����趨��ʱ��ᳬʱ����
	 * time == 0 ��ʾ�޳�ʱ����, ��һֱ����ֱ��������ɻ��߳���ŷ���
	 * time < 0 ��ʾ��β�����ִ��һ�����̷���, ���ܳɹ�Ҳ����ʧ��.
	 */
	int send(const char* pData, int len);
	int send(const char* buf, int len, int timeout);
	int recv(char* buf, int len);
	int recv(char* buf, int len, int timeout);
	int recv_whole(char* buf, int len);	//len����ȫ����ȡ��ŷ���. ���ɹ�����ֵ��len���, ʧ�ܷ���-1
	int recv_whole(char* buf, int len, int timeout); //�ڹ涨ʱ���ڷ���ֵ��timeout�����ɹ�, ����ʧ��

private:
	SOCKET m_socket;
	sockaddr_in m_addr;
};

/*
������UDP����
*/
class ZTC_CLASS ZBudp
{
public:
	ZBudp(const char* ip, unsigned int port);
	virtual ~ZBudp();

	int send(const char* pData, int len, int timeout = -1);	//timeout��λ����, <0��ʾ�޳�ʱ����
	int recv(char* buf, int len, int timeout = -1);	//timeout��λ����, <0��ʾ�޳�ʱ����

	SOCKET m_socket;

private:
	//SOCKET m_socket;
	sockaddr_in m_addr;
};

END_ZTC_NAMESPACE
#endif //ZTC_CLIENTNET_ZCLIENTSOCKET_H