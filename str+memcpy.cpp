#include <iostream>
#include <string>
using namespace std;

char * strcpy1(char* dest, const char* src)
{
    if(dest == NULL || src == NULL) return NULL;
    if(dest == src) return dest;
    char* destbak = dest;
    while ((*dest++ = *src++) != '\0')//, 如果内存有重叠，这里会出错，BAD_ACCESS, *src的\0被覆盖了,strcpy1(s+1, s)
        ;
    return destbak;
}

char * strcpy2(char* dest, const char* src)
{
    if(dest == NULL || src == NULL) return NULL;
    if(dest == src) return dest;
    char* destbak = dest;
    int len = strlen(src) + 1; //add '\0'
    while(len > 0)
    {
        *(dest+len-1) = *(src+len-1);
        --len;
    }
    return destbak;
}

char * strcpy3(char* dest, const char* src)
{
    if(dest == NULL || src == NULL) return NULL;
    if(dest == src) return dest;
    char* destbak = dest;
    int len = strlen(src) + 1; //add '\0'
    if(dest < src || dest > src+len)
    {
        while ((*dest++ = *src++) != '\0')
            ;
    }else
    {
        while(len > 0)
        {
            *(dest+len-1) = *(src+len-1);
            --len;
        }
    }
    return destbak;
}

void * mymemcpy(void* void_dest, void* void_src, size_t len)
{
    if(void_dest == NULL || void_src == NULL || len == 0) return void_dest;
    char * dest = (char*) void_dest;
    char * src = (char*) void_src;
    void* destbak = void_dest;
    if(dest < src || dest > src+len)
    {
        while ((*dest++ = *src++) != '\0')
            ;
    }else
    {
        while(len > 0)
        {
            *(dest+len-1) = *(src+len-1);
            --len;
        }
    }
    return destbak;
}

void * mymemcpy2(void* void_dest, void* void_src, size_t len)
{
    if(void_dest == NULL || void_src == NULL || len == 0) return void_dest;
    int * dest = (int*) void_dest;
    int * src = (int*) void_src;
    void* destbak = void_dest;
    if(dest < src || dest > src+len)
    {
        int i = 0;
        for(i = 0; i < len / 4; i++)
            *(dest+i) = *(src+i);
        for(i = len / 4 * 4; i < len; i++)
            *((char*)dest + i) = *((char*)src + i);
    }else
    {
        int i = 0;
        for(i = len-1; i >= len / 4 * 4; i--)
            *((char*)dest + i) = *((char*)src + i);
        for(i = len / 4 - 1; i >=0 ; i--)
            *(dest+i) = *(src+i);
    }
    return destbak;
}

int main()
{
    char  word[] = "Hello World!"; //not char*, or else sizeof(word) is sizeof(pointer)
    const int len = sizeof(word)/sizeof(char); //13, including '\0'
    cout << word << endl;
    cout << "\t sizeof(word)/sizeof(char) = " << len << endl;
    cout << "\t strlen(word) = " << strlen(word) << endl;
    char * (*func)(char*, const char*);
    func = strcpy3;
    
    {
        char dest[len + 1];
        char * s = new char[len+1];
        for(int i = 0; i < len; i++)
            s[i] = word[i];
        {
            cout << func(dest, s) << endl;
            //strcpy1 : ok
            //strcpy2 : ok
            //strcpy3 : ok
        }
        {
            cout << func(s+1, s) << endl;
            //strcpy1 : BAD_ACCESS, dest "HHHHHHHHHHHHHHHHHH....."
            //strcpy2 : ok
            //strcpy3 : ok
            
        }
    }
    {
        char dest[len + 1];
        char * s = new char[len+1];
        for(int i = 1; i < len+1; i++)
            s[i] = word[i-1];
        {
            cout << func(dest, s+1) << endl;
            //strcpy1 : ok
            //strcpy2 : ok
            //strcpy3 : ok
        }
        {
            cout << func(s, s+1) << endl;
            //strcpy1 : ok
            //strcpy2 : '\0'
            //strcpy3: ok
        }
    }
    cout << "mymemecpy" << endl;
    {
        char dest[len + 1];
        char * s = new char[len+1];
        for(int i = 0; i < len; i++)
            s[i] = word[i];
        {
            cout << (char*)mymemcpy2(s+1, s, len) << endl;
        }
    }
    {
        char dest[len + 1];
        char * s = new char[len+1];
        for(int i = 1; i < len+1; i++)
            s[i] = word[i-1];
        {
            cout << (char*)mymemcpy2(dest, s+1, len) << endl;
        }
        {
            cout << (char*)mymemcpy2(s, s+1, len) << endl;
        }
    }
}
