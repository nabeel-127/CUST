//#include <stdio.h>
//TimeConverter(struct Time *ptr);
//struct Time
//{
//	int seconds, minutes, hours;
//}
//main()
//{
//	struct Time t1;
//	int t;
//	printf("Enter the hour: ");
//	scanf("%d", &t1.hours);
//	printf("Enter the minutes: ");
//	scanf("%d", &t1.minutes);
//	printf("Enter the seconds: ");
//	scanf("%d", &t1.seconds);
//	t = TimeConverter(&t1);
//	printf("Time in seconds = %d\n", t);
//}
//TimeConverter(struct Time *ptr)
//{
//	int t;
//	t = (ptr->seconds) + ((ptr->minutes) * 60) + ((ptr->hours) * 60 * 60);
//	return t;
//}