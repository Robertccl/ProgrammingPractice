#define _CRT_SECURE_NO_WARNINGS

#include "imagedeal.h"
#include "util.h"

#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;

int main()
{
	/*path p("d:\\");
	directory_iterator iter(p), _end;
	while (iter != _end){
		cout << (iter++)->path() << endl;
	}*/
	//vector<double > v;

	//Mat m = imread("D:/CAR/sharpen/000001_s.jpg");
	//Mat_<Vec3b>::iterator it = m.begin<Vec3b>();
	//Mat_<Vec3b>::iterator itend = m.end<Vec3b>();
	//int rowsNumber = m.rows;
	//int colsNumber = m.cols*m.channels();
	//for (int i = 0; i < 10; i++)
	//{

	//	cout << it[i] << endl;;
	//	
	//	/*uchar* d = m.ptr<uchar>(i);
	//	for (int j = 0; j < 10; j++)
	//		cout << d[j] << endl;*/

	//}

	//getchar();

	ImageDeal myImageDeal("D:/CAR/tanke_all/", "002001", "jpg", 15);

	myImageDeal.run();
	
	return 0;
}