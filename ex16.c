// adding the 'stdio.'-header file so I can use the printf-function
#include <stdio.h>
// adding the 'assert.h'-header file so I can use the assert-funtion
#include <assert.h>
// adding the 'stdlib.h'-header file so I can use the malloc-funtion
#include <stdlib.h>
// adding the 'string.h'-header file so I can use the strdup-function
#include <string.h>

// declaring the structure 'Person' with four elements
struct Person {
	// declaring the char 'name'-element 
	char *name;
	// declaring the int 'age'-element 
	int age;
	// declaring the int 'height'-element 
	int height;
	// declaring the int 'weight'-element 
	int weight;
};

// function that returns a Person-structure which takes four parameters to fill it
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// creating a Person-structure via malloc which returns a block of memory to the who pointer
	struct Person *who = malloc(sizeof(struct Person));
	// checking if the who-pointer points to a valid location, otherwise quitting the program
	assert(who != NULL);
	
	// filling the 'name'-element of the struct with a pointer to a duplicate of the name parameter
	who->name = strdup(name);
	// filling the 'age'-element of the struct with the age parameter
	who->age = age;
	// filling the 'height'-element of the struct with the height paramenter
	who->height = height;
	// filling the 'weight'-element of the struct with the weight paramenter
	who->weight = weight;
	
	// returning the structure which who is pointing to
	return who;
}	

// function without return-value that takes one Person-structure as a parameter
void Person_destroy(struct Person *who)
{
	// checking if the who-pointer points to a valid location, otherwise quitting the program
	assert(who != NULL);

	// releasing the memory allocated to the name element via strdup
	free(who->name);
	// releasing the memory allocated to the Person-structure via malloc
	free(who);
}

// function without return-value that takes ein Person-structure as parameter
void Person_print(struct Person *who)
{
	// printing the value of the name element of the Person-structure to the console
	printf("Name: %s\n", who->name);
	// printing the value of the age element of the Person-structure to the console
	printf("\tAge: %d\n", who->age);
	// printing the value of the height element of the Person-structure to the console
	printf("\tHeight: %d\n", who->height);
	// printing the value of the weight element of the Person-structure to the console
	printf("\tWeight: %d\n", who->weight);	
}

// the main-function, returning an integer value, taking parameters with program call and counts them
int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
			"Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
