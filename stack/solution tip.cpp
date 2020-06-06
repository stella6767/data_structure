#include <iostream>
using namespace std;


class parent {  //빌드에서 제외로 필요없는 소스파일 제거할 수 있슴돠. 
				//또 원하는 프로젝트만 실행하려면 솔루션 탐색기에 원하는 프로젝트 우클릭 시작 프로젝트 설정누르면된다.
private:
	int x = 0; //맴버변수 초기화 안 하면 에러 뜸
protected:
	int y = 0;//IntelliSense기능은 소스코드뷰에서 클래스나 함수, 변수등을 오른쪽마우스로 클릭하여  원하는 컨텍스트(Parameter Info, Type Info, 

	//Go To Definition 등)를 선택할 경우 해 당 개체에 대한 정보를 알려주거나 정보가 있는 위치로 이동시키는 것을 말한다
public:
	int z = 0;
};

//프로세스 종료 error LNK1168:을(를) 쓰기용으로 열 수 없습니다. 나올 경우에는
//cmd 창에 들어가 tasklist로 문제 있는 exe 파일을 확인하고 START /wait taskkill /f /im 파일명.exe 으로 확실히 지워준다.
//이것 때문에 3시간 날려먹었네 시발
//단축키 설정 도구-옵션-환경 안먹히네 이거 또 무슨 문제냐

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
	//cout << a.y << endl;//다른 함수(main())에서 사용할 때는 public으로 선언된 변수 외엔 사용할 수 없습니다.
	cout << a.z << endl;

	//cout << b.x << endl;
	//cout << b.y << endl;
	//cout << b.z << endl;

	//cout << c.x << endl;
	//cout << c.y << endl;
	//cout << c.z << endl;

	return 0;
}





