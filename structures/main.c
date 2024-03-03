#include <stdlib.h>
#include <stdio.h>

typedef enum {
    LDAP, 
    LOCAL
} Login;

struct user{
    char * name;
    int age;
    char * email;
    char * phoneNumber;
    Login login;
};

void draw();

int main(){
    struct user user1 = {"Brian", 20, "briankathukya2000@gmail.com", "254740272915", LOCAL};
    // user1.name = "Brian";
    // user1.age = 20;
    // user1.email = "briankathukya2000@gmail.com";
    // user1.phoneNumber = "254740272915";
    draw();
    printf("My details:\n");
    printf("Name : %s\n", user1.name);
    printf("Age : %d\n", user1.age);
    printf("Email : %s\n", user1.email);
    printf("Phone Number : %s\n", user1.phoneNumber);
    draw();
    // printf("Login : %s\n", user1.login);

}

void draw(){
    printf("+++++++++++++++++++++++++++++++++\n");
}
