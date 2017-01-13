#ifndef ZTC_PICTUREREAD_BITMAP_H
#define ZTC_PICTUREREAD_BITMAP_H

namespace ZTC
{

	typedef unsigned char BYTE;  
	typedef unsigned short WORD;  
	typedef unsigned long DWORD;  
	typedef signed int LONG;
	typedef DWORD COLORREF;

	const int BitmapFileHeaderSize = 14;
	const int BitmapInfoHeaderSize = 40;
	const int RGBQuadSize = 4;

	//λͼ�ļ�ͷ����;    
	struct BitmapFileHeader
	{  
		WORD bfType; //�ļ����ͣ�������0x424D�����ַ���BM��  
		DWORD bfSize; //�ļ���С  
		WORD bfReserved1; //������,����Ϊ0  
		WORD bfReserved2; //�����֣�����Ϊ0
		DWORD bfOffBits; //���ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ���  
	};  

	struct BitmapInfoHeader
	{  
		DWORD biSize;//��Ϣͷ��С  
		LONG biWidth;//ͼ����  
		LONG biHeight;//ͼ��߶�  
		WORD biPlanes;//λƽ����������Ϊ1  
		WORD biBitCount;//ÿ���ض�����λ��  
		DWORD biCompression; //ѹ������  
		DWORD biSizeImage; //ѹ��ͼ���С�ֽ���  
		LONG biXPelsPerMeter; //ˮƽ�ֱ���  
		LONG biYPelsPerMeter; //��ֱ�ֱ���  
		DWORD biClrUsed; //λͼʵ���õ���ɫ��������������ɫ��  
		DWORD biClrImportant; //��λͼ����Ҫ��ɫ���������Ϊ0������Ϊ������ɫ������Ҫ��  
	}; //λͼ��Ϣͷ����  

	struct RGBQuad
	{  
		BYTE rgbBlue; //����ɫ����ɫ����  
		BYTE rgbGreen; //����ɫ����ɫ����  
		BYTE rgbRed; //����ɫ�ĺ�ɫ����  
		BYTE rgbReserved; //����ֵ  
	};//��ɫ�嶨��  

	//������Ϣ  
	struct ZRGB  
	{  
		BYTE red;
		BYTE green;  
		BYTE blue;
	};  
}
#endif //ZTC_PICTUREREAD_BITMAP_H