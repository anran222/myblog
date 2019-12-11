#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct node {
	char name[20];     /*���̵�����*/
	int prio;          /*���̵����ȼ�*/
	//int cputime;     /*CPUִ��ʱ��*/
	int needtime;      /*����ִ������Ҫ��ʱ��*/
	char state;        /*���̵�״̬��W--����̬��R--ִ��̬��F--���̬*/
	struct node *next;/*����ָ��*/
}PCB;

PCB*ready = NULL, *run = NULL, *finish = NULL;/*�����������У��������У�ִ�ж��к���ɶ���*/
int num;
void GetFirst();       /*�Ӿ�������ȡ�õ�һ���ڵ�*/
void Output();         /*���������Ϣ*/
void InsertPrio(PCB*in);/*�������ȼ����У��涨������ԽС�����ȼ�Խ��*/
void InsertTime(PCB*in);/*ʱ��Ƭ����*/
void InsertFinish(PCB*in);/*ʱ��Ƭ����*/
void PrioCreate();     /*���ȼ����뺯��*/
//void TimeCreate();   /*ʱ��Ƭ���뺯��*/
void Priority();       /*�������ȼ�����*/
//void RoundRun();     /*ʱ��Ƭ��ת����*/
int main() {
	printf("���ȼ������㷨\n");
	printf("please input the number of processes:");
	scanf("%d", &num);
	PrioCreate();
	Priority();
	Output();
	return 0;
}
/*ȡ�õ�һ���������нڵ�*/
void GetFirst(){
	run = ready;
	if (ready != NULL){
		run->state = 'R';
		ready = ready->next;
		run->next = NULL;
	}
}
void Output()/*���������Ϣ*/
{
	PCB*p;
	p = ready;
	printf("pcb_name\tpriority\tneed_time\tpro_state\n");
	while (p != NULL){
		printf("%s\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->needtime, p->state);
		p = p->next;
	}
	p = finish;
	while (p != NULL){
		printf("%s\t%d\t%d\t\t%c\t\n", p->name, p->prio, p->needtime, p->state);
		p = p->next;
	}
	p = run;
	while (p != NULL){
		printf("%s\t    %d\t    %d\t    \t%c    \t\n", p->name, p->prio, p->needtime, p->state);
		p = p->next;
	}
}
/*�������ȼ����У��涨������ԽС�����ȼ�Խ��*/
void InsertPrio(PCB*in){
	PCB*fst, *nxt;
	fst = nxt = ready;
	/*�������Ϊ�գ���Ϊ��һ��Ԫ��*/
	if (ready == NULL){
		in->next = ready;
		ready = in;
	}
	/*�鵽���ʵ�λ�ý��в���*/
	else
	{
		if (in->prio >= fst->prio)/*�ȵ�һ����Ҫ������뵽��ͷ*/
		{
			in->next = ready;
			ready = in;
		}
		else{
			while (fst->next != NULL)/*�ƶ�ָ����ҵ�һ������С��Ԫ�ص�λ�ý��в���*/
			{
				nxt = fst;
				fst = fst->next;
			}
			if (fst->next == NULL)/*�Ѿ���������β���������ȼ�����С��������뵽��β����*/
			{
				in->next = fst->next;
				fst->next = in;
			}
			else/*���뵽������*/
			{
				nxt = in;
				in->next = fst;
			}
		}
	}
}
void InsertFinish(PCB*in)/*�����̲��뵽��ɶ���β��*/
{
	PCB*fst;
	fst = finish;
	if (finish == NULL){
		in->next = finish;
		finish = in;
	}
	else{
		while (fst->next != NULL){
			fst = fst->next;
		}
		in->next = fst->next;
		fst->next = in;
	}
}
void PrioCreate()/*���ȼ��������뺯��*/
{
	PCB*tmp;
	int i;
	printf("please input process_name,need_time,priority:\n");
	for (i = 0; i<num; i++){
		if ((tmp = (PCB*)malloc(sizeof(PCB))) == NULL){
			perror("malloc");
			exit(1);
		}
		scanf("%s", tmp->name);
		getchar();/*���ջس�����*/
		scanf("%d", &(tmp->needtime));
		getchar();
		scanf("%d", &(tmp->prio));
		//tmp->cputime=0;
		tmp->state = 'W';
		//tmp->prio=20-tmp->needtime;
		/*���������ȼ�����Ҫ��ʱ��Խ�࣬���ȼ�Խ��*/
		InsertPrio(tmp);/*�������ȼ��Ӹߵ��ͣ����뵽��������*/
	}
}
void Priority()/*�������ȼ����ȣ�ÿ��ִ��һ��ʱ��Ƭ*/
{
	int flag = 1;
	GetFirst();
	while (run != NULL)/*���������в�Ϊ��ʱ������Ƚ�����ִ�ж���ִ��*/
	{
		Output();/*���ÿ�ε��ȹ����и����ڵ��״̬*/
		while (flag){
			run->prio -= 3;/*���ȼ���ȥ��*/
			run->needtime--;/*����ִ����ɵ�ʣ��ʱ���һ*/
			if (run->needtime == 0)/*�������ִ����ϣ�������״̬��ΪF��������뵽��ɶ���*/
			{
				run->state = 'F';
				InsertFinish(run);
				flag = 0;
			}
			else/*������״̬��ΪW�����������*/
			{
				run->state = 'W';
				InsertPrio(run);
				flag = 0;
			}
		}
		flag = 1;
		GetFirst();/*����ȡ�������ж�ͷ���̽���ִ�ж���*/
	}
	system("pause");

}