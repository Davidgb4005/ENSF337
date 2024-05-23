/*
 *  ENSF 337 - Lab 3 Exercise D
 *  lab3exe_D.c
 */

#include <stdio.h>
#include <string.h>

const int ARRAY_SIZE = 10;


/* a structure that represents a point on a Cartesian coordinates system. */
struct point
{
    char label[3];  // a label for a point
    double x ;      // x coordinate for point in a Cartesian coordinate system
    double y;       // y coordinate for point in a Cartesian coordinate system
    double z;       // z coordinate for point in a Cartesian coordinate system
};

void display_struct_point(struct point x);
void populate_struct_array(struct point* array, int n);
int search(const struct point* struct_array, const char* label, int n);

int main(void)
{
    
    struct point struct_array[ARRAY_SIZE];
    int i;
    int position;
    
    populate_struct_array(struct_array, ARRAY_SIZE);
    
    printf("\nArray of point structures contains: \n");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i]);
    
    printf("\nNow testing function search ...\n");
    
    position = search(struct_array, "v0", ARRAY_SIZE);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "v0");
    
    position = search(struct_array, "E1", ARRAY_SIZE);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E1");
    
    position = search(struct_array, "C5", ARRAY_SIZE);
    
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "C5");
    
    position = search(struct_array, "B7", ARRAY_SIZE);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "B7");
    position = search(struct_array, "A9", 10);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "A9");
    position = search(struct_array, "E11", ARRAY_SIZE);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E11");
    
    position = search(struct_array, "M1", ARRAY_SIZE);
    if(position != -1)
        printf("\nstruct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "M1");
    
    
    
    return 0;
}

void display_struct_point(struct point x)
{
    printf("\nPoint: %s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


int search(const struct point* struct_array, const char* label, int n)

{
for(int i = 0 ; i<n ; i++){
	if (*struct_array[i].label == *label)
		return i;
}
/*
for(int i = 0 ; i<n ; i++){
	if (struct_array[i]->label == *label)
		return i;
}
*/
/*
for(int i = 0 ; i<n ; i++){
	if (*(struct_array[i]).label == *label)
		return i;
}
*/
    return -1;

}


void populate_struct_array(struct point* array, int n)
{
    int i;
    char ch1 = 'A';
    char ch2 = '9';
    char ch3 = 'z';
    
    for( i = 0; i < 10; i++)
    {
        /* generating some random values to fill them elements of the array: */
        array[i].x = (7 * (i + 1) % 11) * 100 - i /2;
        array[i].y = (7 * (i + 1) % 11) * 120 - i / 3;
        array[i].z = (7 * (i + 1) % 11) * 150 - i /4;
        
        if(i % 2 == 0)
            array[i].label[0] = ch1++;
        else
            array[i].label[0] = ch3--;
        array[i].label[1] = ch2--;
        array[i].label[2] = '\0';
    }
}
