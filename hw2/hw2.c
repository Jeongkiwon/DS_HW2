#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "student.h"


void main() {
	
	STUDENT* head;
	head = createnodes();

	char buf[30];
	char ch = 'y';
	printf("--------프로그램 시작--------\n");
	while (ch == 'y') {
		int j = 0;
		printf("입력하세요=>");
		scanf("%s", buf);getchar();
		checknode(buf, head);
		printf("계속하시겠습니까? (y/n)");
		ch = getchar();
	}
	getchar();
	
	return;
}
STUDENT *createnodes()
{
	FILE *fp;
	fp = fopen("../student.txt", "r");
	
	STUDENT *head;
	STUDENT *ptr;
	STUDENT *newptr;
	int i = 0;
	if (fp) {
		head = ptr = createnode();
		while (!feof(fp)) {

			fscanf(fp, "%d%s", &(ptr->sid), (ptr->name));
			newptr = createnode();
			ptr->link = newptr;
			ptr = newptr;
			i++;
		}
		fclose(fp);
		printf("파일 처리 완료\n");
	}
	return head;
}
STUDENT *createnode()
{
	STUDENT *newptr;

	newptr = (STUDENT*)malloc(sizeof(STUDENT));


	if (newptr == NULL)
	{
		printf("에러\n");
		exit(1);
	}

	newptr->sid= 0;
	newptr->name[30] = "na";
	newptr->link = NULL;
	return newptr;
}
void checknode(char scan[30], STUDENT *head) {
	STUDENT *ptr;
	ptr = head;
	int num, result;
	if (isdigit(scan[0])) {
		num = atoi(scan);
		while (ptr->link != NULL)
		{
			if (num == ptr->sid) {
				printf("%s\n", (ptr->name));
				break;
			}
			ptr = ptr->link;
		}
		if(ptr->link == NULL){
			if (num == ptr->sid) {
				printf("%s\n", (ptr->name));
			}
			else {
				printf("그런 학번은 없습니다.");
			}
		}
		
	}
	else {
		while (ptr->link != NULL)
		{
			result = strcmp(scan, ptr->name);
			if (!result) {
				printf("%d\n", (ptr->sid));
				break;
			}
			ptr = ptr->link;
		}
		if (ptr->link == NULL) {
			result = strcmp(scan, ptr->name);
			if (!result) {
				printf("%d\n", (ptr->sid));
			}
			else {
				printf("그런 이름은 없습니다.");
			}
		}
	}
}