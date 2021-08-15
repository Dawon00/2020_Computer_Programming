#include <iostream>

using namespace std;

//family class
class family {
	//id를 저장할 배열
	int idArray[1000];
	//부모번호를 저장할 배열
	int parent[1000];
public:
	//id를 저장하는 함수
	void setid(int num, int id) {
		idArray[num] = id;
	}
	//부모의 번호를 저장하는 함수
	void setparent(int child, int par) {
		parent[child] = par;
	}
	//id를 반환하는 함수
	int getid(int i) {
		return idArray[i];
	}
	//부모의 번호를 반환하는 함수

	int getparent(int i) {
		return parent[i];
	}

	//두 사람의 자손/조상관계를 알려주는 함수
	int relation(int p1, int p2) {
		if (p1 == p2)
			return 0;
		//temp 변수에 p1의 부모번호를 저장
		int temp = parent[p1];
		while (1) {
			//temp가 p2와 같으면
			if (temp == p2) {
				//p1은 p2의 자손
				return 1;
			}
			//값이 음수가 나오면 반복문을 빠져나온다
			else if (temp == NULL) {
				break;
			}
			//temp의 부모로 거슬러 올라감
			temp = parent[temp];
		}
		//p2의 부모번호를 temp에 저장
		temp = parent[p2];
		while (1) {
			//temp가 p1과 같으면
			if (temp == p1) {
				//p1은 p2의 조상
				return 2;
			}
			//값이 음수가 나오면 반복문이 빠져나온다
			else if (temp == NULL) {
				break;
			}
			//temp의 부모로 거슬러 올라감
			temp = parent[temp];
		}
		//아무런 관계도 아니면 -1을 반환한다
		return -1;


	}

	//두 사람의 가장 가까운 공통 조상의 id를 반환하는 함수
	int lca(int p1, int p2) {
		//p1의 부모과 p2의 부모번호를 저장할 배열을 생성
		int p1parent[1000];
		int p2parent[1000];
		int temp1 = p1;
		int temp2 = p2;
		//배열 인덱스 0에는 p1을 저장
		p1parent[0] = p1;
		//cout << "0 인덱스에 저장할 조상은" << temp1 << endl;

		int i = 1;
		while (1) {
			//부모가 -1이면 반복문을 빠져나온다
			if (parent[temp1] == -1)
				break;
			//부모의 번호를 배열에 차례대로 저장
			p1parent[i] = parent[temp1];
			//cout << i << "인덱스에 저장할 조상은" << parent[temp1] << endl;
			temp1 = parent[temp1];
			//다음 인덱스로 이동
			i++;
		}
		p2parent[0] = p2;
		//cout << "0 인덱스에 저장할 조상은" << temp2 << endl;
		i = 1;
		while (1) {
			//temp2의 부모가 -1이면 반복문을 빠져나온다
			if (parent[temp2] == -1)
				break;
			//temp2의 부모를 배열에 차례로 저장한다
			p2parent[i] = parent[temp2];
			//cout << i << "인덱스에 저장할 조상은" << parent[temp2] << endl;
			temp2 = parent[temp2];
			//배열 다음 인덱스로 이동
			i++;
		}
		int j = 0;
		i = 0;
		while (1) {
			while (1) {
				//만약 조상이 똑같으면 공통조상을 찾은 것
				if (p1parent[i] == p2parent[j]) {
					//cout << "i와 j의 마지막 값" << i << "랑" << j << endl;
					//cout << "공통조상은";
					return getid(p2parent[j]);
				}
				//부모가 음수로 나오면 부모가 없는 것이므로 반복문을 빠져나온다
				else if (p2parent[j] < 0) {
					//cout << j << "인덱스의 부모가 없네요" << endl;
					j = 0;
					break;
				}
				else {
					//다음 인덱스로 이동
					j++;
				}
			}
			//다음 인덱스로 이동
			i++;
			//부모가 음수가 나오면 공통조상이 없는것이다
			if (p1parent[i] < 0) {
				//cout << "공통조상이 없네요" << endl;
				return -1;
			}
		}
	}

	//두 사람의 촌수(거리)를 반환하는 함수
	int distance(int p1, int p2) { //p1이랑 p2는 사람번호임
		//temp는 사람번호임
		//lca값은 id로 나옴
		//공통조상이 없다면
		if (lca(p1, p2) == -1) {
			//cout << "공통조상 없어요" << endl;
		return -1;
		}
		//공통조상이 있다면
		else {
			//p1과 p2가 공통조상이 아니라면
		if (lca(p1, p2) != idArray[p1] && lca(p1, p2) != idArray[p2]) {
			//공통조상 출력
			cout << lca(p1, p2)<< " ";
			//p1을 temp에 저장
		int temp = p1;
		//count 변수를 만들어 준다
		int count = 0;
		while (1) {
			//배열중에서 공통조상이 있다면 반복문을 빠져나온다
			if (idArray[temp] == lca(p1, p2)) {
				break;
			}
			//거리를 1 증가
			count++;
			//부모를 거슬러 올라간다
			temp = parent[temp];
		}
		//temp에 p2저장
		temp = p2;
		while (1) {
			//배열중에 공통조상이 있다면 반복문을 빠져나온다
			if (idArray[temp] == lca(p1, p2)) {
				break;
			}
			//거리를 1증가
			count++;
			//부모를 거슬러 올라간다
			temp = parent[temp];
		}
		//거리 변수를 반환한다
		return count;
		}
		//p1이 공통조상 이라면
		else if (lca(p1, p2) == idArray[p1] && lca(p1, p2) != idArray[p2]) {
			//공통조상을 출력합니다
			cout << lca(p1, p2)<< " ";
			//거리 변수
		int count = 0;
		int temp = p2;
		while (1) {
			//배열중에서 공통 조상이 있다면 반복문을 빠져나온다
			if (idArray[temp] == lca(p1, p2)) {
				break;
			}
			//거리를 1증가시키고 부모를 거슬러 하나 올라감
			count++;
			temp = parent[temp];
		}
		//거리 반환
		return count;
		}
		else if (lca(p1, p2) != idArray[p1] && lca(p1, p2) == idArray[p2]) {
			//공통조상 출력
			cout << lca(p1, p2)<< " ";
			//p1을 temp에 넣고 거리 변수를 만든다
		int temp = p1;
		int count = 0;
		while (1) {
			//배열중에서 공통조상이 있다면 반복문을 빠져나온다
			if (idArray[temp] == lca(p1, p2)) {
				break;
			}
			//거리 1증가 시키고 부모를 하나 거슬러 올라감
			count++;
			temp = parent[temp];
		}
		//거리 반환
		return count;
		}
		}
	}
};

int main() {
	int n, m;
	//cout << "n을 입력하세요" << endl;
	cin >> n;
	//cout << "m을 입력하세요" << endl;
	cin >> m;
	//family 클래스 f 를 만들어줌
	family f;
	
	for (int i = 0; i < n; i++) {
		int id, num = 0;
		//cout << "사람 번호 입력" << endl;
		cin >> num;
		//cout << "id 입력" << endl;
		cin >> id;
		f.setid(num, id);
		//cout << "사람번호와 id를 저장했습니다" << endl;
	}

	for (int i = 0; i < m; i++) {
		int child, par = 0;
		//cout << "자식번호" << endl;
		cin >> child;
		//cout << "부모번호" << endl;
		cin >> par;
		f.setparent(child, par);
		//cout << "자식번호와 부모번호를 저장했습니다" << endl;
	}
	
//부모가 없는 사람은 -1값을 넣어준다.
	for (int i = 0; i < n; i++) {
		if (f.getparent(i) < 0)
			f.setparent(i, -1);
	}
	//p1과 p2의 id를 받을 변수 
	int p1id = 0;
	int p2id = 0;
	//p1과 p2 사람 번호를 받을 변수

	int p1 = 0;
	int p2 = 0;
	//cout << "두 사람의 id 입력" << endl;
	cin >> p1id >> p2id;
	//id를 통해 사람의 번호를 찾아냄
	if (p1id == p2id) {
		for (int i = 0; i < n; i++) {
			if (p1id == f.getid(i)) {
				p1 = i;
				p2 = i;
				//cout << "p1과 p2는 같은데 이거야" << i << endl;
			}
		}
	}
	//id를 통해 사람의 번호를 찾아냄
	for (int i = 0; i < n; i++) {
		//id중에서 p1의 id와 일치하는게 있다면
		if (p1id == f.getid(i)) {
			//그 때의 i를 p1이라고 한다(사람의 번호)
			p1 = i;
			//cout << "p1은" << i << "입니다" << endl;
		}
		//id중에서 p2의 id와 일치하는게 있다면
		else if (p2id == f.getid(i)) {
			//그 때의 i를 p2라고 한다(사람의 번호)
			p2 = i;
			//cout << "p2은" << i << "입니다" << endl;

		}
	}
	//자손/조상관계를 출력(1,2,-1)
	cout << f.relation(p1, p2) << endl;
	cout << f.distance(p1, p2) << endl;
	return 0;
}
