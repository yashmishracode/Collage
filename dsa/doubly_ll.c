
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    printf("%d inserted at beginning.\n", value);
}

// Insert at end
void insertEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    printf("%d inserted at end.\n", value);
}

// Delete from beginning
void deleteBeginning(void)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Deleted: %d\n", temp->data);

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete from end
void deleteEnd(void)
{
    if (tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = tail;
    printf("Deleted: %d\n", temp->data);

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

// Display forward
void display(void)
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(void)
{
    int choice, value;

    do
    {
        printf("\n--- Doubly Linked List ---\n"
               "1. Insert at beginning\n"
               "2. Insert at end\n"
               "3. Delete from beginning\n"
               "4. Delete from end\n"
               "5. Display forward\n"
               "0. Exit\n"
               "Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
            case 2:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (choice == 1)
                    insertBeginning(value);
                else
                    insertEnd(value);

                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}