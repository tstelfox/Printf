/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akramp <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 21:22:54 by akramp         #+#    #+#                */
/*   Updated: 2020/02/11 17:24:09 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define RESETCOLOR "\033[0m"
#define PINK "\n\033[38;5;218m"
#define STR "Twink is best doggo <3"
#define TEST1 "|1|(.3d) \t\t'%.3d'\n"
#define TEST2 "|2|(.7d) \t\t'%.7d'\n"
#define TEST3 "|3|(-8.3d) \t\t'%-8.3d'\n"
#define TEST03 "|03|(-3.8d) \t\t'%-3.8d'\n"
#define TEST003 "|003|(8.3d) \t\t'%8.3d'\n"
#define TEST0003 "|0003|(3.8d) \t\t'%3.8d'\n"
#define TEST4 "|4|(-7d) \t\t'%-7d'\n"
#define TEST5 "|5|(10.7d) \t\t'%10.7d'\n"
#define TEST6 "|6|(-4.7d) \t\t'%-4.7d'\n"
#define TEST7 "|7|(0-4.7d) \t\t'%0-4.7d'\n"
#define TEST8 "|8|(04.7d) \t\t'%04.7d'\n"
#define TEST9 "|9|(0-7d) \t\t'%0-7d'\n"
#define TEST10 "|10|(04d) \t\t'%04d'\n"
#define TEST11 "|11|(-04d) \t\t'%-04d'\n"
#define TEST12 "|12|(044.7d) \t\t'%044.7d'\n"
#define TEST13 "|13|(0d) \t\t'%0d'\n"
#define TEST14 "|14|(07d) \t\t'%07d'\n"
#define TEST15 "|15|(07d) \t\t'%07d'\n"
#define TEST16 "|16|(*.*d) \t\t'%*.*d'\n"
#define TEST17 "|17|(.*d) \t\t'%.*d'\n"
#define TEST18 "|18|(4d) \t\t'%4d'\n"
#define TEST19 "|19|(*.*d) \t\t'%*.*d'\n"
#define TEST20 "|20|(*.*d) \t\t'%*.*d'\n"
#define TEST21 "|21|(i) \t\t'%i'\n"
#define TEST22 "|22|(1i) \t\t'%2i'\n"
#define TEST23 "|23|(.0i) \t\t'%.0i'\n"
#define TEST24 "|24|(.1i) \t\t'%.1i'\n"
#define TEST25 "|25|(.00i) \t\t'%.00i'\n"
#define TEST26 "|26|(.01i) \t\t'%.01i'\n"
#define TEST27 "|27|(0.0i) \t\t'%0.0i'\n"
#define TEST28 "|28|(3.0i) \t\t'%1.0i'\n"
#define TEST29 "|29|(0.1i) \t\t'%0.0i'\n"
#define TEST30 "|30|(8.1i) \t\t'%8.1i'\n"
#define TEST31 "|31|(00.0i) \t\t'%00.0i'\n"
#define TEST32 "|32|(01.1i) \t\t'%01.1i'\n"
#define TEST33 "|33|(08.1i) \t\t'%08.1i'\n"
#define TEST34 "|34|(3d) \t\t'%4d'\n"
#define TEST35 "|35|(*d) \t\t'%*d'\n"
#define TEST36 "|36|(-00-*d) \t\t'%-00-*d'\n"
#define TEST37 "|37|(*.*d) \t\t'%*.*d'\n"
#define TEST38 "|38|(30.20d) \t\t'%30.20d'\n"
#define TEST39 "|39|(-0-000---30.20d) \t\t'%-0-000---30.20d'\n"
#define TEST40 "|40|(*.*i) \t\t'%*.*i'\n"
#define TEST41 "|41|(u) \t\t'%u'\n"
#define TEST42 "|42|(017u) \t\t'%017u'\n" //
#define TEST43 "|43|(-10u) \t\t'%-10u'\n"
#define TEST44 "|44|(-07.8u) \t\t'%-07.8u'\n"
#define TEST45 "|45|(-8.*u) \t\t'%-8.*u'\n"
#define TEST46 "|46|(0*.*u) \t\t'%-0*.*u'\n"
#define TEST47 "|47|(c) \t\t'%c'\n"
#define TEST48 "|48|(c mix) \t\t'%c%c%c%c%c%%%c%%%%%c'\n"
#define TEST49 "|49|(s) \t\t'%s'\n"
#define TEST50 "|50|(6s) \t\t'%6s'\n"
#define TEST51 "|51|(.6s) \t\t'%.6s'\n"
#define TEST52 "|52|(3.6s) \t\t'%3.6s'\n"
#define TEST53 "|53|(6.3s) \t\t'%6.3s'\n"
#define TEST54 "|54|(16.13s) \t\t'%16.13s'\n"
#define TEST55 "|55|(0.0s) \t\t'%0.0s'\n"
#define TEST56 "|56|(0s) \t\t'%0s'\n"
#define TEST57 "|57|(.0s) \t\t'%.0s'\n"
#define TEST58 "|58|(-40s) \t\t'%-40s'\n"
#define TEST59 "|59|(040s) \t\t'%040s'\n"
#define TEST60 "|60|(40s) \t\t'%40s'\n"
#define TEST61 "|61|(.40s) \t\t'%.40s'\n"
#define TEST62 "|62|(p) \t\t'%p'\n"
#define TEST63 "|63|(x) \t\t'%x'\n"
#define TEST64 "|64|(X) \t\t'%X'\n"
#define TEST65 "|65|(7X) \t\t'%7X'\n"
#define TEST66 "|66|(3X) \t\t'%3X'\n"
#define TEST67 "|67|(0X) \t\t'%0X'\n"
#define TEST68 "|68|(.7X) \t\t'%.7X'\n"
#define TEST69 "|69|(7.7X) \t\t'%7.7X'\n"
#define TEST70 "|70|(0.0X) \t\t'%0.0X'\n"
#define TEST71 "|71|(27p) \t\t'%27p'\n"
#define TEST72 "|72|(27x) \t\t'%27x'\n"
//#include "ft_printf.h"
//#include "ft_libft.c"

int	main(void)
{
	//char *s = NULL;
	//char str[3] = "012";

int ret;
int myret;
ret = 0;
myret = 0;

printf("\t\t\033[38;5;222m+-+-+-+-+-+\n");
printf("\t\t|T|e|s|t|s|\n");
printf("ଘ(੭ˊᵕˋ)੭* ✩‧₊˚  +-+-+-+-+-+  ˚₊‧✩ * ٩(๑`^´๑)۶\n");
printf("x--------------------------------------------x\n\n");
printf("%%d & %%i -------------------------------------x\n");

	printf(PINK);
	ret = printf(TEST1, -8);
	printf(RESETCOLOR);
	myret = ft_printf(TEST1, -8);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST2, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST2, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);


	printf(PINK);
	ret = printf(TEST3, -77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST3, -77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST3, 77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST3, 77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST03, -77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST03, -77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST03, 77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST03, 77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST003, -77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST003, -77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST003, 77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST003, 77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST0003, -77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST0003, -77);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST0003, 77);
	printf(RESETCOLOR);
	myret = ft_printf(TEST0003, 77);
	printf("☞ %d\n☞ %d\n", ret, myret);


	printf(PINK);
	ret = printf(TEST4, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST4, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST5, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST5, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST6, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST6, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST7, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST7, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST8, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST8, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST9, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST9, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST10, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST10, 88);

	printf(PINK);
	ret = printf(TEST11, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST11, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST12, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST12, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST12, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST12, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST13, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST13, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST14, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST14, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST15, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST15, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST16, 5 , 4, 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST16, 5, 4, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST17, 5 , 88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST17, 5, 88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST18, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST18, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST19, 9, 5, -88);
	printf(RESETCOLOR);
	myret = ft_printf(TEST19, 9, 5, -88);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 9, 5, -2147483648);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 9, 5, -2147483648);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 9, 5, -2147483647);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 9, 5, -2147483647);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 20, 5, 214748364);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 20, 5, 214748364);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 9, 5, 2147483647);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 9, 5, 2147483647);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 5, 9, 2147483647);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 5, 9, 2147483647);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST20, 5, 9, -2147483648);
	printf(RESETCOLOR);
	myret = ft_printf(TEST20, 5, 9, -2147483648);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST21, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST21, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST22, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST22, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST23, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST23, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST24, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST24, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST25, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST25, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST26, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST26, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST27, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST27, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST28, 10);
	printf(RESETCOLOR);
	myret = ft_printf(TEST28, 10);
	printf("☞ %d\n☞ %d\n", ret, myret);


	printf(PINK);
	ret = printf(TEST28, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST28, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST29, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST29, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST30, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST30, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST31, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST31, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST32, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST32, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST33, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST33, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST34, 777);
	printf(RESETCOLOR);
	myret = ft_printf(TEST34, 777);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST35, -2, 7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST35, -2, 7);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST36, -2, 7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST36, -2, 7);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST37, -2, 5, 7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST37, -2, 5, 7);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST38, -2147483648);
	printf(RESETCOLOR);
	myret = ft_printf(TEST38, -2147483648);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST39, -2147483648);
	printf(RESETCOLOR);
	myret = ft_printf(TEST39, -2147483648);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST40, 0, 1, -458);
	printf(RESETCOLOR);
	myret = ft_printf(TEST40, 0, 1, -458);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf("\n\033[38;5;222m%%%% ------------------------------------------x\n");

	printf(PINK);
	ret = printf("lolo%%llolol%%lololo\n");
	printf(RESETCOLOR);
	myret = ft_printf("lolo%%llolol%%lololo\n");
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf("lo%dlo%%llolol%%lololo\n", 17);
	printf(RESETCOLOR);
	myret = ft_printf("lo%dlo%%llolol%%lololo\n", 17);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf("%%\n");
	printf(RESETCOLOR);
	myret = ft_printf("%%\n");
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf("\n\033[38;5;222m%%u ------------------------------------------x\n");

	printf(PINK);
	ret = printf(TEST41, 7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 7);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST41, 4294967295);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 4294967295);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST41, 4294967294);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 4294967294);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST41, 4294967293);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 4294967293);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST41, 4294967296);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 4294967296);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST41, 429496729);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 429496729);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST42, 34567890);
	printf(RESETCOLOR);
	myret = ft_printf(TEST42, 34567890);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST43, 7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST43, 7);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST44, 42);
	printf(RESETCOLOR);
	myret = ft_printf(TEST44, 42);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 11, 43);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 11, 43);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST46, 7, 3, 44);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 7, 3, 44);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST41, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST41, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 0, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 0, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 1, 1);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 1, 1);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 0, 1);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 0, 1);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 0, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 0, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST45, 1, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST45, 1, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST46, 0, 0, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 0, 0, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	 printf(PINK);
	ret = printf(TEST46, 0, 1, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 0, 1, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST46, 0, 0, 1);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 0, 0, 1);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST46, 1, 0, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 1, 0, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST46, 1, 0, 1);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 1, 0, 1);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST46, 1, 1, 0);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 1, 1, 0);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf(PINK);
	ret = printf(TEST46, 0, 1, 1);
	printf(RESETCOLOR);
	myret = ft_printf(TEST46, 0, 1, 1);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	/* printf("\n\033[38;5;222m%%c ------------------------------------------x\n");

	printf(PINK);
	ret = printf(TEST47, 'a');
	printf(RESETCOLOR);
	myret = ft_printf(TEST47, 'a');
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST48, 'a', 'n', 'g', 'e', 'l', 'i', '!');
	printf(RESETCOLOR);
	myret = ft_printf(TEST48, 'a', 'n', 'g', 'e', 'l', 'i', '!');
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf("\n\033[38;5;222m%%s ------------------------------------------x\n");

	printf(PINK);
	ret = printf(TEST49, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST49, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST50, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST50, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST51, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST51, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST52, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST52, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST53, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST53, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST54, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST54, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST55, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST55, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST56, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST56, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST57, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST57, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST58, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST58, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST59, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST59, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST60, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST60, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST61, STR);
	printf(RESETCOLOR);
	myret = ft_printf(TEST61, STR);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST49, NULL);
	printf(RESETCOLOR);
	myret = ft_printf(TEST49, NULL);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST53, NULL);
	printf(RESETCOLOR);
	myret = ft_printf(TEST53, NULL);
	printf("☞ %d\n☞ %d\n", ret, myret);
	
	printf("\n\033[38;5;222m%%p ------------------------------------------x\n");

	int twink;
	
	printf(PINK);
	ret = printf(TEST62, &twink);
	printf(RESETCOLOR);
	myret = ft_printf(TEST62, &twink);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST62, "drolly");
	printf(RESETCOLOR);
	myret = ft_printf(TEST62, "drolly");
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST62, NULL);
	printf(RESETCOLOR);
	myret = ft_printf(TEST62, NULL);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST62, "");
	printf(RESETCOLOR);
	myret = ft_printf(TEST62, "");
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST62, (void*)7);
	printf(RESETCOLOR);
	myret = ft_printf(TEST62, (void*)7);
	printf("☞ %d\n☞ %d\n", ret, myret);

	// printf(PINK);
	// ret = printf(TEST70, &twink);
	// printf(RESETCOLOR);
	// myret = ft_printf(TEST70, &twink);
	// printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST71, &twink);
	printf(RESETCOLOR);
	myret = ft_printf(TEST71, &twink);
	printf("☞ %d\n☞ %d\n", ret, myret);

	//printf("%020p\n", (void*)7);

	printf("\n\033[38;5;222m%%x & %%X -------------------------------------x\n");

	printf(PINK);
	ret = printf(TEST63, 10);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 10);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 16);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 16);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST63, 20);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 20);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 20);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 20);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST63, 32);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 32);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 32);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 32);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST63, 150);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 150);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 150);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 150);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST63, 153);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 153);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 154);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 154);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST63, 170);
	printf(RESETCOLOR);
	myret = ft_printf(TEST63, 170);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST64, 160);
	printf(RESETCOLOR);
	myret = ft_printf(TEST64, 160);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST65, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST65, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST66, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST66, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST67, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST67, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST68, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST68, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST69, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST69, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf(PINK);
	ret = printf(TEST72, 16656);
	printf(RESETCOLOR);
	myret = ft_printf(TEST72, 16656);
	printf("☞ %d\n☞ %d\n", ret, myret);

	printf("\n\033[38;5;222mx--------------------------------------------x\n");
	*/
	printf("\nMade by                           Angeli Kramp\n");
	return(0);
}