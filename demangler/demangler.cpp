// demangler.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"




int main(int argc, char* argv[])
{
	DWORD Type = UNDNAME_COMPLETE;

	if (argc != 2)
	{

		if (argc == 3)
		{
			++argv;

			if (strcmpi(*argv, ".name") == 0)
			{
				Type = UNDNAME_NAME_ONLY;
				goto Start;
			}
		}

		return 1;
	}

Start:


	++argv;



	FILE *file = fopen(*argv, "r");
	if (file == NULL) {
		printf("�޷����ļ� %s\n", *argv);
		return 1;
	}
	char line[2048] = { 0 };
	char demangled[2048] = { 0 };

	while (fgets(line, 2048, file)) {
		line[strlen(line) - 1] = '\0';

		if (UnDecorateSymbolName(line, demangled, 2048, Type))
			printf("%s\n", demangled);
	}

	fclose(file);

	return 0;
}