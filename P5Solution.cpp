//---------------------------------------------------
//Name: Christelle Mbemba
//Course-Sectio: CS 155-section
//Project: #5
// Due date: 30/11/2022
//Resources: notes from class
//Description: 
//				
//-----------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// constante declaration
int const MAX_EXAM = 3;
int const MAX_PRACTICE = 5;
int const MAX_LAB = 5;
int const MAX_MSLN = 3;
int const MAX_PJT = 4;

double const EXAM_WEIGHT = 0.4;
double const PRACTICE_WEIGHT = 0.1;
double const LAB_WEIGHT = 0.2;
double const MSLN_WEIGHT = 0.05;
double const PJT_WEIGHT = 0.25;



//Functions Declarations
void getExamGrades(double exam[], int size);
void getPracticeGrades(double practice[], int size);
void getLabGrades(double lab[], int size);
void getMiscGrades(double misc[], int size);
void getProject(double project[], int size);
int findTheLowestGrades(double exam[], int size);
double AvgExam(double exam[], int size);
double AvgPractice(double practice[], int size);
double AvgLab(double lab[], int size);
double AvgMisc(double misc[], int size);
double AvgProject(double project[], int size);
double overallAvg (double exam[], double practice[], double lab[], double misc[], double project[], double& overall);
char determineLetterGrades(double exam[], double practice[], double lab[], double misc[], double project[], double overall);
void displayReport(double examAvg, double practiceAvg, double labAvg, double misnAvg,
                   double pjtAvg, double overall, char letterGrade);                    
bool detrmineStatus(double overall);

int main(){
	double examGrades[MAX_EXAM] = {};
	double practiceGrades[MAX_PRACTICE] = {};
	double labGrades[MAX_LAB] = {};
	double miscGrades[MAX_MSLN] = {};
	double project[MAX_PJT] = {};
	
	double examAvg, practiceAvg, labAvg, misnAvg, projectAvg, overall;
	char letterGrade;
	bool status;
	
	
	getExamGrades(examGrades, MAX_EXAM);
	getPracticeGrades(practiceGrades, MAX_PRACTICE);
	getLabGrades(labGrades, MAX_LAB);
	getMiscGrades(miscGrades, MAX_MSLN );
	getProject(project, MAX_PJT);
	
	
	examAvg = AvgExam(examGrades, MAX_EXAM);
	practiceAvg = AvgPractice(practiceGrades, MAX_PRACTICE);
	labAvg = AvgLab(labGrades, MAX_LAB);
	misnAvg = AvgMisc(miscGrades, MAX_MSLN );
	projectAvg = AvgProject(project, MAX_PJT);
	
	
    overall = overallAvg(examGrades, practiceGrades, labGrades, miscGrades, project, overall);
	letterGrade = determineLetterGrades(examGrades, practiceGrades, labGrades, miscGrades, project, overall);	

    displayReport(examAvg, practiceAvg, labAvg, misnAvg, projectAvg, overall, letterGrade);
	
	return 0;
}

// function to get user exams grades
void getExamGrades(double exam[], int size){
	double score = 0;
	int counterGrades = 1;
	
	for(int i = 0; i < size; i++){
		cout << "Enter Exam "<< counterGrades << " : ";
		cin >> score;
		//condition for the user to enter only  valid grades
		while (score < 0 || score > 100){
			cout << "Invalid score !!"<< endl << endl;
			cout << "Enter Exam " << counterGrades << " : ";
			cin >> score;
		}				
		exam[i] = score;
		counterGrades++;
	}
	cout << endl;
}

// function to get user practice grades
void getPracticeGrades(double practice[], int size){
	double score = 0;
	int counterGrades = 1;
	
	for(int i = 0; i < size; i++){
		cout << "Enter Practice "<< counterGrades << " : ";
		cin >> score;
		while (score < 0 || score > 100){
			cout << "Invalid score !!"<< endl << endl;
			cout << "Enter Practice " << counterGrades << " : ";
			cin >> score;
		}		
		
		practice[i] = score;
		counterGrades++;
	}
	cout << endl;	
}

// function to get user lab grades
void getLabGrades(double lab[], int size){
	double score = 0;
	int counterGrades = 1;
	
	for(int i = 0; i < size; i++){
		cout << "Enter Lab "<< counterGrades << " : ";
		cin >> score;
		while (score < 0 || score > 100){
			cout << "Invalid score !!"<< endl << endl;
			cout << "Enter Lab " << counterGrades << " : ";
			cin >> score;
		}		
		lab[i] = score;
		counterGrades++;
	}
	cout << endl;	
}

//function to get misc  grad
void getMiscGrades(double misc[], int size){
	double score = 0;
	int counterGrades = 1;
	
	for(int i = 0; i < size; i++){
		cout << "Enter Miscellaneous "<< counterGrades << " : ";
		cin >> score;
		while (score < 0 || score > 100){
			cout << "Invalid score !!"<< endl << endl;
			cout << "Enter Miscellaneous " << counterGrades << " : ";
			cin >> score;
		}		
		misc[i] = score;
		counterGrades++;
	}
	cout << endl;	
}

//function to get user project grades
void getProject(double project[], int size){
	double score = 0;
	int counterGrades = 1;
	
	for(int i = 0; i < size; i++){
		cout << "Enter Project "<< counterGrades << " : ";
		cin >> score;
		while (score < 0 || score > 100){
			cout << "Invalid score !!"<< endl << endl;
			cout << "Enter Project " << counterGrades << " : ";
			cin >> score;
		}		
		project[i] = score;
		counterGrades++;
	}
	cout << endl;	
}

//function to find the lowest grade on the  array exam
int findTheLowestGrades(double exam[], int size){
	double lowest = exam[0];
	for(int i = 1; i < size; i++){
		if(exam[i] < lowest){
			lowest = exam[i];
		}
	}
	return lowest;
	
}

// function to calculate the exam average
double AvgExam(double exam[], int size){
	double sum = 0;
	double min = 0;
	double examAverage = 0;
	//call the find lowest grade function
	min = findTheLowestGrades(exam, MAX_EXAM);
	
	// calculate the some of grades
	for(int i = 0; i < size; i++){
		sum += exam[i];
	} 
	// drop the lowest grades
	sum -= min;
	//calu of the average
	examAverage = (sum /( MAX_EXAM - 1)) * EXAM_WEIGHT;
	
	return examAverage;
}

//function to calculate the practices average
double AvgPractice(double practice[], int size){
	double sum = 0;
	double practiceAverage = 0;
	
	for (int i = 0; i < size; i++){
		sum += practice[i];
	}
	
	practiceAverage = (sum / MAX_PRACTICE) * PRACTICE_WEIGHT;
	
	return practiceAverage;
}

double AvgLab(double lab[], int size){
	double sum = 0;
	double labAverage = 0;
	
	for (int i = 0; i < size; i++){
		sum += lab[i];
	}
	
	labAverage = (sum / MAX_LAB)*LAB_WEIGHT;
	
	return labAverage;
	
}

double AvgMisc(double misc[], int size){
	double sum = 0;
	double miscAverage = 0;
	
	for (int i = 0; i < size; i++){
		sum += misc[i];
	}
	miscAverage = (sum / MAX_MSLN)*MSLN_WEIGHT;
	
	return miscAverage;	
}

double AvgProject(double project[], int size){
	double sum = 0;
	double pjtAverage = 0;
	
	for (int i = 0; i < size; i++){
		sum += project[i];
	}
	pjtAverage = (sum / MAX_PJT)*PJT_WEIGHT;
	
	return pjtAverage;	
}

double overallAvg(double exam[], double practice[], double lab[], double misc[], double project[], double& overall){
	
	double examAvg =0, practiceAvg=0,  labAvg=0 , mslnAvg =0, projectAvg=0;
	
	
	examAvg = AvgExam(exam, MAX_EXAM);
	practiceAvg = AvgPractice(practice, MAX_PRACTICE);
	labAvg = AvgLab(lab, MAX_LAB);
	mslnAvg = AvgMisc(misc, MAX_MSLN );
	projectAvg = AvgProject(project, MAX_PJT);
	
	cout << setprecision(1)<< fixed;
    overall = examAvg + mslnAvg + practiceAvg + labAvg + projectAvg;
	
	
	return overall;
	
}
//funtion to detremine the letter grades
char determineLetterGrades(double exam[], double practice[], double lab[], double misc[], double project[]
                          , double overall){
    overallAvg (exam, practice,lab, misc, project, overall);
	char letterGrade = ' ';

	if(overall >= 90 && overall <= 100){
		letterGrade = 'A';
	}
	else if(overall >= 80 && overall <= 89.0){
		letterGrade = 'B';
	}
	
	else if(overall >= 70 && overall <= 79.9){
		letterGrade = 'C';
	}
	
	else if(overall >= 60 && overall <= 69.9){
		letterGrade = 'D';
	}
	
	else if(overall >= 0 && overall <= 59.9){
		letterGrade = 'F';
	}			
	
	return letterGrade;	
}

bool detrmineStatus(double overall){
	int status = true;
	
	if (overall >= 79.9){
		status = true;
		cout << "STATUS : PASS.";
	}
	else{
		
		status = false;
	    cout << "STATUT : FAIL.";
		
	}
	   
	      
}

void displayReport(double examAvg, double practiceAvg, double labAvg, double misnAvg,
                   double pjtAvg, double overall, char letterGrade){
                   	
        
                   	
        cout << "*************************************************" << endl;
		cout << "Weighted Exam Average: " << examAvg <<endl;
		cout << "Weighted Practice Average: " << practiceAvg <<endl;
		cout << "Weighted Lab Average: " << labAvg <<endl;
		cout << "Weighted Misc. Average: " << misnAvg <<endl;
		cout << "Weighted Project Average: " << pjtAvg << endl << endl;
		cout << "Overall Average : " << overall << endl;
		cout << "Letter Grade: " << letterGrade << endl;
        detrmineStatus(overall);
	
}


	
	


