/*
  ����������ɸ����ɹ��1~N�ڵ���������
  bool b[N] : �жϸ����Ƿ�Ϊ����
  int p[N] : ���ڴ洢����
  sz �� ����������
*/

const int N = 1000010;
int p[N], sz;
bool b[N];

void Prime() {
	for(int i = 2; i < N; ++i) {
		if(!b[i]) p[++sz] = i;
		for(int j = 1; j <= sz && i * p[j] < N; ++j) {
			b[i * p[j]] = 1;
			if(i % p[j] == 0)
				break;
		}
	}
}
