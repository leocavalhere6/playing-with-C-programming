#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct Person {
    char name[10];
    uint8_t age;
    uint8_t height;
};

void createPerson(char name[], 
    uint8_t age,
    uint8_t height,
    void(*function_pointer)(struct Person)){
        struct Person person;
        strcpy(person.name, name);
        person.age = age;
        person.height = age;

        (*function_pointer)(person);
    }

void printPerson(struct Person person) {
    printf("Person: %s %d %d\n",
        person.name, person.age, person.height);
}

void printPerson2(struct Person person) {
    printf("%s %d %d\n",
        person.name, person.age, person.height);
}

void main() {
    createPerson("lucas", 20, 175, &printPerson);
    createPerson("mario", 22, 185, &printPerson2);
    return ;
}