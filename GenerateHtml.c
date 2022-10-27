#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)


#define SEPERATOR "[[[LINE1]]]"


int SaveIntoFile(char* fileName, char* buff)
{
	FILE* fi = fopen(fileName, "w");
	if (!fi)
	{
		return 0;
	}

	fputs(buff, fi);


	fclose(fi);
}

char* ReadAllFile(char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}


	// Get the file size
	char* buff = (char*)malloc(1000);
	char* read;
	int fileSize = 0;
	while ((read = fgets(buff, 1000, f)))
	{
		fileSize += strlen(buff);
	}

	free(buff);
	fclose(f);

	// alloc space as file size
	buff = (char*)malloc(fileSize+1);

	f = fopen(fileName, "r");
	if (!f)
	{
		return NULL;
	}
	int readPosition = 0;
	char charToRead;
	while ((charToRead = fgetc(f)) != EOF)
	{
		buff[readPosition] = charToRead;
		readPosition++;
	}
	buff[readPosition] = NULL;

	fclose(f);

	return buff;
}



int main() {

	char name[100];
	char HTML_REPLACE[1000];
	fgets(name,20, stdin);
	//gets(name);

	sprintf(HTML_REPLACE, "<div>%s</div>", name);

	char* htmlTemplate = ReadAllFile("C:\\level-up\\c lesson-level up\\source\\repos\\22.9.2022\\GenerateHtml\\GenerateHtml\\about.html");

	char* found = strstr(htmlTemplate, SEPERATOR);

	int len = found - htmlTemplate;
	char* newBuff = (char*)malloc(strlen(htmlTemplate) + strlen(HTML_REPLACE));

	strncpy(newBuff, htmlTemplate, len);
	newBuff[len] = NULL;



	strcat(newBuff, HTML_REPLACE);

	newBuff[len + strlen(HTML_REPLACE)] = NULL;

	strcat(newBuff, found + strlen(SEPERATOR));

	SaveIntoFile("newTest1.html", newBuff);


	free(newBuff);
	free(htmlTemplate);

	return 0;

}












////task 1-4
//char AddresImg[1000];
//char ImgAddres[1000];
//
//printf("please enter an image link:");
//gets(AddresImg);
//
//sprintf(ImgAddres, "<img src = \"%s\" height=\"100\" width=\"100\"/>", AddresImg);
//
//
//int imgNum;
//
//printf("\nplease enter an image link:");
//scanf("%d", &imgNum);
//
//FILE* f = fopen("yoni3.html", "w");
//
//if (f) {
//
//	fputs("<html>\n", f);
//
//	fputs("<head>\n", f);
//	fputs("<title>hi</title>\n", f);
//	fputs("<head>\n", f);
//
//	fputs("<body>\n", f);
//	fputs("<table>\n", f);
//	fputs("<tr>\n", f);
//
//	fputs("<td>1</td>\n", f);
//
//	fputs("<td>2</td>\n", f);
//	fputs("</tr>\n", f);
//	fputs("<table>\n", f);
//
//	for (int i = 0; i < imgNum; i++) {
//		fputs("<div style=\"background-color:aquamarine\"> ", f);
//		fputs(ImgAddres, f);
//		fputs("</div>", f);
//	}
//	fputs("</body>\n", f);
//
//	fputs("</html>\n", f);
//
//}
//else {
//	////eror
//}
//
//fclose(f);






















//
//FILE* f;
//int zero = '0';
//int countI = 0;
//int num_count;
//
//f = fopen("yoni.html", "w");
//
//if (f != NULL)
//{
//	char ch = fgetc(f);
//
//	while (ch != EOF)
//	{
//
//		if (ch != 'c' && ch != 'i') {
//			num_count = ch - zero;
//		}
//		else {
//
//			if (ch == 'i') {
//
//				int* New_Memory_Int = malloc(sizeof(int) * num_count);
//				int* OriginalC = New_Memory_Int;
//				for (int i = 0; i < num_count; i++)
//				{
//					printf("please enter number to memory for int:\n");
//					scanf("%d", New_Memory_Int);
//					New_Memory_Int++;
//				}
//				free(OriginalC);
//			}
//
//			else {
//				char* New_Memory_char = malloc(sizeof(char) * num_count);
//				char* OriginalI = New_Memory_char;
//				for (int i = 0; i < num_count; i++)
//				{
//					printf("please enter number to memory for char:\n");
//					scanf(" %c", New_Memory_char);
//					New_Memory_char++;
//				}
//				free(OriginalI);
//			}
//		}
//		ch = fgetc(f);
//	}
//	fclose(f);
//}
//else
//{
//	// problem
//	// error message
//}
