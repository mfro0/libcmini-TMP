#include <cstdint> 
#include <array> 
#include <osbind.h> 

#define LAST 101 

extern "C" char *strrev(char *str); 

namespace {
char *itoa(int num, char *str, int len, int base) { 
    int sum = num; 
    int i = 0; 
    int digit; 
    do { 
        digit = sum % base; 

        if (digit < 0xA) 
            str[i++] = '0' + digit; 
        else 
            str[i++] = 'A' + digit - 0xA; 
        sum /= base; 
    } while (sum && (i < (len - 1))); 
    str[i] = '\0'; 

    return strrev(str); 
} 

    template <int16_t i> struct squares { 
        squares <i - 1> rest; 
        int16_t x; 
        
        squares() : x((i - 1) * (i - 1)) { } 

        // make some nice support for array notation 
        int16_t& operator[](int16_t &index) { 
            return reinterpret_cast<int16_t *>(this)[index]; 
        } 

        void printme(void) { 
            char str[30]; 

            for (int16_t index = 0; index < i; index++) { 
                itoa((*this)[index], str, sizeof(str) - 1, 10); 
                Cconws(str); 
                Cconws(",\r\n"); 
            } 
        } 
    }; 
    
    template <> struct squares<1> { 
        int16_t x; 
        squares() : x(0) { } 
    }; 
} 

int main() 
{ 
    squares<LAST> s; 
    s.printme(); 
}
