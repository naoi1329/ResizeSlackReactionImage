//
//  main.cpp
//  resizeToSlackReaction
//
//  Created by 直井翔汰 on 2018/07/21.
//  Copyright © 2018年 直井翔汰. All rights reserved.
//

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//正規表現系
#include <regex>

//ファイル系
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

//openCV系
#include <opencv2/opencv.hpp>

//関数宣言
std::vector<std::string> getDirectoryFileList(const char* directoryPath);
bool includeImageFileExtension(std::string str);
std::vector<std::string> split(const std::string &str, char sep);

int main(int argc, const char * argv[]) {
    // insert code here...
    const char* directoryPath = argv[1];
//    char* directoryPath = "/Users/naoishota/Desktop/AIBECK";
    
    std::vector<std::string> strings = getDirectoryFileList(directoryPath);
    std::vector<std::string> imageFilePaths, imageFileName;
    
    for (int i = 0; i < strings.size(); i++) {
        if (includeImageFileExtension(strings[i])) {
            imageFilePaths.push_back(directoryPath + std::string("/") + strings[i]);
            imageFileName.push_back(strings[i]);
        }
    }
    
    //mkdir
    std::string makeDirectoryPath = std::string(directoryPath) + std::string("/resizeImages");
    
    struct stat statBuf;
    if (stat(makeDirectoryPath.c_str(), &statBuf) != 0) {
        if (mkdir(makeDirectoryPath.c_str(), 0777) != 0) {
            std::cout << "can't mkdir" << std::endl;
            return -1;
        }
    }
    for (int i = 0; i < imageFilePaths.size(); i++) {
        //image Open
        cv::Mat sourceImage = cv::imread(imageFilePaths[i]);
        
        if (sourceImage.empty()) {
            std::cout << "can't read image" << imageFilePaths[i] << std::endl;
            continue;
        }
        //image resize
        cv::Mat resizeImage;
        int resizeX, resizeY;
        if (sourceImage.cols >sourceImage.rows) { //横方向に長い画像の時
            //横方向正規化
            resizeX = 128;
            resizeY = sourceImage.rows * 128 / sourceImage.cols;
        } else { //たて方向に長い画像の時
            //たて方向に正規化
            resizeY = 128;
            resizeX = sourceImage.cols * 128 / sourceImage.rows;
        }
        cv::resize(sourceImage, resizeImage, cv::Size(resizeX, resizeY));
        //image save
        cv::imwrite((makeDirectoryPath + "/" + imageFileName[i]).c_str(), resizeImage);
    }
    
    return 0;
}


std::vector<std::string> getDirectoryFileList(const char* directoryPath) {
    DIR* directory = opendir(directoryPath);
    std::vector<std::string> returnStrings;
    if (directory != NULL) {
        struct dirent* dent;
        do {
            dent = readdir(directory);
            
            if (dent!=NULL) {
                returnStrings.push_back(std::string(dent->d_name));
            }
            
        } while(dent!=NULL);
        closedir(directory);
    }
    
    return returnStrings;
}


bool includeImageFileExtension(std::string str) {
    
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    if (std::regex_search(str, std::regex(".(jpg|gif|jpeg|png)"))) {
        return true;
    }
    
    return false;
}

std::vector<std::string> split(const std::string &str, char sep) {
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    
    while(std::getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}
