////
//// Created by chen on 17-4-20.
////
//
//#include <iostream>
//#include <unistd.h>
//#include <sys/types.h>
//#include <dirent.h>
//#include <stdio.h>
//#include <errno.h>
//#include <cstdlib>
//#include <stdio.h>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    string path="/home/chen";
//    vector<string> files;//存放文件名
//    DIR *dir;
//    struct dirent *ptr;
//    char base[1000];
//    string temp;
//
//    const char *b =path.c_str();
//
//    if ((dir=opendir(b)) == NULL)
//    {
//        perror("Open dir error...");
//        exit(1);
//    }
//
//    while ((ptr=readdir(dir)) != NULL)
//    {
//        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
//            continue;
//        else if(ptr->d_type == 8)    ///file
//        {
//            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
//            temp=ptr->d_name;
//            files.push_back(temp);
//        }
//        else if(ptr->d_type == 10)    ///link file
//            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
//            continue;
//        else if(ptr->d_type == 4)    ///dir
//        {
//            temp=ptr->d_name;
//            files.push_back(temp);
//            /*
//                memset(base,'\0',sizeof(base));
//                strcpy(base,basePath);
//                strcat(base,"/");
//                strcat(base,ptr->d_nSame);
//                readFileList(base);
//            */
//        }
//    }
//    closedir(dir);
//    string cmd="";
//    for(int i=1; i<files.size(); i++)
//    {
//        //cout<<files[i]<<endl;
//        cmd+="mv /home/chen/tanke_all/";
//        cmd+=files[i];
//        cmd+="/* ";
//        cmd+="/home/chen/Desktop/tanke_all/xmlnew";
//
//        system(cmd.c_str());
//        cmd="";
//    }
//
//    //system("mv /home/chen/Desktop/tanke_all/xml/* /home/chen/Desktop/tanke_all/xmlnew/");
//
//
//    return 0;
//}