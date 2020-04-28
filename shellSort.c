/*
	时间复杂度：最坏时间复杂度,当数据逆序时O(n^2)；平均 O(n^1.3)；最好O(n)
	空间复杂度：只有几个临时变量O(1)
	稳定性：不稳定 -->分组时，相同数据不一定分到同一组，元素发生跳跃性的移动，并非顺序性的移动
	数据敏感度：敏感
*/
void  shellSort(int array[] , int len){
	int gap = len; // 步长
	// 多轮的插入排序
	while (gap > 1){
		gap = gap / 3 + 1; // 需要保证最后是一个普通的插入排序
		// 一轮插入排序
		for (int i = 0; i < len - gap; ++i){
			// 通过步长gap进行逻辑分组
			// 组内进行插入排序
			// 不同的元素交替进行排序
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end]>key){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
void shell(int arr[], int len){
	// 确定步长，初始化步长，最后一定要为一个普通插入排序
	int step = len / 2;
	while (step >= 1){// 当步长为1时就是一个普通的插入排序
		// 从当前步长开始进行排序
		for (int i = step; i < len;i++){
			// 当前组内的前一个元素
			int j = i - step;
			// 当前元素
			int cur = arr[i];
			// 对当前位置的元素与组内前面已经排好序的元素比较，后移，直至不满足条件为止
			while (j>=0 && cur<arr[j]){
				arr[j + step] = arr[j];
				j -= step;
			}
			// 插入当前元素
			arr[j + step] = cur;
		}
		step /= 2;
	}
}

void testShell(){
		void shl(int arr[], int len);
		srand(time(NULL));
		// 定义数据量
		int num = 0;
		scanf("%d",&num);
		int* arr = (int*)malloc(sizeof(int)*num);
		for (int i = 0; i < num;i++){
			arr[i] = rand();
		}
		int begin = clock();
		shl(arr, num);
		int end = clock();
		//display(arr, num);
		printf("希尔排序所费时间为:>%d\n", end - begin);
		begin = clock();
		shl(arr, num);
		end = clock();
		//display(arr, num);
		printf("排好序之后的希尔排序所费时间为:>%d\n", end - begin);
}
int main(){
	testShell();
	//testTime();
	//test();
	system("pause");
	return 0;
}