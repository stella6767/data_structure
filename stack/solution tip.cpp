#include <iostream>
using namespace std;


class parent {  //���忡�� ���ܷ� �ʿ���� �ҽ����� ������ �� �ֽ���. 
				//�� ���ϴ� ������Ʈ�� �����Ϸ��� �ַ�� Ž���⿡ ���ϴ� ������Ʈ ��Ŭ�� ���� ������Ʈ ����������ȴ�.
private:
	int x = 0; //�ɹ����� �ʱ�ȭ �� �ϸ� ���� ��
protected:
	int y = 0;//IntelliSense����� �ҽ��ڵ�信�� Ŭ������ �Լ�, �������� �����ʸ��콺�� Ŭ���Ͽ�  ���ϴ� ���ؽ�Ʈ(Parameter Info, Type Info, 

	//Go To Definition ��)�� ������ ��� �� �� ��ü�� ���� ������ �˷��ְų� ������ �ִ� ��ġ�� �̵���Ű�� ���� ���Ѵ�
public:
	int z = 0;
};

//���μ��� ���� error LNK1168:��(��) ��������� �� �� �����ϴ�. ���� ��쿡��
//cmd â�� �� tasklist�� ���� �ִ� exe ������ Ȯ���ϰ� START /wait taskkill /f /im ���ϸ�.exe ���� Ȯ���� �����ش�.
//�̰� ������ 3�ð� �����Ծ��� �ù�
//����Ű ���� ����-�ɼ�-ȯ�� �ȸ����� �̰� �� ���� ������

class child1 :public parent {

};

class child2 :protected parent {

};

class child3 :private parent {

};


int main() {

	child1 a;
	//child2 b;
	//child3 c;

	//cout << a.x << endl;
	//cout << a.y << endl;//�ٸ� �Լ�(main())���� ����� ���� public���� ����� ���� �ܿ� ����� �� �����ϴ�.
	cout << a.z << endl;

	//cout << b.x << endl;
	//cout << b.y << endl;
	//cout << b.z << endl;

	//cout << c.x << endl;
	//cout << c.y << endl;
	//cout << c.z << endl;

	return 0;
}





