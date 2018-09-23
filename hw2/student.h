
typedef struct student {
	int sid; //노드의 데이터 부분
	char name[30];
	struct student *link; //노드의 포인터 부분
}STUDENT;

STUDENT *createnodes();
STUDENT *createnode();
void checknode(char scan[30],STUDENT *head);