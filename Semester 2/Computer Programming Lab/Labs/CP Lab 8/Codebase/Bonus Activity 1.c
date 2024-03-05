////Bonus Activity 1
//#include <stdio.h>
//main()
//{
//	char sentence[50], word[10], temp[10];
//	int i = 0, j = 0, counter = 0, match = 1;
//	printf("Enter a sentence: ");
//	gets(sentence);
//	printf("Enter the word to compare: ");
//	gets(word);
//	for (i = 0; i < 50; i++)
//	{
//		if (sentence[i] == ' ')
//		{
//			if (match == 1)
//			{
//				counter++;
//			}
//			match = 1;
//			j = -1;
//		}
//		else if (sentence[i] == '\0')
//		{
//			if (match == 1)
//			{
//				counter++;
//			}
//			break;
//		}
//		else if (sentence[i] != word[j])
//		{
//			match = 0;
//		}
//		j++;
//	}
//	printf("%d\n", counter);
//}