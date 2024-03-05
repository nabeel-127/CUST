//#include <iostream>
//using namespace std;
//float addition(float x, float y)
//{
//	float answer = x + y;
//	return answer;
//}
//float subtraction(float x, float y)
//{
//	float answer = x - y;
//	return answer;
//}
//float multiplication(float x, float y)
//{
//	float answer = x * y;
//	return answer;
//}
//float division(float x, float y)
//{
//	float answer;
//	answer = x / y;
//	return answer;
//}
//void main()
//{
//	int operation;
//	float x, y, answer;
//	char retry;
//	while (1)
//	{
//		cout << "Enter the first number: ";
//		cin >> x;
//		cout << "Enter the second number: ";
//		cin >> y;
//		cout << "Choose an operation:" << endl;
//		cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl;
//		cin >> operation;
//		switch (operation)
//		{
//		case 1:
//			answer = addition(x, y);
//			cout << "Sum = " << answer << endl;
//			break;
//		case 2:
//			answer = subtraction(x, y);
//			cout << "Difference = " << answer << endl;
//			break;
//		case 3:
//			answer = multiplication(x, y);
//			cout << "Product = " << answer << endl;
//			break;
//		case 4:
//			answer = division(x, y);
//			cout << "Division = " << answer << endl;
//			break;
//
//		default:
//			cout << "Invalid input. Try again" << endl;
//		}
//
//		cout << "Enter 'Y' to try again: ";
//		cin >> retry;
//		if (retry != 'y' && retry != 'Y')
//		{
//			break;
//		}
//		system("cls");
//	}
//}