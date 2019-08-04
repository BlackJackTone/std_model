/*
  ���˲�ͬ�������������ȡģ��ע��ģ��Ҫ�������������������ǵ���
  ���ֺ���������Exgcd.cpp
*/

/*
  case: n, m = 10^5
  Ԥ���� n! �� m!�����ǵĳ˷���Ԫ
  p: ģ��
  fac���׳�
  inv���׳˵���
*/
void Init() {
	for(int i = 2; i < N; ++i) {
		fac[i] = fac[i - 1] * i % p;
		f[i] = (p - p / i) * f[p % i] % p;
		inv[i] = inv[i - 1] * f[i] % p;
	}
}

LL C(LL n, LL m, LL p) {
	if(m > n) return 0;
	return fac[a] * inv[b] % p * inv[a - b] % p;
}

/*
  case: n = 10^9, m = 10^5
  ��������n!/(n-m)! �� m! ����Ԫ
  qpow: ������
*/

LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

LL C(LL n, LL m, LL p) {
	if(m > n) return 0;
	LL ans = 1;
	for(int i = 1; i <= m; ++i)
		ans = ans * (n - i + 1) % p * qpow(i, p - 2, p) % p;
	return ans;
}

/*
  case: n, m = 10^18, p = 10^5
  lucas����C(n, m) = for(i = 0; i <= k; ++i) ans = ans * C(n[i], m[i])
  ���� m = m[k] * p^k + m[k - 1] * p^(k-1) ...
  nͬ��

  ����C(n[i], m[i])�����Ӧ�������ἰ���㷨����
*/

LL lucas(LL n, LL m, LL p) {
	if(!m) return 1;
	return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
