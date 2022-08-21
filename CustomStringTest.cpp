
#include "CustomString.h"
#include "gtest/gtest.h"
namespace ns {

    namespace {
        class CustomStringTest : public ::testing::Test {
        protected:
            void SetUp() override {
                sample = "abcd";
                sample2 = "eeeeefffffffeeeeeeffffff";
                sample3 = "abcdeeeeefffffffeeeeeeffffff";
            }
            const char *sample;
            const char *sample2;
            const char *sample3;
        };

    }

    TEST_F(CustomStringTest, DefaultConstructor) {
        string A;
        EXPECT_STREQ(A.c_str(), "");
    }

    TEST_F(CustomStringTest, CStringConstructor){
        string A(""), B(sample);
        EXPECT_STREQ(A.c_str(), "");
        EXPECT_STREQ(B.c_str(), sample);
    }

    TEST_F(CustomStringTest, CStringNConstructor){
        string A("", 100), B(sample, 1), C(sample, 0), D(sample, 100);
        EXPECT_STREQ(A.c_str(), "");
        EXPECT_STREQ(B.c_str(), "a");
        EXPECT_STREQ(C.c_str(), "");
        EXPECT_STREQ(D.c_str(), sample);
    }
    TEST_F(CustomStringTest, NCharsConstructor){
        string A(3, 'a');
        EXPECT_STREQ(A.c_str(), "aaa");
    }
    TEST_F(CustomStringTest, CopyConstructor){
        string A(sample);
        string B(A);
        EXPECT_EQ(A==B, true);
    }

    TEST_F(CustomStringTest, CopyPosLenConstructor){
        string A(sample);
        string B(A, 0);
        EXPECT_EQ(B.length(), A.length());
        EXPECT_EQ(A==B, true);
        string C(A, 1);
        EXPECT_EQ(C.length(), A.length()-1);
        EXPECT_STREQ(C.c_str(), "bcd");
        string D(A, 1, 2);
        EXPECT_EQ(D.length(), 2);
        EXPECT_STREQ(D.c_str(), "bc");
        string E(A, 2, 100);
        EXPECT_EQ(E.length(), 2);
        EXPECT_STREQ(E.c_str(), "cd");
    }


    TEST_F(CustomStringTest, MoveConstructor){
        string A(sample);
        string B(move(A));
        EXPECT_STREQ(B.c_str(), sample);
        EXPECT_EQ(A.c_str(), nullptr);
    }

    TEST_F(CustomStringTest, ListConstructor){
        string A({'a', 'b', 'c', 'd'});
        EXPECT_STREQ(A.c_str(), sample);
    }

    TEST_F(CustomStringTest, IteratorConstructor){
        string A(sample, sample+4);
        EXPECT_STREQ(A.c_str(), sample);
    }

    TEST_F(CustomStringTest, PushBack){
        string A;
        for(int i = 0; i < 10; ++i){
            A.push_back('a');
        }
        EXPECT_STREQ(A.c_str(), "aaaaaaaaaa");
        EXPECT_EQ(A.capacity(), 16);
    }

    TEST_F(CustomStringTest, POPBack){
        string A(sample);
        for(int i = 0; i < 3; ++i){
            A.pop_back();
        }
        EXPECT_STREQ(A.c_str(), "a");
        for(int i = 0; i < 3; ++i){
            A.pop_back();
        }
        EXPECT_STREQ(A.c_str(), "");
    }

    TEST_F(CustomStringTest, Clear){
        string A(sample);
        A.clear();
        EXPECT_EQ(A.empty(), true);
        EXPECT_EQ(A.capacity(), 1);
    }

    TEST_F(CustomStringTest, Append){
        string A(sample), B(sample2);
        A.append(B);
        EXPECT_STREQ(A.c_str(), sample3);
    }

    TEST_F(CustomStringTest, AssignOperator){
        string A(sample), B(sample), C(sample2);
        A = A;
        EXPECT_EQ(A==B, true);
        A = C;
        EXPECT_EQ(A==C, true);
    }

    TEST_F(CustomStringTest, MoveAssignOperator){
        string A(sample), B(sample2), C(sample2);
        A = move(A);
        EXPECT_STREQ(A.c_str(), sample);
        A = move(B);
        EXPECT_EQ(B.c_str(), nullptr);
        EXPECT_EQ(A==C, true);
    }

    TEST_F(CustomStringTest, AccessOperator){
        string A(sample);
        EXPECT_EQ(A[0], 'a');
        EXPECT_EQ(A[-1], 'd');
        EXPECT_EQ(A[-2], 'c');
        EXPECT_EQ(A[3], 'd');
        EXPECT_EQ(A[4], 'a');
    }


    TEST_F(CustomStringTest, AddOperator){
        string A(sample), B(sample2);
        EXPECT_STREQ((A+B).c_str(), sample3);
    }

    TEST_F(CustomStringTest, AddAssignOperator){
        string A(sample), B(sample2);
        A += B;
        EXPECT_STREQ(A.c_str(), sample3);
    }
}