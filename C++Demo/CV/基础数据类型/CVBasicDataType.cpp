//
//  CVBasicDataType.cpp
//  C++Demo
//
//  Created by lieon on 2020/11/17.
//  Copyright © 2020 lieon. All rights reserved.
//

#include "CVBasicDataType.hpp"
#include <opencv2/opencv.hpp>
using namespace std;

/**
 # OpenCV数据类型
 - 基础数据类型（int float 数组, 矩阵, 点，矩形，Size）
 - 辅助对象：垃圾收集指针类，数据切片的范围对象（range objects，抽象的终止条件类等）
 - 大型数组类型： cv::Mat(任意纬度的包含任意基础元素的数组), cv:SparseMat（稀疏矩阵）
 - 标准库模板（STL)
 ## 基础类型
 - 固定向量类 cv:Vec<>
 ```
 cv::Vec2i i{2, 1};
 cv::Vec3i ii{3, 3, 1};
 cv::Vec4d dd{3, 3, 3, 3};
 ```
 - 固定矩阵类  cv::Matx<>
 - 适用小型矩阵操作
 ```
 b = unsigned char
 w = unsigned short
 s = short
 i = int
 f = float
 d = double
 ```
 - Point类: cv::Point<>
 - 直接通过变量名称访问
 - cv::Vec是通过下标访问
 - cv::Scalar
 - 本质上是一个四纬Point类
 - 所有的成员都是双精度浮点数
 - 继承至少cv::Vec<double,4>
 - cv::Rect
 - cv::Size
 */



void testCVBasicDataType() {
    cv::Point2i p(2, 0);
    cv::Point3i p1(2, 0, 1);
    cv::Scalar s;
    cv::Matx33f m33f(1, 2);
    cv::Vec2i i{2, 1};
    cv::Vec3i ii{3, 3, 1};
    cv::Vec4d dd{3, 3, 3, 3};
    /**
     b = unsigned char
     w = unsigned short
     s = short
     i = int
     f = float
     d = double
     */
    
}


void testPoint() {
    cv::Point2i p2i;
    cv::Point3i p3i;
    cv::Point3f p3f;
    cv::Point3f p4f(p3f);
    cv::Point2d p5(10, 10);
    
    // 叉乘
    p2i.cross(p2i);
    // 点乘
    p2i.dot(p2i);
}

void testScalar() {
    cv::Scalar s;
    cv::Scalar s2(s);
    cv::Scalar s3(10);
    cv::Scalar s4(10, 10, 100, 10);
    // 元素相乘
    s4.mul(s2);
    // 共轭
    s.conj();
    // 真值测试
    s.isReal();
    
}


void testSize() {
    cv::Size sz;
    cv::Size2i s0;
    cv::Size2f s1;
    cv::Size s3(s1);
    cv::Size2f s4(10, 1);
    float width = s4.width;
    float height = s4.height;
    float area = s4.area();
}

void testRect() {
    cv::Rect2i r;
    cv::Rect r2(r);
    cv::Rect r3(3, 1, 200, 100);
    cv::Point2d p0;
    cv::Size2d s0;
    cv::Rect r4(p0, s0);
    // 提取左下角
    r3.tl();
    // 提取右下角
    r3.br();
    r.contains(p0);
    // 矩形的交集
    cv::Rect r5 = r3 & r2;
    // 同时包含矩形r1和矩r2的最小面积矩形
    cv::Rect r6 = r3 | r2;
    r2 |= r2;
    bool eq = r2 == r3;
    bool ne = r2 != r3;
}


void testRotatedRect() {
    cv::RotatedRect rrect = cv::RotatedRect();
    rrect.center = {1, 1};
    cv::RotatedRect rr2(rrect);
    cv::Point2f p1(1, 1);
    cv::Point2f p2(1, 1);
    cv::Size2f s(10, 10);
    cv::RotatedRect rr3(p1, s, 9);
    cv::Point2f points[4];
    rrect.points(points);
    rrect.center;
    rrect.size;
    rrect.angle;
}

#include <fstream>

template<class T>
void print_marix(const cv::SparseMat_<T>* sm) {
    cv::SparseMatConstIterator_<T> it = sm->begin();
    cv::SparseMatConstIterator_<T> it_end = sm->end();
    for (; it != it_end; ++it) {
        const typename cv::SparseMat_<T>::Node *node = it.node();
        cout<< "(" << node->idx[0] << "," <<node->idx[1] << ") =" << *it << endl;
    }
}

void filterDisplace(const cv::Mat &img,
                    const cv::Mat &texture,
                    float x0 = 0,
                    float y0 = 0,
                    float hr = 1.0,
                    float vr = 1.0,
                    float a = 1.0,
                    string displaceSwitch = "gray",
                    int edge = 0) {
    int w = img.cols;
    int h = img.rows;
    if (edge == 0) {
        cv::cvtColor(texture, texture, cv::COLOR_BGR2GRAY);
    }
    int tW = texture.cols;
    int tH = texture.rows;
    int tc = texture.channels();
}
/**
 
 */
void testFilterDisplace(std::string imgPath, std::string texturePath, int blurR, std::string ptsPath) {
    cv::Mat img = cv::imread(imgPath);
    cv::Mat texture = cv::imread(texturePath);
    cv::cvtColor(texture, texture, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    
    // 读取点位
    fstream file1;
    file1.open("/Users/lieon/Desktop/置换/img.pts");
    cv::Mat pts = cv::Mat::zeros(106, 2, CV_32FC1);
    for (int i = 0; i < 106; i++) {
        for (int j = 0; j < 2; j++) {
            file1 >> pts.at<float>(i, j);
        }
    }
    // 用50%灰，填充人脸部分
    cv::Mat grayImg(img.rows, img.cols, CV_8UC1);
    cv::cvtColor(img, grayImg, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    cv::RotatedRect ellipse = cv::fitEllipse(pts);
    // 用50%灰填充人脸部分（填充椭圆），并合并到displace
    cv::Scalar s(128, 128, 128, 1);
    cv::ellipse(grayImg, ellipse, s, -1, cv::LineTypes::FILLED);
    cv::Mat displace(img.rows, img.cols, CV_8UC1);
    cv::GaussianBlur(grayImg, displace, cv::Size(0, 0), 7);
    cv::Mat temNy;
    displace.convertTo(temNy, CV_8UC1);
    cv::imshow("result", grayImg);
    cv::waitKey();
    
    int h = displace.rows;
    int w = displace.cols;
    int th = texture.rows;
    int tw = texture.cols;
    int tc = texture.channels();
    float a = 0.1;
    float b = 1.0;
    cv::Mat ones = cv::Mat(h, w, CV_32SC1, cv::Scalar(1));
    cv::Mat temD;
    displace.convertTo(temD, CV_32SC1);
    cv::Mat tmpGray = ones * 128;
    cv::Mat l = (temD - tmpGray) * a * b;
    string displaceSwitch = "gray";
    int edge = -1;
    cv::Mat np_w = cv::Mat::ones(h, w, CV_32SC1);
    cv::Mat np_h = cv::Mat::ones(h, w, CV_32SC1);
    for (int i = 0 ; i < h; i++) {
        for (int j = 0 ; j < w; j++) {
            np_h.at<int>(i ,j) = (int)i;
            np_w.at<int>(i, j) = (int)j;
        }
    }
    cv::Mat np_y = l + np_h;
    cv::Mat np_x = l + np_w;
    
    cv::Mat result = cv::Mat::ones(h, w, CV_8UC(tc));
    for (int i = 0; i < h; i++) {
        const int* npYRow = np_y.ptr<int>(i);
        const int* npXRow = np_x.ptr<int>(i);
        for(int j = 0; j < w; j++) {
            int curentYPix = *npYRow++;
            int curentXPix = *npXRow++;
            cout << "curentYPix: " << curentYPix << " curentXPix: " << curentXPix << endl;
            if (edge == 0) {
                if(curentYPix < 0 || curentXPix < 0 || curentYPix > th - 1 || curentXPix > tw - 1 ) {
                    uchar *pc = result.ptr<uchar>(i, j);
                    *(pc + 0) = 255;
                    *(pc + 1) = 255;
                    *(pc + 2) = 255;
                    *(pc + 3) = 0;
                } else {
                    uchar *pc = result.ptr<uchar>(i, j);
                    uchar *text = texture.ptr<uchar>(curentYPix, curentXPix);
                    *(pc + 0) = *(text + 0);
                    *(pc + 1) = *(text + 1);
                    *(pc + 2) = *(text + 2);
                    *(pc + 3) = *(text + 3);
                }
            } else if (edge > 0) {
                uchar *pc = result.ptr<uchar>(i, j);
                uchar *text = texture.ptr<uchar>(curentYPix % th, curentXPix% tw);
                *(pc + 0) = *(text + 0);
                *(pc + 1) = *(text + 1);
                *(pc + 2) = *(text + 2);
                *(pc + 3) = *(text + 3);
            } else {
                curentYPix = max(0, min(th - 1, (int)curentYPix));
                curentXPix = max(0, min(tw - 1, (int)curentXPix));
                result.at<uchar>(i, j) = texture.at<uchar>(curentYPix, curentXPix);
            }
        }
    }
}

void testdfdff();

void testReadImg() {
    testdfdff();
//    cv::Mat img = cv::imread("/Users/lieon/Desktop/置换/displace.png");
//    cv::Mat displace(img.rows, img.cols, CV_8UC1);
//    cv::cvtColor(img, displace, cv::ColorConversionCodes::COLOR_BGR2GRAY);
//    int h = displace.rows;
//    int w = displace.cols;
//
//    float a = 0.3;
//    float b = 1.0;
//    cv::Mat ones = cv::Mat(h, w, CV_32SC1, cv::Scalar(127));
//    cv::Mat temD;
//    displace.convertTo(temD, CV_32SC1);
//    cv::Mat l(h, w, CV_8UC1);;
//    cv::subtract(temD, ones, l);
//
//    cv::Mat temNy;
//    l.convertTo(temNy, CV_8UC1);
//    cv::imshow("l", temNy);
//    cv::waitKey();
}

void testMat() {
    cv::Mat ones = cv::Mat::ones(100, 100, CV_32FC(3));
    cv::Vec3f * ptr = ones.ptr<cv::Vec3f>(99, 99);
    //    *(ptr + 0);
    //    *(ptr + 1);
    //    *(ptr + 2);
    cv::Vec3f data = ones.at<cv::Vec3f>(99, 99);
    //    data[0];
    //    data[1];
    //    data[2];
    //
    int sz[3] = {4, 4, 4};
    cv::Mat m(3, sz, CV_32FC3);
    cv::randn(m, -1.0f, 1.0f);
    
    float max = 0.0f;
    cv::MatConstIterator_<cv::Vec3f> it = m.begin<cv::Vec3f>();
    while (it == m.end<cv::Vec3f>()) {
        float len2 = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2];
        if (len2 > max) {
            max = len2;
        }
        it++;
    }
    
    //NAryMatIterator
    const int n_mat_size = 5;
    const int n_mat_sz[] = {n_mat_size, n_mat_size, n_mat_size};
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1);
    
    // 用0.0~1.0之间的数填充数组 n_mat
    cv::RNG rng;
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.0, 1.0);
    
    const cv::Mat* arrays[] = {&n_mat, 0};
    cv::Mat m_planes[1];
    cv::NAryMatIterator nary_it(arrays, m_planes);
    float s = 0.f;
    int n = 0;
    for (int p = 0; p < nary_it.nplanes; p++, ++it) {
        s += cv::sum(nary_it.planes[0])[0];
        n++;
    }
}

// cv::SparseMat稀疏矩阵
void testSpareseMat() {
    int size[] = {10, 10 };
    cv::SparseMat sm {2, size, CV_32F };
    for (int i = 0; i < 10; i++) {
        int idx[2];
        idx[0] = size[0] * rand();
        idx[1] = size[1] * rand();
        sm.ref<float>(idx) += 1.0f;
        sm.ptr(idx, true);
        sm.find<float>(idx);
        sm.value<float>(idx);
    }
}

void sum_rgb(const cv::Mat& src, cv::Mat& dst);
void adaptiveThreshold(const string & imgPth);
void testTransform(const cv::Mat & src);
void testPerspectiveTransform(const cv::Mat & src);

void testdfdff() {
//    adaptiveThreshold("/Users/lieon/Desktop/置换/img.jpg");
    cv::Mat src1 = cv::imread("/Users/lieon/Desktop/置换/img.jpg");
    testPerspectiveTransform(src1);
}

void testFileStore() {
    cv::FileStorage fs2("test.yml", cv::FileStorage::READ);
    int frameCount = (int)fs2["frameCount"];
    string date;
    fs2["calibrationDate"] >> date;
    cv::Mat cameraMatrix2, distCoffs2;
    fs2["cameraMatrix"] >> cameraMatrix2;
    fs2["distCoffs"] >> distCoffs2;
    cv::FileNode features = fs2["features"];
    cv::FileNodeIterator it = features.begin(), it_end = features.end();
    int idx;
    vector<uchar> lbpval;
}

void testDraw() {
    cv::Mat src1 = cv::imread("/Users/lieon/Desktop/置换/img.jpg");
    cv::circle(src1, cv::Point(100, 100), 50, cv::Scalar(255, 0, 255, 1));
}

void testFlip() {
//    cv::flip(src1, src2, 0);
}


void testAddWeight() {
    cv::Mat src1 = cv::imread("/Users/lieon/Desktop/置换/img.jpg");
    cv::Mat src2 = cv::imread("/Users/lieon/Desktop/置换/output.png");
    cv::cvtColor(src2, src2, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    cv::cvtColor(src1, src1, cv::ColorConversionCodes::COLOR_BGR2GRAY);
    int x = 100;
    int y = 100;
    int w = 100;
    int h = 100;
    cv::Mat roi1(src1, cv::Rect(x, y, w, h));
    cv::Mat roi2(src2, cv::Rect(0, 0, 100, 100));
    double alpha = 1.0;
    double beta = 0.5;
    cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi1);
    cv::imshow("blend", roi1);
    cv::waitKey();
}

void sum_rgb(const cv::Mat& src, cv::Mat& dst) {
   vector<cv::Mat>planes;
    // 讲一个多通道矩阵分割成多个单通道矩阵
    cv::split(src, planes);
    /**cv::Mat b = planes[0], g = planes[1], r = planes[2], s;
    cv::addWeighted(r, 1.0 / 3.0, g, 1.0 / 3.0, 0.0, s);
    cv::addWeighted(s, 1.0, b, 1.0 / 3.0, 0.0, s);
    cv::threshold(s, dst, 128, 128, cv::THRESH_TRUNC);*/
    cv::Mat b = planes[0], g = planes[1], r = planes[2];
    cv::Mat s = cv::Mat::zeros(b.size(), CV_32F);
    cv::accumulate(b, s);
    cv::accumulate(g, s);
    cv::accumulate(r, s);
    cv::threshold(s, s, 128, 128, cv::THRESH_TRUNC);
    s.convertTo(dst, b.type());
}

void adaptiveThreshold(const string & imgPth) {
    double fixed_threshold = 1;
    double threshold_type = cv::THRESH_BINARY;
    int adptive_method = cv::ADAPTIVE_THRESH_MEAN_C;
    int block_size = 3;
    double offset = 30;
    cv::Mat Igray = cv::imread(imgPth,  cv::IMREAD_GRAYSCALE);
    if (Igray.empty()) {
        return;
    }
    cv::Mat It, Iat;
    cv::threshold(Igray,
                  It,
                  fixed_threshold,
                  255,
                  threshold_type);
    cv::adaptiveThreshold(Igray,
                          Iat,
                          255,
                          adptive_method,
                          threshold_type,
                          block_size,
                          offset);
    cv::imshow("Raw", Igray);
    cv::imshow("Threshold", It);
    cv::imshow("Adaptive Threshold", Iat);
    cv::waitKey();
}


void testTransform(const cv::Mat & src) {
//    cv::resize(src, dst, cv::Size(100, 100));
    vector<cv::Mat> dsts;
    cv::buildPyramid(src, dsts, 3);
    for(int index = 0; index < dsts.size(); index++) {
        cv::imshow(std::to_string(index), dsts[index]);
    }
    cv::waitKey();
}


void testAffineTransform(const cv::Mat & src) {
    cv::Point2f srcTri[] = {
        cv::Point2f(0, 0),
        cv::Point2f(src.cols - 1, 0),
        cv::Point2f(0, src.rows - 1)
    };
    cv::Point2f dstTri[] = {
        cv::Point2f(src.cols * 0.f, src.rows * 0.33f),
        cv::Point2f(src.cols * 0.8f, src.rows * 0.25f),
        cv::Point2f(src.cols * 0.15f, src.rows * 0.7f)
    };
    cv::Mat warp_mat = cv::getAffineTransform(srcTri, dstTri);
    cv::Mat dst, dst2;
    cv::warpAffine(src,
                   dst,
                   warp_mat,
                   src.size(),
                   cv::INTER_LINEAR,
                   cv::BORDER_CONSTANT,
                   cv::Scalar()
                   );
    for (int i = 0; i < 3; ++i) {
        cv::circle(dst,
                   dstTri[i],
                   5,
                   cv::Scalar(255, 0, 255));
    }
    cv::imshow("Test", dst);
    cv::waitKey();
}

void testPerspectiveTransform(const cv::Mat & src) {
    cv::Point2f scrcQuad[] = {
        cv::Point2f(0, 0),
        cv::Point2f(src.cols - 1, 0),
        cv::Point2f(src.cols - 1, src.rows - 1),
        cv::Point2f(0, src.rows - 1),
    };
    cv::Point2f dstQuad[] = {
        cv::Point2f(src.cols * 0.05f, src.rows * 0.33f),
        cv::Point2f(src.cols * 0.9f, src.rows * 0.25f),
        cv::Point2f(src.cols * 0.8f, src.rows * 0.9f),
        cv::Point2f(src.cols * 0.2f, src.rows * 0.7f),
    };
    cv::Mat warp_mat = cv::getPerspectiveTransform(scrcQuad, dstQuad);
    cv::Mat dst;
    cv::warpPerspective(src, dst, warp_mat, src.size());
    for (int i = 0; i < 4; ++i) {
        cv::circle(dst, dstQuad[i], 5, cv::Scalar(255, 0, 255));
    }
    cv::imshow("pe", dst);
    cv::waitKey();
}

