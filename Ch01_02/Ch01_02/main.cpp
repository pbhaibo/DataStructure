//
//  main.cpp
//  Ch01_02
//
//  Created by PengBo on 16/2/22.
//  Copyright © 2016年 PengBo. All rights reserved.
//

#include <iostream>
#include "FindWords.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //generate input word list
    string sWordList[5];
    sWordList[0] = "this";
    sWordList[1] = "two";
    sWordList[2] = "fat";
    sWordList[3] = "that";
    
    //generate 2-d arrays
    char pCh[4][4] = {'t', 'h', 'i', 's',
                        'w', 'a', 't', 's',
                        'o', 'a', 'h', 'g',
                        'f', 'g', 'd', 't'};
    
    //print out pChar
	cout<<"The words riddle is \n";
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout<<pCh[i][j]<<'\t';
        }
        cout<<endl;
    }
    
    vector<string> sFindWordList;
    
    FindWords(sFindWordList, sWordList, &pCh[0][0], 4);
    
	cout<<"\nThe words found are as follows: ";
    int nListSize = sFindWordList.size();
    for (int i=0; i<nListSize; i++) {
        cout<<'['<<sFindWordList[i]<<']'<<' ';
    }
    
    cout<<endl;
    
    return 0;
}
