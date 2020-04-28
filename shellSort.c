/*
	ʱ�临�Ӷȣ��ʱ�临�Ӷ�,����������ʱO(n^2)��ƽ�� O(n^1.3)�����O(n)
	�ռ临�Ӷȣ�ֻ�м�����ʱ����O(1)
	�ȶ��ԣ����ȶ� -->����ʱ����ͬ���ݲ�һ���ֵ�ͬһ�飬Ԫ�ط�����Ծ�Ե��ƶ�������˳���Ե��ƶ�
	�������жȣ�����
*/
void  shellSort(int array[] , int len){
	int gap = len; // ����
	// ���ֵĲ�������
	while (gap > 1){
		gap = gap / 3 + 1; // ��Ҫ��֤�����һ����ͨ�Ĳ�������
		// һ�ֲ�������
		for (int i = 0; i < len - gap; ++i){
			// ͨ������gap�����߼�����
			// ���ڽ��в�������
			// ��ͬ��Ԫ�ؽ����������
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
	// ȷ����������ʼ�����������һ��ҪΪһ����ͨ��������
	int step = len / 2;
	while (step >= 1){// ������Ϊ1ʱ����һ����ͨ�Ĳ�������
		// �ӵ�ǰ������ʼ��������
		for (int i = step; i < len;i++){
			// ��ǰ���ڵ�ǰһ��Ԫ��
			int j = i - step;
			// ��ǰԪ��
			int cur = arr[i];
			// �Ե�ǰλ�õ�Ԫ��������ǰ���Ѿ��ź����Ԫ�رȽϣ����ƣ�ֱ������������Ϊֹ
			while (j>=0 && cur<arr[j]){
				arr[j + step] = arr[j];
				j -= step;
			}
			// ���뵱ǰԪ��
			arr[j + step] = cur;
		}
		step /= 2;
	}
}

void testShell(){
		void shl(int arr[], int len);
		srand(time(NULL));
		// ����������
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
		printf("ϣ����������ʱ��Ϊ:>%d\n", end - begin);
		begin = clock();
		shl(arr, num);
		end = clock();
		//display(arr, num);
		printf("�ź���֮���ϣ����������ʱ��Ϊ:>%d\n", end - begin);
}
int main(){
	testShell();
	//testTime();
	//test();
	system("pause");
	return 0;
}