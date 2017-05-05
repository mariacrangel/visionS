// Profile.cpp: implementation of the Profile class.
//
//////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include "Profile.h"
#include<ctype.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

char*	_strlwr(char *string)
{
	for (char *p = string; p < string + strlen(string); p++)
	{
		if (isupper(*p))
		{
			*p = tolower(*p);
		}
	}

	return string;
}

CProfile::CProfile()
{

}

CProfile::~CProfile()
{

}
/*
 *return value：-3：open file failed；-2：parameter error；-1：system error；other：return character string length
 */
DWORD CProfile::GetPrivateProfileString(
                              const char* lpAppName,        // section name
                              const char* lpKeyName,        // key name
                              const char* lpDefault,        // default string
                              char* lpReturnedString,  // destination buffer
                              DWORD nSize,              // size of destination buffer
                              const char* lpFileName        // initialization file name
                              )
{
	if(NULL == lpReturnedString || nSize <= 0)
	{
		return -2;
	}
	memset(lpReturnedString, 0, nSize);
	
	fpos_t pos = {0};
	char*  pBuf = NULL;
	FILE* pFile = fopen(lpFileName, "r");
	
	if(NULL == pFile)
	{
		return -3;
	}
	fseek(pFile, 0, SEEK_END);
	if(	fgetpos(pFile, &pos) != 0)
	{
		return -1;
	}

	int npos = 0;
#if (defined(WIN32)||defined(MAC))
        npos = pos;
#else	//linux
        npos = pos.__pos;
#endif

	if(npos <= 0)
	{
		fclose(pFile);
		return -1;
	}
	pBuf = new char[npos+1];
	if(NULL == pBuf)
	{
		return -1;
	}
	memset(pBuf, 0, npos+1);
	fseek(pFile, 0, SEEK_SET);
	int nRead = fread(pBuf, sizeof(char), (int)npos, pFile);
	fclose(pFile);
	_strlwr(pBuf);
	
	char szAppName[128] = {0};
	char szKeyName[128] = {0};
	strcpy(szAppName, lpAppName);
	strcpy(szKeyName, lpKeyName);
	_strlwr(szAppName);
	_strlwr(szKeyName);
	char* pLeftSeciton = NULL;
	char* pRightSection = NULL;
	char* pKeySection = NULL;
	DWORD dwSize = 0;
	pLeftSeciton = strstr(pBuf, szAppName);
	if(pLeftSeciton != NULL)
	{
		pRightSection = strstr(pLeftSeciton, "[");
		if(pRightSection == NULL)
		{
			pRightSection = pBuf + nRead;
		}
		pKeySection = strstr(pLeftSeciton, szKeyName);
	}

	if(NULL == pLeftSeciton || NULL == pKeySection || pKeySection < pLeftSeciton || pKeySection >pRightSection)//关键字不在范围之内
	{
		dwSize = nSize<strlen(lpDefault) ? nSize-1 : strlen(lpDefault);
		memcpy(lpReturnedString, lpDefault, dwSize);
		delete []pBuf;
		return dwSize;
	}
	pLeftSeciton = strstr(pKeySection, "=");
	pRightSection = strstr(pKeySection, "\n");
	dwSize = nSize<(pRightSection-pLeftSeciton-1) ? nSize-1 : (pRightSection-pLeftSeciton-1);
	memcpy(lpReturnedString, pLeftSeciton+1, dwSize);
	delete []pBuf;
	return dwSize;
}
