#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> arr;

int main(){
	/* �׽�Ʈ���̽��� ���� t (t<=100) */
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++){
		bool error = false;					// ���� �߻� ���� 
		/* ������ �Լ� p�� �־���. (1<=p�� ����<=100000)
		// R: �������� ��ȯ , D: ù ��° ���ڸ� ������. */
		string func; cin>>func;
		/* �迭�� ��� �ִ� ���� ���� n�� �־��� (0<=n<=100000) */
		int n; cin>>n;
		/* �迭�� ���� �Է� ex) [1,2,3] */
		arr.erase(arr.begin(), arr.end());
		string arrinput; cin>>arrinput;
		// deque<int> arr�� ���ڸ� ����.
		int num=0;
		if( n!=0 ){
			for(int i=1; i<arrinput.length(); i++){
				if( '0'<=arrinput[i]&&arrinput[i]<='9'){
					num = num*10 + arrinput[i]-'0';
				}
				else{
					arr.push_back(num);
					num=0;
				}
			}
		}
		
		/* �Լ��� ���� */
		bool reverse = false;	// �������� ó������? true/false 
		// �Լ��� ���ʴ�� �ϳ��� �����Ѵ�. 
		for(int i=0; i<func.length(); i++){
			// reverse ����. 
			if( func[i]=='R' ){
				if(reverse==false) reverse=true;
				else reverse=false;
			}
			else if( func[i]=='D' ){
				if( arr.empty() ){		// ���� �߻��� ǥ���ϰ� �Լ� ���� ���� 
					error=true;
					break;
				}
				if( !reverse ){
					// �տ��� �ϳ� ���� 
					arr.pop_front();
				}
				else{
					// �ڿ��� �ϳ� ����
					arr.pop_back();
				}
			}
		}
		
		/* �Լ� ���� ����� ����Ѵ�. */
		// ������ �߻��� ��쿡�� error�� ����Ѵ�. 
		// �����߻� : ��� ���� �Ŀ� []���� �ƹ��͵� ���� �� == deque�� ��� �Ǹ�
		if( error ){
			cout<<"error\n";
			continue;
		}
		
		if( !reverse ){
			// ������� ����Ѵ�.
			cout<<'[';
			for(int i=0; i<arr.size(); i++){
				cout<<arr[i];
				if( i!=arr.size()-1 ){
					cout<<',';
				}
			}
			cout<<']'<<'\n';
		}
		else{
			// �������� ����Ѵ�. 
			cout<<'[';
			for(int i=arr.size()-1; i>=0; i--){
				cout<<arr[i];
				if( i!=0 ){
					cout<<',';
				}
			}
			cout<<']'<<'\n';
		}
	} 
	return 0; 
}