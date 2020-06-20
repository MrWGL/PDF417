#pragma once
/**
* \brief
*Function: PDF417 encode
*Editor: Mr.Wu
*Timer: 2019-8-12
*/

#include <string>
#include <vector>

#include "BarCode/CPDF417.h"
#include "BarCodeItem/barcodelib_global.h"


class BARCODELIB_EXPORT CBarCodePDF417
{
public:
	CBarCodePDF417();
	CBarCodePDF417(std::string text);
	~CBarCodePDF417();

	/**
	*\brief
	*���� PDF417 ��������
	*/
	void setText(std::string text);

	/**
	*\brief
	*���þ���ȼ� 0 - 8 ��
	*/
	void setErrorLevel(int level);


	/**
	*\brief
	*BC ģʽ����
	*/
	void ByteCompress(const unsigned char *str,int length);

	/**
	*\brief
	*TC ģʽ����
	*/
	void TextCompress(const unsigned char *str, int length);

	/**
	*\brief
	*NC ģʽ����
	*/
	void NumberCompress(const unsigned char *str,int length);

	/**
	*\brief
	*�ı�ѹ��ģʽ: ������������,�����ַ���ģʽ���ͣ�
	*��ģʽ����: 1.ALPHA  2.LOWER   3.MIXED   4.PUNCTUATION
	*/
	int ParseData(unsigned char data, int idx, int length);

	/**
	*\brief
	*�ֽ�ѹ��ģʽ: ͨ����256����900ת��
	*/
	void Byte256To900(const unsigned char *str,int k);


	/**
	*����ѹ��ģʽ:�ӻ�10����900ת��
	*/
	void Number10To900(const unsigned char *str,int k, int size);


	/**
	*\brief
	*�����ı�,�������ı�������������䡢��������
	*/
	void InsertFillCode();

	/**
	*\brief
	*���������ֲ�������һ������ʱ,���������������
	*/
	void InsertVirtualCode();

	/**
	*\brief
	*Ѱ�Ҵ���ȼ���
	*/
	int MaxPossibleErrLevel(int m);

	/**
	*\brief
	*���ݴ���ȼ������������,
	*/
	void CalculateErrorCorrection();

	/**
	*\brief
	*��������������
	*/
	void InsertErrCode();

	/**
	*\brief
	*�������С�����ָʾ��,����ʼ�����ӣ����㹫ʽ����:
	*		30xi + a, Ci = 0                   30xi + c, ci = 0
	*
	*Li =   30xi + b, Ci = 3            Ri  =  30xi + a, ci = 3
	*
	*		30xi + c, Ci = 6                   30xi + b, ci = 6 
	*
	*xi = int[(�к�-1��/3], i =1,2,3,4,5 ...90��    Ci = �� i ����š�
	*a = int[(���� - 1) / 3]��     b = ��������ȼ��� * 3 + (���� - 1) % 3;
	*c = ������������ - 1��
	*/
	void CulculateIndicate(int row, int colume);
	
	/**
	*\brief
	*�������к�����ָʾ��
	*/
	void InsertIndicateCharat(int i,int value);

	
	/**
	*\brief
	*��������������������������������
	*/
	void CalaulateRowAndColumn();


	/**
	*\brief
	*���������֣��������֣�������֣�����ָʾ������ʼ������ֹ�����������г�һ������
	*/
	void SortDataCodeWord();

	/**
	*\brief
	*��ȡ��ʼ���ŵ���������
	*/
	int getStartCharacters()const;

	/**
	*\brief
	*��ȡ��ֹ���ŵ���������,
	*/
	int getEndCharacters()const;

	/**
	*\biref
	*��ȡPDF417���־������������
	*/
	std::vector<std::vector<int> > getBarSpace()const;

	/**
	*\brief
	*�����ֽ�ת��������
	*/
	void ByteToCodeWord(const unsigned char *str);

private:
	std::string m_Data;

	const unsigned char *m_RawData;

	PDF417MODE m_PDFMODE;

	//�洢ԭʼ����ת���������
	int m_Codeword[928];

	int codeptr;

	//���ֳ���
	int m_CodeWordLength;

	int m_Mode;

	//����ȼ�
	int m_level;

	//����
	int m_Columns;

	//����
	int m_Rows;

	std::vector<std::vector<int> > m_cluster;
};