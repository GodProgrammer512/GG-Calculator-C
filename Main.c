/* Include guard: */
#ifndef _GG_CALCULATOR_C_
#define _GG_CALCULATOR_C_

/* Importations: */
#include <cutils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_GNU
#include <math.h>


/* Main code: */
int main()
{
	/* GG Calculator version variables: */
	#define GG_CALCULATOR_FULL_VERSION  200.0L /* GG Calculator full version variable (2.0.0). */
	#define GG_CALCULATOR_MAJOR_VERSION 2.0L   /* GG Calculator major version variable (2).    */
	#define GG_CALCULATOR_MINOR_VERSION 0.0L   /* GG Calculator minor version variable (0).    */
	#define GG_CALCULATOR_PATCH_VERSION 0.0L   /* GG Calculator patch version variable (0).    */

	/* Local variables: */
	char loop1 = 1;                            /* First loop variable.                         */
	long double n1 = 0;                        /* First number variable.                       */
	long double n2 = 0;                        /* Second number variable.                      */
	long double result = 0;                    /* Result number variable.                      */
	int precision = 6;                         /* Precision number variable.                   */
	char sn1[8192] = "";                       /* First number string variable.                */
	char sn2[8192] = "";                       /* Second number string variable.               */
	char operator[8192] = "";                  /* Operator variable.                           */
	char sprecision[8192] = "";                /* Precision string variable.                   */

	/* Commands before main loop: */
	CLEAR_TERMINAL();

	/* Main loop: */
	while(loop1)
	{
		fputs("GG Calculator: ", stdout);
		scanf("%8191s", sn1);

		if(strcmp(sn1, "help") == 0)
		{
			puts("Syntax: <first number/action> <operator/action> <second number/action>.");
			printf("Actions: \"lr\" = last result (current: %Lf). \"precision\" = change precision, syntax: <precision> <precision new value>. \"exit/break\" or \"Ctrl + C\" = exit. \"help\" = show this help info.\n", result);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn1);
			n1 = strtold(sn1, NULL);
		}

		else if(strcmp(sn1, "exit") == 0 || strcmp(sn1, "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(sn1, "lr") == 0)
		{
			n1 = result;
		}

		else if(strcmp(sn1, "pi") == 0)
		{
			n1 = M_PIl;
		}

		else if(strcmp(sn1, "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn1);
			n1 = strtold(sn1, NULL);
		}

		else
		{
			n1 = strtold(sn1, NULL);
		}

		scanf("%8191s", operator);

		if(strcmp(operator, "exit") == 0 || strcmp(operator, "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(operator, "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", operator);
		}

		scanf("%8191s", sn2);

		if(strcmp(sn2, "exit") == 0 || strcmp(sn2, "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(sn2, "lr") == 0)
		{
			n2 = result;
		}

		else if(strcmp(sn2, "pi") == 0)
		{
			n2 = M_PIl;
		}

		else if(strcmp(sn2, "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", sn2);
			n2 = strtold(sn2, NULL);
		}

		else
		{
			n2 = strtold(sn2, NULL);
		}

		CLEAR_TERMINAL();

		if(strcmp(operator, "+") == 0)
		{
			result = n1 + n2;
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else if(strcmp(operator, "-") == 0)
		{
			result = n1 - n2;
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else if(strcmp(operator, "*") == 0)
		{
			result = n1 * n2;
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else if(strcmp(operator, "**") == 0)
		{
			result = powl(n1, n2);
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else if(strcmp(operator, "/") == 0)
		{
			result = n1 / n2;
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else if(strcmp(operator, "//") == 0)
		{
			result = powl(n1, 1.0 / n2);
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n1, operator, precision, n2, precision, result);
		}

		else
		{
			printf("Operation error!\n");
			petc();
			CLEAR_TERMINAL();
		}
	}

	return 0;
}

/* End code: */
#endif
