#include "ZBitmap.h"
#include <string>
#include <exception>

#include "../include/ZCommonality.h"

namespace ZTC
{
	ZBitmap::ZBitmap(const char *pFileName):m_pBitmapInfoHeader(NULL)
	{
		m_ifstream.open(pFileName, std::ifstream::in | std::ifstream::binary);
		m_pBitmapInfoHeader = new (std::nothrow)BitmapInfoHeader();
		ReadBitmapInfoHeader(*m_pBitmapInfoHeader);
	}

	ZBitmap::~ZBitmap()
	{
		if(m_ifstream)
			m_ifstream.close();

		DELETE_PTR(m_pBitmapInfoHeader);
	}

	bool ZBitmap::IsValid()
	{
		if(!m_ifstream || !m_ifstream.is_open()|| !m_pBitmapInfoHeader)
			return false;
		else
			return true;
	}

	bool ZBitmap::ReadBitmapFileHeader(BitmapFileHeader &bitmapFileHeader)
	{
		if(!m_ifstream)
			return false;

		char buf[4] = {'\0'};
		
		int tempNum1 = sizeof(unsigned short);
		int tempNum2 = sizeof(unsigned long);

		m_ifstream.seekg(0, std::ios::beg);

		m_ifstream.read(buf, tempNum1); //�ļ�����
		string str = CharToHex(buf);
		bitmapFileHeader.bfType = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum2); //�ļ���С
		str = CharToHex(buf);
		bitmapFileHeader.bfSize = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum1); //������
		str = CharToHex(buf);
		bitmapFileHeader.bfReserved1 = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum1); //������
		str = CharToHex(buf);
		bitmapFileHeader.bfReserved2 = HexToDec(str.c_str());
		
		m_ifstream.read(buf, tempNum2); //�ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ���
		str = CharToHex(buf);
		bitmapFileHeader.bfOffBits = HexToDec(str.c_str());
		
		return true;
	}

	bool ZBitmap::ReadBitmapInfoHeader(BitmapInfoHeader &bitmapInfoHeader)
	{
		if(!m_ifstream)
			return false;

		char buf[4] = {'\0'};
		
		int tempNum1 = sizeof(WORD);
		int tempNum2 = sizeof(DWORD);
		int tempNum3 = sizeof(LONG);

		m_ifstream.seekg(0, std::ios::beg);
		//�ƶ�����Ϣͷλ��
		m_ifstream.seekg(BitmapFileHeaderSize, std::ios::beg);

		m_ifstream.read(buf, tempNum2); //��Ϣͷ��С
		string str = CharToHex(buf);
		bitmapInfoHeader.biSize = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum3); //ͼ����
		str = CharToHex(buf);
		bitmapInfoHeader.biWidth = HexToDec(str.c_str()); 

		m_ifstream.read(buf, tempNum3); //ͼ��߶�
		str = CharToHex(buf);
		bitmapInfoHeader.biHeight = HexToDec(str.c_str()); 

		m_ifstream.read(buf, tempNum1); //λƽ����������Ϊ1
		str = CharToHex(buf);
		bitmapInfoHeader.biPlanes = HexToDec(str.c_str()); 

		m_ifstream.read(buf, tempNum1); //ÿ���ض�����λ��
		str = CharToHex(buf);
		bitmapInfoHeader.biBitCount = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum2); //ѹ������
		str = CharToHex(buf);
		bitmapInfoHeader.biCompression = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum2); //ѹ��ͼ���С�ֽ���
		str = CharToHex(buf);
		bitmapInfoHeader.biSizeImage = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum3); //ˮƽ�ֱ���
		str = CharToHex(buf);
		bitmapInfoHeader.biXPelsPerMeter = HexToDec(str.c_str());
		 
		m_ifstream.read(buf, tempNum3); //��ֱ�ֱ���
		str = CharToHex(buf);
		bitmapInfoHeader.biYPelsPerMeter = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum2); //λͼʵ���õ���ɫ��������������ɫ��
		str = CharToHex(buf);
		bitmapInfoHeader.biClrUsed = HexToDec(str.c_str());
		
		m_ifstream.read(buf, tempNum2); //��λͼ����Ҫ��ɫ���������Ϊ0������Ϊ������ɫ������Ҫ��
		str = CharToHex(buf);
		bitmapInfoHeader.biClrImportant = HexToDec(str.c_str());
		
		return true;
	}

	bool ZBitmap::ReadQuad(RGBQuad &quad)
	{
		if(!IsValid())
			return false;

		char buf[4] = {'\0'};
		
		int tempNum1 = sizeof(BYTE);

		//�ƶ�����ɫ��ͷλ��
		m_ifstream.seekg(BitmapFileHeaderSize, std::ios::beg);
		m_ifstream.seekg(BitmapInfoHeaderSize, std::ios::cur);
 
		m_ifstream.read(buf, tempNum1); //����ɫ����ɫ����
		string str = CharToHex(buf);
		quad.rgbBlue = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum1); //����ɫ����ɫ����
		str = CharToHex(buf);
		quad.rgbGreen = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum1); //����ɫ�ĺ�ɫ����  
		str = CharToHex(buf);
		quad.rgbRed = HexToDec(str.c_str());

		m_ifstream.read(buf, tempNum1); //����ֵ  
		str = CharToHex(buf);
		quad.rgbReserved = HexToDec(str.c_str());

		return true;
	}

	int ZBitmap::GetWidth()
	{
		if(!IsValid() || !m_pBitmapInfoHeader)
			return 0;
		return m_pBitmapInfoHeader->biWidth;
	}

	int ZBitmap::GetHeight()
	{
		if(!IsValid() || !m_pBitmapInfoHeader)
			return 0;
		
		return m_pBitmapInfoHeader->biHeight;
	}

	COLORREF ZBitmap::GetPixel(int x, int y)
	{
		return 0;
	}
}