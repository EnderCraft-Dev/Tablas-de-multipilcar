#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <ctime>

using namespace std;


// List of numbers to multiply by n
int randomMultiplyNumbers[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Function declarations
void title();
int inputNumber();
int randomIndex(int n);
void game();
float calculateScore(int score, int possibleAnswers);

int main()
{
	// Title
	title();

	// Starts the game
	game();
	
	

	// Avoids the program to close when finished
	system("pause");

	return 0;
}

// Builds the title
void title()
{
	string title = "<<Adivina las tablas>>";
	cout << title << endl;
	for (int i = 0; i < title.length(); i++)
	{
		cout << "=";
	}cout << endl << endl;
}

// Ask the user to input an "n" number, where 1 >= n <= 10
int inputNumber()
{
	int startNumber;
	cout << "Ingresa un numero del 1 al 10: "; cin >> startNumber;
	if (startNumber > 10)
	{
		cout << "Error. No puedes introducir numeros mayores a 10." << endl;
		inputNumber();
	}
	else if (startNumber < 1)
	{
		cout << "Error. No puedes introducir numeros menores a 1." << endl;
		inputNumber();
	}
	else {
		system("cls");
		title();
		return startNumber;
	}
}

// Creates a random number to use as index and choose a random number from randomMultiplyNumbers array
int randomIndex(int n)
{
	return rand() % n;
}

float calculateScore(int score, int possibleAnswers)
{
	float percentage = (score*100)/possibleAnswers;
	return percentage;
}

// Game logic
void game()
{
	srand(time(NULL));

	int score = 0;

	int attempts;
	int counter = 0;
	cout << "Ingresa cuantas preguntas quieres responder: "; cin >> attempts;

	int startNumber = inputNumber();

	while (counter < attempts)
	{
		int index = randomIndex(12);
		int userAnswer;
		int numberToMultiply = randomMultiplyNumbers[index];

		int correctAnswer = startNumber * numberToMultiply;
		cout << startNumber << "x" << numberToMultiply << "="; cin >> userAnswer;
		if (userAnswer == correctAnswer)
		{
			cout << "Correcto!" << endl;
			score++;
		}
		else {
			cout << "Incorrecto! La respuesta correcta es " << correctAnswer << endl;
		}
		counter++;
		cout << endl;
	}
	float percentage = calculateScore(score, attempts);
	cout << "Juego terminado! Contestaste correctamente el " << percentage << "% de las preguntas." << endl;
}