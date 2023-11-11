// Client.c

#include <stdio.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(PORT);

    // Connect to server
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    char name[20];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    // Send the name to the server
    send(clientSocket, name, strlen(name), 0);

    char message[1024];

    while (1) {
        // Get user input
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        // Send the message
        send(clientSocket, message, strlen(message), 0);

        // Receive and display the response
        recv(clientSocket, message, sizeof(message), 0);
        printf("Server says: %s", message);
    }

    // Close the socket
    closesocket(clientSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
