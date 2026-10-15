#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Person {
char name[50];
int age;
struct Person *father;
struct Person *mother;
} Person;

Person* create_person(const char*name, int age) {
    Person *new_person = (Person*)malloc(sizeof(Person));
    if (new_person == NULL){
        printf("err\n");
    }
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->father = NULL;
    new_person->mother = NULL;
    return new_person;
}

int main(void){
    Person *test_person = create_person("sid",19);
    printf("name %s",test_person->name);
    printf("age %d",test_person->age);
    printf("father ptr%p", (void *)test_person->father);
    printf("mother ptr %p",(void*)test_person->mother);
    free(test_person);
    test_person = NULL;
    return(0);
}