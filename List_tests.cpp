// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_size1){
    List<int> list;
    int size = 3;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_size2){
    List<int> list;
    int size = 0;
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_size3){
    List<int> list;
    int size = 2;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_front();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_size4){
    List<int> list;
    int size = 1;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_front();
    list.pop_back();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_front1){
    List<int> list;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    ASSERT_EQUAL(list.front(), 2);
}

TEST(test_front2){
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    ASSERT_EQUAL(list.front(), 1);
}

TEST(test_front3){
    List<int> list;
    list.push_back(3);
    list.push_front(2);
    list.push_front(1);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
}

TEST(test_back1){
    List<int> list;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    ASSERT_EQUAL(list.back(), 1);
}

TEST(test_back2){
    List<int> list;
    list.push_back(3);
    list.push_back(2);
    list.push_front(1);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(test_back3){
    List<int> list;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_popfront1){
    List<int> list;
    int size = 0;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_front();
    list.pop_front();
    list.pop_front();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_popfront2){
    List<int> list;
    int size = 1;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_front();
    list.pop_front();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_popback1){
    List<int> list;
    int size = 1;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_back();
    list.pop_back();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_popback2){
    List<int> list;
    int size = 0;
    list.push_back(3);
    list.push_front(2);
    list.push_back(1);
    list.pop_back();
    list.pop_back();
    list.pop_back();
    ASSERT_EQUAL(list.size(), size);
}

TEST(test_1) {
    // Add test code here
        List<int> list1;
        List<int> list2;
        ASSERT_TRUE(list1.empty());
        list1.push_front(22);
        list1.push_back(73);
        list1.push_back(18);
        int s1 = 3;
        ASSERT_EQUAL(list1.size(), s1);
        list1.front() = 11;
        list1.back() = 34;
        list1.pop_front();
        list1.pop_back();
        list1.pop_back();
        list2 = list1;
        ASSERT_TRUE(list2.empty());

        List<int>::Iterator iter1 = list1.begin();
        List<int>::Iterator iter2 = list2.begin();
        list1.insert(iter1, 10);
        list2.insert(iter2, 30);
        iter1 = list1.begin();
        iter2 = list2.begin();
        ASSERT_EQUAL(list1.front(), 10);
        ASSERT_EQUAL(list2.front(), 30);
        ASSERT_TRUE(iter1.operator!=(iter2));
        list1.erase(iter1);
        iter1 = list1.begin();


}

TEST(test_2) {
    // Add test code here
        List<char> list1;
        List<char> list2;
        ASSERT_TRUE(list1.empty());
        list1.push_front('a');
        list1.push_back('b');
        list1.push_back('c');
        list1.push_front('d');
        int s1 = 4;
        ASSERT_EQUAL(list1.size(), s1);
        list1.front() = 's';
        list1.back() = 'y';
        list1.pop_front();
        list1.pop_front();
        list1.pop_back();
        list2 = list1;
        ASSERT_FALSE(list2.empty());

        //
        List<char>::Iterator iter1 = list1.begin();
        List<char>::Iterator iter2 = list2.begin();
        list1.insert(iter1, 'f');
        list2.insert(iter2, 'f');
        ASSERT_TRUE(iter1.operator!=(iter2));
        iter1 = list1.begin();
        //list1.erase(iter1);
        iter2 = list2.begin();
        ASSERT_TRUE(iter2.operator!=(iter1));
        List<char>::Iterator iter3 = list1.begin();
        ASSERT_TRUE(iter1.operator==(iter3));
        list1.erase(iter1);
        iter1 = list1.begin();
        List<char>::Iterator iter4 = list1.end();
        ASSERT_EQUAL(iter1.operator++(), iter4);
        iter1 = list1.end();
        iter4 = list1.begin();
        //cout << iter1.operator*();
        ASSERT_EQUAL(iter1, iter4.operator--());
        //ASSERT_EQUAL(iter4.operator*(), '\0');


}

TEST(test_3){
    // 42 12 21
    List<int> my;
    my.push_back(12);
    my.push_back(21);
    my.push_front(42);
    ASSERT_EQUAL(my.size(), 3);
    List<int>::Iterator iter = my.begin();
    my.insert(iter, 4);
    ASSERT_EQUAL(my.front(), 4);
    my.erase(my.begin());
    ASSERT_EQUAL(my.front(), 42);
    ASSERT_EQUAL(my.size(), 3);

    List<int>::Iterator iter2 = my.begin();
    List<int>::Iterator iter3 = my.begin();
    ASSERT_TRUE(iter2 == iter3);
    ASSERT_FALSE(iter2 != iter);
    ++iter2;

    ASSERT_EQUAL(*iter2, 12);
    --iter2;
    ASSERT_EQUAL(*iter2, 42);
    ++iter2;
    --iter2;
    ASSERT_EQUAL(*iter2, 42);
    ASSERT_EQUAL(*--++my.begin(), 42);

}

TEST(test_4){
    List<int> list;
    list.push_back(1);
    List<int>::Iterator iter = list.begin();
    list.erase(iter);
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_5){
    List<char> list3;
       list3.push_front('a');
       list3.push_back('e');
       list3.push_back('q');
       List<char>::Iterator iter3 = list3.begin();
       ASSERT_EQUAL(iter3.operator*(), 'a');
       ASSERT_EQUAL(*++iter3, 'e');
       ++iter3;
       list3.insert(iter3, 'd');
       List<char>::Iterator iter4 = list3.begin();
       List<char>::Iterator iter5 = ++iter4;
       //++iter5;
       ++iter5;
       ASSERT_EQUAL(*iter5, 'd');
       ++iter5;
       --iter5;
       list3.erase(iter5);
       list3.erase(list3.begin());
       list3.erase(list3.begin());
       list3.erase(list3.begin());
       ASSERT_TRUE(list3.empty());
}

TEST(test_6){
       List<char> list3;
       list3.push_front('a');
       list3.push_back('e');
       list3.push_back('q');
       List<char>::Iterator iter3 = list3.end();
       list3.insert(iter3, 'd');
       ASSERT_EQUAL(list3.back(), 'd');
}

TEST(test_7){
    List<int> list1;
       List<int> list2;
       ASSERT_TRUE(list1.empty());
       list1.push_front(3);
       list1.push_back(5);
       list1.push_back(7);
       List<int>::Iterator iter1 = list1.begin();
       List<int>::Iterator iter2 = list1.end();
       list1.insert(iter2, 9);
       List<int>::Iterator iter3 = ++iter1;
       ++iter3;
       ASSERT_EQUAL(*++iter3, 9);
       iter1 = list1.begin();
       list1.insert(iter1, 1);
       List<int>::Iterator iter4 = --iter3;
       --iter4;
       --iter4;
       ASSERT_EQUAL(*--iter4, 1);
       list1.erase(iter1);
       list1.erase(iter4);
       list1.erase(list1.begin());
       list1.erase(list1.begin());
       list1.erase(list1.begin());
       

}

TEST(test_8){
    List<int> list1;
    list1.push_front(12);
    list1.push_front(10);
    list1.push_front(8);
    List<int> list2(list1);
    List<int>::Iterator iter1 = list2.begin();
    ASSERT_EQUAL(*++iter1, 10);
    List<int>::Iterator iter2 = list1.begin();
    list1.erase(++iter2);
    list2.pop_front();
    ASSERT_EQUAL(list1.size(), list2.size());
    ASSERT_FALSE(iter1.operator==(iter2));
    list2 = list1;
    List<int>::Iterator iter3 = list1.begin();
    List<int>::Iterator iter4 = list2.begin();
    ASSERT_EQUAL(*++iter3, *++iter4);
}
TEST(test_9) {
    List<double> list1;
    List<double> list2;
    List<double>::Iterator iter2 = list1.begin();
    List<double>::Iterator iter3 = list2.begin();
    list1.push_front(1.5);
    list2.push_back(1.5);
    ASSERT_EQUAL(iter2, iter3);
    List<double>::Iterator iter1 = list1.end();
    list1.insert(iter1, 2.3);
    list2.push_back(2.3);
    iter2 = list1.begin();
    iter3 = list2.begin();
    // cout << *iter2 << endl;
    // cout << *iter3 << endl;
    ASSERT_EQUAL(*iter2, *iter3);
    list2.insert(iter3, 0.7);
    list1.push_front(0.7);
    ASSERT_EQUAL(*--iter2, *--iter3);
    ASSERT_EQUAL(list1.end(), list2.end());
    list1.clear();
    list2 = list1;
    ASSERT_FALSE(!list2.empty());
}
TEST(test_10) {
    List<int> list1;
    list1.push_front(1);
    list1.push_back(2);
    list1.push_front(3);
    list1.push_back(4);
    ASSERT_EQUAL(list1.size(), 4);
    List<int>::Iterator iter1 = list1.begin();
    ++++iter1;
    list1.insert(iter1, 0);
    ASSERT_EQUAL(*iter1, 2);
    //List<int>::Iterator iter2 = list1.end();
    //list1.erase(iter1);
    ASSERT_EQUAL(list1.front(), 3);
    list1.erase(list1.begin());
    ASSERT_EQUAL(list1.front(), 1);
    list1.erase(list1.begin());
    ASSERT_EQUAL(list1.front(), 0);
    list1.erase(list1.begin());
    ASSERT_EQUAL(list1.front(), 2);
    list1.clear();
    
}
TEST_MAIN()
