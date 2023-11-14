#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz.
#define TOTAL_QUESTIONS 20

typedef struct
{
  char question[MAX_QUESTION];
  char answerA[MAX_ANSWER];
  char answerB[MAX_ANSWER];
  char answerC[MAX_ANSWER];
  char answerD[MAX_ANSWER];
  char correct_answer;
} quiz_question;

void displayMenu();
void startQuiz();

int main(void)
{
  int choice;

  do
  {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      startQuiz();
      break;
    case 2:
      printf("Exiting the program. Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please enter 1 or 2.\n\n");
    }

    // Clear input buffer
    while (getchar() != '\n');

  } while (choice != 2);

  return 0;
}


void displayMenu()
{
  printf("\n********** Quiz On INDIA   **********\n\n");
  printf("1. Start Quiz\n");
  printf("2. Exit\n\n");
}

void startQuiz()
{
     quiz_question quiz[TOTAL_QUESTIONS];

  strcpy(quiz[0].question, "What is the capital of India?");
  strcpy(quiz[0].answerA, "Delhi");
  strcpy(quiz[0].answerB, "Mumbai");
  strcpy(quiz[0].answerC, "Kolkata");
  strcpy(quiz[0].answerD, "Chennai");
  quiz[0].correct_answer = 'A';

  strcpy(quiz[1].question, "Which river is considered the holiest river in India?");
  strcpy(quiz[1].answerA, "Yamuna");
  strcpy(quiz[1].answerB, "Ganges");
  strcpy(quiz[1].answerC, "Brahmaputra");
  strcpy(quiz[1].answerD, "Godavari");
  quiz[1].correct_answer = 'B';

  strcpy(quiz[2].question, "In which year did India gain independence?");
  strcpy(quiz[2].answerA, "1945");
  strcpy(quiz[2].answerB, "1947");
  strcpy(quiz[2].answerC, "1950");
  strcpy(quiz[2].answerD, "1962");
  quiz[2].correct_answer = 'B';

  strcpy(quiz[3].question, "Which mountain range is considered the youngest in India?");
strcpy(quiz[3].answerA, "Himalayas");
strcpy(quiz[3].answerB, "Aravalli");
strcpy(quiz[3].answerC, "Western Ghats");
strcpy(quiz[3].answerD, "Eastern Ghats");
quiz[3].correct_answer = 'A';

strcpy(quiz[4].question, "Who was the first Prime Minister of India?");
strcpy(quiz[4].answerA, "Jawaharlal Nehru");
strcpy(quiz[4].answerB, "Sardar Patel");
strcpy(quiz[4].answerC, "Indira Gandhi");
strcpy(quiz[4].answerD, "Lal Bahadur Shastri");
quiz[4].correct_answer = 'A';

strcpy(quiz[5].question, "Which Indian city is known as the 'City of Joy'?");
strcpy(quiz[5].answerA, "Mumbai");
strcpy(quiz[5].answerB, "Kolkata");
strcpy(quiz[5].answerC, "Chennai");
strcpy(quiz[5].answerD, "Bangalore");
quiz[5].correct_answer = 'B';

strcpy(quiz[6].question, "What is the largest state in India by area?");
strcpy(quiz[6].answerA, "Rajasthan");
strcpy(quiz[6].answerB, "Maharashtra");
strcpy(quiz[6].answerC, "Uttar Pradesh");
strcpy(quiz[6].answerD, "Madhya Pradesh");
quiz[6].correct_answer = 'A';

strcpy(quiz[7].question, "Which Indian festival is known as the 'Festival of Colors'?");
strcpy(quiz[7].answerA, "Diwali");
strcpy(quiz[7].answerB, "Holi");
strcpy(quiz[7].answerC, "Navratri");
strcpy(quiz[7].answerD, "Eid");
quiz[7].correct_answer = 'B';

strcpy(quiz[8].question, "The song Jana-gana-mana, is orignally composed in which language?");
strcpy(quiz[8].answerA, "English");
strcpy(quiz[8].answerB, "Hindi");
strcpy(quiz[8].answerC, "Bengali");
strcpy(quiz[8].answerD, "Telugu");
quiz[8].correct_answer = 'C';

strcpy(quiz[9].question, "Which Indian state is known as the 'Spice Garden of India'?");
strcpy(quiz[9].answerA, "Karnataka");
strcpy(quiz[9].answerB, "Kerala");
strcpy(quiz[9].answerC, "Andhra Pradesh");
strcpy(quiz[9].answerD, "Tamil Nadu");
quiz[9].correct_answer = 'B';

strcpy(quiz[10].question, "What is the national animal of India?");
strcpy(quiz[10].answerA, "Elephant");
strcpy(quiz[10].answerB, "Tiger");
strcpy(quiz[10].answerC, "Lion");
strcpy(quiz[10].answerD, "Leopard");
quiz[10].correct_answer = 'B';

strcpy(quiz[11].question, "Which river is known as the 'Ganga of the South'?");
strcpy(quiz[11].answerA, "Yamuna");
strcpy(quiz[11].answerB, "Godavari");
strcpy(quiz[11].answerC, "Krishna");
strcpy(quiz[11].answerD, "Cauvery");
quiz[11].correct_answer = 'B';

strcpy(quiz[12].question, "Who was the 'Father of the Nation' in India?");
strcpy(quiz[12].answerA, "Sardar Patel");
strcpy(quiz[12].answerB, "Jawaharlal Nehru");
strcpy(quiz[12].answerC, "Bhagat Singh");
strcpy(quiz[12].answerD, "Mahatma Gandhi");
quiz[12].correct_answer = 'D';

strcpy(quiz[13].question, "Which Indian city is famous for its IT industry?");
strcpy(quiz[13].answerA, "Mumbai");
strcpy(quiz[13].answerB, "Bangalore");
strcpy(quiz[13].answerC, "Hyderabad");
strcpy(quiz[13].answerD, "Chennai");
quiz[13].correct_answer = 'B';

strcpy(quiz[14].question, "What is the currency of India?");
strcpy(quiz[14].answerA, "Rupee");
strcpy(quiz[14].answerB, "Yen");
strcpy(quiz[14].answerC, "Dollar");
strcpy(quiz[14].answerD, "Euro");
quiz[14].correct_answer = 'A';

strcpy(quiz[15].question, "Which state in India is known as the 'Land of Five Rivers'?");
strcpy(quiz[15].answerA, "Punjab");
strcpy(quiz[15].answerB, "Haryana");
strcpy(quiz[15].answerC, "Uttar Pradesh");
strcpy(quiz[15].answerD, "Rajasthan");
quiz[15].correct_answer = 'A';

strcpy(quiz[16].question, "Which Indian state is famous for its tea plantations?");
strcpy(quiz[16].answerA, "Kerala");
strcpy(quiz[16].answerB, "Assam");
strcpy(quiz[16].answerC, "Tamil Nadu");
strcpy(quiz[16].answerD, "Karnataka");
quiz[16].correct_answer = 'B';

strcpy(quiz[17].question, "Who wrote the Indian national anthem, 'Jana Gana Mana'?");
strcpy(quiz[17].answerA, "Rabindranath Tagore");
strcpy(quiz[17].answerB, "Bankim Chandra Chatterjee");
strcpy(quiz[17].answerC, "Sarojini Naidu");
strcpy(quiz[17].answerD, "Mohandas Karamchand Gandhi");
quiz[17].correct_answer = 'A';

strcpy(quiz[18].question, "Which Indian festival is known as the Festival of Lights?");
strcpy(quiz[18].answerA, "Holi");
strcpy(quiz[18].answerB, "Diwali");
strcpy(quiz[18].answerC, "Navratri");
strcpy(quiz[18].answerD, "Eid");
quiz[18].correct_answer = 'B';

strcpy(quiz[19].question, "What is the national currency of India?");
strcpy(quiz[19].answerA, "Rupee");
strcpy(quiz[19].answerB, "Rupiah");
strcpy(quiz[19].answerC, "Dinar");
strcpy(quiz[19].answerD, "Ringgit");
quiz[19].correct_answer = 'A';



  double total_correct = 0;
  char answer;

  for (int i = 0; i < TOTAL_QUESTIONS; i++)
  {
    printf("\nQuestion %d: %s\n\n", (i + 1), quiz[i].question);
    printf("A) %s\n", quiz[i].answerA);
    printf("B) %s\n", quiz[i].answerB);
    printf("C) %s\n", quiz[i].answerC);
    printf("D) %s\n", quiz[i].answerD);

    printf("\nEnter Answer (A, B, C, or D) within 10 seconds: ");

    // Declare the variables for timing
    time_t start_time, current_time;

    start_time = time(NULL); // Record the start time

    // Read the user's answer
    if (scanf(" %c", &answer) == 1)
    {
      current_time = time(NULL); // Record the current time

      double elapsed_time = difftime(current_time, start_time);

      if (elapsed_time > 10.0)
      {
        printf("\nTime's up! You took too long to answer. The correct answer was %c\a.\n", quiz[i].correct_answer);
      }
      else if (toupper(answer) == quiz[i].correct_answer)
      {
        total_correct++;
        printf("\nCorrect Answer!\n");
      }
      else
      {
        printf("\nIncorrect Answer!");
        printf("\nThe correct answer was %c\a.\n", quiz[i].correct_answer);
      }
    }
    else
    {
      printf("\nError reading your answer.\n");
    }

    while (getchar() != '\n');

    printf("\n\n");
  }

  printf("Quiz completed. You answered %.0f/%d questions correctly", total_correct, TOTAL_QUESTIONS);
  printf(" (%.2f%%)\n\n", (total_correct / TOTAL_QUESTIONS) * 100);
}
