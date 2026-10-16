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
        printf("err");
    }
    strcpy(new_person->name, name);
    new_person->age =age;
    new_person->father= NULL;
    new_person->mother= NULL;
    return new_person;
}

void read_person_info(const char*role, char*name_out, int *age_out ){
    printf("enter name of %s",role);
    fgets(name_out,50,stdin);
    int len =strlen(name_out);
    if(name_out[len-1] =='\n'){
        name_out[len-1] = '\0';
    }
    printf("enter age of %s", role);
    scanf("%d", age_out);
    getchar();
}

void link_parents(Person*child,Person*father,Person*mother){
    if (child != NULL){
        child->father=father;
        child->mother=mother;
    }
}

void print_family_relationships(const Person*me){
    printf("me %s age %d\n",me->name,me->age);
    printf("father %s, age %d\n",me->father->name,me->father->age);
    printf("mother %s, age %d\n",me->mother->name,me->mother->age);
    printf("paternal grandffather %s, age %d\n",me->father->father->name,me->father->father->age);
    printf("paternal grandmother%s, age %d\n",me->father->mother->name,me->father->mother->age);
    printf("maternal grandffather %s, age %d\n",me->mother->father->name,me->mother->father->age);
    printf("maternal grandmother %s, age %d\n",me->mother->mother->name,me->mother->mother->age);
}

void free_family_tree(Person*people[],int count){
    for (int i = 0; i < count; i++){
        if (people[i] != NULL){
            free(people[i]);
            people[i] = NULL;
        }
    }
}
int main(void) {
    char name[50];
    int age;
    read_person_info("paternal grandfather",name,&age);
    Person*patgf =create_person(name,age);

    read_person_info("paternal grandmother",name,&age);
    Person*patgm =create_person(name,age);

    read_person_info("maternal grandfather",name,&age);
    Person*matgf =create_person(name,age);

    read_person_info("maternal grandmother",name,&age);
    Person*matgm =create_person(name,age);

    read_person_info("father",name,&age);
    Person*father =create_person(name,age);

    read_person_info("mother",name,&age);
    Person*mother =create_person(name,age);

    read_person_info("me",name,&age);
    Person*me =create_person(name,age);

    link_parents(father,patgf,patgm);
    link_parents(mother,matgf,matgm);
    link_parents(me,father,mother);
    print_family_relationships(me);
    Person*people[7]={
        patgf,
        patgm,
        matgf,
        matgm,
        father,
        mother,
        me
    };
    free_family_tree(people, 7);
}