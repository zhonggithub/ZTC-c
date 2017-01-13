#ifndef ZTC_ZCOMMONALITY_H
#define ZTC_ZCOMMONALITY_H

#include "ZStdf.h"
#include <stdlib.h>
#include <sstream>
#include <limits>

#include "ZBase.h"
#include "ZMacroDefine.h"

BEGIN_ZTC_NAMESPACE
/***************** �ַ����ָ��
* ������ int SplitFromSingleChar(const string &desStr, const string &split, vector<string > &vStr);
* ���ܣ� �ָ�desStr�ַ���
* ����˵���� desStr����Ҫ�ָ��ַ����� split:�ָ���ַ����ַ��� vStr���ָ����ַ���
* ����ֵ������ִ�гɹ������طָ�õ����ַ����ĸ���, ���ʧ�ܣ����� 0 ��
* ���磺str = "my name is<hello,word> : test[string](string.)world";
*       split = " ,;:!?.<>[]()'";  //split�е�ÿһ���ַ����Ƿָ���
*****/
ZTC_API int SplitBaseOnSingleChar(const string &desStr, const string &split, vector<string > &vStr);

/***************** �ַ����ָ��
* ������int SplitFromGropChar(string str, string split, vector<string > &vStr);
* ���ܣ��ָ�str�ַ���
* ����˵���� str����Ҫ�ָ��ַ����� split:�ָ���ַ����ַ��� vStr���ָ����ַ���
* ����ֵ������ִ�гɹ������طָ�õ����ַ����ĸ��� �����ʧ�ܣ����� 0 ��
* ���磺str = "my##eedsfa##";
*       split = "##"; //split�����Ƿָ��� 
*
*****/
ZTC_API int SplitBaseOnGropChar(string str, string split, vector<string > &vStr);

/*****************
* ������int SplitFromMultiGropChar(string str, vector<string > split, vector<string >&vStr);
* ���ܣ��÷ָ�����Ϸָ�str�ַ���
* ����˵����str����Ҫ�ָ��ַ����� split:�ָ���ַ����ַ����ϣ� vStr���ָ����ַ���
* ����ֵ������ִ�гɹ������طָ�õ����ַ����ĸ��� �����ʧ�ܣ����� 0 ��
* ���磺str = "my##eedsfa##";
*       split[0] = "##"; //split[0]�����Ƿָ��� 
*       split[1] = "||"; //split[1]�����Ƿָ��� 
*       split[2] = ","; //split[2]�����Ƿָ��� 
*
*****/
ZTC_API int SplitBaseOnMultiGropChar(string str, vector<string > split, vector<string >&vStr);

/***************** ��������
* ������double RoundOff(double num, int n = 2);
* ���ܣ���������
* ����˵����num�������������ֵ�� n:Ҫ��ľ���, Ĭ��ֵΪ2(��С�������λ)�� 
* ����ֵ������ִ�гɹ���һ��doubleֵ �����ʧ�ܣ����� ��ʼֵ����num�� ��
* ˵�����ú������ֻ�ܷ���һ����ȷ��С�����5λ��ֵ(��double�ľ�ȷֵ),��n�ļ�ֵС��0������ֵΪ0��
*       ��n��ֵ����5��������Ĭ��n��ֵΪ5.
*****/
ZTC_API double RoundOf(double num, int n = 2);

/***����ת�ַ�***/
ZTC_API string ItoString(long double value, int precision = 3);
ZTC_API string do_fraction(long double value, int decplaces = 3);

/*********�ַ�����ͳ��
***/
ZTC_CLASS	map<char, int> CalChar(char const *pCh);

/********���ַ�ת����16����
*  ����ֵ��16�����ַ���
*/
ZTC_API string CharToHex(const char *pCh);

/********��16����ת����10����
*/
ZTC_API unsigned long HexToDec(const char* pCh);

ZTC_API bool multi_to_wide(const std::string& multi, std::wstring& unicode);
ZTC_API bool wide_to_multi(const std::wstring& unicode, std::string& multi);

ZTC_API bool utf8_to_unicode(const std::string& utf8, std::wstring& unicode);
ZTC_API bool unicode_to_utf8(const std::wstring& unicode, std::string& utf8);

END_ZTC_NAMESPACE
#endif // ZTC_ZCOMMONALITY_H