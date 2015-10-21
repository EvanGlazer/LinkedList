// Author: Evan Glazer


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// REGION STRUCT
typedef struct person
{
    char name[50];
    struct person *next;
};

typedef struct person PERSON;
typedef PERSON *LINK;
struct person *add_person;
struct person *current;
struct person *head;


// Function Prototypes
void append(const char* input);
void add(const char* input );
void addafter(const char* input, int loc);
void insert(const char* input);
int delete(const char* input);
void display(struct person *r);
int counter();

// Main function that displays menu
int main()
{
    int input;
    char user[50];
    struct person *n;
 while(1)
    {
        printf("\n Evan Glazer's Menu of Operations\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("/////////////////////////////////////\n\n");
        printf("Please enter the operation you would like: ");

        if(scanf("%d", &input) >= 0)
        {
            switch(input)
            {

                case 1:
                    printf("Enter the name to insert: ");
                    scanf("%s", &user);
                    insert(user);
                    break;
                case 2:
                    if(head == NULL)
                    {
                        printf("List is Empty\n");
                    }
                    else
                    {
                        printf("The List Consists of:  ");
                    }
                    display(n);
                    break;
                case 3:
                    printf("Size of the list is %d\n",counter());
                    break;
                case 4:
                     if(head == NULL)
                        printf("List is Empty\n");
                    else
                    {
                        printf("Enter the name to delete : ");
                        scanf("%s",&user);

                        if(delete(user))
                            printf("%s deleted successfully\n",user);
                        else
                            printf("%s not found in the list\n",user);
                    }
                    break;
                case 5:
                    return 0;
                default:
                    printf("Invalid option\n");
                    break;
            }
        }
        else
        {
            printf("WHOOPS! Please enter the corresponding integer!");
        }
        }

    return 0;
}

// Function definitions
void append(const char* input)
{
    struct person *temp,*right;
    temp = (LINK)malloc(sizeof(PERSON));
    strcpy(temp->name, input);
//    temp->name = input;
    right=(struct person *)head;

    while(right->next != NULL)
        right = right->next;

    right->next = temp;
    right = temp;
    right->next = NULL;
}

// adding a node to the beginning of the linked list
void add( const char*input )
{
    struct person *temp;
    temp =(LINK)malloc(sizeof(PERSON));
    strcpy(temp->name, input);
    //temp->name = input;

    // only one node on the linked list
    if (head == NULL)
    {
        head = temp;
        head->next = NULL;
    }

    else
    {
        temp->next = head;
        head = temp;
    }
}

void addafter(const char* input, int loc)
{
    int i;
    struct person *temp,*left,*right;
    // set the node right equal to the head, the beginning
    right=head;
    // looping through the linked list until we find the desired location to insert the node
    for(i = 1; i < loc; i++)
    {
        left = right;
        printf("position of the linked list %d\n\n", left->name );
        right = right->next;
    }

    temp = (LINK)malloc(sizeof(PERSON));
    strcpy(temp->name, input);
    left->next = temp;
    left = temp;
    left->next = right;

    return;
}

void insert(const char* input)
{
    int c = 0;
    struct person *temp;
    temp = head;
    if(temp == NULL)
    {
        add(input);
    }
    else
    {
        // traverse the linked list while we don't find the end
        while(temp != NULL)
        {
            // sorting data to be in numeric order
            c++;
            // this is where we want to put the data, update the pointer for the next node
            temp = temp->next;
        }

        if(c == 0)
            add(input);
        else if(c < counter())
            addafter(input, ++c);
        else
            append(input);

    }
}
int delete(const char* input)
{
    struct person *temp, *prev;
    temp = head;

    while(temp != NULL)
    {
         if (strcmp(temp->name, input) == 0)
        {
            if(temp == head)
            {
                head = temp->next;
                free(temp);
                return 1;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

void  display(struct person *r)
{
    r = head;

    if(r == NULL)
    {
        return;
    }

    while(r != NULL)
    {
        printf("%s ", r->name);
        r = r->next;
        if(r == NULL)
        {
            printf(" :End of list");

        }
    }

    printf("\n");
}

int counter()
{
    struct person *count;
    count = head;
    int c = 0;

    while(count != NULL)
    {
        count = count->next;
        c++;
    }
    return c;
}



