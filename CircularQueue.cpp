#include <stdio.h> 
#include <stdlib.h> 
#define N 6

void createq(int[], int*, int*);	//�w�qcreateq�Ƶ{��
void front_item(int[], int, int);	//�w�qfront_item�Ƶ{��
void enqueue(int[], int*, int*, int);		//�w�qenqueue�Ƶ{��
void dequeue(int[], int*, int*);	//�w�qdequeue�Ƶ{��
void list(int[], int, int); 	//�w�qlist�Ƶ{��
void add(int[], int, int); 	//�w�qadd�Ƶ{��
void sub(int[], int, int); 	//�w�qsub�Ƶ{��

int main(void) { 
    int queue[N]; //queue�j�p
    int front=0, rear=0; 
    int input, select; 

    createq(queue, &front, &rear);  //�I�screateq�Ƶ{��
    printf("[e]Enqueue, [d]Dequeue, [a]Add, [s]Sub, [l]List, [f]Front_item, [x]Exit\n");
    while(1) { 
        printf("\n�п�J�A��ܪ��u�@:");  
        scanf("%s", &select); //���o��J���e
  
        switch(select) { 
            case 'e': //��Je����enqueue
                printf("\n�п�J�ƭ�:"); 
                scanf("%d", &input); 
                enqueue(queue, &front, &rear, input); //�I�senqueue�Ƶ{��
                break;
            case 'f': //��Jf����front_item
                front_item(queue, front, rear); //�I�sfront_item�Ƶ{��
                break; 
            case 'd':  //��Jd����dequeue
                dequeue(queue, &front, &rear); //�I�sdequeue�Ƶ{��
                break; 
            case 'l': //��Jl����list
                list(queue, front, rear); //�I�slist�Ƶ{��
                break; 
            case 'x':	//��Jx����exit
            	printf("Bye bye!\n");
            	system("pause");
            	exit(1);
           		break;
            case 'a':	//��Ja����add
          		add(queue, front, rear); //�I�sadd�Ƶ{��
           	 	break;
            case 's':	//��Ja����add
          		sub(queue, front, rear); //�I�ssub�Ƶ{��
          		break;
            default: //��J��l�r
                printf("\n�ﶵ���~�I"); 
                break;
        }
    } 

    printf("\n"); 
    return 0;
} 

void createq(int queue[], int* front, int* rear) { //�إߤ@�Ӧ�C
    int i; 

    for(i = 0; i < N; i++) 
        queue[i] = 0; 

    *front = *rear = 0; 
} 

void front_item(int queue[], int front, int rear) { //��ܦ�C�Ĥ@�ӭ�
    if(front == rear) 
        printf("\n��C�O�Ū��I"); 
    else 
        printf("����CFront�ݪ��@�Ӥ�����: %d", queue[(front+1) % N]); 
} 

void sub(int queue[], int front, int rear) { //���X��Ӭ۴���^

    if(front == rear || ((front+1) % N) ==rear) //�S�����e�Υu���@�Ӥ��e�L�k���۴�
        printf("\n��Ƥ����A����ۥ["); 
    else {
    	int count;
    	count=queue[(front+1)%N]-queue[(front+2)%N]; //�۴�
    	front=(front+2)%N;	 //front���V����
		rear=(rear+1)%N;	 //rear���V�᣸��
    	queue[rear]=count;	//��^�۴�᪺��
    }
} 

void add(int queue[], int front, int rear) { //���X��Ӭۥ[���^

    if(front == rear || ((front+1) % N) ==rear) //�S�����e�Υu���@�Ӥ��e�L�k���ۥ[
        printf("\n��Ƥ����A����۴�"); 
    else {
    	int count;
    	count=queue[(front+1)%N]-queue[(front+2)%N]; //�ۥ[
    	front=(front+2)%N;	//front���V����
		rear=(rear+1)%N;	//rear���V��@��
    	queue[rear]=count;	//��^�ۥ[�᪺��
    }
} 

void enqueue(int queue[], int* front, int* rear, int data) { //�[�J�ƭ�
    int f, r; 
    f = *front; 
    r = *rear; 
    r = (r+1) % N;  //rear���V�U�@��

    if(f == r) { 
        printf("\n��C�O�����A�L�k����enqueue�I"); 
        return; 
    } 

    queue[r] = data; 
    *rear = r; 
} 

void dequeue(int queue[], int* front, int* rear) { //�R���ƭ�
    int f, r; 
    f = *front; 
    r = *rear; 

    if(f == r) { 
        printf("\n��C�O�Ū��A�L�k����dequeue�I"); 
        return; 
    } 
	printf("���X��������: %d",queue[f+1]);
    f = (f+1) % N; 	//front���V�U�@��
    *front = f; 
} 

void list(int queue[], int front, int rear) { //show��C
    int i; 

    printf("\n�ثe��C�����e(��Rear��Front):"); 
    for(i = rear; i >= (front+1) % N; i--) 
        printf("%d ", queue[i]);
} 
