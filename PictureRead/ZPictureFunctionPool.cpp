#include "ZPictureFunctionPool.h"
#include <stdlib.h>
#include "../include/ZCommonality.h"
#include "../include/ZCommon.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace ZTC
{
	bool ReadBitmapFileHead(ifstream &file, BitmapFileHeader &bitmapFileHead)
	{
		char buf[4] = {'\0'};

		int tempNum1 = sizeof(unsigned short);
		int tempNum2 = sizeof(unsigned long);

		file.read(buf, tempNum1); //�ļ�����
		string str = CharToHex(buf);
		bitmapFileHead.bfType = HexToDec(str.c_str());

		file.read(buf, tempNum2); //�ļ���С
		str = CharToHex(buf);
		bitmapFileHead.bfSize = HexToDec(str.c_str());

		file.read(buf, tempNum1); //������
		str = CharToHex(buf);
		bitmapFileHead.bfReserved1 = HexToDec(str.c_str());

		file.read(buf, tempNum1); //������
		str = CharToHex(buf);
		bitmapFileHead.bfReserved2 = HexToDec(str.c_str());

		file.read(buf, tempNum2); //�ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ���
		str = CharToHex(buf);
		bitmapFileHead.bfOffBits = HexToDec(str.c_str());

		return true;
	}

	//��ʾλͼ�ļ�ͷ��Ϣ  
	void showBmpHead(BitmapFileHeader pBmpHead)
	{  
		cout<<"λͼ�ļ�ͷ: "<<endl; 
		cout<<"�ļ�����: "<<pBmpHead.bfType<<endl;
		cout<<"�ļ���С: "<<pBmpHead.bfSize<<endl;  
		cout<<"������_1: "<<pBmpHead.bfReserved1<<endl;  
		cout<<"������_2: "<<pBmpHead.bfReserved2<<endl;  
		cout<<"ʵ��λͼ���ݵ�ƫ���ֽ���: "<<pBmpHead.bfOffBits<<endl<<endl;  
	}  

	void showBmpInforHead(BitmapInfoHeader pBmpInforHead)
	{  
		cout<<"λͼ��Ϣͷ: "<<endl;  
		cout<<"�ṹ��ĳ���: "<<pBmpInforHead.biSize<<endl;  
		cout<<"λͼ��: "<<pBmpInforHead.biWidth<<endl;  
		cout<<"λͼ��: "<<pBmpInforHead.biHeight<<endl;  
		cout<<"biPlanesƽ����: "<<pBmpInforHead.biPlanes<<endl;  
		cout<<"biBitCount������ɫλ��: "<<pBmpInforHead.biBitCount<<endl;  
		cout<<"ѹ����ʽ: "<<pBmpInforHead.biCompression<<endl;  
		cout<<"biSizeImageʵ��λͼ����ռ�õ��ֽ���: "<<pBmpInforHead.biSizeImage<<endl;  
		cout<<"X����ֱ���: "<<pBmpInforHead.biXPelsPerMeter<<endl;  
		cout<<"Y����ֱ���: "<<pBmpInforHead.biYPelsPerMeter<<endl;  
		cout<<"ʹ�õ���ɫ��: "<<pBmpInforHead.biClrUsed<<endl;  
		cout<<"��Ҫ��ɫ��: "<<pBmpInforHead.biClrImportant<<endl;  
	}  
}