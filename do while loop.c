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
