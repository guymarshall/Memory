#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
         // iOS, tvOS, or watchOS Simulator
    #elif TARGET_OS_MACCATALYST
         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
    #elif TARGET_OS_IPHONE
        // iOS, tvOS, or watchOS device
    #elif TARGET_OS_MAC
        // Other kinds of Apple platforms
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

int main()
{
    char characters[10] = "ABCDEFGHIJ";

    printf("Enter number of chars to print (max 10): ");
    int number_of_chars;
    scanf("%i", &number_of_chars);

    for (int i = 0; i < number_of_chars; i++)
    {
        if (characters[i] == '\0')
        {
            printf("\n");
        }
        else
        {
            printf("%c", characters[i]);
        }
    }
    
    printf("\n");

    printf("Press enter to continue...\n");
    getchar();

    return 0;
}