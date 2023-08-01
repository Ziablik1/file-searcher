//
//
// Test file
//
//
#include <iostream>
#include <filesystem>
#include <string>
#include <thread>

namespace fs = std::filesystem;
using namespace fs;
using namespace std;

path findFileInDirectory(const string& directory, const string& targetFile) {
    for (const auto& entry : recursive_directory_iterator(directory)) {
        //cout << entry.path().filename() << endl;
        if (entry.is_regular_file() && entry.path().filename() == targetFile) {
            return entry.path();
        }
    }
    return {}; // file not found
}

// list all folders in directory 
vector<path> listFoldersInRoot(const string& directory, const string& targetFile, path& fileInRoot) { 
    vector<path> folders;
    for (const auto& entry : directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename() == targetFile) { 
            fileInRoot = entry.path(); 
            //cout << fileInRoot << endl;
            return {}; // if the searched file is found
        }
        else if (is_directory(entry)) {
                //cout << entry.path().filename() << endl;
                folders.push_back(entry.path());
            }
    }
    return folders;
}

void search(const string& name){
    //string directory = "C:"; // root directory
    string directory = "."; // root directory
    string targetFile = name;
    
    path fileInRoot;
    vector<path> folderList = listFoldersInRoot(directory, targetFile, fileInRoot);
    // for (auto i: folderList){
    //     cout << i << endl;;
    // }
    // cout << fileInRoot << endl;

    //vector<thread> threads;
    //thread t1(findFileInDirectory, directory, targetFile);
    // const int maxThreads = 8;
    // for (int i = 0; i < maxThreads; ++i) {
    //     threads.emplace_back(thread(findFileInDirectory, folderList[i], targetFile));
    // }
    // for (auto& thread : threads) {
    //     thread.join();
    // }
    
    try{
        path filePath = findFileInDirectory(directory, targetFile);
       if (!filePath.empty()) {
        cout << "File found at path: " << filePath << endl;
    } else {
        cout << "File not found in the given directory." << endl;
    } 
    }
    catch(...){
        cout << "Something went wrong" << endl;
    }
}

int main() {
    string fileName;
    cout << "Enter file name you'd like to search (for example \"file.txt\"):" << endl;
    cin >> fileName;
    search(fileName);
    //system("pause");
    return 0;
}