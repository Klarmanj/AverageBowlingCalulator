#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function is called to display the *'s and welcome message to welcome the user to the program.
void welcomeMessage() {
    const int STARS_LENGTH = 60;
    const int SIDE_STAR_LENGTH = 7;
    cout << setw(STARS_LENGTH) << setfill('*') << "" << endl;
    cout << setw(SIDE_STAR_LENGTH) << "" << " Welcome to my Average Bowling Scores Counter "
         << setw(SIDE_STAR_LENGTH) << "" << endl;
    cout << setw(STARS_LENGTH) << "" << endl;
    cout << endl;
}
// This function is called when the scores are inputted into s1-4 and the average is then calculated and stored in an array
int GetAverageScore(int s1, int s2, int s3, int s4){
    int totalScore = s1 + s2 + s3 + s4;
    int average = totalScore / 4;
    return average;

}
// This function prints the final outcome that is sent to the console.
void PrettyPrintResults(string bowlerName[10], int bowlingScores[10][4], int average[10]){
    for (int i = 0; i < 10; i++){
        cout << bowlerName[i] + " scores are: " << endl;
        for (int j = 0; j < 4; j++){
            cout << bowlingScores[i][j] << endl;
        }
        cout << bowlerName[i] + "'s average score is: " << average[i] << endl;
    }
}
// This function does all the calculations in terms of grabbing the names and the scores from the test file, and sending
// all the information to the print results function
bool GetBowlingData(string bowlerName[10], int bowlingScores[10][4], int average[10]){
    int s1, s2, s3, s4;
    int i = 0;
    string names;
    ifstream inputFile;

    inputFile.open("BowlingScores.txt");
    if (!inputFile)
        return false;
    while (getline(inputFile, names, ' ')) {
        inputFile >> s1 >> s2 >> s3 >> s4;
        bowlerName[i] = names;
        bowlingScores[i][0] = s1;
        bowlingScores[i][1] = s2;
        bowlingScores[i][2] = s3;
        bowlingScores[i][3] = s4;
        average[i] = GetAverageScore(s1, s2, s3, s4);
        i++;
    }
    return true;
}
// The main function calls all other functions to perform all the calculations and printing of the results.
int main(){
    int average[10];
    string bowlerName[10];
    int bowlingScores[10][4];
    string names;
    welcomeMessage();
    if (GetBowlingData(bowlerName, bowlingScores, average)) {
        PrettyPrintResults(bowlerName, bowlingScores, average);
    }
    else
        return -1;
}
