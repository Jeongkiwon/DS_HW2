
typedef struct student {
	int sid; //����� ������ �κ�
	char name[30];
	struct student *link; //����� ������ �κ�
}STUDENT;

STUDENT *createnodes();
STUDENT *createnode();
void checknode(char scan[30],STUDENT *head);