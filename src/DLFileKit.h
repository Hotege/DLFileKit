//
// Created by dl on 2018/11/7.
//

#ifndef DLFILEKIT_DLFILEKIT_H
#define DLFILEKIT_DLFILEKIT_H


#include <cstddef>

class DLFileKit
{
public:
	DLFileKit();
	virtual ~DLFileKit();

	bool ReadFile(const char* pFileName);
	bool CreateFile(const char* pFileName);
	bool WriteFile(const void* pWriteData, size_t count, size_t size);
	bool CloseFile();
	bool IsFileValid();
	const long GetSize();
	const unsigned char* GetData();

protected:
	long m_nFileSize;
	void* m_pFileHandle;
	unsigned char* m_pData;
	int m_nType;
};


#endif //DLFILEKIT_DLFILEKIT_H
