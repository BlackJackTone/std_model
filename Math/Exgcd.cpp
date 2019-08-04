/*
  ŷ������㷨����gcd(a, b);
*/
LL gcd(LL a, LL b) {
	if(a < b) swap(a, b);
	LL t;
	while(b)
		t = a % b, a = b, b = t;
	return a;
}

/*
  ��չŷ������㷨����ⷽ�̣�ax + by = gcd(a, b)
  ����ֵΪgcd(a, b)
*/

LL exgcd(LL a, LL b, LL & x, LL & y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		LL d = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
}

/*
  ����Ϊ���򵥵�д�������ڽ�ͬ�෽��ax = z (mod b)
*/

LL exgcd(LL a, LL b, LL z) { return a ? (exgcd(b % a, a, -z) * b + z) / a : z / b; }

/*
  ͬ�෽��Ӧ�ã���˷���Ԫ
  ����Ϊ��a��ģp�µ���Ԫ
*/

LL inv(LL a, LL p) { return exgcd(a, p, 1); }
