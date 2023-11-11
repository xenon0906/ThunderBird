// Server.c

#include <stdio.h>
#include <winsock2.h>

#define MAX_CLIENTS 75
#define PORT 12345

void handleClient(SOCKET clientSocket);

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    listen(serverSocket, MAX_CLIENTS);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a client socket
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);

        // Handle the client in a separate function
        handleClient(clientSocket);
    }

    // Close server socket
    closesocket(serverSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}

void handleClient(SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived;

    // Receive and display messages
    while (1) {
        bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            printf("Received: %s\n", buffer);

            // Send a response (echo back)
            send(clientSocket, buffer, bytesReceived, 0);
        } else if (bytesReceived == 0) {
            // Connection closed by the client
            printf("Client disconnected.\n");
            break;
        }
    }

    // Close the client socket
    closesocket(clientSocket);
}
