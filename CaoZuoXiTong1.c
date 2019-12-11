#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct node {
	char name[20];     /*进程的名字*/
	int prio;          /*进程的优先级*/
	//int cputime;     /*CPU执行时间*/
	int needtime;      /*进程执行所需要的时间*/
	char state;        /*进程的状态，W--就绪态，R--执行态，F--完成态*/
	struct node *next;/*链表指针*/
}PCB;

PCB*ready = NULL, *run = NULL, *finish = NULL;/*定义三个队列，就绪队列，执行队列和完成队列*/
int num;
void GetFirst();       /*从就绪队列取得第一个节点*/
void Output();         /*输出队列信息*/
void InsertPrio(PCB*in);/*创建优先级队列，规定优先数越小，优先级越高*/
void InsertTime(PCB*in);/*时间片队列*/
void InsertFinish(PCB*in);/*时间片队列*/
void PrioCreate();     /*优先级输入函数*/
//void TimeCreate();   /*时间片输入函数*/
void Priority();       /*按照优先级调度*/
//void RoundRun();     /*时间片轮转调度*/
int main() {
	printf("优先级调度算法\n");
	printf("please input the number of processes:");
	scanf("%d", &num);
	PrioCreate();
	Priority();
	Output();
	return 0;
}
/*取得第一个就绪队列节点*/
void GetFirst(){
	run = ready;
	if (ready != NULL){
		run->state = 'R';
		ready = ready->next;
		run->next = NULL;
	}
}
void Output()/*输出队列信息*/
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
/*创建优先级队列，规定优先数越小，优先级越低*/
void InsertPrio(PCB*in){
	PCB*fst, *nxt;
	fst = nxt = ready;
	/*如果队列为空，则为第一个元素*/
	if (ready == NULL){
		in->next = ready;
		ready = in;
	}
	/*查到合适的位置进行插入*/
	else
	{
		if (in->prio >= fst->prio)/*比第一个还要大，则插入到队头*/
		{
			in->next = ready;
			ready = in;
		}
		else{
			while (fst->next != NULL)/*移动指针查找第一个别它小的元素的位置进行插入*/
			{
				nxt = fst;
				fst = fst->next;
			}
			if (fst->next == NULL)/*已经搜索到队尾，则其优先级数最小，将其插入到队尾即可*/
			{
				in->next = fst->next;
				fst->next = in;
			}
			else/*插入到队列中*/
			{
				nxt = in;
				in->next = fst;
			}
		}
	}
}
void InsertFinish(PCB*in)/*将进程插入到完成队列尾部*/
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
void PrioCreate()/*优先级调度输入函数*/
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
		getchar();/*吸收回车符号*/
		scanf("%d", &(tmp->needtime));
		getchar();
		scanf("%d", &(tmp->prio));
		//tmp->cputime=0;
		tmp->state = 'W';
		//tmp->prio=20-tmp->needtime;
		/*设置其优先级，需要的时间越多，优先级越低*/
		InsertPrio(tmp);/*按照优先级从高到低，插入到就绪队列*/
	}
}
void Priority()/*按照优先级调度，每次执行一个时间片*/
{
	int flag = 1;
	GetFirst();
	while (run != NULL)/*当就绪队列不为空时，则调度进程如执行队列执行*/
	{
		Output();/*输出每次调度过程中各个节点的状态*/
		while (flag){
			run->prio -= 3;/*优先级减去三*/
			run->needtime--;/*进程执行完成的剩余时间减一*/
			if (run->needtime == 0)/*如果进程执行完毕，将进程状态置为F，将其插入到完成队列*/
			{
				run->state = 'F';
				InsertFinish(run);
				flag = 0;
			}
			else/*将进程状态置为W，入就绪队列*/
			{
				run->state = 'W';
				InsertPrio(run);
				flag = 0;
			}
		}
		flag = 1;
		GetFirst();/*继续取就绪队列队头进程进入执行队列*/
	}
	system("pause");

}