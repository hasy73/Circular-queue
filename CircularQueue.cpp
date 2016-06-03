#include <stdio.h> 
#include <stdlib.h> 
#define N 6

void createq(int[], int*, int*);	//定義createq副程式
void front_item(int[], int, int);	//定義front_item副程式
void enqueue(int[], int*, int*, int);		//定義enqueue副程式
void dequeue(int[], int*, int*);	//定義dequeue副程式
void list(int[], int, int); 	//定義list副程式
void add(int[], int, int); 	//定義add副程式
void sub(int[], int, int); 	//定義sub副程式

int main(void) { 
    int queue[N]; //queue大小
    int front=0, rear=0; 
    int input, select; 

    createq(queue, &front, &rear);  //呼叫createq副程式
    printf("[e]Enqueue, [d]Dequeue, [a]Add, [s]Sub, [l]List, [f]Front_item, [x]Exit\n");
    while(1) { 
        printf("\n請輸入你選擇的工作:");  
        scanf("%s", &select); //取得輸入內容
  
        switch(select) { 
            case 'e': //輸入e執行enqueue
                printf("\n請輸入數值:"); 
                scanf("%d", &input); 
                enqueue(queue, &front, &rear, input); //呼叫enqueue副程式
                break;
            case 'f': //輸入f執行front_item
                front_item(queue, front, rear); //呼叫front_item副程式
                break; 
            case 'd':  //輸入d執行dequeue
                dequeue(queue, &front, &rear); //呼叫dequeue副程式
                break; 
            case 'l': //輸入l執行list
                list(queue, front, rear); //呼叫list副程式
                break; 
            case 'x':	//輸入x執行exit
            	printf("Bye bye!\n");
            	system("pause");
            	exit(1);
           		break;
            case 'a':	//輸入a執行add
          		add(queue, front, rear); //呼叫add副程式
           	 	break;
            case 's':	//輸入a執行add
          		sub(queue, front, rear); //呼叫sub副程式
          		break;
            default: //輸入其餘字
                printf("\n選項錯誤！"); 
                break;
        }
    } 

    printf("\n"); 
    return 0;
} 

void createq(int queue[], int* front, int* rear) { //建立一個佇列
    int i; 

    for(i = 0; i < N; i++) 
        queue[i] = 0; 

    *front = *rear = 0; 
} 

void front_item(int queue[], int front, int rear) { //顯示佇列第一個值
    if(front == rear) 
        printf("\n佇列是空的！"); 
    else 
        printf("位於佇列Front端的一個元素為: %d", queue[(front+1) % N]); 
} 

void sub(int queue[], int front, int rear) { //取出兩個相減後放回

    if(front == rear || ((front+1) % N) ==rear) //沒有內容或只有一個內容無法做相減
        printf("\n資料不足，不能相加"); 
    else {
    	int count;
    	count=queue[(front+1)%N]-queue[(front+2)%N]; //相減
    	front=(front+2)%N;	 //front指向後兩個
		rear=(rear+1)%N;	 //rear指向後ㄧ個
    	queue[rear]=count;	//放回相減後的值
    }
} 

void add(int queue[], int front, int rear) { //取出兩個相加後放回

    if(front == rear || ((front+1) % N) ==rear) //沒有內容或只有一個內容無法做相加
        printf("\n資料不足，不能相減"); 
    else {
    	int count;
    	count=queue[(front+1)%N]-queue[(front+2)%N]; //相加
    	front=(front+2)%N;	//front指向後兩個
		rear=(rear+1)%N;	//rear指向後一個
    	queue[rear]=count;	//放回相加後的值
    }
} 

void enqueue(int queue[], int* front, int* rear, int data) { //加入數值
    int f, r; 
    f = *front; 
    r = *rear; 
    r = (r+1) % N;  //rear指向下一個

    if(f == r) { 
        printf("\n佇列是滿的，無法執行enqueue！"); 
        return; 
    } 

    queue[r] = data; 
    *rear = r; 
} 

void dequeue(int queue[], int* front, int* rear) { //刪除數值
    int f, r; 
    f = *front; 
    r = *rear; 

    if(f == r) { 
        printf("\n佇列是空的，無法執行dequeue！"); 
        return; 
    } 
	printf("取出之元素為: %d",queue[f+1]);
    f = (f+1) % N; 	//front指向下一個
    *front = f; 
} 

void list(int queue[], int front, int rear) { //show佇列
    int i; 

    printf("\n目前佇列的內容(由Rear至Front):"); 
    for(i = rear; i >= (front+1) % N; i--) 
        printf("%d ", queue[i]);
} 
