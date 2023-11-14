#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz.
#define TOTAL_QUESTIONS 5

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

  } while (choice != 2);

  return 0;
}

void displayMenu()
{
  printf("\n********** Quiz Program Menu **********\n\n");
  printf("1. Start Quiz\n");
  printf("2. Exit\n\n");
}

void startQuiz()
{
  quiz_question quiz[TOTAL_QUESTIONS];

  strcpy(quiz[0].question, "Which of the following is the highest mountain peak in India?");
  strcpy(quiz[0].answerA, "Mount Everest");
  strcpy(quiz[0].answerB, "Kangchenjunga");
  strcpy(quiz[0].answerC, "Nanda Devi");
  strcpy(quiz[0].answerD, "K2");
  quiz[0].correct_answer = 'B';

  strcpy(quiz[1].question, "Which Indian festival is known as the Festival of Lights?");
  strcpy(quiz[1].answerA, " Diwali");
  strcpy(quiz[1].answerB, " Eid");
  strcpy(quiz[1].answerC, "Navratri");
  strcpy(quiz[1].answerD, " Holi");
  quiz[1].correct_answer = 'A';

  strcpy(quiz[2].question, "Which city is known as the Pink City of India?");
  strcpy(quiz[2].answerA, " Agra");
  strcpy(quiz[2].answerB, "Delhi");
  strcpy(quiz[2].answerC, "Mumbai");
  strcpy(quiz[2].answerD, " Jaipur");
  quiz[2].correct_answer = 'D';

  strcpy(quiz[3].question, "Who was the first Prime Minister of India?");
  strcpy(quiz[3].answerA, " Indira Gandhi");
  strcpy(quiz[3].answerB, "Rajiv Gandhi");
  strcpy(quiz[3].answerC, "Jawaharlal Nehru");
  strcpy(quiz[3].answerD, "Sardar Patel");
  quiz[3].correct_answer = 'C';

  strcpy(quiz[4].question, "Which Indian river is the longest?");
  strcpy(quiz[4].answerA, "Yamuna");
  strcpy(quiz[4].answerB, "Brahmaputra");
  strcpy(quiz[4].answerC, "Ganges");
  strcpy(quiz[4].answerD, "Godavari");
  quiz[4].correct_answer = 'B';

  double total_correct = 0;

  char answer;

  for (int i = 0; i < TOTAL_QUESTIONS; i++)
  {
    printf("\nQuestion %d: %s\n\n", (i + 1), quiz[i].question);
    printf("A) %s\n", quiz[i].answerA);
    printf("B) %s\n", quiz[i].answerB);
    printf("C) %s\n", quiz[i].answerC);
    printf("D) %s\n", quiz[i].answerD);

    printf("\nEnter Answer (A, B, C, or D): ");

    scanf(" %c", &answer);

    if (toupper(answer) == quiz[i].correct_answer)
    {
      total_correct++;
      printf("\nCorrect Answer!");
    }
    else
    {
      printf("\nIncorrect Answer!");
      printf("\nThe correct answer was %c\a.", quiz[i].correct_answer);
    }

    printf("\n\n");
  }

  printf("Quiz completed. You answered %.0f/%d questions correctly", total_correct, TOTAL_QUESTIONS);
  printf(" (%.2f%%)\n\n", (total_correct / TOTAL_QUESTIONS) * 100);
}
