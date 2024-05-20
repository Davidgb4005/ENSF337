/* lab2exe_E.c
 * ENSF 337, Lab 2 Exercise E
 */

#include <stdio.h>
#include <string.h>

// Function prototypes
int substring(const char *s1, const char *s2);
/* REQUIRES
 * s1 and s2 are valid C-strings terminated with '\0';
 * PROMISES
 * returns 1 if s2 is a substring of s1. Otherwise, returns 0.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 * n_source >= 0.
 * Elements source[0], source[1], ..., source[n_source - 1] exist.
 * Elements negatives_only[0], negatives_only[1], ..., negatives_only[n_source - 1] exist.
 * PROMISES
 * number_of_negatives == number of negative values in source[0], ..., source[n_source - 1].
 * negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain those negative values, in
 * the same order as in the source array.
 */

int main(void)
{
    char s[] = "Knock knock! Who's there?"; // Test string for the substring function
    int a[] = { -10, 9, -17, 0, -15 }; // Test array for the select_negatives function
    int size_a; // Variable to hold the size of array a
    int i; // Loop index
    int negative[5]; // Array to store negative numbers from array a
    int n_negative; // Variable to hold the number of negative numbers found
    
    size_a = sizeof(a) / sizeof(a[0]); // Calculate the number of elements in array a
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++) {
        printf("  %d", a[i]);
    }
    printf("\n");
    
    // Call select_negatives to find and store negative numbers from array a
    select_negatives(a, size_a, negative, &n_negative);
    
    printf("\nnegative elements from array a are as follows:");
    for (i = 0; i < n_negative; i++) {
        printf("  %d", negative[i]);
    }
    printf("\n");
    
    // Test the substring function with various test cases
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n", substring(s, "Who"));
    printf("Answer must be 0. substring function returned: %d\n", substring(s, "knowk"));
    printf("Answer must be 1. substring function returned: %d\n", substring(s, "knock"));
    printf("Answer must be 0. substring function returned: %d\n", substring(s, ""));
    printf("Answer must be 1. substring function returned: %d\n", substring(s, "ck! Who's"));
    printf("Answer must be 0. substring function returned: %d\n", substring(s, "ck!Who's"));
    
    return 0;
}

// Function to check if s2 is a substring of s1
int substring(const char *s1, const char* s2) {
    #define InPlaceMethod 1 // Set value to 1 to Use the in-place method for substring checking(set other method to 0)
    #define CopyMethod 0 // Set value to 1 to Use the copy method(set other method to 0)

    #if CopyMethod
    {
        char UserStringNullByte = 1;
        int UserStringLength = 0;
        char UserStringChar[64];
        char SubStringNullByte = 1;
        int SubStringLength = 0;
        char SubStringChar[64];
        int IndexValue = 0;
        int StringCompare = 0;
        
        // Determine the lengths of s1 and s2
        while ((SubStringNullByte != 0 || UserStringNullByte != 0) && IndexValue < 64) {
            if (*(s1 + IndexValue) == 0 && UserStringNullByte == 1) {
                UserStringNullByte = 0;
                UserStringLength = IndexValue * sizeof(char);
            }
            if (*(s2 + IndexValue) == 0 && SubStringNullByte == 1) {
                SubStringNullByte = 0;
                SubStringLength = IndexValue * sizeof(char);
            }
            IndexValue++;
        }

        // Copy s2 to SubStringChar array
        for (int i = 0; i < SubStringLength; i++) {
            SubStringChar[i] = *(s2 + i);
        }
        
        // Copy s1 to UserStringChar array
        for (int i = 0; i < UserStringLength; i++) {
            UserStringChar[i] = *(s1 + i);
        }

        // Check if s2 is a substring of s1
        for (int i = 0; i < UserStringLength - SubStringLength; i++) {
            for (int j = 0; j < SubStringLength; j++) {
                if (SubStringChar[j] == UserStringChar[i + j]) {
                    StringCompare++;
                } else {
                    StringCompare = 0;
                }
            }
            if (StringCompare == SubStringLength && StringCompare > 0) {
                return 1;
            }
        }

        return 0;
    }
    #endif

    #if InPlaceMethod
    {
        int IndexValue = 0;
        int MatchCounter = 0;
        
        // Iterate through s1 to search for substring s2 in s1
        while (*(s1 + IndexValue) != '\0' && *(s2 + MatchCounter) != '\0' && IndexValue < 64) {
            if (*(s1 + IndexValue) == *(s2 + MatchCounter)) {
                MatchCounter++; // Increment match counter if characters match
            } else {
                MatchCounter = 0; // Reset match counter if characters do not match
            }
            IndexValue++;
        }
        // Return 1 if a match is found, otherwise return 0
        if ((MatchCounter > 0 && *(s1 + IndexValue) != '\0') || (*(s2 + MatchCounter) == '\0' && *(s1 + IndexValue) == '\0')) {
            return 1;
        } else {
            return 0;
        }
    }
    #endif
}

// Function to select negative numbers from the source array
void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives)
{
    *number_of_negatives = 0; // Initialize the count of negative numbers to 0

    // Iterate through the source array to find negative numbers
    for (int i = 0; i < n_source; i++) {
        if (*(source + i) < 0) {
            *(negatives_only + *number_of_negatives) = *(source + i); // Add negative number to negatives_only array
            (*number_of_negatives)++; // Increment the count of negative numbers
        }
    }

    return;
}
