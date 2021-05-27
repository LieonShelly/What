//
//  main.cpp
//  C++Demo
//
//  Created by lieon on 2020/6/2.
//  Copyright © 2020 lieon. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include "DoubleLinkedList.hpp"
#include <vector>
#include <map>
#include "ArrayList.hpp"

# include "BinarySearchTree.hpp"

using namespace std;

class TestPerson {
public:
    int m_age = 0;
public:
    TestPerson(int age): m_age(age) {}
    
    virtual ~TestPerson() {
        std::cout << "~TestPerson" << std::endl;
    }
    void virtual eatTest() = 0;
};

class TestStudent: public TestPerson {
public:
    
    TestStudent(int age): TestPerson(age) {
        cout << "this:" << this << endl;
    }
    
    void eatTest() override {
        cout << "TestStudent::eat" << endl;
    }

};


class TestGraduate: public TestStudent {
public:
    TestGraduate(): TestStudent(10)  {
        
    }
    
    void eatTest() override {
        cout << "TestGraduate::eat" << endl;
    }
    
};

#include "SingleCycleLinkedList.hpp"
#include "AStack.hpp"
#include "opencv.hpp"

class pgface_box
{
public:
    float x0 {0.0};
    float y0 {0.0};
    float x1 {0.0};
    float y1 {0.0};
    
    float score {0.0};
  
    cv::Point2f pts5[5];
    
public:
    pgface_box() = default;
    pgface_box(cv::Rect &box)
    {
        x0 = box.x;
        y0 = box.y;
        x1 = box.x + box.width;
        y1 = box.y + box.height;
    }
};

class pgface_pts
{
public:
    cv::Point2f pts106[106];
};

class pgface_pose
{
public:
    //unit: rad
    float pitch_;
    float yaw_;
    float roll_;
};

class pgface_attri
{
public:
    int isMen {0};
    int ageNumber{0};
};
class pgface_info
{
public:
    pgface_attri atrri;
    pgface_box box;
    pgface_pts pts;
    pgface_pose pose;
public:
    pgface_info() = default;
    ~pgface_info() = default;
    pgface_info(pgface_box &box)
    {
        this->box = box;
    }
    pgface_info(pgface_pts &pts)
    {
        this->pts = pts;
    }
    pgface_info(pgface_box &box,pgface_pts &pts)
    {
        this->box = box;
        this->pts = pts;
    }
};

class TestStudentComparator: public Comparator {
    
    bool compare(int e1, int e2) {
        return e1 > e2;
    }
};

int main( int argc, char** argv ) {
    TestStudentComparator * comparator = new TestStudentComparator();
    BinarySearchTree *tree = new BinarySearchTree(*comparator);
    for (int index = 0; index < 10; index++) {
        tree->add(index);
//        tree->remove(index);
    }
}
