//
// Created by dl on 2018/11/7.
//

#include "DLFileKit.h"
#include <cstdio>
#include <cstring>

#define pFile ((FILE*)m_pFileHandle)
#define CLOSE(x) { fclose((FILE*)(x)); (x) = nullptr; }
#define DEL_ARRAY(arr) { delete[] (arr); (arr) = nullptr; }

DLFileKit::DLFileKit()
{
	m_nFileSize = 0;
	m_pFileHandle = nullptr;
	m_pData = nullptr;
	m_nType = 0;
}

DLFileKit::~DLFileKit()
{
	CloseFile();
}

bool DLFileKit::ReadFile(const char* pFileName)
{
	if (pFile)
		return false;
	if (m_pData)
		return false;
	m_pFileHandle = fopen(pFileName, "rb");
	if (pFile)
	{
		m_nType = 1;
		fseek(pFile, 0, SEEK_END);
		m_nFileSize = ftell(pFile);
		fseek(pFile, 0, SEEK_SET);
		m_pData = new unsigned char[m_nFileSize + 1];
		memset(m_pData, 0, (size_t)m_nFileSize + 1);
		fread(m_pData, (size_t)m_nFileSize, sizeof(unsigned char), pFile);
		return true;
	}
	else
		return false;
}

bool DLFileKit::CreateFile(const char* pFileName)
{
	if (pFile)
		return false;
	m_pFileHandle = fopen(pFileName, "wb");
	if (pFile)
	{
		m_nType = 2;
		return true;
	}
	else
		return false;
}

bool DLFileKit::WriteFile(const void* pWriteData, size_t count, size_t size)
{
	if (!pFile)
		return false;
	if (m_nType != 2)
		return false;
	unsigned char* pPrefix = nullptr;
	if (m_pData)
	{
		pPrefix = new unsigned char[m_nFileSize + 1];
		memset(pPrefix, 0, (size_t)m_nFileSize + 1);
		memcpy(pPrefix, m_pData, (size_t)m_nFileSize);
		DEL_ARRAY(m_pData);
		m_pData = new unsigned char[m_nFileSize + count * size + 1];
		memset(m_pData, 0, m_nFileSize + count * size + 1);
		memcpy(m_pData, pPrefix, (size_t)m_nFileSize);
		memcpy(m_pData + m_nFileSize, pWriteData, count * size);
		m_nFileSize += count * size;
		DEL_ARRAY(pPrefix);
	}
	else
	{
		m_pData = new unsigned char[count * size + 1];
		memset(m_pData, 0, count * size + 1);
		memcpy(m_pData, pWriteData, count * size);
		m_nFileSize = count * size;
	}
	fwrite(m_pData, m_nFileSize, sizeof(unsigned char), pFile);
	return true;
}

bool DLFileKit::CloseFile()
{
	if (pFile)
		CLOSE(m_pFileHandle);
	if (m_pData)
	{
		DEL_ARRAY(m_pData);
		m_nFileSize = 0;
	}
	return true;
}

bool DLFileKit::IsFileValid()
{
	return pFile != nullptr;
}

const long DLFileKit::GetSize()
{
	return m_nFileSize;
}

const unsigned char* DLFileKit::GetData()
{
	return m_pData;
}