//#include <iostream>
//using namespace std;
//float addition(float x, float y)
//{
//	float result = x + y;
//	return result;
//}
//float subtraction(float x, float y)
//{
//	float result = x - y;
//	return result;
//}
//float multiplication(float x, float y)
//{
//	float result = x * y;
//	return result;
//}
//float division(float x, float y)
//{
//	float result;
//	result = x / y;
//	return result;
//}
//int main()
//{
//	int option;
//	float x, y, result;
//	char retry;
//	while (1)
//	{
//		cout << "Enter the first number: ";
//		cin >> x;
//		cout << "Enter the second number: ";
//		cin >> y;
//
//		cout << "Choose an operation:" << endl;
//		cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl;
//		cin >> option;
//
//		switch (option)
//		{
//		case 1:
//			result = addition(x, y);
//			cout << "Sum = " << result << endl;
//			break;
//		case 2:
//			result = subtraction(x, y);
//			cout << "Difference = " << result << endl;
//			break;
//		case 3:
//			result = multiplication(x, y);
//			cout << "Product = " << result << endl;
//			break;
//		case 4:
//			result = division(x, y);
//			cout << "Division = " << result << endl;
//			break;
//
//		default:
//			cout << "You have entered the wrong input" << endl;
//		}
//
//		cout << "Press 'Y' to try again: ";
//		cin >> retry;
//		if (retry != 'y' && retry != 'Y')
//			break;
//		system("cls");
//	}
//	return 0;
//}