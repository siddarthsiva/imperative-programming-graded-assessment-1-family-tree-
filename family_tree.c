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

int main(void){
    char name[50];
    int age;
    Person*family[7];
    const char *roles[7]={
        "pgf",
        "pgm",
        "mgf",
        "mgm",
        "f",
        "m",
        "me",
    };

    for (int i=0; i<7; i++){
        read_person_info(roles[i], name, &age);
        family[i] = create_person(name,age);
    }

    for (int i = 0; i < 7; i++) {
        printf("%s %s %d %p\n",
               roles[i],family[i]->name,family[i]->age, (void*)family[i]);
    }

    for (int i = 0; i <7; i++) {
        free(family[i]);
        family[i] = NULL;
    }
    return 0;
}