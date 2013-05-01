// testsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <assert.h>
using namespace std;


void swap(int * array, int i, int j)
{
    if(i == j || array[i] == array[j]) return;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void bubble_sort(int* array, int len)
{
    for(int i = len-1; i > 0; i--)
    {   
        for(int j = 0; j < i; j++)
        {   
            if(array[j] > array[j+1])
            {   
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }   
        }   
    }   
}

int partition(int * array, int low, int high)
{
    //int key = swap..to get random;
    int key = array[low];
    while(low < high)
    {
        while(array[high] >= key && low < high)
            high --;
        if(low < high)
            array[low++]=array[high];
        while(array[low] <= key && low < high)
            low ++;
        if(low < high)
             array[high--]=array[low];
    }
    array[low] = key;
    return low;
}

void quick_sort(int* array, int low, int high)
{
    if(high <= low) 
        return;

    int index = partition(array, low, high);
    quick_sort(array, low, index-1);
    quick_sort(array, index+1, high);
}
//the mapping function used in bucket
int map_in_bucket(int num, int bucket_num)
{
    return num / bucket_num;
}
void bucket_sort(int* array, int len, int bucket_num)
{
    //int bucket_num = buckets_size;
    vector<vector<int>> buckets;
    for(int i = 0; i < bucket_num; i++)
    {
        vector<int> b;
        buckets.push_back(b);
    }
    for(int i = 0; i < len; i++)
    {
        buckets[map_in_bucket(array[i], bucket_num)].push_back(array[i]);
    }

    int index = 0;
    for(int i = 0; i < bucket_num; i++)
    {
        vector<int> b = buckets[i];
        sort(b.begin(), b.end());

        for(int j = 0; j < b.size(); j++)
        {
            array[index++] = b.at(j);
        }
    }
    
}

void rank_sort(int * array, int len)
{
    int * pos = new int[len];
    for(int i = 0; i < len; i++)
    {
        int num = 0; //num that smaller than a[i]
        for(int j = 0; j < len; j++)
        {
            if( (array[j] < array[i] && i != j)
            ||(array[j] == array[i] && j > i))
                num++;
        }
        pos[i] = num;
    }
    int * copyofarray = new int[len];
    memcpy(copyofarray, array, len*sizeof(int));
    for(int i = 0; i < len; i++)
        array[pos[i]] = copyofarray[i];

    delete[] pos;
    delete[] copyofarray;
}



void print_array(int * array, int len)
{
    for(int i = 0 ; i < len; i++)
        cout << array[i] << ",";
    cout << endl;
}

void print_array(vector<int> array)
{
    for(int i = 0 ; i < array.size(); i++)
        cout << array[i] << ",";
    cout << endl;
}

vector<int> getRandomNums(int size, int max)
{
    vector<int> result;
    srand(time(NULL));
    for(int i = 0 ;i < size; i ++)
        result.push_back(rand() % max);
    return result;
}

bool assertResult(int* a1, int * b1, int len)
{
    for(int i = 0 ; i < len; i++)
        if(a1[i] != b1[i])
            return false;
    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = {9,38,65,97,48,76,13,27,49,38};
    int len1 = sizeof(a)/sizeof(int);
    //bucket_sort(a, len1);
    //rank_sort(a, len1);
    //print_array(a, len1);
    //cin>>len1;
    int len = 100;
    int max = 1000;
    int bucket_size = 20;
    int bucket_num = max / bucket_size;
    
    vector<int> nums = getRandomNums(len, max);
    print_array(&nums[0], nums.size());

    vector<int> nums1(nums);
    bubble_sort(&nums1[0], nums1.size());
    print_array(&nums1[0], len);

    vector<int> nums2(nums);
    quick_sort(&nums2[0], 0, nums2.size()-1);
    print_array(&nums2[0],len);

    vector<int> nums3(nums);
    bucket_sort(&nums3[0], nums3.size(), bucket_num);
    print_array(&nums3[0],len);

    assert(assertResult(&nums3[0], &nums1[0], len) == true);
    assert(assertResult(&nums2[0], &nums1[0], len) == true);
    cin >> len;
    return 0;
}

