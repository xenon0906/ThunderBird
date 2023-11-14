#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define ANSI_COLOR_RED     ""
    #define ANSI_COLOR_GREEN   ""
    #define ANSI_COLOR_RESET   ""
#else
    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_RESET   "\x1b[0m"
#endif

// Function to shuffle an array
void shuffleArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to display a welcome message and get the user's name
void displayWelcome(char *name) {
    printf("********************************************\n");
    printf("  Welcome to the Grand India Quiz Challenge!\n");
    printf("********************************************\n");

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nHello, %s! Test your knowledge about India. You have 30 seconds for each question.\n", name);
    printf("Let's get started!\n\n");
}

// Function to display a question and get the user's answer
int askQuestion(int questionNumber, char *question, char *options[], int correctOption, int timeLimit) {
    // Shuffle the answer options
    int optionOrder[] = {0, 1, 2, 3};
    shuffleArray(optionOrder, 4);

    printf("\n%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, options[optionOrder[i]]);
    }

    printf("\nYour choice (1-4): ");

    time_t startTime = time(NULL);
    int userChoice;
    scanf("%d", &userChoice);

    time_t endTime = time(NULL);
    int elapsedTime = difftime(endTime, startTime);

    while (elapsedTime < timeLimit && userChoice < 1 && userChoice > 4) {
        printf("Invalid choice. Please enter a number between 1 and 4: ");
        scanf("%d", &userChoice);
    }

    if (elapsedTime >= timeLimit) {
        printf(ANSI_COLOR_RED "\nTime's up! You took too long to answer. This question will be skipped.\n" ANSI_COLOR_RESET);
        return 0;
    }

    if (optionOrder[userChoice - 1] == correctOption) {
        printf(ANSI_COLOR_GREEN "\nCorrect!\n" ANSI_COLOR_RESET);
        return 1;
    } else {
        printf(ANSI_COLOR_RED "\nIncorrect! The correct answer is option %d\n" ANSI_COLOR_RESET, correctOption + 1);
        return 0;
    }
}

// Function to calculate and display the quiz result
void displayResult(char *name, int correctAnswers, int totalQuestions) {
    float percentage = (float)correctAnswers / totalQuestions * 100;
    printf("\n*************************************\n");
    printf("          Quiz Completed\n");
    printf("*************************************\n");
    printf("%s, you answered %d out of %d questions correctly.\n", name, correctAnswers, totalQuestions);
    printf("Your percentage: %.2f%%\n", percentage);
}

int main() {
    srand(time(NULL));

    char name[50]; // Assuming the name won't exceed 50 characters

    // Define quiz questions, options, correct answers, and time limits
    char *questions[] = {
        "Which of the following is the capital of India?",
        "What is the national currency of India?",
        "In which year did India gain independence?",
        "Which river is considered the holiest in Hinduism?",
        "Which Indian state is known as the 'Land of Five Rivers'?",
        "Who is known as the 'Father of the Nation' in India?",
        "Which festival is known as the 'Festival of Lights'?",
        "Which mountain range separates the Indian subcontinent from the Tibetan Plateau?",
        "What is the official language of India?",
        "Who wrote the Indian national anthem, 'Jana Gana Mana'?",
        "In which city is the Taj Mahal located?",
        "Which Indian state is famous for its tea plantations?",
        "Who was the first woman Prime Minister of India?",
        "Which animal is the national symbol of India?",
        "Which Indian state is known as the 'Land of the Gods'?",
        "What is the largest state in India by area?",
        "Who was the first President of India?",
        "Which famous Indian leader was born on October 2nd?",
        "What is the traditional Indian system of medicine?",
        "Which Indian cricket player is known as the 'Little Master'?"
    };

    char *options[][4] = {
        {"Delhi", "Mumbai", "Chennai", "Kolkata"},
        {"Rupee", "Dollar", "Euro", "Yen"},
        {"1947", "1950", "1942", "1925"},
        {"Ganges", "Yamuna", "Brahmaputra", "Sarasvati"},
        {"Punjab", "Haryana", "Uttar Pradesh", "Rajasthan"},
        {"Mahatma Gandhi", "Jawaharlal Nehru", "Sardar Patel", "Subhas Chandra Bose"},
        {"Diwali", "Holi", "Eid", "Christmas"},
        {"Himalayas", "Aravalli", "Western Ghats", "Vindhya Range"},
        {"English", "Hindi", "Bengali", "Telugu"},
        {"Rabindranath Tagore", "Bankim Chandra Chattopadhyay", "Sarojini Naidu", "Subramania Bharati"},
        {"Mumbai", "Agra", "Jaipur", "Delhi"},
        {"Assam", "Kerala", "West Bengal", "Gujarat"},
        {"Indira Gandhi", "Sonia Gandhi", "Jawaharlal Nehru", "Rajiv Gandhi"},
        {"Tiger", "Elephant", "Lion", "Peacock"},
        {"Himachal Pradesh", "Uttarakhand", "Jammu and Kashmir", "Arunachal Pradesh"},
        {"Rajasthan", "Madhya Pradesh", "Maharashtra", "Uttar Pradesh"},
        {"Dr. Rajendra Prasad", "Sarvepalli Radhakrishnan", "Zakir Hussain", "V. V. Giri"},
        {"Mahatma Gandhi", "Jawaharlal Nehru", "Sardar Patel", "Subhas Chandra Bose"},
        {"Ayurveda", "Unani", "Siddha", "Homeopathy"},
        {"Sachin Tendulkar", "Virat Kohli", "Rahul Dravid", "Sunil Gavaskar"}
    };

    int correctAnswers[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 3, 1, 4, 3, 1, 2, 1, 1, 1, 1}; // Correct options corresponding to each question
    int timeLimits[] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30}; // Time limits for each question (in seconds)

    int totalQuestions = sizeof(questions) / sizeof(questions[0]);
    int correctCount = 0;

    displayWelcome(name);

    // Ask each question
    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d:", i + 1);
        correctCount += askQuestion(i + 1, questions[i], options[i], correctAnswers[i], timeLimits[i]);
    }

    // Display the final result
    displayResult(name, correctCount, totalQuestions);

    // Ask if the user wants to replay
    char replay;
    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &replay);

    if (replay == 'y' || replay == 'Y') {
        main(); // Restart the quiz
    } else {
        printf("\nThank you for playing the Grand India Quiz!\n");
    }

    return 0;
}
