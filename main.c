#include <stdio.h>
#include <string.h>

#define MAX_SEATS 10
#define MAX_NAME 20

struct Passenger {
    int seat_number;
    char name[MAX_NAME];
};

struct Passenger passengers[MAX_SEATS];

void initialize_seats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        passengers[i].seat_number = 0;
        strcpy(passengers[i].name, "Empty");
    }
}

void display_seats() {
    printf(" Seat Availability \n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, passengers[i].name);
    }
}

void book_ticket() {
    int seat;
    char name[MAX_NAME];

    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS || passengers[seat - 1].seat_number != 0) {
        printf("Seat is not available");
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", name);

    passengers[seat - 1].seat_number = seat;
    strcpy(passengers[seat - 1].name, name);

    printf("Ticket booked successfully for %s at seat %d.\n", name, seat);
}

void cancel_ticket() {
    int seat;
    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS || passengers[seat - 1].seat_number == 0) {
        printf("Invalid seat number or no booking found.\n");
        return;
    }

    printf("Ticket for %s at seat %d cancelled.\n", passengers[seat - 1].name, seat);
    passengers[seat - 1].seat_number = 0;
    strcpy(passengers[seat - 1].name, "Empty");
}

int main() {
    int choice;
    initialize_seats();

    do {
        printf("\nBus Ticket Reservation Menu\n");
        printf("1. View Seat Availability\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_seats();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                cancel_ticket();
                break;
            case 4:
                printf("Thank you\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
