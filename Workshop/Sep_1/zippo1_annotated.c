// fun with arrays and pointers 
#include <stdio.h>
int main(void)
{
	// setting up an array with 4 rows, 2 columns
	int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
	
	/* Output line 1
		zippo is the address of its first element.
		The first element of zippo is itself an array of two ints,
		so zippo is the address of an array of two ints.
		Adding 1 to a pointer or address yields a value larger by the size 
		of the referred-to object.
		zippo is the address of an array of 2 ints so it identifies an 8-byte 
		data object (assuming 4-byte ints, which is usual but not guaranteed); 
		thus, adding 1 to zippo should produce an address that is larger by 8.
	*/
	printf("   zippo = %p,    zippo + 1 = %p\n",
			   zippo,         zippo+1);
			   
	/* Output line 2
		Because zippo is the address of the array's first element, 
		zippo has the same value as &zippo[0].
		zippo[0] is an array of two integers, so zippo[0] has the same value 
		as &zippo[0][0], the address of the first element.
		Both zippo and zippo[0] begin at the same location
		so zippo and zippo[0] have the same numeric value.
		zippo[0] points to a 2-int array, so adding 1 to zippo[0] should produce 
		the address of its second item, a value larger by 4 (on most systems).
	*/
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
	        zippo[0],      zippo[0] + 1);

	/* Output line 3
		*zippo represents the value of zippo's first element, zippo[0], a 2-int array.
		Thus zippo's first element is in fact an address.
		So the statement below should give the same results as in output line 2.
	*/
	printf("  *zippo = %p,   *zippo + 1 = %p\n",
	          *zippo,        *zippo + 1);

	/* Output line 4
		Finally, some notation that is not confusing!
	*/
	printf("zippo[0][0] = %d\n", zippo[0][0]);

	/* Output line 5
		Dereferencing a pointer or address yields the value represented 
		by the referred-to object. 
		Because zippo[0] is the address of its (zippo[0] 's) first element, 
		*(zippo[0]) represents the value stored in zippo[0][0], an int.
		*zippo represents the value of zippo's first element, zippo[0], but 
		zippo[0] itself is the address of an int.
		Same result as the previous line!
	*/	
	printf("  *zippo[0] = %d\n", *zippo[0]);

	/* Output line 6
		zippo is the address of an address and must be dereferenced twice 
		to get an ordinary value. Same result as the previous two lines!
	*/
	printf("    **zippo = %d\n", **zippo);

	/* Output line 7
		This should also not be confusing.
	*/
	printf("      zippo[2][1] = %d\n", zippo[2][1]);
	
	/* Output line 8
		To match the output of the previous line using pointer notation 
		we do the following (working outward):
		zippo			the address of the first two-int element
		zippo+2			the address of the third two-int element
		*(zippo+2)		the third element, which is a two-int array			
							so this is the address of its first element
		*(zippo+2) + 1	the address of the second element of the third two-int array (an int)
		*(*zippo+2) +1)	the value of the second element in the third row (zippo[2][1])
	*/
	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));
}

