//
//  DirectoryFileList.cpp
//  resizeToSlackReaction
//
//  Created by 直井翔汰 on 2018/07/21.
//  Copyright © 2018年 直井翔汰. All rights reserved.
//

//#include "DirectoryFileList.hpp"
//
//DirectoryFileList::getDirectryFileList() {
//    
//}
//
//WIN32_FIND_DATA find_dir_data;
//CString dir_search_path = "c:\\*";
//HANDLE hFind = FindFirstFile(dir_search_path , &find_dir_data);
//do{
//    if( hFind != INVALID_HANDLE_VALUE ) {
//        if( strcmp( find_dir_data.cFileName, "." ) &&
//           strcmp( find_dir_data.cFileName, ".." )
//           ){
//            if( find_dir_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) {
//                // フォルダ
//                AfxMessageBox(find_dir_data.cFileName);
//            }else{
//                // ファイル
//            }
//        }
//    }
//}while(FindNextFile(hFind,&find_dir_data));
