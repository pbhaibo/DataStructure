//
//  FindWords.h
//  Ch01_02
//
//  Created by PengBo on 16/2/22.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;

#ifndef FindWords_h
#define FindWords_h

//已有的函数，查阅资料
void MakeRightWord(string &sMadeWord, char *pElemt, int nSize)
{
	sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
		sMadeWord += pElemt[i];
    }
}

void MakeLeftWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt-i);
    }
}

void MakeUpWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt-i*4);
    }
}

void MakeDownWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt+i*4);
    }
}


//for char located where row equals to col
void MakeRightDownWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt+i*4+i);
    }
}

void MakeRightUpWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt-i*4+i);
    }
}

void MakeLeftDownWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt+i*4-i);
    }
}

void MakeLeftUpWord(string &sMadeWord, char *pElemt, int nSize)
{
    sMadeWord = "";
    for (int i=0; i<nSize; i++)
    {
        sMadeWord += *(pElemt-i*4-i);
    }
}


////match the word with the words in the list
bool WordMatch(string sWord, string* pWordList, int nListSize)
{
    for (int i=0; i<nListSize; i++) {
        if (sWord == pWordList[i])
        {
            return 1;
        }
    }
    return 0;
}

void FindWords(vector<string> &sFindList, string *pWordList, char* pCh, int nSize)
{
    string sWordMade = "";
    for (int i=0; i<nSize; i++) {
        for (int j=0; j<nSize; j++) {
            //locate the pointer to &pCh[i][j] = pCh+i*nSize+j
            //search right
            for (int k=2; k<=nSize-j; k++) //k is the number of letters in a word
            {
                //make up a word
                MakeRightWord(sWordMade, pCh+i*nSize+j, k);
                //match the word with the words in the list
                if (WordMatch(sWordMade, pWordList, 4))
                {
                    //cout<<sWordMade<<'\t';
                    sFindList.push_back(sWordMade);
                }
            }
            //search left
            for (int k=2; k<=j+1; k++)
            {
                MakeLeftWord(sWordMade, pCh+i*nSize+j, k);
                if (WordMatch(sWordMade, pWordList, 4))
                {
                    //cout<<sWordMade<<'\t';
                    sFindList.push_back(sWordMade);

                }
            }
            //search up
            for (int k=2; k<=i+1; k++)
            {
                MakeUpWord(sWordMade, pCh+i*nSize+j, k);
                if (WordMatch(sWordMade, pWordList, 4))
                {
                    //cout<<sWordMade<<'\t';
                    sFindList.push_back(sWordMade);

                }
            }
            //search down
            for (int k=2; k<=nSize-i; k++)
            {
                //make up a word
                MakeDownWord(sWordMade, pCh+i*nSize+j, k);
                //match the word with the words in the list
                if (WordMatch(sWordMade, pWordList, 4))
                {
                   // cout<<sWordMade<<'\t';
                    sFindList.push_back(sWordMade);
                }
            }
            // if i==j, the diagonal should be considered
            if (i==j || (nSize-i-1)==j) {
                for (int k=2; k<=nSize-i; k++)
                {
					if ((nSize-j) < 2)
					{
						break;
					}
                    //make up a word
                    MakeRightDownWord(sWordMade, pCh+i*nSize+j, k);
                    //match the word with the words in the list
                    if (WordMatch(sWordMade, pWordList, 4))
                    {
                       // cout<<sWordMade<<'\t';
                        sFindList.push_back(sWordMade);
                    }
                }
                for (int k=2; k<=i+1; k++)
                {
					if ((nSize-j) < 2)
					{
						break;
					}
                    //make up a word
                    MakeRightUpWord(sWordMade, pCh+i*nSize+j, k);
                    //match the word with the words in the list
                    if (WordMatch(sWordMade, pWordList, 4))
                    {
                       // cout<<sWordMade<<'\t';
                        sFindList.push_back(sWordMade);
                    }
                }
                for (int k=2; k<=i+1; k++)
                {
					if ((j+1) < 2)
					{
						break;
					}
                    //make up a word
                    MakeLeftUpWord(sWordMade, pCh+i*nSize+j, k);
                    //match the word with the words in the list
                    if (WordMatch(sWordMade, pWordList, 4))
                    {
                        //cout<<sWordMade<<'\t';
                        sFindList.push_back(sWordMade);

                    }
                }
                for (int k=2; k<=nSize-i; k++)
                {
					if ((j+1) < 2)
					{
						break;
					}
                    //make up a word
                    MakeLeftDownWord(sWordMade, pCh+i*nSize+j, k);
                    //match the word with the words in the list
                    if (WordMatch(sWordMade, pWordList, 4))
                    {
                      //  cout<<sWordMade<<'\t';
                        sFindList.push_back(sWordMade);

                    }
                }
            }
        }
    }
}

#endif /* FindWords_h */
